---
title: Classe CBaseTransition | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
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
- CBaseTransition class
ms.assetid: dfe84007-bbc5-43b7-b5b8-fae9145573bf
caps.latest.revision: 17
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: b979d03587ada42486d0462733dfe6fd22f9f7cc
ms.lasthandoff: 02/25/2017

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
|[Enumeração CBaseTransition::TRANSITION_TYPE](#transition_type_enumeration)|Define os tipos de transição atualmente suportados pela implementação da API de animação do Windows MFC.|  
  
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
|[CBaseTransition::GetTransition](#gettransition)|Sobrecarregado. Retorna um ponteiro para o objeto de transição COM subjacente.|  
|[CBaseTransition::GetType](#gettype)|Retorna o tipo de transição.|  
|[CBaseTransition::IsAdded](#isadded)|Informa se uma transição foi adicionada a um storyboard.|  
|[CBaseTransition::SetKeyframes](#setkeyframes)|Define os quadros-chave para uma transição.|  
|[CBaseTransition::SetRelatedVariable](#setrelatedvariable)|Estabelece uma relação entre a variável de animação e transição.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBaseTransition::m_bAdded](#m_badded)|Especifica se uma transição foi adicionada a um storyboard.|  
|[CBaseTransition::m_pEndKeyframe](#m_pendkeyframe)|Armazena um ponteiro para o quadro-chave que especifica o final da transição.|  
|[CBaseTransition::m_pRelatedVariable](#m_prelatedvariable)|Um ponteiro para uma variável de animação, que é animado na transição armazenados em m_transition.|  
|[CBaseTransition::m_pStartKeyframe](#m_pstartkeyframe)|Armazena um ponteiro para o quadro-chave que especifica o início da transição.|  
|[CBaseTransition::m_transition](#m_transition)|Armazena um ponteiro para IUIAnimationTransition. NULL se um objeto de transição COM não foi criado.|  
|[CBaseTransition::m_type](#m_type)|Armazena o tipo de transição.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe encapsula a interface IUIAnimationTransition e serve como uma classe base para todas as transições.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CBaseTransition`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="_dtorcbasetransition"></a>CBaseTransition:: ~ CBaseTransition  
 O destruidor. Chamado quando um objeto de transição está sendo destruído.  
  
```  
virtual ~CBaseTransition();
```  
  
##  <a name="addtostoryboard"></a>CBaseTransition::AddToStoryboard  
 Adiciona uma transição para um storyboard.  
  
```  
BOOL AddToStoryboard(IUIAnimationStoryboard* pStoryboard);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStoryboard`  
 Um ponteiro ao storyboard, que será animada a variável relacionada.  
  
### <a name="return-value"></a>Valor de retorno  
 VERDADEIRO se a transição foi adicionada com êxito a um storyboard.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a transição para a variável relacionada no storyboard. Se esta for a primeira transição aplicada a essa variável nesse storyboard, a transição começa no início do storyboard. Caso contrário, a transição é acrescentada à transição mais recentemente adicionada à variável.  
  
##  <a name="addtostoryboardatkeyframes"></a>CBaseTransition::AddToStoryboardAtKeyframes  
 Adiciona uma transição para um storyboard.  
  
```  
BOOL AddToStoryboardAtKeyframes(IUIAnimationStoryboard* pStoryboard);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStoryboard`  
 Um ponteiro ao storyboard, que será animada a variável relacionada.  
  
### <a name="return-value"></a>Valor de retorno  
 VERDADEIRO se a transição foi adicionada com êxito a um storyboard.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a transição para a variável relacionada no storyboard. Se o quadro-chave inicial foi especificado, a transição começa nesse quadro chave. Se o quadro-chave final foi especificado, a transição começa no quadro-chave de início e e para o quadro-chave final. Se a transição foi criada com um parâmetro de duração especificado, duração será substituída com a duração de tempo entre os quadros-chave inicial e final. Se nenhum quadro chave for especificado, a transição é acrescentada à transição mais recentemente adicionada à variável.  
  
##  <a name="cbasetransition"></a>CBaseTransition::CBaseTransition  
 Constrói um objeto transtion base.  
  
```  
CBaseTransition();
```  
  
##  <a name="clear"></a>CBaseTransition::Clear  
 Versões encapsuladas objeto IUIAnimationTransition COM.  
  
```  
void Clear();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método deve ser chamado do método de criação de uma classe derivada para evitar vazamento de interface IUITransition.  
  
##  <a name="create"></a>CBaseTransition::Create  
 Cria uma transição de COM.  
  
```  
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,  
    IUIAnimationTransitionFactory* pFactory) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pLibrary`  
 Um ponteiro para a biblioteca de transição, que cria transições padrão. Ele pode ser NULL para transições personalizadas.  
  
 `pFactory`  
 Um ponteiro para a fábrica de transição, que cria transições personalizadas. Ele pode ser NULL para transições padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 VERDADEIRO se um objeto de transição COM foi criado com êxito; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Isso é uma função virtual pura que deve ser substituída em uma classe derivada. Ele é chamado pela estrutura para instanciar o objeto de transição COM subjacente.  
  
##  <a name="getendkeyframe"></a>CBaseTransition::GetEndKeyframe  
 Retorna o quadro-chave de início.  
  
```  
CBaseKeyFrame* GetEndKeyframe();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro válido para um quadro-chave, ou nulo se não deve ser inserida uma transição entre quadros-chave.  
  
### <a name="remarks"></a>Comentários  
 Esse método pode ser usado para acessar um objeto de quadro-chave que estava anteriormente definido pela SetKeyframes. Ele é chamado pelo código de nível superior quando transições estão sendo adicionadas ao storyboard.  
  
##  <a name="getrelatedvariable"></a>CBaseTransition::GetRelatedVariable  
 Retorna um ponteiro para a variável relacionado.  
  
```  
CAnimationVariable* GetRelatedVariable();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro válido para a variável de animação, ou nulo se não tiver sido definida uma variável de animação por SetRelatedVariable.  
  
### <a name="remarks"></a>Comentários  
 Esse é um acessador a variável de animação relacionados.  
  
##  <a name="getstartkeyframe"></a>CBaseTransition::GetStartKeyframe  
 Retorna o quadro-chave de início.  
  
```  
CBaseKeyFrame* GetStartKeyframe();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro válido para um quadro-chave ou NULL se uma transição não deve iniciar depois de um quadro-chave.  
  
### <a name="remarks"></a>Comentários  
 Esse método pode ser usado para acessar um objeto de quadro-chave que estava anteriormente definido pela SetKeyframes. Ele é chamado pelo código de nível superior quando transições estão sendo adicionadas ao storyboard.  
  
##  <a name="gettransition"></a>CBaseTransition::GetTransition  
 Retorna um ponteiro para o objeto de transição COM subjacente.  
  
```  
IUIAnimationTransition* GetTransition(
    IUIAnimationTransitionLibrary* pLibrary,  
    IUIAnimationTransitionFactory* pFactory);  
  
IUIAnimationTransition* GetTransition();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pLibrary`  
 Um ponteiro para a biblioteca de transição, que cria transições padrão. Ele pode ser NULL para transições personalizadas.  
  
 `pFactory`  
 Um ponteiro para a fábrica de transição, que cria transições personalizadas. Ele pode ser NULL para transições padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 Não é possível criar um ponteiro válido IUIAnimationTransition ou nulo se a transição de base.  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna um ponteiro para o objeto subjacente de transição COM e cria-se necessário.  
  
##  <a name="gettype"></a>CBaseTransition::GetType  
 Retorna o tipo de transição.  
  
```  
TRANSITION_TYPE GetType() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma das TRANSITION_TYPE valores enumerados.  
  
### <a name="remarks"></a>Comentários  
 Esse método pode ser usado para identificar um objeto de transição por seu tipo. O tipo é definido em um construtor em uma classe derivada.  
  
##  <a name="isadded"></a>CBaseTransition::IsAdded  
 Informa se uma transição foi adicionada a um storyboard.  
  
```  
BOOL IsAdded();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se uma transição foi adicionada a um storyboard, caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Esse sinalizador é definido internamente quando o código de nível superior adiciona transições para o storyboard.  
  
##  <a name="m_badded"></a>CBaseTransition::m_bAdded  
 Especifica se uma transição foi adicionada a um storyboard.  
  
```  
BOOL m_bAdded;  
```  
  
##  <a name="m_pendkeyframe"></a>CBaseTransition::m_pEndKeyframe  
 Armazena um ponteiro para o quadro-chave que especifica o final da transição.  
  
```  
CBaseKeyFrame* m_pEndKeyframe;  
```  
  
##  <a name="m_prelatedvariable"></a>CBaseTransition::m_pRelatedVariable  
 Um ponteiro para uma variável de animação, que é animado na transição armazenados em m_transition.  
  
```  
CAnimationVariable* m_pRelatedVariable;  
```  
  
##  <a name="m_pstartkeyframe"></a>CBaseTransition::m_pStartKeyframe  
 Armazena um ponteiro para o quadro-chave que especifica o início da transição.  
  
```  
CBaseKeyFrame* m_pStartKeyframe;  
```  
  
##  <a name="m_transition"></a>CBaseTransition::m_transition  
 Armazena um ponteiro para IUIAnimationTransition. NULL se um objeto de transição COM não foi criado.  
  
```  
ATL::CComPtr<IUIAnimationTransition> m_transition;  
```  
  
##  <a name="m_type"></a>CBaseTransition::m_type  
 Armazena o tipo de transição.  
  
```  
TRANSITION_TYPE m_type;  
```  
  
##  <a name="setkeyframes"></a>CBaseTransition::SetKeyframes  
 Define os quadros-chave para uma transição.  
  
```  
void SetKeyframes(
    CBaseKeyFrame* pStart = NULL,  
    CBaseKeyFrame* pEnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStart`  
 Um quadro-chave que especifica o início da transição.  
  
 `pEnd`  
 Um quadro-chave que especifica o final da transição.  
  
### <a name="remarks"></a>Comentários  
 Esse método informa a transição para iniciar após o quadro-chave especificada e, opcionalmente, se pendentes não for nulo, terminar antes do quadro-chave especificado. Se a transição foi criada com um parâmetro de duração especificado, duração será substituída com a duração de tempo entre os quadros-chave inicial e final.  
  
##  <a name="setrelatedvariable"></a>CBaseTransition::SetRelatedVariable  
 Estabelece uma relação entre a variável de animação e transição.  
  
```  
void SetRelatedVariable(CAnimationVariable* pVariable);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pVariable`  
 Um ponteiro para a variável de animação relacionados.  
  
### <a name="remarks"></a>Comentários  
 Estabelece uma relação entre a variável de animação e transição. Uma transição pode ser aplicada somente a uma variável.  
  
##  <a name="transition_type_enumeration"></a>Enumeração CBaseTransition::TRANSITION_TYPE  
 Define os tipos de transição atualmente suportados pela implementação da API de animação do Windows MFC.  
  
```  
enum TRANSITION_TYPE;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo de transição é definido no construtor da transição específica. Por exemplo, CSinusoidalTransitionFromRange define seu tipo como SINUSOIDAL_FROM_RANGE.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

