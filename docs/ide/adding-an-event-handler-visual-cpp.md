---
title: Adicionar um manipulador de eventos
ms.date: 11/12/2018
f1_keywords:
- vc.codewiz.eventhandler.overview
- vc.codewiz.eventhandler.overview
helpviewer_keywords:
- event handlers, adding
- properties [Visual Studio], MSBuild
- MSBuild, properties
- event handler wizard [C++]
ms.assetid: 050bebf0-a9e0-474b-905c-796fe5ac8fc3
ms.openlocfilehash: 96e5b8777bb8b0c976277a06e8ad49b3334921fb
ms.sourcegitcommit: c1f646c8b72f330fa8cf5ddb0f8f261ba10d16f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2019
ms.locfileid: "58328565"
---
# <a name="add-an-event-handler"></a>Adicionar um manipulador de eventos

No editor de recursos, você poderá adicionar um novo manipulador de eventos a um controle de caixa de diálogo ou editar um manipulador de eventos existente usando o [assistente de manipulador de eventos](#event-handler-wizard).

Adicione um evento à classe que implementa a caixa de diálogo usando a [janela Propriedades](/visualstudio/ide/reference/properties-window). Para adicionar o evento a uma classe que não seja a classe de caixa de diálogo, use o assistente de manipulador de eventos.

**Para adicionar um manipulador de eventos a um controle de caixa de diálogo:**

1. Clique duas vezes no recurso de caixa de diálogo no [Modo de Exibição de Recursos](../windows/how-to-create-a-resource-script-file.md#create-resources) para abrir o recurso de caixa de diálogo que contém o controle no [editor de caixas de diálogo](../windows/dialog-editor.md).

1. Clique com o botão direito do mouse no controle para o qual deseja manipular o evento de notificação.

1. No menu de atalho, escolha **Adicionar Manipulador de Eventos** para exibir o Assistente de Manipulador de Eventos.

1. Selecione o evento na caixa **Tipo de mensagem** para adicionar à classe selecionada na caixa **Lista de classes**.

1. Aceite o nome padrão da caixa **Nome do manipulador de funções** ou forneça o nome de sua escolha.

1. Selecione **Adicionar e editar** para adicionar o manipulador de eventos ao projeto e abra o editor de texto na nova função para adicionar o código do manipulador de eventos apropriado.

   Se o tipo de mensagem selecionado já tem um manipulador de eventos para a classe selecionada, a opção **Adicionar e editar** não fica disponível e a opção **Editar código** fica disponível. Selecione **Editar código** para abrir o editor de texto na função existente.

Como alternativa, você pode adicionar manipuladores de eventos por meio da [janela Propriedades](/visualstudio/ide/reference/properties-window). Para obter mais informações, confira [Adicionando manipuladores de eventos a controles de caixa de diálogo](../windows/adding-event-handlers-for-dialog-box-controls.md).

## <a name="in-this-section"></a>Nesta seção

- [Assistente de manipulador de eventos](#event-handler-wizard)

## <a name="event-handler-wizard"></a>Assistente de manipulador de eventos

Este assistente adiciona um manipulador de eventos a um controle de caixa de diálogo para a classe de sua escolha. Se você adicionar um manipulador de eventos por meio da [janela Propriedades](/visualstudio/ide/reference/properties-window), adicione-o somente para a classe que implementa a caixa de diálogo. Para obter mais informações, confira [Adicionando manipuladores de eventos a controles de caixa de diálogo](../windows/adding-event-handlers-for-dialog-box-controls.md).

- **Nome do comando**

  Identifica o controle selecionado, ao qual o manipulador de eventos é adicionado. Essa caixa não fica disponível.

- **Tipo de mensagem**

  Exibe a lista de possíveis manipuladores de mensagens atuais para o controle selecionado.

- **Nome do manipulador de funções**

  Exibe o nome da função adicionada para manipular o evento. Por padrão, o nome se baseia no tipo de mensagem e no comando, precedido por `On`. Por exemplo, para o botão chamado `IDC_BUTTON1`, o tipo de mensagem `BN_CLICKED` exibe o nome do manipulador de funções `OnBnClickedButton1`.

- **Lista de classes**

  Exibe as classes disponíveis às quais você pode adicionar um manipulador de eventos. A classe para a caixa de diálogo selecionada é exibida em vermelho.

- **Descrição do manipulador**

  Fornece uma descrição para o item selecionado na caixa **Tipo de mensagem**. Essa caixa não fica disponível.

- **Adicionar e editar**

  Adiciona o manipulador de mensagens à classe ou objeto selecionado. Também abre o editor de texto na nova função de modo que você possa adicionar ou editar o código do manipulador para a notificação de controle.

- **Editar código**

  Abre o editor de texto na função selecionada, de modo que você possa adicionar ou editar o código do manipulador de notificações de controle.
