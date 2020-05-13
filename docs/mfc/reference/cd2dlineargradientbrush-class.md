---
title: Classe CD2DLinearGradientBrushBrush
ms.date: 11/04/2016
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
ms.openlocfilehash: d87cdae5c24eae391be8db2fcdd04f91d592e427
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753161"
---
# <a name="cd2dlineargradientbrush-class"></a>Classe CD2DLinearGradientBrushBrush

Um invólucro para ID2D1LinearGradientBrush.

## <a name="syntax"></a>Sintaxe

```
class CD2DLinearGradientBrush : public CD2DGradientBrush;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DLinearGradientBrush::CD2DLinearGradientBrushBrush](#cd2dlineargradientbrush)|Constrói um objeto CD2DLinearGradientBrushBrush.|
|[CD2DLinearGradientBrush::~CD2DLinearGradientBrushBrushBrush](#_dtorcd2dlineargradientbrush)|O destruidor. Chamado quando um objeto de escova de gradiente linear D2D está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DLinearGradientBrush::Attach](#attach)|Anexa a interface de recurso existente ao objeto|
|[CD2DLinearGradientBrush::Create](#create)|Cria um CD2DLinearGradientBrushBrush. (Substitui [cd2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|
|[CD2DLinearGradientBrush::Destroy](#destroy)|Destrói um objeto CD2DLinearGradientBrushBrush. (Substitui [cd2DGradientBrush::Destroy](../../mfc/reference/cd2dgradientbrush-class.md#destroy).)|
|[CD2DLinearGradientBrush::Detach](#detach)|Destaca a interface de recursos do objeto|
|[CD2DLinearGradientbrush::Get](#get)|Retorna interface ID2D1LinearGradientBrushbrush|
|[CD2DLinearGradientbrush::GetEndPoint](#getendpoint)|Recupera as coordenadas finais do gradiente linear|
|[CD2DLinearGradientbrush::GetStartPoint](#getstartpoint)|Recupera as coordenadas iniciais do gradiente linear|
|[CD2DLinearGradientbrush::SetEndPoint](#setendpoint)|Define as coordenadas finais do gradiente linear no espaço de coordenadas do pincel|
|[CD2DLinearGradientbrush::SetStartPoint](#setstartpoint)|Define as coordenadas de partida do gradiente linear no espaço de coordenadas do pincel|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DLinearGradientBrush::operador ID2D1LinearGradientBrushBrush*](#operator_id2d1lineargradientbrush_star)|Retorna interface ID2D1LinearGradientBrushbrush|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DLinearGradientBrush::m_LinearGradientBrushProperties](#m_lineargradientbrushproperties)|Os pontos de partida e fim do gradiente.|
|[CD2DLinearGradientBrush::m_pLinearGradientBrush](#m_plineargradientbrush)|Um ponteiro para um ID2D1LinearGradientBrush.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

[CD2Dbrush](../../mfc/reference/cd2dbrush-class.md)

[CD2DGradientBrush](../../mfc/reference/cd2dgradientbrush-class.md)

`CD2DLinearGradientBrush`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2dlineargradientbrushcd2dlineargradientbrush"></a><a name="_dtorcd2dlineargradientbrush"></a>CD2DLinearGradientBrush::~CD2DLinearGradientBrushBrushBrush

O destruidor. Chamado quando um objeto de escova de gradiente linear D2D está sendo destruído.

```
virtual ~CD2DLinearGradientBrush();
```

## <a name="cd2dlineargradientbrushattach"></a><a name="attach"></a>CD2DLinearGradientBrush::Attach

Anexa a interface de recurso existente ao objeto

```cpp
void Attach(ID2D1LinearGradientBrush* pResource);
```

### <a name="parameters"></a>Parâmetros

*Presource*<br/>
Interface de recurso existente. Não pode ser NULO

## <a name="cd2dlineargradientbrushcd2dlineargradientbrush"></a><a name="cd2dlineargradientbrush"></a>CD2DLinearGradientBrush::CD2DLinearGradientBrushBrush

Constrói um objeto CD2DLinearGradientBrushBrush.

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
Um ponteiro para o alvo de renderização.

*gradienteParadas*<br/>
Um ponteiro para uma matriz de estruturas D2D1_GRADIENT_STOP.

*gradienteStopsCount*<br/>
Um valor maior ou igual a 1 que especifica o número de paradas de gradiente na matriz GradientStops.

*Propriedades de pincel de gradiência linear*<br/>
Os pontos de partida e fim do gradiente.

*colorInterpolationGamma*<br/>
O espaço em que a interpolação de cores entre as paradas de gradiente é realizada.

*extendMode*<br/>
O comportamento do gradiente fora da faixa normalizada [0,1].

*pBrushProperties*<br/>
Um ponteiro para a opacidade e transformação de um pincel.

*bAutoDestroy*<br/>
Indica que o objeto será destruído pelo proprietário (pParentTarget).

## <a name="cd2dlineargradientbrushcreate"></a><a name="create"></a>CD2DLinearGradientBrush::Create

Cria um CD2DLinearGradientBrushBrush.

```
virtual HRESULT Create(CRenderTarget* pRenderTarget);
```

### <a name="parameters"></a>Parâmetros

*pRenderTarget*<br/>
Um ponteiro para o alvo de renderização.

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.

## <a name="cd2dlineargradientbrushdestroy"></a><a name="destroy"></a>CD2DLinearGradientBrush::Destroy

Destrói um objeto CD2DLinearGradientBrushBrush.

```
virtual void Destroy();
```

## <a name="cd2dlineargradientbrushdetach"></a><a name="detach"></a>CD2DLinearGradientBrush::Detach

Destaca a interface de recursos do objeto

```
ID2D1LinearGradientBrush* Detach();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para interface de recurso separada.

