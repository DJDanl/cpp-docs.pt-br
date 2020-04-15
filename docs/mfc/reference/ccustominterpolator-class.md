---
title: Classe CCustomInterpolator
ms.date: 11/04/2016
f1_keywords:
- CCustomInterpolator
- AFXANIMATIONCONTROLLER/CCustomInterpolator
- AFXANIMATIONCONTROLLER/CCustomInterpolator::CCustomInterpolator
- AFXANIMATIONCONTROLLER/CCustomInterpolator::GetDependencies
- AFXANIMATIONCONTROLLER/CCustomInterpolator::GetDuration
- AFXANIMATIONCONTROLLER/CCustomInterpolator::GetFinalValue
- AFXANIMATIONCONTROLLER/CCustomInterpolator::Init
- AFXANIMATIONCONTROLLER/CCustomInterpolator::InterpolateValue
- AFXANIMATIONCONTROLLER/CCustomInterpolator::InterpolateVelocity
- AFXANIMATIONCONTROLLER/CCustomInterpolator::SetDuration
- AFXANIMATIONCONTROLLER/CCustomInterpolator::SetInitialValueAndVelocity
- AFXANIMATIONCONTROLLER/CCustomInterpolator::m_currentValue
- AFXANIMATIONCONTROLLER/CCustomInterpolator::m_currentVelocity
- AFXANIMATIONCONTROLLER/CCustomInterpolator::m_duration
- AFXANIMATIONCONTROLLER/CCustomInterpolator::m_finalValue
- AFXANIMATIONCONTROLLER/CCustomInterpolator::m_initialValue
- AFXANIMATIONCONTROLLER/CCustomInterpolator::m_initialVelocity
helpviewer_keywords:
- CCustomInterpolator [MFC], CCustomInterpolator
- CCustomInterpolator [MFC], GetDependencies
- CCustomInterpolator [MFC], GetDuration
- CCustomInterpolator [MFC], GetFinalValue
- CCustomInterpolator [MFC], Init
- CCustomInterpolator [MFC], InterpolateValue
- CCustomInterpolator [MFC], InterpolateVelocity
- CCustomInterpolator [MFC], SetDuration
- CCustomInterpolator [MFC], SetInitialValueAndVelocity
- CCustomInterpolator [MFC], m_currentValue
- CCustomInterpolator [MFC], m_currentVelocity
- CCustomInterpolator [MFC], m_duration
- CCustomInterpolator [MFC], m_finalValue
- CCustomInterpolator [MFC], m_initialValue
- CCustomInterpolator [MFC], m_initialVelocity
ms.assetid: 28d85595-989a-40a3-b003-e0e38437a94d
ms.openlocfilehash: 2342432c7651fc1bd1eda23b3e56fa9306eadf09
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81359262"
---
# <a name="ccustominterpolator-class"></a>Classe CCustomInterpolator

Implementa um interpolador básico.

## <a name="syntax"></a>Sintaxe

