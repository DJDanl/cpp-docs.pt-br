---
title: Classe CAnimationPoint
ms.date: 11/04/2016
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
ms.openlocfilehash: fcdd07efb46c97d27a9f1349c297688b5705f176
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81755147"
---
# <a name="canimationpoint-class"></a>Classe CAnimationPoint

Implementa a funcionalidade de um ponto cujas coordenadas podem ser animadas.

## <a name="syntax"></a>Sintaxe

```
class CAnimationPoint : public CAnimationBaseObject;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationPoint::CAnimationPoint](#canimationpoint)|Sobrecarregado. Constrói o objeto CAnimationPoint.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationPoint::AddTransition](#addtransition)|Adiciona transições para coordenadas X e Y.|
|[CAnimationPoint::GetDefaultValue](#getdefaultvalue)|Retorna os valores padrão para coordenadas X e Y.|
|[CAnimationPoint::obtervalor](#getvalue)|Retorna o valor atual.|
|[CAnimationPoint::getX](#getx)|Fornece acesso à coordenada CAnimationVariable for X.|
|[CAnimationPoint::gety](#gety)|Fornece acesso à coordenada CAnimationVariable para Y.|
|[CAnimationPoint:Set'sDefaultValue](#setdefaultvalue)|Define o valor padrão.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationPoint::getAnimationVariablelist](#getanimationvariablelist)|Coloca as variáveis de animação encapsuladas em uma lista. (Substitui [cAnimationBaseObject:GetAnimationVariableList](../../mfc/reference/canimationbaseobject-class.md#getanimationvariablelist).)|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationPoint::operador CPoint](#operator_cpoint)|Converte um CAnimationPoint em um CPoint.|
|[CAnimationPoint::operador=](#operator_eq)|Atribui ptSrc ao CAnimationPoint.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationPoint::m_xValue](#m_xvalue)|A variável de animação encapsulada que representa x coordenada do ponto de animação.|
|[CAnimationPoint::m_yValue](#m_yvalue)|A variável de animação encapsulada que representa a coordenada Y do ponto de animação.|

## <a name="remarks"></a>Comentários

A classe CAnimationPoint encapsula dois objetos CAnimationVariable e pode representar em aplicativos um ponto. Por exemplo, você pode usar esta classe para animar uma posição de qualquer objeto na tela (como seqüência de texto, círculo, ponto etc). Para usar esta classe no aplicativo, basta instanciar um objeto desta classe, adicioná-lo ao controlador de animação usando CAnimationController::AddAnimationObject e chamar AddTransition para cada transição a ser aplicada às coordenadas X e/ou Y.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CAnimationBaseObject](../../mfc/reference/canimationbaseobject-class.md)

`CAnimationPoint`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="canimationpointaddtransition"></a><a name="addtransition"></a>CAnimationPoint::AddTransition

Adiciona transições para coordenadas X e Y.

```cpp
void AddTransition(
    CBaseTransition* pXTransition,
    CBaseTransition* pYTransition);
