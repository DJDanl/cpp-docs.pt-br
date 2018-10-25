---
title: Classe CAnimationPoint | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CAnimationPoint
- AFXANIMATIONCONTROLLER/CAnimationPoint
- AFXANIMATIONCONTROLLER/CAnimationPoint::CAnimationPoint
- AFXANIMATIONCONTROLLER/CAnimationPoint::AddTransition
- AFXANIMATIONCONTROLLER/CAnimationPoint::GetDefaultValue
- AFXANIMATIONCONTROLLER/CAnimationPoint::GetValue
- AFXANIMATIONCONTROLLER/CAnimationPoint::GetX
- AFXANIMATIONCONTROLLER/CAnimationPoint::GetY
- AFXANIMATIONCONTROLLER/CAnimationPoint::SetDefaultValue
- AFXANIMATIONCONTROLLER/CAnimationPoint::GetAnimationVariableList
- AFXANIMATIONCONTROLLER/CAnimationPoint::m_xValue
- AFXANIMATIONCONTROLLER/CAnimationPoint::m_yValue
dev_langs:
- C++
helpviewer_keywords:
- CAnimationPoint [MFC], CAnimationPoint
- CAnimationPoint [MFC], AddTransition
- CAnimationPoint [MFC], GetDefaultValue
- CAnimationPoint [MFC], GetValue
- CAnimationPoint [MFC], GetX
- CAnimationPoint [MFC], GetY
- CAnimationPoint [MFC], SetDefaultValue
- CAnimationPoint [MFC], GetAnimationVariableList
- CAnimationPoint [MFC], m_xValue
- CAnimationPoint [MFC], m_yValue
ms.assetid: 5dc4d46f-e695-4681-b15c-544b78b3e317
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2fa0258b002d421376855eaf88c02444f0ddc620
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50076484"
---
# <a name="canimationpoint-class"></a>Classe CAnimationPoint

Implementa a funcionalidade de um ponto cujas coordenadas podem ser animadas.

## <a name="syntax"></a>Sintaxe

```
class CAnimationPoint : public CAnimationBaseObject;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationPoint::CAnimationPoint](#canimationpoint)|Sobrecarregado. Constrói um objeto CAnimationPoint.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationPoint::AddTransition](#addtransition)|Adiciona as transições para X e Y de coordenadas.|
|[CAnimationPoint::GetDefaultValue](#getdefaultvalue)|Retorna os valores padrão para X e Y de coordenadas.|
|[CAnimationPoint::GetValue](#getvalue)|Retorna o valor atual.|
|[CAnimationPoint::GetX](#getx)|Fornece acesso ao CAnimationVariable de coordenada X.|
|[CAnimationPoint::GetY](#gety)|Fornece acesso ao CAnimationVariable para a coordenada Y.|
|[CAnimationPoint::SetDefaultValue](#setdefaultvalue)|Define o valor padrão.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationPoint::GetAnimationVariableList](#getanimationvariablelist)|Coloca as variáveis de animação encapsulado em uma lista. (Substitui [CAnimationBaseObject::GetAnimationVariableList](../../mfc/reference/canimationbaseobject-class.md#getanimationvariablelist).)|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationPoint::operator CPoint](#operator_cpoint)|Converte um CAnimationPoint um CPoint.|
|[CAnimationPoint::operator =](#operator_eq)|Atribui ptSrc a CAnimationPoint.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationPoint::m_xValue](#m_xvalue)|A variável de animação encapsulada que representa o X coordenadas de ponto de animação.|
|[CAnimationPoint::m_yValue](#m_yvalue)|A variável de animação encapsulada que representa a coordenada Y do ponto de animação.|

## <a name="remarks"></a>Comentários

A classe CAnimationPoint encapsula os dois objetos CAnimationVariable e pode representar em aplicativos de um ponto. Por exemplo, você pode usar essa classe para animar uma posição de qualquer objeto na tela (como cadeia de caracteres de texto, círculo, ponto etc). Para usar essa classe no aplicativo, basta instanciar um objeto dessa classe, adicioná-lo ao controlador de animação usando CAnimationController::AddAnimationObject e chamar AddTransition para cada transição a ser aplicado à coordenadas X e/ou Y.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CAnimationBaseObject](../../mfc/reference/canimationbaseobject-class.md)

`CAnimationPoint`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

##  <a name="addtransition"></a>  CAnimationPoint::AddTransition

Adiciona as transições para X e Y de coordenadas.

```
void AddTransition(
    CBaseTransition* pXTransition,
    CBaseTransition* pYTransition);
```

### <a name="parameters"></a>Parâmetros

*pXTransition*<br/>
Um ponteiro para fazer a transição para coordenadas X.

*pYTransition*<br/>
Coordene um ponteiro para fazer a transição para a Y.

### <a name="remarks"></a>Comentários

Chame essa função para adicionar as transições especificadas à lista interna de transições a serem aplicadas às variáveis de animação para X e Y de coordenadas. Ao adicionar transições, eles não são aplicados imediatamente e armazenados em uma lista interna. As transições são aplicadas (adicionado a um storyboard para um determinado valor) quando você chama CAnimationController::AnimateGroup. Se você não precisa aplicar uma transição de coordenadas, é possível passar NULL.

##  <a name="canimationpoint"></a>  CAnimationPoint::CAnimationPoint

Constrói um objeto CAnimationPoint.

```
CAnimationPoint();