```
class CCustomInterpolator;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CCustomInterpolator::CCustomInterpolator](#ccustominterpolator)|Sobrecarregado. Constrói um objeto interpolador personalizado e inicializa a duração e a velocidade aos valores especificados.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CCustomInterpolator::GetDependencies](#getdependencies)|Fica com as dependências do interpolador.|
|[CCustomInterpolator::GetDuration](#getduration)|Fica com a duração do interpolador.|
|[CCustomInterpolator::GetFinalValue](#getfinalvalue)|Obtém o valor final para o qual o interpolador leva.|
|[CCustomInterpolator::Init](#init)|Inicializa a duração e o valor final.|
|[CCustomInterpolator::InterpolateValue](#interpolatevalue)|Interpola o valor em um determinado deslocamento.|
|[CCustomInterpolator::InterpolateVelocity](#interpolatevelocity)|Interpola a velocidade em um dado deslocamento|
|[CCustomInterpolator::SetDuração](#setduration)|Define a duração do interpolador.|
|[CCustomInterpolator::SetInitialValueAndVelocity](#setinitialvalueandvelocity)|Define o valor inicial e a velocidade do interpolador.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CCustomInterpolator::m_currentValue](#m_currentvalue)|O valor interpolado.|
|[CCustomInterpolator::m_currentVelocity](#m_currentvelocity)|A velocidade interpolada.|
|[CCustomInterpolator::m_duration](#m_duration)|A duração da transição.|
|[CCustomInterpolator::m_finalValue](#m_finalvalue)|O valor final de uma variável no final da transição.|
|[CCustomInterpolator::m_initialValue](#m_initialvalue)|O valor da variável no início da transição.|
|[CCustomInterpolator::m_initialVelocity](#m_initialvelocity)|A velocidade da variável no início da transição.|

## <a name="remarks"></a>Comentários

Obtenha uma classe do CCustomInterpolator e anule todos os métodos necessários para implementar um algoritmo de interpolação personalizado. Um ponteiro para esta classe deve ser passado como um parâmetro para CCustomTransition.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CCustomInterpolator`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="ccustominterpolatorccustominterpolator"></a><a name="ccustominterpolator"></a>CCustomInterpolator::CCustomInterpolator

Constrói um objeto interpolador personalizado e define todos os valores como 0 padrão.

```
CCustomInterpolator();

CCustomInterpolator(
    UI_ANIMATION_SECONDS duration,
    DOUBLE finalValue);
```

### <a name="parameters"></a>Parâmetros

*Duração*<br/>
A duração da transição.

*finalValue*

### <a name="remarks"></a>Comentários

Use CCustomInterpolator::Init para inicializar a duração e o valor final mais tarde no código.

## <a name="ccustominterpolatorgetdependencies"></a><a name="getdependencies"></a>CCustomInterpolator::GetDependencies

Fica com as dependências do interpolador.

```
virtual BOOL GetDependencies(
    UI_ANIMATION_DEPENDENCIES* initialValueDependencies,
    UI_ANIMATION_DEPENDENCIES* initialVelocityDependencies,
    UI_ANIMATION_DEPENDENCIES* durationDependencies);
```

### <a name="parameters"></a>Parâmetros

*initialValueDependencies*<br/>
Saída. Aspectos do interpolador que dependem do valor inicial passado para SetInitialValueAndVelocity.

*dependencies iniciaisVelocity*<br/>
Saída. Aspectos do interpolador que dependem da velocidade inicial passados para SetInitialValueAndVelocity.

*durationDependencies*<br/>
Saída. Aspectos do interpolador que dependem da duração passada para SetDuration.

### <a name="return-value"></a>Valor retornado

A implementação básica sempre retorna TRUE. Devolva FALSO da implementação substituída se desejar falhar no evento.

## <a name="ccustominterpolatorgetduration"></a><a name="getduration"></a>CCustomInterpolator::GetDuration

Fica com a duração do interpolador.

```
virtual BOOL GetDuration(UI_ANIMATION_SECONDS* duration);
```

### <a name="parameters"></a>Parâmetros

*Duração*<br/>
Saída. A duração da transição, em segundos.

### <a name="return-value"></a>Valor retornado

A implementação básica sempre retorna TRUE. Devolva FALSO da implementação substituída se desejar falhar no evento.

## <a name="ccustominterpolatorgetfinalvalue"></a><a name="getfinalvalue"></a>CCustomInterpolator::GetFinalValue

Obtém o valor final para o qual o interpolador leva.

```
virtual BOOL GetFinalValue(DOUBLE* value);
```

### <a name="parameters"></a>Parâmetros

*value*<br/>
Saída. O valor final de uma variável no final da transição.

### <a name="return-value"></a>Valor retornado

A implementação básica sempre retorna TRUE. Devolva FALSO da implementação substituída se desejar falhar no evento.

## <a name="ccustominterpolatorinit"></a><a name="init"></a>CCustomInterpolator::Init

Inicializa a duração e o valor final.

