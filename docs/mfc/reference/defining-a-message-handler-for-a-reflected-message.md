---
title: Definindo um manipulador de mensagens para uma mensagem refletida | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.codewiz.defining.msg.msghandler
dev_langs:
- C++
helpviewer_keywords:
- messages, reflected
- message handling, reflected messages
ms.assetid: 5a403528-58c5-46e7-90d5-4a77f0ab9b9c
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 0033c75d351aa201a0c18e81395d764b9d45761b
ms.lasthandoff: 02/25/2017

---
# <a name="defining-a-message-handler-for-a-reflected-message"></a>Definindo um manipulador de mensagens para uma mensagem refletida
Depois de criar uma nova classe de controle MFC, você pode definir manipuladores de mensagens para ele. Manipuladores de mensagens refletidas permitem que sua classe de controle lidar com suas próprias mensagens antes que a mensagem é recebida pelo pai. Você pode usar o MFC [CWnd::SendMessage](../../mfc/reference/cwnd-class.md#sendmessage) função para enviar mensagens de controle para uma janela pai.  
  
 Com essa funcionalidade, por exemplo, você poderia criar uma caixa de listagem que será redesenhado em vez de contar com a janela pai para fazer assim (desenhados pelo proprietário). Para obter mais informações sobre mensagens refletidas, consulte [Manipulando mensagens refletidas](../../mfc/handling-reflected-messages.md).  
  
 Para criar um [controle ActiveX](../../mfc/activex-controls-on-the-internet.md) com a mesma funcionalidade, você deve criar um projeto para o controle ActiveX.  
  
> [!NOTE]
>  Não é possível adicionar uma mensagem refletida (OCM _*mensagem*) para um controle ActiveX controle usando a janela Propriedades, conforme descrito abaixo. Você deve adicionar essas mensagens manualmente.  
  
### <a name="to-define-a-message-handler-for-a-reflected-message-from-the-properties-window"></a>Para definir um manipulador de mensagens para uma mensagem refletida na janela de propriedades  
  
1.  Adicione um controle, como uma lista, um controle rebar, uma barra de ferramentas ou um controle de árvore, a seu projeto.  
  
2.  No modo de exibição de classe, clique no nome da sua classe de controle.  
  
3.  No [janela propriedades](/visualstudio/ide/reference/properties-window), o nome da classe de controle aparece no **nome da classe** lista.  
  
4.  Clique o **mensagens** botão para exibir as mensagens do Windows disponíveis para adicionar ao controle.  
  
5.  Percorra a lista de mensagens na janela de propriedades até ver o título **refletido**. Como alternativa, clique o **categorias** botão e recolher a exibição para ver o **refletido** título.  
  
6.  Selecione a mensagem refletida para a qual você deseja definir um manipulador. Mensagens refletidas são marcadas com um sinal de igual (=).  
  
7.  Clique na célula na coluna à direita na janela Propriedades para exibir o nome do manipulador como sugerido \<adicionar >*HandlerName*. (Por exemplo, o **= WM_CTLCOLOR** sugere do manipulador de mensagens \<adicionar >**CtlColor**).  
  
8.  Clique no nome sugerido para aceitar. O manipulador é adicionado ao seu projeto.  
  
     Nomes de manipuladores de mensagens que você adicionou aparecem na coluna à direita da janela de mensagens refletidas.  
  
9. Para editar ou excluir um manipulador de mensagens, repita as etapas 4 a 7. Clique na célula que contém o nome do manipulador para editar ou excluir e clique na tarefa apropriada.  
  
## <a name="see-also"></a>Consulte também  
 [Mapeando mensagens para funções](../../mfc/reference/mapping-messages-to-functions.md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)   
 [Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)   
 [Substituindo uma função Virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)   
 [Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)   
 [Navegando na estrutura da classe](../../ide/navigating-the-class-structure-visual-cpp.md)

