#include <Windows.h>
#include <KamataEngine.h>
#include"GameScene.h"
#include "Title.h"
#include "TitleChange.h"
	
using namespace KamataEngine;

GameScene* gameScene = new GameScene();
Title* title = new Title();
TitleChange* titleChange = new TitleChange();

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	KamataEngine::Initialize();
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	gameScene->Initialize();
	title->Initialize();
	titleChange->Initialize();
	int switch_on = 0;
	

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
			
			if (title->IsGameChange()) {
				switch_on = 2;
			}
			break;

		case 1:
			dxCommon->PreDraw();
			gameScene->Draw(dxCommon->GetCommandList());
			dxCommon->PostDraw();
			

			break;

		case 2:
			titleChange->Update();
			dxCommon->PreDraw();
			if (titleChange->IsTitleChange()) {
				title->Draw(dxCommon->GetCommandList());
			} else {
				gameScene->Draw(dxCommon->GetCommandList());
			}
			titleChange->Draw(dxCommon->GetCommandList());
			dxCommon->PostDraw();

			break;
		}
		
		
	}

	
	KamataEngine::Finalize();

	return 0;
}
