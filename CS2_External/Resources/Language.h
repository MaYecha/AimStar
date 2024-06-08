#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma once
#include "..\Font\IconsFontAwesome5.h"
#include <iostream>
#include <string>
#include <windows.h>

namespace Lang
{
	inline static void GetCountry(std::string& Country)
	{
		LCID lcid = GetUserDefaultLCID();
		wchar_t CountryW[256];
		GetUserDefaultGeoName(CountryW, sizeof(CountryW) / sizeof(CountryW[0]));

		int len = WideCharToMultiByte(CP_UTF8, 0, CountryW, -1, nullptr, 0, nullptr, nullptr);
		char* String = new char[len];
		WideCharToMultiByte(CP_UTF8, 0, CountryW, -1, String, len, nullptr, nullptr);
		std::string utf8String(String);
		Country = String;

		delete[] String;
		return;
	}
	
	inline struct Global
	{
		inline static const char* Date;
		inline static const char* Author;

		inline static const char* SwitchButton;
		inline static const char* FeatureSettings;
	} Global;

	inline struct ESPtext
	{
		inline static const char* Toggle;
		inline static const char* FeatureName;
		inline static const char* Box;
		inline static const char* BoxRounding;
		inline static const char* FilledBox;
		inline static const char* FilledAlpha;
		inline static const char* Skeleton;
		inline static const char* HeadBox;
		inline static const char* EyeRay;
		inline static const char* HealthBar;
		inline static const char* Weapon;
		inline static const char* Distance;
		inline static const char* PlayerName;
		inline static const char* SnapLine;
		inline static const char* LinePosList;
		inline static const char* VisCheck;
		inline static const char* Preview;
		inline static const char* CollapseHead;
		inline static const char* Penis;
		inline static const char* PenisLength;
		inline static const char* PenisSize;
		inline static const char* MultiColor;
		inline static const char* MultiColTip;
		inline static const char* Outline;
		inline static const char* BoxType;
		inline static const char* HealthNum;
		inline static const char* Ammo;
		inline static const char* ScopedESP;
		inline static const char* ShowArmorBar;
		inline static const char* ArmorNum;
		inline static const char* RenderDistance;

		inline static const char* BoxType_Normal;
		inline static const char* BoxType_Edge;
		inline static const char* BoxType_Corner;
		inline static const char* BarType_Top;
		inline static const char* BarType_Vertical;
		inline static const char* HeadBoxType_Normal;
		inline static const char* HeadBoxType_Flat;
		inline static const char* LinePos_1;
		inline static const char* LinePos_2;
		inline static const char* LinePos_3;
	} ESPtext;

	inline struct AimbotText
	{
		inline static const char* Enable;
		inline static const char* FeatureName;
		inline static const char* HotKeyList;
		inline static const char* Toggle;
		inline static const char* DrawFov;
		inline static const char* VisCheck;
		inline static const char* JumpCheck;
		inline static const char* FovSlider;
		inline static const char* FovMinSlider;
		inline static const char* SmoothSlider;
		inline static const char* BoneList;
		inline static const char* Tip;
		inline static const char* ScopeOnly;
		inline static const char* AimLock;
		inline static const char* AutoShot;
		inline static const char* BulletSlider;
		inline static const char* IgnoreFlash;
		inline static const char* Ragebot;

		inline static const char* Bone_1;
		inline static const char* Bone_2;
		inline static const char* Bone_3;
		inline static const char* Bone_4;
	} AimbotText;

	inline struct RCStext
	{
		inline static const char* Toggle;
		inline static const char* Yaw;
		inline static const char* Pitch;
	} RCStext;

	inline struct RadarText
	{
		inline static const char* Toggle;
		inline static const char* FeatureName;
		inline static const char* StyleList;
		inline static const char* CustomCheck;
		inline static const char* CrossLine;
		inline static const char* SizeSlider;
		inline static const char* ProportionSlider;
		inline static const char* RangeSlider;
		inline static const char* AlphaSlider;

		inline static const char* Style_1;
		inline static const char* Style_2;
		inline static const char* Style_3;
	} RadarText;

