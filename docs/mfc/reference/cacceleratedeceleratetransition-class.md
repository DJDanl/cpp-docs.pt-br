---
title: Classe CAccelerateDecelerateTransition
ms.date: 11/04/2016
f1_keywords:
- CAccelerateDecelerateTransition
- afxanimationcontroller/CAccelerateDecelerateTransition
helpviewer_keywords:
- CAccelerateDecelerateTransition class [MFC]
ms.assetid: b1f31ee8-bb11-4ccc-b124-365fb02b025c
ms.openlocfilehash: f37670d6e965cb034b81a6fb9ec8cc252bd5ee31
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50614689"
---
# <a name="cacceleratedeceleratetransition-class"></a>Classe CAccelerateDecelerateTransition

Implementa um accelerate-desacelerar a transição.

## <a name="syntax"></a>Sintaxe

```
class CAccelerateDecelerateTransition : public CBaseTransition;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAccelerateDecelerateTransition::CAccelerateDecelerateTransition](#cacceleratedeceleratetransition)|Constrói um objeto de transição.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAccelerateDecelerateTransition::Create](#create)|Chama a biblioteca de transição para criar o objeto encapsulado transição COM. (Substitui [CBaseTransition::Create](../../mfc/reference/cbasetransition-class.md#create).)|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAccelerateDecelerateTransition::m_accelerationRatio](#m_accelerationratio)|A proporção de tempo gasto que acelera à duração.|
|[CAccelerateDecelerateTransition::m_decelerationRatio](#m_decelerationratio)|A proporção de tempo gasto que desacelera à duração.|
|[CAccelerateDecelerateTransition::m_duration](#m_duration)|A duração da transição.|
|[CAccelerateDecelerateTransition::m_finalValue](#m_finalvalue)|O valor da variável de animação no final da transição.|

## <a name="remarks"></a>Comentários

Durante um accelerate-desacelerar a transição, a variável de animação acelera e reduz a velocidade ao longo da duração da transição, terminando em um valor especificado. Você pode controlar o quão rapidamente a variável acelera e desacelerada independentemente, com a especificação de aceleração diferente e taxas de desaceleração. Quando a velocidade inicial for zero, a taxa de aceleração é a fração da duração da variável será gasto acelerando; da mesma forma com a taxa de desaceleração. Se a velocidade inicial for diferente de zero, é a fração do tempo entre a velocidade chegar a zero e o final da transição. A taxa de aceleração e a taxa de desaceleração devem somar um máximo de 1.0. Como todas as transições são limpas automaticamente, é recomendável para alocado-los usando o operador novo. O objeto de IUIAnimationTransition COM encapsulado é criado pelo CAnimationController::AnimateGroup, até então é NULL. Alterando as variáveis de membro após a criação deste objeto COM não tem nenhum efeito.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CBaseTransition](../../mfc/reference/cbasetransition-class.md)

`CAccelerateDecelerateTransition`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

##  <a name="cacceleratedeceleratetransition"></a>  CAccelerateDecelerateTransition::CAccelerateDecelerateTransition

Constrói um objeto de transição.

```
CAccelerateDecelerateTransition(
    UI_ANIMATION_SECONDS duration,
    DOUBLE finalValue,
    DOUBLE accelerationRatio = 0.3,
    DOUBLE decelerationRatio = 0.3);
```

### <a name="parameters"></a>Parâmetros

*duração*<br/>
A duração da transição.

*finalValue*<br/>
O valor da variável de animação no final da transição.

*accelerationRatio*<br/>
A proporção de tempo gasto que acelera à duração.

*decelerationRatio*<br/>
A proporção de tempo gasto que desacelera à duração.

##  <a name="create"></a>  CAccelerateDecelerateTransition::Create

Chama a biblioteca de transição para criar o objeto encapsulado transição COM.

```
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,
    IUIAnimationTransitionFactory* *\not used*\);
```

### <a name="parameters"></a>Parâmetros

*pLibrary*<br/>
Um ponteiro para um [IUIAnimationTransitionLibrary interface](/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary), que define uma biblioteca de transições padrão.

### <a name="return-value"></a>Valor de retorno

TRUE se a transição é criada com êxito; Caso contrário, FALSE.

##  <a name="m_accelerationratio"></a>  CAccelerateDecelerateTransition::m_accelerationRatio

A proporção de tempo gasto que acelera à duração.

```
DOUBLE m_accelerationRatio;
```

##  <a name="m_decelerationratio"></a>  CAccelerateDecelerateTransition::m_decelerationRatio

A proporção de tempo gasto que desacelera à duração.

```
DOUBLE m_decelerationRatio;
```

##  <a name="m_duration"></a>  CAccelerateDecelerateTransition::m_duration

A duração da transição.

```
UI_ANIMATION_SECONDS m_duration;
```

##  <a name="m_finalvalue"></a>  CAccelerateDecelerateTransition::m_finalValue

O valor da variável de animação no final da transição.

```
DOUBLE m_finalValue;
```

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
