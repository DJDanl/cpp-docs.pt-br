---
title: Assistente de Adição de Evento | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.codewiz.event.overview
dev_langs:
- C++
helpviewer_keywords:
- Add Event Wizard [C++]
ms.assetid: bdd2a7bb-13d5-44d7-abc9-e785ba4e05ce
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f83ff02329a373e6ba65315cf33f7cb21145eb48
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46402662"
---
# <a name="add-event-wizard"></a>Assistente de Adição de Eventos

Este assistente adiciona um evento a um projeto de controle ActiveX do MFC. Especifique seu próprio evento, personalize um evento tipicamente de estoque ou selecione um evento em uma lista de eventos de estoque.

- **Nome do evento**

   Define o nome usado por clientes de Automação para solicitar um evento da classe. Insira um nome ou selecione um na lista.

- **Tipo de evento**

   Indica o tipo de evento a ser adicionado. Disponível somente se você seleciona um evento na lista **Nome do Evento**.

   |Opção|Descrição|
   |------------|-----------------|
   |**Estoque**|Especifica que um evento de estoque, como um clique no botão, será implementado para essa classe. Os eventos de estoque são definidos na Biblioteca MFC (Microsoft Foundation Class).|
   |**Personalizado**|Especifica que você está fornecendo sua própria implementação do evento.|

- **Nome interno**

   Define o nome da função de membro que envia o evento. Disponível somente para eventos personalizados. O nome baseia-se no **Nome do evento**. Você poderá alterar o nome interno se desejar fornecer outro nome, em vez do **Nome do evento**.

- **Tipo de parâmetro**

   Define o tipo para o **Nome do parâmetro**. Selecione o tipo na lista.

- **Nome do parâmetro**

   Define o nome de um parâmetro a ser passado pelo evento. Depois de digitar o nome, clique em **Adicionar** para adicioná-lo a lista de parâmetros.

   Depois de clicar em **Adicionar**, o nome do parâmetro é exibido em **Lista de parâmetros**.

   > [!NOTE]
   > Se você fornecer um nome de parâmetro e, em seguida, clicar em **Concluir** antes de clicar em **Adicionar**, o parâmetro não será adicionado ao evento. É necessário encontrar o método e inserir o parâmetro manualmente. **Lista de parâmetros**

- **Adicionar**

   Adiciona o parâmetro especificado em **Nome do parâmetro** e seu tipo a **Lista de parâmetros**. Clique em **Adicionar** para adicionar um parâmetro à lista.

- **Removerr**

   Remove o parâmetro selecionado em **Lista de parâmetros** da lista.

- **Lista de parâmetros**

   Exibe todos os parâmetros e seus tipos atualmente adicionados ao método. Conforme os parâmetros são adicionados, o assistente atualiza a **Lista de parâmetros** para exibir cada parâmetro com seu tipo.

## <a name="see-also"></a>Consulte também

[Adicionando um evento](../ide/adding-an-event-visual-cpp.md)