---
title: Classe CAnimationColor
ms.date: 11/04/2016
f1_keywords:
- CAnimationColor
- AFXANIMATIONCONTROLLER/CAnimationColor
- AFXANIMATIONCONTROLLER/CAnimationColor::CAnimationColor
- AFXANIMATIONCONTROLLER/CAnimationColor::AddTransition
- AFXANIMATIONCONTROLLER/CAnimationColor::GetB
- AFXANIMATIONCONTROLLER/CAnimationColor::GetDefaultValue
- AFXANIMATIONCONTROLLER/CAnimationColor::GetG
- AFXANIMATIONCONTROLLER/CAnimationColor::GetR
- AFXANIMATIONCONTROLLER/CAnimationColor::GetValue
- AFXANIMATIONCONTROLLER/CAnimationColor::SetDefaultValue
- AFXANIMATIONCONTROLLER/CAnimationColor::GetAnimationVariableList
- AFXANIMATIONCONTROLLER/CAnimationColor::m_bValue
- AFXANIMATIONCONTROLLER/CAnimationColor::m_gValue
- AFXANIMATIONCONTROLLER/CAnimationColor::m_rValue
helpviewer_keywords:
- CAnimationColor [MFC], CAnimationColor
- CAnimationColor [MFC], AddTransition
- CAnimationColor [MFC], GetB
- CAnimationColor [MFC], GetDefaultValue
- CAnimationColor [MFC], GetG
- CAnimationColor [MFC], GetR
- CAnimationColor [MFC], GetValue
- CAnimationColor [MFC], SetDefaultValue
- CAnimationColor [MFC], GetAnimationVariableList
- CAnimationColor [MFC], m_bValue
- CAnimationColor [MFC], m_gValue
- CAnimationColor [MFC], m_rValue
ms.assetid: 88bfabd4-efeb-4652-87e8-304253d8e48c
ms.openlocfilehash: 5940cce6d55b95d8e1bac103cacc0bc828c213de
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371113"
---
# <a name="canimationcolor-class"></a>Classe CAnimationColor

Implementa a funcionalidade de uma cor cujos componentes vermelho, verde e azul podem ser animados.

## <a name="syntax"></a>Sintaxe

```
class CAnimationColor : public CAnimationBaseObject;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationColor::CAnimationColor](#canimationcolor)|Sobrecarregado. Constrói um objeto de cor de animação.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationColor::AddTransition](#addtransition)|Adiciona transições para componentes Vermelho, Verde e Azul.|
|[CAnimationColor::GetB](#getb)|Fornece acesso ao CAnimationVariable representando o componente Azul.|
|[CAnimationColor::GetDefaultValue](#getdefaultvalue)|Retorna os valores padrão para componentes de cor.|
|[CAnimationColor::GetG](#getg)|Fornece acesso ao CAnimationVariable representando o componente Verde.|
|[CAnimationColor::GetR](#getr)|Fornece acesso ao CAnimationVariable representando o componente Vermelho.|
|[CAnimationColor::GetValue](#getvalue)|Retorna o valor atual.|
|[CAnimationColor::SetDefaultValue](#setdefaultvalue)|Define o valor padrão.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[cAnimationColor::getAnimationVariablelist](#getanimationvariablelist)|Coloca as variáveis de animação encapsuladas em uma lista. (Substitui [cAnimationBaseObject:GetAnimationVariableList](../../mfc/reference/canimationbaseobject-class.md#getanimationvariablelist).)|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationColor::operador COLORREF](#operator_colorref)||
|[CAnimationColor::operador=](#operator_eq)|Atribui cor ao CAnimationColor.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationColor::m_bValue](#m_bvalue)|A variável de animação encapsulada que representa o componente Azul da cor da animação.|
|[CAnimationColor::m_gValue](#m_gvalue)|A variável de animação encapsulada que representa o componente verde da cor da animação.|
|[CAnimationColor::m_rValue](#m_rvalue)|A variável de animação encapsulada que representa o componente vermelho da cor da animação.|

## <a name="remarks"></a>Comentários

A classe CAnimationColor encapsula três objetos CAnimationVariable e pode representar em aplicativos uma cor. Por exemplo, você pode usar esta classe para animar cores de qualquer objeto na tela (como cor de texto, cor de fundo etc). Para usar esta classe no aplicativo, basta instanciar um objeto desta classe, adicioná-lo ao controlador de animação usando CAnimationController::AddAnimationObject e chamar AddTransition para cada transição a ser aplicada aos componentes Vermelho, Verde e Azul.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CAnimationBaseObject](../../mfc/reference/canimationbaseobject-class.md)

`CAnimationColor`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="canimationcoloraddtransition"></a><a name="addtransition"></a>CAnimationColor::AddTransition

Adiciona transições para componentes Vermelho, Verde e Azul.

```
void AddTransition(
    CBaseTransition* pRTransition,
    CBaseTransition* pGTransition,
    CBaseTransition* pBTransition);
