---
title: Classe CAnimationController | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAnimationController
- AFXANIMATIONCONTROLLER/CAnimationController
- AFXANIMATIONCONTROLLER/CAnimationController::CAnimationController
- AFXANIMATIONCONTROLLER/CAnimationController::AddAnimationObject
- AFXANIMATIONCONTROLLER/CAnimationController::AddKeyframeToGroup
- AFXANIMATIONCONTROLLER/CAnimationController::AnimateGroup
- AFXANIMATIONCONTROLLER/CAnimationController::CleanUpGroup
- AFXANIMATIONCONTROLLER/CAnimationController::CreateKeyframe
- AFXANIMATIONCONTROLLER/CAnimationController::EnableAnimationManagerEvent
- AFXANIMATIONCONTROLLER/CAnimationController::EnableAnimationTimerEventHandler
- AFXANIMATIONCONTROLLER/CAnimationController::EnablePriorityComparisonHandler
- AFXANIMATIONCONTROLLER/CAnimationController::EnableStoryboardEventHandler
- AFXANIMATIONCONTROLLER/CAnimationController::FindAnimationGroup
- AFXANIMATIONCONTROLLER/CAnimationController::FindAnimationObject
- AFXANIMATIONCONTROLLER/CAnimationController::GetKeyframeStoryboardStart
- AFXANIMATIONCONTROLLER/CAnimationController::GetUIAnimationManager
- AFXANIMATIONCONTROLLER/CAnimationController::GetUIAnimationTimer
- AFXANIMATIONCONTROLLER/CAnimationController::GetUITransitionFactory
- AFXANIMATIONCONTROLLER/CAnimationController::GetUITransitionLibrary
- AFXANIMATIONCONTROLLER/CAnimationController::IsAnimationInProgress
- AFXANIMATIONCONTROLLER/CAnimationController::IsValid
- AFXANIMATIONCONTROLLER/CAnimationController::OnAnimationIntegerValueChanged
- AFXANIMATIONCONTROLLER/CAnimationController::OnAnimationManagerStatusChanged
- AFXANIMATIONCONTROLLER/CAnimationController::OnAnimationTimerPostUpdate
- AFXANIMATIONCONTROLLER/CAnimationController::OnAnimationTimerPreUpdate
- AFXANIMATIONCONTROLLER/CAnimationController::OnAnimationTimerRenderingTooSlow
- AFXANIMATIONCONTROLLER/CAnimationController::OnAnimationValueChanged
- AFXANIMATIONCONTROLLER/CAnimationController::OnBeforeAnimationStart
- AFXANIMATIONCONTROLLER/CAnimationController::OnHasPriorityCancel
- AFXANIMATIONCONTROLLER/CAnimationController::OnHasPriorityCompress
- AFXANIMATIONCONTROLLER/CAnimationController::OnHasPriorityConclude
- AFXANIMATIONCONTROLLER/CAnimationController::OnHasPriorityTrim
- AFXANIMATIONCONTROLLER/CAnimationController::OnStoryboardStatusChanged
- AFXANIMATIONCONTROLLER/CAnimationController::OnStoryboardUpdated
- AFXANIMATIONCONTROLLER/CAnimationController::RemoveAllAnimationGroups
- AFXANIMATIONCONTROLLER/CAnimationController::RemoveAnimationGroup
- AFXANIMATIONCONTROLLER/CAnimationController::RemoveAnimationObject
- AFXANIMATIONCONTROLLER/CAnimationController::RemoveTransitions
- AFXANIMATIONCONTROLLER/CAnimationController::ScheduleGroup
- AFXANIMATIONCONTROLLER/CAnimationController::SetRelatedWnd
- AFXANIMATIONCONTROLLER/CAnimationController::UpdateAnimationManager
- AFXANIMATIONCONTROLLER/CAnimationController::CleanUpGroup
- AFXANIMATIONCONTROLLER/CAnimationController::OnAfterSchedule
- AFXANIMATIONCONTROLLER/CAnimationController::gkeyframeStoryboardStart
- AFXANIMATIONCONTROLLER/CAnimationController::m_bIsValid
- AFXANIMATIONCONTROLLER/CAnimationController::m_lstAnimationGroups
- AFXANIMATIONCONTROLLER/CAnimationController::m_pAnimationManager
- AFXANIMATIONCONTROLLER/CAnimationController::m_pAnimationTimer
- AFXANIMATIONCONTROLLER/CAnimationController::m_pRelatedWnd
- AFXANIMATIONCONTROLLER/CAnimationController::m_pTransitionFactory
- AFXANIMATIONCONTROLLER/CAnimationController::m_pTransitionLibrary
dev_langs:
- C++
helpviewer_keywords:
- CAnimationController class
ms.assetid: ed294c98-695e-40a6-b940-33ef1d40aa6b
caps.latest.revision: 18
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 2cf243c25f14ba016f6f30af264322c658e7322c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="canimationcontroller-class"></a>Classe CAnimationController
Implementa o controlador de animação, que fornece uma interface central para criar e gerenciar animações.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CAnimationController : public CObject;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationController::CAnimationController](#canimationcontroller)|Constrói um controlador de animação.|  
|[CAnimationController:: ~ CAnimationController](#canimationcontroller__~canimationcontroller)|O destruidor. Chamado quando o objeto de controlador de animação está sendo destruído.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationController::AddAnimationObject](#addanimationobject)|Adiciona um objeto de animação a um grupo ao qual pertence o controlador de animação.|  
|[CAnimationController::AddKeyframeToGroup](#addkeyframetogroup)|Adiciona um quadro-chave ao grupo.|  
|[CAnimationController::AnimateGroup](#animategroup)|Prepara um grupo para executar a animação e, opcionalmente, a agenda.|  
|[CAnimationController::CleanUpGroup](#cleanupgroup)|Sobrecarregado. Chamado pela estrutura para limpar o grupo quando animação foi agendada.|  
|[CAnimationController::CreateKeyframe](#createkeyframe)|Sobrecarregado. Cria um quadro-chave que depende de transição e o adiciona ao grupo especificado.|  
|[CAnimationController::EnableAnimationManagerEvent](#enableanimationmanagerevent)|Define ou libera um manipulador para chamar quando o status do Gerenciador de animação é alterado.|  
|[CAnimationController::EnableAnimationTimerEventHandler](#enableanimationtimereventhandler)|Define ou libera um manipulador para eventos de tempo e o manipulador para atualizações de tempo.|  
|[CAnimationController::EnablePriorityComparisonHandler](#enableprioritycomparisonhandler)|Define ou libera o identificador de comparação de prioridade para chamar para determinar se um storyboard agendado pode ser cancelado, concluído, cortado ou compactado.|  
|[CAnimationController::EnableStoryboardEventHandler](#enablestoryboardeventhandler)|Define ou libera um manipulador para eventos de status e a atualização do storyboard.|  
|[CAnimationController::FindAnimationGroup](#findanimationgroup)|Sobrecarregado. Localiza um grupo de animação por seu storyboard.|  
|[CAnimationController::FindAnimationObject](#findanimationobject)|Localiza o objeto de animação que contém uma variável de animação especificado.|  
|[CAnimationController::GetKeyframeStoryboardStart](#getkeyframestoryboardstart)|Retorna um quadro-chave que identifica o início do storyboard.|  
|[CAnimationController::GetUIAnimationManager](#getuianimationmanager)|Fornece acesso ao objeto de IUIAnimationManager encapsulado.|  
|[CAnimationController::GetUIAnimationTimer](#getuianimationtimer)|Fornece acesso ao objeto de IUIAnimationTimer encapsulado.|  
|[CAnimationController::GetUITransitionFactory](#getuitransitionfactory)|Um ponteiro de interface IUIAnimationTransitionFactory ou NULL, se a falha na criação da biblioteca de transição.|  
|[CAnimationController::GetUITransitionLibrary](#getuitransitionlibrary)|Fornece acesso ao objeto de IUIAnimationTransitionLibrary encapsulado.|  
|[CAnimationController::IsAnimationInProgress](#isanimationinprogress)|Informa se pelo menos um grupo é Reproduzir animação.|  
|[CAnimationController::IsValid](#isvalid)|Informa se o controlador de animação é válido.|  
|[CAnimationController::OnAnimationIntegerValueChanged](#onanimationintegervaluechanged)|Chamado pela estrutura quando o valor inteiro da variável de animação é alterado.|  
|[CAnimationController::OnAnimationManagerStatusChanged](#onanimationmanagerstatuschanged)|Chamado pela estrutura em resposta a eventos de status alterado do Gerenciador de animação.|  
|[CAnimationController::OnAnimationTimerPostUpdate](#onanimationtimerpostupdate)|Chamado pela estrutura após uma atualização de animação.|  
|[CAnimationController::OnAnimationTimerPreUpdate](#onanimationtimerpreupdate)|Chamado pela estrutura antes do início de uma atualização de animação.|  
|[CAnimationController::OnAnimationTimerRenderingTooSlow](#onanimationtimerrenderingtooslow)|Chamado pela estrutura quando a taxa de quadros de renderização para uma animação fica abaixo de uma taxa de quadros desejável mínimo.|  
|[CAnimationController::OnAnimationValueChanged](#onanimationvaluechanged)|Chamado pela estrutura quando o valor da variável de animação é alterado.|  
|[CAnimationController::OnBeforeAnimationStart](#onbeforeanimationstart)|Chamado pela estrutura correta antes que a animação seja agendada.|  
|[CAnimationController::OnHasPriorityCancel](#onhasprioritycancel)|Chamado pela estrutura para resolver conflitos de agendamento.|  
|[CAnimationController::OnHasPriorityCompress](#onhasprioritycompress)|Chamado pela estrutura para resolver conflitos de agendamento.|  
|[CAnimationController::OnHasPriorityConclude](#onhaspriorityconclude)|Chamado pela estrutura para resolver conflitos de agendamento.|  
|[CAnimationController::OnHasPriorityTrim](#onhasprioritytrim)|Chamado pela estrutura para resolver conflitos de agendamento.|  
|[CAnimationController::OnStoryboardStatusChanged](#onstoryboardstatuschanged)|Chamado pela estrutura quando o status de storyboard mudou.|  
|[CAnimationController::OnStoryboardUpdated](#onstoryboardupdated)|Chamado pela estrutura quando storyboard tiver sido atualizado.|  
|[CAnimationController::RemoveAllAnimationGroups](#removeallanimationgroups)|Remove todos os grupos de animação do controlador de animação.|  
|[CAnimationController::RemoveAnimationGroup](#removeanimationgroup)|Remove um grupo de animação com a ID especificada do controlador de animação.|  
|[CAnimationController::RemoveAnimationObject](#removeanimationobject)|Remova um objeto de animação do controlador de animação.|  
|[CAnimationController::RemoveTransitions](#removetransitions)|Remove as transições de objetos de animação que pertencem ao grupo especificado.|  
|[CAnimationController::ScheduleGroup](#schedulegroup)|Agenda uma animação.|  
|[CAnimationController::SetRelatedWnd](#setrelatedwnd)|Estabelece uma relação entre o controlador de animação e uma janela.|  
|[CAnimationController::UpdateAnimationManager](#updateanimationmanager)|Direciona o Gerenciador de animação para atualizar os valores de todas as variáveis de animação.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationController::CleanUpGroup](#cleanupgroup)|Sobrecarregado. Um auxiliar que limpa o grupo.|  
|[CAnimationController::OnAfterSchedule](#onafterschedule)|Chamado pela estrutura quando uma animação para o grupo especificado apenas foi agendada.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationController::gkeyframeStoryboardStart](#g_keyframestoryboardstart)|Um quadro-chave que representa o início do storyboard.|  
|[CAnimationController::m_bIsValid](#m_bisvalid)|Especifica se um controlador de animação é válido ou não. Esse membro é definido como FALSE se o sistema operacional atual não oferece suporte a API de animação do Windows.|  
|[CAnimationController::m_lstAnimationGroups](#m_lstanimationgroups)|Uma lista de grupos de animação que pertencem a esse controlador de animação.|  
|[CAnimationController::m_pAnimationManager](#m_panimationmanager)|Armazena um ponteiro para o objeto COM do Gerenciador de animação.|  
|[CAnimationController::m_pAnimationTimer](#m_panimationtimer)|Armazena um ponteiro para o objeto COM do Timer de animação.|  
|[CAnimationController::m_pRelatedWnd](#m_prelatedwnd)|Um ponteiro para um objeto CWnd relacionado, o que pode ser redesenhado automaticamente quando o status do Gerenciador de animação foi alterado ou ocorreu o evento de atualização de post. Pode ser NULL.|  
|[CAnimationController::m_pTransitionFactory](#m_ptransitionfactory)|Armazena um ponteiro para o objeto COM da fábrica de transição.|  
|[CAnimationController::m_pTransitionLibrary](#m_ptransitionlibrary)|Armazena um ponteiro para o objeto COM da biblioteca de transição.|  
  
## <a name="remarks"></a>Comentários  
 A classe CAnimationController é a classe de chave que gerencia as animações. Você pode criar uma ou mais instâncias do controlador de animação em um aplicativo e, opcionalmente, conectar uma instância do controlador de animação a um objeto CWnd usando CAnimationController::SetRelatedWnd. Essa conexão é necessária para enviar mensagens WM_PAINT à janela relacionada automaticamente quando o status do Gerenciador de animação foi alterado ou o timer de animação foi atualizado. Se você não habilitar essa relação, você precisará redesenhar uma janela que exibe uma animação manualmente. Para essa finalidade, você pode derivar uma classe de CAnimationController e substituir OnAnimationManagerStatusChanged e/ou OnAnimationTimerPostUpdate e invalidar a uma ou mais janelas quando necessário.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CAnimationController`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="_dtorcanimationcontroller"></a>CAnimationController:: ~ CAnimationController  
 O destruidor. Chamado quando o objeto de controlador de animação está sendo destruído.  
  
```  
virtual ~CAnimationController(void);
```   
  
##  <a name="addanimationobject"></a>CAnimationController::AddAnimationObject  
 Adiciona um objeto de animação a um grupo ao qual pertence o controlador de animação.  
  
```  
CAnimationGroup* AddAnimationObject(CAnimationBaseObject* pObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pObject`  
 Um ponteiro para um objeto de animação.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o grupo de animação novos ou existentes onde pObject foi adicionado se a função for bem-sucedida; NULL se pObject já foi adicionado a um grupo que pertence a outro controlador de animação.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para adicionar um objeto de animação para o controlador de animação. Um objeto será adicionado a um grupo de acordo com a ID do grupo do objeto (consulte CAnimationBaseObject::SetID). O controlador de animação criará um novo grupo se ele for o primeiro objeto que está sendo adicionado com a ID do grupo especificado. Um objeto de animação pode ser adicionado ao controlador uma animação apenas. Se você precisar adicionar um objeto para outro controlador, chame RemoveAnimationObject primeiro. Se você chamar SetID com GroupID novo para um objeto que já tenha sido adicionado a um grupo, o objeto será removido do grupo antigo e adicionado a outro grupo com a ID especificada.  
  
##  <a name="addkeyframetogroup"></a>CAnimationController::AddKeyframeToGroup  
 Adiciona um quadro-chave ao grupo.  
  
```  
BOOL AddKeyframeToGroup(
    UINT32 nGroupID,  
    CBaseKeyFrame* pKeyframe);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nGroupID`  
 Especifica a ID do grupo.  
  
 `pKeyframe`  
 Um ponteiro para um quadro-chave.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a função for bem-sucedida; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Normalmente você não precisa chamar esse método, use CAnimationController::CreateKeyframe, que cria e adiciona automaticamente o quadro-chave criado para um grupo.  
  
##  <a name="animategroup"></a>CAnimationController::AnimateGroup  
 Prepara um grupo para executar a animação e, opcionalmente, a agenda.  
  
```  
BOOL AnimateGroup(
    UINT32 nGroupID,  
    BOOL bScheduleNow = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nGroupID`  
 Especifica a ID do grupo.  
  
 `bScheduleNow`  
 Especifica se deve executar a animação imediatamente.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a animação foi agendada e executar com êxito.  
  
### <a name="remarks"></a>Comentários  
 Esse método faz o trabalho real Criando storyboard, adicionar variáveis de animação, aplicação de transições e definindo quadros-chave. É possível adiar o agendamento se você definir bScheduleNow como FALSE. Nesse caso, o grupo especificado manterá um storyboard que foi configurado para animação. Nesse ponto, você pode configurar eventos para as variáveis de animação e storyboard. Quando você realmente precisa executar a chamada de animação CAnimationController::ScheduleGroup.  
  
##  <a name="canimationcontroller"></a>CAnimationController::CAnimationController  
 Constrói um controlador de animação.  
  
```  
CAnimationController(void);
```   
  
##  <a name="cleanupgroup"></a>CAnimationController::CleanUpGroup  
 Chamado pela estrutura para limpar o grupo quando animação foi agendada.  
  
```  
void CleanUpGroup(UINT32 nGroupID);  
void CleanUpGroup(CAnimationGroup* pGroup);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nGroupID`  
 Especifica a ID do grupo.  
  
 `pGroup`  
 Um ponteiro para o grupo de animação para limpar.  
  
### <a name="remarks"></a>Comentários  
 Este método Remove todas as transições e quadros-chave do grupo especificado, porque eles não são relevantes após uma animação foi agendada.  
  
##  <a name="createkeyframe"></a>CAnimationController::CreateKeyframe  
 Cria um quadro-chave que depende de transição e o adiciona ao grupo especificado.  
  
```  
CKeyFrame* CreateKeyframe(
    UINT32 nGroupID,  
    CBaseTransition* pTransition);

 
CKeyFrame* CreateKeyframe(
    UINT32 nGroupID,  
    CBaseKeyFrame* pKeyframe,  
    UI_ANIMATION_SECONDS offset = 0.0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nGroupID`  
 Especifica a ID do grupo para o qual o quadro-chave é criado.  
  
 `pTransition`  
 Um ponteiro para a transição. Quadro-chave será inserida ao storyboard após essa transição.  
  
 `pKeyframe`  
 Um ponteiro para um quadro-chave base para esse quadro-chave.  
  
 `offset`  
 Deslocamento em segundos desde o quadro-chave base especificado por pKeyframe.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o quadro-chave recém-criado se a função obtiver êxito.  
  
### <a name="remarks"></a>Comentários  
 Você pode armazenar o ponteiro retornado e outros quadros chave se baseará no quadro-chave recém-criado (consulte a segunda sobrecarga). É possível começar a transições em quadros-chave-Consulte CBaseTransition::SetKeyframes. Você não precisa excluir quadros chave criados dessa forma, pois eles são excluídos automaticamente por grupos de animação. Tenha cuidado ao criar quadros-chave com base em outros quadros-chave e transições e evitar referências circulares.  
  
##  <a name="enableanimationmanagerevent"></a>CAnimationController::EnableAnimationManagerEvent  
 Define ou libera um manipulador para chamar quando o status do Gerenciador de animação é alterado.  
  
```  
virtual BOOL EnableAnimationManagerEvent(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bEnable`  
 Especifica se deve definir ou liberar um manipulador.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o manipulador foi definido ou liberado com êxito.  
  
### <a name="remarks"></a>Comentários  
 Quando um manipulador é definido (habilitado) animação do Windows chama OnAnimationManagerStatusChanged quando o status do Gerenciador de animação é alterado.  
  
##  <a name="enableanimationtimereventhandler"></a>CAnimationController::EnableAnimationTimerEventHandler  
 Define ou libera um manipulador para eventos de tempo e o manipulador para atualizações de tempo.  
  
```  
virtual BOOL EnableAnimationTimerEventHandler(
    BOOL bEnable = TRUE,  
    UI_ANIMATION_IDLE_BEHAVIOR idleBehavior = UI_ANIMATION_IDLE_BEHAVIOR_DISABLE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bEnable`  
 Especifica se deve definir ou liberar os manipuladores.  
  
 `idleBehavior`  
 Especifica o comportamento ocioso para o manipulador de atualização do temporizador.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se manipuladores foram definidos ou liberados; com êxito FALSE se este método é chamado pela segunda vez sem soltar os manipuladores pela primeira vez ou se qualquer outro erro ocorre.  
  
### <a name="remarks"></a>Comentários  
 Quando os manipuladores são definidos chamadas de API de animação do Windows (habilitadas) OnAnimationTimerPreUpdate, OnAnimationTimerPostUpdate, OnRenderingTooSlow métodos. Você precisa habilitar os temporizadores de animação permitir que a API de animação do Windows update storyboards. Caso contrário, você precisará chamar CAnimationController::UpdateAnimationManager para direcionar a animação manager para atualizar os valores de todas as variáveis de animação.  
  
##  <a name="enableprioritycomparisonhandler"></a>CAnimationController::EnablePriorityComparisonHandler  
 Define ou libera o identificador de comparação de prioridade para chamar para determinar se um storyboard agendado pode ser cancelado, concluído, cortado ou compactado.  
  
```  
virtual BOOL EnablePriorityComparisonHandler(DWORD dwHandlerType);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwHandlerType`  
 Uma combinação de UI_ANIMATION_PHT_ sinalizadores (consulte comentários), que especifica quais manipuladores para definir ou liberar.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o manipulador foi definido ou liberado com êxito.  
  
### <a name="remarks"></a>Comentários  
 Quando um manipulador é definido (habilitado) animação do Windows chama os seguintes métodos virtuais dependendo dwHandlerType: OnHasPriorityCancel, OnHasPriorityConclude, OnHasPriorityTrim, OnHasPriorityCompress. dwHandler pode ser uma combinação dos seguintes sinalizadores: UI_ANIMATION_PHT_NONE - versão todos os manipuladores UI_ANIMATION_PHT_CANCEL - definir Cancelar manipulador comparação UI_ANIMATION_PHT_CONCLUDE - definir o manipulador de comparação de Conclude UI_ANIMATION_PHT_COMPRESS - definir Compress manipulador comparação UI_ANIMATION_PHT_TRIM - conjunto comparação Trim manipulador UI_ANIMATION_PHT_CANCEL_REMOVE - remover o manipulador de comparação de cancelar UI_ANIMATION_PHT_CONCLUDE_REMOVE - remover o manipulador de comparação Conclude UI_ANIMATION_PHT_COMPRESS_REMOVE - remover o manipulador de comparação de compactar UI_ANIMATION_PHT_TRIM_REMOVE - remover o manipulador de comparação de corte  
  
##  <a name="enablestoryboardeventhandler"></a>CAnimationController::EnableStoryboardEventHandler  
 Define ou libera um manipulador para eventos de status e a atualização do storyboard.  
  
```  
virtual BOOL EnableStoryboardEventHandler(
    UINT32 nGroupID,  
    BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nGroupID`  
 Especifica a ID do grupo.  
  
 `bEnable`  
 Especifica se deve definir ou liberar um manipulador.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o manipulador foi definido ou liberado; com êxito FALSE se o grupo especificado de animação agora está localizado ou animação para o grupo especificado não tiver sido iniciada e seu storyboard interno é nulo.  
  
### <a name="remarks"></a>Comentários  
 Quando um manipulador é definido (habilitado) API de animação do Windows chama métodos virtuais OnStoryboardStatusChanges e OnStoryboardUpdated. Um manipulador deve ser definido depois CAnimationController::Animate foi chamado para o grupo de animação especificada, porque ele cria o objeto de IUIAnimationStoryboard encapsulado.  
  
##  <a name="findanimationgroup"></a>CAnimationController::FindAnimationGroup  
 Localiza um grupo de animação por sua ID de grupo.  
  
```  
CAnimationGroup* FindAnimationGroup(UINT32 nGroupID);  
CAnimationGroup* FindAnimationGroup(IUIAnimationStoryboard* pStoryboard);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nGroupID`  
 Especifica uma ID do grupo.  
  
 `pStoryboard`  
 Um ponteiro para um storyboard.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o grupo de animação ou NULL se o grupo com a ID especificada não foi encontrado.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para localizar um grupo de animação em tempo de execução. Um grupo é criado e adicionado à lista de grupos de animação interna quando um objeto de animação primeiro com GroupID específico está sendo adicionado ao controlador de animação.  
  
##  <a name="findanimationobject"></a>CAnimationController::FindAnimationObject  
 Localiza o objeto de animação que contém uma variável de animação especificado.  
  
```  
BOOL FindAnimationObject(
    IUIAnimationVariable* pVariable,  
    CAnimationBaseObject** ppObject,  
    CAnimationGroup** ppGroup);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pVariable`  
 Um ponteiro para a variável de animação.  
  
 `ppObject`  
 Saída. Contém um ponteiro para o objeto de animação ou NULL.  
  
 `ppGroup`  
 Saída. Contém um ponteiro para o grupo de animação que contém o objeto de animação ou NULL.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o objeto foi encontrado; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Chamada de manipuladores de eventos quando ele é necessário para localizar um objeto de animação de entrada variável de animação.  
  
##  <a name="g_keyframestoryboardstart"></a>CAnimationController::gkeyframeStoryboardStart  
 Um quadro-chave que representa o início do storyboard.  
  
```  
static CBaseKeyFrame gkeyframeStoryboardStart;  
```  
  
##  <a name="getkeyframestoryboardstart"></a>CAnimationController::GetKeyframeStoryboardStart  
 Retorna um quadro-chave que identifica o início do storyboard.  
  
```  
static CBaseKeyFrame* GetKeyframeStoryboardStart();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o quadro-chave base, que identifica o início do storyboard.  
  
### <a name="remarks"></a>Comentários  
 Obter esse quadro chave para basear outros quadros-chave ou transições ponto no tempo quando um storyboard é iniciado.  
  
##  <a name="getuianimationmanager"></a>CAnimationController::GetUIAnimationManager  
 Fornece acesso ao objeto de IUIAnimationManager encapsulado.  
  
```  
IUIAnimationManager* GetUIAnimationManager();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro de interface IUIAnimationManager ou NULL, se a falha na criação do Gerenciador de animação.  
  
### <a name="remarks"></a>Comentários  
 Se o sistema operacional atual não oferece suporte a API de animação do Windows, esse método retorna NULL e depois que todas as chamadas subsequentes no CAnimationController::IsValid retornam FALSE. Talvez seja necessário acessar IUIAnimationManager para chamar seus métodos de interface, que não são compactados com o controlador de animação.  
  
##  <a name="getuianimationtimer"></a>CAnimationController::GetUIAnimationTimer  
 Fornece acesso ao objeto de IUIAnimationTimer encapsulado.  
  
```  
IUIAnimationTimer* GetUIAnimationTimer();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro de interface IUIAnimationTimer ou nulo, se a falha na criação do timer de animação.  
  
### <a name="remarks"></a>Comentários  
 Se o sistema operacional atual não oferece suporte a API de animação do Windows, esse método retorna NULL e depois que todas as chamadas subsequentes no CAnimationController::IsValid retornam FALSE.  
  
##  <a name="getuitransitionfactory"></a>CAnimationController::GetUITransitionFactory  
 Um ponteiro de interface IUIAnimationTransitionFactory ou NULL, se a falha na criação da biblioteca de transição.  
  
```  
IUIAnimationTransitionFactory* GetUITransitionFactory();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para IUIAnimationTransitionFactory ou NULL, se a falha na criação da fábrica de transição.  
  
### <a name="remarks"></a>Comentários  
 Se o sistema operacional atual não oferece suporte a API de animação do Windows, esse método retorna NULL e depois que todas as chamadas subsequentes no CAnimationController::IsValid retornam FALSE.  
  
##  <a name="getuitransitionlibrary"></a>CAnimationController::GetUITransitionLibrary  
 Fornece acesso ao objeto de IUIAnimationTransitionLibrary encapsulado.  
  
```  
IUIAnimationTransitionLibrary* GetUITransitionLibrary();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro de interface IUIAnimationTransitionLibrary ou NULL, se a falha na criação da biblioteca de transição.  
  
### <a name="remarks"></a>Comentários  
 Se o sistema operacional atual não oferece suporte a API de animação do Windows, esse método retorna NULL e depois que todas as chamadas subsequentes no CAnimationController::IsValid retornam FALSE.  
  
##  <a name="isanimationinprogress"></a>CAnimationController::IsAnimationInProgress  
 Informa se pelo menos um grupo é Reproduzir animação.  
  
```  
virtual BOOL IsAnimationInProgress();
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se houver uma animação em andamento para este controlador de animação; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Verifica o status do Gerenciador de animação e retorna TRUE se o status for UI_ANIMATION_MANAGER_BUSY.  
  
##  <a name="isvalid"></a>CAnimationController::IsValid  
 Informa se o controlador de animação é válido.  
  
```  
BOOL IsValid() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o controlador de animação é válido. Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna FALSE apenas se a API de animação do Windows não é compatível com o sistema operacional atual e a criação do Gerenciador de animação falhou porque não está registrado. É necessário chamar GetUIAnimationManager pelo menos uma vez após a inicialização de bibliotecas COM para fazer com que a configuração desse sinalizador.  
  
##  <a name="m_bisvalid"></a>CAnimationController::m_bIsValid  
 Especifica se um controlador de animação é válido ou não. Esse membro é definido como FALSE se o sistema operacional atual não oferece suporte a API de animação do Windows.  
  
```  
BOOL m_bIsValid;  
```  
  
##  <a name="m_lstanimationgroups"></a>CAnimationController::m_lstAnimationGroups  
 Uma lista de grupos de animação que pertencem a esse controlador de animação.  
  
```  
CList<CAnimationGroup*, CAnimationGroup*> m_lstAnimationGroups;  
```  
  
##  <a name="m_panimationmanager"></a>CAnimationController::m_pAnimationManager  
 Armazena um ponteiro para o objeto COM do Gerenciador de animação.  
  
```  
ATL::CComPtr<IUIAnimationManager> m_pAnimationManager;  
```  
  
##  <a name="m_panimationtimer"></a>CAnimationController::m_pAnimationTimer  
 Armazena um ponteiro para o objeto COM do Timer de animação.  
  
```  
ATL::CComPtr<IUIAnimationTimer> m_pAnimationTimer;  
```  
  
##  <a name="m_prelatedwnd"></a>CAnimationController::m_pRelatedWnd  
 Um ponteiro para um objeto CWnd relacionado, o que pode ser redesenhado automaticamente quando o status do Gerenciador de animação foi alterado ou ocorreu o evento de atualização de post. Pode ser NULL.  
  
```  
CWnd* m_pRelatedWnd;  
```  
  
##  <a name="m_ptransitionfactory"></a>CAnimationController::m_pTransitionFactory  
 Armazena um ponteiro para o objeto COM da fábrica de transição.  
  
```  
ATL::CComPtr<IUIAnimationTransitionFactory> m_pTransitionFactory;  
```  
  
##  <a name="m_ptransitionlibrary"></a>CAnimationController::m_pTransitionLibrary  
 Armazena um ponteiro para o objeto COM da biblioteca de transição.  
  
```  
ATL::CComPtr<IUIAnimationTransitionLibrary> m_pTransitionLibrary;  
```  
  
##  <a name="onafterschedule"></a>CAnimationController::OnAfterSchedule  
 Chamado pela estrutura quando uma animação para o grupo especificado apenas foi agendada.  
  
```  
virtual void OnAfterSchedule(CAnimationGroup* pGroup);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pGroup`  
 Um ponteiro para um grupo de animação que foi agendado.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão remove quadros-chave de um grupo e faz a transição de variáveis de animação que pertencem ao grupo especificado. Pode ser substituído em uma classe derivada para executar quaisquer ações adicionais na agenda de animação.  
  
##  <a name="onanimationintegervaluechanged"></a>CAnimationController::OnAnimationIntegerValueChanged  
 Chamado pela estrutura quando o valor inteiro da variável de animação é alterado.  
  
```  
virtual void OnAnimationIntegerValueChanged(
    CAnimationGroup* pGroup,  
    CAnimationBaseObject* pObject,  
    IUIAnimationVariable* variable,  
    INT32 newValue,  
    INT32 prevValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pGroup`  
 Um ponteiro para um grupo de animação que contém um objeto de animação cujo valor foi alterado.  
  
 `pObject`  
 Um ponteiro para um objeto de animação que contém uma variável de animação cujo valor foi alterado.  
  
 `variable`  
 Um ponteiro para uma variável de animação.  
  
 `newValue`  
 Especifica o novo valor.  
  
 `prevValue`  
 Especifica o valor anterior.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado se você habilitar eventos de variável de animação com EnableIntegerValueChangedEvent chamada para uma variável de animação específico ou objeto de animação. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo.  
  
##  <a name="onanimationmanagerstatuschanged"></a>CAnimationController::OnAnimationManagerStatusChanged  
 Chamado pela estrutura em resposta a eventos de status alterado do Gerenciador de animação.  
  
```  
virtual void OnAnimationManagerStatusChanged(
    UI_ANIMATION_MANAGER_STATUS newStatus,  
    UI_ANIMATION_MANAGER_STATUS previousStatus);
```  
  
### <a name="parameters"></a>Parâmetros  
 `newStatus`  
 Novo status do Gerenciador de animação.  
  
 `previousStatus`  
 Status do Gerenciador de animação anterior.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado se você ativar eventos do Gerenciador de animação com EnableAnimationManagerEvent. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo. A implementação padrão atualiza uma janela relacionada, se ele tiver sido definido com SetRelatedWnd.  
  
##  <a name="onanimationtimerpostupdate"></a>CAnimationController::OnAnimationTimerPostUpdate  
 Chamado pela estrutura após uma atualização de animação.  
  
```  
virtual void OnAnimationTimerPostUpdate();
```  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado se você habilitar os manipuladores de eventos do timer usando EnableAnimationTimerEventHandler. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo.  
  
##  <a name="onanimationtimerpreupdate"></a>CAnimationController::OnAnimationTimerPreUpdate  
 Chamado pela estrutura antes do início de uma atualização de animação.  
  
```  
virtual void OnAnimationTimerPreUpdate();
```  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado se você habilitar os manipuladores de eventos do timer usando EnableAnimationTimerEventHandler. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo.  
  
##  <a name="onanimationtimerrenderingtooslow"></a>CAnimationController::OnAnimationTimerRenderingTooSlow  
 Chamado pela estrutura quando a taxa de quadros de renderização para uma animação fica abaixo de uma taxa de quadros desejável mínimo.  
  
```  
virtual void OnAnimationTimerRenderingTooSlow(UINT32 fps);
```  
  
### <a name="parameters"></a>Parâmetros  
 `fps`  
 A taxa de quadros atual em quadros por segundo.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado se você habilitar os manipuladores de eventos do timer usando EnableAnimationTimerEventHandler. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo. A taxa de quadros desejável mínimo é especificada chamando IUIAnimationTimer::SetFrameRateThreshold.  
  
##  <a name="onanimationvaluechanged"></a>CAnimationController::OnAnimationValueChanged  
 Chamado pela estrutura quando o valor da variável de animação é alterado.  
  
```  
virtual void OnAnimationValueChanged(
    CAnimationGroup* pGroup,  
    CAnimationBaseObject* pObject,  
    IUIAnimationVariable* variable,  
    DOUBLE newValue,  
    DOUBLE prevValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pGroup`  
 Um ponteiro para um grupo de animação que contém um objeto de animação cujo valor foi alterado.  
  
 `pObject`  
 Um ponteiro para um objeto de animação que contém uma variável de animação cujo valor foi alterado.  
  
 `variable`  
 Um ponteiro para uma variável de animação.  
  
 `newValue`  
 Especifica o novo valor.  
  
 `prevValue`  
 Especifica o valor anterior.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado se você habilitar eventos de variável de animação com EnableValueChangedEvent chamada para uma variável de animação específico ou objeto de animação. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo.  
  
##  <a name="onbeforeanimationstart"></a>CAnimationController::OnBeforeAnimationStart  
 Chamado pela estrutura correta antes que a animação seja agendada.  
  
```  
virtual void OnBeforeAnimationStart(CAnimationGroup* pGroup);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pGroup`  
 Um ponteiro para um grupo de animação cuja animação está prestes a iniciar.  
  
### <a name="remarks"></a>Comentários  
 Essa chamada é roteada para CWnd relacionado e pode ser substituída em uma classe derivada para realizar as ações adicionais antes de inicia a animação para o grupo especificado.  
  
##  <a name="onhasprioritycancel"></a>CAnimationController::OnHasPriorityCancel  
 Chamado pela estrutura para resolver conflitos de agendamento.  
  
```  
virtual BOOL OnHasPriorityCancel(
    CAnimationGroup* pGroupScheduled,  
    CAnimationGroup* pGroupNew,  
    UI_ANIMATION_PRIORITY_EFFECT priorityEffect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pGroupScheduled`  
 O grupo que possui o storyboard agendado no momento.  
  
 `pGroupNew`  
 O grupo que possui o novo storyboard que está em conflito de agendamento com o storyboard agendado pGroupScheduled de propriedade.  
  
 `priorityEffect`  
 O efeito potencial no pGroupNew se pGroupScheduled tem uma prioridade mais alta.  
  
### <a name="return-value"></a>Valor de retorno  
 Deve retornar TRUE se o storyboard de propriedade pGroupNew tem prioridade. Deve retornar FALSE se o storyboard de propriedade pGroupScheduled tem prioridade.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado se você habilitar eventos de comparação de prioridade usando CAnimationController::EnablePriorityComparisonHandler e especifica UI_ANIMATION_PHT_CANCEL. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo. Documentação da API de animação do Windows de leitura para obter mais informações sobre o gerenciamento de conflito (http://msdn.microsoft.com/library/dd371759 (VS.85).aspx).  
  
##  <a name="onhasprioritycompress"></a>CAnimationController::OnHasPriorityCompress  
 Chamado pela estrutura para resolver conflitos de agendamento.  
  
```  
virtual BOOL OnHasPriorityCompress(
    CAnimationGroup* pGroupScheduled,  
    CAnimationGroup* pGroupNew,  
    UI_ANIMATION_PRIORITY_EFFECT priorityEffect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pGroupScheduled`  
 O grupo que possui o storyboard agendado no momento.  
  
 `pGroupNew`  
 O grupo que possui o novo storyboard que está em conflito de agendamento com o storyboard agendado pGroupScheduled de propriedade.  
  
 `priorityEffect`  
 O efeito potencial no pGroupNew se pGroupScheduled tem uma prioridade mais alta.  
  
### <a name="return-value"></a>Valor de retorno  
 Deve retornar TRUE se o storyboard de propriedade pGroupNew tem prioridade. Deve retornar FALSE se o storyboard de propriedade pGroupScheduled tem prioridade.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado se você habilitar eventos de comparação de prioridade usando CAnimationController::EnablePriorityComparisonHandler e especifica UI_ANIMATION_PHT_COMPRESS. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo. Documentação da API de animação do Windows de leitura para obter mais informações sobre o gerenciamento de conflito (http://msdn.microsoft.com/library/dd371759 (VS.85).aspx).  
  
##  <a name="onhaspriorityconclude"></a>CAnimationController::OnHasPriorityConclude  
 Chamado pela estrutura para resolver conflitos de agendamento.  
  
```  
virtual BOOL OnHasPriorityConclude(
    CAnimationGroup* pGroupScheduled,  
    CAnimationGroup* pGroupNew,  
    UI_ANIMATION_PRIORITY_EFFECT priorityEffect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pGroupScheduled`  
 O grupo que possui o storyboard agendado no momento.  
  
 `pGroupNew`  
 O grupo que possui o novo storyboard que está em conflito de agendamento com o storyboard agendado pGroupScheduled de propriedade.  
  
 `priorityEffect`  
 O efeito potencial no pGroupNew se pGroupScheduled tem uma prioridade mais alta.  
  
### <a name="return-value"></a>Valor de retorno  
 Deve retornar TRUE se o storyboard de propriedade pGroupNew tem prioridade. Deve retornar FALSE se o storyboard de propriedade pGroupScheduled tem prioridade.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado se você habilitar eventos de comparação de prioridade usando CAnimationController::EnablePriorityComparisonHandler e especifica UI_ANIMATION_PHT_CONCLUDE. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo. Documentação da API de animação do Windows de leitura para obter mais informações sobre o gerenciamento de conflito (http://msdn.microsoft.com/library/dd371759 (VS.85).aspx).  
  
##  <a name="onhasprioritytrim"></a>CAnimationController::OnHasPriorityTrim  
 Chamado pela estrutura para resolver conflitos de agendamento.  
  
```  
virtual BOOL OnHasPriorityTrim(
    CAnimationGroup* pGroupScheduled,  
    CAnimationGroup* pGroupNew,  
    UI_ANIMATION_PRIORITY_EFFECT priorityEffect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pGroupScheduled`  
 O grupo que possui o storyboard agendado no momento.  
  
 `pGroupNew`  
 O grupo que possui o novo storyboard que está em conflito de agendamento com o storyboard agendado pGroupScheduled de propriedade.  
  
 `priorityEffect`  
 O efeito potencial no pGroupNew se pGroupScheduled tem uma prioridade mais alta.  
  
### <a name="return-value"></a>Valor de retorno  
 Deve retornar TRUE se o storyboard de propriedade pGroupNew tem prioridade. Deve retornar FALSE se o storyboard de propriedade pGroupScheduled tem prioridade.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado se você habilitar eventos de comparação de prioridade usando CAnimationController::EnablePriorityComparisonHandler e especifica UI_ANIMATION_PHT_TRIM. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo. Documentação da API de animação do Windows de leitura para obter mais informações sobre o gerenciamento de conflito (http://msdn.microsoft.com/library/dd371759 (VS.85).aspx).  
  
##  <a name="onstoryboardstatuschanged"></a>CAnimationController::OnStoryboardStatusChanged  
 Chamado pela estrutura quando o status de storyboard mudou.  
  
```  
virtual void OnStoryboardStatusChanged(
    CAnimationGroup* pGroup,  
    UI_ANIMATION_STORYBOARD_STATUS newStatus,  
    UI_ANIMATION_STORYBOARD_STATUS previousStatus);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pGroup`  
 Um ponteiro para um grupo de animação que possui o storyboard cujo status foi alterado.  
  
 `newStatus`  
 Especifica o novo status.  
  
 `previousStatus`  
 Especifica o status anterior.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado se você habilitar eventos storyboard usando CAnimationController::EnableStoryboardEventHandler. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo.  
  
##  <a name="onstoryboardupdated"></a>CAnimationController::OnStoryboardUpdated  
 Chamado pela estrutura quando storyboard tiver sido atualizado.  
  
```  
virtual void OnStoryboardUpdated(CAnimationGroup* pGroup);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pGroup`  
 Um ponteiro para um grupo que possui o storyboard.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado se você habilitar eventos storyboard usando CAnimationController::EnableStoryboardEventHandler. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo.  
  
##  <a name="removeallanimationgroups"></a>CAnimationController::RemoveAllAnimationGroups  
 Remove todos os grupos de animação do controlador de animação.  
  
```  
void RemoveAllAnimationGroups();
```  
  
### <a name="remarks"></a>Comentários  
 Todos os grupos serão excluídos, o ponteiro se armazenado no nível do aplicativo, deve invalidado. Se CAnimationGroup::m_bAutodestroyAnimationObjects para um grupo que está sendo excluído for TRUE, todos os objetos de animação que pertencem a esse grupo serão excluídos; Caso contrário, suas referências ao controlador de animação do pai serão definidas como NULL e eles podem ser adicionados a outro controlador.  
  
##  <a name="removeanimationgroup"></a>CAnimationController::RemoveAnimationGroup  
 Remove um grupo de animação com a ID especificada do controlador de animação.  
  
```  
void RemoveAnimationGroup(UINT32 nGroupID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nGroupID`  
 Especifica a ID do grupo de animação.  
  
### <a name="remarks"></a>Comentários  
 Esse método Remove um grupo de animação a lista interna de grupos e exclui-lo, portanto se você armazenou um ponteiro para esse grupo de animação, ele deve ser invalidado. Se CAnimationGroup::m_bAutodestroyAnimationObjects for TRUE, todos os objetos de animação que pertencem a esse grupo serão excluídos; Caso contrário, suas referências ao controlador de animação do pai serão definidas como NULL e eles podem ser adicionados a outro controlador.  
  
##  <a name="removeanimationobject"></a>CAnimationController::RemoveAnimationObject  
 Remova um objeto de animação do controlador de animação.  
  
```  
void RemoveAnimationObject(
    CAnimationBaseObject* pObject,  
    BOOL bNoDelete = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pObject`  
 Um ponteiro para um objeto de animação.  
  
 `bNoDelete`  
 Se esse parâmetro for TRUE o objeto não será excluído após a remoção.  
  
### <a name="remarks"></a>Comentários  
 Remove um objeto de animação do controlador de animação e o grupo de animação. Chame essa função se um determinado objeto não deve ser animado mais, ou se você precisar mover o objeto para outro controlador de animação. No último caso bNoDelete deve ser verdadeiro.  
  
##  <a name="removetransitions"></a>CAnimationController::RemoveTransitions  
 Remove as transições de objetos de animação que pertencem ao grupo especificado.  
  
```  
void RemoveTransitions(UINT32 nGroupID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nGroupID`  
 Especifica a ID do grupo.  
  
### <a name="remarks"></a>Comentários  
 O grupo faz um loop sobre seus objetos de animação e chama ClearTransitions(FALSE) para cada objeto de animação. Esse método é chamado pela estrutura depois animação foi agendada.  
  
##  <a name="schedulegroup"></a>CAnimationController::ScheduleGroup  
 Agenda uma animação.  
  
```  
BOOL ScheduleGroup(
    UINT32 nGroupID,  
    UI_ANIMATION_SECONDS time = 0.0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nGroupID`  
 Especifica a ID de grupo para agendar animação.  
  
 `time`  
 Especifica o tempo para agendar.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a animação foi agendada com êxito. FALSE se o storyboard não tiver sido criado, ou outro erro ocorre.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar AnimateGroup com o parâmetro bScheduleNow definido como FALSE ScheduleGroup anterior. Você pode especificar o tempo de animação desejado é obtido do IUIAnimationTimer::GetTime. Se o parâmetro de tempo é 0.0, a animação será agendada para o horário atual.  
  
##  <a name="setrelatedwnd"></a>CAnimationController::SetRelatedWnd  
 Estabelece uma relação entre o controlador de animação e uma janela.  
  
```  
void SetRelatedWnd(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Um ponteiro para o objeto de janela a ser definido.  
  
### <a name="remarks"></a>Comentários  
 Se um objeto CWnd relacionado for definido, o controlador de animação pode atualizá-lo automaticamente (Enviar mensagem WM_PAINT) quando o status do Gerenciador de animação foi alterado ou evento de atualização de post timer ocorreu.  
  
##  <a name="updateanimationmanager"></a>CAnimationController::UpdateAnimationManager  
 Direciona o Gerenciador de animação para atualizar os valores de todas as variáveis de animação.  
  
```  
virtual void UpdateAnimationManager();
```  
  
### <a name="remarks"></a>Comentários  
 Chamar que esse método avança o Gerenciador de animação a hora atual, alterando o status de storyboards conforme necessário e atualizar quaisquer variáveis de animação apropriada interpolados valores. Este método chama internamente IUIAnimationTimer::GetTime(timeNow) e IUIAnimationManager::Update(timeNow). Substitua esse método em uma classe derivada para personalizar esse comportamento.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

