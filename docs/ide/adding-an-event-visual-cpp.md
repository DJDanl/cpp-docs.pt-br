---
title: Adicionar um evento
ms.date: 11/12/2018
f1_keywords:
- vc.codewiz.event.overview
helpviewer_keywords:
- ActiveX controls [C++], adding events to
- MFC ActiveX controls [C++], adding events
- events [C++], ActiveX controls
- add event wizard [C++]
ms.assetid: fe34832a-edfc-4f86-aacb-8df77001873d
ms.openlocfilehash: 1d5a8f5666dd04e00f8a438fdbf00320c37e14f4
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51693419"
---
# <a name="add-an-event"></a>Adicionar um evento

Em Modo de Exibição de Classe, usando o [assistente de adição de eventos](#add-event-wizard), adicione um evento somente à classe de controle do projeto [Controle ActiveX do MFC](../mfc/reference/creating-an-mfc-activex-control.md). Caso deseje adicionar um evento a outro tipo de projeto, use o botão **Eventos** na [janela Propriedades](/visualstudio/ide/reference/properties-window).

**Para adicionar um evento ao projeto de controle ActiveX do MFC:**

1. Em Modo de Exibição de Classe, expanda o nó do projeto para exibir as classes no projeto.

1. Clique com o botão direito do mouse na classe de controle do projeto.

1. No menu de atalho, escolha **Adicionar** e, em seguida, escolha **Adicionar Evento** para exibir o Assistente de Adição de Eventos.

1. Forneça as informações de evento nas caixas apropriadas do assistente.

1. Selecione **Concluir** para adicionar o evento ao projeto.

## <a name="in-this-section"></a>Nesta seção

- [Assistente de adição de eventos](#add-event-wizard)

## <a name="add-event-wizard"></a>Assistente de adição de eventos

Este assistente adiciona um evento a um projeto de controle ActiveX do MFC. Especifique seu próprio evento, personalize um evento típico de estoque ou selecione um evento em uma lista de eventos de estoque.

- **Nome do evento**

   Define o nome usado por clientes de Automação para solicitar um evento da classe. Insira um nome ou selecione um na lista.

- **Tipo de evento**

   Indica o tipo de evento a ser adicionado. Disponível somente se você seleciona um evento na lista **Nome do evento**.

   |Opção|Descrição|
   |------------|-----------------|
   |**Estoque**|Especifica que um evento de estoque, como um clique no botão, será implementado para essa classe. Os eventos de estoque são definidos na Biblioteca MFC (Microsoft Foundation Class).|
   |**Personalizado**|Especifica que você está utilizando sua própria implementação do evento.|

- **Nome interno**

   Define o nome da função de membro que envia o evento. Disponível somente para eventos personalizados. O nome baseia-se no **Nome do evento**. Você poderá alterar o nome interno se desejar fornecer outro nome, em vez do **Nome do evento**.

- **Tipo de parâmetro**

   Define o tipo para o **Nome do parâmetro**. Selecione o tipo na lista.

- **Nome do parâmetro**

   Define o nome de um parâmetro a ser passado pelo evento. Depois de digitar o nome, selecione **Adicionar** para adicioná-lo a lista de parâmetros.

   Depois de selecionar **Adicionar**, o nome do parâmetro é exibido em **Lista de parâmetros**.

   > [!NOTE]
   > Se você fornecer um nome de parâmetro e, em seguida, selecionar **Concluir** antes de selecionar **Adicionar**, o parâmetro não será adicionado ao evento. É necessário encontrar o método e inserir o parâmetro manualmente.

- **Adicionar**

   Adiciona o parâmetro especificado em **Nome do parâmetro** e seu tipo a **Lista de parâmetros**. Selecione **Adicionar** para adicionar um parâmetro à lista.

- **Removerr**

   Remove o parâmetro selecionado em **Lista de parâmetros** da lista.

- **Lista de parâmetros**

   Exibe todos os parâmetros e seus tipos atualmente adicionados ao método. Conforme os parâmetros são adicionados, o assistente atualiza a **Lista de parâmetros** para exibir cada parâmetro com seu tipo.
