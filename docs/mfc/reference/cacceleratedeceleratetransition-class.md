---
title: Classe CAccelerateDecelerateTransition
ms.date: 11/04/2016
f1_keywords:
- CAccelerateDecelerateTransition
- afxanimationcontroller/CAccelerateDecelerateTransition
helpviewer_keywords:
- CAccelerateDecelerateTransition class [MFC]
ms.assetid: b1f31ee8-bb11-4ccc-b124-365fb02b025c
ms.openlocfilehash: 356ba30e6d9a638672d2c356676735ebfaed8f3e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371142"
---
# <a name="cacceleratedeceleratetransition-class"></a>Classe CAccelerateDecelerateTransition

Implementa uma transição acelerada de desaceleração.

## <a name="syntax"></a>Sintaxe

```
class CAccelerateDecelerateTransition : public CBaseTransition;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAccelerateDeelerateTransition::CAccelerateDeeleelerateTransition](#cacceleratedeceleratetransition)|Constrói um objeto de transição.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAccelerateDeelerateTransition::Create](#create)|Chama a biblioteca de transição para criar um objeto COM de transição encapsulado. (Substitui [cbaseTransition::create](../../mfc/reference/cbasetransition-class.md#create).)|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAccelerateDeelerateTransition::m_accelerationRatio](#m_accelerationratio)|A proporção do tempo gasto acelerando até a duração.|
|[CAccelerateDeelerateTransition::m_decelerationRatio](#m_decelerationratio)|A razão do tempo gasto desacelerando para a duração.|
|[CAccelerateDeelerateTransition::m_duration](#m_duration)|A duração da transição.|
|[CAccelerateDeelerateTransition::m_finalValue](#m_finalvalue)|O valor da variável animação no final da transição.|

## <a name="remarks"></a>Comentários

Durante uma transição de aceleração, a variável animação acelera e, em seguida, diminui a velocidade durante a transição, terminando em um valor especificado. Você pode controlar a rapidez com que a variável acelera e desacelera independentemente, especificando diferentes taxas de aceleração e desaceleração. Quando a velocidade inicial é zero, a razão de aceleração é a fração da duração que a variável gastará acelerando; da mesma forma com a razão de desaceleração. Se a velocidade inicial não for zero, é a fração do tempo entre a velocidade que atinge zero e o fim da transição. A relação de aceleração e a razão de desaceleração devem ser somadas a um máximo de 1,0. Como todas as transições são liberadas automaticamente, recomenda-se alocá-las usando o operador novo. O objeto Encapsulado IUIAnimationTransition COM é criado por CAnimationController::AnimateGroup, até então ele é NULL. Alterar variáveis de membro após a criação deste objeto COM não tem efeito.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Transição de Cbase](../../mfc/reference/cbasetransition-class.md)

`CAccelerateDecelerateTransition`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="cacceleratedeceleratetransitioncacceleratedeceleratetransition"></a><a name="cacceleratedeceleratetransition"></a>CAccelerateDeelerateTransition::CAccelerateDeeleelerateTransition

Constrói um objeto de transição.

```
CAccelerateDecelerateTransition(
    UI_ANIMATION_SECONDS duration,
    DOUBLE finalValue,
    DOUBLE accelerationRatio = 0.3,
    DOUBLE decelerationRatio = 0.3);
```

### <a name="parameters"></a>Parâmetros

*Duração*<br/>
A duração da transição.

*finalValue*<br/>
O valor da variável animação no final da transição.

*Accelerationratio*<br/>
A proporção do tempo gasto acelerando até a duração.

*Decelerationratio*<br/>
A razão do tempo gasto desacelerando para a duração.

## <a name="cacceleratedeceleratetransitioncreate"></a><a name="create"></a>CAccelerateDeelerateTransition::Create

Chama a biblioteca de transição para criar um objeto COM de transição encapsulado.

```
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,
    IUIAnimationTransitionFactory* *\not used*\);
```

### <a name="parameters"></a>Parâmetros

*pBiblioteca*<br/>
Um ponteiro para uma [interface IUIAnimationTransitionLibrary](/windows/win32/api/uianimation/nn-uianimation-iuianimationtransitionlibrary), que define uma biblioteca de transições padrão.

### <a name="return-value"></a>Valor retornado

TRUE se a transição for criada com sucesso; caso contrário, FALSO.

## <a name="cacceleratedeceleratetransitionm_accelerationratio"></a><a name="m_accelerationratio"></a>CAccelerateDeelerateTransition::m_accelerationRatio

A proporção do tempo gasto acelerando até a duração.

```
DOUBLE m_accelerationRatio;
```

## <a name="cacceleratedeceleratetransitionm_decelerationratio"></a><a name="m_decelerationratio"></a>CAccelerateDeelerateTransition::m_decelerationRatio

A razão do tempo gasto desacelerando para a duração.

```
DOUBLE m_decelerationRatio;
```

## <a name="cacceleratedeceleratetransitionm_duration"></a><a name="m_duration"></a>CAccelerateDeelerateTransition::m_duration

A duração da transição.

```
UI_ANIMATION_SECONDS m_duration;
```

## <a name="cacceleratedeceleratetransitionm_finalvalue"></a><a name="m_finalvalue"></a>CAccelerateDeelerateTransition::m_finalValue

O valor da variável animação no final da transição.

```
DOUBLE m_finalValue;
```

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
