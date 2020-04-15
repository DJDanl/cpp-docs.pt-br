---
title: Classe CInstantaneousTransition
ms.date: 11/04/2016
f1_keywords:
- CInstantaneousTransition
- AFXANIMATIONCONTROLLER/CInstantaneousTransition
- AFXANIMATIONCONTROLLER/CInstantaneousTransition::CInstantaneousTransition
- AFXANIMATIONCONTROLLER/CInstantaneousTransition::Create
- AFXANIMATIONCONTROLLER/CInstantaneousTransition::m_dblFinalValue
helpviewer_keywords:
- CInstantaneousTransition [MFC], CInstantaneousTransition
- CInstantaneousTransition [MFC], Create
- CInstantaneousTransition [MFC], m_dblFinalValue
ms.assetid: c3d5121f-2c6b-4221-9e57-10e082a31120
ms.openlocfilehash: 15c471d64309cc1358c9c5b0b33577261dd877f6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372435"
---
# <a name="cinstantaneoustransition-class"></a>Classe CInstantaneousTransition

Encapsula uma transição instantânea.

## <a name="syntax"></a>Sintaxe

```
class CInstantaneousTransition : public CBaseTransition;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Transição CInstantaneous::CInstantaneousTransition](#cinstantaneoustransition)|Constrói um objeto de transição e inicializa seu valor final.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Transição CInstantaneous::Criar](#create)|Chama a biblioteca de transição para criar um objeto COM de transição encapsulado. (Substitui [cbaseTransition::create](../../mfc/reference/cbasetransition-class.md#create).)|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[Transição CInstantaneous::m_dblFinalValue](#m_dblfinalvalue)|O valor da variável animação no final da transição.|

## <a name="remarks"></a>Comentários

Durante uma transição instantânea, o valor da variável animação muda instantaneamente de seu valor atual para um valor final especificado. A duração dessa transição é sempre zero. Como todas as transições são liberadas automaticamente, recomenda-se alocá-las usando o operador novo. O objeto Encapsulado IUIAnimationTransition COM é criado por CAnimationController::AnimateGroup, até então ele é NULL. Alterar variáveis de membro após a criação deste objeto COM não tem efeito.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Transição de Cbase](../../mfc/reference/cbasetransition-class.md)

[Transição CInstantaneous](../../mfc/reference/cinstantaneoustransition-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="cinstantaneoustransitioncinstantaneoustransition"></a><a name="cinstantaneoustransition"></a>Transição CInstantaneous::CInstantaneousTransition

Constrói um objeto de transição e inicializa seu valor final.

```
CInstantaneousTransition(DOUBLE dblFinalValue);
```

### <a name="parameters"></a>Parâmetros

*dblFinalValue*<br/>
O valor da variável animação no final da transição.

## <a name="cinstantaneoustransitioncreate"></a><a name="create"></a>Transição CInstantaneous::Criar

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

## <a name="cinstantaneoustransitionm_dblfinalvalue"></a><a name="m_dblfinalvalue"></a>Transição CInstantaneous::m_dblFinalValue

O valor da variável animação no final da transição.

```
DOUBLE m_dblFinalValue;
```

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
