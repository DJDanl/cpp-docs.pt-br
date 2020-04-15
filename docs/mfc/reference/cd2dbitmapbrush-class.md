---
title: Classe CD2DBitmapBrush
ms.date: 11/04/2016
f1_keywords:
- CD2DBitmapBrush
- AFXRENDERTARGET/CD2DBitmapBrush
- AFXRENDERTARGET/CD2DBitmapBrush::CD2DBitmapBrush
- AFXRENDERTARGET/CD2DBitmapBrush::Attach
- AFXRENDERTARGET/CD2DBitmapBrush::Create
- AFXRENDERTARGET/CD2DBitmapBrush::Destroy
- AFXRENDERTARGET/CD2DBitmapBrush::Detach
- AFXRENDERTARGET/CD2DBitmapBrush::Get
- AFXRENDERTARGET/CD2DBitmapBrush::GetBitmap
- AFXRENDERTARGET/CD2DBitmapBrush::GetExtendModeX
- AFXRENDERTARGET/CD2DBitmapBrush::GetExtendModeY
- AFXRENDERTARGET/CD2DBitmapBrush::GetInterpolationMode
- AFXRENDERTARGET/CD2DBitmapBrush::SetBitmap
- AFXRENDERTARGET/CD2DBitmapBrush::SetExtendModeX
- AFXRENDERTARGET/CD2DBitmapBrush::SetExtendModeY
- AFXRENDERTARGET/CD2DBitmapBrush::SetInterpolationMode
- AFXRENDERTARGET/CD2DBitmapBrush::CommonInit
- AFXRENDERTARGET/CD2DBitmapBrush::m_pBitmap
- AFXRENDERTARGET/CD2DBitmapBrush::m_pBitmapBrush
- AFXRENDERTARGET/CD2DBitmapBrush::m_pBitmapBrushProperties
helpviewer_keywords:
- CD2DBitmapBrush [MFC], CD2DBitmapBrush
- CD2DBitmapBrush [MFC], Attach
- CD2DBitmapBrush [MFC], Create
- CD2DBitmapBrush [MFC], Destroy
- CD2DBitmapBrush [MFC], Detach
- CD2DBitmapBrush [MFC], Get
- CD2DBitmapBrush [MFC], GetBitmap
- CD2DBitmapBrush [MFC], GetExtendModeX
- CD2DBitmapBrush [MFC], GetExtendModeY
- CD2DBitmapBrush [MFC], GetInterpolationMode
- CD2DBitmapBrush [MFC], SetBitmap
- CD2DBitmapBrush [MFC], SetExtendModeX
- CD2DBitmapBrush [MFC], SetExtendModeY
- CD2DBitmapBrush [MFC], SetInterpolationMode
- CD2DBitmapBrush [MFC], CommonInit
- CD2DBitmapBrush [MFC], m_pBitmap
- CD2DBitmapBrush [MFC], m_pBitmapBrush
- CD2DBitmapBrush [MFC], m_pBitmapBrushProperties
ms.assetid: 46ebbe34-66e0-44c8-af1d-d129e851de5e
ms.openlocfilehash: e26202392bf4783598aec0dddfea514fce806a8c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369305"
---
# <a name="cd2dbitmapbrush-class"></a>Classe CD2DBitmapBrush

Um invólucro para ID2D1BitmapBrush.

## <a name="syntax"></a>Sintaxe

