using UnityEngine;
using System.Collections;

using System.Collections.Generic;
using System.IO;
using System.Xml;
using System.Linq;

public class DeserializedLevelsCrossChecker
{
    
    public void crossCheck()
    {
        
        HashSet<string> resPrefabSet = new HashSet<string>();
        HashSet<string> xmlPrefabSet = new HashSet<string>();

        
        getLevelPrefabs(xmlPrefabSet);

        
        getResPrefabs(resPrefabSet);

        
        foreach (string prefab in xmlPrefabSet.Except(resPrefabSet).ToList())
            Debug.LogError(prefab + " is missing in the /Resorces/Prefabs folder but used in Levels.xml");

        foreach (string prefab in resPrefabSet.Except(xmlPrefabSet).ToList())
            Debug.Log(prefab + " exists in the /Resorces/Prefabs folder but not used in Levels.xml");

        Debug.Log("Cross Check Done");
    }

    private static void getResPrefabs(HashSet<string> resPrefabList)
    {
        
        DirectoryInfo dir = new DirectoryInfo("Assets/Resources/Prefabs");
        FileInfo[] fileInfos = dir.GetFiles("*.prefab");
        fileInfos.Select(f => f.FullName).ToArray();

        
        foreach (FileInfo fileInfo in fileInfos)
        {
            resPrefabList.Add(fileInfo.Name.Substring(0, fileInfo.Name.Length - ".prefab".Length));
        }
    }

    private static void getLevelPrefabs(HashSet<string> xmlPrefabSet)
    {
        DeserializedLevels deserializedLevels = XmlIO.LoadXml<DeserializedLevels>("Levels");
        foreach (DeserializedLevels.Level level in deserializedLevels.levels)
        {
            foreach (DeserializedLevels.Item item in level.items)
            {
               xmlPrefabSet.Add(item.prefab);
            }
        }
    }

}
