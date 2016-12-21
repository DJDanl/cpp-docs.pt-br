---
title: "Assistente de Manipulador de Eventos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.codewiz.eventhandler.overview"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de Manipulador de Eventos [C++]"
ms.assetid: af8e1835-94b1-4d9a-b353-c519e011d3a1
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente de Manipulador de Eventos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este assistente adiciona um manipulador de eventos para um controle de caixa de diálogo para a classe de sua escolha.  Se você adicionar um manipulador de eventos a partir do  [janela de propriedades](../Topic/Properties%20Window.md), você pode adicioná\-lo apenas para a classe que implementa a caixa de diálogo.  Consulte  [Adicionando manipuladores de eventos para controles de caixa de diálogo](../mfc/adding-event-handlers-for-dialog-box-controls.md) para obter mais informações.  
  
 **Nome do comando**  
 Identifica o controle selecionado, o qual o manipulador de eventos é adicionado.  Esta caixa está disponível.  
  
 **Tipo de mensagem**  
 Exibe a lista de manipuladores de mensagem possíveis atual para o controle selecionado.  
  
 **Nome do manipulador de função**  
 Exibe o nome da função que é adicionado ao manipular o evento.  Por padrão, o nome se baseia o tipo de mensagem e o comando, precedida por "On".  Por exemplo, para o botão chamado `IDC_BUTTON1`, o tipo de mensagem `BN_CLICKED` exibe o nome de função do manipulador `OnBnClickedButton1`.  
  
 **Lista de classe**  
 Exibe as classes disponíveis para o qual você pode adicionar um manipulador de eventos.  A classe para a caixa de diálogo é exibida em vermelho.  
  
 **Descrição do manipulador**  
 Fornece uma descrição para o item selecionado no  **tipo de mensagem** caixa.  Esta caixa está disponível.  
  
 **Adicionar e editar**  
 Adiciona o manipulador de mensagens para o objeto ou classe selecionada e, em seguida, abre o editor de texto para a nova função para que você possa adicionar o código de manipulador de notificações de controle.  
  
 **Editar código**  
 Abre o editor de texto da função selecionada para que possa adicionar ou editar o código de manipulador de notificações de controle.  
  
## Consulte também  
 [Adicionando um manipulador de eventos](../ide/adding-an-event-handler-visual-cpp.md)