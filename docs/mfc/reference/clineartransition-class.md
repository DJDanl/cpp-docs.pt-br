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
ms.openlocfilehash: 4aa2d9955d2bbf98d2d7829806c4bcbd76340847
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62392525"
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
|[CLinearTransition::CLinearTransition](#clineartransition)|Constrói um objeto de transição linear e o inicializa com duração e o valor final.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CLinearTransition::Create](#create)|Chama a biblioteca de transição para criar o objeto encapsulado transição COM. (Substitui [CBaseTransition::Create](../../mfc/reference/cbasetransition-class.md#create).)|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CLinearTransition::m_dblFinalValue](#m_dblfinalvalue)|O valor da variável de animação no final da transição.|
|[CLinearTransition::m_duration](#m_duration)|A duração da transição.|

## <a name="remarks"></a>Comentários

Durante uma transição linear, o valor da variável de animação faz a transição linearmente do seu valor inicial para um valor final especificado. Como todas as transições são limpas automaticamente, é recomendável para alocado-los usando o operador novo. O objeto de IUIAnimationTransition COM encapsulado é criado pelo CAnimationController::AnimateGroup, até então é NULL. Alterando as variáveis de membro após a criação deste objeto COM não tem nenhum efeito.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CBaseTransition](../../mfc/reference/cbasetransition-class.md)

[CLinearTransition](../../mfc/reference/clineartransition-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

##  <a name="clineartransition"></a>  CLinearTransition::CLinearTransition

Constrói um objeto de transição linear e o inicializa com duração e o valor final.

```
CLinearTransition(
    UI_ANIMATION_SECONDS duration,
    DOUBLE dblFinalValue);
```

### <a name="parameters"></a>Parâmetros

*duration*<br/>
A duração da transição.

*dblFinalValue*<br/>
O valor da variável de animação no final da transição.

##  <a name="create"></a>  CLinearTransition::Create

Chama a biblioteca de transição para criar o objeto encapsulado transição COM.

```
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,
    IUIAnimationTransitionFactory* \*not used*\);
```

### <a name="parameters"></a>Parâmetros

*pLibrary*<br/>
Um ponteiro para um [IUIAnimationTransitionLibrary interface](/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary), que define uma biblioteca de transições padrão.

### <a name="return-value"></a>Valor de retorno

TRUE se a transição é criada com êxito; Caso contrário, FALSE.

##  <a name="m_dblfinalvalue"></a>  CLinearTransition::m_dblFinalValue

O valor da variável de animação no final da transição.

```
DOUBLE m_dblFinalValue;
```

##  <a name="m_duration"></a>  CLinearTransition::m_duration

A duração da transição.

```
UI_ANIMATION_SECONDS m_duration;
```

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
