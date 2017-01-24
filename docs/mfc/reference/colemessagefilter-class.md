---
title: "Classe de COleMessageFilter | Microsoft Docs"
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
  - "COleMessageFilter"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "aplicativos [OLE], gerenciando interações"
  - "Classe de COleMessageFilter"
  - "mensagem filtragem [C++]"
  - "mensagens [C++], O OLE"
  - "OLE [C++], gerenciando concorrência"
  - "Aplicativos OLE [C++], gerenciando interações"
  - "Mensagens VELHOS"
ms.assetid: b1fd1639-fac4-4fd0-bf17-15172deba13c
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleMessageFilter
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gerencia concorrência necessária por interação de aplicativos OLE.  
  
## Sintaxe  
  
```  
class COleMessageFilter : public CCmdTarget  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleMessageFilter::COleMessageFilter](../Topic/COleMessageFilter::COleMessageFilter.md)|Constrói um objeto de `COleMessageFilter` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleMessageFilter::BeginBusyState](../Topic/COleMessageFilter::BeginBusyState.md)|Colocar o aplicativo no estado ocupado.|  
|[COleMessageFilter::EnableBusyDialog](../Topic/COleMessageFilter::EnableBusyDialog.md)|Ativar e desativar a caixa de diálogo que aparece quando um aplicativo é chamado ocupado.|  
|[COleMessageFilter::EnableNotRespondingDialog](../Topic/COleMessageFilter::EnableNotRespondingDialog.md)|Ativar e desativar a caixa de diálogo que aparece quando um aplicativo é chamado não responder.|  
|[COleMessageFilter::EndBusyState](../Topic/COleMessageFilter::EndBusyState.md)|Finaliza ocupado o estado do aplicativo.|  
|[COleMessageFilter::OnMessagePending](../Topic/COleMessageFilter::OnMessagePending.md)|Chamado pela estrutura para processar mensagens quando uma chamada OLE está em andamento.|  
|[COleMessageFilter::Register](../Topic/COleMessageFilter::Register.md)|Registra o filtro de mensagem com as dlls VELHOS do sistema.|  
|[COleMessageFilter::Revoke](../Topic/COleMessageFilter::Revoke.md)|Revoga o registro de filtro de mensagem com as dlls VELHOS do sistema.|  
|[COleMessageFilter::SetBusyReply](../Topic/COleMessageFilter::SetBusyReply.md)|Determina a resposta ocupado de aplicativo a uma chamada OLE.|  
|[COleMessageFilter::SetMessagePendingDelay](../Topic/COleMessageFilter::SetMessagePendingDelay.md)|Determina quanto tempo o aplicativo aguarda uma resposta a uma chamada OLE.|  
|[COleMessageFilter::SetRetryReply](../Topic/COleMessageFilter::SetRetryReply.md)|Determina a resposta do aplicativo de chamada para um aplicativo ocupado.|  
  
## Comentários  
 A classe de `COleMessageFilter` é útil em aplicativos visuais do servidor e de contêiner de edição, bem como aplicativos VELHOS de automação.  Para aplicativos de servidor que está sendo chamado, essa classe pode ser usada para fazer o aplicativo “ocupado” de modo que chamadas de entrada de outros aplicativos de contêiner serão canceladas ou experimentados de volta posteriormente.  Essa classe também pode ser usada para determinar a ação a ser tomada por um aplicativo de chamada quando o aplicativo é chamado ocupado.  
  
 O uso comum é que um aplicativo para servidores chama [BeginBusyState](../Topic/COleMessageFilter::BeginBusyState.md) e [EndBusyState](../Topic/COleMessageFilter::EndBusyState.md) quando seria perigoso para um documento ou outro objeto acessível OLE é destruído.  Essas chamadas são feitas em [CWinApp::OnIdle](../Topic/CWinApp::OnIdle.md) durante atualizações de interface do usuário.  
  
 Por padrão, um objeto de `COleMessageFilter` é atribuído quando o aplicativo é inicializado.  Pode ser recuperada com [AfxOleGetMessageFilter](../Topic/AfxOleGetMessageFilter.md).  
  
 Esta é uma classe avançado; raramente você precisa trabalhar diretamente com ele.  
  
 Para obter mais informações, consulte o artigo [servidores: implementando um servidor](../../mfc/servers-implementing-a-server.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 `COleMessageFilter`  
  
## Requisitos  
 **Cabeçalho:** afxole.h  
  
## Consulte também  
 [Classe de CCmdTarget](../Topic/CCmdTarget%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CCmdTarget](../Topic/CCmdTarget%20Class.md)