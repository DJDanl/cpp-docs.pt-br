---
title: Classe CBitmapRenderTarget
ms.date: 11/04/2016
f1_keywords:
- CBitmapRenderTarget
- AFXRENDERTARGET/CBitmapRenderTarget
- AFXRENDERTARGET/CBitmapRenderTarget::CBitmapRenderTarget
- AFXRENDERTARGET/CBitmapRenderTarget::Attach
- AFXRENDERTARGET/CBitmapRenderTarget::Detach
- AFXRENDERTARGET/CBitmapRenderTarget::GetBitmap
- AFXRENDERTARGET/CBitmapRenderTarget::GetBitmapRenderTarget
- AFXRENDERTARGET/CBitmapRenderTarget::m_pBitmapRenderTarget
helpviewer_keywords:
- CBitmapRenderTarget [MFC], CBitmapRenderTarget
- CBitmapRenderTarget [MFC], Attach
- CBitmapRenderTarget [MFC], Detach
- CBitmapRenderTarget [MFC], GetBitmap
- CBitmapRenderTarget [MFC], GetBitmapRenderTarget
- CBitmapRenderTarget [MFC], m_pBitmapRenderTarget
ms.assetid: c89a4437-812e-4943-acb2-b429a04cc4d2
ms.openlocfilehash: 6249c121f7bcca0675a8138baef0e2cdc9e632d8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81352599"
---
# <a name="cbitmaprendertarget-class"></a>Classe CBitmapRenderTarget

Um invólucro para ID2D1BitmapRenderTarget.

## <a name="syntax"></a>Sintaxe

```
class CBitmapRenderTarget : public CRenderTarget;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CBitmapRenderTarget:CBitmapRenderTarget](#cbitmaprendertarget)|Constrói um objeto CBitmapRenderTarget.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CBitmapRenderTarget::Anexo](#attach)|Anexa a interface de destino de renderização existente ao objeto|
|[CBitmapRenderTarget::Detach](#detach)|Desapegos renderizam interface de destino do objeto|
|[CBitmapRenderTarget::GetBitmap](#getbitmap)|Recupera o bitmap para este destino de renderização. O bitmap retornado pode ser usado para operações de desenho.|
|[CBitmapRenderTarget::GetBitmapRenderTarget](#getbitmaprendertarget)|Retorna ID2D1BitmapRenderizainterfaceTarget|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CBitmapRenderTarget:: operador ID2D1BitmapRenderTarget*](#operator_id2d1bitmaprendertarget_star)|Retorna ID2D1BitmapRenderizainterfaceTarget|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CBitmapRenderTarget::m_pBitmapRenderTarget](#m_pbitmaprendertarget)|Um ponteiro para um objeto ID2D1BitmapRenderTarget.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CRenderTarget](../../mfc/reference/crendertarget-class.md)

`CBitmapRenderTarget`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cbitmaprendertargetattach"></a><a name="attach"></a>CBitmapRenderTarget::Anexo

Anexa a interface de destino de renderização existente ao objeto

```
void Attach(ID2D1BitmapRenderTarget* pTarget);
```

### <a name="parameters"></a>Parâmetros

*Ptarget*<br/>
Interface de destino de renderização existente. Não pode ser NULO

## <a name="cbitmaprendertargetcbitmaprendertarget"></a><a name="cbitmaprendertarget"></a>CBitmapRenderTarget:CBitmapRenderTarget

Constrói um objeto CBitmapRenderTarget.

```
CBitmapRenderTarget();
```

## <a name="cbitmaprendertargetdetach"></a><a name="detach"></a>CBitmapRenderTarget::Detach

Desapegos renderizam interface de destino do objeto

```
ID2D1BitmapRenderTarget* Detach();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para interface de destino de renderização separada.

## <a name="cbitmaprendertargetgetbitmap"></a><a name="getbitmap"></a>CBitmapRenderTarget::GetBitmap

Recupera o bitmap para este destino de renderização. O bitmap retornado pode ser usado para operações de desenho.

```
BOOL GetBitmap(CD2DBitmap& bitmap);
```

### <a name="parameters"></a>Parâmetros

*Bitmap*<br/>
Quando este método retornar, contenha o bitmap válido para este destino de renderização. Este bitmap pode ser usado para operações de desenho.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO.

## <a name="cbitmaprendertargetgetbitmaprendertarget"></a><a name="getbitmaprendertarget"></a>CBitmapRenderTarget::GetBitmapRenderTarget

Retorna ID2D1BitmapRenderizainterfaceTarget

```
ID2D1BitmapRenderTarget* GetBitmapRenderTarget();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1BitmapRenderTarget ou NULL se o objeto ainda não estiver inicializado.

## <a name="cbitmaprendertargetm_pbitmaprendertarget"></a><a name="m_pbitmaprendertarget"></a>CBitmapRenderTarget::m_pBitmapRenderTarget

Um ponteiro para um objeto ID2D1BitmapRenderTarget.

```
ID2D1BitmapRenderTarget* m_pBitmapRenderTarget;
```

## <a name="cbitmaprendertargetoperator-id2d1bitmaprendertarget"></a><a name="operator_id2d1bitmaprendertarget_star"></a>CBitmapRenderTarget:: operador ID2D1BitmapRenderTarget*

Retorna ID2D1BitmapRenderizainterfaceTarget

```
operator ID2D1BitmapRenderTarget*();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1BitmapRenderTarget ou NULL se o objeto ainda não estiver inicializado.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
