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
ms.openlocfilehash: dc2311f7dae71f7c3848b7825b297ec5c9747859
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57262825"
---
# <a name="cdiscretetransition-class"></a>Classe CDiscreteTransition

Encapsula uma transição discreta.

## <a name="syntax"></a>Sintaxe

```
class CDiscreteTransition : public CBaseTransition;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDiscreteTransition::CDiscreteTransition](#cdiscretetransition)|Constrói um objeto de transição discreta e inicializa seus parâmetros.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDiscreteTransition::Create](#create)|Chama a biblioteca de transição para criar o objeto encapsulado transição COM. (Substitui [CBaseTransition::Create](../../mfc/reference/cbasetransition-class.md#create).)|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDiscreteTransition::m_dblFinalValue](#m_dblfinalvalue)|O valor da variável de animação no final da transição.|
|[CDiscreteTransition::m_delay](#m_delay)|A quantidade de tempo pelo qual atrasar a opção de instantânea para o valor final.|
|[CDiscreteTransition::m_hold](#m_hold)|A quantidade de tempo pelo qual armazenar a variável em seu valor final.|

## <a name="remarks"></a>Comentários

Durante uma transição discreta, a variável de animação permanece o valor inicial para um tempo de espera especificado, em seguida, alterna instantaneamente para um valor final especificado e permanece com esse valor por um período de retenção determinada. Como todas as transições são limpas automaticamente, é recomendável para alocado-los usando o operador novo. O objeto de IUIAnimationTransition COM encapsulado é criado pelo CAnimationController::AnimateGroup, até então é NULL. Alterando as variáveis de membro após a criação deste objeto COM não tem nenhum efeito.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CBaseTransition](../../mfc/reference/cbasetransition-class.md)

[CDiscreteTransition](../../mfc/reference/cdiscretetransition-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

##  <a name="cdiscretetransition"></a>  CDiscreteTransition::CDiscreteTransition

Constrói um objeto de transição discreta e inicializa seus parâmetros.

```
CDiscreteTransition(
    UI_ANIMATION_SECONDS delay,
    DOUBLE dblFinalValue,
    UI_ANIMATION_SECONDS hold);
```

### <a name="parameters"></a>Parâmetros

*delay*<br/>
A quantidade de tempo pelo qual atrasar a opção de instantânea para o valor final.

*dblFinalValue*<br/>
O valor da variável de animação no final da transição.

*hold*<br/>
A quantidade de tempo pelo qual armazenar a variável em seu valor final.

##  <a name="create"></a>  CDiscreteTransition::Create

Chama a biblioteca de transição para criar o objeto encapsulado transição COM.

```
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,
    IUIAnimationTransitionFactory* \*not used*\);
```

*pLibrary*<br/>
Um ponteiro para um [IUIAnimationTransitionLibrary interface](/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary), que define uma biblioteca de transições padrão.

### <a name="return-value"></a>Valor de retorno

TRUE se a transição é criada com êxito; Caso contrário, FALSE.

##  <a name="m_dblfinalvalue"></a>  CDiscreteTransition::m_dblFinalValue

O valor da variável de animação no final da transição.

```
DOUBLE m_dblFinalValue;
```

##  <a name="m_delay"></a>  CDiscreteTransition::m_delay

A quantidade de tempo pelo qual atrasar a opção de instantânea para o valor final.

```
UI_ANIMATION_SECONDS m_delay;
```

##  <a name="m_hold"></a>  CDiscreteTransition::m_hold

A quantidade de tempo pelo qual armazenar a variável em seu valor final.

```
UI_ANIMATION_SECONDS m_hold;
```

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