## <a name="cd2dlineargradientbrushget"></a><a name="get"></a>CD2DLinearGradientbrush::Get

Retorna interface ID2D1LinearGradientBrushbrush

```
ID2D1LinearGradientBrush* Get();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1LinearGradientBrush ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dlineargradientbrushgetendpoint"></a><a name="getendpoint"></a>CD2DLinearGradientbrush::GetEndPoint

Recupera as coordenadas finais do gradiente linear

```
CD2DPointF GetEndPoint() const;
```

### <a name="return-value"></a>Valor retornado

As coordenadas bidimensionais finais do gradiente linear, no espaço de coordenadas do pincel

## <a name="cd2dlineargradientbrushgetstartpoint"></a><a name="getstartpoint"></a>CD2DLinearGradientbrush::GetStartPoint

Recupera as coordenadas iniciais do gradiente linear

```
CD2DPointF GetStartPoint() const;
```

### <a name="return-value"></a>Valor retornado

As coordenadas bidimensionais iniciais do gradiente linear, no espaço de coordenadas do pincel

## <a name="cd2dlineargradientbrushm_lineargradientbrushproperties"></a><a name="m_lineargradientbrushproperties"></a>CD2DLinearGradientBrush::m_LinearGradientBrushProperties

Os pontos de partida e fim do gradiente.

```
D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES m_LinearGradientBrushProperties;
```

## <a name="cd2dlineargradientbrushm_plineargradientbrush"></a><a name="m_plineargradientbrush"></a>CD2DLinearGradientBrush::m_pLinearGradientBrush

Um ponteiro para um ID2D1LinearGradientBrush.

```
ID2D1LinearGradientBrush* m_pLinearGradientBrush;
```

## <a name="cd2dlineargradientbrushoperator-id2d1lineargradientbrush"></a><a name="operator_id2d1lineargradientbrush_star"></a>CD2DLinearGradientBrush::operador ID2D1LinearGradientBrushBrush*

Retorna interface ID2D1LinearGradientBrushbrush

```
operator ID2D1LinearGradientBrush*();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1LinearGradientBrush ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dlineargradientbrushsetendpoint"></a><a name="setendpoint"></a>CD2DLinearGradientbrush::SetEndPoint

Define as coordenadas finais do gradiente linear no espaço de coordenadas do pincel

```cpp
void SetEndPoint(CD2DPointF point);
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
As coordenadas bidimensionais finais do gradiente linear, no espaço de coordenadas do pincel

## <a name="cd2dlineargradientbrushsetstartpoint"></a><a name="setstartpoint"></a>CD2DLinearGradientbrush::SetStartPoint

Define as coordenadas de partida do gradiente linear no espaço de coordenadas do pincel

```cpp
void SetStartPoint(CD2DPointF point);
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
As coordenadas bidimensionais iniciais do gradiente linear, no espaço de coordenadas do pincel

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
