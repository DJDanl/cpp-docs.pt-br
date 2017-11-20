---
title: Roteamento de comando | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- MFC, command routing
- command handling [MFC], routing commands
- handlers [MFC]
- handlers, command [MFC]
- command routing
ms.assetid: 9393a956-bdd4-47c5-9013-dbd680433f93
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 622853951c9119bb2a32e9e624966bf77579b557
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="command-routing"></a>Roteamento de comando
Sua responsabilidade em trabalhar com os comandos é limitada a fazer conexões de mapa de mensagem entre os comandos e suas funções de manipulador, uma tarefa para a qual você pode usar a janela Propriedades. Você também deve gravar a maioria dos manipuladores de comandos.  
  
 Mensagens do Windows geralmente são enviadas para a janela do quadro principal, mas as mensagens de comando, em seguida, são roteadas para outros objetos. A estrutura de rotas de comandos por meio de uma sequência de padrão de objetos de destino do comando, um dos quais deve ter um manipulador para o comando. Cada objeto de destino do comando verifica seu mapa de mensagem para ver se ele pode manipular a mensagem de entrada.  
  
 Classes diferentes de destino do comando Verifique suas próprias mensagens mapeia em momentos diferentes. Normalmente, uma classe encaminha o comando para alguns outros objetos para dar-lhes a primeira instância no comando. Se nenhum desses objetos lida com o comando, a classe original verifica seu próprio mapa de mensagem. Em seguida, se ele não pode fornecer um manipulador de si mesmo, ele pode rotear o comando para ainda mais destinos de comando. A tabela [rota de comando padrão](#_core_standard_command_route) abaixo mostra como cada uma das classes estruturas essa sequência. A ordem geral na qual um destino do comando direciona um comando é:  
  
1.  Para seu objeto de destino do comando filho ativo no momento.  
  
2.  A mesmo.  
  
3.  Para outros destinos de comando.  
  
 Como esse mecanismo de roteamento comparadas para que o manipulador faz em resposta a um comando é cara, o custo de roteamento é baixo. Tenha em mente que a estrutura gera comandos somente quando o usuário interage com um objeto de interface do usuário.  
  
### <a name="_core_standard_command_route"></a>Padrão de rota de comando  
  
|Quando um objeto desse tipo recebe um comando. . .|Ele oferece a mesmo e outros objetos de destino do comando a oportunidade de lidar com o comando nesta ordem:|  
|----------------------------------------------------------|-----------------------------------------------------------------------------------------------------|  
|Janela de quadro MDI (`CMDIFrameWnd`)|1.  Ativo`CMDIChildWnd`<br />2.  Essa janela do quadro<br />3.  Aplicativo (`CWinApp` objeto)|  
|Janela do quadro de documento (`CFrameWnd`, `CMDIChildWnd`)|1.  Modo de exibição ativo<br />2.  Essa janela do quadro<br />3.  Aplicativo (`CWinApp` objeto)|  
|Exibir|1.  Este modo de exibição<br />2.  Documento anexado ao modo de exibição|  
|Documento|1.  Este documento<br />2.  Modelo de documento anexado ao documento|  
|Caixa de diálogo|1.  Essa caixa de diálogo<br />2.  Janela que possui a caixa de diálogo<br />3.  Aplicativo (`CWinApp` objeto)|  
  
 Onde numeradas entradas na segunda coluna da tabela anterior mencionem outros objetos, como um documento, consulte o item correspondente na primeira coluna. Por exemplo, ao ler na segunda coluna que a exibição encaminha um comando para o documento, consulte a entrada de "Documento" na primeira coluna a seguir o roteamento adicional.  
  
## <a name="see-also"></a>Consulte também  
 [Como o Framework chama um manipulador](../mfc/how-the-framework-calls-a-handler.md)

