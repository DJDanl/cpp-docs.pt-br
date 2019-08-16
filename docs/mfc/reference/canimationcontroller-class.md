---
title: Classe CAnimationController
ms.date: 03/27/2019
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
ms.openlocfilehash: 9039d44d9ef36a47c11b3ecaddf232ad427727c4
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69507645"
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
|[CAnimationController:: ~ CAnimationController](#_dtorcanimationcontroller)|O destruidor. Chamado quando o objeto do controlador de animação está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationController::AddAnimationObject](#addanimationobject)|Adiciona um objeto de animação a um grupo que pertence ao controlador de animação.|
|[CAnimationController::AddKeyframeToGroup](#addkeyframetogroup)|Adiciona um quadro-chave ao grupo.|
|[CAnimationController::AnimateGroup](#animategroup)|Prepara um grupo para executar a animação e, opcionalmente, a agenda.|
|[CAnimationController:: CleanUp](#cleanupgroup)|Sobrecarregado. Chamado pelo Framework para limpar o grupo quando a animação tiver sido agendada.|
|[CAnimationController::CreateKeyframe](#createkeyframe)|Sobrecarregado. Cria um quadro-chave que depende da transição e a adiciona ao grupo especificado.|
|[CAnimationController::EnableAnimationManagerEvent](#enableanimationmanagerevent)|Define ou libera um manipulador para chamar quando o status do Gerenciador de animação for alterado.|
|[CAnimationController::EnableAnimationTimerEventHandler](#enableanimationtimereventhandler)|Define ou libera um manipulador para eventos de temporização e manipulador para atualizações de tempo.|
|[CAnimationController::EnablePriorityComparisonHandler](#enableprioritycomparisonhandler)|Define ou libera o manipulador de comparação de prioridade a ser chamado para determinar se um storyboard agendado pode ser cancelado, concluído, cortado ou compactado.|
|[CAnimationController::EnableStoryboardEventHandler](#enablestoryboardeventhandler)|Define ou libera um manipulador para o status do storyboard e eventos de atualização.|
|[CAnimationController::FindAnimationGroup](#findanimationgroup)|Sobrecarregado. Localiza um grupo de animação por seu Storyboard.|
|[CAnimationController::FindAnimationObject](#findanimationobject)|Localiza o objeto de animação que contém uma variável de animação especificada.|
|[CAnimationController::GetKeyframeStoryboardStart](#getkeyframestoryboardstart)|Retorna um quadro-chave que identifica o início do storyboard.|
|[CAnimationController::GetUIAnimationManager](#getuianimationmanager)|Fornece acesso ao objeto encapsulado IUIAnimationManager.|
|[CAnimationController::GetUIAnimationTimer](#getuianimationtimer)|Fornece acesso ao objeto encapsulado IUIAnimationTimer.|
|[CAnimationController::GetUITransitionFactory](#getuitransitionfactory)|Um ponteiro para IUIAnimationTransitionFactory interface ou NULL, se a criação da biblioteca de transição falhar.|
|[CAnimationController::GetUITransitionLibrary](#getuitransitionlibrary)|Fornece acesso ao objeto encapsulado IUIAnimationTransitionLibrary.|
|[CAnimationController::IsAnimationInProgress](#isanimationinprogress)|Informa se pelo menos um grupo está executando a animação.|
|[CAnimationController::IsValid](#isvalid)|Informa se o controlador de animação é válido.|
|[CAnimationController::OnAnimationIntegerValueChanged](#onanimationintegervaluechanged)|Chamado pelo Framework quando o valor inteiro da variável de animação foi alterado.|
|[CAnimationController::OnAnimationManagerStatusChanged](#onanimationmanagerstatuschanged)|Chamado pelo Framework em resposta ao evento StatusChanged do Gerenciador de animação.|
|[CAnimationController::OnAnimationTimerPostUpdate](#onanimationtimerpostupdate)|Chamado pelo Framework após a conclusão de uma atualização de animação.|
|[CAnimationController::OnAnimationTimerPreUpdate](#onanimationtimerpreupdate)|Chamado pelo Framework antes do início de uma atualização de animação.|
|[CAnimationController::OnAnimationTimerRenderingTooSlow](#onanimationtimerrenderingtooslow)|Chamado pelo Framework quando a taxa de quadros de renderização de uma animação cai abaixo de uma taxa de quadros desejável mínima.|
|[CAnimationController::OnAnimationValueChanged](#onanimationvaluechanged)|Chamado pelo Framework quando o valor da variável de animação foi alterado.|
|[CAnimationController::OnBeforeAnimationStart](#onbeforeanimationstart)|Chamado pelo Framework logo antes que a animação seja agendada.|
|[CAnimationController::OnHasPriorityCancel](#onhasprioritycancel)|Chamado pelo Framework para resolver conflitos de agendamento.|
|[CAnimationController::OnHasPriorityCompress](#onhasprioritycompress)|Chamado pelo Framework para resolver conflitos de agendamento.|
|[CAnimationController::OnHasPriorityConclude](#onhaspriorityconclude)|Chamado pelo Framework para resolver conflitos de agendamento.|
|[CAnimationController::OnHasPriorityTrim](#onhasprioritytrim)|Chamado pelo Framework para resolver conflitos de agendamento.|
|[CAnimationController::OnStoryboardStatusChanged](#onstoryboardstatuschanged)|Chamado pelo Framework quando o status do storyboard é alterado.|
|[CAnimationController::OnStoryboardUpdated](#onstoryboardupdated)|Chamado pelo Framework quando o storyboard foi atualizado.|
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
|[CAnimationController:: CleanUp](#cleanupgroup)|Sobrecarregado. Um auxiliar que limpa o grupo.|
|[CAnimationController::OnAfterSchedule](#onafterschedule)|Chamado pelo Framework quando uma animação para o grupo especificado acabou de ser agendada.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationController::gkeyframeStoryboardStart](#g_keyframestoryboardstart)|Um quadro-chave que representa o início do storyboard.|
|[CAnimationController::m_bIsValid](#m_bisvalid)|Especifica se um controlador de animação é válido ou não. Esse membro será definido como FALSE se o sistema operacional atual não oferecer suporte à API de animação do Windows.|
|[CAnimationController::m_lstAnimationGroups](#m_lstanimationgroups)|Uma lista de grupos de animação que pertencem a este controlador de animação.|
|[CAnimationController::m_pAnimationManager](#m_panimationmanager)|Armazena um ponteiro para o objeto COM do Gerenciador de animação.|
|[CAnimationController::m_pAnimationTimer](#m_panimationtimer)|Armazena um ponteiro para objeto COM do temporizador de animação.|
|[CAnimationController::m_pRelatedWnd](#m_prelatedwnd)|Um ponteiro para um objeto CWnd relacionado, que pode ser redesenhado automaticamente quando o status do Gerenciador de animação for alterado ou o evento post update tiver ocorrido. Pode ser NULL.|
|[CAnimationController::m_pTransitionFactory](#m_ptransitionfactory)|Armazena um ponteiro para o objeto COM da fábrica de transição.|
|[CAnimationController::m_pTransitionLibrary](#m_ptransitionlibrary)|Armazena um ponteiro para o objeto COM da biblioteca de transição.|

## <a name="remarks"></a>Comentários

A classe CAnimationController é a classe de chave que gerencia animações. Você pode criar uma ou mais instâncias do controlador de animação em um aplicativo e, opcionalmente, conectar uma instância do controlador de animação a um objeto CWnd usando CAnimationController:: SetRelatedWnd. Essa conexão é necessária para enviar mensagens WM_PAINT para a janela relacionada automaticamente quando o status do Gerenciador de animação tiver sido alterado ou o temporizador de animação tiver sido atualizado. Se você não habilitar essa relação, deverá redesenhar uma janela que exibe uma animação manualmente. Para essa finalidade, você pode derivar uma classe de CAnimationController e substituir OnAnimationManagerStatusChanged e/ou OnAnimationTimerPostUpdate e invalidar uma ou mais janelas quando necessário.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CAnimationController`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller. h

##  <a name="_dtorcanimationcontroller"></a>CAnimationController:: ~ CAnimationController

O destruidor. Chamado quando o objeto do controlador de animação está sendo destruído.

```
virtual ~CAnimationController(void);
```

##  <a name="addanimationobject"></a>  CAnimationController::AddAnimationObject

Adiciona um objeto de animação a um grupo que pertence ao controlador de animação.

```
CAnimationGroup* AddAnimationObject(CAnimationBaseObject* pObject);
```

### <a name="parameters"></a>Parâmetros

*pObject*<br/>
Um ponteiro para um objeto de animação.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um grupo de animação novo ou existente em que pObject foi adicionado se a função for concluída com sucesso; NULL se pObject já tiver sido adicionado a um grupo que pertence a outro controlador de animação.

### <a name="remarks"></a>Comentários

Chame esse método para adicionar um objeto de animação ao controlador de animação. Um objeto será adicionado a um grupo de acordo com GroupId do objeto (consulte CAnimationBaseObject:: SetID). O controlador de animação criará um novo grupo se ele for o primeiro objeto que está sendo adicionado com o GroupId especificado. Um objeto de animação só pode ser adicionado a um controlador de animação. Se você precisar adicionar um objeto a outro controlador, chame RemoveAnimationObject primeiro. Se você chamar SetID com novo GroupId para um objeto que já foi adicionado a um grupo, o objeto será removido do grupo antigo e adicionado a outro grupo com a ID especificada.

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

TRUE se a função for realizada com sucesso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Em geral, você não precisa chamar esse método, use CAnimationController:: createkeyframe, que cria e adiciona o quadro-chave criado a um grupo automaticamente.

##  <a name="animategroup"></a>  CAnimationController::AnimateGroup

Prepara um grupo para executar a animação e, opcionalmente, a agenda.

```
BOOL AnimateGroup(
    UINT32 nGroupID,
    BOOL bScheduleNow = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica GroupId.

*bScheduleNow*<br/>
Especifica se a animação deve ser executada imediatamente.

### <a name="return-value"></a>Valor de retorno

TRUE se a animação tiver sido agendada e executada com êxito.

### <a name="remarks"></a>Comentários

Esse método faz o trabalho real criando storyboard, adicionando variáveis de animação, aplicando transições e Configurando quadros-chave. É possível atrasar o agendamento se você definir bScheduleNow como FALSE. Nesse caso, o grupo especificado manterá um Storyboard que foi configurado para animação. Nesse ponto, você pode configurar eventos para as variáveis storyboard e Animation. Quando você realmente precisa executar a chamada de animação CAnimationController:: Schedule.

##  <a name="canimationcontroller"></a>CAnimationController::CAnimationController

Constrói um controlador de animação.

```
CAnimationController(void);
```

##  <a name="cleanupgroup"></a>CAnimationController:: CleanUp

Chamado pelo Framework para limpar o grupo quando a animação tiver sido agendada.

```
void CleanUpGroup(UINT32 nGroupID);
void CleanUpGroup(CAnimationGroup* pGroup);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica GroupId.

*pGroup*<br/>
Um ponteiro para o grupo de animação a ser limpo.

### <a name="remarks"></a>Comentários

Esse método remove todas as transições e quadros-chave do grupo especificado, pois eles não são relevantes depois que uma animação é agendada.

##  <a name="createkeyframe"></a>  CAnimationController::CreateKeyframe

Cria um quadro-chave que depende da transição e a adiciona ao grupo especificado.

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
Especifica a ID do grupo para o qual o quadro-chave é criado.

*pTransition*<br/>
Um ponteiro para fazer a transição. O quadro-chave será inserido no Storyboard após essa transição.

*pKeyframe*<br/>
Um ponteiro para o quadro-chave base para este quadro-chave.

*deslocamento*<br/>
Deslocamento em segundos a partir do quadro chave base especificado por pKeyframe.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o quadro-chave recém-criado se a função tiver sucesso.

### <a name="remarks"></a>Comentários

Você pode armazenar o ponteiro retornado e basear outros quadros principais no quadro-chave recém-criado (consulte a segunda sobrecarga). É possível iniciar as transições em quadros-chave-consulte CBaseTransition:: setkeyframes. Você não precisa excluir quadros-chave criados dessa forma, pois eles são excluídos automaticamente por grupos de animação. Tenha cuidado ao criar quadros-chave com base em outros quadros-chave e transições e evite referências circulares.

##  <a name="enableanimationmanagerevent"></a>  CAnimationController::EnableAnimationManagerEvent

Define ou libera um manipulador para chamar quando o status do Gerenciador de animação for alterado.

```
virtual BOOL EnableAnimationManagerEvent(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
Especifica se deve ser definido ou liberado um manipulador.

### <a name="return-value"></a>Valor de retorno

TRUE se o manipulador tiver sido definido ou liberado com êxito.

### <a name="remarks"></a>Comentários

Quando um manipulador é definido (habilitado), a animação do Windows chama OnAnimationManagerStatusChanged quando o status do Gerenciador de animação é alterado.

##  <a name="enableanimationtimereventhandler"></a>  CAnimationController::EnableAnimationTimerEventHandler

Define ou libera um manipulador para eventos de temporização e manipulador para atualizações de tempo.

```
virtual BOOL EnableAnimationTimerEventHandler(
    BOOL bEnable = TRUE,
    UI_ANIMATION_IDLE_BEHAVIOR idleBehavior = UI_ANIMATION_IDLE_BEHAVIOR_DISABLE);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
Especifica se os manipuladores devem ser definidos ou liberados.

*idleBehavior*<br/>
Especifica o comportamento ocioso para o manipulador de atualização de timer.

### <a name="return-value"></a>Valor de retorno

TRUE se os manipuladores foram definidos ou liberados com êxito; FALSE se esse método for chamado por uma segunda vez sem liberar os manipuladores primeiro ou se ocorrer algum outro erro.

### <a name="remarks"></a>Comentários

Quando os manipuladores são definidos (habilitados), a API de animação do Windows chama os métodos OnAnimationTimerPreUpdate, OnAnimationTimerPostUpdate e OnRenderingTooSlow. Você precisa habilitar temporizadores de animação para permitir que os storyboards de atualização da API de animação do Windows. Caso contrário, você precisará chamar CAnimationController:: UpdateAnimationManager para direcionar o Gerenciador de animação a atualizar os valores de todas as variáveis de animação.

##  <a name="enableprioritycomparisonhandler"></a>  CAnimationController::EnablePriorityComparisonHandler

Define ou libera o manipulador de comparação de prioridade a ser chamado para determinar se um storyboard agendado pode ser cancelado, concluído, cortado ou compactado.

```
virtual BOOL EnablePriorityComparisonHandler(DWORD dwHandlerType);
```

### <a name="parameters"></a>Parâmetros

*dwHandlerType*<br/>
Uma combinação de sinalizadores UI_ANIMATION_PHT_ (consulte comentários), que especifica quais manipuladores definir ou liberar.

### <a name="return-value"></a>Valor de retorno

TRUE se o manipulador tiver sido definido ou liberado com êxito.

### <a name="remarks"></a>Comentários

Quando um manipulador é definido (habilitado), a animação do Windows chama os seguintes métodos virtuais, dependendo do dwHandlerType: OnHasPriorityCancel, OnHasPriorityConclude, OnHasPriorityTrim, OnHasPriorityCompress. dwHandler pode ser uma combinação dos seguintes sinalizadores: UI_ANIMATION_PHT_NONE-liberar todos os manipuladores UI_ANIMATION_PHT_CANCEL-definir cancelar o manipulador de comparação UI_ANIMATION_PHT_CONCLUDE-Set concluir manipulador de comparação UI_ANIMATION_PHT_COMPRESS-definir o manipulador de comparação de compactação UI_ANIMATION_PHT_TRIM-Set Aparar manipulador de comparação UI_ANIMATION_PHT_CANCEL_REMOVE-remover cancelar manipulador de comparação UI_ANIMATION_PHT_CONCLUDE_REMOVE-remover concluir manipulador de comparação UI_ANIMATION_PHT_COMPRESS_REMOVE-remover o manipulador de comparação de compactação UI_ANIMATION_PHT _TRIM_REMOVE-remover manipulador de comparação de corte

##  <a name="enablestoryboardeventhandler"></a>  CAnimationController::EnableStoryboardEventHandler

Define ou libera um manipulador para o status do storyboard e eventos de atualização.

```
virtual BOOL EnableStoryboardEventHandler(
    UINT32 nGroupID,
    BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica a ID do grupo.

*bEnable*<br/>
Especifica se deve ser definido ou liberado um manipulador.

### <a name="return-value"></a>Valor de retorno

TRUE se o manipulador tiver sido definido ou liberado com êxito; FALSE se o grupo de animação especificado agora for encontrado ou a animação para o grupo especificado não tiver sido iniciada e seu storyboard interno for nulo.

### <a name="remarks"></a>Comentários

Quando um manipulador é definido (habilitado) a API de animação do Windows chama os métodos virtuais OnStoryboardStatusChanges e OnStoryboardUpdated. Um manipulador deve ser definido após CAnimationController:: Animate ter sido chamado para o grupo de animação especificado, pois ele cria um objeto IUIAnimationStoryboard encapsulado.

##  <a name="findanimationgroup"></a>  CAnimationController::FindAnimationGroup

Localiza um grupo de animação por sua ID de grupo.

```
CAnimationGroup* FindAnimationGroup(UINT32 nGroupID);
CAnimationGroup* FindAnimationGroup(IUIAnimationStoryboard* pStoryboard);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica um GroupId.

*pStoryboard*<br/>
Um ponteiro para um Storyboard.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um grupo de animação ou nulo se o grupo com a ID especificada não for encontrado.

### <a name="remarks"></a>Comentários

Use este método para localizar um grupo de animação em tempo de execução. Um grupo é criado e adicionado à lista interna de grupos de animação quando um primeiro objeto de animação com GroupId específico está sendo adicionado ao controlador de animação.

##  <a name="findanimationobject"></a>CAnimationController::FindAnimationObject

Localiza o objeto de animação que contém uma variável de animação especificada.

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
Der. Contém um ponteiro para objeto de animação ou nulo.

*ppGroup*<br/>
Der. Contém um ponteiro para um grupo de animação que contém o objeto de animação ou nulo.

### <a name="return-value"></a>Valor de retorno

TRUE se o objeto foi encontrado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chamado de manipuladores de eventos quando é necessário encontrar um objeto de animação da variável de animação de entrada.

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

Um ponteiro para o quadro-chave de base, que identifica o início do storyboard.

### <a name="remarks"></a>Comentários

Obtenha este quadro-chave para basear quaisquer outros quadros chave ou transições no momento em que um Storyboard é iniciado.

##  <a name="getuianimationmanager"></a>  CAnimationController::GetUIAnimationManager

Fornece acesso ao objeto encapsulado IUIAnimationManager.

```
IUIAnimationManager* GetUIAnimationManager();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para IUIAnimationManager interface ou NULL, se a criação do Gerenciador de animação falhar.

### <a name="remarks"></a>Comentários

Se o sistema operacional atual não oferecer suporte à API de animação do Windows, esse método retornará nulo e depois que todas as chamadas subsequentes em CAnimationController:: IsValid retornarem FALSE. Talvez seja necessário acessar o IUIAnimationManager para chamar seus métodos de interface, que não são encapsulados pelo controlador de animação.

##  <a name="getuianimationtimer"></a>  CAnimationController::GetUIAnimationTimer

Fornece acesso ao objeto encapsulado IUIAnimationTimer.

```
IUIAnimationTimer* GetUIAnimationTimer();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para IUIAnimationTimer interface ou NULL se a criação do temporizador de animação falhar.

### <a name="remarks"></a>Comentários

Se o sistema operacional atual não oferecer suporte à API de animação do Windows, esse método retornará nulo e depois que todas as chamadas subsequentes em CAnimationController:: IsValid retornarem FALSE.

##  <a name="getuitransitionfactory"></a>  CAnimationController::GetUITransitionFactory

Um ponteiro para IUIAnimationTransitionFactory interface ou NULL, se a criação da biblioteca de transição falhar.

```
IUIAnimationTransitionFactory* GetUITransitionFactory();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para IUIAnimationTransitionFactory ou NULL, se a criação da fábrica de transição falhar.

### <a name="remarks"></a>Comentários

Se o sistema operacional atual não oferecer suporte à API de animação do Windows, esse método retornará nulo e depois que todas as chamadas subsequentes em CAnimationController:: IsValid retornarem FALSE.

##  <a name="getuitransitionlibrary"></a>  CAnimationController::GetUITransitionLibrary

Fornece acesso ao objeto encapsulado IUIAnimationTransitionLibrary.

```
IUIAnimationTransitionLibrary* GetUITransitionLibrary();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para IUIAnimationTransitionLibrary interface ou NULL, se a criação da biblioteca de transição falhar.

### <a name="remarks"></a>Comentários

Se o sistema operacional atual não oferecer suporte à API de animação do Windows, esse método retornará nulo e depois que todas as chamadas subsequentes em CAnimationController:: IsValid retornarem FALSE.

##  <a name="isanimationinprogress"></a>  CAnimationController::IsAnimationInProgress

Informa se pelo menos um grupo está executando a animação.

```
virtual BOOL IsAnimationInProgress();
```

### <a name="return-value"></a>Valor de retorno

TRUE se houver uma animação em andamento para esse controlador de animação; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Verifica o status do Gerenciador de animação e retorna TRUE se o status for UI_ANIMATION_MANAGER_BUSY.

##  <a name="isvalid"></a>  CAnimationController::IsValid

Informa se o controlador de animação é válido.

```
BOOL IsValid() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o controlador de animação for válido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método retornará FALSE somente se a API de animação do Windows não tiver suporte no sistema operacional atual e a criação do Gerenciador de animação falhar porque ela não está registrada. Você precisa chamar GetUIAnimationManager pelo menos uma vez após a inicialização de bibliotecas COM para causar a configuração desse sinalizador.

##  <a name="m_bisvalid"></a>  CAnimationController::m_bIsValid

Especifica se um controlador de animação é válido ou não. Esse membro será definido como FALSE se o sistema operacional atual não oferecer suporte à API de animação do Windows.

```
BOOL m_bIsValid;
```

##  <a name="m_lstanimationgroups"></a>  CAnimationController::m_lstAnimationGroups

Uma lista de grupos de animação que pertencem a este controlador de animação.

```
CList<CAnimationGroup*, CAnimationGroup*> m_lstAnimationGroups;
```

##  <a name="m_panimationmanager"></a>  CAnimationController::m_pAnimationManager

Armazena um ponteiro para o objeto COM do Gerenciador de animação.

```
ATL::CComPtr<IUIAnimationManager> m_pAnimationManager;
```

##  <a name="m_panimationtimer"></a>  CAnimationController::m_pAnimationTimer

Armazena um ponteiro para objeto COM do temporizador de animação.

```
ATL::CComPtr<IUIAnimationTimer> m_pAnimationTimer;
```

##  <a name="m_prelatedwnd"></a>  CAnimationController::m_pRelatedWnd

Um ponteiro para um objeto CWnd relacionado, que pode ser redesenhado automaticamente quando o status do Gerenciador de animação for alterado ou o evento post update tiver ocorrido. Pode ser NULL.

```
CWnd* m_pRelatedWnd;
```

##  <a name="m_ptransitionfactory"></a>  CAnimationController::m_pTransitionFactory

Armazena um ponteiro para o objeto COM da fábrica de transição.

```
ATL::CComPtr<IUIAnimationTransitionFactory> m_pTransitionFactory;
```

##  <a name="m_ptransitionlibrary"></a>  CAnimationController::m_pTransitionLibrary

Armazena um ponteiro para o objeto COM da biblioteca de transição.

```
ATL::CComPtr<IUIAnimationTransitionLibrary> m_pTransitionLibrary;
```

##  <a name="onafterschedule"></a>  CAnimationController::OnAfterSchedule

Chamado pelo Framework quando uma animação para o grupo especificado acabou de ser agendada.

```
virtual void OnAfterSchedule(CAnimationGroup* pGroup);
```

### <a name="parameters"></a>Parâmetros

*pGroup*<br/>
Um ponteiro para um grupo de animação, que foi agendado.

### <a name="remarks"></a>Comentários

A implementação padrão remove quadros-chave do grupo especificado e faz a transição de variáveis de animação que pertencem ao grupo especificado. Pode ser substituído em uma classe derivada para realizar qualquer ação adicional no agendamento de animação.

##  <a name="onanimationintegervaluechanged"></a>  CAnimationController::OnAnimationIntegerValueChanged

Chamado pelo Framework quando o valor inteiro da variável de animação foi alterado.

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

Esse método será chamado se você habilitar eventos de variável de animação com EnableIntegerValueChangedEvent chamado para uma variável de animação ou objeto de animação específico. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo.

##  <a name="onanimationmanagerstatuschanged"></a>  CAnimationController::OnAnimationManagerStatusChanged

Chamado pelo Framework em resposta ao evento StatusChanged do Gerenciador de animação.

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

Esse método será chamado se você habilitar eventos do Gerenciador de animação com EnableAnimationManagerEvent. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo. A implementação padrão atualizará uma janela relacionada se ela tiver sido definida com SetRelatedWnd.

##  <a name="onanimationtimerpostupdate"></a>  CAnimationController::OnAnimationTimerPostUpdate

Chamado pelo Framework após a conclusão de uma atualização de animação.

```
virtual void OnAnimationTimerPostUpdate();
```

### <a name="remarks"></a>Comentários

Esse método será chamado se você habilitar manipuladores de eventos de timer usando EnableAnimationTimerEventHandler. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo.

##  <a name="onanimationtimerpreupdate"></a>  CAnimationController::OnAnimationTimerPreUpdate

Chamado pelo Framework antes do início de uma atualização de animação.

```
virtual void OnAnimationTimerPreUpdate();
```

### <a name="remarks"></a>Comentários

Esse método será chamado se você habilitar manipuladores de eventos de timer usando EnableAnimationTimerEventHandler. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo.

##  <a name="onanimationtimerrenderingtooslow"></a>  CAnimationController::OnAnimationTimerRenderingTooSlow

Chamado pelo Framework quando a taxa de quadros de renderização de uma animação cai abaixo de uma taxa de quadros desejável mínima.

```
virtual void OnAnimationTimerRenderingTooSlow(UINT32 fps);
```

### <a name="parameters"></a>Parâmetros

*fps*<br/>
A taxa de quadros atual em quadros por segundo.

### <a name="remarks"></a>Comentários

Esse método será chamado se você habilitar manipuladores de eventos de timer usando EnableAnimationTimerEventHandler. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo. A taxa de quadros desejável mínimo é especificada chamando IUIAnimationTimer:: SetFrameRateThreshold.

##  <a name="onanimationvaluechanged"></a>  CAnimationController::OnAnimationValueChanged

Chamado pelo Framework quando o valor da variável de animação foi alterado.

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

Esse método será chamado se você habilitar eventos de variável de animação com EnableValueChangedEvent chamado para uma variável de animação ou objeto de animação específico. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo.

##  <a name="onbeforeanimationstart"></a>  CAnimationController::OnBeforeAnimationStart

Chamado pelo Framework logo antes que a animação seja agendada.

```
virtual void OnBeforeAnimationStart(CAnimationGroup* pGroup);
```

### <a name="parameters"></a>Parâmetros

*pGroup*<br/>
Um ponteiro para um grupo de animação cuja animação está prestes a ser iniciada.

### <a name="remarks"></a>Comentários

Essa chamada é roteada para CWnd relacionados e pode ser substituída em uma classe derivada para executar quaisquer ações adicionais antes que a animação comece para o grupo especificado.

##  <a name="onhasprioritycancel"></a>  CAnimationController::OnHasPriorityCancel

Chamado pelo Framework para resolver conflitos de agendamento.

```
virtual BOOL OnHasPriorityCancel(
    CAnimationGroup* pGroupScheduled,
    CAnimationGroup* pGroupNew,
    UI_ANIMATION_PRIORITY_EFFECT priorityEffect);
```

### <a name="parameters"></a>Parâmetros

*pGroupScheduled*<br/>
O grupo que possui o storyboard atualmente agendado.

*pGroupNew*<br/>
O grupo que possui o novo Storyboard que está no agendamento está em conflito com o storyboard agendado de propriedade de pGroupScheduled.

*priorityEffect*<br/>
O efeito potencial em pGroupNew se pGroupScheduled tiver uma prioridade mais alta.

### <a name="return-value"></a>Valor de retorno

Deve retornar TRUE se o storyboard de propriedade de pGroupNew tiver prioridade. Deve retornar FALSE se o storyboard de propriedade de pGroupScheduled tiver prioridade.

### <a name="remarks"></a>Comentários

Esse método será chamado se você habilitar eventos de comparação de prioridade usando CAnimationController:: EnablePriorityComparisonHandler e especificar UI_ANIMATION_PHT_CANCEL. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo. Leia a documentação da API de animação do Windows para obter mais informações sobre o [Gerenciamento de conflitos](/windows/win32/api/uianimation/nf-uianimation-iuianimationprioritycomparison-haspriority).

##  <a name="onhasprioritycompress"></a>  CAnimationController::OnHasPriorityCompress

Chamado pelo Framework para resolver conflitos de agendamento.

```
virtual BOOL OnHasPriorityCompress(
    CAnimationGroup* pGroupScheduled,
    CAnimationGroup* pGroupNew,
    UI_ANIMATION_PRIORITY_EFFECT priorityEffect);
```

### <a name="parameters"></a>Parâmetros

*pGroupScheduled*<br/>
O grupo que possui o storyboard atualmente agendado.

*pGroupNew*<br/>
O grupo que possui o novo Storyboard que está no agendamento está em conflito com o storyboard agendado de propriedade de pGroupScheduled.

*priorityEffect*<br/>
O efeito potencial em pGroupNew se pGroupScheduled tiver uma prioridade mais alta.

### <a name="return-value"></a>Valor de retorno

Deve retornar TRUE se o storyboard de propriedade de pGroupNew tiver prioridade. Deve retornar FALSE se o storyboard de propriedade de pGroupScheduled tiver prioridade.

### <a name="remarks"></a>Comentários

Esse método será chamado se você habilitar eventos de comparação de prioridade usando CAnimationController:: EnablePriorityComparisonHandler e especificar UI_ANIMATION_PHT_COMPRESS. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo. Leia a documentação da API de animação do Windows para obter mais informações sobre o [Gerenciamento de conflitos](/windows/win32/api/uianimation/nf-uianimation-iuianimationprioritycomparison-haspriority).

##  <a name="onhaspriorityconclude"></a>  CAnimationController::OnHasPriorityConclude

Chamado pelo Framework para resolver conflitos de agendamento.

```
virtual BOOL OnHasPriorityConclude(
    CAnimationGroup* pGroupScheduled,
    CAnimationGroup* pGroupNew,
    UI_ANIMATION_PRIORITY_EFFECT priorityEffect);
```

### <a name="parameters"></a>Parâmetros

*pGroupScheduled*<br/>
O grupo que possui o storyboard atualmente agendado.

*pGroupNew*<br/>
O grupo que possui o novo Storyboard que está no agendamento está em conflito com o storyboard agendado de propriedade de pGroupScheduled.

*priorityEffect*<br/>
O efeito potencial em pGroupNew se pGroupScheduled tiver uma prioridade mais alta.

### <a name="return-value"></a>Valor de retorno

Deve retornar TRUE se o storyboard de propriedade de pGroupNew tiver prioridade. Deve retornar FALSE se o storyboard de propriedade de pGroupScheduled tiver prioridade.

### <a name="remarks"></a>Comentários

Esse método será chamado se você habilitar eventos de comparação de prioridade usando CAnimationController:: EnablePriorityComparisonHandler e especificar UI_ANIMATION_PHT_CONCLUDE. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo. Leia a documentação da API de animação do Windows para obter mais informações sobre o [Gerenciamento de conflitos](/windows/win32/api/uianimation/nf-uianimation-iuianimationprioritycomparison-haspriority).

##  <a name="onhasprioritytrim"></a>  CAnimationController::OnHasPriorityTrim

Chamado pelo Framework para resolver conflitos de agendamento.

```
virtual BOOL OnHasPriorityTrim(
    CAnimationGroup* pGroupScheduled,
    CAnimationGroup* pGroupNew,
    UI_ANIMATION_PRIORITY_EFFECT priorityEffect);
```

### <a name="parameters"></a>Parâmetros

*pGroupScheduled*<br/>
O grupo que possui o storyboard atualmente agendado.

*pGroupNew*<br/>
O grupo que possui o novo Storyboard que está no agendamento está em conflito com o storyboard agendado de propriedade de pGroupScheduled.

*priorityEffect*<br/>
O efeito potencial em pGroupNew se pGroupScheduled tiver uma prioridade mais alta.

### <a name="return-value"></a>Valor de retorno

Deve retornar TRUE se o storyboard de propriedade de pGroupNew tiver prioridade. Deve retornar FALSE se o storyboard de propriedade de pGroupScheduled tiver prioridade.

### <a name="remarks"></a>Comentários

Esse método será chamado se você habilitar eventos de comparação de prioridade usando CAnimationController:: EnablePriorityComparisonHandler e especificar UI_ANIMATION_PHT_TRIM. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo. Leia a documentação da API de animação do Windows para obter mais informações sobre o [Gerenciamento de conflitos](/windows/win32/api/uianimation/nf-uianimation-iuianimationprioritycomparison-haspriority).

##  <a name="onstoryboardstatuschanged"></a>CAnimationController::OnStoryboardStatusChanged

Chamado pelo Framework quando o status do storyboard é alterado.

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

Esse método será chamado se você habilitar os eventos de storyboard usando CAnimationController:: EnableStoryboardEventHandler. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo.

##  <a name="onstoryboardupdated"></a>  CAnimationController::OnStoryboardUpdated

Chamado pelo Framework quando o storyboard foi atualizado.

```
virtual void OnStoryboardUpdated(CAnimationGroup* pGroup);
```

### <a name="parameters"></a>Parâmetros

*pGroup*<br/>
Um ponteiro para um grupo que possui o storyboard.

### <a name="remarks"></a>Comentários

Esse método será chamado se você habilitar os eventos de storyboard usando CAnimationController:: EnableStoryboardEventHandler. Ele pode ser substituído em uma classe derivada para executar ações específicas do aplicativo.

##  <a name="removeallanimationgroups"></a>  CAnimationController::RemoveAllAnimationGroups

Remove todos os grupos de animação do controlador de animação.

```
void RemoveAllAnimationGroups();
```

### <a name="remarks"></a>Comentários

Todos os grupos serão excluídos, seus ponteiros, se armazenados no nível do aplicativo, deverão ser invalidados. Se CAnimationGroup:: m_bAutodestroyAnimationObjects para um grupo que está sendo excluído for TRUE, todos os objetos de animação que pertencem a esse grupo serão excluídos; caso contrário, suas referências ao controlador de animação pai serão definidas como nulas e poderão ser adicionadas a outro controlador.

##  <a name="removeanimationgroup"></a>  CAnimationController::RemoveAnimationGroup

Remove um grupo de animação com a ID especificada do controlador de animação.

```
void RemoveAnimationGroup(UINT32 nGroupID);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica a ID do grupo de animação.

### <a name="remarks"></a>Comentários

Esse método Remove um grupo de animação da lista interna de grupos e o exclui, portanto, se você tiver armazenado um ponteiro para esse grupo de animação, ele deverá ser invalidado. Se CAnimationGroup:: m_bAutodestroyAnimationObjects for TRUE, todos os objetos de animação que pertencem a esse grupo serão excluídos; caso contrário, suas referências ao controlador de animação pai serão definidas como nulas e poderão ser adicionadas a outro controlador.

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
Se esse parâmetro for TRUE, o objeto não será excluído após a remoção.

### <a name="remarks"></a>Comentários

Remove um objeto de animação do controlador de animação e do grupo de animação. Chame essa função se um determinado objeto não puder mais ser animado ou se você precisar mover o objeto para outro controlador de animação. No último caso, bNoDelete deve ser TRUE.

##  <a name="removetransitions"></a>  CAnimationController::RemoveTransitions

Remove as transições de objetos de animação que pertencem ao grupo especificado.

```
void RemoveTransitions(UINT32 nGroupID);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica a ID do grupo.

### <a name="remarks"></a>Comentários

O grupo faz um loop sobre seus objetos de animação e chama ClearTransitions (FALSE) para cada objeto de animação. Esse método é chamado pelo Framework depois que a animação tiver sido agendada.

##  <a name="schedulegroup"></a>CAnimationController:: Schedule

Agenda uma animação.

```
BOOL ScheduleGroup(
    UINT32 nGroupID,
    UI_ANIMATION_SECONDS time = 0.0);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica a ID do grupo de animação a ser agendada.

*time*<br/>
Especifica o tempo de agendamento.

### <a name="return-value"></a>Valor de retorno

TRUE se a animação tiver sido agendada com êxito. FALSE se o storyboard não tiver sido criado ou se ocorrer outro erro.

### <a name="remarks"></a>Comentários

Você deve chamar o elemento Animate com o parâmetro bScheduleNow definido como FALSE anterior. Você pode especificar o tempo de animação desejado Obtido em IUIAnimationTimer:: getTime. Se o parâmetro time for 0,0, a animação será agendada para a hora atual.

##  <a name="setrelatedwnd"></a>  CAnimationController::SetRelatedWnd

Estabelece uma relação entre o controlador de animação e uma janela.

```
void SetRelatedWnd(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Um ponteiro para o objeto de janela a ser definido.

### <a name="remarks"></a>Comentários

Se um objeto CWnd relacionado for definido, o controlador de animação poderá atualizá-lo automaticamente (enviar mensagem WM_PAINT) quando o status do Gerenciador de animação tiver sido alterado ou o evento pós-atualização do temporizador tiver ocorrido.

##  <a name="updateanimationmanager"></a>  CAnimationController::UpdateAnimationManager

Direciona o Gerenciador de animação para atualizar os valores de todas as variáveis de animação.

```
virtual void UpdateAnimationManager();
```

### <a name="remarks"></a>Comentários

Chamar esse método avança o Gerenciador de animação para a hora atual, alterando os status dos storyboards conforme necessário e atualizando as variáveis de animação para os valores adequados interpolados. Internamente, esse método chama IUIAnimationTimer:: getTime (timeNow) e IUIAnimationManager:: Update (timeNow). Substitua esse método em uma classe derivada para personalizar esse comportamento.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