```

### <a name="parameters"></a>Parâmetros

*pXTransition*<br/>
Um ponteiro para transição para coordenadas X.

*pYTransition*<br/>
Um ponteiro para a transição para a coordenada Y.

### <a name="remarks"></a>Comentários

Chame esta função para adicionar as transições especificadas à lista interna de transições a serem aplicadas às variáveis de animação para coordenadas X e Y. Quando você adiciona transições, elas não são aplicadas imediatamente e armazenadas em uma lista interna. Transições são aplicadas (adicionadas a um storyboard para um determinado valor) quando você chama CAnimationController::AnimateGroup. Se você não precisar aplicar uma transição para uma das coordenadas, você pode passar NULL.

## <a name="canimationpointcanimationpoint"></a><a name="canimationpoint"></a>CAnimationPoint::CAnimationPoint

Constrói o objeto CAnimationPoint.

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
Especifica o ID do grupo.

*nObjectID*<br/>
Especifica o ID do objeto.

*dwUserData*<br/>
Especifica dados definidos pelo usuário.

### <a name="remarks"></a>Comentários

Construa o objeto CAnimationPoint com propriedades padrão: as coordenadas de ponto padrão, o ID do grupo e o ID do objeto são definidos como 0.

## <a name="canimationpointgetanimationvariablelist"></a><a name="getanimationvariablelist"></a>CAnimationPoint::getAnimationVariablelist

Coloca as variáveis de animação encapsuladas em uma lista.

```
virtual void GetAnimationVariableList(CList<CAnimationVariable*, CAnimationVariable*>& lst);
```

### <a name="parameters"></a>Parâmetros

*Lst*<br/>
Quando a função retorna, ela contém ponteiros para dois objetos CAnimationVariable representando as coordenadas X e Y.

## <a name="canimationpointgetdefaultvalue"></a><a name="getdefaultvalue"></a>CAnimationPoint::GetDefaultValue

Retorna os valores padrão para coordenadas X e Y.

```
CPoint GetDefaultValue();
```

### <a name="return-value"></a>Valor retornado

Um ponto contendo valor padrão.

### <a name="remarks"></a>Comentários

Chame essa função para recuperar o valor padrão, que foi definido anteriormente pelo construtor ou setDefaultValue.

## <a name="canimationpointgetvalue"></a><a name="getvalue"></a>CAnimationPoint::obtervalor

Retorna o valor atual.

```
BOOL GetValue(CPoint& ptValue);
```

### <a name="parameters"></a>Parâmetros

*ptValue*<br/>
Saída. Contém o valor atual quando este método retorna.

### <a name="return-value"></a>Valor retornado

TRUE, se o valor atual foi recuperado com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Chame esta função para recuperar o valor atual do ponto de animação. Se este método falhar ou os objetos COM subjacentes para coordenadas X e Y não tiverem sido inicializados, o ptValue contém o valor padrão, que foi previamente definido no construtor ou no SetDefaultValue.

## <a name="canimationpointgetx"></a><a name="getx"></a>CAnimationPoint::getX

Fornece acesso à coordenada CAnimationVariable for X.

```
CAnimationVariable& GetX();
```

### <a name="return-value"></a>Valor retornado

Uma referência ao CAnimationVariable encapsulado representando a coordenada X.

### <a name="remarks"></a>Comentários

Você pode chamar este método para obter acesso direto à CAnimationVariable subjacente representando x coordenadas.

## <a name="canimationpointgety"></a><a name="gety"></a>CAnimationPoint::gety

Fornece acesso à coordenada CAnimationVariable para Y.

```
CAnimationVariable& GetY();
```

### <a name="return-value"></a>Valor retornado

Uma referência à CAnimationVariable encapsulada representando a coordenada Y.

### <a name="remarks"></a>Comentários

Você pode chamar este método para obter acesso direto à canimationvariable subjacente representando a coordenada Y.

## <a name="canimationpointm_xvalue"></a><a name="m_xvalue"></a>CAnimationPoint::m_xValue

A variável de animação encapsulada que representa x coordenada do ponto de animação.

```
CAnimationVariable m_xValue;
```

## <a name="canimationpointm_yvalue"></a><a name="m_yvalue"></a>CAnimationPoint::m_yValue

A variável de animação encapsulada que representa a coordenada Y do ponto de animação.

```
CAnimationVariable m_yValue;
```

## <a name="canimationpointoperator-cpoint"></a><a name="operator_cpoint"></a>CAnimationPoint::operador CPoint

Converte um CAnimationPoint em um CPoint.

```
operator CPoint();
```

### <a name="return-value"></a>Valor retornado

Valor atual do CAnimationPoint como CPoint.

### <a name="remarks"></a>Comentários

Esta função chama internamente GetValue. Se getvalue por algum motivo falhar, o ponto retornado conterá valores padrão para coordenadas X e Y.

## <a name="canimationpointoperator"></a><a name="operator_eq"></a>CAnimationPoint::operador=

Atribui ptSrc ao CAnimationPoint.

```cpp
void operator=(const CPoint& ptSrc);
```

### <a name="parameters"></a>Parâmetros

*ptSrc*<br/>
Refere-se a CPoint ou POINT.

### <a name="remarks"></a>Comentários

Atribui ptSrc ao CAnimationPoint. Recomenda-se fazer isso antes do início da animação, porque este operador chama SetDefaultValue, que recria os objetos COM subjacentes para coordenadas X e Y se eles tiverem sido criados. Se você inscreveu esse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisará reativar esses eventos.

## <a name="canimationpointsetdefaultvalue"></a><a name="setdefaultvalue"></a>CAnimationPoint:Set'sDefaultValue

Define o valor padrão.

```cpp
void SetDefaultValue(const POINT& ptDefault);
```

### <a name="parameters"></a>Parâmetros

*ptDefault*<br/>
Especifica o valor de ponto padrão.

### <a name="remarks"></a>Comentários

Use esta função para definir um valor padrão para objeto de animação. Estemétodo atribui valores padrão às coordenadas X e Y do ponto de animação. Ele também recria objetos COM subjacentes se eles tiverem sido criados. Se você inscreveu esse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisará reativar esses eventos.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
