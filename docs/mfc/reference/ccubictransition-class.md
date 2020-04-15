---
title: Classe CCubicTransition
ms.date: 11/04/2016
f1_keywords:
- CCubicTransition
- AFXANIMATIONCONTROLLER/CCubicTransition
- AFXANIMATIONCONTROLLER/CCubicTransition::CCubicTransition
- AFXANIMATIONCONTROLLER/CCubicTransition::Create
- AFXANIMATIONCONTROLLER/CCubicTransition::m_dblFinalValue
- AFXANIMATIONCONTROLLER/CCubicTransition::m_dblFinalVelocity
- AFXANIMATIONCONTROLLER/CCubicTransition::m_duration
helpviewer_keywords:
- CCubicTransition [MFC], CCubicTransition
- CCubicTransition [MFC], Create
- CCubicTransition [MFC], m_dblFinalValue
- CCubicTransition [MFC], m_dblFinalVelocity
- CCubicTransition [MFC], m_duration
ms.assetid: 4fc30e9c-160c-45e1-bdbe-51adf8fee9c5
ms.openlocfilehash: de376503111dab157ca34744863fb1d35a58785e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369340"
---
# <a name="ccubictransition-class"></a>Classe CCubicTransition

Encapsula uma transição cúbica.

## <a name="syntax"></a>Sintaxe

```
class CCubicTransition : public CBaseTransition;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CCubicTransition::CCubicTransition](#ccubictransition)|Constrói um objeto de transição e inicializa seus parâmetros.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CCubicTransition::Create](#create)|Chama a biblioteca de transição para criar um objeto COM de transição encapsulado. (Substitui [cbaseTransition::create](../../mfc/reference/cbasetransition-class.md#create).)|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CCubicTransition::m_dblFinalValue](#m_dblfinalvalue)|O valor da variável animação no final da transição.|
|[Transição ccubic::m_dblFinalVelocity](#m_dblfinalvelocity)|A velocidade da variável no final da transição.|
|[Transição ccubic::m_duration](#m_duration)|A duração da transição.|

## <a name="remarks"></a>Comentários

Durante uma transição cúbica, o valor da variável animação muda de seu valor inicial para um valor final especificado ao longo da duração da transição, terminando em uma velocidade especificada. Como todas as transições são liberadas automaticamente, recomenda-se alocá-las usando o operador novo. O objeto Encapsulado IUIAnimationTransition COM é criado por CAnimationController::AnimateGroup, até então ele é NULL. Alterar variáveis de membro após a criação deste objeto COM não tem efeito.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Transição de Cbase](../../mfc/reference/cbasetransition-class.md)

`CCubicTransition`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="ccubictransitionccubictransition"></a><a name="ccubictransition"></a>CCubicTransition::CCubicTransition

Constrói um objeto de transição e inicializa seus parâmetros.

```
CCubicTransition(
    UI_ANIMATION_SECONDS duration,
    DOUBLE finalValue,
    DOUBLE finalVelocity);
```

### <a name="parameters"></a>Parâmetros

*Duração*<br/>
A duração da transição.

*finalValue*<br/>
O valor da variável animação no final da transição.

*velocidade final*<br/>
A velocidade da variável no final da transição.

## <a name="ccubictransitioncreate"></a><a name="create"></a>CCubicTransition::Create

Chama a biblioteca de transição para criar um objeto COM de transição encapsulado.

```
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,
    IUIAnimationTransitionFactory* \*not used*\);
```

### <a name="parameters"></a>Parâmetros

*pBiblioteca*<br/>
Um ponteiro para uma [interface IUIAnimationTransitionLibrary](/windows/win32/api/uianimation/nn-uianimation-iuianimationtransitionlibrary), que define uma biblioteca de transições padrão.

### <a name="return-value"></a>Valor retornado

TRUE se a transição for criada com sucesso; caso contrário, FALSO.

## <a name="ccubictransitionm_dblfinalvalue"></a><a name="m_dblfinalvalue"></a>CCubicTransition::m_dblFinalValue

O valor da variável animação no final da transição.

```
DOUBLE m_dblFinalValue;
```

## <a name="ccubictransitionm_dblfinalvelocity"></a><a name="m_dblfinalvelocity"></a>Transição ccubic::m_dblFinalVelocity

A velocidade da variável no final da transição.

```
DOUBLE m_dblFinalVelocity;
```

## <a name="ccubictransitionm_duration"></a><a name="m_duration"></a>Transição ccubic::m_duration

A duração da transição.

```
UI_ANIMATION_SECONDS m_duration;
```

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
