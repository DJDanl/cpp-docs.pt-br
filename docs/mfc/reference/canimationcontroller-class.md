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
ms.openlocfilehash: 34a02567bfeb76666cc38ccf05dcc285a1f658f5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369761"
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
|[CAnimationController:CAnimationController](#canimationcontroller)|Constrói um controlador de animação.|
|[CAnimationController::~CAnimationController](#_dtorcanimationcontroller)|O destruidor. Chamado quando o objeto do controlador de animação está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationController::AddAnimationObject](#addanimationobject)|Adiciona um objeto de animação a um grupo que pertence ao controlador de animação.|
|[CAnimationController::AddKeyframeToGroup](#addkeyframetogroup)|Adiciona um quadro-chave ao grupo.|
|[CAnimationController::AnimateGroup](#animategroup)|Prepara um grupo para executar a animação e, opcionalmente, agenda-a.|
|[CAnimationController::CleanUpGroup](#cleanupgroup)|Sobrecarregado. Chamado pela estrutura para limpar o grupo quando a animação foi programada.|
|[CAnimationController::CreateKeyframe](#createkeyframe)|Sobrecarregado. Cria um quadro-chave que depende da transição e o adiciona ao grupo especificado.|
|[CAnimationController::Ativareventodeprogramaçãodeanimaçãodeanimação](#enableanimationmanagerevent)|Define ou libera um manipulador para chamar quando o status do gerenciador de animação for alterado.|
|[CAnimationController::AtivarAnimationTimerEventHandler](#enableanimationtimereventhandler)|Define ou libera um manipulador para eventos de cronometragem e manipulador para atualizações de tempo.|
|[CAnimationController::Ativarcontroledeprioridadesdeprioridades](#enableprioritycomparisonhandler)|Define ou libera o manipulador de comparação de prioridades para chamar para determinar se um storyboard programado pode ser cancelado, concluído, aparado ou compactado.|
|[CAnimationController::EnableStoryboardEventHandler](#enablestoryboardeventhandler)|Define ou libera um manipulador para eventos de status do storyboard e atualização.|
|[CAnimationController::FindAnimationGroup](#findanimationgroup)|Sobrecarregado. Encontra um grupo de animação por seu storyboard.|
|[CAnimationController::FindAnimationObject](#findanimationobject)|Encontra objeto de animação contendo uma variável de animação especificada.|
|[CAnimationController::GetKeyframeStoryboardStart](#getkeyframestoryboardstart)|Retorna um quadro-chave que identifica o início do storyboard.|
|[CAnimationController::getUiAnimationManager](#getuianimationmanager)|Fornece acesso ao objeto Encapsulado IUIAnimationManager.|
|[CAnimationController::GetUIAnimationTimer](#getuianimationtimer)|Fornece acesso ao objeto IUIAnimationTimer encapsulado.|
|[CAnimationController::getUiTransitionFactory](#getuitransitionfactory)|Um ponteiro para interface IUIAnimationTransitionFactory ou NULL, se a criação da biblioteca de transição falhar.|
|[CAnimationController::GetUITransitionLibrary](#getuitransitionlibrary)|Fornece acesso ao objeto Encapsulado IUIAnimationTransitionLibrary.|
|[CAnimationController::isAnimationInProgress](#isanimationinprogress)|Diz se pelo menos um grupo está jogando animação.|
|[CAnimationController::IsValid](#isvalid)|Diz se o controlador de animação é válido.|
|[CAnimationController:OnAnimationIntegerValueChanged](#onanimationintegervaluechanged)|Chamado pelo framework quando o valor inteiro da variável animação foi alterado.|
|[CAnimationController:OnAnimation'Sstatus2](#onanimationmanagerstatuschanged)|Chamado pelo framework em resposta ao evento StatusChanged do gerenciador de animação.|
|[CAnimationController::OnAnimationTimerPostUpdate](#onanimationtimerpostupdate)|Chamado pelo framework depois que uma atualização de animação é concluída.|
|[CAnimationController::OnAnimationTimerPreUpdate](#onanimationtimerpreupdate)|Chamado pelo framework antes de uma atualização de animação começar.|
|[CAnimationController::OnAnimationTimerRenderingTooSlow](#onanimationtimerrenderingtooslow)|Chamado pelo framework quando a taxa de quadros de renderização para uma animação cai abaixo de uma taxa de quadros mínima desejável.|
|[CAnimationController:OnAnimationValueAlterado](#onanimationvaluechanged)|Chamado pelo framework quando o valor da variável animação foi alterado.|
|[cAnimationController::OnbeforeAnimationStart](#onbeforeanimationstart)|Chamado pela estrutura pouco antes da animação ser agendada.|
|[canimationcontroller::onhasprioritycancel](#onhasprioritycancel)|Chamado pelo quadro para resolver conflitos de agendamento.|
|[CAnimationController::OnHasPriorityCompress](#onhasprioritycompress)|Chamado pelo quadro para resolver conflitos de agendamento.|
|[canimationcontroller::onhaspriorityconcluir](#onhaspriorityconclude)|Chamado pelo quadro para resolver conflitos de agendamento.|
|[canimationcontroller::OnHasPriorityTrim](#onhasprioritytrim)|Chamado pelo quadro para resolver conflitos de agendamento.|
|[CAnimationController::OnStoryboardStatusChanged](#onstoryboardstatuschanged)|Chamado pela estrutura quando o status do storyboard mudou.|
|[CAnimationController::OnStoryboardAtualizado](#onstoryboardupdated)|Chamado pelo framework quando storyboard foi atualizado.|
|[CAnimationController::RemoveAllAnimationGroups](#removeallanimationgroups)|Remove todos os grupos de animação do controlador de animação.|
|[CAnimationController::RemoveAnimationGroup](#removeanimationgroup)|Remove um grupo de animação com ID especificado do controlador de animação.|
|[CAnimationController::RemoveAnimationObject](#removeanimationobject)|Remova um objeto de animação do controlador de animação.|
|[CAnimationController::RemoveTransitions](#removetransitions)|Remove transições de objetos de animação que pertencem ao grupo especificado.|
|[CAnimationController::ScheduleGroup](#schedulegroup)|Agenda uma animação.|
|[CAnimationController::SetRelatedWnd](#setrelatedwnd)|Estabelece uma relação entre o controlador de animação e uma janela.|
|[CAnimationController::UpdateAnimationManager](#updateanimationmanager)|Direciona o gerenciador de animação para atualizar os valores de todas as variáveis de animação.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationController::CleanUpGroup](#cleanupgroup)|Sobrecarregado. Um ajudante que limpa o grupo.|
|[CAnimationController::OnAfterSchedule](#onafterschedule)|Chamado pela estrutura quando uma animação para o grupo especificado acaba de ser agendada.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationController::gkeyframeStoryboardStart](#g_keyframestoryboardstart)|Um quadro-chave que representa o início do storyboard.|
|[CAnimationController::m_bIsValid](#m_bisvalid)|Especifica se um controlador de animação é válido ou não. Este membro é definido como FALSE se o sistema operacional atual não suportar a API de animação do Windows.|
|[CAnimationController::m_lstAnimationGroups](#m_lstanimationgroups)|Uma lista de grupos de animação que pertencem a este controlador de animação.|
|[CAnimationController::m_pAnimationManager](#m_panimationmanager)|Armazena um ponteiro para o objeto COM do Gerenciador de animação.|
|[CAnimationController::m_pAnimationTimer](#m_panimationtimer)|Armazena um ponteiro para o objeto Animation Timer COM.|
|[CAnimationController::m_pRelatedWnd](#m_prelatedwnd)|Um ponteiro para um objeto CWnd relacionado, que pode ser redesenhado automaticamente quando o status do gerenciador de animação foi alterado ou ocorreu um evento pós-atualização. Pode ser NULL.|
|[CAnimationController::m_pTransitionFactory](#m_ptransitionfactory)|Armazena um ponteiro para o objeto Transition Factory COM.|
|[CAnimationController::m_pTransitionLibrary](#m_ptransitionlibrary)|Armazena um ponteiro para o objeto TRANSITION Library COM.|

## <a name="remarks"></a>Comentários

A classe CAnimationController é a classe-chave que gerencia as animações. Você pode criar uma ou mais instâncias de controlador de animação em um aplicativo e, opcionalmente, conectar uma instância do controlador de animação a um objeto CWnd usando CAnimationController::SetRelatedWnd. Essa conexão é necessária para enviar mensagens WM_PAINT para a janela relacionada automaticamente quando o status do gerenciador de animação tiver sido alterado ou o temporizador de animação tiver sido atualizado. Se você não habilitar essa relação, você deve redesenhar uma janela que exibe uma animação manualmente. Para isso, você pode derivar uma classe do CAnimationController e substituir o OnAnimationManagerStatusChanged e/ou OnAnimationTimerPostUpdate e invalidar uma ou mais janelas quando necessário.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CAnimationController`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="canimationcontrollercanimationcontroller"></a><a name="_dtorcanimationcontroller"></a>CAnimationController::~CAnimationController

O destruidor. Chamado quando o objeto do controlador de animação está sendo destruído.

```
virtual ~CAnimationController(void);
```

## <a name="canimationcontrolleraddanimationobject"></a><a name="addanimationobject"></a>CAnimationController::AddAnimationObject

Adiciona um objeto de animação a um grupo que pertence ao controlador de animação.

```
CAnimationGroup* AddAnimationObject(CAnimationBaseObject* pObject);
```

### <a name="parameters"></a>Parâmetros

*Pobject*<br/>
Um ponteiro para um objeto de animação.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o grupo de animação existente ou novo onde o pObject foi adicionado se a função for bem sucedida; NULL se pObject já foi adicionado a um grupo que pertence a outro controlador de animação.

### <a name="remarks"></a>Comentários

Chame este método para adicionar um objeto de animação ao controlador de animação. Um objeto será adicionado a um grupo de acordo com o GroupID do objeto (ver CAnimationBaseObject::SetID). O controlador de animação criará um novo grupo se for o primeiro objeto a ser adicionado com o GroupID especificado. Um objeto de animação pode ser adicionado apenas a um controlador de animação. Se você precisar adicionar um objeto a outro controlador, chame RemoveAnimationObject primeiro. Se você chamar SetID com novo GroupID para um objeto que já foi adicionado a um grupo, o objeto será removido do grupo antigo e adicionado a outro grupo com ID especificado.

## <a name="canimationcontrolleraddkeyframetogroup"></a><a name="addkeyframetogroup"></a>CAnimationController::AddKeyframeToGroup

Adiciona um quadro-chave ao grupo.

```
BOOL AddKeyframeToGroup(
    UINT32 nGroupID,
    CBaseKeyFrame* pKeyframe);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica o ID do grupo.

*pKeyframe*<br/>
Um ponteiro para um quadro-chave.

### <a name="return-value"></a>Valor retornado

VERDADE se a função for bem sucedida; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Normalmente você não precisa chamar esse método, use CAnimationController::CreateKeyframe em vez disso, que cria e adiciona o quadro-chave criado a um grupo automaticamente.

## <a name="canimationcontrolleranimategroup"></a><a name="animategroup"></a>CAnimationController::AnimateGroup

Prepara um grupo para executar a animação e, opcionalmente, agenda-a.

```
BOOL AnimateGroup(
    UINT32 nGroupID,
    BOOL bScheduleNow = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica groupID.

*bScheduleNow*<br/>
Especifica se deve executar a animação imediatamente.

### <a name="return-value"></a>Valor retornado

TRUE se a animação foi programada e executada com sucesso.

### <a name="remarks"></a>Comentários

Este método faz o trabalho real criando storyboard, adicionando variáveis de animação, aplicando transições e definindo quadros-chave. É possível atrasar o agendamento se você definir bScheduleNow como FALSO. Neste caso, o grupo especificado manterá um storyboard que foi configurado para animação. Nesse ponto, você pode configurar eventos para as variáveis storyboard e animação. Quando você realmente precisa executar a chamada de animação CAnimationController::ScheduleGroup.

## <a name="canimationcontrollercanimationcontroller"></a><a name="canimationcontroller"></a>CAnimationController:CAnimationController

Constrói um controlador de animação.

```
CAnimationController(void);
```

## <a name="canimationcontrollercleanupgroup"></a><a name="cleanupgroup"></a>CAnimationController::CleanUpGroup

Chamado pela estrutura para limpar o grupo quando a animação foi programada.

```
void CleanUpGroup(UINT32 nGroupID);
void CleanUpGroup(CAnimationGroup* pGroup);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica groupID.

*pGroup*<br/>
Um ponteiro para o grupo de animação para limpar.

### <a name="remarks"></a>Comentários

Este método remove todas as transições e quadros-chave do grupo especificado, porque eles não são relevantes depois que uma animação foi programada.

## <a name="canimationcontrollercreatekeyframe"></a><a name="createkeyframe"></a>CAnimationController::CreateKeyframe

Cria um quadro-chave que depende da transição e o adiciona ao grupo especificado.

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
Especifica o ID do grupo para o qual o quadro-chave é criado.

*pTransição*<br/>
Um ponteiro para a transição. O quadro-chave será inserido no storyboard após essa transição.

*pKeyframe*<br/>
Um ponteiro para basear o quadro-chave para este quadro-chave.

*deslocamento*<br/>
Deslocamento em segundos do quadro-chave base especificado por pKeyframe.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o quadro-chave recém-criado se a função for bem sucedida.

### <a name="remarks"></a>Comentários

Você pode armazenar o ponteiro retornado e basear outros quadros-chave no quadro-chave recém-criado (veja a segunda sobrecarga). É possível iniciar transições em quadros-chave - veja CBaseTransition::SetKeyframes. Você não precisa excluir quadros-chave criados dessa forma, porque eles são excluídos automaticamente por grupos de animação. Tenha cuidado ao criar quadros-chave com base em outros quadros-chave e transições e evite referências circulares.

## <a name="canimationcontrollerenableanimationmanagerevent"></a><a name="enableanimationmanagerevent"></a>CAnimationController::Ativareventodeprogramaçãodeanimaçãodeanimação

Define ou libera um manipulador para chamar quando o status do gerenciador de animação for alterado.

```
virtual BOOL EnableAnimationManagerEvent(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
Especifica se deve definir ou liberar um manipulador.

### <a name="return-value"></a>Valor retornado

TRUE se o manipulador foi definido ou liberado com sucesso.

### <a name="remarks"></a>Comentários

Quando um manipulador é definido (ativado) a animação do Windows chama onAnimationManagerStatusAlterado quando o status do gerenciador de animação é alterado.

## <a name="canimationcontrollerenableanimationtimereventhandler"></a><a name="enableanimationtimereventhandler"></a>CAnimationController::AtivarAnimationTimerEventHandler

Define ou libera um manipulador para eventos de cronometragem e manipulador para atualizações de tempo.

```
virtual BOOL EnableAnimationTimerEventHandler(
    BOOL bEnable = TRUE,
    UI_ANIMATION_IDLE_BEHAVIOR idleBehavior = UI_ANIMATION_IDLE_BEHAVIOR_DISABLE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
Especifica se deve definir ou liberar os manipuladores.

*idleBehavior*<br/>
Especifica o comportamento ocioso para o manipulador de atualização do temporizador.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se os manipuladores foram definidos ou liberados com sucesso; FALSO se este método for chamado pela segunda vez sem liberar os manipuladores primeiro, ou se ocorrer qualquer outro erro.

### <a name="remarks"></a>Comentários

Quando os manipuladores estão definidos (habilitados) a API do Windows Animation chama onAnimationTimerPreUpdate, OnAnimationTimerPostUpdate, onRenderingTooSlow métodos. Você precisa ativar temporizadores de animação para permitir que a API do Windows API atualize storyboards. Caso contrário, você precisará chamar CAnimationController::UpdateAnimationManager para direcionar o gerenciador de animação para atualizar os valores de todas as variáveis de animação.

## <a name="canimationcontrollerenableprioritycomparisonhandler"></a><a name="enableprioritycomparisonhandler"></a>CAnimationController::Ativarcontroledeprioridadesdeprioridades

Define ou libera o manipulador de comparação de prioridades para chamar para determinar se um storyboard programado pode ser cancelado, concluído, aparado ou compactado.

```
virtual BOOL EnablePriorityComparisonHandler(DWORD dwHandlerType);
```

### <a name="parameters"></a>Parâmetros

*dwHandlerType*<br/>
Uma combinação de UI_ANIMATION_PHT_ bandeiras (ver observações), que especifica quais manipuladores definir ou liberar.

### <a name="return-value"></a>Valor retornado

TRUE se o manipulador foi definido ou liberado com sucesso.

### <a name="remarks"></a>Comentários

Quando um manipulador é definido (ativado) a Animação do Windows chama os seguintes métodos virtuais dependendo do dwHandlerType: OnHasPriorityCancel, OnHasPriorityConclude, OnHasPriorityTrim, OnHasPriorityCompress. dwHandler pode ser uma combinação dos seguintes sinalizadores: UI_ANIMATION_PHT_NONE - libere todos os manipuladores UI_ANIMATION_PHT_CANCEL - definir manipulador de comparação de cancele UI_ANIMATION_PHT_CONCLUDE - definir manipulador de comparação de conclusão UI_ANIMATION_PHT_COMPRESS - definir manipulador de comparação compressa UI_ANIMATION_PHT_TRIM - definir manipulador de comparação de corte UI_ANIMATION_PHT_CANCEL_REMOVE - remover manipulador de comparação cancelar UI_ANIMATION_PHT_CONCLUDE_REMOVE - remover UI_ANIMATION_PHT_COMPRESS_REMOVE manipulador de comparação concluir - remover manipulador de comparação compressa UI_ANIMATION_PHT_TRIM_REMOVE - remover manipulador de comparação de corte

## <a name="canimationcontrollerenablestoryboardeventhandler"></a><a name="enablestoryboardeventhandler"></a>CAnimationController::EnableStoryboardEventHandler

Define ou libera um manipulador para eventos de status do storyboard e atualização.

```
virtual BOOL EnableStoryboardEventHandler(
    UINT32 nGroupID,
    BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica o ID do grupo.

*Benable*<br/>
Especifica se deve definir ou liberar um manipulador.

### <a name="return-value"></a>Valor retornado

TRUE se o manipulador foi configurado ou liberado com sucesso; FALSO se o grupo de animação especificado for encontrado ou a animação para o grupo especificado não tiver sido iniciada e seu storyboard interno for NULO.

### <a name="remarks"></a>Comentários

Quando um manipulador é definido (ativado) a API do Windows Animation chama onStoryboardStatusChanges e OnStoryboardMétodos virtuais atualizados. Um manipulador deve ser definido após CAnimationController::Animate foi chamado para o grupo de animação especificado, porque cria o objeto Encapsulado IUIAnimationStoryboard.

## <a name="canimationcontrollerfindanimationgroup"></a><a name="findanimationgroup"></a>CAnimationController::FindAnimationGroup

Encontra um grupo de animação por seu ID de grupo.

```
CAnimationGroup* FindAnimationGroup(UINT32 nGroupID);
CAnimationGroup* FindAnimationGroup(IUIAnimationStoryboard* pStoryboard);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica um GroupID.

*pStoryboard*<br/>
Um ponteiro para um storyboard.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o grupo de animação ou NULL se o grupo com ID especificado não for encontrado.

### <a name="remarks"></a>Comentários

Use este método para encontrar um grupo de animação em tempo de execução. Um grupo é criado e adicionado à lista interna de grupos de animação quando um primeiro objeto de animação com GroupID específico está sendo adicionado ao controlador de animação.

## <a name="canimationcontrollerfindanimationobject"></a><a name="findanimationobject"></a>CAnimationController::FindAnimationObject

Encontra objeto de animação contendo uma variável de animação especificada.

```
BOOL FindAnimationObject(
    IUIAnimationVariable* pVariable,
    CAnimationBaseObject** ppObject,
    CAnimationGroup** ppGroup);
```

### <a name="parameters"></a>Parâmetros

*pVariable*<br/>
Um ponteiro para a variável animação.

*Ppobject*<br/>
Saída. Contém um ponteiro para objeto de animação ou NULL.

*ppGroup*<br/>
Saída. Contém um ponteiro para o grupo de animação que contém o objeto de animação, ou NULL.

### <a name="return-value"></a>Valor retornado

VERDADE se objeto foi encontrado; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Chamado de manipuladores de eventos quando é necessário encontrar um objeto de animação da variável de animação de entrada.

## <a name="canimationcontrollergkeyframestoryboardstart"></a><a name="g_keyframestoryboardstart"></a>CAnimationController::gkeyframeStoryboardStart

Um quadro-chave que representa o início do storyboard.

```
static CBaseKeyFrame gkeyframeStoryboardStart;
```

## <a name="canimationcontrollergetkeyframestoryboardstart"></a><a name="getkeyframestoryboardstart"></a>CAnimationController::GetKeyframeStoryboardStart

Retorna um quadro-chave que identifica o início do storyboard.

```
static CBaseKeyFrame* GetKeyframeStoryboardStart();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o quadro-chave base, que identifica o início do storyboard.

### <a name="remarks"></a>Comentários

Obtenha este quadro-chave para basear quaisquer outros quadros-chave ou transições no momento em que um storyboard é iniciado.

## <a name="canimationcontrollergetuianimationmanager"></a><a name="getuianimationmanager"></a>CAnimationController::getUiAnimationManager

Fornece acesso ao objeto Encapsulado IUIAnimationManager.

```
IUIAnimationManager* GetUIAnimationManager();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para interface IUIAnimationManager ou NULL, se a criação do gerenciador de animação falhar.

### <a name="remarks"></a>Comentários

Se o sistema operacional atual não suportar a API de animação do Windows, este método retorna NULL e depois todas as chamadas subseqüentes no CAnimationController::IsValid return FALSE. Você pode precisar acessar o IUIAnimationManager para chamar seus métodos de interface, que não são embrulhados pelo controlador de animação.

## <a name="canimationcontrollergetuianimationtimer"></a><a name="getuianimationtimer"></a>CAnimationController::GetUIAnimationTimer

Fornece acesso ao objeto IUIAnimationTimer encapsulado.

```
IUIAnimationTimer* GetUIAnimationTimer();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para interface IUIAnimationTimer ou NULL, se a criação do temporizador de animação falhar.

### <a name="remarks"></a>Comentários

Se o sistema operacional atual não suportar a API de animação do Windows, este método retorna NULL e depois todas as chamadas subseqüentes no CAnimationController::IsValid return FALSE.

## <a name="canimationcontrollergetuitransitionfactory"></a><a name="getuitransitionfactory"></a>CAnimationController::getUiTransitionFactory

Um ponteiro para interface IUIAnimationTransitionFactory ou NULL, se a criação da biblioteca de transição falhar.

```
IUIAnimationTransitionFactory* GetUITransitionFactory();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para IUIAnimationTransitionFactory ou NULL, se a criação da fábrica de transição falhar.

### <a name="remarks"></a>Comentários

Se o sistema operacional atual não suportar a API de animação do Windows, este método retorna NULL e depois todas as chamadas subseqüentes no CAnimationController::IsValid return FALSE.

## <a name="canimationcontrollergetuitransitionlibrary"></a><a name="getuitransitionlibrary"></a>CAnimationController::GetUITransitionLibrary

Fornece acesso ao objeto Encapsulado IUIAnimationTransitionLibrary.

```
IUIAnimationTransitionLibrary* GetUITransitionLibrary();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para interface IUIAnimationTransitionLibrary ou NULL, se a criação da biblioteca de transição falhar.

### <a name="remarks"></a>Comentários

Se o sistema operacional atual não suportar a API de animação do Windows, este método retorna NULL e depois todas as chamadas subseqüentes no CAnimationController::IsValid return FALSE.

## <a name="canimationcontrollerisanimationinprogress"></a><a name="isanimationinprogress"></a>CAnimationController::isAnimationInProgress

Diz se pelo menos um grupo está jogando animação.

```
virtual BOOL IsAnimationInProgress();
```

### <a name="return-value"></a>Valor retornado

TRUE se houver uma animação em andamento para este controlador de animação; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Verifica o status do gerenciador de animação e retorna TRUE se o status for UI_ANIMATION_MANAGER_BUSY.

## <a name="canimationcontrollerisvalid"></a><a name="isvalid"></a>CAnimationController::IsValid

Diz se o controlador de animação é válido.

```
BOOL IsValid() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o controlador de animação for válido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Este método retorna FALSO somente se a API do Windows Animation não for suportada no sistema operacional atual e a criação do gerenciador de animação falhar porque não está registrada. Você precisa ligar para o GetUIAnimationManager pelo menos uma vez após a inicialização das bibliotecas COM para causar a configuração deste sinalizador.

## <a name="canimationcontrollerm_bisvalid"></a><a name="m_bisvalid"></a>CAnimationController::m_bIsValid

Especifica se um controlador de animação é válido ou não. Este membro é definido como FALSE se o sistema operacional atual não suportar a API de animação do Windows.

```
BOOL m_bIsValid;
```

## <a name="canimationcontrollerm_lstanimationgroups"></a><a name="m_lstanimationgroups"></a>CAnimationController::m_lstAnimationGroups

Uma lista de grupos de animação que pertencem a este controlador de animação.

```
CList<CAnimationGroup*, CAnimationGroup*> m_lstAnimationGroups;
```

## <a name="canimationcontrollerm_panimationmanager"></a><a name="m_panimationmanager"></a>CAnimationController::m_pAnimationManager

Armazena um ponteiro para o objeto COM do Gerenciador de animação.

```
ATL::CComPtr<IUIAnimationManager> m_pAnimationManager;
```

## <a name="canimationcontrollerm_panimationtimer"></a><a name="m_panimationtimer"></a>CAnimationController::m_pAnimationTimer

Armazena um ponteiro para o objeto Animation Timer COM.

```
ATL::CComPtr<IUIAnimationTimer> m_pAnimationTimer;
```

## <a name="canimationcontrollerm_prelatedwnd"></a><a name="m_prelatedwnd"></a>CAnimationController::m_pRelatedWnd

Um ponteiro para um objeto CWnd relacionado, que pode ser redesenhado automaticamente quando o status do gerenciador de animação foi alterado ou ocorreu um evento pós-atualização. Pode ser NULL.

```
CWnd* m_pRelatedWnd;
```

## <a name="canimationcontrollerm_ptransitionfactory"></a><a name="m_ptransitionfactory"></a>CAnimationController::m_pTransitionFactory

Armazena um ponteiro para o objeto Transition Factory COM.

```
ATL::CComPtr<IUIAnimationTransitionFactory> m_pTransitionFactory;
```

## <a name="canimationcontrollerm_ptransitionlibrary"></a><a name="m_ptransitionlibrary"></a>CAnimationController::m_pTransitionLibrary

Armazena um ponteiro para o objeto TRANSITION Library COM.

```
ATL::CComPtr<IUIAnimationTransitionLibrary> m_pTransitionLibrary;
```

## <a name="canimationcontrolleronafterschedule"></a><a name="onafterschedule"></a>CAnimationController::OnAfterSchedule

Chamado pela estrutura quando uma animação para o grupo especificado acaba de ser agendada.

```
virtual void OnAfterSchedule(CAnimationGroup* pGroup);
```

### <a name="parameters"></a>Parâmetros

*pGroup*<br/>
Um ponteiro para um grupo de animação, que foi agendado.

### <a name="remarks"></a>Comentários

A implementação padrão remove quadros-chave do grupo especificado e transições de variáveis de animação que pertencem ao grupo especificado. Pode ser substituído em uma classe derivada para tomar quaisquer ações adicionais no cronograma de animação.

## <a name="canimationcontrolleronanimationintegervaluechanged"></a><a name="onanimationintegervaluechanged"></a>CAnimationController:OnAnimationIntegerValueChanged

Chamado pelo framework quando o valor inteiro da variável animação foi alterado.

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

*Pobject*<br/>
Um ponteiro para um objeto de animação que contém uma variável de animação cujo valor foi alterado.

*variável*<br/>
Um ponteiro para uma variável de animação.

*newValue*<br/>
Especifica novo valor.

*prevValue*<br/>
Especifica o valor anterior.

### <a name="remarks"></a>Comentários

Este método é chamado se você habilitar eventos variáveis de animação com EnableIntegerValueChangedEvent chamado para uma variável de animação específica ou objeto de animação. Ele pode ser substituído em uma classe derivada para tomar ações específicas do aplicativo.

## <a name="canimationcontrolleronanimationmanagerstatuschanged"></a><a name="onanimationmanagerstatuschanged"></a>CAnimationController:OnAnimation'Sstatus2

Chamado pelo framework em resposta ao evento StatusChanged do gerenciador de animação.

```
virtual void OnAnimationManagerStatusChanged(
    UI_ANIMATION_MANAGER_STATUS newStatus,
    UI_ANIMATION_MANAGER_STATUS previousStatus);
```

### <a name="parameters"></a>Parâmetros

*newStatus*<br/>
Novo status de gerenciador de animação.

*previousStatus*<br/>
Status de gerenciador de animação anterior.

### <a name="remarks"></a>Comentários

Esse método é chamado se você habilitar eventos de gerenciador de animação com EnableAnimationManagerEvent. Ele pode ser substituído em uma classe derivada para tomar ações específicas do aplicativo. A implementação padrão atualiza uma janela relacionada se ela tiver sido definida com SetRelatedWnd.

## <a name="canimationcontrolleronanimationtimerpostupdate"></a><a name="onanimationtimerpostupdate"></a>CAnimationController::OnAnimationTimerPostUpdate

Chamado pelo framework depois que uma atualização de animação é concluída.

```
virtual void OnAnimationTimerPostUpdate();
```

### <a name="remarks"></a>Comentários

Este método é chamado se você habilitar manipuladores de eventos de temporizador usando EnableAnimationTimerEventHandler. Ele pode ser substituído em uma classe derivada para tomar ações específicas do aplicativo.

## <a name="canimationcontrolleronanimationtimerpreupdate"></a><a name="onanimationtimerpreupdate"></a>CAnimationController::OnAnimationTimerPreUpdate

Chamado pelo framework antes de uma atualização de animação começar.

```
virtual void OnAnimationTimerPreUpdate();
```

### <a name="remarks"></a>Comentários

Este método é chamado se você habilitar manipuladores de eventos de temporizador usando EnableAnimationTimerEventHandler. Ele pode ser substituído em uma classe derivada para tomar ações específicas do aplicativo.

## <a name="canimationcontrolleronanimationtimerrenderingtooslow"></a><a name="onanimationtimerrenderingtooslow"></a>CAnimationController::OnAnimationTimerRenderingTooSlow

Chamado pelo framework quando a taxa de quadros de renderização para uma animação cai abaixo de uma taxa de quadros mínima desejável.

```
virtual void OnAnimationTimerRenderingTooSlow(UINT32 fps);
```

### <a name="parameters"></a>Parâmetros

*Fps*<br/>
A taxa de quadros atual em quadros por segundo.

### <a name="remarks"></a>Comentários

Este método é chamado se você habilitar manipuladores de eventos de temporizador usando EnableAnimationTimerEventHandler. Ele pode ser substituído em uma classe derivada para tomar ações específicas do aplicativo. A taxa de quadros mínima desejável é especificada chamando IUIAnimationTimer::SetFrameRateThreshold.

## <a name="canimationcontrolleronanimationvaluechanged"></a><a name="onanimationvaluechanged"></a>CAnimationController:OnAnimationValueAlterado

Chamado pelo framework quando o valor da variável animação foi alterado.

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

*Pobject*<br/>
Um ponteiro para um objeto de animação que contém uma variável de animação cujo valor foi alterado.

*variável*<br/>
Um ponteiro para uma variável de animação.

*newValue*<br/>
Especifica novo valor.

*prevValue*<br/>
Especifica o valor anterior.

### <a name="remarks"></a>Comentários

Este método é chamado se você habilitar eventos variáveis de animação com EnableValueChangedEvent chamado para uma variável de animação específica ou objeto de animação. Ele pode ser substituído em uma classe derivada para tomar ações específicas do aplicativo.

## <a name="canimationcontrolleronbeforeanimationstart"></a><a name="onbeforeanimationstart"></a>cAnimationController::OnbeforeAnimationStart

Chamado pela estrutura pouco antes da animação ser agendada.

```
virtual void OnBeforeAnimationStart(CAnimationGroup* pGroup);
```

### <a name="parameters"></a>Parâmetros

*pGroup*<br/>
Um ponteiro para um grupo de animação cuja animação está prestes a começar.

### <a name="remarks"></a>Comentários

Esta chamada é roteada para CWnd relacionado e pode ser substituída em uma classe derivada para executar quaisquer ações adicionais antes que a animação seja iniciada para o grupo especificado.

## <a name="canimationcontrolleronhasprioritycancel"></a><a name="onhasprioritycancel"></a>canimationcontroller::onhasprioritycancel

Chamado pelo quadro para resolver conflitos de agendamento.

```
virtual BOOL OnHasPriorityCancel(
    CAnimationGroup* pGroupScheduled,
    CAnimationGroup* pGroupNew,
    UI_ANIMATION_PRIORITY_EFFECT priorityEffect);
```

### <a name="parameters"></a>Parâmetros

*pGroupScheduled*<br/>
O grupo que possui o storyboard atualmente programado.

*pGroupNew*<br/>
O grupo que possui o novo storyboard que está em conflito de agendamento com o storyboard programado de propriedade do pGroupScheduled.

*priorityEffect*<br/>
O efeito potencial no pGroupNew se pGroupScheduled tem uma prioridade maior.

### <a name="return-value"></a>Valor retornado

Deve retornar TRUE se storyboard de propriedade do pGroupNew tiver prioridade. Deve retornar FALSE se storyboard de propriedade do pGroupGroupScheduled tiver prioridade.

### <a name="remarks"></a>Comentários

Este método é chamado se você habilitar eventos de comparação de prioridades usando CAnimationController::EnablePriorityComparisonHandler e especificar UI_ANIMATION_PHT_CANCEL. Ele pode ser substituído em uma classe derivada para tomar ações específicas do aplicativo. Leia a documentação da API de animação do Windows para obter mais informações sobre [gerenciamento de conflitos](/windows/win32/api/uianimation/nf-uianimation-iuianimationprioritycomparison-haspriority).

## <a name="canimationcontrolleronhasprioritycompress"></a><a name="onhasprioritycompress"></a>CAnimationController::OnHasPriorityCompress

Chamado pelo quadro para resolver conflitos de agendamento.

```
virtual BOOL OnHasPriorityCompress(
    CAnimationGroup* pGroupScheduled,
    CAnimationGroup* pGroupNew,
    UI_ANIMATION_PRIORITY_EFFECT priorityEffect);
```

### <a name="parameters"></a>Parâmetros

*pGroupScheduled*<br/>
O grupo que possui o storyboard atualmente programado.

*pGroupNew*<br/>
O grupo que possui o novo storyboard que está em conflito de agendamento com o storyboard programado de propriedade do pGroupScheduled.

*priorityEffect*<br/>
O efeito potencial no pGroupNew se pGroupScheduled tem uma prioridade maior.

### <a name="return-value"></a>Valor retornado

Deve retornar TRUE se storyboard de propriedade do pGroupNew tiver prioridade. Deve retornar FALSE se storyboard de propriedade do pGroupGroupScheduled tiver prioridade.

### <a name="remarks"></a>Comentários

Este método é chamado se você habilitar eventos de comparação de prioridades usando CAnimationController::EnablePriorityComparisonHandler e especificar UI_ANIMATION_PHT_COMPRESS. Ele pode ser substituído em uma classe derivada para tomar ações específicas do aplicativo. Leia a documentação da API de animação do Windows para obter mais informações sobre [gerenciamento de conflitos](/windows/win32/api/uianimation/nf-uianimation-iuianimationprioritycomparison-haspriority).

## <a name="canimationcontrolleronhaspriorityconclude"></a><a name="onhaspriorityconclude"></a>canimationcontroller::onhaspriorityconcluir

Chamado pelo quadro para resolver conflitos de agendamento.

```
virtual BOOL OnHasPriorityConclude(
    CAnimationGroup* pGroupScheduled,
    CAnimationGroup* pGroupNew,
    UI_ANIMATION_PRIORITY_EFFECT priorityEffect);
```

### <a name="parameters"></a>Parâmetros

*pGroupScheduled*<br/>
O grupo que possui o storyboard atualmente programado.

*pGroupNew*<br/>
O grupo que possui o novo storyboard que está em conflito de agendamento com o storyboard programado de propriedade do pGroupScheduled.

*priorityEffect*<br/>
O efeito potencial no pGroupNew se pGroupScheduled tem uma prioridade maior.

### <a name="return-value"></a>Valor retornado

Deve retornar TRUE se storyboard de propriedade do pGroupNew tiver prioridade. Deve retornar FALSE se storyboard de propriedade do pGroupGroupScheduled tiver prioridade.

### <a name="remarks"></a>Comentários

Este método é chamado se você habilitar eventos de comparação de prioridades usando CAnimationController::EnablePriorityComparisonHandler e especificar UI_ANIMATION_PHT_CONCLUDE. Ele pode ser substituído em uma classe derivada para tomar ações específicas do aplicativo. Leia a documentação da API de animação do Windows para obter mais informações sobre [gerenciamento de conflitos](/windows/win32/api/uianimation/nf-uianimation-iuianimationprioritycomparison-haspriority).

## <a name="canimationcontrolleronhasprioritytrim"></a><a name="onhasprioritytrim"></a>canimationcontroller::OnHasPriorityTrim

Chamado pelo quadro para resolver conflitos de agendamento.

```
virtual BOOL OnHasPriorityTrim(
    CAnimationGroup* pGroupScheduled,
    CAnimationGroup* pGroupNew,
    UI_ANIMATION_PRIORITY_EFFECT priorityEffect);
```

### <a name="parameters"></a>Parâmetros

*pGroupScheduled*<br/>
O grupo que possui o storyboard atualmente programado.

*pGroupNew*<br/>
O grupo que possui o novo storyboard que está em conflito de agendamento com o storyboard programado de propriedade do pGroupScheduled.

*priorityEffect*<br/>
O efeito potencial no pGroupNew se pGroupScheduled tem uma prioridade maior.

### <a name="return-value"></a>Valor retornado

Deve retornar TRUE se storyboard de propriedade do pGroupNew tiver prioridade. Deve retornar FALSE se storyboard de propriedade do pGroupGroupScheduled tiver prioridade.

### <a name="remarks"></a>Comentários

Este método é chamado se você habilitar eventos de comparação de prioridades usando CAnimationController::EnablePriorityComparisonHandler e especificar UI_ANIMATION_PHT_TRIM. Ele pode ser substituído em uma classe derivada para tomar ações específicas do aplicativo. Leia a documentação da API de animação do Windows para obter mais informações sobre [gerenciamento de conflitos](/windows/win32/api/uianimation/nf-uianimation-iuianimationprioritycomparison-haspriority).

## <a name="canimationcontrolleronstoryboardstatuschanged"></a><a name="onstoryboardstatuschanged"></a>CAnimationController::OnStoryboardStatusChanged

Chamado pela estrutura quando o status do storyboard mudou.

```
virtual void OnStoryboardStatusChanged(
    CAnimationGroup* pGroup,
    UI_ANIMATION_STORYBOARD_STATUS newStatus,
    UI_ANIMATION_STORYBOARD_STATUS previousStatus);
```

### <a name="parameters"></a>Parâmetros

*pGroup*<br/>
Um ponteiro para um grupo de animação que possui o storyboard cujo status mudou.

*newStatus*<br/>
Especifica o novo status.

*previousStatus*<br/>
Especifica o status anterior.

### <a name="remarks"></a>Comentários

Este método é chamado se você habilitar eventos de storyboard usando CAnimationController::EnableStoryboardEventHandler. Ele pode ser substituído em uma classe derivada para tomar ações específicas do aplicativo.

## <a name="canimationcontrolleronstoryboardupdated"></a><a name="onstoryboardupdated"></a>CAnimationController::OnStoryboardAtualizado

Chamado pelo framework quando storyboard foi atualizado.

```
virtual void OnStoryboardUpdated(CAnimationGroup* pGroup);
```

### <a name="parameters"></a>Parâmetros

*pGroup*<br/>
Um ponteiro para um grupo que possui o storyboard.

### <a name="remarks"></a>Comentários

Este método é chamado se você habilitar eventos de storyboard usando CAnimationController::EnableStoryboardEventHandler. Ele pode ser substituído em uma classe derivada para tomar ações específicas do aplicativo.

## <a name="canimationcontrollerremoveallanimationgroups"></a><a name="removeallanimationgroups"></a>CAnimationController::RemoveAllAnimationGroups

Remove todos os grupos de animação do controlador de animação.

```
void RemoveAllAnimationGroups();
```

### <a name="remarks"></a>Comentários

Todos os grupos serão excluídos, seu ponteiro, se armazenado no nível do aplicativo, deve ser invalidado. Se CAnimationGroup::m_bAutodestroyAnimationObjects para que um grupo seja excluído seja TRUE, todos os objetos de animação que pertencem a esse grupo serão excluídos; caso contrário, suas referências ao controlador de animação pai serão definidas como NULL e podem ser adicionadas a outro controlador.

## <a name="canimationcontrollerremoveanimationgroup"></a><a name="removeanimationgroup"></a>CAnimationController::RemoveAnimationGroup

Remove um grupo de animação com ID especificado do controlador de animação.

```
void RemoveAnimationGroup(UINT32 nGroupID);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica id de grupo de animação.

### <a name="remarks"></a>Comentários

Este método remove um grupo de animação da lista interna de grupos e o exclui, portanto, se você armazenou um ponteiro para esse grupo de animação, ele deve ser invalidado. Se CAnimationGroup::m_bAutodestroyAnimationObjects for TRUE, todos os objetos de animação que pertencem a esse grupo serão excluídos; caso contrário, suas referências ao controlador de animação pai serão definidas como NULL e podem ser adicionadas a outro controlador.

## <a name="canimationcontrollerremoveanimationobject"></a><a name="removeanimationobject"></a>CAnimationController::RemoveAnimationObject

Remova um objeto de animação do controlador de animação.

```
void RemoveAnimationObject(
    CAnimationBaseObject* pObject,
    BOOL bNoDelete = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Pobject*<br/>
Um ponteiro para um objeto de animação.

*bNoDelete*<br/>
Se este parâmetro for TRUE, o objeto não será excluído após a remoção.

### <a name="remarks"></a>Comentários

Remove um objeto de animação do controlador de animação e do grupo de animação. Chame esta função se um objeto em particular não deve mais ser animado, ou se você precisar mover o objeto para outro controlador de animação. No último caso bNoDelete deve ser VERDADEIRO.

## <a name="canimationcontrollerremovetransitions"></a><a name="removetransitions"></a>CAnimationController::RemoveTransitions

Remove transições de objetos de animação que pertencem ao grupo especificado.

```
void RemoveTransitions(UINT32 nGroupID);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica o ID do grupo.

### <a name="remarks"></a>Comentários

O grupo faz loops sobre seus objetos de animação e chama ClearTransitions(FALSE) para cada objeto de animação. Este método é chamado pela estrutura após a animação ter sido programada.

## <a name="canimationcontrollerschedulegroup"></a><a name="schedulegroup"></a>CAnimationController::ScheduleGroup

Agenda uma animação.

```
BOOL ScheduleGroup(
    UINT32 nGroupID,
    UI_ANIMATION_SECONDS time = 0.0);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica o ID do grupo de animação para agendar.

*time*<br/>
Especifica o tempo para agendar.

### <a name="return-value"></a>Valor retornado

TRUE se a animação foi programada com sucesso. FALSO se storyboard não foi criado ou outro erro ocorrer.

### <a name="remarks"></a>Comentários

Você deve chamar AnimateGroup com parâmetro bScheduleNow definido como FALSO schedulegroup anterior. Você pode especificar o tempo de animação desejado obtido de IUIAnimationTimer::GetTime. Se o parâmetro de tempo for 0.0, a animação será agendada para o momento atual.

## <a name="canimationcontrollersetrelatedwnd"></a><a name="setrelatedwnd"></a>CAnimationController::SetRelatedWnd

Estabelece uma relação entre o controlador de animação e uma janela.

```
void SetRelatedWnd(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Um ponteiro para o objeto da janela para definir.

### <a name="remarks"></a>Comentários

Se um objeto CWnd relacionado estiver definido, o controlador de animação poderá atualizá-lo automaticamente (enviar WM_PAINT mensagem) quando o status do gerenciador de animação tiver sido alterado ou o evento de atualização pós-hora do temporizador ocorreu.

## <a name="canimationcontrollerupdateanimationmanager"></a><a name="updateanimationmanager"></a>CAnimationController::UpdateAnimationManager

Direciona o gerenciador de animação para atualizar os valores de todas as variáveis de animação.

```
virtual void UpdateAnimationManager();
```

### <a name="remarks"></a>Comentários

Chamar esse método avança o gerenciador de animação para o tempo atual, alterando os status dos storyboards conforme necessário e atualizando quaisquer variáveis de animação para valores interpolados apropriados. Internamente, este método chama IUIAnimationTimer::GetTime(timeNow) e IUIAnimationManager::Update(timeNow). Anular este método em uma classe derivada para personalizar esse comportamento.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
