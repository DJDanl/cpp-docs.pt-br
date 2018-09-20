---
title: Classe CD2DLinearGradientBrush | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CD2DLinearGradientBrush
- AFXRENDERTARGET/CD2DLinearGradientBrush
- AFXRENDERTARGET/CD2DLinearGradientBrush::CD2DLinearGradientBrush
- AFXRENDERTARGET/CD2DLinearGradientBrush::Attach
- AFXRENDERTARGET/CD2DLinearGradientBrush::Create
- AFXRENDERTARGET/CD2DLinearGradientBrush::Destroy
- AFXRENDERTARGET/CD2DLinearGradientBrush::Detach
- AFXRENDERTARGET/CD2DLinearGradientBrush::Get
- AFXRENDERTARGET/CD2DLinearGradientBrush::GetEndPoint
- AFXRENDERTARGET/CD2DLinearGradientBrush::GetStartPoint
- AFXRENDERTARGET/CD2DLinearGradientBrush::SetEndPoint
- AFXRENDERTARGET/CD2DLinearGradientBrush::SetStartPoint
- AFXRENDERTARGET/CD2DLinearGradientBrush::m_LinearGradientBrushProperties
- AFXRENDERTARGET/CD2DLinearGradientBrush::m_pLinearGradientBrush
dev_langs:
- C++
helpviewer_keywords:
- CD2DLinearGradientBrush [MFC], CD2DLinearGradientBrush
- CD2DLinearGradientBrush [MFC], Attach
- CD2DLinearGradientBrush [MFC], Create
- CD2DLinearGradientBrush [MFC], Destroy
- CD2DLinearGradientBrush [MFC], Detach
- CD2DLinearGradientBrush [MFC], Get
- CD2DLinearGradientBrush [MFC], GetEndPoint
- CD2DLinearGradientBrush [MFC], GetStartPoint
- CD2DLinearGradientBrush [MFC], SetEndPoint
- CD2DLinearGradientBrush [MFC], SetStartPoint
- CD2DLinearGradientBrush [MFC], m_LinearGradientBrushProperties
- CD2DLinearGradientBrush [MFC], m_pLinearGradientBrush
ms.assetid: d4be9ff9-0ea8-45e6-9b8d-f3bc5673cbac
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b33b49c818a290d5bcbae20864a4e73006dd1f01
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46403923"
---
# <a name="cd2dlineargradientbrush-class"></a>Classe CD2DLinearGradientBrush

Um wrapper para ID2D1LinearGradientBrush.

## <a name="syntax"></a>Sintaxe

