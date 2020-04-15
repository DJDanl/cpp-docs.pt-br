---
title: Classe CD2DSolidColorBrush
ms.date: 03/27/2019
f1_keywords:
- CD2DSolidColorBrush
- AFXRENDERTARGET/CD2DSolidColorBrush
- AFXRENDERTARGET/CD2DSolidColorBrush::CD2DSolidColorBrush
- AFXRENDERTARGET/CD2DSolidColorBrush::Attach
- AFXRENDERTARGET/CD2DSolidColorBrush::Create
- AFXRENDERTARGET/CD2DSolidColorBrush::Destroy
- AFXRENDERTARGET/CD2DSolidColorBrush::Detach
- AFXRENDERTARGET/CD2DSolidColorBrush::Get
- AFXRENDERTARGET/CD2DSolidColorBrush::GetColor
- AFXRENDERTARGET/CD2DSolidColorBrush::SetColor
- AFXRENDERTARGET/CD2DSolidColorBrush::m_colorSolid
- AFXRENDERTARGET/CD2DSolidColorBrush::m_pSolidColorBrush
helpviewer_keywords:
- CD2DSolidColorBrush [MFC], CD2DSolidColorBrush
- CD2DSolidColorBrush [MFC], Attach
- CD2DSolidColorBrush [MFC], Create
- CD2DSolidColorBrush [MFC], Destroy
- CD2DSolidColorBrush [MFC], Detach
- CD2DSolidColorBrush [MFC], Get
- CD2DSolidColorBrush [MFC], GetColor
- CD2DSolidColorBrush [MFC], SetColor
- CD2DSolidColorBrush [MFC], m_colorSolid
- CD2DSolidColorBrush [MFC], m_pSolidColorBrush
ms.assetid: d4506637-acce-4f74-8a9b-f0a45571a735
ms.openlocfilehash: 5aa3d7688046b0c1b04983f2d27fe5579dd7c680
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369055"
---
# <a name="cd2dsolidcolorbrush-class"></a>Classe CD2DSolidColorBrush

Um invólucro para ID2D1SolidColorBrush.

## <a name="syntax"></a>Sintaxe

```
class CD2DSolidColorBrush : public CD2DBrush;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DSolidColorbrush::CD2DSolidColorbrush](#cd2dsolidcolorbrush)|Sobrecarregado. Constrói um objeto CD2DSolidColorBrush.|
|[CD2DSolidColorbrush::~CD2DSolidColorbrush](#_dtorcd2dsolidcolorbrush)|O destruidor. Chamado quando um objeto de escova sólida D2D está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DSolidColorbrush::attach](#attach)|Anexa a interface de recurso existente ao objeto|
|[CD2DSolidColorbrush::Criar](#create)|Cria um CD2DSolidColorBrush. (Substitui [cd2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|
|[CD2DSolidColorBrush::Destroy](#destroy)|Destrói um objeto CD2DSolidColorBrush. (Substitui [cd2DBrush::Destroy](../../mfc/reference/cd2dbrush-class.md#destroy).)|
|[CD2DSolidColorBrush::Detach](#detach)|Destaca a interface de recursos do objeto|
|[CD2DSolidColorbrush::Get](#get)|Retorna interface ID2D1SolidColorBrush|
|[CD2DSolidColorbrush::GetColor](#getcolor)|Recupera a cor do pincel de cor sólida|
|[CD2DSolidColorbrush::SetColor](#setcolor)|Especifica a cor deste pincel de cor sólida|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DSolidColorBrush::operador ID2D1SolidColorbrush*](#operator_id2d1solidcolorbrush_star)|Retorna interface ID2D1SolidColorBrush|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DSolidColorbrush::m_colorSolid](#m_colorsolid)|Pincel de cor sólida.|
|[CD2DSolidColorbrush::m_pSolidColorBrush](#m_psolidcolorbrush)|Armazena um ponteiro para um objeto ID2D1SolidColorBrush.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

[CD2Dbrush](../../mfc/reference/cd2dbrush-class.md)

[CD2DSolidColorbrush](../../mfc/reference/cd2dsolidcolorbrush-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2dsolidcolorbrushcd2dsolidcolorbrush"></a><a name="_dtorcd2dsolidcolorbrush"></a>CD2DSolidColorbrush::~CD2DSolidColorbrush

O destruidor. Chamado quando um objeto de escova sólida D2D está sendo destruído.

```
virtual ~CD2DSolidColorBrush();
```

## <a name="cd2dsolidcolorbrushattach"></a><a name="attach"></a>CD2DSolidColorbrush::attach

Anexa a interface de recurso existente ao objeto

```
void Attach(ID2D1SolidColorBrush* pResource);
```

### <a name="parameters"></a>Parâmetros

*Presource*<br/>
Interface de recurso existente. Não pode ser NULO

## <a name="cd2dsolidcolorbrushcd2dsolidcolorbrush"></a><a name="cd2dsolidcolorbrush"></a>CD2DSolidColorbrush::CD2DSolidColorbrush

Constrói um objeto CD2DSolidColorBrush.

```
CD2DSolidColorBrush(
    CRenderTarget* pParentTarget,
    D2D1_COLOR_F color,
    CD2DBrushProperties* pBrushProperties = NULL,
    BOOL bAutoDestroy = TRUE);

