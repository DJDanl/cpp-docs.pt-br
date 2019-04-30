---
title: Classe CCustomTransition
ms.date: 11/04/2016
f1_keywords:
- CCustomTransition
- AFXANIMATIONCONTROLLER/CCustomTransition
- AFXANIMATIONCONTROLLER/CCustomTransition::CCustomTransition
- AFXANIMATIONCONTROLLER/CCustomTransition::Create
- AFXANIMATIONCONTROLLER/CCustomTransition::SetInitialValue
- AFXANIMATIONCONTROLLER/CCustomTransition::SetInitialVelocity
- AFXANIMATIONCONTROLLER/CCustomTransition::m_bInitialValueSpecified
- AFXANIMATIONCONTROLLER/CCustomTransition::m_bInitialVelocitySpecified
- AFXANIMATIONCONTROLLER/CCustomTransition::m_initialValue
- AFXANIMATIONCONTROLLER/CCustomTransition::m_initialVelocity
- AFXANIMATIONCONTROLLER/CCustomTransition::m_pInterpolator
helpviewer_keywords:
- CCustomTransition [MFC], CCustomTransition
- CCustomTransition [MFC], Create
- CCustomTransition [MFC], SetInitialValue
- CCustomTransition [MFC], SetInitialVelocity
- CCustomTransition [MFC], m_bInitialValueSpecified
- CCustomTransition [MFC], m_bInitialVelocitySpecified
- CCustomTransition [MFC], m_initialValue
- CCustomTransition [MFC], m_initialVelocity
- CCustomTransition [MFC], m_pInterpolator
ms.assetid: 5bd3f492-940f-4290-a38b-fa68eb8f8401
ms.openlocfilehash: e0e5250b27ce6b902939ebcbfa03bf022a202788
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62391277"
---
# <a name="ccustomtransition-class"></a>Classe CCustomTransition

Implementa uma transição personalizada.

## <a name="syntax"></a>Sintaxe

```
class CCustomTransition : public CBaseTransition;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CCustomTransition::CCustomTransition](#ccustomtransition)|Constrói um objeto de transição personalizada.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CCustomTransition::Create](#create)|Chama a biblioteca de transição para criar o objeto encapsulado transição COM. (Substitui [CBaseTransition::Create](../../mfc/reference/cbasetransition-class.md#create).)|
|[CCustomTransition::SetInitialValue](#setinitialvalue)|Define um valor inicial, que será aplicado a uma variável de animação associada a essa transição.|
|[CCustomTransition::SetInitialVelocity](#setinitialvelocity)|Define uma velocidade inicial, que será aplicada a uma variável de animação associada a essa transição.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CCustomTransition::m_bInitialValueSpecified](#m_binitialvaluespecified)|Especifica se o valor inicial foi especificado com SetInitialValue.|
|[CCustomTransition::m_bInitialVelocitySpecified](#m_binitialvelocityspecified)|Especifica se a velocidade inicial foi especificada com SetInitialVelocity.|
|[CCustomTransition::m_initialValue](#m_initialvalue)|Armazena o valor inicial.|
|[CCustomTransition::m_initialVelocity](#m_initialvelocity)|Armazena a velocidade inicial.|
|[CCustomTransition::m_pInterpolator](#m_pinterpolator)|Armazena um ponteiro para um interpolador personalizado.|

## <a name="remarks"></a>Comentários

A classe CCustomTransitions permite aos desenvolvedores implementar transições personalizadas. Ele foi criado e usado como uma transição padrão, mas seu construtor aceita um ponteiro para um interpolador personalizado como parâmetro. Execute as seguintes etapas para usar transições personalizadas: 1. Derive uma classe de CCustomInterpolator e implementar pelo menos InterpolateValue método. 2. Certifique-se de que o tempo de vida do objeto personalizado do interpolador deve ser maior que a duração da animação onde ele é usado. 3. Criar uma instância (usando o operador new) um objeto CCustomTransition e passe um ponteiro para um interpolador personalizado no construtor. 4. Chame CCustomTransition::SetInitialValue e CCustomTransition::SetInitialVelocity se esses parâmetros são necessários para a interpolação personalizada. 5. Passe o ponteiro para fazer a transição personalizada ao método AddTransition do objeto de animação, cujo valor deve ser animado com o algoritmo personalizado. 6. Quando o valor do objeto de animação deve alterar o API de animação do Windows chamará InterpolateValue (e outros métodos relevantes) em CCustomInterpolator.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CBaseTransition](../../mfc/reference/cbasetransition-class.md)

`CCustomTransition`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

##  <a name="ccustomtransition"></a>  CCustomTransition::CCustomTransition

Constrói um objeto de transição personalizada.

```
CCustomTransition(CCustomInterpolator* pInterpolator);
```

### <a name="parameters"></a>Parâmetros

*pInterpolator*<br/>
Um ponteiro para um interpolador personalizado.

##  <a name="create"></a>  CCustomTransition::Create

Chama a biblioteca de transição para criar o objeto encapsulado transição COM.

```
virtual BOOL Create(
    IUIAnimationTransitionLibrary* */,
    IUIAnimationTransitionFactory* pFactory);
```

### <a name="parameters"></a>Parâmetros

*pFactory*<br/>
Um ponteiro para a fábrica de transição, que é responsável pela criação de transições personalizadas.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

Esse método também pode definir o valor inicial e a velocidade inicial a ser aplicado a uma variável de animação, que está associada essa transição. Para essa finalidade, você precisa chamar SetInitialValue e SetInitialVelocity antes que a estrutura cria objeto COM encapsulado transição (isso acontece quando você chamar CAnimationController::AnimateGroup).

##  <a name="m_binitialvaluespecified"></a>  CCustomTransition::m_bInitialValueSpecified

Especifica se o valor inicial foi especificado com SetInitialValue.

```
BOOL m_bInitialValueSpecified;
```

##  <a name="m_binitialvelocityspecified"></a>  CCustomTransition::m_bInitialVelocitySpecified

Especifica se a velocidade inicial foi especificada com SetInitialVelocity.

```
BOOL m_bInitialVelocitySpecified;
```

##  <a name="m_initialvalue"></a>  CCustomTransition::m_initialValue

Armazena o valor inicial.

```
DOUBLE m_initialValue;
```

##  <a name="m_initialvelocity"></a>  CCustomTransition::m_initialVelocity

Armazena a velocidade inicial.

```
DOUBLE m_initialVelocity;
```

##  <a name="m_pinterpolator"></a>  CCustomTransition::m_pInterpolator

Armazena um ponteiro para um interpolador personalizado.

```
CCustomInterpolator* m_pInterpolator;
```

##  <a name="setinitialvalue"></a>  CCustomTransition::SetInitialValue

Define um valor inicial, que será aplicado a uma variável de animação associada a essa transição.

```
void SetInitialValue(DOUBLE initialValue);
```

### <a name="parameters"></a>Parâmetros

*initialValue*

##  <a name="setinitialvelocity"></a>  CCustomTransition::SetInitialVelocity

Define uma velocidade inicial, que será aplicada a uma variável de animação associada a essa transição.

```
void SetInitialVelocity(DOUBLE initialVelocity);
```

### <a name="parameters"></a>Parâmetros

*initialVelocity*

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
