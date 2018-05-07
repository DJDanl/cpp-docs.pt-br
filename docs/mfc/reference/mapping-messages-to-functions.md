---
title: Mapeando mensagens para funções | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.codewiz.mapping.msg.function
dev_langs:
- C++
helpviewer_keywords:
- Windows messages [MFC], adding message handlers
- message maps [MFC], mapping messages to functions
ms.assetid: a7727a62-f638-4b20-b7f5-131f47200d6a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3388cd8e9a52ef9aacb427d66b027d793b08ca75
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="mapping-messages-to-functions"></a>Mapeando mensagens para funções
A janela Propriedades permite vincular manipuladores de mensagens (funções de membro de classes de interface do usuário do MFC) para as mensagens geradas por recursos de seu aplicativo. Eles usam [mapas de mensagem MFC](../../mfc/messages-and-commands-in-the-framework.md) para criar uma associação.  
  
 Quando você usar o modo de exibição de classe para criar uma nova classe derivada de uma das classes do framework, ele automaticamente coloca um completos e funcionais arquivos de classe no cabeçalho (. h) e implementação (. cpp) que você especificar.  
  
> [!NOTE]
>  Para adicionar uma nova classe que não processa mensagens, crie a classe diretamente no editor de texto.  
  
### <a name="to-define-or-remove-a-message-handler-using-the-properties-window"></a>Para definir ou remover um manipulador de mensagens usando a janela Propriedades  
  
1.  No modo de exibição de classe, clique na classe.  
  
2.  Na janela Propriedades, clique o **mensagens** botão.  
  
    > [!NOTE]
    >  O **mensagens** botão está disponível quando você seleciona o nome de classe no modo de exibição de classe ou quando você clica dentro da janela de origem.  
  
     Se o projeto tiver um manipulador para uma mensagem, o nome do manipulador de aparece na coluna à direita, próximo à mensagem.  
  
3.  Se a mensagem não tem um manipulador, em seguida, clique na célula na coluna à direita na janela Propriedades para exibir o nome sugerido do manipulador como \<Adicionar >*HandlerName*. (Por exemplo, o `WM_TIMER` sugere o manipulador de mensagens \<Adicionar >`OnTimer`).  
  
4.  Clique no nome sugerido para adicionar código de stub para a função.  
  
5.  Para editar um manipulador de mensagens, clique duas vezes em mensagem na exibição de classe e editar o código na janela de origem.  
  
 Para remover um manipulador de mensagens, clique duas vezes o manipulador na coluna à direita e selecione \<excluir >*HandlerName*. Código da função será comentado.  
  
## <a name="see-also"></a>Consulte também  
 [Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)   
 [Adicionar uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionar uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)   
 [Substituindo uma função Virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)   
 [Adicionando manipuladores de eventos para controles de caixa de diálogo](../../windows/adding-event-handlers-for-dialog-box-controls.md)   
 [Navegando na estrutura de classe](../../ide/navigating-the-class-structure-visual-cpp.md)
