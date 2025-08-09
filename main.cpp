#include <Windows.h>
#include"GameScene.h"

GameScene* gameScene = new GameScene();

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	KamataEngine::Initialize();
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	gameScene->Initialize();

	while (true) {
		
		gameScene->Update();


		dxCommon->PreDraw();
		gameScene->Draw(dxCommon->GetCommandList());
		dxCommon->PostDraw();
		
	}

	


	return 0;
}
