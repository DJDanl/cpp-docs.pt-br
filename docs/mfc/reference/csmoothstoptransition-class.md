---
title: Classe CSmoothStopTransition
ms.date: 11/04/2016
f1_keywords:
- CSmoothStopTransition
- AFXANIMATIONCONTROLLER/CSmoothStopTransition
- AFXANIMATIONCONTROLLER/CSmoothStopTransition::CSmoothStopTransition
- AFXANIMATIONCONTROLLER/CSmoothStopTransition::Create
- AFXANIMATIONCONTROLLER/CSmoothStopTransition::m_dblFinalValue
- AFXANIMATIONCONTROLLER/CSmoothStopTransition::m_maximumDuration
helpviewer_keywords:
- CSmoothStopTransition [MFC], CSmoothStopTransition
- CSmoothStopTransition [MFC], Create
- CSmoothStopTransition [MFC], m_dblFinalValue
- CSmoothStopTransition [MFC], m_maximumDuration
ms.assetid: e1a4b476-6f96-43dd-90db-870a64406b85
ms.openlocfilehash: 0ba550b4a0b9443d0681e17195687fb94c207ace
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318204"
---
# <a name="csmoothstoptransition-class"></a>Classe CSmoothStopTransition

Encapsula uma transição suave.

## <a name="syntax"></a>Sintaxe

```
class CSmoothStopTransition : public CBaseTransition;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Transição csmoothstop::CsmoothStoptransition](#csmoothstoptransition)|Constrói uma transição de parada suave e inicia sua duração máxima e valor final.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Transição CSmoothStop::Criar](#create)|Chama a biblioteca de transição para criar um objeto COM de transição encapsulado. (Substitui [cbaseTransition::create](../../mfc/reference/cbasetransition-class.md#create).)|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[Transição CsmoothStop::m_dblFinalValue](#m_dblfinalvalue)|O valor da variável animação no final da transição.|
|[Transição CSmoothStop::m_maximumDuration](#m_maximumduration)|A duração máxima da transição.|

## <a name="remarks"></a>Comentários

Uma transição de parada suave diminui à medida que se aproxima de um determinado valor final, e atinge-o com uma velocidade de zero. A duração da transição é determinada pela velocidade inicial, a diferença entre os valores inicial e final e a duração máxima especificada. Se não houver solução que consista em um único arco parabólico, este método cria uma transição cúbica. Como todas as transições são liberadas automaticamente, recomenda-se alocá-las usando o operador novo. O objeto Encapsulado IUIAnimationTransition COM é criado por CAnimationController::AnimateGroup, até então ele é NULL. Alterar variáveis de membro após a criação deste objeto COM não tem efeito.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Transição de Cbase](../../mfc/reference/cbasetransition-class.md)

[Transição CsmoothStop](../../mfc/reference/csmoothstoptransition-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="csmoothstoptransitioncreate"></a><a name="create"></a>Transição CSmoothStop::Criar

Chama a biblioteca de transição para criar um objeto COM de transição encapsulado.

```
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,
    IUIAnimationTransitionFactory* \*not used*\);
```

### <a name="parameters"></a>Parâmetros

*pBiblioteca*<br/>
Um ponteiro para a biblioteca de transição, que é responsável pela criação de transições padrão.

### <a name="return-value"></a>Valor retornado

TRUE se a transição for criada com sucesso; caso contrário, FALSO.

## <a name="csmoothstoptransitioncsmoothstoptransition"></a><a name="csmoothstoptransition"></a>Transição csmoothstop::CsmoothStoptransition

Constrói uma transição de parada suave e inicia sua duração máxima e valor final.

```
CSmoothStopTransition(
    UI_ANIMATION_SECONDS maximumDuration,
    DOUBLE dblFinalValue);
```

### <a name="parameters"></a>Parâmetros

*duração máxima*<br/>
A duração máxima da transição.

*dblFinalValue*<br/>
O valor da variável animação no final da transição.

## <a name="csmoothstoptransitionm_dblfinalvalue"></a><a name="m_dblfinalvalue"></a>Transição CsmoothStop::m_dblFinalValue

O valor da variável animação no final da transição.

```
DOUBLE m_dblFinalValue;
```

## <a name="csmoothstoptransitionm_maximumduration"></a><a name="m_maximumduration"></a>Transição CSmoothStop::m_maximumDuration

A duração máxima da transição.

```
UI_ANIMATION_SECONDS m_maximumDuration;
```

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
