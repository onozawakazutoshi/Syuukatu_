#include <Windows.h>
#include <KamataEngine.h>
#include"GameScene.h"
#include "Title.h"
	
using namespace KamataEngine;

GameScene* gameScene = new GameScene();
Title* title = new Title();

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	KamataEngine::Initialize();
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	gameScene->Initialize();
	title->Initialize();
	int switch_on = 1;
	

	while (true) {
		if (KamataEngine::Update()) {

			break;
		}
		gameScene->Update();

		switch (switch_on) {
		default:
			break;
		case 0:

			title->Update();
			dxCommon->PreDraw();
			title->Draw(dxCommon->GetCommandList());
			dxCommon->PostDraw();
			break;

		case 1:
			dxCommon->PreDraw();
			gameScene->Draw(dxCommon->GetCommandList());
			dxCommon->PostDraw();
			break;

		}
		
		
	}

	
	KamataEngine::Finalize();

	return 0;
}
