---
title: Assistente de Manipulador de Eventos | Microsoft Docs
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
ms.openlocfilehash: eb3a025c293c3252b52b9ae705e6475b7095f049
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46444075"
---
# <a name="event-handler-wizard"></a>Assistente de Manipulador de Eventos

Este assistente adiciona um manipulador de eventos a um controle de caixa de diálogo para a classe de sua escolha. Se você adicionar um manipulador de eventos por meio da [janela Propriedades](/visualstudio/ide/reference/properties-window), adicione-o somente para a classe que implementa a caixa de diálogo. Confira [Adicionando manipuladores de eventos a controles de caixa de diálogo](../windows/adding-event-handlers-for-dialog-box-controls.md) para obter mais informações.

- **Nome do comando**

   Identifica o controle selecionado, ao qual o manipulador de eventos é adicionado. Essa caixa não fica disponível.

- **Tipo de mensagem**

   Exibe a lista de possíveis manipuladores de mensagens atuais para o controle selecionado.

- **Nome do manipulador de funções**

   Exibe o nome da função que é adicionada para manipular o evento. Por padrão, o nome se baseia no tipo de mensagem e no comando, precedido por "On". Por exemplo, para o botão chamado `IDC_BUTTON1`, o tipo de mensagem `BN_CLICKED` exibe o nome do manipulador de funções `OnBnClickedButton1`.

- **Lista de classes**

   Exibe as classes disponíveis às quais você pode adicionar um manipulador de eventos. A classe para a caixa de diálogo selecionada é exibida em vermelho.

- **Descrição do manipulador**

   Fornece uma descrição para o item selecionado na caixa **Tipo de mensagem**. Essa caixa não fica disponível.

- **Adicionar e editar**

   Adiciona o manipulador de mensagens à classe ou ao objeto selecionado e, em seguida, abre o editor de texto na nova função, de modo que você possa adicionar o código do manipulador de notificações de controle.

- **Editar código**

   Abre o editor de texto na função selecionada, de modo que você possa adicionar ou editar o código do manipulador de notificações de controle.

## <a name="see-also"></a>Consulte também

[Adicionando um manipulador de eventos](../ide/adding-an-event-handler-visual-cpp.md)