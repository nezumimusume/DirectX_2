/*!
 *@brief	�Q�[���e���v���[�g�B
 */
#include "stdafx.h"
#include "myEngine/Graphics/Camera.h"
#include "myEngine/Graphics/Light.h"
#include "game.h"

Game* game;

//-----------------------------------------------------------------------------
// Name: �Q�[�����������B
//-----------------------------------------------------------------------------
void Init()
{
	game = new Game;
	game->Start();
}
//-----------------------------------------------------------------------------
// Name: �`�揈���B
//-----------------------------------------------------------------------------
VOID Render()
{
	// ��ʂ��N���A�B
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
	//�V�[���̕`��J�n�B
	g_pd3dDevice->BeginScene();

	game->Render();

	// �V�[���̕`��I���B
	g_pd3dDevice->EndScene();
	// �o�b�N�o�b�t�@�ƃt�����g�o�b�t�@�����ւ���B
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}
/*!-----------------------------------------------------------------------------
 *@brief	�X�V�����B
 -----------------------------------------------------------------------------*/
void Update()
{
	game->Update();
}
//-----------------------------------------------------------------------------
//�Q�[�����I������Ƃ��ɌĂ΂�鏈���B
//-----------------------------------------------------------------------------
void Terminate()
{
	delete game;
	delete g_effectManager;
	g_pd3dDevice->Release();
	g_pD3D->Release();
}