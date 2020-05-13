---
title: Classe CAnimationValue
ms.date: 11/04/2016
f1_keywords:
- CAnimationValue
- AFXANIMATIONCONTROLLER/CAnimationValue
- AFXANIMATIONCONTROLLER/CAnimationValue::CAnimationValue
- AFXANIMATIONCONTROLLER/CAnimationValue::AddTransition
- AFXANIMATIONCONTROLLER/CAnimationValue::GetValue
- AFXANIMATIONCONTROLLER/CAnimationValue::GetVariable
- AFXANIMATIONCONTROLLER/CAnimationValue::SetDefaultValue
- AFXANIMATIONCONTROLLER/CAnimationValue::GetAnimationVariableList
- AFXANIMATIONCONTROLLER/CAnimationValue::m_value
helpviewer_keywords:
- CAnimationValue [MFC], CAnimationValue
- CAnimationValue [MFC], AddTransition
- CAnimationValue [MFC], GetValue
- CAnimationValue [MFC], GetVariable
- CAnimationValue [MFC], SetDefaultValue
- CAnimationValue [MFC], GetAnimationVariableList
- CAnimationValue [MFC], m_value
ms.assetid: 78c5ae19-ede5-4f20-bfbe-68b467b603c2
ms.openlocfilehash: e020e3e123bb5dc96a623e7a41896d75c611b81e
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81755080"
---
# <a name="canimationvalue-class"></a>Classe CAnimationValue

Implementa a funcionalidade do objeto de animação que tem um valor.

## <a name="syntax"></a>Sintaxe

```
class CAnimationValue : public CAnimationBaseObject;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationValue::CAnimationValue](#canimationvalue)|Sobrecarregado. Constrói um objeto CAnimationValue.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationValue::AddTransition](#addtransition)|Adiciona uma transição a ser aplicada a um valor.|
|[CAnimationValue::GetValue](#getvalue)|Sobrecarregado. Recupera o valor atual.|
|[CAnimationValue::GetVariable](#getvariable)|Fornece acesso à variável animação encapsulada.|
|[CAnimationValue::SetDefault'2](#setdefaultvalue)|Define o valor padrão.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[cAnimationValue::GetAnimationVariableList](#getanimationvariablelist)|Coloca a variável de animação encapsulada em uma lista. (Substitui [cAnimationBaseObject:GetAnimationVariableList](../../mfc/reference/canimationbaseobject-class.md#getanimationvariablelist).)|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationValue::operador DUPLO](#operator_double)|Fornece conversão entre CAnimationValue e DOUBLE.|
|[CAnimationValue::operador INT32](#operator_int32)|Fornece conversão entre CAnimationValue e INT32.|
|[CAnimationValue::operador=](#operator_eq)|Sobrecarregado. Atribui um valor INT32 ao CAnimationValue.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationValue::m_value](#m_value)|A variável de animação encapsulada que representa o valor da animação.|

## <a name="remarks"></a>Comentários

A classe CAnimationValue encapsula um único objeto CAnimationVariable e pode representar em aplicativos um único valor animado. Por exemplo, você pode usar esta classe para transparência animada (efeito fade), ângulo (para girar objetos) ou para qualquer outro caso quando você precisar criar uma animação dependendo de um único valor animado. Para usar esta classe no aplicativo, basta instanciar um objeto desta classe, adicioná-lo ao controlador de animação usando CAnimationController::AddAnimationObject e chamar AddTransition para cada transição a ser aplicada ao valor.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CAnimationBaseObject](../../mfc/reference/canimationbaseobject-class.md)

`CAnimationValue`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="canimationvalueaddtransition"></a><a name="addtransition"></a>CAnimationValue::AddTransition

Adiciona uma transição a ser aplicada a um valor.

```cpp
void AddTransition(CBaseTransition* pTransition);
```

### <a name="parameters"></a>Parâmetros

*pTransição*<br/>
Um ponteiro para objeto de transição.

### <a name="remarks"></a>Comentários

Chame esta função para adicionar uma transição à lista interna de transições a serem aplicadas a uma variável de animação. Quando você adiciona transições, elas não são aplicadas imediatamente e armazenadas em uma lista interna. Transições são aplicadas (adicionadas a um storyboard para um determinado valor) quando você chama CAnimationController::AnimateGroup.

## <a name="canimationvaluecanimationvalue"></a><a name="canimationvalue"></a>CAnimationValue::CAnimationValue

Constrói um objeto CAnimationValue.

```
CAnimationValue();

CAnimationValue(
    DOUBLE dblDefaultValue,
    UINT32 nGroupID,
    UINT32 nObjectID = (UINT32)-1,
    DWORD dwUserData = 0);