	inline struct TriggerText
	{
		inline static const char* Enable;
		inline static const char* FeatureName;
		inline static const char* HotKeyList;
		inline static const char* Toggle;
		inline static const char* ScopeOnly;
		inline static const char* DelaySlider;
		inline static const char* FakeShotSlider;
	} TriggerText;

	inline struct CrosshairsText
	{
		inline static const char* Toggle;
		inline static const char* FeatureName;
		inline static const char* PresetList;
		inline static const char* ColorEditor;
		inline static const char* Dot;
		inline static const char* DotSizeSlider;
		inline static const char* Outline;
		inline static const char* Crossline;
		inline static const char* hLengthSlider;
		inline static const char* vLengthSilder;
		inline static const char* GapSlider;
		inline static const char* ThicknessSlider;
		inline static const char* tStyle;
		inline static const char* Circle;
		inline static const char* RadiusSlider;
		inline static const char* TargetCheck;
		inline static const char* TeamCheck;
	} CrosshairsText;

	inline struct MiscText
	{
		inline static const char* FeatureName;
		inline static const char* ThemeList;
		inline static const char* StyleList;
		inline static const char* HeadshotLine;
		inline static const char* SpecCheck;
		inline static const char* NoFlash;
		inline static const char* FastStop;
		inline static const char* HitSound;
		inline static const char* bmbTimer;
		inline static const char* SpecList;
		inline static const char* Bhop;
		inline static const char* Watermark;
		inline static const char* CheatList;
		inline static const char* TeamCheck;
		inline static const char* AntiRecord;
		inline static const char* MoneyService;
		inline static const char* ShowCashSpent;
		inline static const char* EnemySensor;
		inline static const char* RadarHack;
		inline static const char* NoSmoke;
		inline static const char* SmokeColor;
		inline static const char* fovchanger;
		inline static const char* ForceScope;
		inline static const char* FlashImmunity;
		inline static const char* NightMode;
		inline static const char* Alpha;
		inline static const char* JumpThrow;
		
		inline static const char* FakeDuck;

		inline static const char* LanguageList;

		inline static const char* VisCheckDisable;
	} MiscText;

	inline struct ConfigText
	{
		inline static const char* FeatureName;
		inline static const char* Load;
		inline static const char* Save;
		inline static const char* Delete;
		inline static const char* Reset;
		inline static const char* Create;
		inline static const char* OpenFolder;
		inline static const char* SeparateLine;
		inline static const char* MyConfigs;
		inline static const char* AuthorName;
		inline static const char* ConfigName;

		inline static const char* SafeMode;
		inline static const char* fpsCap;
		inline static const char* SafeModeHoveredTip;
	} ConfigText;

	inline struct ReadMeText
	{
		inline static const char* FeatureName;
		inline static const char* LastUpdate;
		inline static const char* SourceButton;
		inline static const char* DiscordButton;
		inline static const char* OffsetsTitle;
	} ReadMeText;

