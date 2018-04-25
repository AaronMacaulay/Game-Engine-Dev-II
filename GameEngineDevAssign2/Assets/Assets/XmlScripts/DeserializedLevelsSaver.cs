using UnityEngine;
using System.Collections.Generic;
using System.Xml;

public class DeserializedLevelsSaver
{
    public const string xmlItemsToExportGOName = "XmlItemsToExport";

    public void saveExportItems()
    {
        GameObject xmlItemsToExportGO;

        
        if (GameObject.Find(xmlItemsToExportGOName) == null)
        {
            xmlItemsToExportGO = new GameObject(xmlItemsToExportGOName);
            
            return;
        }
        else
        {
            xmlItemsToExportGO = GameObject.Find(xmlItemsToExportGOName);
        }

        Transform[] xmlItemsToExportGOchildren = xmlItemsToExportGO.GetComponentsInChildren<Transform>();

        
        if (xmlItemsToExportGOchildren.Length == 1)
        {
            Debug.LogError("Add the prefabs to " + xmlItemsToExportGOName);
            return;
        }

        
        List<DeserializedLevels.Item> itemList = new List<DeserializedLevels.Item>();

        foreach (Transform item in xmlItemsToExportGOchildren)
        {
            if (item.parent == xmlItemsToExportGO.transform)
            {
                itemList.Add(new DeserializedLevels.Item(item));
            }
        }

        
        DeserializedLevels.Level levelXml = new DeserializedLevels.Level();
        levelXml.items = new DeserializedLevels.Item[itemList.Count];
        itemList.CopyTo(levelXml.items);

        
        DeserializedLevels levelsXmlToExport = new DeserializedLevels();
        levelsXmlToExport.levels = new DeserializedLevels.Level[1];
        levelsXmlToExport.levels[0] = levelXml;

        string outputFilePath = "./Assets/Resources/" + xmlItemsToExportGOName + ".xml";
        XmlIO.SaveXml<DeserializedLevels>(levelsXmlToExport, outputFilePath);
    }

    public static string toStringNullIfZero(float num)
    {
        return num == 0 ? null : mathRound(num, 2).ToString();
    }

    public static string toStringNullIfOne(float num)
    {
        return num == 1 ? null : mathRound(num, 2).ToString();
    }

    public static float mathRound(float round, int decimals)
    {
        return Mathf.Round(round * Mathf.Pow(10, decimals)) / Mathf.Pow(10, decimals);
    }
}
