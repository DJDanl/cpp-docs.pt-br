---
title: Classe CDCRenderTarget | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CDCRenderTarget [MFC], CDCRenderTarget
- CDCRenderTarget [MFC], Attach
- CDCRenderTarget [MFC], BindDC
- CDCRenderTarget [MFC], Create
- CDCRenderTarget [MFC], Detach
- CDCRenderTarget [MFC], GetDCRenderTarget
- CDCRenderTarget [MFC], m_pDCRenderTarget
ms.assetid: aa8059c9-08e6-49e4-9b8c-00fa54077a61
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fc5903f50136aaffcb0358e1a60c99a71e67540e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46447122"
---
# <a name="cdcrendertarget-class"></a>Classe CDCRenderTarget

Um wrapper para ID2D1DCRenderTarget.

## <a name="syntax"></a>Sintaxe

```
class CDCRenderTarget : public CRenderTarget;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDCRenderTarget::CDCRenderTarget](#cdcrendertarget)|Constrói um objeto CDCRenderTarget.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDCRenderTarget::Attach](#attach)|Anexa existente renderizar a interface para o objeto de destino|
|[CDCRenderTarget::BindDC](#binddc)|Associa o destino de renderização para o contexto de dispositivo ao qual ele emite comandos de desenho|
|[CDCRenderTarget::Create](#create)|Cria um CDCRenderTarget.|
|[CDCRenderTarget::Detach](#detach)|Desanexa a interface de destino de renderização do objeto|
|[CDCRenderTarget::GetDCRenderTarget](#getdcrendertarget)|Interface de ID2D1DCRenderTarget retorna|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDCRenderTarget::operator ID2D1DCRenderTarget *](#operator_id2d1dcrendertarget_star)|Interface de ID2D1DCRenderTarget retorna|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CDCRenderTarget::m_pDCRenderTarget](#m_pdcrendertarget)|Um ponteiro para um objeto ID2D1DCRenderTarget.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CRenderTarget](../../mfc/reference/crendertarget-class.md)

[CDCRenderTarget](../../mfc/reference/cdcrendertarget-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

##  <a name="attach"></a>  CDCRenderTarget::Attach

Anexa existente renderizar a interface para o objeto de destino

```
void Attach(ID2D1DCRenderTarget* pTarget);
```

### <a name="parameters"></a>Parâmetros

*pTarget*<br/>
Adaptador de destino de renderização existente. Não pode ser NULL

##  <a name="binddc"></a>  CDCRenderTarget::BindDC

Associa o destino de renderização para o contexto de dispositivo ao qual ele emite comandos de desenho

```
BOOL BindDC(
    const CDC& dc,
    const CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*dc*<br/>
O contexto de dispositivo para o qual o destino de renderização emite comandos de desenho

*Rect*<br/>
As dimensões do identificador para um contexto de dispositivo (HDC) à qual o destino de renderização está associado

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, ele retornará TRUE. Caso contrário, retornará FALSE.

##  <a name="cdcrendertarget"></a>  CDCRenderTarget::CDCRenderTarget

Constrói um objeto CDCRenderTarget.

```
CDCRenderTarget();
```

##  <a name="create"></a>  CDCRenderTarget::Create

Cria um CDCRenderTarget.

```
BOOL Create(const D2D1_RENDER_TARGET_PROPERTIES& props);
```

### <a name="parameters"></a>Parâmetros

*arquivos de propriedades*<br/>
O modo de renderização, formato de pixel, opções de comunicação remota, informações de DPI e o suporte do DirectX mínimo necessário para a renderização de hardware.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, ele retornará TRUE. Caso contrário, retornará FALSE.

##  <a name="detach"></a>  CDCRenderTarget::Detach

Desanexa a interface de destino de renderização do objeto

```
ID2D1DCRenderTarget* Detach();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para desanexado renderizar a interface de destino.

##  <a name="getdcrendertarget"></a>  CDCRenderTarget::GetDCRenderTarget

Interface de ID2D1DCRenderTarget retorna

```
ID2D1DCRenderTarget* GetDCRenderTarget();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para uma interface ID2D1DCRenderTarget ou NULL se o objeto ainda não foi inicializado.

##  <a name="m_pdcrendertarget"></a>  CDCRenderTarget::m_pDCRenderTarget

Um ponteiro para um objeto ID2D1DCRenderTarget.

```
ID2D1DCRenderTarget* m_pDCRenderTarget;
```

##  <a name="operator_id2d1dcrendertarget_star"></a>  CDCRenderTarget::operator ID2D1DCRenderTarget *

Interface de ID2D1DCRenderTarget retorna

```
operator ID2D1DCRenderTarget*();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para uma interface ID2D1DCRenderTarget ou NULL se o objeto ainda não foi inicializado.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