```
class CD2DBitmapBrush : public CD2DBrush;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBitmapEscova::CD2DBitmapBrush](#cd2dbitmapbrush)|Sobrecarregado. Constrói um objeto CD2DBitmapBrush a partir de um arquivo.|
|[CD2DBitmapEscova::~CD2DBitmapBrush](#dtor)|O destruidor. Chamado quando um objeto de pincel de bitmap D2D está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBitmapEscova::Anexar](#attach)|Anexa a interface de recurso existente ao objeto|
|[CD2DBitmapBrush::Criar](#create)|Cria um CD2DBitmapBrush. (Substitui [cd2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|
|[CD2DBitmapBrush::Destroy](#destroy)|Destrói um objeto CD2DBitmapBrush. (Substitui [cd2DBrush::Destroy](../../mfc/reference/cd2dbrush-class.md#destroy).)|
|[CD2DBitmapBrush::Detach](#detach)|Destaca a interface de recursos do objeto|
|[CD2DBitmapBrush::Obter](#get)|Retorna interface ID2D1BitmapBrush|
|[CD2DBitmapBrush::GetBitmap](#getbitmap)|Obtém a fonte bitmap que este pincel usa para pintar|
|[CD2DBitmapBrush::GetExtendModeX](#getextendmodex)|Obtém o método pelo qual o pincel horizontalmente ladrilhos as áreas que se estendem além de seu bitmap|
|[CD2DBitmapBrush::GetExtendModeY](#getextendmodey)|Obtém o método pelo qual o pincel verticalmente ladrilhos as áreas que se estendem além de seu bitmap|
|[CD2DBitmapBrush::GetInterpolationMode](#getinterpolationmode)|Obtém o método de interpolação usado quando o bitmap de pincel é dimensionado ou girado|
|[CD2DBitmapEscova::SetBitmap](#setbitmap)|Especifica a fonte bitmap que este pincel usa para pintar|
|[CD2DBitmapEscova::SetExtendModeX](#setextendmodex)|Especifica como o pincel horizontalmente ladrilhos as áreas que se estendem além de seu bitmap|
|[CD2DBitmapEscova::SetExtendModeY](#setextendmodey)|Especifica como o pincel ladria verticalmente as áreas que se estendem além de seu bitmap|
|[CD2DBitmapBrush::SetInterpolationMode](#setinterpolationmode)|Especifica o modo de interpolação usado quando o bitmap de pincel é dimensionado ou girado|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBitmapBrush::CommonInit](#commoninit)|Inicializa o objeto|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBitmapEscova:operador ID2D1BitmapBrush*](#operator_id2d1bitmapbrush_star)|Retorna interface ID2D1BitmapBrush|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBitmapBrush::m_pBitmap](#m_pbitmap)|Armazena um ponteiro em um objeto CD2DBitmap.|
|[CD2DBitmapEscova::m_pBitmapBrush](#m_pbitmapbrush)|Armazena um ponteiro para um objeto ID2D1BitmapBrush.|
|[CD2DBitmapBrush::m_pBitmapBrushProperties](#m_pbitmapbrushproperties)|Propriedades do pincel bitmap.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

[CD2Dbrush](../../mfc/reference/cd2dbrush-class.md)

`CD2DBitmapBrush`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2dbitmapbrushcd2dbitmapbrush"></a><a name="dtor"></a>CD2DBitmapEscova::~CD2DBitmapBrush

O destruidor. Chamado quando um objeto de pincel de bitmap D2D está sendo destruído.

```
virtual ~CD2DBitmapBrush();
```

## <a name="cd2dbitmapbrushattach"></a><a name="attach"></a>CD2DBitmapEscova::Anexar

Anexa a interface de recurso existente ao objeto

```
void Attach(ID2D1BitmapBrush* pResource);
```

### <a name="parameters"></a>Parâmetros

*Presource*<br/>
Interface de recurso existente. Não pode ser NULO

## <a name="cd2dbitmapbrushcd2dbitmapbrush"></a><a name="cd2dbitmapbrush"></a>CD2DBitmapEscova::CD2DBitmapBrush

Constrói um objeto CD2DBitmapBrush.

```
CD2DBitmapBrush(
    CRenderTarget* pParentTarget,
    D2D1_BITMAP_BRUSH_PROPERTIES* pBitmapBrushProperties = NULL,
    CD2DBrushProperties* pBrushProperties = NULL,
    BOOL bAutoDestroy = TRUE);

