---
title: Classe CAnimationController
ms.date: 11/04/2016
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
- AFXANIMATIONCONTROLLER/CAnimationController::OnAfterSchedule
- AFXANIMATIONCONTROLLER/CAnimationController::gkeyframeStoryboardStart
- AFXANIMATIONCONTROLLER/CAnimationController::m_bIsValid
- AFXANIMATIONCONTROLLER/CAnimationController::m_lstAnimationGroups
- AFXANIMATIONCONTROLLER/CAnimationController::m_pAnimationManager
- AFXANIMATIONCONTROLLER/CAnimationController::m_pAnimationTimer
- AFXANIMATIONCONTROLLER/CAnimationController::m_pRelatedWnd
- AFXANIMATIONCONTROLLER/CAnimationController::m_pTransitionFactory
- AFXANIMATIONCONTROLLER/CAnimationController::m_pTransitionLibrary
helpviewer_keywords:
- CAnimationController [MFC], CAnimationController
- CAnimationController [MFC], AddAnimationObject
- CAnimationController [MFC], AddKeyframeToGroup
- CAnimationController [MFC], AnimateGroup
- CAnimationController [MFC], CleanUpGroup
- CAnimationController [MFC], CreateKeyframe
- CAnimationController [MFC], EnableAnimationManagerEvent
- CAnimationController [MFC], EnableAnimationTimerEventHandler
- CAnimationController [MFC], EnablePriorityComparisonHandler
- CAnimationController [MFC], EnableStoryboardEventHandler
- CAnimationController [MFC], FindAnimationGroup
- CAnimationController [MFC], FindAnimationObject
- CAnimationController [MFC], GetKeyframeStoryboardStart
- CAnimationController [MFC], GetUIAnimationManager
- CAnimationController [MFC], GetUIAnimationTimer
- CAnimationController [MFC], GetUITransitionFactory
- CAnimationController [MFC], GetUITransitionLibrary
- CAnimationController [MFC], IsAnimationInProgress
- CAnimationController [MFC], IsValid
- CAnimationController [MFC], OnAnimationIntegerValueChanged
- CAnimationController [MFC], OnAnimationManagerStatusChanged
- CAnimationController [MFC], OnAnimationTimerPostUpdate
- CAnimationController [MFC], OnAnimationTimerPreUpdate
- CAnimationController [MFC], OnAnimationTimerRenderingTooSlow
- CAnimationController [MFC], OnAnimationValueChanged
- CAnimationController [MFC], OnBeforeAnimationStart
- CAnimationController [MFC], OnHasPriorityCancel
- CAnimationController [MFC], OnHasPriorityCompress
- CAnimationController [MFC], OnHasPriorityConclude
- CAnimationController [MFC], OnHasPriorityTrim
- CAnimationController [MFC], OnStoryboardStatusChanged
- CAnimationController [MFC], OnStoryboardUpdated
- CAnimationController [MFC], RemoveAllAnimationGroups
- CAnimationController [MFC], RemoveAnimationGroup
- CAnimationController [MFC], RemoveAnimationObject
- CAnimationController [MFC], RemoveTransitions
- CAnimationController [MFC], ScheduleGroup
- CAnimationController [MFC], SetRelatedWnd
- CAnimationController [MFC], UpdateAnimationManager
- CAnimationController [MFC], CleanUpGroup
- CAnimationController [MFC], OnAfterSchedule
- CAnimationController [MFC], gkeyframeStoryboardStart
- CAnimationController [MFC], m_bIsValid
- CAnimationController [MFC], m_lstAnimationGroups
- CAnimationController [MFC], m_pAnimationManager
- CAnimationController [MFC], m_pAnimationTimer
- CAnimationController [MFC], m_pRelatedWnd
- CAnimationController [MFC], m_pTransitionFactory
- CAnimationController [MFC], m_pTransitionLibrary
ms.assetid: ed294c98-695e-40a6-b940-33ef1d40aa6b
ms.openlocfilehash: bd0bdd1a3f423257b2f73745d7260d1fac12a0d8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50556652"
---
# <a name="canimationcontroller-class"></a>Classe CAnimationController

Implementa o controlador de animação, que fornece uma interface central para criar e gerenciar animações.

## <a name="syntax"></a>Sintaxe

