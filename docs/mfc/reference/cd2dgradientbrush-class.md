---
title: Classe CD2DGradientBrush
ms.date: 03/27/2019
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
ms.openlocfilehash: 861bc32382737bd6482a3d51eb8470bf834e8508
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369226"
---
# <a name="cd2dgradientbrush-class"></a>Classe CD2DGradientBrush

A classe base das classes CD2DLinearGradientBrushbrush e cd2DRadialGradientBrush.

## <a name="syntax"></a>Sintaxe

```
class CD2DGradientBrush : public CD2DBrush;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGradientBrush::CD2DGradientBrush](#cd2dgradientbrush)|Constrói um objeto CD2DGradientBrush.|
|[CD2DGradientBrush::~CD2DGradientBrush](#_dtorcd2dgradientbrush)|O destruidor. Chamado quando um objeto de escova de gradiente D2D está sendo destruído.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGradientBrush::Destroy](#destroy)|Destrói um objeto CD2DGradientBrush. (Substitui [cd2DBrush::Destroy](../../mfc/reference/cd2dbrush-class.md#destroy).)|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGradientBrush::m_arGradientStops](#m_argradientstops)|Matriz das estruturas D2D1_GRADIENT_STOP.|
|[CD2DGradientBrush::m_colorInterpolationGamma](#m_colorinterpolationgamma)|O espaço em que a interpolação de cores entre as paradas de gradiente é realizada.|
|[CD2DGradientBrush::m_extendMode](#m_extendmode)|O comportamento do gradiente fora da faixa normalizada [0,1].|
|[CD2DGradientBrush::m_pGradientStops](#m_pgradientstops)|Um ponteiro para uma matriz de estruturas D2D1_GRADIENT_STOP.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

[CD2Dbrush](../../mfc/reference/cd2dbrush-class.md)

`CD2DGradientBrush`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2dgradientbrushcd2dgradientbrush"></a><a name="_dtorcd2dgradientbrush"></a>CD2DGradientBrush::~CD2DGradientBrush

O destruidor. Chamado quando um objeto de escova de gradiente D2D está sendo destruído.

```
virtual ~CD2DGradientBrush();
```

## <a name="cd2dgradientbrushcd2dgradientbrush"></a><a name="cd2dgradientbrush"></a>CD2DGradientBrush::CD2DGradientBrush

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
Um ponteiro para o alvo de renderização.

*gradienteParadas*<br/>
Um ponteiro para uma matriz de estruturas D2D1_GRADIENT_STOP.

*gradienteStopsCount*<br/>
Um valor maior ou igual a 1 que especifica o número de paradas de gradiente na matriz GradientStops.

*colorInterpolationGamma*<br/>
O espaço em que a interpolação de cores entre as paradas de gradiente é realizada.

*extendMode*<br/>
O comportamento do gradiente fora da faixa normalizada [0,1].

*pBrushProperties*<br/>
Um ponteiro para a opacidade e transformação de um pincel.

*bAutoDestroy*<br/>
Indica que o objeto será destruído pelo proprietário (pParentTarget).

## <a name="cd2dgradientbrushdestroy"></a><a name="destroy"></a>CD2DGradientBrush::Destroy

Destrói um objeto CD2DGradientBrush.

```
virtual void Destroy();
```

## <a name="cd2dgradientbrushm_argradientstops"></a><a name="m_argradientstops"></a>CD2DGradientBrush::m_arGradientStops

Matriz das estruturas D2D1_GRADIENT_STOP.

```
CArray<D2D1_GRADIENT_STOP, D2D1_GRADIENT_STOP> m_arGradientStops;
```

## <a name="cd2dgradientbrushm_colorinterpolationgamma"></a><a name="m_colorinterpolationgamma"></a>CD2DGradientBrush::m_colorInterpolationGamma

O espaço em que a interpolação de cores entre as paradas de gradiente é realizada.

```
D2D1_GAMMA m_colorInterpolationGamma;
```

## <a name="cd2dgradientbrushm_extendmode"></a><a name="m_extendmode"></a>CD2DGradientBrush::m_extendMode

O comportamento do gradiente fora da faixa normalizada [0,1].

```
D2D1_EXTEND_MODE m_extendMode;
```

## <a name="cd2dgradientbrushm_pgradientstops"></a><a name="m_pgradientstops"></a>CD2DGradientBrush::m_pGradientStops

Um ponteiro para uma matriz de estruturas D2D1_GRADIENT_STOP.

```
ID2D1GradientStopCollection* m_pGradientStops;
```

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