CD2DSolidColorBrush(
    CRenderTarget* pParentTarget,
    COLORREF color,
    int nAlpha = 255,
    CD2DBrushProperties* pBrushProperties = NULL,
    BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pParentTarget*<br/>
Um ponteiro para o alvo de renderização.

*cor*<br/>
Os valores vermelho, verde, azul e alfa da cor do pincel.

*pBrushProperties*<br/>
Um ponteiro para a opacidade e transformação de um pincel.

*bAutoDestroy*<br/>
Indica que o objeto será destruído pelo proprietário (pParentTarget).

*nAlfa*<br/>
A opacidade da cor do pincel.

## <a name="cd2dsolidcolorbrushcreate"></a><a name="create"></a>CD2DSolidColorbrush::Criar

Cria um CD2DSolidColorBrush.

```
virtual HRESULT Create(CRenderTarget* pRenderTarget);
```

### <a name="parameters"></a>Parâmetros

*pRenderTarget*<br/>
Um ponteiro para o alvo de renderização.

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.

## <a name="cd2dsolidcolorbrushdestroy"></a><a name="destroy"></a>CD2DSolidColorBrush::Destroy

Destrói um objeto CD2DSolidColorBrush.

```
virtual void Destroy();
```

## <a name="cd2dsolidcolorbrushdetach"></a><a name="detach"></a>CD2DSolidColorBrush::Detach

Destaca a interface de recursos do objeto

```
ID2D1SolidColorBrush* Detach();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para interface de recurso separada.

## <a name="cd2dsolidcolorbrushget"></a><a name="get"></a>CD2DSolidColorbrush::Get

Retorna interface ID2D1SolidColorBrush

```
ID2D1SolidColorBrush* Get();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1SolidColorBrush ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dsolidcolorbrushgetcolor"></a><a name="getcolor"></a>CD2DSolidColorbrush::GetColor

Recupera a cor do pincel de cor sólida

```
D2D1_COLOR_F GetColor() const;
```

### <a name="return-value"></a>Valor retornado

A cor deste pincel de cor sólida

## <a name="cd2dsolidcolorbrushm_colorsolid"></a><a name="m_colorsolid"></a>CD2DSolidColorbrush::m_colorSolid

Pincel de cor sólida.

```
D2D1_COLOR_F m_colorSolid;
```

## <a name="cd2dsolidcolorbrushm_psolidcolorbrush"></a><a name="m_psolidcolorbrush"></a>CD2DSolidColorbrush::m_pSolidColorBrush

Armazena um ponteiro para um objeto ID2D1SolidColorBrush.

```
ID2D1SolidColorBrush* m_pSolidColorBrush;
```

## <a name="cd2dsolidcolorbrushoperator-id2d1solidcolorbrush"></a><a name="operator_id2d1solidcolorbrush_star"></a>CD2DSolidColorBrush::operador ID2D1SolidColorbrush*

Retorna interface ID2D1SolidColorBrush

```
operator ID2D1SolidColorBrush*();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1SolidColorBrush ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dsolidcolorbrushsetcolor"></a><a name="setcolor"></a>CD2DSolidColorbrush::SetColor

Especifica a cor deste pincel de cor sólida

```
void SetColor(D2D1_COLOR_F color);
```

### <a name="parameters"></a>Parâmetros

*cor*<br/>
A cor deste pincel de cor sólida

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
