---
title: Classe CDiscreteTransition
ms.date: 11/04/2016
f1_keywords:
- CDiscreteTransition
- AFXANIMATIONCONTROLLER/CDiscreteTransition
- AFXANIMATIONCONTROLLER/CDiscreteTransition::CDiscreteTransition
- AFXANIMATIONCONTROLLER/CDiscreteTransition::Create
- AFXANIMATIONCONTROLLER/CDiscreteTransition::m_dblFinalValue
- AFXANIMATIONCONTROLLER/CDiscreteTransition::m_delay
- AFXANIMATIONCONTROLLER/CDiscreteTransition::m_hold
helpviewer_keywords:
- CDiscreteTransition [MFC], CDiscreteTransition
- CDiscreteTransition [MFC], Create
- CDiscreteTransition [MFC], m_dblFinalValue
- CDiscreteTransition [MFC], m_delay
- CDiscreteTransition [MFC], m_hold
ms.assetid: b4d84fb3-ccaa-451c-a69b-6b50dcb9b9c8
ms.openlocfilehash: 7087dfa13972737f0a1244d2cc9a7088b23dc184
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69506862"
---
# <a name="cdiscretetransition-class"></a>Classe CDiscreteTransition

Encapsula uma transição discreta.

## <a name="syntax"></a>Sintaxe

```
class CDiscreteTransition : public CBaseTransition;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDiscreteTransition::CDiscreteTransition](#cdiscretetransition)|Constrói um objeto de transição discreto e inicializa seus parâmetros.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDiscreteTransition:: criar](#create)|Chama a biblioteca de transição para criar objeto COM de transição encapsulada. (Substitui [CBaseTransition:: Create](../../mfc/reference/cbasetransition-class.md#create).)|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDiscreteTransition::m_dblFinalValue](#m_dblfinalvalue)|O valor da variável de animação no final da transição.|
|[CDiscreteTransition::m_delay](#m_delay)|A quantidade de tempo pela qual atrasar a opção instantânea para o valor final.|
|[CDiscreteTransition::m_hold](#m_hold)|A quantidade de tempo pela qual manter a variável em seu valor final.|

## <a name="remarks"></a>Comentários

Durante uma transição discreta, a variável de animação permanece no valor inicial de um tempo de atraso especificado, alterna instantaneamente para um valor final especificado e permanece nesse valor para um determinado tempo de espera. Como todas as transições são limpas automaticamente, é recomendável alocá-las usando o operador novo. O objeto COM encapsulado IUIAnimationTransition é criado por CAnimationController:: Animate, até que ele seja nulo. A alteração de variáveis de membro após a criação desse objeto COM não tem nenhum efeito.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CBaseTransition](../../mfc/reference/cbasetransition-class.md)

[CDiscreteTransition](../../mfc/reference/cdiscretetransition-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller. h

##  <a name="cdiscretetransition"></a>CDiscreteTransition::CDiscreteTransition

Constrói um objeto de transição discreto e inicializa seus parâmetros.

```
CDiscreteTransition(
    UI_ANIMATION_SECONDS delay,
    DOUBLE dblFinalValue,
    UI_ANIMATION_SECONDS hold);
```

### <a name="parameters"></a>Parâmetros

*retardo*<br/>
A quantidade de tempo pela qual atrasar a opção instantânea para o valor final.

*dblFinalValue*<br/>
O valor da variável de animação no final da transição.

*bloqueio*<br/>
A quantidade de tempo pela qual manter a variável em seu valor final.

##  <a name="create"></a>CDiscreteTransition:: criar

Chama a biblioteca de transição para criar objeto COM de transição encapsulada.

```
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,
    IUIAnimationTransitionFactory* \*not used*\);
```

*pLibrary*<br/>
Um ponteiro para uma [interface IUIAnimationTransitionLibrary](/windows/win32/api/uianimation/nn-uianimation-iuianimationtransitionlibrary), que define uma biblioteca de transições padrão.

### <a name="return-value"></a>Valor de retorno

TRUE se a transição for criada com êxito; caso contrário, FALSE.

##  <a name="m_dblfinalvalue"></a>CDiscreteTransition::m_dblFinalValue

O valor da variável de animação no final da transição.

```
DOUBLE m_dblFinalValue;
```

##  <a name="m_delay"></a>CDiscreteTransition::m_delay

A quantidade de tempo pela qual atrasar a opção instantânea para o valor final.

```
UI_ANIMATION_SECONDS m_delay;
```

##  <a name="m_hold"></a>CDiscreteTransition::m_hold

A quantidade de tempo pela qual manter a variável em seu valor final.

```
UI_ANIMATION_SECONDS m_hold;
```

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
