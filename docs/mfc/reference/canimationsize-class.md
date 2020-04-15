---
title: Classe CAnimationSize
ms.date: 11/04/2016
f1_keywords:
- CAnimationSize
- AFXANIMATIONCONTROLLER/CAnimationSize
- AFXANIMATIONCONTROLLER/CAnimationSize::CAnimationSize
- AFXANIMATIONCONTROLLER/CAnimationSize::AddTransition
- AFXANIMATIONCONTROLLER/CAnimationSize::GetCX
- AFXANIMATIONCONTROLLER/CAnimationSize::GetCY
- AFXANIMATIONCONTROLLER/CAnimationSize::GetDefaultValue
- AFXANIMATIONCONTROLLER/CAnimationSize::GetValue
- AFXANIMATIONCONTROLLER/CAnimationSize::SetDefaultValue
- AFXANIMATIONCONTROLLER/CAnimationSize::GetAnimationVariableList
- AFXANIMATIONCONTROLLER/CAnimationSize::m_cxValue
- AFXANIMATIONCONTROLLER/CAnimationSize::m_cyValue
helpviewer_keywords:
- CAnimationSize [MFC], CAnimationSize
- CAnimationSize [MFC], AddTransition
- CAnimationSize [MFC], GetCX
- CAnimationSize [MFC], GetCY
- CAnimationSize [MFC], GetDefaultValue
- CAnimationSize [MFC], GetValue
- CAnimationSize [MFC], SetDefaultValue
- CAnimationSize [MFC], GetAnimationVariableList
- CAnimationSize [MFC], m_cxValue
- CAnimationSize [MFC], m_cyValue
ms.assetid: ea06d1b5-502c-44a3-82ca-8bd6ba6a9364
ms.openlocfilehash: 80a90dfa37bc1d2c3c84e6451ae23af7ded767c2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369698"
---
# <a name="canimationsize-class"></a>Classe CAnimationSize

Implementa a funcionalidade de um objeto de tamanho cujas dimensões podem ser animadas.

## <a name="syntax"></a>Sintaxe

```
class CAnimationSize : public CAnimationBaseObject;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[cAnimationTamanho:CAnimationSize](#canimationsize)|Sobrecarregado. Constrói um objeto de tamanho de animação.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[cAnimationSize::AddTransition](#addtransition)|Adiciona transições para largura e altura.|
|[canimationsize::getcx](#getcx)|Fornece acesso ao CAnimationVariable representando largura.|
|[CAnimationSize::GetCY](#getcy)|Fornece acesso ao CAnimationVariable representando Height.|
|[cAnimationSize::GetDefaultValue](#getdefaultvalue)|Retorna os valores padrão de Largura e Altura.|
|[canimationsize::getValue](#getvalue)|Retorna o valor atual.|
|[CAnimationTamanho:Conjunto Conjunto', ''''''''''''''''''](#setdefaultvalue)|Define o valor padrão.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[cAnimationSize::GetAnimationVariableList](#getanimationvariablelist)|Coloca as variáveis de animação encapsuladas em uma lista. (Substitui [cAnimationBaseObject:GetAnimationVariableList](../../mfc/reference/canimationbaseobject-class.md#getanimationvariablelist).)|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationTamanho:operador CSize](#operator_csize)|Converte um CAnimationSize em um CSize.|
|[CAnimationTamanho::operador=](#operator_eq)|Atribui szSrc ao CAnimationSize.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationSize::m_cxValue](#m_cxvalue)|A variável de animação encapsulada que representa a largura do tamanho da animação.|
|[CAnimationSize::m_cyValue](#m_cyvalue)|A variável de animação encapsulada que representa a altura do tamanho da animação.|

## <a name="remarks"></a>Comentários

A classe CAnimationSize encapsula dois objetos CAnimationVariable e pode representar em aplicativos um tamanho. Por exemplo, você pode usar esta classe para animar um tamanho de qualquer objeto bidimensional na tela (como retângulo, controle etc). Para usar esta classe no aplicativo, basta instanciar um objeto desta classe, adicioná-lo ao controlador de animação usando CAnimationController::AddAnimationObject e chamar AddTransition para cada transição a ser aplicada a Largura e/ou Altura.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CAnimationBaseObject](../../mfc/reference/canimationbaseobject-class.md)

`CAnimationSize`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="canimationsizeaddtransition"></a><a name="addtransition"></a>cAnimationSize::AddTransition

Adiciona transições para largura e altura.

```
void AddTransition(
    CBaseTransition* pCXTransition,
    CBaseTransition* pCYTransition);
```

### <a name="parameters"></a>Parâmetros

*pCXTransition*<br/>
Um ponteiro para transição para largura.

*pCYTransition*<br/>
Um ponteiro para a transição para altura.

### <a name="remarks"></a>Comentários

Chame esta função para adicionar as transições especificadas à lista interna de transições a serem aplicadas às variáveis de animação para Largura e Altura. Quando você adiciona transições, elas não são aplicadas imediatamente e armazenadas em uma lista interna. Transições são aplicadas (adicionadas a um storyboard para um determinado valor) quando você chama CAnimationController::AnimateGroup. Se você não precisa aplicar uma transição para uma das dimensões, você pode passar NULL.

## <a name="canimationsizecanimationsize"></a><a name="canimationsize"></a>cAnimationTamanho:CAnimationSize

Constrói um objeto de tamanho de animação.

```
CAnimationSize();

