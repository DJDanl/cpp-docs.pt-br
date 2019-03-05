---
title: Classe CD2DResource
ms.date: 11/04/2016
f1_keywords:
- CD2DResource
- AFXRENDERTARGET/CD2DResource
- AFXRENDERTARGET/CD2DResource::CD2DResource
- AFXRENDERTARGET/CD2DResource::Create
- AFXRENDERTARGET/CD2DResource::Destroy
- AFXRENDERTARGET/CD2DResource::IsValid
- AFXRENDERTARGET/CD2DResource::IsAutoDestroy
- AFXRENDERTARGET/CD2DResource::ReCreate
- AFXRENDERTARGET/CD2DResource::m_bIsAutoDestroy
- AFXRENDERTARGET/CD2DResource::m_pParentTarget
helpviewer_keywords:
- CD2DResource [MFC], CD2DResource
- CD2DResource [MFC], Create
- CD2DResource [MFC], Destroy
- CD2DResource [MFC], IsValid
- CD2DResource [MFC], IsAutoDestroy
- CD2DResource [MFC], ReCreate
- CD2DResource [MFC], m_bIsAutoDestroy
- CD2DResource [MFC], m_pParentTarget
ms.assetid: 34e3ee18-aab6-4c39-9294-de869e1f7820
ms.openlocfilehash: 04d1fa57e34528f96f505fa20abb9b1131f80689
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57284860"
---
# <a name="cd2dresource-class"></a>Classe CD2DResource

Uma classe abstrata que fornece uma interface para criar e gerenciar recursos D2D como pincéis, camadas e textos.

## <a name="syntax"></a>Sintaxe

```
class CD2DResource : public CObject;
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DResource::CD2DResource](#cd2dresource)|Constrói um objeto CD2DResource.|
|[CD2DResource:: ~ CD2DResource](#cd2dresource__~cd2dresource)|O destruidor. Chamado quando um objeto de recurso D2D está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DResource::Create](#create)|Cria um CD2DResource.|
|[CD2DResource::Destroy](#destroy)|Destrói um objeto CD2DResource.|
|[CD2DResource::IsValid](#isvalid)|Verificações de validade de recurso|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DResource::IsAutoDestroy](#isautodestroy)|Seleção automática destruir o sinalizador.|
|[CD2DResource::ReCreate](#recreate)|Recria um CD2DResource.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DResource::m_bIsAutoDestroy](#m_bisautodestroy)|Recurso será destoyed pelo proprietário (CRenderTarget)|
|[CD2DResource::m_pParentTarget](#m_pparenttarget)|Ponteiro para o pai CRenderTarget)|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CD2DResource`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

##  <a name="_dtorcd2dresource"></a>  CD2DResource:: ~ CD2DResource

O destruidor. Chamado quando um objeto de recurso D2D está sendo destruído.

```
virtual ~CD2DResource();
```

##  <a name="cd2dresource"></a>  CD2DResource::CD2DResource

Constrói um objeto CD2DResource.

```
CD2DResource(
    CRenderTarget* pParentTarget,
    BOOL bAutoDestroy);
```

### <a name="parameters"></a>Parâmetros

*pParentTarget*<br/>
Um ponteiro para o destino de renderização.

*bAutoDestroy*<br/>
Indica se o objeto será destruído pelo proprietário (pParentTarget).

##  <a name="create"></a>  CD2DResource::Create

Cria um CD2DResource.

```
virtual HRESULT Create(CRenderTarget* pRenderTarget) = 0;
```

### <a name="parameters"></a>Parâmetros

*pRenderTarget*<br/>
Um ponteiro para o destino de renderização.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retornará um código de erro HRESULT.

##  <a name="destroy"></a>  CD2DResource::Destroy

Destrói um objeto CD2DResource.

```
virtual void Destroy() = 0;
```

##  <a name="isautodestroy"></a>  CD2DResource::IsAutoDestroy

Seleção automática destruir o sinalizador.

```
BOOL IsAutoDestroy() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o objeto será destruído por seu proprietário; Caso contrário, FALSE.

##  <a name="isvalid"></a>  CD2DResource::IsValid

Verificações de validade de recurso

```
virtual BOOL IsValid() const = 0;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o recurso for válido. Caso contrário, FALSE.

##  <a name="m_bisautodestroy"></a>  CD2DResource::m_bIsAutoDestroy

Recurso será destoyed pelo proprietário (CRenderTarget)

```
BOOL m_bIsAutoDestroy;
```

##  <a name="m_pparenttarget"></a>  CD2DResource::m_pParentTarget

Ponteiro para o pai CRenderTarget)

```
CRenderTarget* m_pParentTarget;
```

##  <a name="recreate"></a>  CD2DResource::ReCreate

Recria um CD2DResource.

```
virtual HRESULT ReCreate(CRenderTarget* pRenderTarget);
```

### <a name="parameters"></a>Parâmetros

*pRenderTarget*<br/>
Um ponteiro para o destino de renderização.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retornará um código de erro HRESULT.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
