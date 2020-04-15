---
title: Classe CD2DRadialGradientBrush
ms.date: 11/04/2016
f1_keywords:
- CD2DRadialGradientBrush
- AFXRENDERTARGET/CD2DRadialGradientBrush
- AFXRENDERTARGET/CD2DRadialGradientBrush::CD2DRadialGradientBrush
- AFXRENDERTARGET/CD2DRadialGradientBrush::Attach
- AFXRENDERTARGET/CD2DRadialGradientBrush::Create
- AFXRENDERTARGET/CD2DRadialGradientBrush::Destroy
- AFXRENDERTARGET/CD2DRadialGradientBrush::Detach
- AFXRENDERTARGET/CD2DRadialGradientBrush::Get
- AFXRENDERTARGET/CD2DRadialGradientBrush::GetCenter
- AFXRENDERTARGET/CD2DRadialGradientBrush::GetGradientOriginOffset
- AFXRENDERTARGET/CD2DRadialGradientBrush::GetRadiusX
- AFXRENDERTARGET/CD2DRadialGradientBrush::GetRadiusY
- AFXRENDERTARGET/CD2DRadialGradientBrush::SetCenter
- AFXRENDERTARGET/CD2DRadialGradientBrush::SetGradientOriginOffset
- AFXRENDERTARGET/CD2DRadialGradientBrush::SetRadiusX
- AFXRENDERTARGET/CD2DRadialGradientBrush::SetRadiusY
- AFXRENDERTARGET/CD2DRadialGradientBrush::m_pRadialGradientBrush
- AFXRENDERTARGET/CD2DRadialGradientBrush::m_RadialGradientBrushProperties
helpviewer_keywords:
- CD2DRadialGradientBrush [MFC], CD2DRadialGradientBrush
- CD2DRadialGradientBrush [MFC], Attach
- CD2DRadialGradientBrush [MFC], Create
- CD2DRadialGradientBrush [MFC], Destroy
- CD2DRadialGradientBrush [MFC], Detach
- CD2DRadialGradientBrush [MFC], Get
- CD2DRadialGradientBrush [MFC], GetCenter
- CD2DRadialGradientBrush [MFC], GetGradientOriginOffset
- CD2DRadialGradientBrush [MFC], GetRadiusX
- CD2DRadialGradientBrush [MFC], GetRadiusY
- CD2DRadialGradientBrush [MFC], SetCenter
- CD2DRadialGradientBrush [MFC], SetGradientOriginOffset
- CD2DRadialGradientBrush [MFC], SetRadiusX
- CD2DRadialGradientBrush [MFC], SetRadiusY
- CD2DRadialGradientBrush [MFC], m_pRadialGradientBrush
- CD2DRadialGradientBrush [MFC], m_RadialGradientBrushProperties
ms.assetid: 6c76d84a-d831-4ee2-96f1-82c1f5b0d6a9
ms.openlocfilehash: aca9606271040e5c5c9aee81be0a08b64cf2bab7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369139"
---
# <a name="cd2dradialgradientbrush-class"></a>Classe CD2DRadialGradientBrush

Um invólucro para ID2D1RadialGradientBrush.

## <a name="syntax"></a>Sintaxe

