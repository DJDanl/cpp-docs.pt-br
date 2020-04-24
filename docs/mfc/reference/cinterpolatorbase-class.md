---
title: Classe CInterpolatorBase
ms.date: 11/04/2016
f1_keywords:
- CInterpolatorBase
- AFXANIMATIONCONTROLLER/CInterpolatorBase
- AFXANIMATIONCONTROLLER/CInterpolatorBase::CInterpolatorBase
- AFXANIMATIONCONTROLLER/CInterpolatorBase::CreateInstance
- AFXANIMATIONCONTROLLER/CInterpolatorBase::GetDependencies
- AFXANIMATIONCONTROLLER/CInterpolatorBase::GetDuration
- AFXANIMATIONCONTROLLER/CInterpolatorBase::GetFinalValue
- AFXANIMATIONCONTROLLER/CInterpolatorBase::InterpolateValue
- AFXANIMATIONCONTROLLER/CInterpolatorBase::InterpolateVelocity
- AFXANIMATIONCONTROLLER/CInterpolatorBase::SetCustomInterpolator
- AFXANIMATIONCONTROLLER/CInterpolatorBase::SetDuration
- AFXANIMATIONCONTROLLER/CInterpolatorBase::SetInitialValueAndVelocity
helpviewer_keywords:
- CInterpolatorBase [MFC], CInterpolatorBase
- CInterpolatorBase [MFC], CreateInstance
- CInterpolatorBase [MFC], GetDependencies
- CInterpolatorBase [MFC], GetDuration
- CInterpolatorBase [MFC], GetFinalValue
- CInterpolatorBase [MFC], InterpolateValue
- CInterpolatorBase [MFC], InterpolateVelocity
- CInterpolatorBase [MFC], SetCustomInterpolator
- CInterpolatorBase [MFC], SetDuration
- CInterpolatorBase [MFC], SetInitialValueAndVelocity
ms.assetid: bbc3dce7-8398-47f9-b97e-e4fd2d737232
ms.openlocfilehash: efa08aa5dd556d7e136323c31451a9f33bd72ec6
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754951"
---
# <a name="cinterpolatorbase-class"></a>Classe CInterpolatorBase

Implementa um retorno de chamada, que é chamado pela API de animação quando ele tem que calcular um novo valor de uma variável de animação.

## <a name="syntax"></a>Sintaxe

```
class CInterpolatorBase : public CUIAnimationInterpolatorBase<CInterpolatorBase>;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CInterpolatorBase::CInterpolatorBase](#cinterpolatorbase)|Constrói o `CInterpolatorBase` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CInterpolatorBase::CreateInstance](#createinstance)|Cria uma `CInterpolatorBase` instância e armazena um ponteiro para interpolador personalizado, que estará lidando com eventos.|
|[CInterpolatorBase::GetDependencies](#getdependencies)|Fica com as dependências do interpolador. (Substitui `CUIAnimationInterpolatorBase::GetDependencies`.)|
|[CInterpolatorBase::GetDuration](#getduration)|Fica com a duração do interpolador. (Substitui `CUIAnimationInterpolatorBase::GetDuration`.)|
|[CInterpolatorBase::GetFinalValue](#getfinalvalue)|Obtém o valor final para o qual o interpolador leva. (Substitui `CUIAnimationInterpolatorBase::GetFinalValue`.)|
|[CInterpolatorBase::InterpolateValue](#interpolatevalue)|Interpola o valor em uma determinada `CUIAnimationInterpolatorBase::InterpolateValue`compensação (Overrides .)|
|[CInterpolatorBase::InterpolateVelocity](#interpolatevelocity)|Interpola a velocidade em um determinado `CUIAnimationInterpolatorBase::InterpolateVelocity`deslocamento (Overrides .)|
|[CInterpolatorBase::SetCustomInterpolator](#setcustominterpolator)|Armazena um ponteiro para interpolador personalizado, que estará lidando com eventos.|
|[CInterpolatorBase::SetDuração](#setduration)|Define a duração do interpolador (Overrides `CUIAnimationInterpolatorBase::SetDuration`.)|
|[CInterpolatorBase::SetInitialValueAndVelocity](#setinitialvalueandvelocity)|Define o valor inicial e a velocidade do interpolador. (Substitui `CUIAnimationInterpolatorBase::SetInitialValueAndVelocity`.)|

## <a name="remarks"></a>Comentários

Este manipulador é criado `IUIAnimationTransitionFactory::CreateTransition` e `CCustomTransition` passado para quando um objeto está sendo criado `CAnimationController::AnimateGroup`como parte do processo de inicialização de animação (iniciado por ). Normalmente você não precisa usar esta classe diretamente, ele apenas `CCustomInterpolator`routs todos os eventos para `CCustomTransition`uma classe derivada, cujo ponteiro é passado para construtor de .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CUIAnimationCallbackBase`

`CUIAnimationInterpolatorBase`

`CInterpolatorBase`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="cinterpolatorbasecinterpolatorbase"></a><a name="cinterpolatorbase"></a>CInterpolatorBase::CInterpolatorBase

Constrói o objeto CInterpolatorBase.

```
CInterpolatorBase();
```

## <a name="cinterpolatorbasecreateinstance"></a><a name="createinstance"></a>CInterpolatorBase::CreateInstance

Cria uma instância do CInterpolatorBase e armazena um ponteiro para interpolador personalizado, que estará lidando com eventos.

```
static COM_DECLSPEC_NOTHROW HRESULT CreateInstance(
    CCustomInterpolator* pInterpolator,
    IUIAnimationInterpolator** ppHandler);
```

### <a name="parameters"></a>Parâmetros

