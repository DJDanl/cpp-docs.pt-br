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
ms.openlocfilehash: 1a6348d1afd0117683bd31af61324b14e16f710c
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505737"
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
|[CLinearTransition::CLinearTransition](#clineartransition)|Constrói um objeto de transição linear e o inicializa com a duração e o valor final.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CLinearTransition::Create](#create)|Chama a biblioteca de transição para criar objeto COM de transição encapsulada. (Substitui [CBaseTransition:: Create](../../mfc/reference/cbasetransition-class.md#create).)|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CLinearTransition::m_dblFinalValue](#m_dblfinalvalue)|O valor da variável de animação no final da transição.|
|[CLinearTransition::m_duration](#m_duration)|A duração da transição.|

## <a name="remarks"></a>Comentários

Durante uma transição linear, o valor da variável de animação faz a transição linearmente de seu valor inicial para um valor final especificado. Como todas as transições são limpas automaticamente, é recomendável alocá-las usando o operador novo. O objeto COM encapsulado IUIAnimationTransition é criado por CAnimationController:: Animate, até que ele seja nulo. A alteração de variáveis de membro após a criação desse objeto COM não tem nenhum efeito.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CBaseTransition](../../mfc/reference/cbasetransition-class.md)

[CLinearTransition](../../mfc/reference/clineartransition-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller. h

##  <a name="clineartransition"></a>  CLinearTransition::CLinearTransition

Constrói um objeto de transição linear e o inicializa com a duração e o valor final.

```
CLinearTransition(
    UI_ANIMATION_SECONDS duration,
    DOUBLE dblFinalValue);
```

### <a name="parameters"></a>Parâmetros

*permanência*<br/>
A duração da transição.

*dblFinalValue*<br/>
O valor da variável de animação no final da transição.

##  <a name="create"></a>  CLinearTransition::Create

Chama a biblioteca de transição para criar objeto COM de transição encapsulada.

```
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,
    IUIAnimationTransitionFactory* \*not used*\);
```

### <a name="parameters"></a>Parâmetros

*pLibrary*<br/>
Um ponteiro para uma [interface IUIAnimationTransitionLibrary](/windows/win32/api/uianimation/nn-uianimation-iuianimationtransitionlibrary), que define uma biblioteca de transições padrão.

### <a name="return-value"></a>Valor de retorno

TRUE se a transição for criada com êxito; caso contrário, FALSE.

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
