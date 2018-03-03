---
title: Adicionar Assistente de eventos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.codewiz.event.overview
dev_langs:
- C++
helpviewer_keywords:
- Add Event Wizard [C++]
ms.assetid: bdd2a7bb-13d5-44d7-abc9-e785ba4e05ce
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 62ecbe7dece323ce5e99fbe32b3b936fe3661362
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="add-event-wizard"></a>Assistente de Adição de Eventos
Este assistente adiciona um evento para um projeto de controle ActiveX do MFC. Você pode especificar seus próprios eventos, você pode personalizar um evento normalmente estoque ou você pode selecionar em uma lista de eventos de estoque.  
  
 **Nome do evento**  
 Define o nome usado por clientes de automação para solicitar um evento da classe. Insira um nome ou selecione um na lista.  
  
 **Tipo de evento**  
 Indica o tipo de evento a ser adicionado. Disponível somente se você selecionar o **nome do evento** lista.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Estoque**|Especifica que um evento de estoque, como clicar em um botão, será implementado para esta classe. Eventos de estoque são definidos na biblioteca Microsoft Foundation Class (MFC).|  
|**Personalizado**|Especifica que você está fornecendo sua própria implementação do evento.|  
  
 **Nome interno**  
 Define o nome da função de membro que envia o evento. Disponível apenas para eventos personalizados. O nome é baseado no **nome do evento**. Você pode alterar o nome interno para fornecer um nome diferente de **nome do evento**.  
  
 **Tipo de parâmetro**  
 Define o tipo para o **nome do parâmetro**. Selecione o tipo da lista.  
  
 **Nome do parâmetro**  
 Define o nome de um parâmetro de passagem, o evento. Depois de digitar o nome, você deve clicar em **adicionar** para adicioná-lo a lista de parâmetros.  
  
 Depois de clicar em **adicionar**, o nome do parâmetro aparece no **lista de parâmetros**.  
  
> [!NOTE]
>  Se você fornecer um nome de parâmetro e, em seguida, clique em **concluir** antes de clicar em **adicionar**, o parâmetro não será adicionada ao evento. Você deve localizar o método e inserir o parâmetro manualmente. **Lista de parâmetros**  
  
 **Adicionar**  
 Adiciona o parâmetro que você especificar na **nome do parâmetro**e seu tipo, para **lista de parâmetros**. Você deve clicar em **adicionar** para adicionar um parâmetro à lista.  
  
 **Removerr**  
 Remove o parâmetro selecionado na **lista de parâmetros** da lista.  
  
 **Lista de parâmetros**  
 Exibe todos os parâmetros e seus tipos adicionados no momento para o método. Como adicionar parâmetros, o assistente atualiza **lista de parâmetros** para exibir cada parâmetro com seu tipo.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando um evento](../ide/adding-an-event-visual-cpp.md)