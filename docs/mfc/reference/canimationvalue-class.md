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
ms.openlocfilehash: 86a2caa8946bcafeabf85687a24b2430ecefe790
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62338682"
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
|[CAnimationValue::AddTransition](#addtransition)|Adiciona uma transição para ser aplicado a um valor.|
|[CAnimationValue::GetValue](#getvalue)|Sobrecarregado. Recupera o valor atual.|
|[CAnimationValue::GetVariable](#getvariable)|Fornece acesso à variável de animação encapsulado.|
|[CAnimationValue::SetDefaultValue](#setdefaultvalue)|Define o valor padrão.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationValue::GetAnimationVariableList](#getanimationvariablelist)|Coloca a variável de animação encapsulado em uma lista. (Substitui [CAnimationBaseObject::GetAnimationVariableList](../../mfc/reference/canimationbaseobject-class.md#getanimationvariablelist).)|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationValue::operator dupla](#operator_double)|Fornece a conversão entre CAnimationValue e DOUBLE.|
|[CAnimationValue::operator INT32](#operator_int32)|Fornece a conversão entre CAnimationValue e INT32.|
|[CAnimationValue::operator=](#operator_eq)|Sobrecarregado. Atribui um valor INT32 a CAnimationValue.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationValue::m_value](#m_value)|A variável de animação encapsulada que representa o valor da animação.|

## <a name="remarks"></a>Comentários

A classe CAnimationValue encapsula um único objeto CAnimationVariable e pode representar em aplicativos de um único valor animado. Por exemplo, você pode usar essa classe para transparência animada (efeito de esmaecimento), de ângulo (para girar objetos), ou para qualquer outro caso, quando você precisa criar uma animação dependendo de um único valor animado. Para usar essa classe no aplicativo, basta instanciar um objeto dessa classe, adicioná-lo ao controlador de animação usando CAnimationController::AddAnimationObject e chamar AddTransition para cada transição a ser aplicado ao valor.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CAnimationBaseObject](../../mfc/reference/canimationbaseobject-class.md)

`CAnimationValue`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

##  <a name="addtransition"></a>  CAnimationValue::AddTransition

Adiciona uma transição para ser aplicado a um valor.

```
void AddTransition(CBaseTransition* pTransition);
```

### <a name="parameters"></a>Parâmetros

*pTransition*<br/>
Um ponteiro para objeto de transição.

### <a name="remarks"></a>Comentários

Chame essa função para adicionar uma transição à lista interna de transições a serem aplicadas a uma variável de animação. Ao adicionar transições, eles não são aplicados imediatamente e armazenados em uma lista interna. As transições são aplicadas (adicionado a um storyboard para um determinado valor) quando você chama CAnimationController::AnimateGroup.

##  <a name="canimationvalue"></a>  CAnimationValue::CAnimationValue

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
Especifica a ID do grupo.

*nObjectID*<br/>
Especifica a ID de objeto.

*dwUserData*<br/>
Especifica os dados definidos pelo usuário.

### <a name="remarks"></a>Comentários

Constrói um objeto CAnimationValue com propriedades padrão: valor padrão, ID de grupo e a ID de objeto são definidos como 0.

##  <a name="getanimationvariablelist"></a>  CAnimationValue::GetAnimationVariableList

Coloca a variável de animação encapsulado em uma lista.

```
virtual void GetAnimationVariableList(
    CList<CAnimationVariable*,
    CAnimationVariable*>& lst);
```

### <a name="parameters"></a>Parâmetros

*lst*<br/>
Quando a função retorna, ele contém um ponteiro para CAnimationVariable que representa o valor animado.

##  <a name="getvalue"></a>  CAnimationValue::GetValue

Recupera o valor atual.

```
BOOL GetValue(DOUBLE& dblValue);
BOOL GetValue(INT32& nValue);
```

### <a name="parameters"></a>Parâmetros

*dblValue*<br/>
Saída. Quando a função retorna, ele contém um valor atual da variável de animação.

*nValue*<br/>
Saída. Quando a função retorna, ele contém um valor atual da variável de animação.

### <a name="return-value"></a>Valor de retorno

TRUE se o valor atual foi recuperado com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame essa função para recuperar o valor atual. Essa implementação chama o objeto COM encapsulado, e se a chamada falhar, este método retorna o valor padrão que foi anteriormente definido no construtor ou com SetDefaultValue.

##  <a name="getvariable"></a>  CAnimationValue::GetVariable

Fornece acesso à variável de animação encapsulado.

```
CAnimationVariable& GetVariable();
```

### <a name="return-value"></a>Valor de retorno

Uma referência à variável de animação encapsulado.

### <a name="remarks"></a>Comentários

Use esse método para acessar a variável de animação encapsulado. Do CAnimationVariable você obtém acesso ao objeto subjacente de IUIAnimationVariable, cujo ponteiro pode ser NULL se a variável de animação não tiver sido criado.

##  <a name="m_value"></a>  CAnimationValue::m_value

A variável de animação encapsulada que representa o valor da animação.

```
CAnimationVariable m_value;
```

##  <a name="operator_double"></a>  CAnimationValue::operator DOUBLE

Fornece a conversão entre CAnimationValue e DOUBLE.

```
operator DOUBLE();
```

### <a name="return-value"></a>Valor de retorno

Valor atual do valor da animação.

### <a name="remarks"></a>Comentários

Fornece a conversão entre CAnimationValue e DOUBLE. Internamente, esse método chama GetValue e não verifica se há erros. Se falhar GetValue, o valor retornado conterá um valor padrão definido anteriormente no construtor ou com SetDefaultValue.

##  <a name="operator_int32"></a>  CAnimationValue::operator INT32

Fornece a conversão entre CAnimationValue e INT32.

```
operator INT32();
```

### <a name="return-value"></a>Valor de retorno

Valor atual do valor da animação como inteiro.

### <a name="remarks"></a>Comentários

Fornece a conversão entre CAnimationValue e INT32. Internamente, esse método chama GetValue e não verifica se há erros. Se falhar GetValue, o valor retornado conterá um valor padrão definido anteriormente no construtor ou com SetDefaultValue.

##  <a name="operator_eq"></a>  CAnimationValue::operator=

Atribui um valor duplo a CAnimationValue.

```
void operator=(DOUBLE dblVal);
void operator=(INT32 nVal);
```

### <a name="parameters"></a>Parâmetros

*dblVal*<br/>
Especifica o valor a ser atribuído ao valor da animação.

*nVal*<br/>
Especifica o valor a ser atribuído ao valor da animação.

### <a name="remarks"></a>Comentários

Atribui um valor duplo a CAnimationValue. Esse valor é definido como um valor padrão para a variável de animação encapsulado. Se você se inscreveu nesse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisa habilitar novamente esses eventos.

##  <a name="setdefaultvalue"></a>  CAnimationValue::SetDefaultValue

Define o valor padrão.

```
void SetDefaultValue(DOUBLE dblDefaultValue);
```

### <a name="parameters"></a>Parâmetros

*dblDefaultValue*<br/>
Especifica o valor padrão.

### <a name="remarks"></a>Comentários

Use esse método para definir um valor padrão. Um valor padrão é retornado ao aplicativo quando a animação não tiver sido iniciada e/ou o objeto subjacente de COM não foi criado. Se o objeto COM subjacente encapsulado em CAnimationVarible já foi criado, esse método recria a ele, portanto você pode precisar chamar métodos EnableValueChanged/EnableIntegerValueChanged novamente.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
