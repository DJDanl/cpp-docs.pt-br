---
title: Classe CD2DBrush
ms.date: 11/04/2016
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
ms.openlocfilehash: 536d84fe2c2f68d62490e1ce2b65085426762e87
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754200"
---
# <a name="cd2dbrush-class"></a>Classe CD2DBrush

Um invólucro para ID2D1Brush.

## <a name="syntax"></a>Sintaxe

```
class CD2DBrush : public CD2DResource;
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2Dbrush::CD2Dbrush](#cd2dbrush)|Constrói um objeto CD2DBrush.|
|[CD2Dbrush::~CD2Dbrush](#_dtorcd2dbrush)|O destruidor. Chamado quando um objeto de escova D2D está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2Dbrush::Anexar](#attach)|Anexa a interface de recurso existente ao objeto|
|[CD2DBrush::Destroy](#destroy)|Destrói um objeto CD2DBrush. (Substitui [cd2DResource::Destroy](../../mfc/reference/cd2dresource-class.md#destroy).)|
|[CD2DBrush::Detach](#detach)|Destaca a interface de recursos do objeto|
|[CD2Dbrush::Get](#get)|Retorna interface ID2D1Brush|
|[CD2DBrush::GetOpacity](#getopacity)|Obtém o grau de opacidade deste pincel|
|[CD2Dbrush::getTransform](#gettransform)|Obtém a transformação atual do alvo render|
|[CD2Dbrush::isValid](#isvalid)|Verifica a validade do recurso (Substitui [cd2DResource::IsValid](../../mfc/reference/cd2dresource-class.md#isvalid).)|
|[CD2DBrush::SetOpacity](#setopacity)|Define o grau de opacidade deste pincel|
|[CD2Dbrush::SetTransform](#settransform)|Aplica a transformação especificada ao destino de renderização, substituindo a transformação existente. Todas as operações de desenho subsequentes ocorrem no espaço transformado|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBrush::operador ID2D1Brush*](#operator_id2d1brush_star)|Retorna interface ID2D1Brush|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2Dbrush::m_pBrush](#m_pbrush)|Armazena um ponteiro para um objeto ID2D1Brush.|
|[CD2DBrush::m_pBrushProperties](#m_pbrushproperties)|Propriedades do pincel.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

`CD2DBrush`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2dbrushcd2dbrush"></a><a name="_dtorcd2dbrush"></a>CD2Dbrush::~CD2Dbrush

O destruidor. Chamado quando um objeto de escova D2D está sendo destruído.

```
virtual ~CD2DBrush();
```

## <a name="cd2dbrushattach"></a><a name="attach"></a>CD2Dbrush::Anexar

Anexa a interface de recurso existente ao objeto.

```cpp
void Attach(ID2D1Brush* pResource);
```

### <a name="parameters"></a>Parâmetros

*Presource*<br/>
Interface de recurso existente. Não pode ser NULL.

## <a name="cd2dbrushcd2dbrush"></a><a name="cd2dbrush"></a>CD2Dbrush::CD2Dbrush

Constrói um objeto CD2DBrush.

```
CD2DBrush(
    CRenderTarget* pParentTarget,
    CD2DBrushProperties* pBrushProperties = NULL,
    BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pParentTarget*<br/>
Um ponteiro para o alvo de renderização.

*pBrushProperties*<br/>
Um ponteiro para a opacidade e transformação de um pincel.

*bAutoDestroy*<br/>
Indica que o objeto será destruído pelo proprietário (pParentTarget).

## <a name="cd2dbrushdestroy"></a><a name="destroy"></a>CD2DBrush::Destroy

Destrói um objeto CD2DBrush.

```
virtual void Destroy();
```

## <a name="cd2dbrushdetach"></a><a name="detach"></a>CD2DBrush::Detach

Destaca a interface de recursos do objeto.

```
ID2D1Brush* Detach();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para interface de recurso separada.

## <a name="cd2dbrushget"></a><a name="get"></a>CD2Dbrush::Get

Retorna interface ID2D1Brush

```
ID2D1Brush* Get();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1Brush ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dbrushgetopacity"></a><a name="getopacity"></a>CD2DBrush::GetOpacity

Obtém o grau de opacidade deste pincel

```
FLOAT GetOpacity() const;
```

### <a name="return-value"></a>Valor retornado

Um valor entre zero e 1 que indica a opacidade do pincel. Este valor é um multiplicador constante que escala linearmente o valor alfa de todos os pixels preenchidos pelo pincel. Os valores de opacidade são fixados na faixa de 0 a 1 antes de serem multiplicados juntos.

## <a name="cd2dbrushgettransform"></a><a name="gettransform"></a>CD2Dbrush::getTransform

Obtém a transformação atual do alvo render

```cpp
void GetTransform(D2D1_MATRIX_3X2_F* transform) const;
```

### <a name="parameters"></a>Parâmetros

*Transformar*<br/>
Quando isso retornar, contém a transformação atual do alvo de renderização. Este parâmetro é passado não inicializado.

## <a name="cd2dbrushisvalid"></a><a name="isvalid"></a>CD2Dbrush::isValid

Verifica a validade dos recursos

```
virtual BOOL IsValid() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o recurso for válido; caso contrário, FALSO.

## <a name="cd2dbrushm_pbrush"></a><a name="m_pbrush"></a>CD2Dbrush::m_pBrush

Armazena um ponteiro para um objeto ID2D1Brush.

```
ID2D1Brush* m_pBrush;
```

## <a name="cd2dbrushm_pbrushproperties"></a><a name="m_pbrushproperties"></a>CD2DBrush::m_pBrushProperties

Propriedades do pincel.

```
CD2DBrushProperties* m_pBrushProperties;
```

## <a name="cd2dbrushoperator-id2d1brush"></a><a name="operator_id2d1brush_star"></a>CD2DBrush::operador ID2D1Brush*

Retorna interface ID2D1Brush

```
operator ID2D1Brush*();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1Brush ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dbrushsetopacity"></a><a name="setopacity"></a>CD2DBrush::SetOpacity

Define o grau de opacidade deste pincel

```cpp
void SetOpacity(FLOAT opacity);
```

### <a name="parameters"></a>Parâmetros

*Opacidade*<br/>
Um valor entre zero e 1 que indica a opacidade do pincel. Este valor é um multiplicador constante que escala linearmente o valor alfa de todos os pixels preenchidos pelo pincel. Os valores de opacidade são fixados na faixa de 0 a 1 antes de serem multiplicados juntos.

## <a name="cd2dbrushsettransform"></a><a name="settransform"></a>CD2Dbrush::SetTransform

Aplica a transformação especificada ao destino de renderização, substituindo a transformação existente. Todas as operações de desenho subsequentes ocorrem no espaço transformado.

```cpp
void SetTransform(const D2D1_MATRIX_3X2_F* transform);
```

### <a name="parameters"></a>Parâmetros

*Transformar*<br/>
A transformação para aplicar ao alvo de renderização

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
