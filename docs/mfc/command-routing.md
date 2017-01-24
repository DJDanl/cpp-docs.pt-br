---
title: "Roteamento de comando | Microsoft Docs"
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
  - "MFC, roteamento de comando"
  - "comando de manipulação, roteamento de comandos"
  - "manipuladores"
  - "manipuladores de comando"
  - "roteamento de comando"
ms.assetid: 9393a956-bdd4-47c5-9013-dbd680433f93
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Roteamento de comando
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Sua responsabilidade em trabalhar com os comandos é limitada a fazer conexões de mapa de mensagem entre comandos e suas funções de manipulador, uma tarefa para a qual você pode usar a janela Propriedades. Você também deve escrever a maioria dos manipuladores de comandos.  
  
 Mensagens do Windows geralmente são enviadas para a janela do quadro principal, mas as mensagens de comando são encaminhadas para outros objetos. A estrutura roteia comandos por meio de uma seqüência padrão de objetos de destino do comando, um deles deve ter um manipulador para o comando. Cada objeto de destino do comando verifica seu mapa de mensagem para ver se ele pode manipular a mensagem de entrada.  
  
 Classes diferentes de destino do comando Verifique suas próprias mensagens mapeia em momentos diferentes. Normalmente, uma classe encaminha o comando para determinados outros objetos para dar\-lhes a chance de primeiro no comando. Se nenhum desses objetos lida com o comando, a classe original verifica seu próprio mapa de mensagem. Em seguida, se ele não pode fornecer um manipulador em si, ele pode rotear o comando para ainda mais destinos de comando. A tabela [rota de comando padrão](#_core_standard_command_route) abaixo mostra como cada uma das classes estruturas essa sequência. A ordem geral na qual um destino do comando direciona um comando é:  
  
1.  Para seu objeto de destino do comando filho ativo no momento.  
  
2.  A mesmo.  
  
3.  Para outros destinos de comando.  
  
 Quanto custa o mecanismo de roteamento? Em comparação com o que faz seu manipulador em resposta a um comando, o custo do roteamento é baixa. Tenha em mente que a estrutura gera comandos somente quando o usuário interage com um objeto de interface do usuário.  
  
### Rota padrão de comando  
  
|Quando um objeto desse tipo recebe um comando. . .|Ele oferece em si e outros objetos de destino do comando a possibilidade de tratar o comando nesta ordem:|  
|--------------------------------------------------------|---------------------------------------------------------------------------------------------------------------|  
|Janela de quadro MDI \(`CMDIFrameWnd`\)|1.  Ativo `CMDIChildWnd`<br />2.  Esta janela de quadro<br />3.  Aplicativo \(`CWinApp` objeto\)|  
|Janela de quadro do documento \(`CFrameWnd`, `CMDIChildWnd`\)|1.  Modo de exibição ativo<br />2.  Esta janela de quadro<br />3.  Aplicativo \(`CWinApp` objeto\)|  
|Modo de Exibição|1.  Este modo de exibição<br />2.  Documento anexado no modo de exibição|  
|Documento|1.  Este documento<br />2.  Modelo de documento anexado ao documento|  
|Caixa de diálogo|1.  Essa caixa de diálogo<br />2.  Janela que possui a caixa de diálogo<br />3.  Aplicativo \(`CWinApp` objeto\)|  
  
 Onde numeradas entradas na segunda coluna da tabela anterior mencionam outros objetos, como um documento, consulte o item correspondente na primeira coluna. Por exemplo, quando você lê na segunda coluna que a exibição encaminha um comando para seu documento, consulte a entrada "Documento" na primeira coluna siga o roteamento ainda mais.  
  
## Consulte também  
 [Como o Framework chama um identificador](../mfc/how-the-framework-calls-a-handler.md)