```

### <a name="parameters"></a>Parâmetros

*dblDefaultValue*<br/>
Especifica o valor padrão.

*nGroupID*<br/>
Especifica o ID do grupo.

*nObjectID*<br/>
Especifica o ID do objeto.

*dwUserData*<br/>
especifica dados definidos pelo usuário.

### <a name="remarks"></a>Comentários

Construa o objeto CAnimationValue com propriedades padrão: o valor padrão, o ID do grupo e o ID do objeto são definidos como 0.

## <a name="canimationvaluegetanimationvariablelist"></a><a name="getanimationvariablelist"></a>cAnimationValue::GetAnimationVariableList

Coloca a variável de animação encapsulada em uma lista.

```
virtual void GetAnimationVariableList(
    CList<CAnimationVariable*,
    CAnimationVariable*>& lst);
```

### <a name="parameters"></a>Parâmetros

*Lst*<br/>
Quando a função retorna, ela contém um ponteiro para CAnimationVariable representando o valor animado.

## <a name="canimationvaluegetvalue"></a><a name="getvalue"></a>CAnimationValue::GetValue

Recupera o valor atual.

```
BOOL GetValue(DOUBLE& dblValue);
BOOL GetValue(INT32& nValue);
```

### <a name="parameters"></a>Parâmetros

*dblValue*<br/>
Saída. Quando a função retorna, ela contém um valor atual da variável animação.

*Nvalue*<br/>
Saída. Quando a função retorna, ela contém um valor atual da variável animação.

### <a name="return-value"></a>Valor retornado

TRUE se o valor atual foi recuperado com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Chame esta função para recuperar o valor atual. Essa implementação chama o objeto COM encapsulado e, se a chamada falhar, esse método retorna o valor padrão que foi definido anteriormente no construtor ou com SetDefaultValue.

## <a name="canimationvaluegetvariable"></a><a name="getvariable"></a>CAnimationValue::GetVariable

Fornece acesso à variável animação encapsulada.

```
CAnimationVariable& GetVariable();
```

### <a name="return-value"></a>Valor retornado

Uma referência à variável animação encapsulada.

### <a name="remarks"></a>Comentários

Use este método para acessar a variável de animação encapsulada. A partir do CAnimationVariable você tem acesso ao objeto IUIAnimationVariable subjacente, cujo ponteiro pode ser NULO se a variável de animação não tiver sido criada.

## <a name="canimationvaluem_value"></a><a name="m_value"></a>CAnimationValue::m_value

A variável de animação encapsulada que representa o valor da animação.

```
CAnimationVariable m_value;
```

## <a name="canimationvalueoperator-double"></a><a name="operator_double"></a>CAnimationValue::operador DUPLO

Fornece conversão entre CAnimationValue e DOUBLE.

```
operator DOUBLE();
```

### <a name="return-value"></a>Valor retornado

Valor atual do Valor de Animação.

### <a name="remarks"></a>Comentários

Fornece conversão entre CAnimationValue e DOUBLE. Este método chama internamente getvalue e não verifica se há erros. Se o GetValue falhar, o valor retornado conterá um valor padrão previamente definido no construtor ou com SetDefaultValue.

## <a name="canimationvalueoperator-int32"></a><a name="operator_int32"></a>CAnimationValue::operador INT32

Fornece conversão entre CAnimationValue e INT32.

```
operator INT32();
```

### <a name="return-value"></a>Valor retornado

Valor atual do Valor de Animação como inteiro.

### <a name="remarks"></a>Comentários

Fornece conversão entre CAnimationValue e INT32. Este método chama internamente getvalue e não verifica se há erros. Se o GetValue falhar, o valor retornado conterá um valor padrão previamente definido no construtor ou com SetDefaultValue.

## <a name="canimationvalueoperator"></a><a name="operator_eq"></a>CAnimationValue::operador=

Atribui um valor DUPLO ao CAnimationValue.

```cpp
void operator=(DOUBLE dblVal);
void operator=(INT32 nVal);
```

### <a name="parameters"></a>Parâmetros

*dblVal*<br/>
Especifica o valor a ser atribuído ao Valor de Animação.

*nVal*<br/>
Especifica o valor a ser atribuído ao Valor de Animação.

### <a name="remarks"></a>Comentários

Atribui um valor DUPLO ao CAnimationValue. Esse valor é definido como um valor padrão para a variável animação encapsulada. Se você inscreveu esse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisará reativar esses eventos.

## <a name="canimationvaluesetdefaultvalue"></a><a name="setdefaultvalue"></a>CAnimationValue::SetDefault'2

Define o valor padrão.

```cpp
void SetDefaultValue(DOUBLE dblDefaultValue);
```

### <a name="parameters"></a>Parâmetros

*dblDefaultValue*<br/>
Especifica o valor padrão.

### <a name="remarks"></a>Comentários

Use este método para definir um valor padrão. Um valor padrão é devolvido ao aplicativo quando a animação não foi iniciada e/ou objeto COM subjacente não foi criado. Se o objeto COM subjacente encapsulado no CAnimationVarible já foi criado, este método o recria, portanto, você pode precisar chamar Os métodos EnableValueChanged/EnableIntegerValueChanged novamente.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
