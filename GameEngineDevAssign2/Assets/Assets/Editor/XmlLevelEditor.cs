using UnityEngine;
using UnityEditor;

public class XmlLevelEditor : EditorWindow
{

    DeserializedLevelsLoader deserializedLevelsLoader;
    DeserializedLevelsSaver deserializedLevelsSaver;
    DeserializedLevelsCrossChecker deserializedLevelsCrossChecker;

    string importGOName = DeserializedLevelsLoader.xmlItemsGOName;
    string exportGOName = DeserializedLevelsSaver.xmlItemsToExportGOName;

    [MenuItem("Window/Xml Level Editor")]
    public static void ShowWindow()
    {
        
        EditorWindow.GetWindow(typeof(XmlLevelEditor));
    }

    void OnGUI()
    {
        
        init();

        
        GUILayout.Label("Import", EditorStyles.boldLabel);
        GUILayout.Label("Import Levels.xml into the scene");

        if (GUILayout.Button("Import Levels.xml"))
            deserializedLevelsLoader.generateItems();


       
        GUILayout.Label("Export", EditorStyles.boldLabel);
        GUILayout.Label("Export children of \"" + exportGOName + "\" GameObject into " + exportGOName + ".xml", EditorStyles.wordWrappedLabel);
        if (GUILayout.Button("Export " + exportGOName))
            deserializedLevelsSaver.saveExportItems();


        
        GUILayout.Label("Delete", EditorStyles.boldLabel);
        GUILayout.Label("Delete " + importGOName + " and " + exportGOName + " GameObjects from scene", EditorStyles.wordWrappedLabel);
        if (GUILayout.Button("Delete"))
        {
            DestroyImmediate(GameObject.Find(importGOName));
            DestroyImmediate(GameObject.Find(exportGOName));
        }


        
        GUILayout.Label("Cross Check", EditorStyles.boldLabel);
        GUILayout.Label("Cross check /Resources/Prefabs and Levels.xml if there are any item prefabs that exist only in one but not the other", EditorStyles.wordWrappedLabel);
        if (GUILayout.Button("Cross Check"))
            deserializedLevelsCrossChecker.crossCheck();
    }

    private void init()
    {
        if (deserializedLevelsLoader == null) deserializedLevelsLoader = new DeserializedLevelsLoader();
        if (deserializedLevelsSaver == null) deserializedLevelsSaver = new DeserializedLevelsSaver();
        if (deserializedLevelsCrossChecker == null) deserializedLevelsCrossChecker = new DeserializedLevelsCrossChecker();
    }

}