```
class CD2DLinearGradientBrush : public CD2DGradientBrush;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DLinearGradientBrush::CD2DLinearGradientBrush](#cd2dlineargradientbrush)|Constrói um objeto CD2DLinearGradientBrush.|
|[CD2DLinearGradientBrush:: ~ CD2DLinearGradientBrush](#_dtorcd2dlineargradientbrush)|O destruidor. Chamado quando um objeto de pincel de gradiente linear D2D está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DLinearGradientBrush::Attach](#attach)|Anexa existente de interface de recurso para o objeto|
|[CD2DLinearGradientBrush::Create](#create)|Cria um CD2DLinearGradientBrush. (Substitui [CD2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|
|[CD2DLinearGradientBrush::Destroy](#destroy)|Destrói um objeto CD2DLinearGradientBrush. (Substitui [CD2DGradientBrush::Destroy](../../mfc/reference/cd2dgradientbrush-class.md#destroy).)|
|[CD2DLinearGradientBrush::Detach](#detach)|Desanexa a interface do recurso do objeto|
|[CD2DLinearGradientBrush::Get](#get)|Interface de ID2D1LinearGradientBrush retorna|
|[CD2DLinearGradientBrush::GetEndPoint](#getendpoint)|Recupera as coordenadas de encerramento do gradiente linear|
|[CD2DLinearGradientBrush::GetStartPoint](#getstartpoint)|Recupera as coordenadas iniciais do gradiente linear|
|[CD2DLinearGradientBrush::SetEndPoint](#setendpoint)|Define as coordenadas de encerramento do gradiente linear no espaço de coordenadas do pincel|
|[CD2DLinearGradientBrush::SetStartPoint](#setstartpoint)|Define as coordenadas iniciais do gradiente linear no espaço de coordenadas do pincel|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DLinearGradientBrush::Operator ID2D1LinearGradientBrush *](#operator_id2d1lineargradientbrush_star)|Interface de ID2D1LinearGradientBrush retorna|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DLinearGradientBrush::m_LinearGradientBrushProperties](#m_lineargradientbrushproperties)|Os pontos inicial e final do gradiente.|
|[CD2DLinearGradientBrush::m_pLinearGradientBrush](#m_plineargradientbrush)|Um ponteiro para um ID2D1LinearGradientBrush.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

[CD2DBrush](../../mfc/reference/cd2dbrush-class.md)

[CD2DGradientBrush](../../mfc/reference/cd2dgradientbrush-class.md)

`CD2DLinearGradientBrush`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

##  <a name="_dtorcd2dlineargradientbrush"></a>  CD2DLinearGradientBrush:: ~ CD2DLinearGradientBrush

O destruidor. Chamado quando um objeto de pincel de gradiente linear D2D está sendo destruído.

```
virtual ~CD2DLinearGradientBrush();
```

##  <a name="attach"></a>  CD2DLinearGradientBrush::Attach

Anexa existente de interface de recurso para o objeto

```
void Attach(ID2D1LinearGradientBrush* pResource);
```

### <a name="parameters"></a>Parâmetros

*pResource*<br/>
Interface de recursos existente. Não pode ser NULL

##  <a name="cd2dlineargradientbrush"></a>  CD2DLinearGradientBrush::CD2DLinearGradientBrush

Constrói um objeto CD2DLinearGradientBrush.

```
CD2DLinearGradientBrush(
    CRenderTarget* pParentTarget,
    const D2D1_GRADIENT_STOP* gradientStops,
    UINT gradientStopsCount,
    D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES LinearGradientBrushProperties,
    D2D1_GAMMA colorInterpolationGamma = D2D1_GAMMA_2_2,
    D2D1_EXTEND_MODE extendMode = D2D1_EXTEND_MODE_CLAMP,
    CD2DBrushProperties* pBrushProperties = NULL,
    BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pParentTarget*<br/>
Um ponteiro para o destino de renderização.

*gradientStops*<br/>
Um ponteiro para uma matriz de estruturas de D2D1_GRADIENT_STOP.

*gradientStopsCount*<br/>
Um valor maior que ou igual a 1 que especifica o número de paradas de gradiente na matriz gradientStops.

*LinearGradientBrushProperties*<br/>
Os pontos inicial e final do gradiente.

*colorInterpolationGamma*<br/>
O espaço no qual cor interpolação entre as paradas de gradiente é executada.

*extendMode*<br/>
O comportamento do gradiente fora do intervalo [0,1] normalizado.

*pBrushProperties*<br/>
Um ponteiro para a opacidade e a transformação de um pincel.

*bAutoDestroy*<br/>
Indica se o objeto será destruído pelo proprietário (pParentTarget).

##  <a name="create"></a>  CD2DLinearGradientBrush::Create

Cria um CD2DLinearGradientBrush.

```
virtual HRESULT Create(CRenderTarget* pRenderTarget);
```

### <a name="parameters"></a>Parâmetros

*pRenderTarget*<br/>
Um ponteiro para o destino de renderização.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retornará um código de erro HRESULT.

##  <a name="destroy"></a>  CD2DLinearGradientBrush::Destroy

Destrói um objeto CD2DLinearGradientBrush.

```
virtual void Destroy();
```

##  <a name="detach"></a>  CD2DLinearGradientBrush::Detach

Desanexa a interface do recurso do objeto

```
ID2D1LinearGradientBrush* Detach();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para interface de recurso desanexado.

##  <a name="get"></a>  CD2DLinearGradientBrush::Get

Interface de ID2D1LinearGradientBrush retorna

```
ID2D1LinearGradientBrush* Get();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para uma interface ID2D1LinearGradientBrush ou NULL se o objeto ainda não foi inicializado.

##  <a name="getendpoint"></a>  CD2DLinearGradientBrush::GetEndPoint

Recupera as coordenadas de encerramento do gradiente linear

```
CD2DPointF GetEndPoint() const;
```

### <a name="return-value"></a>Valor de retorno

As coordenadas bidimensionais de encerramento do gradiente linear, no espaço de coordenadas do pincel

##  <a name="getstartpoint"></a>  CD2DLinearGradientBrush::GetStartPoint

Recupera as coordenadas iniciais do gradiente linear

```
CD2DPointF GetStartPoint() const;
```

### <a name="return-value"></a>Valor de retorno

As coordenadas bidimensionais de início do gradiente linear, no espaço de coordenadas do pincel

##  <a name="m_lineargradientbrushproperties"></a>  CD2DLinearGradientBrush::m_LinearGradientBrushProperties

Os pontos inicial e final do gradiente.

```
D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES m_LinearGradientBrushProperties;
```

##  <a name="m_plineargradientbrush"></a>  CD2DLinearGradientBrush::m_pLinearGradientBrush

Um ponteiro para um ID2D1LinearGradientBrush.

```
ID2D1LinearGradientBrush* m_pLinearGradientBrush;
```

##  <a name="operator_id2d1lineargradientbrush_star"></a>  CD2DLinearGradientBrush::Operator ID2D1LinearGradientBrush *

Interface de ID2D1LinearGradientBrush retorna

```
operator ID2D1LinearGradientBrush*();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para uma interface ID2D1LinearGradientBrush ou NULL se o objeto ainda não foi inicializado.

##  <a name="setendpoint"></a>  CD2DLinearGradientBrush::SetEndPoint

Define as coordenadas de encerramento do gradiente linear no espaço de coordenadas do pincel

```
void SetEndPoint(CD2DPointF point);
```

### <a name="parameters"></a>Parâmetros

*ponto*<br/>
As coordenadas bidimensionais de encerramento do gradiente linear, no espaço de coordenadas do pincel

##  <a name="setstartpoint"></a>  CD2DLinearGradientBrush::SetStartPoint

Define as coordenadas iniciais do gradiente linear no espaço de coordenadas do pincel

```
void SetStartPoint(CD2DPointF point);
```

### <a name="parameters"></a>Parâmetros

*ponto*<br/>
As coordenadas bidimensionais de início do gradiente linear, no espaço de coordenadas do pincel

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
