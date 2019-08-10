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
ms.openlocfilehash: d1fc675b1014ab9a099e8310b52b7458f2bff65f
ms.sourcegitcommit: 46d24d6e70c03e05484923d9efc6ed5150e96a64
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2019
ms.locfileid: "68916209"
---
# <a name="cinterpolatorbase-class"></a>Classe CInterpolatorBase

Implementa um retorno de chamada, que é chamado pela API de animação quando ele precisa calcular um novo valor de uma variável de animação.

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
|[CInterpolatorBase:: CreateInstance](#createinstance)|Cria uma instância do `CInterpolatorBase` e armazena um ponteiro para o interpolador personalizado, que tratará os eventos.|
|[CInterpolatorBase:: GetDependencies](#getdependencies)|Obtém as dependências do interpolador. (Substitui `CUIAnimationInterpolatorBase::GetDependencies`.)|
|[CInterpolatorBase::GetDuration](#getduration)|Obtém a duração do interpolador. (Substitui `CUIAnimationInterpolatorBase::GetDuration`.)|
|[CInterpolatorBase:: getfinalizevalue](#getfinalvalue)|Obtém o valor final para o qual o interpolador leva. (Substitui `CUIAnimationInterpolatorBase::GetFinalValue`.)|
|[CInterpolatorBase::InterpolateValue](#interpolatevalue)|Interpola o valor em um determinado deslocamento (Substitui `CUIAnimationInterpolatorBase::InterpolateValue`.)|
|[CInterpolatorBase::InterpolateVelocity](#interpolatevelocity)|Interpola a velocidade em um deslocamento específico (Substitui `CUIAnimationInterpolatorBase::InterpolateVelocity`.)|
|[CInterpolatorBase::SetCustomInterpolator](#setcustominterpolator)|Armazena um ponteiro para o interpolador personalizado, que tratará os eventos.|
|[CInterpolatorBase::SetDuration](#setduration)|Define a duração do interpolador (Substitui `CUIAnimationInterpolatorBase::SetDuration`.)|
|[CInterpolatorBase::SetInitialValueAndVelocity](#setinitialvalueandvelocity)|Define o valor inicial e a velocidade do interpolador. (Substitui `CUIAnimationInterpolatorBase::SetInitialValueAndVelocity`.)|

## <a name="remarks"></a>Comentários

Esse manipulador é criado e passado para `IUIAnimationTransitionFactory::CreateTransition` quando um `CCustomTransition` objeto está sendo criado como parte do processo de inicialização da animação (iniciado `CAnimationController::AnimateGroup`por). Normalmente, você não precisa usar essa classe diretamente, ela apenas encaminha todos os eventos para `CCustomInterpolator`uma classe derivada, cujo ponteiro é passado para o construtor `CCustomTransition`de.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CUIAnimationCallbackBase`

`CUIAnimationInterpolatorBase`

`CInterpolatorBase`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller. h

##  <a name="cinterpolatorbase"></a>CInterpolatorBase::CInterpolatorBase

Constrói o objeto CInterpolatorBase.

```
CInterpolatorBase();
```

##  <a name="createinstance"></a>CInterpolatorBase:: CreateInstance

Cria uma instância de CInterpolatorBase e armazena um ponteiro para o interpolador personalizado, que tratará os eventos.

```
static COM_DECLSPEC_NOTHROW HRESULT CreateInstance(
    CCustomInterpolator* pInterpolator,
    IUIAnimationInterpolator** ppHandler);
```

### <a name="parameters"></a>Parâmetros

*pInterpolator*<br/>
Um ponteiro para o interpolador personalizado.

*ppHandler*<br/>
Der. Contém um ponteiro para a instância de CInterpolatorBase quando a função retorna.

### <a name="return-value"></a>Valor de retorno

##  <a name="getdependencies"></a>CInterpolatorBase:: GetDependencies

Obtém as dependências do interpolador.

```
IFACEMETHOD(GetDependencies)(
    __out UI_ANIMATION_DEPENDENCIES* initialValueDependencies,
    __out UI_ANIMATION_DEPENDENCIES* initialVelocityDependencies,
    __out UI_ANIMATION_DEPENDENCIES* durationDependencies);
```

### <a name="parameters"></a>Parâmetros

*initialValueDependencies*<br/>
Der. Aspectos do interpolador que dependem do valor inicial passado para SetInitialValueAndVelocity.

*initialVelocityDependencies*<br/>
Der. Aspectos do interpolador que dependem da velocidade inicial passada para SetInitialValueAndVelocity.

*durationDependencies*<br/>
Der. Aspectos do interpolador que dependem da duração passada para setduration.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, retornará S_OK. Retorna E_FAIL se CCustomInterpolator não estiver definido ou se a implementação personalizada retornar FALSE do método GetDependencies.

##  <a name="getduration"></a>CInterpolatorBase:: getDuration

Obtém a duração do interpolador.

```
IFACEMETHOD(GetDuration)(__out UI_ANIMATION_SECONDS* duration);
```

### <a name="parameters"></a>Parâmetros

*permanência*<br/>
Der. A duração da transição, em segundos.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, retornará S_OK. Retorna E_FAIL se CCustomInterpolator não estiver definido ou se a implementação personalizada retornar FALSE do método GetDuration.

##  <a name="getfinalvalue"></a>  CInterpolatorBase::GetFinalValue

Obtém o valor final para o qual o interpolador leva.

```
IFACEMETHOD(GetFinalValue)(__out DOUBLE* value);
```

### <a name="parameters"></a>Parâmetros

*value*<br/>
Der. O valor final de uma variável no final da transição.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, retornará S_OK. Retorna E_FAIL se CCustomInterpolator não estiver definido ou se a implementação personalizada retornar FALSE do método getfinalizevalue.

##  <a name="interpolatevalue"></a>CInterpolatorBase::InterpolateValue

Interpola o valor em um determinado deslocamento

```
IFACEMETHOD(InterpolateValue)(
    __in UI_ANIMATION_SECONDS offset,
    __out DOUBLE* value);
```

### <a name="parameters"></a>Parâmetros

*deslocamento*<br/>
O deslocamento do início da transição. O deslocamento é sempre maior ou igual a zero e menor que a duração da transição. Esse método não será chamado se a duração da transição for zero.

*value*<br/>
Der. O valor interpolado.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, retornará S_OK. Retorna E_FAIL se CCustomInterpolator não estiver definido ou se a implementação personalizada retornar FALSE do método InterpolateValue.

##  <a name="interpolatevelocity"></a>CInterpolatorBase::InterpolateVelocity

Interpola a velocidade em um determinado deslocamento

```
IFACEMETHOD(InterpolateVelocity)(
    __in UI_ANIMATION_SECONDS offset,
    __out DOUBLE* velocity);
```

### <a name="parameters"></a>Parâmetros

*deslocamento*<br/>
O deslocamento do início da transição. O deslocamento é sempre maior ou igual a zero e menor ou igual à duração da transição. Esse método não será chamado se a duração da transição for zero.

*velocidade*<br/>
Der. A velocidade da variável no deslocamento.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, retornará S_OK. Retorna E_FAIL se CCustomInterpolator não estiver definido ou se a implementação personalizada retornar FALSE do método InterpolateVelocity.

##  <a name="setcustominterpolator"></a>CInterpolatorBase::SetCustomInterpolator

Armazena um ponteiro para o interpolador personalizado, que tratará os eventos.

```
void SetCustomInterpolator(CCustomInterpolator* pInterpolator);
```

### <a name="parameters"></a>Parâmetros

*pInterpolator*<br/>
Um ponteiro para o interpolador personalizado.

##  <a name="setduration"></a>CInterpolatorBase:: setduration

Define a duração do interpolador

```
IFACEMETHOD(SetDuration)(__in UI_ANIMATION_SECONDS duration);
```

### <a name="parameters"></a>Parâmetros

*permanência*<br/>
A duração da transição.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, retornará S_OK. Retorna E_FAIL se CCustomInterpolator não estiver definido ou se a implementação personalizada retornar FALSE do método setduration.

##  <a name="setinitialvalueandvelocity"></a>CInterpolatorBase::SetInitialValueAndVelocity

Define o valor inicial e a velocidade do interpolador.

```
IFACEMETHOD(SetInitialValueAndVelocity)(
    __in DOUBLE initialValue,
    __in DOUBLE initialVelocity);
```

### <a name="parameters"></a>Parâmetros

*inicialvalue*<br/>
O valor da variável no início da transição.

*initialVelocity*<br/>
A velocidade da variável no início da transição.

### <a name="return-value"></a>Valor de retorno

Se o método tiver sucesso, retornará S_OK. Retorna E_FAIL se CCustomInterpolator não estiver definido ou se a implementação personalizada retornar FALSE do método SetInitialValueAndVelocity.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
