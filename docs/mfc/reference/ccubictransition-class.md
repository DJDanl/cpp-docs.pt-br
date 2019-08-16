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
ms.openlocfilehash: b6bb626f944ce87748809a5eb03a6f06f92c3de5
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69507135"
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
|[CCubicTransition::Create](#create)|Chama a biblioteca de transição para criar objeto COM de transição encapsulada. (Substitui [CBaseTransition:: Create](../../mfc/reference/cbasetransition-class.md#create).)|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CCubicTransition::m_dblFinalValue](#m_dblfinalvalue)|O valor da variável de animação no final da transição.|
|[CCubicTransition::m_dblFinalVelocity](#m_dblfinalvelocity)|A velocidade da variável no final da transição.|
|[CCubicTransition::m_duration](#m_duration)|A duração da transição.|

## <a name="remarks"></a>Comentários

Durante uma transição cúbica, o valor da variável de animação muda de seu valor inicial para um valor final especificado ao longo da duração da transição, terminando em uma velocidade especificada. Como todas as transições são limpas automaticamente, é recomendável alocá-las usando o operador novo. O objeto COM encapsulado IUIAnimationTransition é criado por CAnimationController:: Animate, até que ele seja nulo. A alteração de variáveis de membro após a criação desse objeto COM não tem nenhum efeito.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CBaseTransition](../../mfc/reference/cbasetransition-class.md)

`CCubicTransition`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller. h

##  <a name="ccubictransition"></a>CCubicTransition::CCubicTransition

Constrói um objeto de transição e inicializa seus parâmetros.

```
CCubicTransition(
    UI_ANIMATION_SECONDS duration,
    DOUBLE finalValue,
    DOUBLE finalVelocity);
```

### <a name="parameters"></a>Parâmetros

*permanência*<br/>
A duração da transição.

*finalValue*<br/>
O valor da variável de animação no final da transição.

*finalVelocity*<br/>
A velocidade da variável no final da transição.

##  <a name="create"></a>CCubicTransition:: criar

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

##  <a name="m_dblfinalvalue"></a>CCubicTransition::m_dblFinalValue

O valor da variável de animação no final da transição.

```
DOUBLE m_dblFinalValue;
```

##  <a name="m_dblfinalvelocity"></a>  CCubicTransition::m_dblFinalVelocity

A velocidade da variável no final da transição.

```
DOUBLE m_dblFinalVelocity;
```

##  <a name="m_duration"></a>CCubicTransition::m_duration

A duração da transição.

```
UI_ANIMATION_SECONDS m_duration;
```

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
