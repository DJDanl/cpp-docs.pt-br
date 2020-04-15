---
title: Classe CBaseTransition
ms.date: 03/27/2019
f1_keywords:
- CBaseTransition
- AFXANIMATIONCONTROLLER/CBaseTransition
- AFXANIMATIONCONTROLLER/CBaseTransition::CBaseTransition
- AFXANIMATIONCONTROLLER/CBaseTransition::AddToStoryboard
- AFXANIMATIONCONTROLLER/CBaseTransition::AddToStoryboardAtKeyframes
- AFXANIMATIONCONTROLLER/CBaseTransition::Clear
- AFXANIMATIONCONTROLLER/CBaseTransition::Create
- AFXANIMATIONCONTROLLER/CBaseTransition::GetEndKeyframe
- AFXANIMATIONCONTROLLER/CBaseTransition::GetRelatedVariable
- AFXANIMATIONCONTROLLER/CBaseTransition::GetStartKeyframe
- AFXANIMATIONCONTROLLER/CBaseTransition::GetTransition
- AFXANIMATIONCONTROLLER/CBaseTransition::GetType
- AFXANIMATIONCONTROLLER/CBaseTransition::IsAdded
- AFXANIMATIONCONTROLLER/CBaseTransition::SetKeyframes
- AFXANIMATIONCONTROLLER/CBaseTransition::SetRelatedVariable
- AFXANIMATIONCONTROLLER/CBaseTransition::m_bAdded
- AFXANIMATIONCONTROLLER/CBaseTransition::m_pEndKeyframe
- AFXANIMATIONCONTROLLER/CBaseTransition::m_pRelatedVariable
- AFXANIMATIONCONTROLLER/CBaseTransition::m_pStartKeyframe
- AFXANIMATIONCONTROLLER/CBaseTransition::m_transition
- AFXANIMATIONCONTROLLER/CBaseTransition::m_type
helpviewer_keywords:
- CBaseTransition [MFC], CBaseTransition
- CBaseTransition [MFC], AddToStoryboard
- CBaseTransition [MFC], AddToStoryboardAtKeyframes
- CBaseTransition [MFC], Clear
- CBaseTransition [MFC], Create
- CBaseTransition [MFC], GetEndKeyframe
- CBaseTransition [MFC], GetRelatedVariable
- CBaseTransition [MFC], GetStartKeyframe
- CBaseTransition [MFC], GetTransition
- CBaseTransition [MFC], GetType
- CBaseTransition [MFC], IsAdded
- CBaseTransition [MFC], SetKeyframes
- CBaseTransition [MFC], SetRelatedVariable
- CBaseTransition [MFC], m_bAdded
- CBaseTransition [MFC], m_pEndKeyframe
- CBaseTransition [MFC], m_pRelatedVariable
- CBaseTransition [MFC], m_pStartKeyframe
- CBaseTransition [MFC], m_transition
- CBaseTransition [MFC], m_type
ms.assetid: dfe84007-bbc5-43b7-b5b8-fae9145573bf
ms.openlocfilehash: 8339785fd10fa3dcef1c0fb573310762dc2d2405
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81352831"
---
# <a name="cbasetransition-class"></a>Classe CBaseTransition

Representa uma transição básica.

## <a name="syntax"></a>Sintaxe

```
class CBaseTransition : public CObject;
```

## <a name="members"></a>Membros

### <a name="public-enumerations"></a>Enumerações públicas