CAnimationPoint(
    const CPoint& ptDefault,
    UINT32 nGroupID,
    UINT32 nObjectID = (UINT32)-1,
    DWORD dwUserData = 0);
```

### <a name="parameters"></a>Parâmetros

*ptDefault*<br/>
Especifica as coordenadas de ponto padrão.

*nGroupID*<br/>
Especifica a ID do grupo.

*nObjectID*<br/>
Especifica a ID de objeto.

*dwUserData*<br/>
Especifica os dados definidos pelo usuário.

### <a name="remarks"></a>Comentários

Constrói um objeto CAnimationPoint com propriedades padrão: padrão as coordenadas de ponto, a ID do grupo e a ID de objeto são definidos como 0.

##  <a name="getanimationvariablelist"></a>  CAnimationPoint::GetAnimationVariableList

Coloca as variáveis de animação encapsulado em uma lista.

```
virtual void GetAnimationVariableList(CList<CAnimationVariable*, CAnimationVariable*>& lst);
```

### <a name="parameters"></a>Parâmetros

*lst*<br/>
Quando a função retorna, ele contém ponteiros para dois objetos CAnimationVariable que representam as coordenadas X e Y.

##  <a name="getdefaultvalue"></a>  CAnimationPoint::GetDefaultValue

Retorna os valores padrão para X e Y de coordenadas.

```
CPoint GetDefaultValue();
```

### <a name="return-value"></a>Valor de retorno

Um valor padrão de recipiente ponto.

### <a name="remarks"></a>Comentários

Chame essa função para recuperar o valor padrão, que foi anteriormente definido pelo construtor ou SetDefaultValue.

##  <a name="getvalue"></a>  CAnimationPoint::GetValue

Retorna o valor atual.

```
BOOL GetValue(CPoint& ptValue);
```

### <a name="parameters"></a>Parâmetros

*ptValue*<br/>
Saída. Quando este método retorna, contém o valor atual.

### <a name="return-value"></a>Valor de retorno

TRUE se o valor atual foi recuperado com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame essa função para recuperar o valor atual de ponto de animação. Se esse método falhar ou subjacente COM objetos para X e Y coordenadas não foram inicializadas, ptValue contém o valor padrão, que foi anteriormente definido no construtor ou por SetDefaultValue.

##  <a name="getx"></a>  CAnimationPoint::GetX

Fornece acesso ao CAnimationVariable de coordenada X.

```
CAnimationVariable& GetX();
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao CAnimationVariable encapsulado representando X coordenar.

### <a name="remarks"></a>Comentários

Você pode chamar esse método para obter acesso direto ao CAnimationVariable subjacente que representa o X coordenar.

##  <a name="gety"></a>  CAnimationPoint::GetY

Fornece acesso ao CAnimationVariable para a coordenada Y.

```
CAnimationVariable& GetY();
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao CAnimationVariable encapsulado, que representa a coordenada Y.

### <a name="remarks"></a>Comentários

Você pode chamar esse método para obter acesso direto ao CAnimationVariable subjacente que representa a coordenada Y.

##  <a name="m_xvalue"></a>  CAnimationPoint::m_xValue

A variável de animação encapsulada que representa o X coordenadas de ponto de animação.

```
CAnimationVariable m_xValue;
```

##  <a name="m_yvalue"></a>  CAnimationPoint::m_yValue

A variável de animação encapsulada que representa a coordenada Y do ponto de animação.

```
CAnimationVariable m_yValue;
```

##  <a name="operator_cpoint"></a>  CAnimationPoint::operator CPoint

Converte um CAnimationPoint um CPoint.

```
operator CPoint();
```

### <a name="return-value"></a>Valor de retorno

Valor atual da CAnimationPoint como CPoint.

### <a name="remarks"></a>Comentários

Essa função chama internamente GetValue. Se falhar GetValue por algum motivo, o ponto retornado conterá valores padrão para X e Y de coordenadas.

##  <a name="operator_eq"></a>  CAnimationPoint::operator =

Atribui ptSrc a CAnimationPoint.

```
void operator=(const CPoint& ptSrc);
```

### <a name="parameters"></a>Parâmetros

*ptSrc*<br/>
Refere-se a CPoint ou ponto.

### <a name="remarks"></a>Comentários

Atribui ptSrc a CAnimationPoint. É recomendável fazer o que antes do início da animação, pois este operador chama SetDefaultValue, que recria o subjacente COM objetos de coordenadas X e Y se eles tiverem sido criados. Se você se inscreveu nesse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisa habilitar novamente esses eventos.

##  <a name="setdefaultvalue"></a>  CAnimationPoint::SetDefaultValue

Define o valor padrão.

```
void SetDefaultValue(const POINT& ptDefault);
```

### <a name="parameters"></a>Parâmetros

*ptDefault*<br/>
Especifica o valor de ponto padrão.

### <a name="remarks"></a>Comentários

Use esta função para definir um valor padrão para o objeto de animação. Esse padrão do métodos atribui valores para as coordenadas X e Y do ponto de animação. Ele também recria os objetos subjacentes se eles tiverem sido criados. Se você se inscreveu nesse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisa habilitar novamente esses eventos.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
