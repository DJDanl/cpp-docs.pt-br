---
title: Classe CSinusoidalTransitionFromRange
ms.date: 11/04/2016
f1_keywords:
- CSinusoidalTransitionFromRange
- AFXANIMATIONCONTROLLER/CSinusoidalTransitionFromRange
- AFXANIMATIONCONTROLLER/CSinusoidalTransitionFromRange::CSinusoidalTransitionFromRange
- AFXANIMATIONCONTROLLER/CSinusoidalTransitionFromRange::Create
- AFXANIMATIONCONTROLLER/CSinusoidalTransitionFromRange::m_dblMaximumValue
- AFXANIMATIONCONTROLLER/CSinusoidalTransitionFromRange::m_dblMinimumValue
- AFXANIMATIONCONTROLLER/CSinusoidalTransitionFromRange::m_duration
- AFXANIMATIONCONTROLLER/CSinusoidalTransitionFromRange::m_period
- AFXANIMATIONCONTROLLER/CSinusoidalTransitionFromRange::m_slope
helpviewer_keywords:
- CSinusoidalTransitionFromRange [MFC], CSinusoidalTransitionFromRange
- CSinusoidalTransitionFromRange [MFC], Create
- CSinusoidalTransitionFromRange [MFC], m_dblMaximumValue
- CSinusoidalTransitionFromRange [MFC], m_dblMinimumValue
- CSinusoidalTransitionFromRange [MFC], m_duration
- CSinusoidalTransitionFromRange [MFC], m_period
- CSinusoidalTransitionFromRange [MFC], m_slope
ms.assetid: 8b66a729-5f10-431a-b055-e3600d0065da
ms.openlocfilehash: 20e910dfa34e90af2c8a2765947ad85a2465c596
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50477578"
---
# <a name="csinusoidaltransitionfromrange-class"></a>Classe CSinusoidalTransitionFromRange

Encapsula uma transição de intervalo sinusoidal que tem um determinado intervalo de oscilação.

## <a name="syntax"></a>Sintaxe

```
class CSinusoidalTransitionFromRange : public CBaseTransition;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSinusoidalTransitionFromRange::CSinusoidalTransitionFromRange](#csinusoidaltransitionfromrange)|Constrói um objeto de transição.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSinusoidalTransitionFromRange::Create](#create)|Chama a biblioteca de transição para criar o objeto encapsulado transição COM. (Substitui [CBaseTransition::Create](../../mfc/reference/cbasetransition-class.md#create).)|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSinusoidalTransitionFromRange::m_dblMaximumValue](#m_dblmaximumvalue)|O valor da variável de animação em um horário de pico da sinusoidal onda.|
|[CSinusoidalTransitionFromRange::m_dblMinimumValue](#m_dblminimumvalue)|O valor da variável de animação em um trough da sinusoidal onda.|
|[CSinusoidalTransitionFromRange::m_duration](#m_duration)|A duração da transição.|
|[CSinusoidalTransitionFromRange::m_period](#m_period)|O período de oscilação da onda sinusoidal em segundos.|
|[CSinusoidalTransitionFromRange::m_slope](#m_slope)|A inclinação no início da transição.|

## <a name="remarks"></a>Comentários

O valor da variável de animação varia entre os valores mínimo e máximo especificados ao longo de todo o período de uma transição de intervalo sinusoidal com. O parâmetro do coeficiente é usado para resolver a ambiguidade entre as duas ondas senoidais possíveis especificadas pelos outros parâmetros. Como todas as transições são limpas automaticamente, é recomendável para alocado-los usando o operador novo. O objeto de IUIAnimationTransition COM encapsulado é criado pelo CAnimationController::AnimateGroup, até então é NULL. Alterando as variáveis de membro após a criação deste objeto COM não tem nenhum efeito.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CBaseTransition](../../mfc/reference/cbasetransition-class.md)

[CSinusoidalTransitionFromRange](../../mfc/reference/csinusoidaltransitionfromrange-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

##  <a name="create"></a>  CSinusoidalTransitionFromRange::Create

Chama a biblioteca de transição para criar o objeto encapsulado transição COM.

```
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,
    IUIAnimationTransitionFactory* \*not used*\);
```

### <a name="parameters"></a>Parâmetros

*pLibrary*<br/>
Um ponteiro para a biblioteca de transição, que é responsável pela criação de transições padrão.

### <a name="return-value"></a>Valor de retorno

TRUE se a transição é criada com êxito; Caso contrário, FALSE.

##  <a name="csinusoidaltransitionfromrange"></a>  CSinusoidalTransitionFromRange::CSinusoidalTransitionFromRange

Constrói um objeto de transição.

```
CSinusoidalTransitionFromRange(
    UI_ANIMATION_SECONDS duration,
    DOUBLE dblMinimumValue,
    DOUBLE dblMaximumValue,
    UI_ANIMATION_SECONDS period,
    UI_ANIMATION_SLOPE slope);
```

### <a name="parameters"></a>Parâmetros

*duração*<br/>
A duração da transição.

*dblMinimumValue*<br/>
O valor da variável de animação em um trough da sinusoidal onda.

*dblMaximumValue*<br/>
O valor da variável de animação em um horário de pico da sinusoidal onda.

*Período*<br/>
O período de oscilação da onda sinusoidal em segundos.

*inclinação*<br/>
A inclinação no início da transição.

##  <a name="m_dblmaximumvalue"></a>  CSinusoidalTransitionFromRange::m_dblMaximumValue

O valor da variável de animação em um horário de pico da sinusoidal onda.

```
DOUBLE m_dblMaximumValue;
```

##  <a name="m_dblminimumvalue"></a>  CSinusoidalTransitionFromRange::m_dblMinimumValue

O valor da variável de animação em um trough da sinusoidal onda.

```
DOUBLE m_dblMinimumValue;
```

##  <a name="m_duration"></a>  CSinusoidalTransitionFromRange::m_duration

A duração da transição.

```
UI_ANIMATION_SECONDS m_duration;
```

##  <a name="m_period"></a>  CSinusoidalTransitionFromRange::m_period

O período de oscilação da onda sinusoidal em segundos.

```
UI_ANIMATION_SECONDS m_period;
```

##  <a name="m_slope"></a>  CSinusoidalTransitionFromRange::m_slope

A inclinação no início da transição.

```
UI_ANIMATION_SLOPE m_slope;
```

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
