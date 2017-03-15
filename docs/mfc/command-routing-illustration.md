---
title: "Ilustra&#231;&#227;o de roteamento do comando | Microsoft Docs"
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
  - "tratamento de comandos, roteando comandos"
  - "roteamento de comando, Manipulador OnCmdMsg"
  - "MFC, roteamento de comando"
ms.assetid: 4b7b4741-565f-4878-b076-fd85c670f87f
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Ilustra&#231;&#227;o de roteamento do comando
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para ilustrar, considere uma mensagem do comando de um espaço livre qualquer item de menu no menu de edição de um aplicativo MDI.  Suponha que a função de manipulador deste comando for uma função de membro da classe do documento de aplicativo.  Veja como o comando atingir seu manipulador depois que o usuário escolhe o item de menu:  
  
1.  A janela principal do quadro obtém a mensagem do primeiro comando.  
  
2.  A janela principal do quadro MDI da janela ativa no momento filho MDI uma possibilidade tratar o comando.  
  
3.  O roteamento padrão de uma janela filho MDI do quadro da sua exibição uma possibilidade no comando antes de verificar seu próprio mapa da mensagem.  
  
4.  A exibição verifique seu próprio mapa de mensagem primeiro e, não localizando nenhum manipulador, rotas seguintes o comando ao documento associado.  
  
5.  Verifica o documento seu mapa da mensagem e localiza um manipulador.  Essa função de membro do documento é chamada e o roteamento.  
  
 Se o documento não tinha um manipulador rotearia em seguida, o comando para seu modelo de documento.  O comando retorna à exibição e na janela do quadro.  Finalmente, a janela do quadro poderia verificar seu mapa da mensagem.  Se houve falha nessa verificação além disso, o comando será roteado de volta para a janela principal do quadro MDI e para o objeto do aplicativo — o destino final de comandos não manipulado.  
  
## Consulte também  
 [Como o Framework chama um identificador](../mfc/how-the-framework-calls-a-handler.md)