```

### <a name="parameters"></a>Parâmetros

*pRTransition*<br/>
Transição para componente vermelho.

*pGTransition*<br/>
Transição para componente verde.

*pBTransition*<br/>
Transição para componente Azul.

### <a name="remarks"></a>Comentários

Chame esta função para adicionar as transições especificadas à lista interna de transições a serem aplicadas às variáveis de animação que representam componentes de cor. Quando você adiciona transições, elas não são aplicadas imediatamente e armazenadas em uma lista interna. Transições são aplicadas (adicionadas a um storyboard para um determinado valor) quando você chama CAnimationController::AnimateGroup. Se você não precisar aplicar uma transição a um dos componentes de cor, você pode passar NULL.

## <a name="canimationcolorcanimationcolor"></a><a name="canimationcolor"></a>CAnimationColor::CAnimationColor

Constrói um objeto CAnimationColor.

```
CAnimationColor();

CAnimationColor(
    COLORREF color,
    UINT32 nGroupID,
    UINT32 nObjectID = (UINT32)-1,
    DWORD dwUserData = 0);
```

### <a name="parameters"></a>Parâmetros

*cor*<br/>
Especifica a cor padrão.

*nGroupID*<br/>
Especifica o ID do grupo.

*nObjectID*<br/>
Especifica o ID do objeto.

*dwUserData*<br/>
Especifica dados definidos pelo usuário.

### <a name="remarks"></a>Comentários

O objeto é construído com valores padrão para vermelho, verde, azul, ID de objeto e ID de grupo, que será definido como 0. Eles podem ser alterados mais tarde em tempo de execução usando SetDefaultValue e SetID.

## <a name="canimationcolorgetanimationvariablelist"></a><a name="getanimationvariablelist"></a>cAnimationColor::getAnimationVariablelist

Coloca as variáveis de animação encapsuladas em uma lista.

```
virtual void GetAnimationVariableList(CList<CAnimationVariable*>& lst);
```

### <a name="parameters"></a>Parâmetros

*Lst*<br/>
Quando a função retorna, ela contém ponteiros para três objetos CAnimationVariable representando componentes vermelhos, verdes e azuis.

## <a name="canimationcolorgetb"></a><a name="getb"></a>CAnimationColor::GetB

Fornece acesso ao CAnimationVariable representando o componente Azul.

```
CAnimationVariable& GetB();
```

### <a name="return-value"></a>Valor retornado

Uma referência ao CAnimationVariable encapsulado representando o componente Azul.

### <a name="remarks"></a>Comentários

Você pode chamar este método para obter acesso direto ao CAnimationVariable subjacente representando o componente Azul.

## <a name="canimationcolorgetdefaultvalue"></a><a name="getdefaultvalue"></a>CAnimationColor::GetDefaultValue

Retorna os valores padrão para componentes de cor.

```
COLORREF GetDefaultValue();
```

### <a name="return-value"></a>Valor retornado

Um valor COLORREF contendo padrões para componentes RGB.

### <a name="remarks"></a>Comentários

Chame essa função para recuperar o valor padrão, que foi definido anteriormente pelo construtor ou setDefaultValue.

## <a name="canimationcolorgetg"></a><a name="getg"></a>CAnimationColor::GetG

Fornece acesso ao CAnimationVariable representando o componente Verde.

```
CAnimationVariable& GetG();
```

### <a name="return-value"></a>Valor retornado

Uma referência ao CAnimationVariable encapsulado representando o componente Verde.

### <a name="remarks"></a>Comentários

Você pode chamar este método para obter acesso direto ao CAnimationVariable subjacente representando o componente Verde.

## <a name="canimationcolorgetr"></a><a name="getr"></a>CAnimationColor::GetR

Fornece acesso ao CAnimationVariable representando o componente Vermelho.

```
CAnimationVariable& GetR();
```

### <a name="return-value"></a>Valor retornado

Uma referência ao CAnimationVariable encapsulado representando o componente Vermelho.

### <a name="remarks"></a>Comentários

Você pode chamar este método para obter acesso direto ao CAnimationVariable subjacente representando o componente Vermelho.

## <a name="canimationcolorgetvalue"></a><a name="getvalue"></a>CAnimationColor::GetValue

Retorna o valor atual.

```
BOOL GetValue(COLORREF& color);
```

### <a name="parameters"></a>Parâmetros

*cor*<br/>
Saída. Contém o valor atual quando este método retorna.

### <a name="return-value"></a>Valor retornado

TRUE, se o valor atual foi recuperado com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Chame esta função para recuperar o valor atual da cor da animação. Se este método falhar ou os objetos COM subjacentes para componentes de cor não tiverem sido inicializados, a cor contém o valor padrão, que foi previamente definido no construtor ou no SetDefaultValue.

## <a name="canimationcolorm_bvalue"></a><a name="m_bvalue"></a>CAnimationColor::m_bValue

A variável de animação encapsulada que representa o componente Azul da cor da animação.

```
CAnimationVariable m_bValue;
```

## <a name="canimationcolorm_gvalue"></a><a name="m_gvalue"></a>CAnimationColor::m_gValue

A variável de animação encapsulada que representa o componente verde da cor da animação.

```
CAnimationVariable m_gValue;
```

## <a name="canimationcolorm_rvalue"></a><a name="m_rvalue"></a>CAnimationColor::m_rValue

A variável de animação encapsulada que representa o componente vermelho da cor da animação.

```
CAnimationVariable m_rValue;
```

## <a name="canimationcoloroperator-colorref"></a><a name="operator_colorref"></a>CAnimationColor::operador COLORREF

```
operator COLORREF();
```

### <a name="return-value"></a>Valor retornado

## <a name="canimationcoloroperator"></a><a name="operator_eq"></a>CAnimationColor::operador=

Atribui cor ao CAnimationColor.

```
void operator=(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*cor*<br/>
Especifica a nova cor de animação de valor.

### <a name="remarks"></a>Comentários

Recomenda-se fazer isso antes do início da animação, porque este operador chama SetDefaultValue, que recria os objetos COM subjacentes para componentes de cor se eles tiverem sido criados. Se você inscreveu esse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisará reativar esses eventos.

## <a name="canimationcolorsetdefaultvalue"></a><a name="setdefaultvalue"></a>CAnimationColor::SetDefaultValue

Define o valor padrão.

```
void SetDefaultValue(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*cor*<br/>
Especifica novos valores padrão para componentes vermelho, verde e azul.

### <a name="remarks"></a>Comentários

Use esta função para definir um valor padrão para objeto de animação. Esses métodos atribuem valores padrão a componentes de cor de cor de animação. Ele também recria objetos COM subjacentes se eles tiverem sido criados. Se você inscreveu esse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisará reativar esses eventos.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