```
class CAnimationController : public CObject;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

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
|[CAnimationController::CleanUpGroup](#cleanupgroup)|Sobrecarregado. Chamado pelo framework para limpar o grupo de quando a animação foi agendada.|
|[CAnimationController::CreateKeyframe](#createkeyframe)|Sobrecarregado. Cria um quadro-chave que depende de transição e o adiciona ao grupo especificado.|
|[CAnimationController::EnableAnimationManagerEvent](#enableanimationmanagerevent)|Define ou libera um manipulador a chamar quando o status do Gerenciador de animação é alterado.|
|[CAnimationController::EnableAnimationTimerEventHandler](#enableanimationtimereventhandler)|Define ou libera um manipulador para eventos de tempo e o manipulador de atualizações de tempo.|
|[CAnimationController::EnablePriorityComparisonHandler](#enableprioritycomparisonhandler)|Define ou libera o identificador de comparação de prioridade para chamar para determinar se um storyboard agendado pode ser cancelado, concluiu, cortado ou compactado.|
|[CAnimationController::EnableStoryboardEventHandler](#enablestoryboardeventhandler)|Define ou libera um manipulador para eventos de status e a atualização do storyboard.|
|[CAnimationController::FindAnimationGroup](#findanimationgroup)|Sobrecarregado. Localiza um grupo de animação por seu storyboard.|
|[CAnimationController::FindAnimationObject](#findanimationobject)|Localiza o objeto de animação que contém uma variável de animação especificado.|
|[CAnimationController::GetKeyframeStoryboardStart](#getkeyframestoryboardstart)|Retorna um quadro-chave que identifica o início do storyboard.|
|[CAnimationController::GetUIAnimationManager](#getuianimationmanager)|Fornece acesso ao objeto de IUIAnimationManager encapsulado.|
|[CAnimationController::GetUIAnimationTimer](#getuianimationtimer)|Fornece acesso ao objeto de IUIAnimationTimer encapsulado.|
|[CAnimationController::GetUITransitionFactory](#getuitransitionfactory)|Um ponteiro para a interface IUIAnimationTransitionFactory ou nulo, se a falha na criação da biblioteca de transição.|
|[CAnimationController::GetUITransitionLibrary](#getuitransitionlibrary)|Fornece acesso ao objeto de IUIAnimationTransitionLibrary encapsulado.|
|[CAnimationController::IsAnimationInProgress](#isanimationinprogress)|Informa se pelo menos um grupo está sendo reproduzido a animação.|
|[CAnimationController::IsValid](#isvalid)|Informa se o controlador de animação é válido.|
|[CAnimationController::OnAnimationIntegerValueChanged](#onanimationintegervaluechanged)|Chamado pelo framework quando o valor inteiro da variável de animação é alterado.|
|[CAnimationController::OnAnimationManagerStatusChanged](#onanimationmanagerstatuschanged)|Chamado pelo framework em resposta ao evento StatusChanged do Gerenciador de animação.|
|[CAnimationController::OnAnimationTimerPostUpdate](#onanimationtimerpostupdate)|Chamado pelo framework depois que uma atualização de animação for concluída.|
|[CAnimationController::OnAnimationTimerPreUpdate](#onanimationtimerpreupdate)|Chamado pelo framework antes do início de uma atualização de animação.|
|[CAnimationController::OnAnimationTimerRenderingTooSlow](#onanimationtimerrenderingtooslow)|Chamado pelo framework quando a taxa de quadros de renderização para uma animação fica abaixo de uma taxa de quadros desejável mínimo.|
|[CAnimationController::OnAnimationValueChanged](#onanimationvaluechanged)|Chamado pelo framework quando o valor da variável de animação é alterado.|
|[CAnimationController::OnBeforeAnimationStart](#onbeforeanimationstart)|Chamado pelo framework correto antes da animação é agendada.|
|[CAnimationController::OnHasPriorityCancel](#onhasprioritycancel)|Chamado pelo framework para resolver conflitos de agendamento.|
|[CAnimationController::OnHasPriorityCompress](#onhasprioritycompress)|Chamado pelo framework para resolver conflitos de agendamento.|
|[CAnimationController::OnHasPriorityConclude](#onhaspriorityconclude)|Chamado pelo framework para resolver conflitos de agendamento.|
|[CAnimationController::OnHasPriorityTrim](#onhasprioritytrim)|Chamado pelo framework para resolver conflitos de agendamento.|
|[CAnimationController::OnStoryboardStatusChanged](#onstoryboardstatuschanged)|Chamado pelo framework quando o status de storyboard foi alterado.|
|[CAnimationController::OnStoryboardUpdated](#onstoryboardupdated)|Chamado pelo framework quando o storyboard foi atualizado.|
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
|[CAnimationController::OnAfterSchedule](#onafterschedule)|Chamado pelo framework quando uma animação para o grupo especificado apenas foi agendada.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationController::gkeyframeStoryboardStart](#g_keyframestoryboardstart)|Um quadro-chave que representa o início do storyboard.|
|[CAnimationController::m_bIsValid](#m_bisvalid)|Especifica se um controlador de animação é válido ou não. Esse membro é definido como FALSE se o sistema operacional atual não oferece suporte a API de animação do Windows.|
|[CAnimationController::m_lstAnimationGroups](#m_lstanimationgroups)|Uma lista de grupos de animação que pertencem a esse controlador de animação.|
|[CAnimationController::m_pAnimationManager](#m_panimationmanager)|Armazena um ponteiro para objeto COM do Gerenciador de animação.|
|[CAnimationController::m_pAnimationTimer](#m_panimationtimer)|Armazena um ponteiro para objeto COM do temporizador de animação.|
|[CAnimationController::m_pRelatedWnd](#m_prelatedwnd)|Um ponteiro para um objeto CWnd relacionado, que pode ser redesenhado automaticamente quando o status do Gerenciador de animação é alterado ou ocorreu o evento de atualização de postagem. Pode ser NULL.|
|[CAnimationController::m_pTransitionFactory](#m_ptransitionfactory)|Armazena um ponteiro para objeto COM fábrica de transição.|
|[CAnimationController::m_pTransitionLibrary](#m_ptransitionlibrary)|Armazena um ponteiro para objeto COM biblioteca de transição.|

## <a name="remarks"></a>Comentários

A classe CAnimationController é a principal classe que gerencia as animações. Você pode criar uma ou mais instâncias do controlador de animação em um aplicativo e, opcionalmente, conecte-se uma instância do controlador de animação a um objeto CWnd usando CAnimationController::SetRelatedWnd. Essa conexão é necessária para enviar mensagens WM_PAINT para a janela relacionada automaticamente quando o status do Gerenciador de animação foi alterado ou o timer de animação foi atualizado. Se você não habilitar essa relação, você deve redesenhar uma janela que exibe uma animação manualmente. Para essa finalidade, você pode derivar uma classe CAnimationController e substituir OnAnimationManagerStatusChanged e/ou OnAnimationTimerPostUpdate e invalidar uma ou mais janelas quando necessário.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CAnimationController`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

##  <a name="_dtorcanimationcontroller"></a>  CAnimationController:: ~ CAnimationController

O destruidor. Chamado quando o objeto de controlador de animação está sendo destruído.

```
virtual ~CAnimationController(void);
```

##  <a name="addanimationobject"></a>  CAnimationController::AddAnimationObject

