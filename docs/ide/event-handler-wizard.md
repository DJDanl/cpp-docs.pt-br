---
title: Assistente de manipulador de eventos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.codewiz.eventhandler.overview
dev_langs:
- C++
helpviewer_keywords:
- Event Handler Wizard [C++]
ms.assetid: af8e1835-94b1-4d9a-b353-c519e011d3a1
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3ccb80add8a98b9251a7ccbb5c85bf98b610a22e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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