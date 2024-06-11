
#定义_ CRT _ SECURE _ NO _ WARNINGS
#包括"骗子h "
#包括"抵消h "
#包括"资源/语言h "
#包括"实用程序/初始/初始化h "
#包括"Utils/ConfigSaver .hpp"
#包括<慢性的>
#包括<文件系统>
#包括《伊奥曼尼普》
#包括《已知文件夹h >
#包括《什洛布》.h >
#包括《标准》杂志.h >
#包括"实用工具/卷曲/卷曲h "
#包括" Utils/json/json .hpp”
使用 命名空间标准
/*
贡献者：
Shinyaluvs，
Nx0Ri，
字节库,
斯卡博,
佩德罗贡萨尔维斯,
KeysIsCool，
肯尼,
Cr1ppl3，
泰利苏,
sh1pi，
托福考试,
流行音乐节目主持人神圣的,
托基纳阿,
更快_bbc、
vsantos1，
5mmod，
gScream，
哈泽蒂克,
冥河,
用户1232,
TaKaStuKi.sen
*/

命名空间fs =文件系统；
布尔otp =错误的；
字符串文件名；

空的出口()
{
系统("暂停");
出口(0);
}

LRESULT回调WndProc(HWND hwnd消息WPARAM wParam，LPARAM lParam);