Adiciona um objeto de animação a um grupo ao qual pertence o controlador de animação.

```
CAnimationGroup* AddAnimationObject(CAnimationBaseObject* pObject);
```

### <a name="parameters"></a>Parâmetros

*pObject*<br/>
Um ponteiro para um objeto de animação.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o grupo de animação novos ou existentes onde pObject foi adicionado se a função for bem-sucedida; NULL se pObject já foi adicionado a um grupo que pertence a outro controlador de animação.

### <a name="remarks"></a>Comentários

Chame esse método para adicionar um objeto de animação para o controlador de animação. Um objeto será adicionado a um grupo de acordo com a ID do grupo do objeto (consulte CAnimationBaseObject::SetID). O controlador de animação criará um novo grupo, se for o primeiro objeto que está sendo adicionado com a ID do grupo especificado. Um objeto de animação pode ser adicionado ao controlador de animação de uma só. Se você precisar adicionar um objeto para outro controlador, chame RemoveAnimationObject primeiro. Se você chamar SetID com a ID do novo grupo de um objeto que já adicionado a um grupo, o objeto será removido do grupo antigo e adicionado a outro grupo com a ID especificada.

##  <a name="addkeyframetogroup"></a>  CAnimationController::AddKeyframeToGroup

Adiciona um quadro-chave ao grupo.