CAnimationSize(
    const CSize& szDefault,
    UINT32 nGroupID,
    UINT32 nObjectID = (UINT32)-1,
    DWORD dwUserData = 0);
```

### <a name="parameters"></a>Parâmetros

*szDefault*<br/>
Especifica o tamanho padrão.

*nGroupID*<br/>
Especifica o ID do grupo.

*nObjectID*<br/>
Especifica o ID do objeto.

*dwUserData*<br/>
Especifica dados definidos pelo usuário.

### <a name="remarks"></a>Comentários

O objeto é construído com valores padrão para largura, altura, ID do objeto e ID do grupo, que serão definidos como 0. Eles podem ser alterados mais tarde em tempo de execução usando SetDefaultValue e SetID.

## <a name="canimationsizegetanimationvariablelist"></a><a name="getanimationvariablelist"></a>cAnimationSize::GetAnimationVariableList

Coloca as variáveis de animação encapsuladas em uma lista.

```
virtual void GetAnimationVariableList(
    CList<CAnimationVariable*,
    CAnimationVariable*>& lst);
```

### <a name="parameters"></a>Parâmetros

*Lst*<br/>
Quando a função retorna, ela contém ponteiros para dois objetos CAnimationVariable representando a largura e a altura.

## <a name="canimationsizegetcx"></a><a name="getcx"></a>canimationsize::getcx

Fornece acesso ao CAnimationVariable representando largura.

```
CAnimationVariable& GetCX();
```

### <a name="return-value"></a>Valor retornado

Uma referência ao CAnimationVariable encapsulado representando largura.

### <a name="remarks"></a>Comentários

Você pode chamar este método para obter acesso direto ao CAnimationVariable subjacente representando Largura.

## <a name="canimationsizegetcy"></a><a name="getcy"></a>CAnimationSize::GetCY

Fornece acesso ao CAnimationVariable representando Height.

```
CAnimationVariable& GetCY();
```

### <a name="return-value"></a>Valor retornado

Uma referência ao CAnimationVariable encapsulado representando Height.

### <a name="remarks"></a>Comentários

Você pode chamar este método para obter acesso direto ao CAnimationVariable subjacente representando Height.

## <a name="canimationsizegetdefaultvalue"></a><a name="getdefaultvalue"></a>cAnimationSize::GetDefaultValue

Retorna os valores padrão de Largura e Altura.

```
CSize GetDefaultValue();
```

### <a name="return-value"></a>Valor retornado

Um objeto CSize contendo valores padrão.

### <a name="remarks"></a>Comentários

Chame essa função para recuperar o valor padrão, que foi definido anteriormente pelo construtor ou setDefaultValue.

## <a name="canimationsizegetvalue"></a><a name="getvalue"></a>canimationsize::getValue

Retorna o valor atual.

```
BOOL GetValue(CSize& szValue);
```

### <a name="parameters"></a>Parâmetros

*szValue*<br/>
Saída. Contém o valor atual quando este método retorna.

### <a name="return-value"></a>Valor retornado

TRUE, se o valor atual foi recuperado com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Chame esta função para recuperar o valor atual do tamanho da animação. Se este método falhar ou os objetos COM subjacentes para largura e tamanho não tiverem sido inicializados, o szValue contém o valor padrão, que foi previamente definido no construtor ou no SetDefaultValue.

## <a name="canimationsizem_cxvalue"></a><a name="m_cxvalue"></a>CAnimationSize::m_cxValue

A variável de animação encapsulada que representa a largura do tamanho da animação.

```
CAnimationVariable m_cxValue;
```

## <a name="canimationsizem_cyvalue"></a><a name="m_cyvalue"></a>CAnimationSize::m_cyValue

A variável de animação encapsulada que representa a altura do tamanho da animação.

```
CAnimationVariable m_cyValue;
```

## <a name="canimationsizeoperator-csize"></a><a name="operator_csize"></a>CAnimationTamanho:operador CSize

Converte um CAnimationSize em um CSize.

```
operator CSize();
```

### <a name="return-value"></a>Valor retornado

Valor atual do tamanho da animação como CSize.

### <a name="remarks"></a>Comentários

Esta função chama internamente GetValue. Se o GetValue por algum motivo falhar, o tamanho retornado conterá valores padrão para Largura e Altura.

## <a name="canimationsizeoperator"></a><a name="operator_eq"></a>CAnimationTamanho::operador=

Atribui szSrc ao CAnimationSize.

```
void operator=(const CSize& szSrc);
```

### <a name="parameters"></a>Parâmetros

*szSrc*<br/>
Refere-se a CSize ou SIZE.

### <a name="remarks"></a>Comentários

Atribui szSrc ao CAnimationSize. Recomenda-se fazer isso antes do início da animação, porque este operador chama SetDefaultValue, que recria os objetos COM subjacentes para Largura e Altura se eles tiverem sido criados. Se você inscreveu esse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisará reativar esses eventos.

## <a name="canimationsizesetdefaultvalue"></a><a name="setdefaultvalue"></a>CAnimationTamanho:Conjunto Conjunto', ''''''''''''''''''

Define o valor padrão.

```
void SetDefaultValue(const CSize& szDefault);
```

### <a name="parameters"></a>Parâmetros

*szDefault*<br/>
Especifica o novo tamanho padrão.

### <a name="remarks"></a>Comentários

Use esta função para definir um valor padrão para objeto de animação. Estemétodo atribui valores padrão à largura e altura do tamanho da animação. Ele também recria objetos COM subjacentes se eles tiverem sido criados. Se você inscreveu esse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisará reativar esses eventos.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
