---
title: Definir um manipulador de mensagens para uma mensagem refletida | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.codewiz.defining.msg.msghandler
dev_langs:
- C++
helpviewer_keywords:
- messages [MFC], reflected
- message handling [MFC], reflected messages
ms.assetid: 5a403528-58c5-46e7-90d5-4a77f0ab9b9c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3ed941816824c77f14a3364b06af0b3da171ee8f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="defining-a-message-handler-for-a-reflected-message"></a>Definindo um manipulador de mensagens para uma mensagem refletida
Depois de criar uma nova classe de controle MFC, você pode definir manipuladores de mensagens para ela. Manipuladores de mensagens refletidas permitem que a sua classe de controle lidar com suas próprias mensagens antes da mensagem é recebida pelo pai. Você pode usar o MFC [CWnd::SendMessage](../../mfc/reference/cwnd-class.md#sendmessage) função para enviar mensagens de seu controle a uma janela pai.  
  
 Com essa funcionalidade, por exemplo, você poderia criar uma caixa de listagem que irá redesenhado em vez de confiar na janela pai para fazer assim (desenhados pelo proprietário). Para obter mais informações sobre mensagens refletidas, consulte [Manipulando mensagens refletidas](../../mfc/handling-reflected-messages.md).  
  
 Para criar um [controle ActiveX](../../mfc/activex-controls-on-the-internet.md) com a mesma funcionalidade, você deve criar um projeto para o controle ActiveX.  
  
> [!NOTE]
>  Não é possível adicionar uma mensagem refletida (OCM _*mensagem*) para um controle ActiveX controle usando a janela Propriedades, conforme descrito abaixo. Você deve adicionar manualmente essas mensagens.  
  
### <a name="to-define-a-message-handler-for-a-reflected-message-from-the-properties-window"></a>Para definir um manipulador de mensagens para uma mensagem refletida na janela de propriedades  
  
1.  Adicione um controle, como uma lista, um controle rebar, uma barra de ferramentas ou um controle de árvore, a seu projeto.  
  
2.  No modo de exibição de classe, clique no nome da classe do controle.  
  
3.  No [janela propriedades](/visualstudio/ide/reference/properties-window), o nome de classe de controle aparece no **nome da classe** lista.  
  
4.  Clique o **mensagens** botão para exibir as mensagens do Windows disponíveis para adicionar ao controle.  
  
5.  Role para baixo a lista de mensagens na janela Propriedades, até que você veja o título **refletido**. Como alternativa, clique o **categorias** botão e reduzir a exibição para ver o **refletido** título.  
  
6.  Selecione a mensagem refletida para o qual você deseja definir um manipulador. Mensagens refletidas são marcadas com um sinal de igual (=).  
  
7.  Clique na célula na coluna à direita na janela Propriedades para exibir o nome sugerido do manipulador como \<Adicionar >*HandlerName*. (Por exemplo, o **= WM_CTLCOLOR** sugere o manipulador de mensagens \<Adicionar >**CtlColor**).  
  
8.  Clique no nome sugerido para aceitar. O manipulador é adicionado ao seu projeto.  
  
     Nomes de manipulador de mensagem que você adicionou aparecem na coluna à direita da janela de mensagens refletidas.  
  
9. Para editar ou excluir um manipulador de mensagens, repita as etapas 4 a 7. Clique na célula que contém o nome do manipulador para editar ou excluir e clique na tarefa apropriada.  
  
## <a name="see-also"></a>Consulte também  
 [Mapeando mensagens para funções](../../mfc/reference/mapping-messages-to-functions.md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)   
 [Adicionar uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionar uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)   
 [Substituindo uma função Virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)   
 [Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)   
 [Navegando na estrutura de classe](../../ide/navigating-the-class-structure-visual-cpp.md)
