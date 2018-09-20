---
title: Classe CBaseTransition | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 16c838d9ffbef8ace933990fdaa88dc84c1c56ee
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46385489"
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
|[Enumeração CBaseTransition::TRANSITION_TYPE](#transition_type_enumeration)|Define os tipos de transição atualmente suportados pela implementação MFC de API de animação do Windows.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CBaseTransition::CBaseTransition](#cbasetransition)|Constrói um objeto transtion base.|
|[CBaseTransition:: ~ CBaseTransition](#cbasetransition__~cbasetransition)|O destruidor. Chamado quando um objeto de transição está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CBaseTransition::AddToStoryboard](#addtostoryboard)|Adiciona uma transição para um storyboard.|
|[CBaseTransition::AddToStoryboardAtKeyframes](#addtostoryboardatkeyframes)|Adiciona uma transição para um storyboard.|
|[CBaseTransition::Clear](#clear)|Versões encapsuladas objeto IUIAnimationTransition COM.|
|[CBaseTransition::Create](#create)|Cria uma transição de COM.|
|[CBaseTransition::GetEndKeyframe](#getendkeyframe)|Retorna o quadro-chave de início.|
|[CBaseTransition::GetRelatedVariable](#getrelatedvariable)|Retorna um ponteiro para a variável relacionado.|
|[CBaseTransition::GetStartKeyframe](#getstartkeyframe)|Retorna o quadro-chave de início.|
|[CBaseTransition::GetTransition](#gettransition)|Sobrecarregado. Retorna um ponteiro para o objeto subjacente de transição de COM.|
|[CBaseTransition::GetType](#gettype)|Retorna o tipo de transição.|
|[CBaseTransition::IsAdded](#isadded)|Informa se uma transição foi adicionada a um storyboard.|
|[CBaseTransition::SetKeyframes](#setkeyframes)|Define os quadros-chave para uma transição.|
|[CBaseTransition::SetRelatedVariable](#setrelatedvariable)|Estabelece uma relação entre a variável de animação e fazer a transição.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CBaseTransition::m_bAdded](#m_badded)|Especifica se uma transição foi adicionada a um storyboard.|
|[CBaseTransition::m_pEndKeyframe](#m_pendkeyframe)|Armazena um ponteiro para o quadro-chave que especifica o final da transição.|
|[CBaseTransition::m_pRelatedVariable](#m_prelatedvariable)|Um ponteiro para uma variável de animação, que é animado na transição armazenados em m_transition.|
|[CBaseTransition::m_pStartKeyframe](#m_pstartkeyframe)|Armazena um ponteiro para o quadro-chave que especifica o início da transição.|
|[CBaseTransition::m_transition](#m_transition)|Armazena um ponteiro para IUIAnimationTransition. NULL se não tiver sido criado um objeto de transição de COM.|
|[CBaseTransition::m_type](#m_type)|Armazena o tipo de transição.|

## <a name="remarks"></a>Comentários

Essa classe encapsula a interface IUIAnimationTransition e serve como uma classe base para todas as transições.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CBaseTransition`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

##  <a name="_dtorcbasetransition"></a>  CBaseTransition:: ~ CBaseTransition

O destruidor. Chamado quando um objeto de transição está sendo destruído.

```
virtual ~CBaseTransition();
```

##  <a name="addtostoryboard"></a>  CBaseTransition::AddToStoryboard

Adiciona uma transição para um storyboard.

```
BOOL AddToStoryboard(IUIAnimationStoryboard* pStoryboard);
```

### <a name="parameters"></a>Parâmetros

*pStoryboard*<br/>
Um ponteiro para criar um storyboard, que será animada a variável relacionada.

### <a name="return-value"></a>Valor de retorno

TRUE se a transição foi adicionada com êxito a um storyboard.

### <a name="remarks"></a>Comentários

Aplica-se a transição para a variável relacionada no storyboard. Se esta for a primeira transição aplicada a essa variável nesse storyboard, a transição começa no início do storyboard. Caso contrário, a transição é acrescentada à transição mais recentemente adicionada à variável.

##  <a name="addtostoryboardatkeyframes"></a>  CBaseTransition::AddToStoryboardAtKeyframes

Adiciona uma transição para um storyboard.

```
BOOL AddToStoryboardAtKeyframes(IUIAnimationStoryboard* pStoryboard);
```

### <a name="parameters"></a>Parâmetros

*pStoryboard*<br/>
Um ponteiro para criar um storyboard, que será animada a variável relacionada.

### <a name="return-value"></a>Valor de retorno

TRUE se a transição foi adicionada com êxito a um storyboard.

### <a name="remarks"></a>Comentários

Aplica-se a transição para a variável relacionada no storyboard. Se o quadro-chave inicial foi especificado, a transição começa em desse quadro-chave. Se o quadro-chave final foi especificado, a transição começa no quadro-chave inicial e parará no quadro-chave final. Se a transição foi criada com um parâmetro de duração especificado, essa duração é substituída com a duração de tempo entre os quadros-chave inicial e final. Se nenhum quadro chave tiver sido especificada, a transição é acrescentada à transição mais recentemente adicionada à variável.

##  <a name="cbasetransition"></a>  CBaseTransition::CBaseTransition

Constrói um objeto transtion base.

```
CBaseTransition();
```

##  <a name="clear"></a>  CBaseTransition::Clear

Versões encapsuladas objeto IUIAnimationTransition COM.

```
void Clear();
```

### <a name="remarks"></a>Comentários

Esse método deve ser chamado do método de criação de uma classe derivada fim de evitar vazamento de interface IUITransition.

##  <a name="create"></a>  CBaseTransition::Create

Cria uma transição de COM.

```
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,
    IUIAnimationTransitionFactory* pFactory) = 0;
```

### <a name="parameters"></a>Parâmetros

*pLibrary*<br/>
Um ponteiro para a biblioteca de transição, que cria as transições de padrão. Ele pode ser NULL para transições personalizadas.

*pFactory*<br/>
Um ponteiro para a fábrica de transição, que cria as transições de personalizado. Ele pode ser NULL para transições padrão.

### <a name="return-value"></a>Valor de retorno

TRUE se a transição de uma objeto COM foi criado com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Isso é uma função virtual pura que deve ser substituída em uma classe derivada. Ele é chamado pelo framework para instanciar o objeto de transição COM subjacente.

##  <a name="getendkeyframe"></a>  CBaseTransition::GetEndKeyframe

Retorna o quadro-chave de início.

```
CBaseKeyFrame* GetEndKeyframe();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro válido para um quadro-chave, ou nulo se não deve ser inserida uma transição entre quadros-chave.

### <a name="remarks"></a>Comentários

Esse método pode ser usado para acessar um objeto de quadro-chave que foi anteriormente definido pela SetKeyframes. Ele é chamado pelo código de nível superior quando as transições que estão sendo adicionadas ao storyboard.

##  <a name="getrelatedvariable"></a>  CBaseTransition::GetRelatedVariable

Retorna um ponteiro para a variável relacionado.

```
CAnimationVariable* GetRelatedVariable();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro válido para a variável de animação ou NULL se uma variável de animação não tiver sido definida por SetRelatedVariable.

### <a name="remarks"></a>Comentários

Esse é um acessador para a variável de animação relacionados.

##  <a name="getstartkeyframe"></a>  CBaseTransition::GetStartKeyframe

Retorna o quadro-chave de início.

```
CBaseKeyFrame* GetStartKeyframe();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro válido para um quadro-chave, ou nulo se não deve começar a uma transição após um quadro-chave.

### <a name="remarks"></a>Comentários

Esse método pode ser usado para acessar um objeto de quadro-chave que foi anteriormente definido pela SetKeyframes. Ele é chamado pelo código de nível superior quando as transições que estão sendo adicionadas ao storyboard.

##  <a name="gettransition"></a>  CBaseTransition::GetTransition

Retorna um ponteiro para o objeto subjacente de transição de COM.

```
IUIAnimationTransition* GetTransition(
    IUIAnimationTransitionLibrary* pLibrary,
    IUIAnimationTransitionFactory* pFactory);

IUIAnimationTransition* GetTransition();
```

### <a name="parameters"></a>Parâmetros

*pLibrary*<br/>
Um ponteiro para a biblioteca de transição, que cria as transições de padrão. Ele pode ser NULL para transições personalizadas.

*pFactory*<br/>
Um ponteiro para a fábrica de transição, que cria as transições de personalizado. Ele pode ser NULL para transições padrão.

### <a name="return-value"></a>Valor de retorno

Um ponteiro válido para IUIAnimationTransition ou nulo se a transição de base não pode ser criado.

### <a name="remarks"></a>Comentários

Esse método retorna um ponteiro para o objeto subjacente de transição de COM e o cria se necessário.

##  <a name="gettype"></a>  CBaseTransition::GetType

Retorna o tipo de transição.

```
TRANSITION_TYPE GetType() const;
```

### <a name="return-value"></a>Valor de retorno

Um dos TRANSITION_TYPE valores enumerados.

### <a name="remarks"></a>Comentários

Esse método pode ser usado para identificar um objeto de transição por seu tipo. O tipo é definido em um construtor em uma classe derivada.

##  <a name="isadded"></a>  CBaseTransition::IsAdded

Informa se uma transição foi adicionada a um storyboard.

```
BOOL IsAdded();
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se uma transição foi adicionada a um storyboard, caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse sinalizador é definido internamente quando o código de nível superior adiciona as transições para executar o storyboard.

##  <a name="m_badded"></a>  CBaseTransition::m_bAdded

Especifica se uma transição foi adicionada a um storyboard.

```
BOOL m_bAdded;
```

##  <a name="m_pendkeyframe"></a>  CBaseTransition::m_pEndKeyframe

Armazena um ponteiro para o quadro-chave que especifica o final da transição.

```
CBaseKeyFrame* m_pEndKeyframe;
```

##  <a name="m_prelatedvariable"></a>  CBaseTransition::m_pRelatedVariable

Um ponteiro para uma variável de animação, que é animado na transição armazenados em m_transition.

```
CAnimationVariable* m_pRelatedVariable;
```

##  <a name="m_pstartkeyframe"></a>  CBaseTransition::m_pStartKeyframe

Armazena um ponteiro para o quadro-chave que especifica o início da transição.

```
CBaseKeyFrame* m_pStartKeyframe;
```

##  <a name="m_transition"></a>  CBaseTransition::m_transition

Armazena um ponteiro para IUIAnimationTransition. NULL se não tiver sido criado um objeto de transição de COM.

```
ATL::CComPtr<IUIAnimationTransition> m_transition;
```

##  <a name="m_type"></a>  CBaseTransition::m_type

Armazena o tipo de transição.

```
TRANSITION_TYPE m_type;
```

##  <a name="setkeyframes"></a>  CBaseTransition::SetKeyframes

Define os quadros-chave para uma transição.

```
void SetKeyframes(
    CBaseKeyFrame* pStart = NULL,
    CBaseKeyFrame* pEnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*pStart*<br/>
Um quadro-chave que especifica o início da transição.

*Pendente*<br/>
Um quadro-chave que especifica o final da transição.

### <a name="remarks"></a>Comentários

Esse método informa à transição para iniciar após o quadro-chave especificada e, opcionalmente, se pendente não for nulo, terminar antes do quadro-chave especificado. Se a transição foi criada com um parâmetro de duração especificado, essa duração é substituída com a duração de tempo entre os quadros-chave inicial e final.

##  <a name="setrelatedvariable"></a>  CBaseTransition::SetRelatedVariable

Estabelece uma relação entre a variável de animação e fazer a transição.

```
void SetRelatedVariable(CAnimationVariable* pVariable);
```

### <a name="parameters"></a>Parâmetros

*pVariable*<br/>
Um ponteiro para a variável de animação relacionados.

### <a name="remarks"></a>Comentários

Estabelece uma relação entre a variável de animação e fazer a transição. Uma transição pode ser aplicada somente a uma variável.

##  <a name="transition_type_enumeration"></a>  Enumeração CBaseTransition::TRANSITION_TYPE

Define os tipos de transição atualmente suportados pela implementação MFC de API de animação do Windows.

```
enum TRANSITION_TYPE;
```

### <a name="remarks"></a>Comentários

Um tipo de transição é definido no construtor da transição específica. Por exemplo, o CSinusoidalTransitionFromRange define seu tipo como SINUSOIDAL_FROM_RANGE.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