*pInterpolator*<br/>
Um ponteiro para interpolador personalizado.

*ppHandler*<br/>
Saída. Contém um ponteiro para a ocorrência de CInterpolatorBase quando a função retorna.

### <a name="return-value"></a>Valor retornado

## <a name="cinterpolatorbasegetdependencies"></a><a name="getdependencies"></a>CInterpolatorBase::GetDependencies

Fica com as dependências do interpolador.

```
IFACEMETHOD(GetDependencies)(
    __out UI_ANIMATION_DEPENDENCIES* initialValueDependencies,
    __out UI_ANIMATION_DEPENDENCIES* initialVelocityDependencies,
    __out UI_ANIMATION_DEPENDENCIES* durationDependencies);
```

### <a name="parameters"></a>Parâmetros

*initialValueDependencies*<br/>
Saída. Aspectos do interpolador que dependem do valor inicial passado para SetInitialValueAndVelocity.

*dependencies iniciaisVelocity*<br/>
Saída. Aspectos do interpolador que dependem da velocidade inicial passados para SetInitialValueAndVelocity.

*durationDependencies*<br/>
Saída. Aspectos do interpolador que dependem da duração passada para SetDuration.

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Ele retorna E_FAIL se o CCustomInterpolator não estiver definido ou a implementação personalizada retornar FALSA do método GetDependencies.

## <a name="cinterpolatorbasegetduration"></a><a name="getduration"></a>CInterpolatorBase::GetDuration

Fica com a duração do interpolador.

```
IFACEMETHOD(GetDuration)(__out UI_ANIMATION_SECONDS* duration);
```

### <a name="parameters"></a>Parâmetros

*duration*<br/>
Saída. A duração da transição, em segundos.

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Ele retorna E_FAIL se o CCustomInterpolator não estiver definido ou a implementação personalizada retornar FALSA do método GetDuration.

## <a name="cinterpolatorbasegetfinalvalue"></a><a name="getfinalvalue"></a>CInterpolatorBase::GetFinalValue

Obtém o valor final para o qual o interpolador leva.

```
IFACEMETHOD(GetFinalValue)(__out DOUBLE* value);
```

### <a name="parameters"></a>Parâmetros

*value*<br/>
Saída. O valor final de uma variável no final da transição.

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Ele retorna E_FAIL se o CCustomInterpolator não estiver definido ou a implementação personalizada retornar FALSA do método GetFinalValue.

## <a name="cinterpolatorbaseinterpolatevalue"></a><a name="interpolatevalue"></a>CInterpolatorBase::InterpolateValue

Interpola o valor em uma determinada compensação

```
IFACEMETHOD(InterpolateValue)(
    __in UI_ANIMATION_SECONDS offset,
    __out DOUBLE* value);
```

### <a name="parameters"></a>Parâmetros

*deslocamento*<br/>
O deslocamento desde o início da transição. O deslocamento é sempre maior ou igual a zero e menor do que a duração da transição. Este método não é chamado se a duração da transição for zero.

*value*<br/>
Saída. O valor interpolado.

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Ele retorna E_FAIL se o CCustomInterpolator não estiver definido ou a implementação personalizada retornar FALSA do método InterpolateValue.

## <a name="cinterpolatorbaseinterpolatevelocity"></a><a name="interpolatevelocity"></a>CInterpolatorBase::InterpolateVelocity

Interpola a velocidade em um dado deslocamento

```
IFACEMETHOD(InterpolateVelocity)(
    __in UI_ANIMATION_SECONDS offset,
    __out DOUBLE* velocity);
```

### <a name="parameters"></a>Parâmetros

*deslocamento*<br/>
O deslocamento desde o início da transição. O deslocamento é sempre maior ou igual a zero e menor ou igual à duração da transição. Este método não é chamado se a duração da transição for zero.

*velocity*<br/>
Saída. A velocidade da variável no deslocamento.

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Ele retorna E_FAIL se o CCustomInterpolator não estiver definido ou a implementação personalizada retornar FALSA do método InterpolateVelocity.

## <a name="cinterpolatorbasesetcustominterpolator"></a><a name="setcustominterpolator"></a>CInterpolatorBase::SetCustomInterpolator

Armazena um ponteiro para interpolador personalizado, que estará lidando com eventos.

```cpp
void SetCustomInterpolator(CCustomInterpolator* pInterpolator);
```

### <a name="parameters"></a>Parâmetros

*pInterpolator*<br/>
Um ponteiro para interpolador personalizado.

## <a name="cinterpolatorbasesetduration"></a><a name="setduration"></a>CInterpolatorBase::SetDuração

Define a duração do interpolador

```
IFACEMETHOD(SetDuration)(__in UI_ANIMATION_SECONDS duration);
```

### <a name="parameters"></a>Parâmetros

*duration*<br/>
A duração da transição.

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Ele retorna E_FAIL se o CCustomInterpolator não estiver definido ou a implementação personalizada retornar FALSA do método SetDuration.

## <a name="cinterpolatorbasesetinitialvalueandvelocity"></a><a name="setinitialvalueandvelocity"></a>CInterpolatorBase::SetInitialValueAndVelocity

Define o valor inicial e a velocidade do interpolador.

```
IFACEMETHOD(SetInitialValueAndVelocity)(
    __in DOUBLE initialValue,
    __in DOUBLE initialVelocity);
```

### <a name="parameters"></a>Parâmetros

*Initialvalue*<br/>
O valor da variável no início da transição.

*velocidade inicial*<br/>
A velocidade da variável no início da transição.

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Ele retorna E_FAIL se o CCustomInterpolator não estiver definido ou a implementação personalizada retornar FALSA do método SetInitialValueAndVelocity.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
