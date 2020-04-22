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
ms.openlocfilehash: 76e0d12308ad579e4bdf9866dfcf1cde231a2d0c
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81749157"
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
|[Transição ccustom::CCustomTransition](#ccustomtransition)|Constrói um objeto de transição personalizado.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CCustomTransition::Create](#create)|Chama a biblioteca de transição para criar um objeto COM de transição encapsulado. (Substitui [cbaseTransition::create](../../mfc/reference/cbasetransition-class.md#create).)|
|[CCustomTransition::SetInitialValue setInitial](#setinitialvalue)|Define um valor inicial, que será aplicado a uma variável de animação associada a essa transição.|
|[CCustomTransition::SetInitialVelocity](#setinitialvelocity)|Define uma velocidade inicial, que será aplicada a uma variável de animação associada a essa transição.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CCustomTransition::m_bInitialValueSpecified](#m_binitialvaluespecified)|Especifica se o valor inicial foi especificado com SetInitialValue.|
|[CCustomTransition::m_bInitialVelocitySpecified](#m_binitialvelocityspecified)|Especifica se a velocidade inicial foi especificada com SetInitialVelocity.|
|[CCustomTransition::m_initialValue](#m_initialvalue)|Armazena o valor inicial.|
|[CCustomTransition::m_initialVelocity](#m_initialvelocity)|Armazena a velocidade inicial.|
|[CCustomTransition::m_pInterpolator](#m_pinterpolator)|Armazena um ponteiro para um interpolador personalizado.|

## <a name="remarks"></a>Comentários

A classe CCustomTransitions permite que os desenvolvedores implementem transições personalizadas. É criado e usado como uma transição padrão, mas seu construtor aceita como parâmetro um ponteiro para um interpolador personalizado. Execute as seguintes etapas para usar transições personalizadas: 1. Obtenha uma classe do CCustomInterpolator e implemente pelo menos o método InterpolateValue. 2. Certifique-se de que a vida útil do objeto interpolador personalizado deve ser maior do que a duração da animação onde ele é usado. 3. Instanciar (usando o novo operador) um objeto CCustomTransition e passar um ponteiro para interpolador personalizado no construtor. 4. Chamada CCustomTransition::SetInitialValue e CCustomTransition:SetInitialVelocity se esses parâmetros forem necessários para interpolação personalizada. 5. Passe o ponteiro para a transição personalizada para o método AddTransition do objeto de animação, cujo valor deve ser animado com o algoritmo personalizado. 6. Quando o valor do objeto de animação deve alterar a API do Windows Animation chamará InterpolateValue (e outros métodos relevantes) no CCustomInterpolator.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Transição de Cbase](../../mfc/reference/cbasetransition-class.md)

`CCustomTransition`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="ccustomtransitionccustomtransition"></a><a name="ccustomtransition"></a>Transição ccustom::CCustomTransition

Constrói um objeto de transição personalizado.

```
CCustomTransition(CCustomInterpolator* pInterpolator);
```

### <a name="parameters"></a>Parâmetros

*pInterpolator*<br/>
Um ponteiro para interpolador personalizado.

## <a name="ccustomtransitioncreate"></a><a name="create"></a>CCustomTransition::Create

Chama a biblioteca de transição para criar um objeto COM de transição encapsulado.

```
virtual BOOL Create(
    IUIAnimationTransitionLibrary* */,
    IUIAnimationTransitionFactory* pFactory);
```

### <a name="parameters"></a>Parâmetros

*pFactory*<br/>
Um ponteiro para a fábrica de transição, que é responsável pela criação de transições personalizadas.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

Este método também pode definir o valor inicial e a velocidade inicial a ser aplicado a uma variável de animação, que está associada a essa transição. Para isso, você tem que chamar SetInitialValue e SetInitialVelocity antes que a estrutura crie o objeto COM de transição encapsulada (acontece quando você chama CAnimationController::AnimateGroup).

## <a name="ccustomtransitionm_binitialvaluespecified"></a><a name="m_binitialvaluespecified"></a>CCustomTransition::m_bInitialValueSpecified

Especifica se o valor inicial foi especificado com SetInitialValue.

```
BOOL m_bInitialValueSpecified;
```

## <a name="ccustomtransitionm_binitialvelocityspecified"></a><a name="m_binitialvelocityspecified"></a>CCustomTransition::m_bInitialVelocitySpecified

Especifica se a velocidade inicial foi especificada com SetInitialVelocity.

```
BOOL m_bInitialVelocitySpecified;
```

## <a name="ccustomtransitionm_initialvalue"></a><a name="m_initialvalue"></a>CCustomTransition::m_initialValue

Armazena o valor inicial.

```
DOUBLE m_initialValue;
```

## <a name="ccustomtransitionm_initialvelocity"></a><a name="m_initialvelocity"></a>CCustomTransition::m_initialVelocity

Armazena a velocidade inicial.

```
DOUBLE m_initialVelocity;
```

## <a name="ccustomtransitionm_pinterpolator"></a><a name="m_pinterpolator"></a>CCustomTransition::m_pInterpolator

Armazena um ponteiro para um interpolador personalizado.

```
CCustomInterpolator* m_pInterpolator;
```

## <a name="ccustomtransitionsetinitialvalue"></a><a name="setinitialvalue"></a>CCustomTransition::SetInitialValue setInitial

Define um valor inicial, que será aplicado a uma variável de animação associada a essa transição.

```cpp
void SetInitialValue(DOUBLE initialValue);
```

### <a name="parameters"></a>Parâmetros

*Initialvalue*

## <a name="ccustomtransitionsetinitialvelocity"></a><a name="setinitialvelocity"></a>CCustomTransition::SetInitialVelocity

Define uma velocidade inicial, que será aplicada a uma variável de animação associada a essa transição.

```cpp
void SetInitialVelocity(DOUBLE initialVelocity);
```

### <a name="parameters"></a>Parâmetros

*velocidade inicial*

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