CD2DBitmapBrush(
    CRenderTarget* pParentTarget,
    UINT uiResID,
    LPCTSTR lpszType = NULL,
    CD2DSizeU sizeDest = CD2DSizeU(0, 0),
    D2D1_BITMAP_BRUSH_PROPERTIES* pBitmapBrushProperties = NULL,
    CD2DBrushProperties* pBrushProperties = NULL,
    BOOL bAutoDestroy = TRUE);

CD2DBitmapBrush(
    CRenderTarget* pParentTarget,
    LPCTSTR lpszImagePath,
    CD2DSizeU sizeDest = CD2DSizeU(0, 0),
    D2D1_BITMAP_BRUSH_PROPERTIES* pBitmapBrushProperties = NULL,
    CD2DBrushProperties* pBrushProperties = NULL,
    BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pParentTarget*<br/>
Um ponteiro para o alvo de renderização.

*pBitmapBrushPropriedades*<br/>
Um ponteiro para os modos de extensão e o modo de interpolação de um pincel de bitmap.

*pBrushProperties*<br/>
Um ponteiro para a opacidade e transformação de um pincel.

*bAutoDestroy*<br/>
Indica que o objeto será destruído pelo proprietário (pParentTarget).

*uiResID*<br/>
O número de id de recurso do recurso.

*lpszType*<br/>
Ponteiro para uma seqüência de terminadas nula que contém o tipo de recurso.

*tamanhoDest*<br/>
Tamanho do destino do bitmap.

*lpszImagePath*<br/>
Ponteiro para uma seqüência de terminadas nula que contém o nome do arquivo.

## <a name="cd2dbitmapbrushcommoninit"></a><a name="commoninit"></a>CD2DBitmapBrush::CommonInit

Inicializa o objeto

```
void CommonInit(D2D1_BITMAP_BRUSH_PROPERTIES* pBitmapBrushProperties);
```

### <a name="parameters"></a>Parâmetros

*pBitmapBrushPropriedades*<br/>
Um ponteiro para as propriedades do pincel bitmap.

## <a name="cd2dbitmapbrushcreate"></a><a name="create"></a>CD2DBitmapBrush::Criar

Cria um CD2DBitmapBrush.

```
virtual HRESULT Create(CRenderTarget* pRenderTarget);
```

### <a name="parameters"></a>Parâmetros

*pRenderTarget*<br/>
Um ponteiro para o alvo de renderização.

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.

## <a name="cd2dbitmapbrushdestroy"></a><a name="destroy"></a>CD2DBitmapBrush::Destroy

Destrói um objeto CD2DBitmapBrush.

```
virtual void Destroy();
```

## <a name="cd2dbitmapbrushdetach"></a><a name="detach"></a>CD2DBitmapBrush::Detach

Destaca a interface de recursos do objeto

```
ID2D1BitmapBrush* Detach();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para interface de recurso separada.

## <a name="cd2dbitmapbrushget"></a><a name="get"></a>CD2DBitmapBrush::Obter

Retorna interface ID2D1BitmapBrush

```
ID2D1BitmapBrush* Get();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1BitmapBrush ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dbitmapbrushgetbitmap"></a><a name="getbitmap"></a>CD2DBitmapBrush::GetBitmap

Obtém a fonte bitmap que este pincel usa para pintar

```
CD2DBitmap* GetBitmap();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para um objeto CD2DBitmap ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dbitmapbrushgetextendmodex"></a><a name="getextendmodex"></a>CD2DBitmapBrush::GetExtendModeX

Obtém o método pelo qual o pincel horizontalmente ladrilhos as áreas que se estendem além de seu bitmap

```
D2D1_EXTEND_MODE GetExtendModeX() const;
```

### <a name="return-value"></a>Valor retornado

Um valor que especifica como o pincel horizontalmente ladrilhos as áreas que se estendem além de seu bitmap

## <a name="cd2dbitmapbrushgetextendmodey"></a><a name="getextendmodey"></a>CD2DBitmapBrush::GetExtendModeY

Obtém o método pelo qual o pincel verticalmente ladrilhos as áreas que se estendem além de seu bitmap

```
D2D1_EXTEND_MODE GetExtendModeY() const;
```

### <a name="return-value"></a>Valor retornado

Um valor que especifica como o pincel ladria verticalmente as áreas que se estendem além de seu bitmap

## <a name="cd2dbitmapbrushgetinterpolationmode"></a><a name="getinterpolationmode"></a>CD2DBitmapBrush::GetInterpolationMode

Obtém o método de interpolação usado quando o bitmap de pincel é dimensionado ou girado

```
D2D1_BITMAP_INTERPOLATION_MODE GetInterpolationMode() const;
```

### <a name="return-value"></a>Valor retornado

O método de interpolação usado quando o bitmap de pincel é dimensionado ou girado

## <a name="cd2dbitmapbrushm_pbitmap"></a><a name="m_pbitmap"></a>CD2DBitmapBrush::m_pBitmap

Armazena um ponteiro em um objeto CD2DBitmap.

```
CD2DBitmap* m_pBitmap;
```

## <a name="cd2dbitmapbrushm_pbitmapbrush"></a><a name="m_pbitmapbrush"></a>CD2DBitmapEscova::m_pBitmapBrush

Armazena um ponteiro para um objeto ID2D1BitmapBrush.

```
ID2D1BitmapBrush* m_pBitmapBrush;
```

## <a name="cd2dbitmapbrushm_pbitmapbrushproperties"></a><a name="m_pbitmapbrushproperties"></a>CD2DBitmapBrush::m_pBitmapBrushProperties

Propriedades do pincel bitmap.

```
D2D1_BITMAP_BRUSH_PROPERTIES* m_pBitmapBrushProperties;
```

## <a name="cd2dbitmapbrushoperator-id2d1bitmapbrush"></a><a name="operator_id2d1bitmapbrush_star"></a>CD2DBitmapEscova:operador ID2D1BitmapBrush*

Retorna interface ID2D1BitmapBrush

```
operator ID2D1BitmapBrush*();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1BitmapBrush ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dbitmapbrushsetbitmap"></a><a name="setbitmap"></a>CD2DBitmapEscova::SetBitmap

Especifica a fonte bitmap que este pincel usa para pintar

```
void SetBitmap(CD2DBitmap* pBitmap);
```

### <a name="parameters"></a>Parâmetros

*Pbitmap*<br/>
A fonte bitmap usada pelo pincel

## <a name="cd2dbitmapbrushsetextendmodex"></a><a name="setextendmodex"></a>CD2DBitmapEscova::SetExtendModeX

Especifica como o pincel horizontalmente ladrilhos as áreas que se estendem além de seu bitmap

```
void SetExtendModeX(D2D1_EXTEND_MODE extendModeX);
```

### <a name="parameters"></a>Parâmetros

*estenderModeX*<br/>
Um valor que especifica como o pincel horizontalmente ladrilhos as áreas que se estendem além de seu bitmap

## <a name="cd2dbitmapbrushsetextendmodey"></a><a name="setextendmodey"></a>CD2DBitmapEscova::SetExtendModeY

Especifica como o pincel ladria verticalmente as áreas que se estendem além de seu bitmap

```
void SetExtendModeY(D2D1_EXTEND_MODE extendModeY);
```

### <a name="parameters"></a>Parâmetros

*extendModeY*<br/>
Um valor que especifica como o pincel ladria verticalmente as áreas que se estendem além de seu bitmap

## <a name="cd2dbitmapbrushsetinterpolationmode"></a><a name="setinterpolationmode"></a>CD2DBitmapBrush::SetInterpolationMode

Especifica o modo de interpolação usado quando o bitmap de pincel é dimensionado ou girado

```
void SetInterpolationMode(D2D1_BITMAP_INTERPOLATION_MODE interpolationMode);
```

### <a name="parameters"></a>Parâmetros

*Interpolationmode*<br/>
O modo de interpolação usado quando o bitmap de pincel é dimensionado ou girado

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
