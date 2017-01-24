---
title: "Gerenciando menus, barras de controle e aceleradores | Microsoft Docs"
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
  - "tabelas de teclas aceleradoras [C++]"
  - "barras de controle, atualizando em janelas com moldura"
  - "janelas com moldura, atualizando"
  - "MDI, janelas com moldura"
  - "menus, atualizando como alterações de contexto"
  - "compartilhando menus"
  - "barras de status, atualizando"
  - "atualizando objetos de interface do usuário"
  - "objetos de interface do usuário, atualizando"
ms.assetid: 97ca1997-06df-4373-b023-4f7ecd81047b
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Gerenciando menus, barras de controle e aceleradores
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A janela do quadro gerencia atualizar os objetos de interface do usuário, inclusive menus, botões da barra de ferramentas, a barra de status, e aceleradores.  Também gerencia compartilhar a barra de menus em aplicativos MDI.  
  
## Gerenciando menus  
 A janela do quadro participa de atualizar itens da interface do usuário usando o mecanismo de `ON_UPDATE_COMMAND_UI` descrito em [Como atualizar objetos de interface do usuário](../mfc/how-to-update-user-interface-objects.md).  Os botões na barra de ferramentas e em outras barras de controle são atualizados durante o loop ocioso.  Os itens de menu e os menus suspensos na barra de menus são atualizados imediatamente antes de remover o menu para baixo.  
  
 Para aplicativos MDI, a janela do quadro MDI gerencia a barra de menus e a legenda.  Uma janela do quadro MDI possui um menu padrão que será usado como a barra de menus quando não há nenhuma janela ativa filho MDI.  Quando houver filhos ativas, a barra de menus do quadro da janela de documentos é over efetivado pelo menu para a janela ativa filho MDI.  Se um aplicativo MDI da suporte a vários tipos de documento, como o gráfico e os documentos da planilha, cada tipo coloca seus próprios menus na barra de menus e altera a legenda da janela principal do quadro.  
  
 [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md) fornece implementações padrão para os comandos padrão no menu janela que é exibido para aplicativos MDI.  Em particular, o comando de nova janela**ID\_WINDOW\_NEW**\(\) é implementado criar uma nova janela e exibição de quadro no documento atual.  Você precisará substituir essas implementações somente se você precisar de personalização avançada.  
  
 Várias janelas filho MDI do mesmo tipo de documento compartilham recursos no menu.  Se várias janelas filho MDI são criadas pelo mesmo modelo de documento, todas elas poderão usar o mesmo recurso no menu, salvando em recursos do sistema no windows.  
  
## Gerenciando a barra de status  
 A janela do quadro também posicionar a barra de status dentro da área de cliente e gerencia os indicadores de barra de status.  A janela do quadro limpa e atualiza a área de mensagem na barra de status quando necessário e exibe solicitam cadeias de caracteres como o usuário seleciona itens de menu ou botões da barra de ferramentas, conforme descrito em [Como exibir informações de comando na barra de status](../Topic/How%20to:%20Display%20Command%20Information%20in%20the%20Status%20Bar.md).  
  
## Gerenciando aceleradores  
 Cada janela do quadro mantém uma tabela de aceleração opcional que faz a tradução de acelerador de teclado para você automaticamente.  Esse mecanismo facilita definir as teclas de aceleração \(também chamadas teclas de atalho\) que invocam comandos de menu.  
  
## Consulte também  
 [Usando janelas com moldura](../Topic/Using%20Frame%20Windows.md)