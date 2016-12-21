---
title: "Classe de CAnimationController | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CAnimationController"
  - "afxanimationcontroller/CAnimationController"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAnimationController"
ms.assetid: ed294c98-695e-40a6-b940-33ef1d40aa6b
caps.latest.revision: 18
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAnimationController
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa o controlador de animação, que fornece uma interface central para criar e gerenciar animações.  
  
## Sintaxe  
  
```  
class CAnimationController : public CObject;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationController::CAnimationController](../Topic/CAnimationController::CAnimationController.md)|Constrói um controlador de animação.|  
|[CAnimationController::~CAnimationController](../Topic/CAnimationController::~CAnimationController.md)|O destrutor.  Chamado quando o objeto do controlador de animação é destruído.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationController::AddAnimationObject](../Topic/CAnimationController::AddAnimationObject.md)|Adiciona um objeto de animação a um grupo que pertence ao controlador da animação.|  
|[CAnimationController::AddKeyframeToGroup](../Topic/CAnimationController::AddKeyframeToGroup.md)|Adiciona um keyframe ao grupo.|  
|[CAnimationController::AnimateGroup](../Topic/CAnimationController::AnimateGroup.md)|Preparar um grupo para executar a animação e agendar\-lo opcionalmente.|  
|[CAnimationController::CleanUpGroup](../Topic/CAnimationController::CleanUpGroup.md)|Sobrecarregado.  Chamado pela estrutura para limpar o grupo quando a animação é agendada.|  
|[CAnimationController::CreateKeyframe](../Topic/CAnimationController::CreateKeyframe.md)|Sobrecarregado.  Cria um keyframe que depende de transição e o adiciona ao grupo especificado.|  
|[CAnimationController::EnableAnimationManagerEvent](../Topic/CAnimationController::EnableAnimationManagerEvent.md)|Define ou libere um manipulador para chamar quando o status do gerenciador de animação é alterado.|  
|[CAnimationController::EnableAnimationTimerEventHandler](../Topic/CAnimationController::EnableAnimationTimerEventHandler.md)|Define ou versões um manipulador de eventos de tempo e manipulador para atualizações de temporização.|  
|[CAnimationController::EnablePriorityComparisonHandler](../Topic/CAnimationController::EnablePriorityComparisonHandler.md)|Define ou libere o manipulador de comparação de prioridade para chamar para determinar se um storyboard agendada pode ser cancelado, concluído, quebrado ou compactado.|  
|[CAnimationController::EnableStoryboardEventHandler](../Topic/CAnimationController::EnableStoryboardEventHandler.md)|Define ou versões um manipulador de eventos de status e de atualização do storyboard.|  
|[CAnimationController::FindAnimationGroup](../Topic/CAnimationController::FindAnimationGroup.md)|Sobrecarregado.  Localiza um grupo de animação por seu storyboard.|  
|[CAnimationController::FindAnimationObject](../Topic/CAnimationController::FindAnimationObject.md)|Objeto de animação de localiza que contém uma variável especificado de animação.|  
|[CAnimationController::GetKeyframeStoryboardStart](../Topic/CAnimationController::GetKeyframeStoryboardStart.md)|Retorna um keyframe que identifica o início do storyboard.|  
|[CAnimationController::GetUIAnimationManager](../Topic/CAnimationController::GetUIAnimationManager.md)|Fornece o objeto encapsulado de IUIAnimationManager de acesso.|  
|[CAnimationController::GetUIAnimationTimer](../Topic/CAnimationController::GetUIAnimationTimer.md)|Fornece o objeto encapsulado de IUIAnimationTimer de acesso.|  
|[CAnimationController::GetUITransitionFactory](../Topic/CAnimationController::GetUITransitionFactory.md)|Um ponteiro para a interface ou o NULL IUIAnimationTransitionFactory de, se a criação de biblioteca de transição falhou.|  
|[CAnimationController::GetUITransitionLibrary](../Topic/CAnimationController::GetUITransitionLibrary.md)|Fornece o objeto encapsulado de IUIAnimationTransitionLibrary de acesso.|  
|[CAnimationController::IsAnimationInProgress](../Topic/CAnimationController::IsAnimationInProgress.md)|Informa se o menos um grupo está executando a animação.|  
|[CAnimationController::IsValid](../Topic/CAnimationController::IsValid.md)|Informa se o controlador de animação é válido.|  
|[CAnimationController::OnAnimationIntegerValueChanged](../Topic/CAnimationController::OnAnimationIntegerValueChanged.md)|Chamado pela estrutura quando o valor inteiro da variável de animação alterar.|  
|[CAnimationController::OnAnimationManagerStatusChanged](../Topic/CAnimationController::OnAnimationManagerStatusChanged.md)|Chamado pela estrutura em resposta ao evento de StatusChanged do gerenciador de animação.|  
|[CAnimationController::OnAnimationTimerPostUpdate](../Topic/CAnimationController::OnAnimationTimerPostUpdate.md)|Chamado pela estrutura após uma atualização de animação é concluído.|  
|[CAnimationController::OnAnimationTimerPreUpdate](../Topic/CAnimationController::OnAnimationTimerPreUpdate.md)|Chamado pela estrutura antes de uma atualização de animação começa.|  
|[CAnimationController::OnAnimationTimerRenderingTooSlow](../Topic/CAnimationController::OnAnimationTimerRenderingTooSlow.md)|Chamado pela estrutura quando a taxa de quadros renderizados para uma animação cair dentro de uma taxa de quadros desejável mínima.|  
|[CAnimationController::OnAnimationValueChanged](../Topic/CAnimationController::OnAnimationValueChanged.md)|Chamado pela estrutura quando o valor da variável de animação alterar.|  
|[CAnimationController::OnBeforeAnimationStart](../Topic/CAnimationController::OnBeforeAnimationStart.md)|Chamado pela estrutura mesmo antes da animação é agendada.|  
|[CAnimationController::OnHasPriorityCancel](../Topic/CAnimationController::OnHasPriorityCancel.md)|Chamado pela estrutura para agendar resolver conflitos.|  
|[CAnimationController::OnHasPriorityCompress](../Topic/CAnimationController::OnHasPriorityCompress.md)|Chamado pela estrutura para agendar resolver conflitos.|  
|[CAnimationController::OnHasPriorityConclude](../Topic/CAnimationController::OnHasPriorityConclude.md)|Chamado pela estrutura para agendar resolver conflitos.|  
|[CAnimationController::OnHasPriorityTrim](../Topic/CAnimationController::OnHasPriorityTrim.md)|Chamado pela estrutura para agendar resolver conflitos.|  
|[CAnimationController::OnStoryboardStatusChanged](../Topic/CAnimationController::OnStoryboardStatusChanged.md)|Chamado pela estrutura quando o status do storyboard alterar.|  
|[CAnimationController::OnStoryboardUpdated](../Topic/CAnimationController::OnStoryboardUpdated.md)|Chamado pela estrutura quando o storyboard é atualizado.|  
|[CAnimationController::RemoveAllAnimationGroups](../Topic/CAnimationController::RemoveAllAnimationGroups.md)|Remove todos os grupos de animação do controlador da animação.|  
|[CAnimationController::RemoveAnimationGroup](../Topic/CAnimationController::RemoveAnimationGroup.md)|Remove um grupo de animação com ID especificado do controlador da animação.|  
|[CAnimationController::RemoveAnimationObject](../Topic/CAnimationController::RemoveAnimationObject.md)|Remover um objeto de animação do controlador da animação.|  
|[CAnimationController::RemoveTransitions](../Topic/CAnimationController::RemoveTransitions.md)|Remove as transições de objetos de animação que pertencem ao grupo especificado.|  
|[CAnimationController::ScheduleGroup](../Topic/CAnimationController::ScheduleGroup.md)|Agenda uma animação.|  
|[CAnimationController::SetRelatedWnd](../Topic/CAnimationController::SetRelatedWnd.md)|Estabelece uma relação entre o controlador de animação e uma janela.|  
|[CAnimationController::UpdateAnimationManager](../Topic/CAnimationController::UpdateAnimationManager.md)|Direciona o gerenciador de animação para atualizar os valores de quaisquer variáveis de animação.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationController::CleanUpGroup](../Topic/CAnimationController::CleanUpGroup.md)|Sobrecarregado.  Um auxiliar que limpe o grupo.|  
|[CAnimationController::OnAfterSchedule](../Topic/CAnimationController::OnAfterSchedule.md)|Chamado pela estrutura quando uma animação para o grupo especificado é agendada apenas.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationController::g\_KeyframeStoryboardStart](../Topic/CAnimationController::g_KeyframeStoryboardStart.md)|Um keyframe que representa o início do storyboard.|  
|[CAnimationController::m\_bIsValid](../Topic/CAnimationController::m_bIsValid.md)|Especifica se um controlador de animação é válido ou não.  Esse membro é definido como FALSO se o sistema operacional atual não oferece suporte a animação API do windows.|  
|[CAnimationController::m\_lstAnimationGroups](../Topic/CAnimationController::m_lstAnimationGroups.md)|Uma lista de grupos de animação que pertencem a esse controlador de animação.|  
|[CAnimationController::m\_pAnimationManager](../Topic/CAnimationController::m_pAnimationManager.md)|Armazena um ponteiro para o objeto COM do gerenciador de animação.|  
|[CAnimationController::m\_pAnimationTimer](../Topic/CAnimationController::m_pAnimationTimer.md)|Armazena um ponteiro para o objeto COM timer de animação.|  
|[CAnimationController::m\_pRelatedWnd](../Topic/CAnimationController::m_pRelatedWnd.md)|Um ponteiro para um objeto relacionado de CWnd, que pode ser redesenhado automaticamente quando o status do gerenciador de animação foi alterado, ou evento de atualização de postagem ocorreu.  Pode ser NULO.|  
|[CAnimationController::m\_pTransitionFactory](../Topic/CAnimationController::m_pTransitionFactory.md)|Armazena um ponteiro para fazer a transição o objeto COM de fábrica.|  
|[CAnimationController::m\_pTransitionLibrary](../Topic/CAnimationController::m_pTransitionLibrary.md)|Armazena um ponteiro para fazer a transição o objeto COM de biblioteca.|  
  
## Comentários  
 a classe de CAnimationController é a classe principal que gerencia animações.  Você pode criar uma ou mais instâncias do controlador da animação em um aplicativo e, opcionalmente, para conectar\-se uma instância do controlador de animação a um objeto de CWnd usando CAnimationController::SetRelatedWnd.  A conexão é necessária para enviar automaticamente mensagens de WM\_PAINT relacionada à janela quando o status do gerenciador de animação foi alterado ou timer de animação foi atualizada.  Se você não permite esse relacionamento, você deve redesenho uma janela que exibe uma animação manualmente.  Essa finalidade você pode derivar uma classe de CAnimationController e substituir OnAnimationManagerStatusChanged e\/ou OnAnimationTimerPostUpdate e invalidar uma ou mais janelas quando necessário.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CAnimationController](../../mfc/reference/canimationcontroller-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)