|Nome|Descrição|
|----------|-----------------|
|[CBaseTransition::enumeração TRANSITION_TYPE](#transition_type_enumeration)|Define os tipos de transição atualmente suportados pela implementação do MFC da API de animação do Windows.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CBaseTransition::CBaseTransition](#cbasetransition)|Constrói um objeto de transição base.|
|[Transição de CBase::~Transição de base](#_dtorcbasetransition)|O destruidor. Chamado quando um objeto de transição está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CBaseTransition::AddToStoryboard](#addtostoryboard)|Adiciona uma transição a um storyboard.|
|[CBaseTransition::AddToStoryboardAtKeyframes](#addtostoryboardatkeyframes)|Adiciona uma transição a um storyboard.|
|[Transição de cbase::limpar](#clear)|Lançamentos encapsulados IUIAnimationTransition COM objeto.|
|[CBaseTransition::Create](#create)|Cria uma transição COM.|
|[CBaseTransition::GetEndKeyframe](#getendkeyframe)|Retorna o quadro-chave iniciar.|
|[CBaseTransition::GetRelatedVariable](#getrelatedvariable)|Retorna um ponteiro para variável relacionada.|
|[CBaseTransition::GetStartKeyframe](#getstartkeyframe)|Retorna o quadro-chave iniciar.|
|[Transição de cbase::gettransition](#gettransition)|Sobrecarregado. Retorna um ponteiro para o objeto de transição COM subjacente.|
|[CBaseTransition::GetType](#gettype)|Tipo de transição de retorno.|
|[Transição de cbase::isadded](#isadded)|Conta se uma transição foi adicionada a um storyboard.|
|[CBaseTransition::SetKeyframes](#setkeyframes)|Define quadros-chave para uma transição.|
|[Transição de cBase::SetRelatedVariable](#setrelatedvariable)|Estabelece uma relação entre a variável animação e a transição.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CBaseTransition::m_bAdded](#m_badded)|Especifica se uma transição foi adicionada a um storyboard.|
|[Transição de CBase::m_pEndKeyframe](#m_pendkeyframe)|Armazena um ponteiro para o quadro-chave que especifica o fim da transição.|
|[Transição de cbase::m_pRelatedVariable](#m_prelatedvariable)|Um ponteiro para uma variável de animação, que é animado com a transição armazenada em m_transition.|
|[Transição de cbase::m_pStartKeyframe](#m_pstartkeyframe)|Armazena um ponteiro para o quadro-chave que especifica o início da transição.|
|[Transição de CBase::m_transition](#m_transition)|Armazena um ponteiro para IUIAnimationTransition. NULL se um objeto de transição COM não tiver sido criado.|
|[CBaseTransition::m_type](#m_type)|Armazena o tipo de transição.|

## <a name="remarks"></a>Comentários

Esta classe encapsula a interface IUIAnimationTransition e serve como uma classe base para todas as transições.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CBaseTransition`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="cbasetransitioncbasetransition"></a><a name="_dtorcbasetransition"></a>Transição de CBase::~Transição de base

O destruidor. Chamado quando um objeto de transição está sendo destruído.

```
virtual ~CBaseTransition();
```

## <a name="cbasetransitionaddtostoryboard"></a><a name="addtostoryboard"></a>CBaseTransition::AddToStoryboard

Adiciona uma transição a um storyboard.

```
BOOL AddToStoryboard(IUIAnimationStoryboard* pStoryboard);
```

### <a name="parameters"></a>Parâmetros

*pStoryboard*<br/>
Um ponteiro para storyboard, que animará a variável relacionada.

### <a name="return-value"></a>Valor retornado

VERDADE, se a transição foi adicionada com sucesso a um storyboard.

### <a name="remarks"></a>Comentários

Aplica a transição para a variável relacionada no storyboard. Se esta é a primeira transição aplicada a esta variável neste storyboard, a transição começa no início do storyboard. Caso contrário, a transição é anexada à transição adicionada mais recentemente à variável.

## <a name="cbasetransitionaddtostoryboardatkeyframes"></a><a name="addtostoryboardatkeyframes"></a>CBaseTransition::AddToStoryboardAtKeyframes

Adiciona uma transição a um storyboard.

```
BOOL AddToStoryboardAtKeyframes(IUIAnimationStoryboard* pStoryboard);
```

### <a name="parameters"></a>Parâmetros

*pStoryboard*<br/>
Um ponteiro para storyboard, que animará a variável relacionada.

### <a name="return-value"></a>Valor retornado

VERDADE, se a transição foi adicionada com sucesso a um storyboard.

### <a name="remarks"></a>Comentários

Aplica a transição para a variável relacionada no storyboard. Se o quadro-chave de início foi especificado, a transição começará nesse quadro-chave. Se o quadro-chave final foi especificado, a transição começa no quadro-chave inicial e pára no quadro-chave final. Se a transição foi criada com um parâmetro de duração especificado, essa duração será sobressacada com a duração do tempo entre os quadros-chave de início e de fim. Se nenhum quadro-chave foi especificado, a transição será anexada à transição adicionada mais recentemente à variável.

## <a name="cbasetransitioncbasetransition"></a><a name="cbasetransition"></a>CBaseTransition::CBaseTransition

Constrói um objeto de transição base.

```
CBaseTransition();
```

## <a name="cbasetransitionclear"></a><a name="clear"></a>Transição de cbase::limpar

Lançamentos encapsulados IUIAnimationTransition COM objeto.

```
void Clear();
```

### <a name="remarks"></a>Comentários

Este método deve ser chamado a partir do método Create de uma classe derivada, a fim de evitar o vazamento da interface IUITransition.

## <a name="cbasetransitioncreate"></a><a name="create"></a>CBaseTransition::Create

Cria uma transição COM.

```
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,
    IUIAnimationTransitionFactory* pFactory) = 0;
```

### <a name="parameters"></a>Parâmetros

*pBiblioteca*<br/>
Um ponteiro para a biblioteca de transição, que cria transições padrão. Pode ser NULL para transições personalizadas.

*pFactory*<br/>
Um ponteiro para a fábrica de transição, que cria transições personalizadas. Pode ser NULO para transições padrão.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se um objeto COM de transição foi criado com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Esta é uma função virtual pura que deve ser substituída em uma classe derivada. É chamado pela estrutura para instanciar o objeto de transição COM subjacente.

## <a name="cbasetransitiongetendkeyframe"></a><a name="getendkeyframe"></a>CBaseTransition::GetEndKeyframe

Retorna o quadro-chave iniciar.

```
CBaseKeyFrame* GetEndKeyframe();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro válido para um quadro-chave ou NULL se uma transição não for inserida entre quadros-chave.

### <a name="remarks"></a>Comentários

Este método pode ser usado para acessar um objeto de quadro-chave que foi previamente definido por SetKeyframes. É chamado por código de alto nível quando transições estão sendo adicionadas ao storyboard.

## <a name="cbasetransitiongetrelatedvariable"></a><a name="getrelatedvariable"></a>CBaseTransition::GetRelatedVariable

Retorna um ponteiro para variável relacionada.

```
CAnimationVariable* GetRelatedVariable();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro válido para a variável de animação ou NULL se uma variável de animação não tiver sido definida por SetRelatedVariable.

### <a name="remarks"></a>Comentários

Este é um acessório para variável de animação relacionada.

## <a name="cbasetransitiongetstartkeyframe"></a><a name="getstartkeyframe"></a>CBaseTransition::GetStartKeyframe

Retorna o quadro-chave iniciar.

```
CBaseKeyFrame* GetStartKeyframe();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro válido para um quadro-chave ou NULL se uma transição não for iniciada após um quadro-chave.

### <a name="remarks"></a>Comentários

Este método pode ser usado para acessar um objeto de quadro-chave que foi previamente definido por SetKeyframes. É chamado por código de alto nível quando transições estão sendo adicionadas ao storyboard.

## <a name="cbasetransitiongettransition"></a><a name="gettransition"></a>Transição de cbase::gettransition

Retorna um ponteiro para o objeto de transição COM subjacente.

```
IUIAnimationTransition* GetTransition(
    IUIAnimationTransitionLibrary* pLibrary,
    IUIAnimationTransitionFactory* pFactory);

IUIAnimationTransition* GetTransition();
```

### <a name="parameters"></a>Parâmetros

*pBiblioteca*<br/>
Um ponteiro para a biblioteca de transição, que cria transições padrão. Pode ser NULL para transições personalizadas.

*pFactory*<br/>
Um ponteiro para a fábrica de transição, que cria transições personalizadas. Pode ser NULO para transições padrão.

### <a name="return-value"></a>Valor retornado

Um ponteiro válido para IUIAnimationTransition ou NULL se a transição subjacente não puder ser criada.

### <a name="remarks"></a>Comentários

Este método retorna um ponteiro para o objeto de transição COM subjacente e o cria se necessário.

## <a name="cbasetransitiongettype"></a><a name="gettype"></a>CBaseTransition::GetType

Tipo de transição de retorno.

```
TRANSITION_TYPE GetType() const;
```

### <a name="return-value"></a>Valor retornado

Um dos valores TRANSITION_TYPE enumerados.

### <a name="remarks"></a>Comentários

Este método pode ser usado para identificar um objeto de transição por seu tipo. O tipo é definido em um construtor em uma classe derivada.

## <a name="cbasetransitionisadded"></a><a name="isadded"></a>Transição de cbase::isadded

Conta se uma transição foi adicionada a um storyboard.

```
BOOL IsAdded();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se uma transição foi adicionada a um storyboard, caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este sinalizador é definido internamente quando o código de nível superior adiciona transições ao storyboard.

## <a name="cbasetransitionm_badded"></a><a name="m_badded"></a>CBaseTransition::m_bAdded

Especifica se uma transição foi adicionada a um storyboard.

```
BOOL m_bAdded;
```

## <a name="cbasetransitionm_pendkeyframe"></a><a name="m_pendkeyframe"></a>Transição de CBase::m_pEndKeyframe

Armazena um ponteiro para o quadro-chave que especifica o fim da transição.

```
CBaseKeyFrame* m_pEndKeyframe;
```

## <a name="cbasetransitionm_prelatedvariable"></a><a name="m_prelatedvariable"></a>Transição de cbase::m_pRelatedVariable

Um ponteiro para uma variável de animação, que é animado com a transição armazenada em m_transition.

```
CAnimationVariable* m_pRelatedVariable;
```

## <a name="cbasetransitionm_pstartkeyframe"></a><a name="m_pstartkeyframe"></a>Transição de cbase::m_pStartKeyframe

Armazena um ponteiro para o quadro-chave que especifica o início da transição.

```
CBaseKeyFrame* m_pStartKeyframe;
```

## <a name="cbasetransitionm_transition"></a><a name="m_transition"></a>Transição de CBase::m_transition

Armazena um ponteiro para IUIAnimationTransition. NULL se um objeto de transição COM não tiver sido criado.

```
ATL::CComPtr<IUIAnimationTransition> m_transition;
```

## <a name="cbasetransitionm_type"></a><a name="m_type"></a>CBaseTransition::m_type

Armazena o tipo de transição.

```
TRANSITION_TYPE m_type;
```

## <a name="cbasetransitionsetkeyframes"></a><a name="setkeyframes"></a>CBaseTransition::SetKeyframes

Define quadros-chave para uma transição.

```
void SetKeyframes(
    CBaseKeyFrame* pStart = NULL,
    CBaseKeyFrame* pEnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*Pstart*<br/>
Um quadro-chave que especifica o início da transição.

*Pend*<br/>
Um quadro-chave que especifica o fim da transição.

### <a name="remarks"></a>Comentários

Este método diz a transição para iniciar após quadro-chave especificado e, opcionalmente, se pEnd não for NULL, termine antes do quadro-chave especificado. Se a transição foi criada com um parâmetro de duração especificado, essa duração será sobressacada com a duração do tempo entre os quadros-chave de início e de fim.

## <a name="cbasetransitionsetrelatedvariable"></a><a name="setrelatedvariable"></a>Transição de cBase::SetRelatedVariable

Estabelece uma relação entre a variável animação e a transição.

```
void SetRelatedVariable(CAnimationVariable* pVariable);
```

### <a name="parameters"></a>Parâmetros

*pVariable*<br/>
Um ponteiro para a variável de animação relacionada.

### <a name="remarks"></a>Comentários

Estabelece uma relação entre a variável animação e a transição. Uma transição pode ser aplicada apenas a uma variável.

## <a name="cbasetransitiontransition_type-enumeration"></a><a name="transition_type_enumeration"></a>CBaseTransition::enumeração TRANSITION_TYPE

Define os tipos de transição atualmente suportados pela implementação do MFC da API de animação do Windows.

```
enum TRANSITION_TYPE;
```

### <a name="remarks"></a>Comentários

Um tipo de transição é definido no construtor de transição específica. Por exemplo, CSinusoidalTransitionFromRange define seu tipo para SINUSOIDAL_FROM_RANGE.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
