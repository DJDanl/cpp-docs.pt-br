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
ms.openlocfilehash: ad7200ca53aa99104270209ca253b93d2393d8a8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50448640"
---
# <a name="canimationsize-class"></a>Classe CAnimationSize

Implementa a funcionalidade de um objeto de tamanho cujas dimensões podem ser animadas.

## <a name="syntax"></a>Sintaxe

```
class CAnimationSize : public CAnimationBaseObject;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationSize::CAnimationSize](#canimationsize)|Sobrecarregado. Constrói um objeto de tamanho de animação.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationSize::AddTransition](#addtransition)|Adiciona as transições de largura e altura.|
|[CAnimationSize::GetCX](#getcx)|Fornece acesso ao CAnimationVariable que representa a largura.|
|[CAnimationSize::GetCY](#getcy)|Fornece acesso ao CAnimationVariable que representa a altura.|
|[CAnimationSize::GetDefaultValue](#getdefaultvalue)|Retorna os valores padrão para largura e altura.|
|[CAnimationSize::GetValue](#getvalue)|Retorna o valor atual.|
|[CAnimationSize::SetDefaultValue](#setdefaultvalue)|Define o valor padrão.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationSize::GetAnimationVariableList](#getanimationvariablelist)|Coloca as variáveis de animação encapsulado em uma lista. (Substitui [CAnimationBaseObject::GetAnimationVariableList](../../mfc/reference/canimationbaseobject-class.md#getanimationvariablelist).)|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationSize::operator CSize](#operator_csize)|Converte um CAnimationSize um CSize.|
|[CAnimationSize::operator =](#operator_eq)|Atribui szSrc a CAnimationSize.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationSize::m_cxValue](#m_cxvalue)|A variável de animação encapsulada que representa a largura do tamanho de animação.|
|[CAnimationSize::m_cyValue](#m_cyvalue)|A variável de animação encapsulada que representa a altura do tamanho de animação.|

## <a name="remarks"></a>Comentários

A classe CAnimationSize encapsula os dois objetos CAnimationVariable e pode representar em aplicativos de um tamanho. Por exemplo, você pode usar essa classe para animar um tamanho de quaisquer dois objeto dimensional na tela (como o retângulo, controlar etc). Para usar essa classe no aplicativo, basta instanciar um objeto dessa classe, adicioná-lo ao controlador de animação usando CAnimationController::AddAnimationObject e chamar AddTransition para cada transição a ser aplicado à largura e/ou a altura.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CAnimationBaseObject](../../mfc/reference/canimationbaseobject-class.md)

`CAnimationSize`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

##  <a name="addtransition"></a>  CAnimationSize::AddTransition

Adiciona as transições de largura e altura.

```
void AddTransition(
    CBaseTransition* pCXTransition,
    CBaseTransition* pCYTransition);
```

### <a name="parameters"></a>Parâmetros

*pCXTransition*<br/>
Um ponteiro para fazer a transição para a largura.

*pCYTransition*<br/>
Um ponteiro para fazer a transição para a altura.

### <a name="remarks"></a>Comentários

Chame essa função para adicionar as transições especificadas à lista interna de transições a serem aplicadas às variáveis de animação para largura e altura. Ao adicionar transições, eles não são aplicados imediatamente e armazenados em uma lista interna. As transições são aplicadas (adicionado a um storyboard para um determinado valor) quando você chama CAnimationController::AnimateGroup. Se você não precisa aplicar uma transição para uma das dimensões, é possível passar NULL.

##  <a name="canimationsize"></a>  CAnimationSize::CAnimationSize

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
Especifica a ID do grupo.

*nObjectID*<br/>
Especifica a ID de objeto.

*dwUserData*<br/>
Especifica os dados definidos pelo usuário.

### <a name="remarks"></a>Comentários

O objeto é construído com valores padrão para largura, altura, objeto ID e a ID de grupo, que será definida como 0. Eles podem ser alterados posteriormente em tempo de execução usando SetDefaultValue e SetID.

##  <a name="getanimationvariablelist"></a>  CAnimationSize::GetAnimationVariableList

Coloca as variáveis de animação encapsulado em uma lista.

```
virtual void GetAnimationVariableList(
    CList<CAnimationVariable*,
    CAnimationVariable*>& lst);
