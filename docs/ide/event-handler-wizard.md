---
title: Assistente de manipulador de eventos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.codewiz.eventhandler.overview
dev_langs:
- C++
helpviewer_keywords:
- Event Handler Wizard [C++]
ms.assetid: af8e1835-94b1-4d9a-b353-c519e011d3a1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 544ce4cd0f4ed9a7f3592e5ec1691fb3734b8772
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="event-handler-wizard"></a>Assistente de Manipulador de Eventos
Este assistente adiciona um manipulador de eventos para um controle de caixa de diálogo para a classe de sua escolha. Se você adicionar um manipulador de eventos do [janela propriedades](/visualstudio/ide/reference/properties-window), você pode adicioná-lo somente para a classe que implementa a caixa de diálogo. Consulte [adicionar manipuladores de eventos para controles de caixa de diálogo](../windows/adding-event-handlers-for-dialog-box-controls.md) para obter mais informações.  
  
 **Nome de comando**  
 Identifica o controle selecionado, para o qual o manipulador de eventos é adicionado. Essa caixa fica indisponível.  
  
 **Tipo de mensagem**  
 Exibe a lista de manipuladores de mensagens de possíveis atual para o controle selecionado.  
  
 **Nome do manipulador de função**  
 Exibe o nome da função que é adicionado para manipular o evento. Por padrão, o nome é baseado no tipo de mensagem e o comando, precedida por "On". Por exemplo, para o botão chamado `IDC_BUTTON1`, o tipo de mensagem `BN_CLICKED` exibe o nome do manipulador de função `OnBnClickedButton1`.  
  
 **Lista de classes**  
 Exibe as classes disponíveis para o qual você pode adicionar um manipulador de eventos. A classe de caixa de diálogo é exibida em vermelho.  
  
 **Descrição de manipulador**  
 Fornece uma descrição para o item selecionado no **tipo de mensagem** caixa. Essa caixa fica indisponível.  
  
 **Adicionar e editar**  
 Adiciona o manipulador de mensagens para a classe selecionada ou o objeto e, em seguida, abre o editor de texto para a nova função para que você possa adicionar o código de manipulador de notificações de controle.  
  
 **Editar código**  
 Abre o editor de texto para a função selecionada para que você pode adicionar ou editar o código de manipulador de notificações de controle.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando um manipulador de eventos](../ide/adding-an-event-handler-visual-cpp.md)