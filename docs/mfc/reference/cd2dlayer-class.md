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
ms.openlocfilehash: 28ebe19b0f28692116a0b95721ff2e5490ad7e68
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57270848"
---
# <a name="cd2dlayer-class"></a>Classe CD2DLayer

Um wrapper para ID2D1Layer.

## <a name="syntax"></a>Sintaxe

```
class CD2DLayer : public CD2DResource;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DLayer::CD2DLayer](#cd2dlayer)|Constrói um objeto CD2DLayer.|
|[CD2DLayer:: ~ CD2DLayer](#_dtorcd2dlayer)|O destruidor. Chamado quando um objeto de camada D2D está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DLayer::Attach](#attach)|Anexa existente de interface de recurso para o objeto|
|[CD2DLayer::Create](#create)|Cria um CD2DLayer. (Substitui [CD2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|
|[CD2DLayer::Destroy](#destroy)|Destrói um objeto CD2DLayer. (Substitui [CD2DResource::Destroy](../../mfc/reference/cd2dresource-class.md#destroy).)|
|[CD2DLayer::Detach](#detach)|Desanexa a interface do recurso do objeto|
|[CD2DLayer::Get](#get)|Interface de ID2D1Layer retorna|
|[CD2DLayer::GetSize](#getsize)|Retorna o tamanho do destino de renderização em pixels independentes de dispositivo|
|[CD2DLayer::IsValid](#isvalid)|Verifica a validade de recurso (substitui [CD2DResource::IsValid](../../mfc/reference/cd2dresource-class.md#isvalid).)|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DLayer::Operator ID2D1Layer *](#operator_id2d1layer_star)|Interface de ID2D1Layer retorna|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DLayer::m_pLayer](#m_player)|Armazena um ponteiro para um objeto ID2D1Layer.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

`CD2DLayer`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

##  <a name="_dtorcd2dlayer"></a>  CD2DLayer:: ~ CD2DLayer

O destruidor. Chamado quando um objeto de camada D2D está sendo destruído.

```
virtual ~CD2DLayer();
```

##  <a name="attach"></a>  CD2DLayer::Attach

Anexa existente de interface de recurso para o objeto

```
void Attach(ID2D1Layer* pResource);
```

### <a name="parameters"></a>Parâmetros

*pResource*<br/>
Interface de recursos existente. Não pode ser NULL

##  <a name="cd2dlayer"></a>  CD2DLayer::CD2DLayer

Constrói um objeto CD2DLayer.

```
CD2DLayer(
    CRenderTarget* pParentTarget,
    BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pParentTarget*<br/>
Um ponteiro para o destino de renderização.

*bAutoDestroy*<br/>
Indica se o objeto será destruído pelo proprietário (pParentTarget).

##  <a name="create"></a>  CD2DLayer::Create

Cria um CD2DLayer.

```
virtual HRESULT Create(CRenderTarget* pRenderTarget);
```

### <a name="parameters"></a>Parâmetros

*pRenderTarget*<br/>
Um ponteiro para o destino de renderização.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retornará um código de erro HRESULT.

##  <a name="destroy"></a>  CD2DLayer::Destroy

Destrói um objeto CD2DLayer.

```
virtual void Destroy();
```

##  <a name="detach"></a>  CD2DLayer::Detach

Desanexa a interface do recurso do objeto

```
ID2D1Layer* Detach();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para interface de recurso desanexado.

##  <a name="get"></a>  CD2DLayer::Get

Interface de ID2D1Layer retorna

```
ID2D1Layer* Get();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para uma interface ID2D1Layer ou NULL se o objeto ainda não foi inicializado.

##  <a name="getsize"></a>  CD2DLayer::GetSize

Retorna o tamanho do destino de renderização em pixels independentes de dispositivo

```
CD2DSizeF GetSize() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho atual do destino de renderização em pixels independentes de dispositivo

##  <a name="isvalid"></a>  CD2DLayer::IsValid

Verificações de validade de recurso

```
virtual BOOL IsValid() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o recurso for válido. Caso contrário, FALSE.

##  <a name="m_player"></a>  CD2DLayer::m_pLayer

Armazena um ponteiro para um objeto ID2D1Layer.

```
ID2D1Layer* m_pLayer;
```

##  <a name="operator_id2d1layer_star"></a>  CD2DLayer::operator ID2D1Layer*

Interface de ID2D1Layer retorna

```
operator ID2D1Layer* ();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para uma interface ID2D1Layer ou NULL se o objeto ainda não foi inicializado.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