```
class CD2DRadialGradientBrush : public CD2DGradientBrush;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DRadialGradientBrush::CD2DRadialGradientBrush](#cd2dradialgradientbrush)|Constrói um objeto CD2DLinearGradientBrushBrush.|
|[CD2DRadialGradientBrush::~CD2DRadialGradientBrushBrush](#_dtorcd2dradialgradientbrush)|O destruidor. Chamado quando um objeto de escova de gradiente radial D2D está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DRadialGradientBrush::Attach](#attach)|Anexa a interface de recurso existente ao objeto|
|[CD2DRadialGradientBrush::Criar](#create)|Cria um CD2DRadialGradientBrush. (Substitui [cd2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|
|[CD2DRadialGradientBrush::Destroy](#destroy)|Destrói um objeto CD2DRadialGradientBrush. (Substitui [cd2DGradientBrush::Destroy](../../mfc/reference/cd2dgradientbrush-class.md#destroy).)|
|[CD2DRadialGradientBrush::Detach](#detach)|Destaca a interface de recursos do objeto|
|[CD2DRadialGradientBrush::Get](#get)|Retorna interface ID2D1RadialGradientBrush|
|[CD2DRadialGradientBrush::GetCenter](#getcenter)|Recupera o centro da elipse de gradiente|
|[CD2DRadialGradientBrush::GetGradientOriginOffset](#getgradientoriginoffset)|Recupera o deslocamento da origem gradiente em relação ao centro da elipse gradiente|
|[CD2DRadialGradientBrush::GetRadiusX](#getradiusx)|Recupera o raio-x da elipse de gradiente|
|[CD2DRadialGradientBrush::GetRadiusY](#getradiusy)|Recupera o raio-y da elipse de gradiente|
|[CD2DRadialGradientBrush::SetCenter](#setcenter)|Especifica o centro da elipse de gradiente no espaço de coordenadas do pincel|
|[CD2DRadialGradientbrush::SetGradientOriginOffset](#setgradientoriginoffset)|Especifica a compensação da origem gradiente em relação ao centro da elipse gradiente|
|[CD2DRadialGradientBrush::SetRadiusX](#setradiusx)|Especifica o raio x da elipse de gradiente, no espaço de coordenadas do pincel|
|[CD2DRadialGradientBrush::SetRadiusY](#setradiusy)|Especifica o raio-y da elipse de gradiente, no espaço de coordenadas do pincel|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DRadialGradientBrush::operador ID2D1RadialGradientBrush*](#operator_id2d1radialgradientbrush_star)|Retorna interface ID2D1RadialGradientBrush|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DRadialGradientBrush::m_pRadialGradientBrush](#m_pradialgradientbrush)|Um ponteiro para um ID2D1RadialGradientBrush.|
|[CD2DRadialGradientBrush::m_RadialGradientBrushProperties](#m_radialgradientbrushproperties)|O centro, o deslocamento de origem gradiente, e o raio X e o raio-y do gradiente da escova.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

[CD2Dbrush](../../mfc/reference/cd2dbrush-class.md)

[CD2DGradientBrush](../../mfc/reference/cd2dgradientbrush-class.md)

`CD2DRadialGradientBrush`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2dradialgradientbrushcd2dradialgradientbrush"></a><a name="_dtorcd2dradialgradientbrush"></a>CD2DRadialGradientBrush::~CD2DRadialGradientBrushBrush

O destruidor. Chamado quando um objeto de escova de gradiente radial D2D está sendo destruído.

```
virtual ~CD2DRadialGradientBrush();
```

## <a name="cd2dradialgradientbrushattach"></a><a name="attach"></a>CD2DRadialGradientBrush::Attach

Anexa a interface de recurso existente ao objeto

```
void Attach(ID2D1RadialGradientBrush* pResource);
```

### <a name="parameters"></a>Parâmetros

*Presource*<br/>
Interface de recurso existente. Não pode ser NULO

## <a name="cd2dradialgradientbrushcd2dradialgradientbrush"></a><a name="cd2dradialgradientbrush"></a>CD2DRadialGradientBrush::CD2DRadialGradientBrush

Constrói um objeto CD2DLinearGradientBrushBrush.

```
CD2DRadialGradientBrush(
    CRenderTarget* pParentTarget,
    const D2D1_GRADIENT_STOP* gradientStops,
    UINT gradientStopsCount,
    D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES RadialGradientBrushProperties,
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

*RadialGradientBrushProperties*<br/>
O centro, o deslocamento de origem gradiente, e o raio X e o raio-y do gradiente da escova.

*colorInterpolationGamma*<br/>
O espaço em que a interpolação de cores entre as paradas de gradiente é realizada.

*extendMode*<br/>
O comportamento do gradiente fora da faixa normalizada [0,1].

*pBrushProperties*<br/>
Um ponteiro para a opacidade e transformação de um pincel.

*bAutoDestroy*<br/>
Indica que o objeto será destruído pelo proprietário (pParentTarget).

## <a name="cd2dradialgradientbrushcreate"></a><a name="create"></a>CD2DRadialGradientBrush::Criar

Cria um CD2DRadialGradientBrush.

```
virtual HRESULT Create(CRenderTarget* pRenderTarget);
```

### <a name="parameters"></a>Parâmetros

*pRenderTarget*<br/>
Um ponteiro para o alvo de renderização.

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.

## <a name="cd2dradialgradientbrushdestroy"></a><a name="destroy"></a>CD2DRadialGradientBrush::Destroy

Destrói um objeto CD2DRadialGradientBrush.

```
virtual void Destroy();
```

## <a name="cd2dradialgradientbrushdetach"></a><a name="detach"></a>CD2DRadialGradientBrush::Detach

Destaca a interface de recursos do objeto

```
ID2D1RadialGradientBrush* Detach();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para interface de recurso separada.

## <a name="cd2dradialgradientbrushget"></a><a name="get"></a>CD2DRadialGradientBrush::Get

Retorna interface ID2D1RadialGradientBrush

```
ID2D1RadialGradientBrush* Get();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1RadialGradientBrush ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dradialgradientbrushgetcenter"></a><a name="getcenter"></a>CD2DRadialGradientBrush::GetCenter

Recupera o centro da elipse de gradiente

```
CD2DPointF GetCenter() const;
```

### <a name="return-value"></a>Valor retornado

O centro da elipse de gradiente. Este valor é expresso no espaço de coordenadas do pincel

## <a name="cd2dradialgradientbrushgetgradientoriginoffset"></a><a name="getgradientoriginoffset"></a>CD2DRadialGradientBrush::GetGradientOriginOffset

Recupera o deslocamento da origem gradiente em relação ao centro da elipse gradiente

```
CD2DPointF GetGradientOriginOffset() const;
```

### <a name="return-value"></a>Valor retornado

O deslocamento da origem gradiente do centro da elipse gradiente. Este valor é expresso no espaço de coordenadas do pincel

## <a name="cd2dradialgradientbrushgetradiusx"></a><a name="getradiusx"></a>CD2DRadialGradientBrush::GetRadiusX

Recupera o raio-x da elipse de gradiente

```
FLOAT GetRadiusX() const;
```

### <a name="return-value"></a>Valor retornado

O raio X da elipse de gradiente. Este valor é expresso no espaço de coordenadas do pincel

## <a name="cd2dradialgradientbrushgetradiusy"></a><a name="getradiusy"></a>CD2DRadialGradientBrush::GetRadiusY

Recupera o raio-y da elipse de gradiente

```
FLOAT GetRadiusY() const;
```

### <a name="return-value"></a>Valor retornado

O raio y da elipse de gradiente. Este valor é expresso no espaço de coordenadas do pincel

## <a name="cd2dradialgradientbrushm_pradialgradientbrush"></a><a name="m_pradialgradientbrush"></a>CD2DRadialGradientBrush::m_pRadialGradientBrush

Um ponteiro para um ID2D1RadialGradientBrush.

```
ID2D1RadialGradientBrush* m_pRadialGradientBrush;
```

## <a name="cd2dradialgradientbrushm_radialgradientbrushproperties"></a><a name="m_radialgradientbrushproperties"></a>CD2DRadialGradientBrush::m_RadialGradientBrushProperties

O centro, o deslocamento de origem gradiente, e o raio X e o raio-y do gradiente da escova.

```
D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES m_RadialGradientBrushProperties;
```

## <a name="cd2dradialgradientbrushoperator-id2d1radialgradientbrush"></a><a name="operator_id2d1radialgradientbrush_star"></a>CD2DRadialGradientBrush::operador ID2D1RadialGradientBrush*

Retorna interface ID2D1RadialGradientBrush

```
operator ID2D1RadialGradientBrush*();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1RadialGradientBrush ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dradialgradientbrushsetcenter"></a><a name="setcenter"></a>CD2DRadialGradientBrush::SetCenter

Especifica o centro da elipse de gradiente no espaço de coordenadas do pincel

```
void SetCenter(CD2DPointF point);
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
O centro da elipse gradiente, no espaço de coordenadas do pincel

## <a name="cd2dradialgradientbrushsetgradientoriginoffset"></a><a name="setgradientoriginoffset"></a>CD2DRadialGradientbrush::SetGradientOriginOffset

Especifica a compensação da origem gradiente em relação ao centro da elipse gradiente

```
void SetGradientOriginOffset(CD2DPointF gradientOriginOffset);
```

### <a name="parameters"></a>Parâmetros

*gradienteOriginOffset*<br/>
O deslocamento da origem gradiente do centro da elipse gradiente

## <a name="cd2dradialgradientbrushsetradiusx"></a><a name="setradiusx"></a>CD2DRadialGradientBrush::SetRadiusX

Especifica o raio x da elipse de gradiente, no espaço de coordenadas do pincel

```
void SetRadiusX(FLOAT radiusX);
```

### <a name="parameters"></a>Parâmetros

*Radiusx*<br/>
O raio X da elipse de gradiente. Este valor está no espaço de coordenadas do pincel

## <a name="cd2dradialgradientbrushsetradiusy"></a><a name="setradiusy"></a>CD2DRadialGradientBrush::SetRadiusY

Especifica o raio-y da elipse de gradiente, no espaço de coordenadas do pincel

```
void SetRadiusY(FLOAT radiusY);
```

### <a name="parameters"></a>Parâmetros

*Radiusy*<br/>
O raio y da elipse de gradiente. Este valor está no espaço de coordenadas do pincel

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
