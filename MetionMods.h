//MMBH VERSION 0.1.d1.b1
//MMBH(Metion Mod Build Headerfile)
#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;

namespace metmod//Metion Mod Library, Support and Registration
{
	class Modreger
	{
		public:
			//ready to registration the Metion Mod
				//Info
				string ModName = "MetionMod";
				string ModID = "mmod";
				string ModPackID = "mmod.metion.mod";
				string ModCr = "Create Name";
				string ModDcr = "A Metion Mod let Windows experience better.";
				string ModVer = "1.0.s1";
				string ModMMBHVer = "0.1.d1.b1";
				//Config and APIO Path
				string ModFP = "\\MetionMod";
				string ModCFP = "\\MetionMod\\config";
				string ModAPIOP = "\\MetionMod\\apio";
				string ModPath = "\\MetionMod.exe";
			//A Metion Mod must need have a folder and it name it's ModName otherwise the mod is invalid
			//The mod config file and mods folder do not match and are invalid
			//Absolute Path!!!!!!
			//only when the mod is in the mods folder can the mod be loaded by metion
			//Therefore, the mod developer should at least install documentation for the whole mod
			//Some user who use your mod are f**k stupid and scold if they cannot read the document, so forget I just said
			
			//Registration the mod
				int regmod();
	};
	//Every metion mod must edit the reg info and regmod() otherwise the mod is invalid
	int Modreger::regmod()
	{
		std::wstring wModFP(ModFP.begin(), ModFP.end());
		CreateDirectoryW(wModFP.c_str(), NULL);

		std::wstring wModCFP(ModCFP.begin(), ModCFP.end());
		CreateDirectoryW(wModCFP.c_str(), NULL);

		std::wstring wModAPIOP(ModAPIOP.begin(), ModAPIOP.end());
		CreateDirectoryW(wModAPIOP.c_str(), NULL);

		ofstream file(ModFP+"\\mod.info");//Create ofs to manage infofile

		file.is_open();//open it

		string infoinput;
		infoinput =
			  "ModName:" + ModName + "\n"
			+ "ModID:" + ModID + "\n"
			+ "ModPackID:" + ModPackID + "\n"
			+ "ModCr:" + ModCr + "\n"
			+ "ModDcr:" + ModDcr + "\n"
			+ "ModVer:" + ModVer + "\n"
			+ "ModMMBHVer:" + ModMMBHVer + "\n"
			+ "ModFP:" + ModFP + "\n"
			+ "ModCFP:" + ModCFP + "\n"
			+ "ModAPIOP:" + ModAPIOP + "\n"
			+ "ModPath:" + ModPath + "\n";

		file << infoinput << endl;//write

		file.close();
	}
}