```
BOOL AddKeyframeToGroup(
    UINT32 nGroupID,
    CBaseKeyFrame* pKeyframe);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica a ID do grupo.

*pKeyframe*<br/>
Um ponteiro para um quadro-chave.

### <a name="return-value"></a>Valor de retorno

TRUE se a função for bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Normalmente, você não precisa chamar esse método, use CAnimationController::CreateKeyframe em vez disso, que cria e adiciona o quadro-chave criado para um grupo automaticamente.

##  <a name="animategroup"></a>  CAnimationController::AnimateGroup

Prepara um grupo para executar a animação e, opcionalmente, a agenda.

```
BOOL AnimateGroup(
    UINT32 nGroupID,
    BOOL bScheduleNow = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica a ID do grupo.

*bScheduleNow*<br/>
Especifica se deve executar imediatamente a animação.

### <a name="return-value"></a>Valor de retorno

TRUE se a animação foi agendada e executou com sucesso.

### <a name="remarks"></a>Comentários

Esse método faz o trabalho real de criação de storyboard, adicionar variáveis de animação, aplicando as transições e definindo quadros-chave. É possível atrasar o agendamento se você definir bScheduleNow como FALSE. Nesse caso, o grupo especificado manterá um storyboard que foi configurado para animação. Nesse ponto, você pode configurar eventos para as variáveis de storyboard e animação. Quando você realmente precisa executar a chamada de animação CAnimationController::ScheduleGroup.

##  <a name="canimationcontroller"></a>  CAnimationController::CAnimationController

Constrói um controlador de animação.

```
CAnimationController(void);
```

##  <a name="cleanupgroup"></a>  CAnimationController::CleanUpGroup

Chamado pelo framework para limpar o grupo de quando a animação foi agendada.

```
void CleanUpGroup(UINT32 nGroupID);
void CleanUpGroup(CAnimationGroup* pGroup);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica a ID do grupo.

*pGroup*<br/>
Um ponteiro para o grupo de animação para limpar.

### <a name="remarks"></a>Comentários

Esse método Remove todas as transições e quadros-chave do grupo especificado, pois eles não são relevantes depois que uma animação foi agendada.

##  <a name="createkeyframe"></a>  CAnimationController::CreateKeyframe

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

*nGroupID*<br/>
Especifica a ID de grupo para o qual o quadro-chave é criada.

*pTransition*<br/>
Um ponteiro para fazer a transição. Quadro-chave será inserido para criar um storyboard depois dessa transição.

*pKeyframe*<br/>
Um ponteiro para um quadro-chave base para este quadro-chave.

*deslocamento*<br/>
Deslocamento em segundos desde o quadro-chave base especificado pelo pKeyframe.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o quadro-chave criada recentemente se a função for bem-sucedida.

### <a name="remarks"></a>Comentários

Você pode armazenar o ponteiro retornado e basear outros quadros chave no quadro-chave criado recentemente (consulte a segunda sobrecarga). É possível começar a transições em quadros-chave – Consulte CBaseTransition::SetKeyframes. Você não precisa excluir quadros chave criados dessa maneira, porque eles são excluídos automaticamente por grupos de animação. Tenha cuidado ao criar com base em outros quadros-chave e as transições de quadros-chave e evitar referências circulares.

##  <a name="enableanimationmanagerevent"></a>  CAnimationController::EnableAnimationManagerEvent

Define ou libera um manipulador a chamar quando o status do Gerenciador de animação é alterado.

```
virtual BOOL EnableAnimationManagerEvent(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bAtivar*<br/>
Especifica se deve definir ou liberar um manipulador.

### <a name="return-value"></a>Valor de retorno

TRUE se o manipulador com êxito foi definido ou liberado.

### <a name="remarks"></a>Comentários

Quando um manipulador é definido (habilitado) animação do Windows chama OnAnimationManagerStatusChanged quando o status do Gerenciador de animação é alterado.

##  <a name="enableanimationtimereventhandler"></a>  CAnimationController::EnableAnimationTimerEventHandler

Define ou libera um manipulador para eventos de tempo e o manipulador de atualizações de tempo.

```
virtual BOOL EnableAnimationTimerEventHandler(
    BOOL bEnable = TRUE,
    UI_ANIMATION_IDLE_BEHAVIOR idleBehavior = UI_ANIMATION_IDLE_BEHAVIOR_DISABLE);
```

### <a name="parameters"></a>Parâmetros

*bAtivar*<br/>
Especifica se deve definir ou liberar os manipuladores.

*idleBehavior*<br/>
Especifica o comportamento ocioso para manipulador de atualização do temporizador.

### <a name="return-value"></a>Valor de retorno

TRUE se manipuladores foram com êxito definidos ou liberados; FALSE se esse método é chamado pela segunda vez sem liberar os manipuladores pela primeira vez, ou se qualquer outro erro ocorre.

### <a name="remarks"></a>Comentários

Quando os manipuladores são definidos (habilitadas) chamadas à API de animação do Windows OnAnimationTimerPreUpdate, OnAnimationTimerPostUpdate, OnRenderingTooSlow métodos. Você precisa habilitar os temporizadores de animação permitir que a API de animação do Windows update storyboards. Caso contrário, você precisará chamar CAnimationController::UpdateAnimationManager para comandar a animação manager para atualizar os valores de todas as variáveis de animação.

##  <a name="enableprioritycomparisonhandler"></a>  CAnimationController::EnablePriorityComparisonHandler

Define ou libera o identificador de comparação de prioridade para chamar para determinar se um storyboard agendado pode ser cancelado, concluiu, cortado ou compactado.

```
virtual BOOL EnablePriorityComparisonHandler(DWORD dwHandlerType);
```

### <a name="parameters"></a>Parâmetros

*dwHandlerType*<br/>
Uma combinação de UI_ANIMATION_PHT_ sinalizadores (consulte comentários), que especifica quais manipuladores para definir ou liberar.

### <a name="return-value"></a>Valor de retorno

TRUE se o manipulador com êxito foi definido ou liberado.

### <a name="remarks"></a>Comentários

Quando um manipulador é definido (habilitado) animação do Windows chama os seguintes métodos virtuais dependendo dwHandlerType: OnHasPriorityCancel, OnHasPriorityConclude, OnHasPriorityTrim, OnHasPriorityCompress. dwHandler pode ser uma combinação dos seguintes sinalizadores: UI_ANIMATION_PHT_NONE - versão de todos os manipuladores UI_ANIMATION_PHT_CANCEL - definir cancelar o manipulador de comparação UI_ANIMATION_PHT_CONCLUDE - definir o manipulador de comparação Conclude UI_ANIMATION_PHT_COMPRESS - definir Manipulador de comparação Compress UI_ANIMATION_PHT_TRIM - definir o manipulador de comparação de corte UI_ANIMATION_PHT_CANCEL_REMOVE - Remover manipulador de comparação de cancelar UI_ANIMATION_PHT_CONCLUDE_REMOVE - Remover manipulador de comparação de Conclude UI_ANIMATION_PHT_COMPRESS_ Remover - Remover manipulador de comparação Compress UI_ANIMATION_PHT_TRIM_REMOVE - Remover manipulador de comparação de corte

##  <a name="enablestoryboardeventhandler"></a>  CAnimationController::EnableStoryboardEventHandler

Define ou libera um manipulador para eventos de status e a atualização do storyboard.

```
virtual BOOL EnableStoryboardEventHandler(
    UINT32 nGroupID,
    BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica a ID do grupo.

*bAtivar*<br/>
Especifica se deve definir ou liberar um manipulador.

### <a name="return-value"></a>Valor de retorno

TRUE se o manipulador com êxito foi definido ou liberado; FALSE se o grupo de animação especificado agora está localizado ou animação para o grupo especificado não foi iniciada e seu storyboard interno é nulo.

### <a name="remarks"></a>Comentários

Quando um manipulador é definido (habilitado) API de animação do Windows chama métodos virtuais OnStoryboardStatusChanges e OnStoryboardUpdated. Um manipulador deve ser definido depois CAnimationController::Animate tiver sido chamado para o grupo de animação especificado, pois ele cria o objeto de IUIAnimationStoryboard encapsulado.

##  <a name="findanimationgroup"></a>  CAnimationController::FindAnimationGroup

Localiza um grupo de animação pela sua ID de grupo.

```
CAnimationGroup* FindAnimationGroup(UINT32 nGroupID);
CAnimationGroup* FindAnimationGroup(IUIAnimationStoryboard* pStoryboard);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica uma ID do grupo.

*pStoryboard*<br/>
Um ponteiro para um storyboard.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o grupo de animação ou NULL se o grupo com a ID especificada não for encontrado.

### <a name="remarks"></a>Comentários

Use esse método para localizar um grupo de animação em tempo de execução. Um grupo é criado e adicionado à lista interna de grupos de animação quando um objeto de animação primeiro com a ID do grupo específico está sendo adicionado ao controlador de animação.

##  <a name="findanimationobject"></a>  CAnimationController::FindAnimationObject

Localiza o objeto de animação que contém uma variável de animação especificado.

```
BOOL FindAnimationObject(
    IUIAnimationVariable* pVariable,
    CAnimationBaseObject** ppObject,
    CAnimationGroup** ppGroup);
```

### <a name="parameters"></a>Parâmetros

*pVariable*<br/>
Um ponteiro para a variável de animação.

*ppObject*<br/>
Saída. Contém um ponteiro para o objeto de animação ou nulo.

*ppGroup*<br/>
Saída. Contém um ponteiro para o grupo de animação que contém o objeto de animação, ou nulo.

### <a name="return-value"></a>Valor de retorno

TRUE se o objeto foi encontrado; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chamado de manipuladores de eventos quando necessário para localizar um objeto de animação da variável de animação de entrada.

##  <a name="g_keyframestoryboardstart"></a>  CAnimationController::gkeyframeStoryboardStart

Um quadro-chave que representa o início do storyboard.

```
static CBaseKeyFrame gkeyframeStoryboardStart;
```

##  <a name="getkeyframestoryboardstart"></a>  CAnimationController::GetKeyframeStoryboardStart

Retorna um quadro-chave que identifica o início do storyboard.

```
static CBaseKeyFrame* GetKeyframeStoryboardStart();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o quadro-chave base, que identifica o início do storyboard.

### <a name="remarks"></a>Comentários

Obtenha esse quadro-chave base outros quadros-chave ou transições no momento no tempo quando um storyboard é iniciado.

##  <a name="getuianimationmanager"></a>  CAnimationController::GetUIAnimationManager

Fornece acesso ao objeto de IUIAnimationManager encapsulado.

```
IUIAnimationManager* GetUIAnimationManager();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a interface IUIAnimationManager ou nulo, se a falha na criação do Gerenciador de animação.

### <a name="remarks"></a>Comentários

Se o sistema operacional atual não oferece suporte a API de animação do Windows, esse método retornará nulo e depois que todas as chamadas subsequentes em CAnimationController::IsValid retornam FALSE. Você talvez precise acessar IUIAnimationManager para chamar seus métodos de interface, que não são encapsulados pelo controlador de animação.

##  <a name="getuianimationtimer"></a>  CAnimationController::GetUIAnimationTimer

Fornece acesso ao objeto de IUIAnimationTimer encapsulado.

```
IUIAnimationTimer* GetUIAnimationTimer();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a interface IUIAnimationTimer ou nulo, se a falha na criação do timer de animação.

### <a name="remarks"></a>Comentários

Se o sistema operacional atual não oferece suporte a API de animação do Windows, esse método retornará nulo e depois que todas as chamadas subsequentes em CAnimationController::IsValid retornam FALSE.

##  <a name="getuitransitionfactory"></a>  CAnimationController::GetUITransitionFactory

Um ponteiro para a interface IUIAnimationTransitionFactory ou nulo, se a falha na criação da biblioteca de transição.

```
IUIAnimationTransitionFactory* GetUITransitionFactory();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para IUIAnimationTransitionFactory ou nulo, se a falha na criação do fábrica de transição.

### <a name="remarks"></a>Comentários

Se o sistema operacional atual não oferece suporte a API de animação do Windows, esse método retornará nulo e depois que todas as chamadas subsequentes em CAnimationController::IsValid retornam FALSE.

##  <a name="getuitransitionlibrary"></a>  CAnimationController::GetUITransitionLibrary

Fornece acesso ao objeto de IUIAnimationTransitionLibrary encapsulado.

```
IUIAnimationTransitionLibrary* GetUITransitionLibrary();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a interface IUIAnimationTransitionLibrary ou nulo, se a falha na criação da biblioteca de transição.

### <a name="remarks"></a>Comentários

Se o sistema operacional atual não oferece suporte a API de animação do Windows, esse método retornará nulo e depois que todas as chamadas subsequentes em CAnimationController::IsValid retornam FALSE.

##  <a name="isanimationinprogress"></a>  CAnimationController::IsAnimationInProgress

Informa se pelo menos um grupo está sendo reproduzido a animação.

```
virtual BOOL IsAnimationInProgress();
```

### <a name="return-value"></a>Valor de retorno

TRUE se houver uma animação em andamento para esse controlador de animação; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Verifica o status do Gerenciador de animação e retorna TRUE se o status for UI_ANIMATION_MANAGER_BUSY.

##  <a name="isvalid"></a>  CAnimationController::IsValid

Informa se o controlador de animação é válido.

```
BOOL IsValid() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o controlador de animação é válido. Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método retorna FALSE apenas se a API de animação do Windows não é compatível com o sistema operacional atual e a criação do Gerenciador de animação falhou porque não está registrado. Você precisará chamar GetUIAnimationManager pelo menos uma vez após a inicialização de bibliotecas de COM para fazer com que a configuração desse sinalizador.

##  <a name="m_bisvalid"></a>  CAnimationController::m_bIsValid

Especifica se um controlador de animação é válido ou não. Esse membro é definido como FALSE se o sistema operacional atual não oferece suporte a API de animação do Windows.

```
BOOL m_bIsValid;
```

##  <a name="m_lstanimationgroups"></a>  CAnimationController::m_lstAnimationGroups

Uma lista de grupos de animação que pertencem a esse controlador de animação.

```
CList<CAnimationGroup*, CAnimationGroup*> m_lstAnimationGroups;
```

##  <a name="m_panimationmanager"></a>  CAnimationController::m_pAnimationManager

Armazena um ponteiro para objeto COM do Gerenciador de animação.

```
ATL::CComPtr<IUIAnimationManager> m_pAnimationManager;
```

##  <a name="m_panimationtimer"></a>  CAnimationController::m_pAnimationTimer

Armazena um ponteiro para objeto COM do temporizador de animação.

```
ATL::CComPtr<IUIAnimationTimer> m_pAnimationTimer;
```

##  <a name="m_prelatedwnd"></a>  CAnimationController::m_pRelatedWnd

Um ponteiro para um objeto CWnd relacionado, que pode ser redesenhado automaticamente quando o status do Gerenciador de animação é alterado ou ocorreu o evento de atualização de postagem. Pode ser NULL.

```
CWnd* m_pRelatedWnd;
```

##  <a name="m_ptransitionfactory"></a>  CAnimationController::m_pTransitionFactory

Armazena um ponteiro para objeto COM fábrica de transição.

```
ATL::CComPtr<IUIAnimationTransitionFactory> m_pTransitionFactory;
```

##  <a name="m_ptransitionlibrary"></a>  CAnimationController::m_pTransitionLibrary

Armazena um ponteiro para objeto COM biblioteca de transição.

```
ATL::CComPtr<IUIAnimationTransitionLibrary> m_pTransitionLibrary;
```

##  <a name="onafterschedule"></a>  CAnimationController::OnAfterSchedule

Chamado pelo framework quando uma animação para o grupo especificado apenas foi agendada.

```
virtual void OnAfterSchedule(CAnimationGroup* pGroup);
```

### <a name="parameters"></a>Parâmetros

*pGroup*<br/>
Um ponteiro para um grupo de animação que foi agendado.

### <a name="remarks"></a>Comentários

A implementação padrão remove os quadros-chave do grupo especificado e faz a transição de variáveis de animação que pertencem ao grupo especificado. Pode ser substituído em uma classe derivada para executar quaisquer ações adicionais após a agenda de animação.

##  <a name="onanimationintegervaluechanged"></a>  CAnimationController::OnAnimationIntegerValueChanged

Chamado pelo framework quando o valor inteiro da variável de animação é alterado.

```
virtual void OnAnimationIntegerValueChanged(
    CAnimationGroup* pGroup,
    CAnimationBaseObject* pObject,
    IUIAnimationVariable* variable,
    INT32 newValue,
    INT32 prevValue);
```

### <a name="parameters"></a>Parâmetros

*pGroup*<br/>
Um ponteiro para um grupo de animação que contém um objeto de animação cujo valor foi alterado.

*pObject*<br/>
Um ponteiro para um objeto de animação que contém uma variável de animação cujo valor foi alterado.

*variable*<br/>
Um ponteiro para uma variável de animação.

*newValue*<br/>
Especifica o novo valor.

*prevValue*<br/>
Especifica o valor anterior.

### <a name="remarks"></a>Comentários

Este método é chamado, se você habilitar eventos de variável de animação com EnableIntegerValueChangedEvent chamado para uma variável de animação específico ou um objeto de animação. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo.

##  <a name="onanimationmanagerstatuschanged"></a>  CAnimationController::OnAnimationManagerStatusChanged

Chamado pelo framework em resposta ao evento StatusChanged do Gerenciador de animação.

```
virtual void OnAnimationManagerStatusChanged(
    UI_ANIMATION_MANAGER_STATUS newStatus,
    UI_ANIMATION_MANAGER_STATUS previousStatus);
```

### <a name="parameters"></a>Parâmetros

*newStatus*<br/>
Novo status do Gerenciador de animação.

*previousStatus*<br/>
Status do Gerenciador de animação anterior.

### <a name="remarks"></a>Comentários

Este método é chamado, se você ativar eventos do Gerenciador de animação com EnableAnimationManagerEvent. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo. A implementação padrão de atualizações de uma janela relacionada se ele tiver sido definido com SetRelatedWnd.

##  <a name="onanimationtimerpostupdate"></a>  CAnimationController::OnAnimationTimerPostUpdate

Chamado pelo framework depois que uma atualização de animação for concluída.

```
virtual void OnAnimationTimerPostUpdate();
```

### <a name="remarks"></a>Comentários

Este método é chamado, se você habilitar os manipuladores de eventos do timer usando EnableAnimationTimerEventHandler. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo.

##  <a name="onanimationtimerpreupdate"></a>  CAnimationController::OnAnimationTimerPreUpdate

Chamado pelo framework antes do início de uma atualização de animação.

```
virtual void OnAnimationTimerPreUpdate();
```

### <a name="remarks"></a>Comentários

Este método é chamado, se você habilitar os manipuladores de eventos do timer usando EnableAnimationTimerEventHandler. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo.

##  <a name="onanimationtimerrenderingtooslow"></a>  CAnimationController::OnAnimationTimerRenderingTooSlow

Chamado pelo framework quando a taxa de quadros de renderização para uma animação fica abaixo de uma taxa de quadros desejável mínimo.

```
virtual void OnAnimationTimerRenderingTooSlow(UINT32 fps);
```

### <a name="parameters"></a>Parâmetros

*fps*<br/>
A taxa de quadros atual em quadros por segundo.

### <a name="remarks"></a>Comentários

Este método é chamado, se você habilitar os manipuladores de eventos do timer usando EnableAnimationTimerEventHandler. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo. A taxa de quadros desejável mínima é especificada chamando IUIAnimationTimer::SetFrameRateThreshold.

##  <a name="onanimationvaluechanged"></a>  CAnimationController::OnAnimationValueChanged

Chamado pelo framework quando o valor da variável de animação é alterado.

```
virtual void OnAnimationValueChanged(
    CAnimationGroup* pGroup,
    CAnimationBaseObject* pObject,
    IUIAnimationVariable* variable,
    DOUBLE newValue,
    DOUBLE prevValue);
```

### <a name="parameters"></a>Parâmetros

*pGroup*<br/>
Um ponteiro para um grupo de animação que contém um objeto de animação cujo valor foi alterado.

*pObject*<br/>
Um ponteiro para um objeto de animação que contém uma variável de animação cujo valor foi alterado.

*variable*<br/>
Um ponteiro para uma variável de animação.

*newValue*<br/>
Especifica o novo valor.

*prevValue*<br/>
Especifica o valor anterior.

### <a name="remarks"></a>Comentários

Este método é chamado, se você habilitar eventos de variável de animação com EnableValueChangedEvent chamado para uma variável de animação específico ou um objeto de animação. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo.

##  <a name="onbeforeanimationstart"></a>  CAnimationController::OnBeforeAnimationStart

Chamado pelo framework correto antes da animação é agendada.

```
virtual void OnBeforeAnimationStart(CAnimationGroup* pGroup);
```

### <a name="parameters"></a>Parâmetros

*pGroup*<br/>
Um ponteiro para um grupo de animação cuja animação está prestes a iniciar.

### <a name="remarks"></a>Comentários

Essa chamada será roteada para CWnd relacionado e pode ser substituída em uma classe derivada para executar ações adicionais antes da animação é iniciado para o grupo especificado.

##  <a name="onhasprioritycancel"></a>  CAnimationController::OnHasPriorityCancel

Chamado pelo framework para resolver conflitos de agendamento.

```
virtual BOOL OnHasPriorityCancel(
    CAnimationGroup* pGroupScheduled,
    CAnimationGroup* pGroupNew,
    UI_ANIMATION_PRIORITY_EFFECT priorityEffect);
```

### <a name="parameters"></a>Parâmetros

*pGroupScheduled*<br/>
O grupo que possui o storyboard no momento agendado.

*pGroupNew*<br/>
O grupo que possui o novo storyboard que está em conflito de agendamento com o storyboard agendado pertencente a pGroupScheduled.

*priorityEffect*<br/>
O efeito potencial no pGroupNew se pGroupScheduled tem uma prioridade mais alta.

### <a name="return-value"></a>Valor de retorno

Deve retornar TRUE se o storyboard pertencente a pGroupNew tem prioridade. Deve retornar FALSE se o storyboard pertencente a pGroupScheduled tem prioridade.

### <a name="remarks"></a>Comentários

Esse método é chamado, se você habilitar os eventos de comparação de prioridade usando CAnimationController::EnablePriorityComparisonHandler e especificar UI_ANIMATION_PHT_CANCEL. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo. Documentação da API de animação do Windows de leitura para obter mais informações sobre [gerenciamento de conflito](https://msdn.microsoft.com/library/dd371759).

##  <a name="onhasprioritycompress"></a>  CAnimationController::OnHasPriorityCompress

Chamado pelo framework para resolver conflitos de agendamento.

```
virtual BOOL OnHasPriorityCompress(
    CAnimationGroup* pGroupScheduled,
    CAnimationGroup* pGroupNew,
    UI_ANIMATION_PRIORITY_EFFECT priorityEffect);
```

### <a name="parameters"></a>Parâmetros

*pGroupScheduled*<br/>
O grupo que possui o storyboard no momento agendado.

*pGroupNew*<br/>
O grupo que possui o novo storyboard que está em conflito de agendamento com o storyboard agendado pertencente a pGroupScheduled.

*priorityEffect*<br/>
O efeito potencial no pGroupNew se pGroupScheduled tem uma prioridade mais alta.

### <a name="return-value"></a>Valor de retorno

Deve retornar TRUE se o storyboard pertencente a pGroupNew tem prioridade. Deve retornar FALSE se o storyboard pertencente a pGroupScheduled tem prioridade.

### <a name="remarks"></a>Comentários

Esse método é chamado, se você habilitar os eventos de comparação de prioridade usando CAnimationController::EnablePriorityComparisonHandler e especificar UI_ANIMATION_PHT_COMPRESS. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo. Documentação da API de animação do Windows de leitura para obter mais informações sobre [gerenciamento de conflito](https://msdn.microsoft.com/library/dd371759).

##  <a name="onhaspriorityconclude"></a>  CAnimationController::OnHasPriorityConclude

Chamado pelo framework para resolver conflitos de agendamento.

```
virtual BOOL OnHasPriorityConclude(
    CAnimationGroup* pGroupScheduled,
    CAnimationGroup* pGroupNew,
    UI_ANIMATION_PRIORITY_EFFECT priorityEffect);
```

### <a name="parameters"></a>Parâmetros

*pGroupScheduled*<br/>
O grupo que possui o storyboard no momento agendado.

*pGroupNew*<br/>
O grupo que possui o novo storyboard que está em conflito de agendamento com o storyboard agendado pertencente a pGroupScheduled.

*priorityEffect*<br/>
O efeito potencial no pGroupNew se pGroupScheduled tem uma prioridade mais alta.

### <a name="return-value"></a>Valor de retorno

Deve retornar TRUE se o storyboard pertencente a pGroupNew tem prioridade. Deve retornar FALSE se o storyboard pertencente a pGroupScheduled tem prioridade.

### <a name="remarks"></a>Comentários

Esse método é chamado, se você habilitar os eventos de comparação de prioridade usando CAnimationController::EnablePriorityComparisonHandler e especificar UI_ANIMATION_PHT_CONCLUDE. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo. Documentação da API de animação do Windows de leitura para obter mais informações sobre [gerenciamento de conflito](https://msdn.microsoft.com/library/dd371759).

##  <a name="onhasprioritytrim"></a>  CAnimationController::OnHasPriorityTrim

Chamado pelo framework para resolver conflitos de agendamento.

```
virtual BOOL OnHasPriorityTrim(
    CAnimationGroup* pGroupScheduled,
    CAnimationGroup* pGroupNew,
    UI_ANIMATION_PRIORITY_EFFECT priorityEffect);
```

### <a name="parameters"></a>Parâmetros

*pGroupScheduled*<br/>
O grupo que possui o storyboard no momento agendado.

*pGroupNew*<br/>
O grupo que possui o novo storyboard que está em conflito de agendamento com o storyboard agendado pertencente a pGroupScheduled.

*priorityEffect*<br/>
O efeito potencial no pGroupNew se pGroupScheduled tem uma prioridade mais alta.

### <a name="return-value"></a>Valor de retorno

Deve retornar TRUE se o storyboard pertencente a pGroupNew tem prioridade. Deve retornar FALSE se o storyboard pertencente a pGroupScheduled tem prioridade.

### <a name="remarks"></a>Comentários

Esse método é chamado, se você habilitar os eventos de comparação de prioridade usando CAnimationController::EnablePriorityComparisonHandler e especificar UI_ANIMATION_PHT_TRIM. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo. Documentação da API de animação do Windows de leitura para obter mais informações sobre [gerenciamento de conflito](https://msdn.microsoft.com/library/dd371759).

##  <a name="onstoryboardstatuschanged"></a>  CAnimationController::OnStoryboardStatusChanged

Chamado pelo framework quando o status de storyboard foi alterado.

```
virtual void OnStoryboardStatusChanged(
    CAnimationGroup* pGroup,
    UI_ANIMATION_STORYBOARD_STATUS newStatus,
    UI_ANIMATION_STORYBOARD_STATUS previousStatus);
```

### <a name="parameters"></a>Parâmetros

*pGroup*<br/>
Um ponteiro para um grupo de animação que possui o storyboard cujo status foi alterado.

*newStatus*<br/>
Especifica o novo status.

*previousStatus*<br/>
Especifica o status anterior.

### <a name="remarks"></a>Comentários

Este método é chamado, se você habilitar os eventos de storyboard usando CAnimationController::EnableStoryboardEventHandler. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo.

##  <a name="onstoryboardupdated"></a>  CAnimationController::OnStoryboardUpdated

Chamado pelo framework quando o storyboard foi atualizado.

```
virtual void OnStoryboardUpdated(CAnimationGroup* pGroup);
```

### <a name="parameters"></a>Parâmetros

*pGroup*<br/>
Um ponteiro para um grupo que possui o storyboard.

### <a name="remarks"></a>Comentários

Este método é chamado, se você habilitar os eventos de storyboard usando CAnimationController::EnableStoryboardEventHandler. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo.

##  <a name="removeallanimationgroups"></a>  CAnimationController::RemoveAllAnimationGroups

Remove todos os grupos de animação do controlador de animação.

```
void RemoveAllAnimationGroups();
```

### <a name="remarks"></a>Comentários

Todos os grupos serão excluídos, o ponteiro se armazenado no nível do aplicativo, deve ser invalidado. Se CAnimationGroup::m_bAutodestroyAnimationObjects para um grupo que está sendo excluído for TRUE, todos os objetos de animação que pertencem a esse grupo serão excluídos; Caso contrário, suas referências ao controlador de animação do pai serão definidas como NULL e eles podem ser adicionados para outro controlador.

##  <a name="removeanimationgroup"></a>  CAnimationController::RemoveAnimationGroup

Remove um grupo de animação com a ID especificada do controlador de animação.

```
void RemoveAnimationGroup(UINT32 nGroupID);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica a ID do grupo de animação.

### <a name="remarks"></a>Comentários

Esse método Remove um grupo de animação da lista interna de grupos e exclui-lo, portanto se você tiver armazenado um ponteiro para esse grupo de animação, ele deve ser invalidado. Se CAnimationGroup::m_bAutodestroyAnimationObjects for TRUE, todos os objetos de animação que pertencem a esse grupo serão excluídos; Caso contrário, suas referências ao controlador de animação do pai serão definidas como NULL e eles podem ser adicionados para outro controlador.

##  <a name="removeanimationobject"></a>  CAnimationController::RemoveAnimationObject

Remova um objeto de animação do controlador de animação.

```
void RemoveAnimationObject(
    CAnimationBaseObject* pObject,
    BOOL bNoDelete = FALSE);
```

### <a name="parameters"></a>Parâmetros

*pObject*<br/>
Um ponteiro para um objeto de animação.

*bNoDelete*<br/>
Se esse parâmetro for verdadeiro o objeto não será excluído após a remoção.

### <a name="remarks"></a>Comentários

Remove um objeto de animação do controlador de animação e o grupo de animação. Chame essa função se um determinado objeto não deve ser animado mais, ou se você precisar mover o objeto para outro controlador de animação. No último caso bNoDelete deve ser verdadeiro.

##  <a name="removetransitions"></a>  CAnimationController::RemoveTransitions

Remove as transições de objetos de animação que pertencem ao grupo especificado.

```
void RemoveTransitions(UINT32 nGroupID);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica a ID do grupo.

### <a name="remarks"></a>Comentários

O grupo faz um loop sobre seus objetos de animação e chama ClearTransitions(FALSE) para cada objeto de animação. Esse método é chamado pelo framework depois animação foi agendada.

##  <a name="schedulegroup"></a>  CAnimationController::ScheduleGroup

Agenda uma animação.

```
BOOL ScheduleGroup(
    UINT32 nGroupID,
    UI_ANIMATION_SECONDS time = 0.0);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica a animação ID de grupo para agendar.

*time*<br/>
Especifica a hora de agendar.

### <a name="return-value"></a>Valor de retorno

TRUE se a animação foi agendada com êxito. FALSE se não tiver sido criado um storyboard ou outro erro ocorre.

### <a name="remarks"></a>Comentários

Você deve chamar AnimateGroup com bScheduleNow parâmetro definido como FALSE ScheduleGroup anterior. Você pode especificar o tempo de animação desejado é obtido do IUIAnimationTimer::GetTime. Se o parâmetro de tempo é 0.0, a animação está agendada para a hora atual.

##  <a name="setrelatedwnd"></a>  CAnimationController::SetRelatedWnd

Estabelece uma relação entre o controlador de animação e uma janela.

```
void SetRelatedWnd(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Apropriei*<br/>
Um ponteiro para o objeto de janela a ser definido.

### <a name="remarks"></a>Comentários

Se um objeto CWnd relacionado for definido, o controlador de animação automaticamente pode atualizá-lo (Enviar mensagem WM_PAINT) quando o status do Gerenciador de animação foi alterado ou ocorreu o evento de atualização de postagem de temporizador.

##  <a name="updateanimationmanager"></a>  CAnimationController::UpdateAnimationManager

Direciona o Gerenciador de animação para atualizar os valores de todas as variáveis de animação.

```
virtual void UpdateAnimationManager();
```

### <a name="remarks"></a>Comentários

Chamar que esse método avança o Gerenciador de animação à hora atual, alterar o status de storyboards conforme necessário e atualizar todas as variáveis de animação apropriado interpolada valores. Esse método chama internamente IUIAnimationTimer::GetTime(timeNow) e IUIAnimationManager::Update(timeNow). Substitua este método em uma classe derivada para personalizar esse comportamento.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
