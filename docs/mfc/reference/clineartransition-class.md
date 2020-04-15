---
title: Classe CLinearTransition
ms.date: 11/04/2016
f1_keywords:
- CLinearTransition
- AFXANIMATIONCONTROLLER/CLinearTransition
- AFXANIMATIONCONTROLLER/CLinearTransition::CLinearTransition
- AFXANIMATIONCONTROLLER/CLinearTransition::Create
- AFXANIMATIONCONTROLLER/CLinearTransition::m_dblFinalValue
- AFXANIMATIONCONTROLLER/CLinearTransition::m_duration
helpviewer_keywords:
- CLinearTransition [MFC], CLinearTransition
- CLinearTransition [MFC], Create
- CLinearTransition [MFC], m_dblFinalValue
- CLinearTransition [MFC], m_duration
ms.assetid: 7fcb2dba-beb8-4933-9f5d-3b7fb1585ef0
ms.openlocfilehash: 1d3bc50255dae93bfa80e8212c2349db66db4eb6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372274"
---
# <a name="clineartransition-class"></a>Classe CLinearTransition

Encapsula uma transição linear.

## <a name="syntax"></a>Sintaxe

```
class CLinearTransition : public CBaseTransition;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Transição clinear::Transição linear](#clineartransition)|Constrói um objeto de transição linear e o inicializa com duração e valor final.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Transição clinear::criar](#create)|Chama a biblioteca de transição para criar um objeto COM de transição encapsulado. (Substitui [cbaseTransition::create](../../mfc/reference/cbasetransition-class.md#create).)|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[Transição Clinear::m_dblFinalValue](#m_dblfinalvalue)|O valor da variável animação no final da transição.|
|[Transição Clinear::m_duration](#m_duration)|A duração da transição.|

## <a name="remarks"></a>Comentários

Durante uma transição linear, o valor da variável animação transita linearmente de seu valor inicial para um valor final especificado. Como todas as transições são liberadas automaticamente, recomenda-se alocá-las usando o operador novo. O objeto Encapsulado IUIAnimationTransition COM é criado por CAnimationController::AnimateGroup, até então ele é NULL. Alterar variáveis de membro após a criação deste objeto COM não tem efeito.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Transição de Cbase](../../mfc/reference/cbasetransition-class.md)

[Transição Clinear](../../mfc/reference/clineartransition-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="clineartransitionclineartransition"></a><a name="clineartransition"></a>Transição clinear::Transição linear

Constrói um objeto de transição linear e o inicializa com duração e valor final.

```
CLinearTransition(
    UI_ANIMATION_SECONDS duration,
    DOUBLE dblFinalValue);
```

### <a name="parameters"></a>Parâmetros

*Duração*<br/>
A duração da transição.

*dblFinalValue*<br/>
O valor da variável animação no final da transição.

## <a name="clineartransitioncreate"></a><a name="create"></a>Transição clinear::criar

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

## <a name="clineartransitionm_dblfinalvalue"></a><a name="m_dblfinalvalue"></a>Transição Clinear::m_dblFinalValue

O valor da variável animação no final da transição.

```
DOUBLE m_dblFinalValue;
```

## <a name="clineartransitionm_duration"></a><a name="m_duration"></a>Transição Clinear::m_duration

A duração da transição.

```
UI_ANIMATION_SECONDS m_duration;
```

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
