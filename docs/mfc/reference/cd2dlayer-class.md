---
title: Classe CD2DLayer
ms.date: 11/04/2016
f1_keywords:
- CD2DLayer
- AFXRENDERTARGET/CD2DLayer
- AFXRENDERTARGET/CD2DLayer::CD2DLayer
- AFXRENDERTARGET/CD2DLayer::Attach
- AFXRENDERTARGET/CD2DLayer::Create
- AFXRENDERTARGET/CD2DLayer::Destroy
- AFXRENDERTARGET/CD2DLayer::Detach
- AFXRENDERTARGET/CD2DLayer::Get
- AFXRENDERTARGET/CD2DLayer::GetSize
- AFXRENDERTARGET/CD2DLayer::IsValid
- AFXRENDERTARGET/CD2DLayer::m_pLayer
helpviewer_keywords:
- CD2DLayer [MFC], CD2DLayer
- CD2DLayer [MFC], Attach
- CD2DLayer [MFC], Create
- CD2DLayer [MFC], Destroy
- CD2DLayer [MFC], Detach
- CD2DLayer [MFC], Get
- CD2DLayer [MFC], GetSize
- CD2DLayer [MFC], IsValid
- CD2DLayer [MFC], m_pLayer
ms.assetid: 2f96378e-66bb-40d1-9661-6afe324de3c1
ms.openlocfilehash: aa6fb313bfcc2983f167936e5ad4f78be1e17a44
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369210"
---
# <a name="cd2dlayer-class"></a>Classe CD2DLayer

Um invólucro para ID2D1Layer.

## <a name="syntax"></a>Sintaxe

```
class CD2DLayer : public CD2DResource;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2Dlayer::CD2Dlayer](#cd2dlayer)|Constrói um objeto CD2DLayer.|
|[CD2Dlayer::~CD2Dlayer](#_dtorcd2dlayer)|O destruidor. Chamado quando um objeto de camada D2D está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DLayer::Anexar](#attach)|Anexa a interface de recurso existente ao objeto|
|[CD2Dlayer::Criar](#create)|Cria um CD2DLayer. (Substitui [cd2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|
|[CD2DLayer::Destroy](#destroy)|Destrói um objeto CD2DLayer. (Substitui [cd2DResource::Destroy](../../mfc/reference/cd2dresource-class.md#destroy).)|
|[CD2DLayer::Detach](#detach)|Destaca a interface de recursos do objeto|
|[CD2Dlayer::Get](#get)|Retorna interface ID2D1Layer|
|[CD2Dlayer::getSize](#getsize)|Retorna o tamanho do destino de renderização em pixels independentes do dispositivo|
|[CD2Dlayer::isValid](#isvalid)|Verifica a validade do recurso (Substitui [cd2DResource::IsValid](../../mfc/reference/cd2dresource-class.md#isvalid).)|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DLayer::operador ID2D1Layer*](#operator_id2d1layer_star)|Retorna interface ID2D1Layer|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2Dlayer::m_pLayer](#m_player)|Armazena um ponteiro para um objeto ID2D1Layer.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

`CD2DLayer`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2dlayercd2dlayer"></a><a name="_dtorcd2dlayer"></a>CD2Dlayer::~CD2Dlayer

O destruidor. Chamado quando um objeto de camada D2D está sendo destruído.

```
virtual ~CD2DLayer();
```

## <a name="cd2dlayerattach"></a><a name="attach"></a>CD2DLayer::Anexar

Anexa a interface de recurso existente ao objeto

```
void Attach(ID2D1Layer* pResource);
```

### <a name="parameters"></a>Parâmetros

*Presource*<br/>
Interface de recurso existente. Não pode ser NULO

## <a name="cd2dlayercd2dlayer"></a><a name="cd2dlayer"></a>CD2Dlayer::CD2Dlayer

Constrói um objeto CD2DLayer.

```
CD2DLayer(
    CRenderTarget* pParentTarget,
    BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pParentTarget*<br/>
Um ponteiro para o alvo de renderização.

*bAutoDestroy*<br/>
Indica que o objeto será destruído pelo proprietário (pParentTarget).

## <a name="cd2dlayercreate"></a><a name="create"></a>CD2Dlayer::Criar

Cria um CD2DLayer.

```
virtual HRESULT Create(CRenderTarget* pRenderTarget);
```

### <a name="parameters"></a>Parâmetros

*pRenderTarget*<br/>
Um ponteiro para o alvo de renderização.

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.

## <a name="cd2dlayerdestroy"></a><a name="destroy"></a>CD2DLayer::Destroy

Destrói um objeto CD2DLayer.

```
virtual void Destroy();
```

## <a name="cd2dlayerdetach"></a><a name="detach"></a>CD2DLayer::Detach

Destaca a interface de recursos do objeto

```
ID2D1Layer* Detach();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para interface de recurso separada.

## <a name="cd2dlayerget"></a><a name="get"></a>CD2Dlayer::Get

Retorna interface ID2D1Layer

```
ID2D1Layer* Get();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1Layer ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dlayergetsize"></a><a name="getsize"></a>CD2Dlayer::getSize

Retorna o tamanho do destino de renderização em pixels independentes do dispositivo

```
CD2DSizeF GetSize() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho atual do destino de renderização em pixels independentes do dispositivo

## <a name="cd2dlayerisvalid"></a><a name="isvalid"></a>CD2Dlayer::isValid

Verifica a validade dos recursos

```
virtual BOOL IsValid() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o recurso for válido; caso contrário, FALSO.

## <a name="cd2dlayerm_player"></a><a name="m_player"></a>CD2Dlayer::m_pLayer

Armazena um ponteiro para um objeto ID2D1Layer.

```
ID2D1Layer* m_pLayer;
```

## <a name="cd2dlayeroperator-id2d1layer"></a><a name="operator_id2d1layer_star"></a>CD2DLayer::operador ID2D1Layer*

Retorna interface ID2D1Layer

```
operator ID2D1Layer* ();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1Layer ou NULL se o objeto ainda não estiver inicializado.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
