---
title: "Mapeando mensagens para funções | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.codewiz.mapping.msg.function
dev_langs:
- C++
helpviewer_keywords:
- Windows messages [C++], adding message handlers
- message maps [C++], mapping messages to functions
ms.assetid: a7727a62-f638-4b20-b7f5-131f47200d6a
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 4fafe461008e3545243d693e0d9e34acd57163e0
ms.openlocfilehash: 584cc8b1f59f94d88718add5c21046c487b8556f
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="mapping-messages-to-functions"></a>Mapeando mensagens para funções
A janela de propriedades permite que você vincule manipuladores de mensagens (funções de membro de classes de interface do usuário do MFC) as mensagens geradas por recursos de seu aplicativo. Eles usam [mapas de mensagem MFC](../../mfc/messages-and-commands-in-the-framework.md) para criar a associação.  
  
 Quando você usa o modo de exibição de classe para criar uma nova classe derivada de uma das classes do framework, ele automaticamente coloca um completo e funcional arquivos de classe no cabeçalho (. h) e implementação (. cpp) que você especificar.  
  
> [!NOTE]
>  Para adicionar uma nova classe que não processa mensagens, crie a classe diretamente no editor de texto.  
  
### <a name="to-define-or-remove-a-message-handler-using-the-properties-window"></a>Para definir ou remover um manipulador de mensagens usando a janela Propriedades  
  
1.  No modo de exibição de classe, clique na classe.  
  
2.  Na janela Propriedades, clique o **mensagens** botão.  
  
    > [!NOTE]
    >  O **mensagens** botão está disponível quando você seleciona o nome de classe no modo de exibição de classe ou quando você clica dentro da janela de origem.  
  
     Se o projeto tiver um manipulador para uma mensagem, o nome do manipulador é exibido na coluna à direita ao lado da mensagem.  
  
3.  Se a mensagem não tiver nenhum manipulador, em seguida, clique na célula na coluna à direita na janela Propriedades para exibir o nome do manipulador como sugerido \<adicionar >*HandlerName*. (Por exemplo, o `WM_TIMER` sugere do manipulador de mensagens \<adicionar >`OnTimer`).  
  
4.  Clique no nome sugerido para adicionar código de stub para a função.  
  
5.  Para editar um manipulador de mensagens, clique duas vezes a mensagem no modo de exibição de classe e editar o código na janela de origem.  
  
 Para remover um manipulador de mensagens, clique duas vezes o manipulador na coluna à direita e selecione \<excluir >*HandlerName*. Código da função é comentado.  
  
## <a name="see-also"></a>Consulte também  
 [Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)   
 [Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)   
 [Substituindo uma função Virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)   
 [Adicionando manipuladores de eventos para controles de caixa de diálogo](../../windows/adding-event-handlers-for-dialog-box-controls.md)   
 [Navegando na estrutura da classe](../../ide/navigating-the-class-structure-visual-cpp.md)