```

### <a name="parameters"></a>Parâmetros

*lst*<br/>
Quando a função retorna, ele contém ponteiros para dois objetos CAnimationVariable que representa a largura e altura.

##  <a name="getcx"></a>  CAnimationSize::GetCX

Fornece acesso ao CAnimationVariable que representa a largura.

```
CAnimationVariable& GetCX();
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao CAnimationVariable encapsulado, que representa a largura.

### <a name="remarks"></a>Comentários

Você pode chamar esse método para obter acesso direto ao CAnimationVariable subjacente que representa a largura.

##  <a name="getcy"></a>  CAnimationSize::GetCY

Fornece acesso ao CAnimationVariable que representa a altura.

```
CAnimationVariable& GetCY();
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao CAnimationVariable encapsulado, que representa a altura.

### <a name="remarks"></a>Comentários

Você pode chamar esse método para obter acesso direto ao CAnimationVariable subjacente que representa a altura.

##  <a name="getdefaultvalue"></a>  CAnimationSize::GetDefaultValue

Retorna os valores padrão para largura e altura.

```
CSize GetDefaultValue();
```

### <a name="return-value"></a>Valor de retorno

Um objeto CSize que contém os valores padrão.

### <a name="remarks"></a>Comentários

Chame essa função para recuperar o valor padrão, que foi anteriormente definido pelo construtor ou SetDefaultValue.

##  <a name="getvalue"></a>  CAnimationSize::GetValue

Retorna o valor atual.

```
BOOL GetValue(CSize& szValue);
```

### <a name="parameters"></a>Parâmetros

*szValue*<br/>
Saída. Quando este método retorna, contém o valor atual.

### <a name="return-value"></a>Valor de retorno

TRUE se o valor atual foi recuperado com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame essa função para recuperar o valor atual de tamanho de animação. Se esse método falhar ou objetos de COM subjacentes para largura e o tamanho não foram inicializados, szValue contém o valor padrão, que foi anteriormente definido no construtor ou por SetDefaultValue.

##  <a name="m_cxvalue"></a>  CAnimationSize::m_cxValue

A variável de animação encapsulada que representa a largura do tamanho de animação.

```
CAnimationVariable m_cxValue;
```

##  <a name="m_cyvalue"></a>  CAnimationSize::m_cyValue

A variável de animação encapsulada que representa a altura do tamanho de animação.

```
CAnimationVariable m_cyValue;
```

##  <a name="operator_csize"></a>  CAnimationSize::operator CSize

Converte um CAnimationSize um CSize.

```
operator CSize();
```

### <a name="return-value"></a>Valor de retorno

Valor atual de tamanho de animação como CSize.

### <a name="remarks"></a>Comentários

Essa função chama internamente GetValue. Se falhar GetValue por algum motivo, o tamanho retornado conterá valores padrão para largura e altura.

##  <a name="operator_eq"></a>  CAnimationSize::operator =

Atribui szSrc a CAnimationSize.

```
void operator=(const CSize& szSrc);
```

### <a name="parameters"></a>Parâmetros

*szSrc*<br/>
Refere-se ao CSize ou tamanho.

### <a name="remarks"></a>Comentários

Atribui szSrc a CAnimationSize. É recomendável fazer isso antes do início da animação, pois este operador chama SetDefaultValue, que recria os objetos subjacentes de COM para largura e altura se eles tiverem sido criados. Se você se inscreveu nesse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisa habilitar novamente esses eventos.

##  <a name="setdefaultvalue"></a>  CAnimationSize::SetDefaultValue

Define o valor padrão.

```
void SetDefaultValue(const CSize& szDefault);
```

### <a name="parameters"></a>Parâmetros

*szDefault*<br/>
Especifica o novo tamanho padrão.

### <a name="remarks"></a>Comentários

Use esta função para definir um valor padrão para o objeto de animação. Esse método atribui valores padrão para largura e altura do tamanho de animação. Ele também recria os objetos subjacentes se eles tiverem sido criados. Se você se inscreveu nesse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisa habilitar novamente esses eventos.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