	inline void English()
	{
		Global.Date = u8"None";
		Global.Author = u8"None";

		Global.SwitchButton = u8"Enable";
		Global.FeatureSettings = u8"Settings";

		// ESP
		ESPtext.Toggle = u8"总开关";
		ESPtext.FeatureName = u8" ESP";
		ESPtext.Box = u8"方框";
		ESPtext.BoxRounding = u8"圆角化:";
		ESPtext.FilledBox = u8"填充方框";
		ESPtext.FilledAlpha = u8"填充透明度";
		ESPtext.Skeleton = u8"骨骼";
		ESPtext.HeadBox = u8"头部方框";
		ESPtext.EyeRay = u8"视线朝向";
		ESPtext.HealthBar = u8"生命栏";
		ESPtext.Weapon = u8"武器";
		ESPtext.Distance = u8"距离";
		ESPtext.PlayerName = u8"玩家名";
		ESPtext.SnapLine = u8"射线";
		ESPtext.LinePosList = u8"射线位置:";
		ESPtext.VisCheck = u8"可视检查";
		ESPtext.Preview = u8"效果预览";
		ESPtext.CollapseHead = u8"性感设置";
		ESPtext.Penis = u8"显示牛子";
		ESPtext.PenisLength = u8"牛子长度";
		ESPtext.PenisSize = u8"牛子粗细";
		ESPtext.MultiColor = u8"渐变色";
		ESPtext.MultiColTip = u8"仅在圆角度为0时显示.";
		ESPtext.Outline = u8"轮廓线";
		ESPtext.BoxType = u8"方框样式:";
		ESPtext.HealthNum = u8"生命数值";
		ESPtext.Ammo = u8"弹夹栏";
		ESPtext.ScopedESP = u8"开镜状态";
		ESPtext.ShowArmorBar = u8"盔甲栏";
		ESPtext.ArmorNum = u8"盔甲数值";
		ESPtext.RenderDistance = u8"最远显示距离: ";

		ESPtext.BoxType_Normal = u8"正常";
		ESPtext.BoxType_Edge = u8"动态";
		ESPtext.BoxType_Corner = u8"四角";
		ESPtext.LinePos_1 = u8"顶部";
		ESPtext.LinePos_2 = u8"中心";
		ESPtext.LinePos_3 = u8"底部";

		// Aimbot
		AimbotText.Enable = u8"启用自瞄";
		AimbotText.FeatureName = u8" 瞄准辅助";
		AimbotText.HotKeyList = u8"热键        ";
		AimbotText.Toggle = u8"开关模式";
		AimbotText.DrawFov = u8"显示范围";
		AimbotText.VisCheck = u8"仅可见目标";
		AimbotText.JumpCheck = u8"仅在地面上";
		AimbotText.FovSlider = u8"自瞄范围: ";
		AimbotText.FovMinSlider = u8"最小自瞄范围: ";
		AimbotText.SmoothSlider = u8"平滑度: ";
		AimbotText.BoneList = u8"瞄准部位  ";
		AimbotText.Tip = u8"此功能在菜单打开时不会工作";
		AimbotText.ScopeOnly = u8"仅开镜";
		AimbotText.AimLock = u8"自动锁定";
		AimbotText.AutoShot = u8"自动开火";
		AimbotText.BulletSlider = u8"从第几枪开始: ";
		AimbotText.IgnoreFlash = u8"无视闪光弹自瞄";
		AimbotText.Ragebot = u8"暴力模式";

		// RCS
		RCStext.Toggle = u8"后座修正";
		RCStext.Yaw = u8"水平偏移量: ";
		RCStext.Pitch = u8"竖直偏移量: ";

		// Radar
		RadarText.Toggle = u8"显示雷达";
		RadarText.FeatureName = u8" 外部雷达";
		RadarText.StyleList = u8"雷达样式";
		RadarText.CustomCheck = u8"自定义设置";
		RadarText.CrossLine = u8"十字线";
		RadarText.SizeSlider = u8"标记大小:";
		RadarText.ProportionSlider = u8"缩放比例:";
		RadarText.RangeSlider = u8"范围:";
		RadarText.AlphaSlider = u8"窗口透明度:";

		// Triggerbot
		TriggerText.Enable = u8"启用扳机";
		TriggerText.FeatureName = u8" 自动扳机";
		TriggerText.HotKeyList = u8"热键    ";
		TriggerText.Toggle = u8"保持激活";
		TriggerText.ScopeOnly = u8"仅开镜";
		TriggerText.DelaySlider = u8"延迟射击:";
		TriggerText.FakeShotSlider = u8"射击持续时间:";

		// Crosshairs
		CrosshairsText.Toggle = u8"显示准星";
		CrosshairsText.FeatureName = u8" 外部准星";
		CrosshairsText.PresetList = u8"预设";
		CrosshairsText.ColorEditor = u8"准星颜色";
		CrosshairsText.Dot = u8"中心点";
		CrosshairsText.DotSizeSlider = u8"中心点大小:";
		CrosshairsText.Outline = u8"轮廓线";
		CrosshairsText.Crossline = u8"十字线";
		CrosshairsText.hLengthSlider = u8"水平长度:";
		CrosshairsText.vLengthSilder = u8"垂直长度:";
		CrosshairsText.GapSlider = u8"间隙:";
		CrosshairsText.ThicknessSlider = u8"粗细:";
		CrosshairsText.tStyle = u8"T形准星";
		CrosshairsText.Circle = u8"圆环";
		CrosshairsText.RadiusSlider = u8"圆环半径:";
		CrosshairsText.TargetCheck = u8"瞄准变色";
		CrosshairsText.TeamCheck = u8"队伍检查";

		// Misc 
		MiscText.FeatureName = u8" 杂项功能";
		MiscText.ThemeList = u8"主题配色       ";
		MiscText.StyleList = u8"窗口样式";
		MiscText.HeadshotLine = u8"爆头线";
		MiscText.SpecCheck = u8"旁观者保持运行";
		MiscText.NoFlash = u8"无视闪光弹";
		MiscText.FastStop = u8"自动急停";
		MiscText.HitSound = u8"命中音效 ";
		MiscText.bmbTimer = u8"C4计时器";
		MiscText.SpecList = u8"旁观者列表";
		MiscText.Bhop = u8"自动连跳";
		MiscText.Watermark = u8"水印浮窗";
		MiscText.CheatList = u8"功能列表";
		MiscText.TeamCheck = u8"阵营判断";
		MiscText.AntiRecord = u8"过OBS";
		MiscText.MoneyService = u8"经济系统";
		MiscText.ShowCashSpent = u8"显示消费";
		MiscText.EnemySensor = u8"发光";
		MiscText.RadarHack = u8"小地图雷达";
		MiscText.VisCheckDisable = u8"可视检查已关闭";
		MiscText.NoSmoke = u8"移除烟雾";
		MiscText.SmokeColor = u8"烟雾颜色";
		MiscText.fovchanger = u8"FOV修改器: ";
		MiscText.ForceScope = u8"总是开镜";
		MiscText.FlashImmunity = u8"闪光免疫成都: ";
		MiscText.NightMode = u8"深色模式";
		MiscText.Alpha = u8"程度: ";
		MiscText.JumpThrow = u8"跳投";

		MiscText.FakeDuck = u8"假蹲";

		MiscText.LanguageList = u8"语言";

		// Config Menu
		ConfigText.FeatureName = u8" 参数配置";
		ConfigText.MyConfigs = u8"我的配置";
		ConfigText.Load = u8"加载选中";
		ConfigText.Save = u8"保存选中";
		ConfigText.Delete = u8"删除选中";
		ConfigText.Reset = u8"重置配置";
		ConfigText.Create = u8"创建配置";
		ConfigText.OpenFolder = u8"打开文件夹";
		ConfigText.SeparateLine = u8"新建配置";
		ConfigText.AuthorName = u8"作者";
		ConfigText.ConfigName = u8"配置名";

		ConfigText.SafeMode = u8"安全模式";
		ConfigText.fpsCap = u8"绘制刷新率: ";
		ConfigText.SafeModeHoveredTip = u8"关闭所有修改内存的功能";

		// Readme Menu
		ReadMeText.FeatureName = u8"README";
		ReadMeText.LastUpdate = u8"最后更新时间: ";
		ReadMeText.SourceButton = u8" ";
		ReadMeText.DiscordButton = u8" ";
		ReadMeText.OffsetsTitle = u8"基址:";
	}
}
