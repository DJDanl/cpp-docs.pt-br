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
ms.openlocfilehash: f3861bbbc0fc138dcb0f2a8b969ed9bde41335bd
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505932"
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
|[CInstantaneousTransition::CInstantaneousTransition](#cinstantaneoustransition)|Constrói um objeto de transição e inicializa seu valor final.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CInstantaneousTransition::Create](#create)|Chama a biblioteca de transição para criar objeto COM de transição encapsulada. (Substitui [CBaseTransition:: Create](../../mfc/reference/cbasetransition-class.md#create).)|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CInstantaneousTransition::m_dblFinalValue](#m_dblfinalvalue)|O valor da variável de animação no final da transição.|

## <a name="remarks"></a>Comentários

Durante uma transição instantânea, o valor da variável de animação é alterado instantaneamente de seu valor atual para um valor final especificado. A duração dessa transição é sempre zero. Como todas as transições são limpas automaticamente, é recomendável alocá-las usando o operador novo. O objeto COM encapsulado IUIAnimationTransition é criado por CAnimationController:: Animate, até que ele seja nulo. A alteração de variáveis de membro após a criação desse objeto COM não tem nenhum efeito.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CBaseTransition](../../mfc/reference/cbasetransition-class.md)

[CInstantaneousTransition](../../mfc/reference/cinstantaneoustransition-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller. h

##  <a name="cinstantaneoustransition"></a>CInstantaneousTransition::CInstantaneousTransition

Constrói um objeto de transição e inicializa seu valor final.

```
CInstantaneousTransition(DOUBLE dblFinalValue);
```

### <a name="parameters"></a>Parâmetros

*dblFinalValue*<br/>
O valor da variável de animação no final da transição.

##  <a name="create"></a>  CInstantaneousTransition::Create

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

##  <a name="m_dblfinalvalue"></a>  CInstantaneousTransition::m_dblFinalValue

O valor da variável de animação no final da transição.

```
DOUBLE m_dblFinalValue;
```

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
