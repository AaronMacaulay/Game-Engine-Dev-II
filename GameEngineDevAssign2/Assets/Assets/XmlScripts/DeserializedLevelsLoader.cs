using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Xml;
using UnityEngine;

public class DeserializedLevelsLoader
{
    
    private DeserializedLevels deserializedLevels;

    private const string prefabsFolder = "Prefabs/";

    struct ItemStruct
    {
        public GameObject prefab;
        public float x;
        public float y;
        public float rot;
        public float scale_x;
        public float scale_y;

        public ItemStruct(GameObject prefabGO, DeserializedLevels.Item deserializedItem)
        {
            prefab = prefabGO;
            x = toFloatZeroIfNull(deserializedItem.x);
            y = toFloatZeroIfNull(deserializedItem.y);
            rot = toFloatZeroIfNull(deserializedItem.rot);
            scale_x = toFloatOneIfNull(deserializedItem.scale_x);
            scale_y = toFloatOneIfNull(deserializedItem.scale_y);
        }
    }

    
    Dictionary<string, GameObject> prefabPool;

    
    List<ItemStruct> sceneItemsList;

    Transform parentOfXmlItems;

    public const string xmlItemsGOName = "XmlItems";

    private void init()
    {
        prefabPool = new Dictionary<string, GameObject>();
        sceneItemsList = new List<ItemStruct>();

        
        while (GameObject.Find(xmlItemsGOName) != null)
            MonoBehaviour.DestroyImmediate(GameObject.Find(xmlItemsGOName));

        parentOfXmlItems = new GameObject(xmlItemsGOName).transform;
    }

    public void generateItems()
    {
        init();

        createSceneItemsList();

        
        instantiateItems();
    }

    private DeserializedLevels.Level getCurLevel()
    {
        deserializedLevels = XmlIO.LoadXml<DeserializedLevels>("Levels");

        
        int startLevel = int.Parse(deserializedLevels.developer.startLevel);

        return deserializedLevels.levels[startLevel - 1]; ;
    }


    private void instantiateItems()
    {
        foreach (ItemStruct item in sceneItemsList)
        {

            
            GameObject newGameObject = MonoBehaviour.Instantiate(item.prefab) as GameObject;

            
            setPos2D(newGameObject, new Vector2(item.x, item.y));

            
            setRot2D(newGameObject, item.rot);

            
            newGameObject.transform.localScale = new Vector3(item.scale_x, item.scale_y, 1);

            
            newGameObject.transform.parent = parentOfXmlItems;
        }
    }

    private void createSceneItemsList()
    {
        // <Item prefab="Chair" x="1" y="10" rot="90" />
        foreach (DeserializedLevels.Item deserializedItem in getCurLevel().items)
        {
            
            string prefabString = deserializedItem.prefab;

            
            if (!prefabPool.ContainsKey(prefabString))
            {
                
                GameObject prefabObject = Resources.Load(prefabsFolder + prefabString, typeof(GameObject)) as GameObject;

                
                if (prefabObject == null)
                {
                    Debug.LogError("Prefab \"" + prefabString + "\" does not exists.");
                    continue;
                }

                
                prefabPool.Add(prefabString, prefabObject);
            }

            ItemStruct item = new ItemStruct(prefabPool[prefabString], deserializedItem);

            sceneItemsList.Add(item);
        }
    }


    
    static float toFloatZeroIfNull(string value) { return value == null ? 0 : float.Parse(value); }
    static float toFloatOneIfNull(string value) { return value == null ? 1 : float.Parse(value); }


    void setPos2D(GameObject g, Vector2 pos)
    {
        g.transform.position = new Vector3(
            pos.x,
            pos.y,
            g.transform.position.z
        );
    }

    void setRot2D(GameObject g, float rot)
    {
        Quaternion rotation = Quaternion.identity;
        rotation.eulerAngles = new Vector3(0, 0, rot);
        g.transform.localRotation = rotation;
    }

}
