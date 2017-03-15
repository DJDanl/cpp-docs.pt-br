---
title: "Tarefas de programa&#231;&#227;o da Internet MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "aplicativos da Internet, primeiras etapas"
  - "aplicativos da Internet, guia de introdução"
ms.assetid: 6377e9b8-07c4-4380-b63b-05f5a9061313
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tarefas de programa&#231;&#227;o da Internet MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Esta seção contém etapas detalhadas para adicionar suporte da Internet em seus aplicativos.  Os tópicos incluem como usar as classes de MFC internet para permitir que os aplicativos existentes, e como adicionar suporte do documento ativo para seu componente COM existente.  Você deseja criar um documento com as contagens atualizados dos preços de títulos, de futebol de Pittsburgh, e a temperatura a mais recente na Antártica?  O Microsoft fornece diversas tecnologias para ajudar você faz isso pela Internet.  
  
 As tecnologias ativos incluem controles ActiveX \(anteriormente controladores OLE\) e documentos ativos; WinInet para recuperar facilmente e salvar arquivos por meio da Internet\); apelidos e assíncronos da transferência eficaz de dados.  Visual C\+\+ fornece assistentes para ajudar você a começar rapidamente em um aplicativo do acionador de partida.  Para obter uma introdução a essas tecnologias, consulte [MFC Internet que programa noções básicas](../mfc/mfc-internet-programming-basics.md) e [WITH MFC](../mfc/mfc-com.md).  
  
 Têm\-no sempre queria a FTP um arquivo mas não eles descobriram protocolos de programação de Winsock e de rede?  As classes de WinInet encapsulam esses protocolos o, fornecendo um conjunto simples de funções que você pode usar para escrever um aplicativo cliente na Internet para os arquivos de download usando HTTP, o FTP, e o Gopher.  Você pode usar WinInet para pesquisar diretórios em seu disco rígido ou no mundo.  Você pode coletar dados transparente de vários tipos diferentes, e apresenta ao usuário em uma interface integrada.  
  
 Você tiver grandes quantidades de dados para download?  Apelidos assíncronas fornecem uma solução COM \(Component Object Model\) para a renderização progressiva de objetos grandes.  WinInet também pode ser usado de forma assíncrona.  
  
 A tabela a seguir descreve algumas das coisas que você pode fazer com essas tecnologias.  
  
|Você tem|Você deseja que a|Você deve|  
|--------------|-----------------------|---------------|  
|Um servidor Web.|Logons e informações detalhadas de controle sobre solicitações de URL.|Grave um filtro, notificações de solicitação para eventos de logon e mapeamento de URL.|  
|Um navegador da Web.|Fornecer conteúdo dinâmico.|Crie controles ActiveX e documentos ativas.|  
|Um aplicativo documento baseado.|Adicionar suporte ao FTP um arquivo.|Use WinInet origem ou assíncronas.|  
  
 Consulte os seguintes tópicos para obter detalhes para começar started:  
  
-   [Opções de criação de aplicativo](../mfc/application-design-choices.md)  
  
-   [MFC a gravação de aplicativos](../mfc/writing-mfc-applications.md)  
  
-   [Controles ActiveX na Internet](../mfc/activex-controls-on-the-internet.md)  
  
-   [Atualizando um controle ActiveX existente](../Topic/Upgrading%20an%20Existing%20ActiveX%20Control.md)  
  
-   [Documentos ativos na Internet](../Topic/Active%20Documents%20on%20the%20Internet.md)  
  
-   [Apelidos assíncrona na Internet](../mfc/asynchronous-monikers-on-the-internet.md)  
  
-   [Aplicativos da Internet de teste](../mfc/testing-internet-applications.md)  
  
-   [Segurança da Internet](../Topic/Internet%20Security%20\(C++\).md)  
  
## Consulte também  
 [Noções básicas de programação da Internet MFC](../mfc/mfc-internet-programming-basics.md)   
 [Informações da Internet por tarefa](../mfc/internet-information-by-task.md)