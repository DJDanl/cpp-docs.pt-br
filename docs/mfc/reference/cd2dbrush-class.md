---
title: Classe CD2DBrush | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CD2DBrush
- AFXRENDERTARGET/CD2DBrush
- AFXRENDERTARGET/CD2DBrush::CD2DBrush
- AFXRENDERTARGET/CD2DBrush::Attach
- AFXRENDERTARGET/CD2DBrush::Destroy
- AFXRENDERTARGET/CD2DBrush::Detach
- AFXRENDERTARGET/CD2DBrush::Get
- AFXRENDERTARGET/CD2DBrush::GetOpacity
- AFXRENDERTARGET/CD2DBrush::GetTransform
- AFXRENDERTARGET/CD2DBrush::IsValid
- AFXRENDERTARGET/CD2DBrush::SetOpacity
- AFXRENDERTARGET/CD2DBrush::SetTransform
- AFXRENDERTARGET/CD2DBrush::m_pBrush
- AFXRENDERTARGET/CD2DBrush::m_pBrushProperties
dev_langs:
- C++
helpviewer_keywords:
- CD2DBrush [MFC], CD2DBrush
- CD2DBrush [MFC], Attach
- CD2DBrush [MFC], Destroy
- CD2DBrush [MFC], Detach
- CD2DBrush [MFC], Get
- CD2DBrush [MFC], GetOpacity
- CD2DBrush [MFC], GetTransform
- CD2DBrush [MFC], IsValid
- CD2DBrush [MFC], SetOpacity
- CD2DBrush [MFC], SetTransform
- CD2DBrush [MFC], m_pBrush
- CD2DBrush [MFC], m_pBrushProperties
ms.assetid: 0d2c0857-2261-48a8-8ee0-a88cbf08499a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f7141350d318673b5458cd760f7ad9d48a466bda
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46409773"
---
# <a name="cd2dbrush-class"></a>Classe CD2DBrush

Um wrapper para ID2D1Brush.

## <a name="syntax"></a>Sintaxe

