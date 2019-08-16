---
title: Classe CAccelerateDecelerateTransition
ms.date: 11/04/2016
f1_keywords:
- CAccelerateDecelerateTransition
- afxanimationcontroller/CAccelerateDecelerateTransition
helpviewer_keywords:
- CAccelerateDecelerateTransition class [MFC]
ms.assetid: b1f31ee8-bb11-4ccc-b124-365fb02b025c
ms.openlocfilehash: 1e55e81b4d9b5c324f86bfd141b74d9faa362d94
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69507737"
---
# <a name="cacceleratedeceleratetransition-class"></a>Classe CAccelerateDecelerateTransition

Implementa uma transição aceleração e desaceleração.

## <a name="syntax"></a>Sintaxe

```
class CAccelerateDecelerateTransition : public CBaseTransition;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAccelerateDecelerateTransition::CAccelerateDecelerateTransition](#cacceleratedeceleratetransition)|Constrói um objeto de transição.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAccelerateDecelerateTransition::Create](#create)|Chama a biblioteca de transição para criar objeto COM de transição encapsulada. (Substitui [CBaseTransition:: Create](../../mfc/reference/cbasetransition-class.md#create).)|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAccelerateDecelerateTransition::m_accelerationRatio](#m_accelerationratio)|A proporção do tempo gasto acelerando até a duração.|
|[CAccelerateDecelerateTransition::m_decelerationRatio](#m_decelerationratio)|A proporção do tempo gasto decelerating até a duração.|
|[CAccelerateDecelerateTransition::m_duration](#m_duration)|A duração da transição.|
|[CAccelerateDecelerateTransition::m_finalValue](#m_finalvalue)|O valor da variável de animação no final da transição.|

## <a name="remarks"></a>Comentários

Durante uma transição acelerar aceleração, a variável de animação acelera e reduz a duração da transição, terminando em um valor especificado. Você pode controlar a rapidez com que a variável é acelerada e desacelerada de forma independente, especificando taxas de aceleração e desaceleração diferentes. Quando a velocidade inicial é zero, a taxa de aceleração é a fração da duração que a variável gastará acelerando; da mesma forma, com a taxa de desaceleração. Se a velocidade inicial for diferente de zero, será a fração do tempo entre a velocidade de alcance zero e o fim da transição. A taxa de aceleração e a taxa de desaceleração devem somar no máximo 1,0. Como todas as transições são limpas automaticamente, é recomendável alocá-las usando o operador novo. O objeto COM encapsulado IUIAnimationTransition é criado por CAnimationController:: Animate, até que ele seja nulo. A alteração de variáveis de membro após a criação desse objeto COM não tem nenhum efeito.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CBaseTransition](../../mfc/reference/cbasetransition-class.md)

`CAccelerateDecelerateTransition`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller. h

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

*permanência*<br/>
A duração da transição.

*finalValue*<br/>
O valor da variável de animação no final da transição.

*accelerationRatio*<br/>
A proporção do tempo gasto acelerando até a duração.

*decelerationRatio*<br/>
A proporção do tempo gasto decelerating até a duração.

##  <a name="create"></a>  CAccelerateDecelerateTransition::Create

Chama a biblioteca de transição para criar objeto COM de transição encapsulada.

```
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,
    IUIAnimationTransitionFactory* *\not used*\);
```

### <a name="parameters"></a>Parâmetros

*pLibrary*<br/>
Um ponteiro para uma [interface IUIAnimationTransitionLibrary](/windows/win32/api/uianimation/nn-uianimation-iuianimationtransitionlibrary), que define uma biblioteca de transições padrão.

### <a name="return-value"></a>Valor de retorno

TRUE se a transição for criada com êxito; caso contrário, FALSE.

##  <a name="m_accelerationratio"></a>  CAccelerateDecelerateTransition::m_accelerationRatio

A proporção do tempo gasto acelerando até a duração.

```
DOUBLE m_accelerationRatio;
```

##  <a name="m_decelerationratio"></a>  CAccelerateDecelerateTransition::m_decelerationRatio

A proporção do tempo gasto decelerating até a duração.

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
