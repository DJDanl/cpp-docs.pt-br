---
title: Classe CDCRenderTarget
ms.date: 11/04/2016
f1_keywords:
- CDCRenderTarget
- AFXRENDERTARGET/CDCRenderTarget
- AFXRENDERTARGET/CDCRenderTarget::CDCRenderTarget
- AFXRENDERTARGET/CDCRenderTarget::Attach
- AFXRENDERTARGET/CDCRenderTarget::BindDC
- AFXRENDERTARGET/CDCRenderTarget::Create
- AFXRENDERTARGET/CDCRenderTarget::Detach
- AFXRENDERTARGET/CDCRenderTarget::GetDCRenderTarget
- AFXRENDERTARGET/CDCRenderTarget::m_pDCRenderTarget
helpviewer_keywords:
- CDCRenderTarget [MFC], CDCRenderTarget
- CDCRenderTarget [MFC], Attach
- CDCRenderTarget [MFC], BindDC
- CDCRenderTarget [MFC], Create
- CDCRenderTarget [MFC], Detach
- CDCRenderTarget [MFC], GetDCRenderTarget
- CDCRenderTarget [MFC], m_pDCRenderTarget
ms.assetid: aa8059c9-08e6-49e4-9b8c-00fa54077a61
ms.openlocfilehash: 790ce0f32c2325fa0ea92ca0bda64ddaa4c86c45
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375700"
---
# <a name="cdcrendertarget-class"></a>Classe CDCRenderTarget

Um invólucro para ID2D1DCRenderTarget.

## <a name="syntax"></a>Sintaxe

```
class CDCRenderTarget : public CRenderTarget;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDCRenderTarget::CDCRenderTarget](#cdcrendertarget)|Constrói um objeto CDCRenderTarget.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDCRenderTarget::Anexar](#attach)|Anexa a interface de destino de renderização existente ao objeto|
|[CDCRenderTarget::BindDC](#binddc)|Vincula o destino de renderização ao contexto do dispositivo ao qual ele emite comandos de desenho|
|[CDCRenderTarget::Criar](#create)|Cria um CDCRenderTarget.|
|[CDCRenderTarget::Detach](#detach)|Desapegos renderizam interface de destino do objeto|
|[CDCRenderTarget::getDCRenderTarget](#getdcrendertarget)|Retorna iD2D1DCRenderização interface target|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDCRenderTarget::operador ID2D1DCRenderTarget*](#operator_id2d1dcrendertarget_star)|Retorna iD2D1DCRenderização interface target|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CDCRenderTarget::m_pDCRenderTarget](#m_pdcrendertarget)|Um ponteiro para um objeto ID2D1DCRenderTarget.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CRenderTarget](../../mfc/reference/crendertarget-class.md)

[CDCRenderTarget](../../mfc/reference/cdcrendertarget-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cdcrendertargetattach"></a><a name="attach"></a>CDCRenderTarget::Anexar

Anexa a interface de destino de renderização existente ao objeto

```
void Attach(ID2D1DCRenderTarget* pTarget);
```

### <a name="parameters"></a>Parâmetros

*Ptarget*<br/>
Interface de destino de renderização existente. Não pode ser NULO

## <a name="cdcrendertargetbinddc"></a><a name="binddc"></a>CDCRenderTarget::BindDC

Vincula o destino de renderização ao contexto do dispositivo ao qual ele emite comandos de desenho

```
BOOL BindDC(
    const CDC& dc,
    const CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*Dc*<br/>
O contexto do dispositivo ao qual a renderização emite comandos de desenho

*Rect*<br/>
As dimensões da alça para um contexto de dispositivo (HDC) ao qual o alvo de renderização está vinculado

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO.

## <a name="cdcrendertargetcdcrendertarget"></a><a name="cdcrendertarget"></a>CDCRenderTarget::CDCRenderTarget

Constrói um objeto CDCRenderTarget.

```
CDCRenderTarget();
```

## <a name="cdcrendertargetcreate"></a><a name="create"></a>CDCRenderTarget::Criar

Cria um CDCRenderTarget.

```
BOOL Create(const D2D1_RENDER_TARGET_PROPERTIES& props);
```

### <a name="parameters"></a>Parâmetros

*Adereços*<br/>
O modo de renderização, o formato do pixel, as opções de remo, as informações de DPI e o suporte mínimo do DirectX necessário para renderização de hardware.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO.

## <a name="cdcrendertargetdetach"></a><a name="detach"></a>CDCRenderTarget::Detach

Desapegos renderizam interface de destino do objeto

```
ID2D1DCRenderTarget* Detach();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para interface de destino de renderização separada.

## <a name="cdcrendertargetgetdcrendertarget"></a><a name="getdcrendertarget"></a>CDCRenderTarget::getDCRenderTarget

Retorna iD2D1DCRenderização interface target

```
ID2D1DCRenderTarget* GetDCRenderTarget();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1DCRenderTarget ou NULL se o objeto ainda não estiver inicializado.

## <a name="cdcrendertargetm_pdcrendertarget"></a><a name="m_pdcrendertarget"></a>CDCRenderTarget::m_pDCRenderTarget

Um ponteiro para um objeto ID2D1DCRenderTarget.

```
ID2D1DCRenderTarget* m_pDCRenderTarget;
```

## <a name="cdcrendertargetoperator-id2d1dcrendertarget"></a><a name="operator_id2d1dcrendertarget_star"></a>CDCRenderTarget::operador ID2D1DCRenderTarget*

Retorna iD2D1DCRenderização interface target

```
operator ID2D1DCRenderTarget*();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1DCRenderTarget ou NULL se o objeto ainda não estiver inicializado.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