```
class CD2DBrush : public CD2DResource;
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBrush::CD2DBrush](#cd2dbrush)|Constrói um objeto CD2DBrush.|
|[CD2DBrush:: ~ CD2DBrush](#_dtorcd2dbrush)|O destruidor. Chamado quando um objeto de pincel D2D está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBrush::Attach](#attach)|Anexa existente de interface de recurso para o objeto|
|[CD2DBrush::Destroy](#destroy)|Destrói um objeto CD2DBrush. (Substitui [CD2DResource::Destroy](../../mfc/reference/cd2dresource-class.md#destroy).)|
|[CD2DBrush::Detach](#detach)|Desanexa a interface do recurso do objeto|
|[CD2DBrush::Get](#get)|Interface de ID2D1Brush retorna|
|[CD2DBrush::GetOpacity](#getopacity)|Obtém o grau de opacidade desse pincel|
|[CD2DBrush::GetTransform](#gettransform)|Obtém a transformação atual do destino de renderização|
|[CD2DBrush::IsValid](#isvalid)|Verifica a validade de recurso (substitui [CD2DResource::IsValid](../../mfc/reference/cd2dresource-class.md#isvalid).)|
|[CD2DBrush::SetOpacity](#setopacity)|Define o grau de opacidade desse pincel|
|[CD2DBrush::SetTransform](#settransform)|Aplica a transformação especificada para o destino de renderização, substituindo a transformação existente. Todas as operações de desenho subsequentes ocorrem no espaço de transformados|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBrush::Operator ID2D1Brush *](#operator_id2d1brush_star)|Interface de ID2D1Brush retorna|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBrush::m_pBrush](#m_pbrush)|Armazena um ponteiro para um objeto ID2D1Brush.|
|[CD2DBrush::m_pBrushProperties](#m_pbrushproperties)|Propriedades do pincel.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

`CD2DBrush`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

##  <a name="_dtorcd2dbrush"></a>  CD2DBrush:: ~ CD2DBrush

O destruidor. Chamado quando um objeto de pincel D2D está sendo destruído.

```
virtual ~CD2DBrush();
```

##  <a name="attach"></a>  CD2DBrush::Attach

Anexa existente de interface de recurso para o objeto.

```
void Attach(ID2D1Brush* pResource);
```

### <a name="parameters"></a>Parâmetros

*pResource*<br/>
Interface de recursos existente. Não pode ser NULL.

##  <a name="cd2dbrush"></a>  CD2DBrush::CD2DBrush

Constrói um objeto CD2DBrush.

```
CD2DBrush(
    CRenderTarget* pParentTarget,
    CD2DBrushProperties* pBrushProperties = NULL,
    BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pParentTarget*<br/>
Um ponteiro para o destino de renderização.

*pBrushProperties*<br/>
Um ponteiro para a opacidade e a transformação de um pincel.

*bAutoDestroy*<br/>
Indica se o objeto será destruído pelo proprietário (pParentTarget).

##  <a name="destroy"></a>  CD2DBrush::Destroy

Destrói um objeto CD2DBrush.

```
virtual void Destroy();
```

##  <a name="detach"></a>  CD2DBrush::Detach

Desanexa a interface do recurso do objeto.

```
ID2D1Brush* Detach();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para interface de recurso desanexado.

##  <a name="get"></a>  CD2DBrush::Get

Interface de ID2D1Brush retorna

```
ID2D1Brush* Get();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para uma interface ID2D1Brush ou NULL se o objeto ainda não foi inicializado.

##  <a name="getopacity"></a>  CD2DBrush::GetOpacity

Obtém o grau de opacidade desse pincel

```
FLOAT GetOpacity() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor entre zero e 1 que indica a opacidade do pincel. Esse valor é um multiplicador de constante que dimensiona linearmente o valor alfa de todos os pixels preenchido pelo pincel. Os valores de opacidade estiverem fixados no intervalo de 0 a 1, antes que eles são multiplicados juntos.

##  <a name="gettransform"></a>  CD2DBrush::GetTransform

Obtém a transformação atual do destino de renderização

```
void GetTransform(D2D1_MATRIX_3X2_F* transform) const;
```

### <a name="parameters"></a>Parâmetros

*transform*<br/>
Quando isso for retornado, contém a transformação atual do destino de renderização. Este parâmetro é passado não inicializado.

##  <a name="isvalid"></a>  CD2DBrush::IsValid

Verificações de validade de recurso

```
virtual BOOL IsValid() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o recurso for válido. Caso contrário, FALSE.

##  <a name="m_pbrush"></a>  CD2DBrush::m_pBrush

Armazena um ponteiro para um objeto ID2D1Brush.

```
ID2D1Brush* m_pBrush;
```

##  <a name="m_pbrushproperties"></a>  CD2DBrush::m_pBrushProperties

Propriedades do pincel.

```
CD2DBrushProperties* m_pBrushProperties;
```

##  <a name="operator_id2d1brush_star"></a>  CD2DBrush::Operator ID2D1Brush *

Interface de ID2D1Brush retorna

```
operator ID2D1Brush*();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para uma interface ID2D1Brush ou NULL se o objeto ainda não foi inicializado.

##  <a name="setopacity"></a>  CD2DBrush::SetOpacity

Define o grau de opacidade desse pincel

```
void SetOpacity(FLOAT opacity);
```

### <a name="parameters"></a>Parâmetros

*Opacidade*<br/>
Um valor entre zero e 1 que indica a opacidade do pincel. Esse valor é um multiplicador de constante que dimensiona linearmente o valor alfa de todos os pixels preenchido pelo pincel. Os valores de opacidade estiverem fixados no intervalo de 0 a 1, antes que eles são multiplicados juntos.

##  <a name="settransform"></a>  CD2DBrush::SetTransform

Aplica a transformação especificada para o destino de renderização, substituindo a transformação existente. Todas as operações de desenho subsequentes ocorrem no espaço de transformados.

```
void SetTransform(const D2D1_MATRIX_3X2_F* transform);
```

### <a name="parameters"></a>Parâmetros

*transform*<br/>
A transformação a ser aplicada para o destino de renderização

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
