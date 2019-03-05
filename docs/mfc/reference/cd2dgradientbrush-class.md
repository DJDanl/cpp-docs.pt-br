---
title: Classe CD2DGradientBrush
ms.date: 11/04/2016
f1_keywords:
- CD2DGradientBrush
- AFXRENDERTARGET/CD2DGradientBrush
- AFXRENDERTARGET/CD2DGradientBrush::CD2DGradientBrush
- AFXRENDERTARGET/CD2DGradientBrush::Destroy
- AFXRENDERTARGET/CD2DGradientBrush::m_arGradientStops
- AFXRENDERTARGET/CD2DGradientBrush::m_colorInterpolationGamma
- AFXRENDERTARGET/CD2DGradientBrush::m_extendMode
- AFXRENDERTARGET/CD2DGradientBrush::m_pGradientStops
helpviewer_keywords:
- CD2DGradientBrush [MFC], CD2DGradientBrush
- CD2DGradientBrush [MFC], Destroy
- CD2DGradientBrush [MFC], m_arGradientStops
- CD2DGradientBrush [MFC], m_colorInterpolationGamma
- CD2DGradientBrush [MFC], m_extendMode
- CD2DGradientBrush [MFC], m_pGradientStops
ms.assetid: 5bf133e6-16b7-4e3a-845d-0ce63fafe5ec
ms.openlocfilehash: f49a3a1a1aaebed47b05bf003926379c6f0b8102
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57290970"
---
# <a name="cd2dgradientbrush-class"></a>Classe CD2DGradientBrush

A classe base de classes CD2DRadialGradientBrush e o CD2DLinearGradientBrush.

## <a name="syntax"></a>Sintaxe

```
class CD2DGradientBrush : public CD2DBrush;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGradientBrush::CD2DGradientBrush](#cd2dgradientbrush)|Constrói um objeto CD2DGradientBrush.|
|[CD2DGradientBrush:: ~ CD2DGradientBrush](#cd2dgradientbrush__~cd2dgradientbrush)|O destruidor. Chamado quando um objeto de pincel de gradiente D2D está sendo destruído.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGradientBrush::Destroy](#destroy)|Destrói um objeto CD2DGradientBrush. (Substitui [CD2DBrush::Destroy](../../mfc/reference/cd2dbrush-class.md#destroy).)|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGradientBrush::m_arGradientStops](#m_argradientstops)|Matriz de estruturas de D2D1_GRADIENT_STOP.|
|[CD2DGradientBrush::m_colorInterpolationGamma](#m_colorinterpolationgamma)|O espaço no qual cor interpolação entre as paradas de gradiente é executada.|
|[CD2DGradientBrush::m_extendMode](#m_extendmode)|O comportamento do gradiente fora do intervalo [0,1] normalizado.|
|[CD2DGradientBrush::m_pGradientStops](#m_pgradientstops)|Um ponteiro para uma matriz de estruturas de D2D1_GRADIENT_STOP.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

[CD2DBrush](../../mfc/reference/cd2dbrush-class.md)

`CD2DGradientBrush`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

##  <a name="_dtorcd2dgradientbrush"></a>  CD2DGradientBrush::~CD2DGradientBrush

O destruidor. Chamado quando um objeto de pincel de gradiente D2D está sendo destruído.

```
virtual ~CD2DGradientBrush();
```

##  <a name="cd2dgradientbrush"></a>  CD2DGradientBrush::CD2DGradientBrush

Constrói um objeto CD2DGradientBrush.

```
CD2DGradientBrush(
    CRenderTarget* pParentTarget,
    const D2D1_GRADIENT_STOP* gradientStops,
    UINT gradientStopsCount,
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

*colorInterpolationGamma*<br/>
O espaço no qual cor interpolação entre as paradas de gradiente é executada.

*extendMode*<br/>
O comportamento do gradiente fora do intervalo [0,1] normalizado.

*pBrushProperties*<br/>
Um ponteiro para a opacidade e a transformação de um pincel.

*bAutoDestroy*<br/>
Indica se o objeto será destruído pelo proprietário (pParentTarget).

##  <a name="destroy"></a>  CD2DGradientBrush::Destroy

Destrói um objeto CD2DGradientBrush.

```
virtual void Destroy();
```

##  <a name="m_argradientstops"></a>  CD2DGradientBrush::m_arGradientStops

Matriz de estruturas de D2D1_GRADIENT_STOP.

```
CArray<D2D1_GRADIENT_STOP, D2D1_GRADIENT_STOP> m_arGradientStops;
```

##  <a name="m_colorinterpolationgamma"></a>  CD2DGradientBrush::m_colorInterpolationGamma

O espaço no qual cor interpolação entre as paradas de gradiente é executada.

```
D2D1_GAMMA m_colorInterpolationGamma;
```

##  <a name="m_extendmode"></a>  CD2DGradientBrush::m_extendMode

O comportamento do gradiente fora do intervalo [0,1] normalizado.

```
D2D1_EXTEND_MODE m_extendMode;
```

##  <a name="m_pgradientstops"></a>  CD2DGradientBrush::m_pGradientStops

Um ponteiro para uma matriz de estruturas de D2D1_GRADIENT_STOP.

```
ID2D1GradientStopCollection* m_pGradientStops;
```

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