```
void Init(
    UI_ANIMATION_SECONDS duration,
    DOUBLE finalValue);
```

### <a name="parameters"></a>Parâmetros

*Duração*<br/>
A duração da transição.

*finalValue*<br/>
O valor final de uma variável no final da transição.

## <a name="ccustominterpolatorinterpolatevalue"></a><a name="interpolatevalue"></a>CCustomInterpolator::InterpolateValue

Interpola o valor em um determinado deslocamento.

```
virtual BOOL InterpolateValue(
    UI_ANIMATION_SECONDS */,
    DOUBLE* value);
```

### <a name="parameters"></a>Parâmetros

*value*<br/>
Saída. O valor interpolado.

### <a name="return-value"></a>Valor retornado

A implementação básica sempre retorna TRUE. Devolva FALSO da implementação substituída se desejar falhar no evento.

## <a name="ccustominterpolatorinterpolatevelocity"></a><a name="interpolatevelocity"></a>CCustomInterpolator::InterpolateVelocity

Interpola a velocidade em um dado deslocamento

```
virtual BOOL InterpolateVelocity(
    UI_ANIMATION_SECONDS */,
    DOUBLE* velocity);
```

### <a name="parameters"></a>Parâmetros

*velocity*<br/>
Saída. A velocidade da variável no deslocamento.

### <a name="return-value"></a>Valor retornado

A implementação básica sempre retorna TRUE. Devolva FALSO da implementação substituída se desejar falhar no evento.

## <a name="ccustominterpolatorm_currentvalue"></a><a name="m_currentvalue"></a>CCustomInterpolator::m_currentValue

O valor interpolado.

```
DOUBLE m_currentValue;
```

## <a name="ccustominterpolatorm_currentvelocity"></a><a name="m_currentvelocity"></a>CCustomInterpolator::m_currentVelocity

A velocidade interpolada.

```
DOUBLE m_currentVelocity;
```

## <a name="ccustominterpolatorm_duration"></a><a name="m_duration"></a>CCustomInterpolator::m_duration

A duração da transição.

```
UI_ANIMATION_SECONDS m_duration;
```

## <a name="ccustominterpolatorm_finalvalue"></a><a name="m_finalvalue"></a>CCustomInterpolator::m_finalValue

O valor final de uma variável no final da transição.

```
DOUBLE m_finalValue;
```

## <a name="ccustominterpolatorm_initialvalue"></a><a name="m_initialvalue"></a>CCustomInterpolator::m_initialValue

O valor da variável no início da transição.

```
DOUBLE m_initialValue;
```

## <a name="ccustominterpolatorm_initialvelocity"></a><a name="m_initialvelocity"></a>CCustomInterpolator::m_initialVelocity

A velocidade da variável no início da transição.

```
DOUBLE m_initialVelocity;
```

## <a name="ccustominterpolatorsetduration"></a><a name="setduration"></a>CCustomInterpolator::SetDuração

Define a duração do interpolador.

```
virtual BOOL SetDuration(UI_ANIMATION_SECONDS duration);
```

### <a name="parameters"></a>Parâmetros

*Duração*<br/>
A duração da transição.

### <a name="return-value"></a>Valor retornado

A implementação básica sempre retorna TRUE. Devolva FALSO da implementação substituída se desejar falhar no evento.

## <a name="ccustominterpolatorsetinitialvalueandvelocity"></a><a name="setinitialvalueandvelocity"></a>CCustomInterpolator::SetInitialValueAndVelocity

Define o valor inicial e a velocidade do interpolador.

```
virtual BOOL SetInitialValueAndVelocity(
    DOUBLE initialValue,
    DOUBLE initialVelocity);
```

### <a name="parameters"></a>Parâmetros

*Initialvalue*<br/>
O valor da variável no início da transição.

*velocidade inicial*<br/>
A velocidade da variável no início da transição.

### <a name="return-value"></a>Valor retornado

A implementação básica sempre retorna TRUE. Devolva FALSO da implementação substituída se desejar falhar no evento.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
