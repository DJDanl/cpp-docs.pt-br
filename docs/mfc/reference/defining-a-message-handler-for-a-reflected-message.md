---
title: "Definindo um manipulador de mensagens para uma mensagem refletida | Microsoft Docs"
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
  - "vc.codewiz.defining.msg.msghandler"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "lidando com erros, mensagens refletidas"
  - "mensagens, refletido"
ms.assetid: 5a403528-58c5-46e7-90d5-4a77f0ab9b9c
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Definindo um manipulador de mensagens para uma mensagem refletida
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Depois de criar uma nova classe de controle de MFC, você pode definir manipuladores de mensagem para ela.  Os manipuladores de mensagem refletidas permitem que a sua classe de controle trata suas próprias mensagens antes que a mensagem foi recebida pelo pai.  Você pode usar a função MFC [CWnd::SendMessage](../Topic/CWnd::SendMessage.md) para enviar mensagens do controle para uma janela pai.  
  
 Com essa funcionalidade você pode, por exemplo, para criar uma caixa de listagem que se redesenhasse em vez de utilizar a janela pai para fazer isso \(proprietário desenhado\).  Para obter mais informações sobre mensagens refletidas, consulte [A manipulação de mensagens refletido](../../mfc/handling-reflected-messages.md).  
  
 Para criar [Controle ActiveX](../../mfc/activex-controls-on-the-internet.md) com a mesma funcionalidade, você deve criar um projeto do controle ActiveX.  
  
> [!NOTE]
>  Você não pode adicionar uma mensagem refletida \(OCM\_*Message*\) para um controle ActiveX usando a janela Propriedades, como descrito abaixo.  Você deve adicionar essas mensagens manualmente.  
  
### Para definir um manipulador de mensagem para uma mensagem refletida na janela Propriedades  
  
1.  Adicionar um controle, como uma lista, um controle de rebar, uma barra de ferramentas, ou um controle de árvore, ao seu projeto MFC.  
  
2.  Na exibição da classe, clique no nome da sua classe do controle.  
  
3.  Em [Janela Propriedades](../Topic/Properties%20Window.md), o nome da classe do controle é exibido na lista de **Nome da classe** .  
  
4.  Clique no botão de **Mensagens** para exibir as mensagens do windows disponíveis para adicionar ao controle.  
  
5.  Percorra a lista de mensagens na janela Propriedades até ver o título **Refletido**.  Como alternativa, clique no botão de **Categorias** e recolher a exibição para ver a direção de **Refletido** .  
  
6.  Selecione a mensagem refletida para o qual você deseja definir um manipulador.  As mensagens são refletidas marcadas com um sinal de igual \(\=\).  
  
7.  Clique na célula na coluna esquerda na janela Propriedades para exibir o nome do manipulador sugerido como \<add\>*HandlerName*. \(Por exemplo, o manipulador de mensagens de **\=WM\_CTLCOLOR** sugere \<adiciona\>**CtlColor**\).  
  
8.  Clique no nome sugerido para aceitar.  O manipulador é adicionado ao seu projeto.  
  
     Os nomes de manipulador de mensagens que você adicionou aparecem na coluna direita da janela refletida de mensagens.  
  
9. Para editar ou excluir um manipulador de mensagens, repita as etapas 4 a 7.  Clique na célula que contém o nome do manipulador para editar ou excluir e clique na tarefa apropriada.  
  
## Consulte também  
 [Mapeando mensagens para funções](../Topic/Mapping%20Messages%20to%20Functions.md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md)   
 [Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)   
 [Substituindo uma função virtual](../Topic/Overriding%20a%20Virtual%20Function%20\(Visual%20C++\).md)   
 [Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)   
 [Navegando na estrutura da classe](../../ide/navigating-the-class-structure-visual-cpp.md)