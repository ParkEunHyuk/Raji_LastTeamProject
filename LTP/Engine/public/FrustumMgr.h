#pragma once
#include "Base.h"

BEGIN(Engine)
class CFrustumMgr :public CBase
{
	DECLARE_SINGLETON(CFrustumMgr);

private:
	explicit CFrustumMgr();
	virtual ~CFrustumMgr() = default;

public:
	HRESULT Initialize_FrustumMgr(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);

public:
	//�� �Լ��� �� ������ �� �ѹ��� ���� ������ �� ������ ���� ����, �� ������״ϱ� 
	HRESULT SetUp_WorldFrustumPlane();
	HRESULT SetUp_LightFrustumPlane();

	//�� �Լ��� ���� ��ü���� �����ؼ� �׷������� ���θ� �Ǵ�
	_bool IsNeedToRender(_float3 vWorldPosition, _float fLenth = 1.4142135623f);
	_bool IsNeedToLightRender(_float3 vWorldPosition, _float fLenth = 1.4142135623f);

private:
	_float3 vDefaultProjectFrustumCubePos[8];
	_float4 tWorldFrustumPlane[6];
	_float4 tLightFrustumPlane[6];

private:
	ID3D11Device*			m_pDevice = nullptr;
	ID3D11DeviceContext*	m_pDeviceContext = nullptr;

public:
	virtual void Free() override;

};
END