空的随机标题()
{
constexprint长度=25;
常数 汽车字符=文本(“0123456789abcdefghijklmnopqrstuvwxyzabbdefghijklmnopqrstuvwxyz `-= ~！@#$%^&*()_+,./;'[]|{}:?");
TCHAR头衔[长度+1]{};

	为 (int j =0；j！=长度；j++)
	{
标题[j]+=字符[边缘() % 95];
	}

setconsolettitle(标题);
}


使用JSON = nlohmann::JSON；


静电尺寸_t写回调(无效*内容，size_t size，size_t nmemb，void* userp) {
	((std::string*)userp)->附加((字符*)内容,大小* nmemb);
返回大小* nmemb
}



bool checkHWIDFromURL(const std::string& url, const std::string& hwid) {
	CURL* curl;
	CURLcode res;
	std::string readBuffer;
	json jData;

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);


		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);

		if (res != CURLE_OK) {
			std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << '\n';
			return false;
		}

		jData = json::parse(readBuffer);
	}

	for (const auto& element : jData) {
		if (element.get<std::string>() == hwid) {
			return true;
		}
	}
	return false;
}

void Cheat()
{
	MenuConfig::HWID = Init::Client::GenerateHWID();
	//if (checkHWIDFromURL("http://aimstar.tkm.icu/drm", MenuConfig::HWID.substr(MenuConfig::HWID.length() - 16).c_str()))
	//	MenuConfig::Ban = true;
	if (Init::Verify::CheckWindowVersion())
	{
		Lang::GetCountry(MenuConfig::Country);
		MenuConfig::MaxFrameRate = Init::Client::getMaxFrameRate();
	}
		
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	//Gets a standard output device handle  
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);	//Set the text color to green  
	srand((unsigned)time(NULL));
	RandomTitle();
	cout << R"(                                                                   
    ___    _          _____ __            
   /   |  (_)___ ___ / ___// /_____ ______
  / /| | / / __ `__ \\__ \/ __/ __ `/ ___/
 / ___ |/ / / / / / /__/ / /_/ /_/ / /    
/_/  |_/_/_/ /_/ /_/____/\__/\__,_/_/    
	)" << endl;
	printf("Build-%s-%s\n", __DATE__, __TIME__);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

	auto ProcessStatus = ProcessMgr.Attach("cs2.exe");

	char documentsPath[MAX_PATH];
	if (SHGetFolderPathA(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath) != S_OK) {
		cerr << "[Info] Error: Failed to get the Documents folder path." << endl;
		Exit();
	}
	MenuConfig::path = documentsPath;
	MenuConfig::path += "\\AimStar";

	switch (ProcessStatus) {
	case 1:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "[ERROR] Please launch the game first!" << endl;
		Exit();
	case 2:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "[ERROR] Failed to hook process, please run the cheat as Administrator (Right click AimStar > Run as Adminstrator)." << endl;
		Exit();
	case 3:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "[ERROR] Failed to get module address." << endl;
		Exit();
	default:
		break;
	}
/*
	if (!Offset::UpdateOffsets())
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "[ERROR] Failed to update offsets." << endl;
		Exit();
	}
*/
	if (!gGame.InitAddress())
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "[ERROR] Failed to call InitAddress()." << endl;
		Exit();
	}

	cout << "[Game] Process ID: " << ProcessMgr.ProcessID << endl;
	cout << "[Game] Client Address: " << gGame.GetClientDLLAddress() << endl;

	if (fs::exists(MenuConfig::path))
	{
		cout << "[Info] Config folder connected: " << MenuConfig::path << endl;
	}
	else
	{
		if (fs::create_directory(MenuConfig::path))
		{
			cout << "[Info] Config folder created: " << MenuConfig::path << endl;
		}
		else
		{
			cerr << "[Info] Error: Failed to create the config directory." << endl;
			Exit();
		}
	}

	ifstream defaultConfig(MenuConfig::path + "\\default.yml");
	if (defaultConfig.is_open())
	{
		MenuConfig::defaultConfig = true;
		defaultConfig.close();		
	}

	cout << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "Cheat running successfully!" << endl;
	cout << "Press [INS] or [DEL] to show or hide Menu." << endl;
	cout << "Have fun..." << endl << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "=======[ Offset List ]=======" << endl;
	cout << setw(23) << left << "EntityList:" << setiosflags(ios::uppercase) << hex << Offset::EntityList << endl;
	cout << setw(23) << left << "Matrix:" << setiosflags(ios::uppercase) << hex << Offset::Matrix << endl;
	cout << setw(23) << left << "LocalPlayerController:" << setiosflags(ios::uppercase) << hex << Offset::LocalPlayerController << endl;
	cout << setw(23) << left << "ViewAngles:" << setiosflags(ios::uppercase) << hex << Offset::ViewAngle << endl;
	cout << setw(23) << left << "LocalPlayerPawn:" << setiosflags(ios::uppercase) << hex << Offset::LocalPlayerPawn << endl;
	cout << setw(23) << left << "PlantedC4:" << setiosflags(ios::uppercase) << hex << Offset::PlantedC4 << endl;
	cout << setw(23) << left << "ForceJump:" << setiosflags(ios::uppercase) << hex << Offset::ForceJump << endl;
	cout << setw(23) << left << "Sensitivity:" << setiosflags(ios::uppercase) << hex << Offset::Sensitivity << endl;
	// cout << setw(23) << left << "ForceCrouch:" << setiosflags(ios::uppercase) << hex << Offset::ForceCrouch << endl;
	// cout << setw(23) << left << "ForceForward:" << setiosflags(ios::uppercase) << hex << Offset::ForceForward << endl;
	// cout << setw(23) << left << "ForceLeft:" << setiosflags(ios::uppercase) << hex << Offset::ForceLeft << endl;
	// cout << setw(23) << left << "ForceRight:" << setiosflags(ios::uppercase) << hex << Offset::ForceRight << endl;
	// cout << setw(23) << left << "TestPointer:" << setiosflags(ios::uppercase) << hex << Offset::Pointer << endl;
	cout << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

	try
	{
		Gui.AttachAnotherWindow("Counter-Strike 2", "SDL_app", Cheats::Run);
	}
	catch (OSImGui::OSException& e)
	{
		try
		{
			// Perfect World version
			Gui.AttachAnotherWindow("\u53cd\u6050\u7cbe\u82f1\uff1a\u5168\u7403\u653b\u52bf", "SDL_app", Cheats::Run);
		}
		catch (OSImGui::OSException& e)
		{
			cout << e.what() << endl;
		}
	}
}

int main(void)
{
	const char* tempPath = std::getenv("TMP");
	if (tempPath != nullptr)
	{
		fileName = std::string(tempPath) + "\\Aimstar";
		otp = Init::Verify::isVerified(fileName);
	}

	Cheat();
}




LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	//bool showed = false;
	if (!otp /*&& !showed*/)
	{
		cout << "Please enter your OTP code! Get the OTP code from: https://aimstar.tkm.icu" << endl;
		//showed = true;
	}
	static int RetTimes = 0;

	switch (message) {
        case WM_CREATE:
	{
		CreateWindowW(L"STATIC", L"Please enter your OTP code:",
			WS_VISIBLE | WS_CHILD | SS_CENTER,
			50, 20, 300, 20, hwnd, NULL, NULL, NULL);
		CreateWindowW(L"EDIT", L"",
			WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
			100, 50, 200, 20, hwnd, (HMENU)2, NULL, NULL);
		CreateWindowW(L"BUTTON", L"Verify",
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			215, 90, 70, 30, hwnd, (HMENU)1, NULL, NULL);
		CreateWindowW(L"BUTTON", L"Get OTP",
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			115, 90, 70, 30, hwnd, (HMENU)3, NULL, NULL);
		break;
	}
	case WM_COMMAND:
	{
		if (LOWORD(wParam) == 1) {
			wchar_t buffer[10];
			GetWindowTextW(GetDlgItem(hwnd, 2), buffer, 10);
			wstring ws(buffer);
			string input(ws.begin(), ws.end());
			string time, code;
			Init::Verify::CodeGenerate(time, code);

			if (input != code) {
				RetTimes++;
				if (RetTimes < 3) {
					MessageBox(hwnd, L"OTP code error!!", L"Error", MB_OK | MB_ICONERROR);
				}
				else {
					MessageBox(hwnd, L"Exceeded maximum attempts.", L"Error", MB_OK | MB_ICONERROR);
					DestroyWindow(hwnd);
					Init::Client::QuitGame();
					Exit();
				}
			}
			else {
				otp = true;
				std::ofstream outfile(fileName);
				outfile.close();
				ShowWindow(hwnd, SW_HIDE);
				system("cls");
				Cheat();
			}
		}
		if (LOWORD(wParam) == 3)
		{
			ShellExecuteA(NULL, "open", "https://aimstar.tkm.icu", NULL, NULL, SW_SHOWNORMAL);
			// ShellExecute(NULL, TEXT("open"), TEXT("https://aimstar.tkm.icu"), NULL, NULL, SW_SHOWNORMAL);
		}
		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
