---
title: "Assistente de Adi&#231;&#227;o de Eventos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.codewiz.event.overview"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de Adição de Eventos [C++]"
ms.assetid: bdd2a7bb-13d5-44d7-abc9-e785ba4e05ce
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente de Adi&#231;&#227;o de Eventos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este assistente adiciona um evento para um projeto de controle de ActiveX do MFC.  Você pode especificar seus próprios eventos, você pode personalizar um evento normalmente ações ou você pode selecionar uma lista de eventos de ações.  
  
 **Nome do evento**  
 Define o nome usado por clientes de automação para solicitar um evento da classe.  Digite um nome ou selecione um na lista.  
  
 **Tipo de evento**  
 Indica o tipo de evento a ser adicionado.  Disponível somente se você selecionar a partir de  **Nome do evento** lista.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**Estoque**|Especifica que um evento de ações, como, por exemplo, clicar em um botão, será implementado para esta classe.  Eventos de ações são definidos na biblioteca Microsoft Foundation Class \(MFC\).|  
|**Personalizado**|Especifica que você está fornecendo sua própria implementação do evento.|  
  
 **Nome interno**  
 Define o nome da função de membro que envia o evento.  Disponível somente para eventos personalizados.  O nome é baseado no  **nome do evento**.  Você pode alterar o nome interno, se você desejar fornecer um nome diferente de  **nome do evento**.  
  
 **Tipo de parâmetro**  
 Define o tipo para o  **o nome do parâmetro**.  Selecione o tipo da lista.  
  
 **Nome do parâmetro**  
 Define o nome de um parâmetro para passar por seu evento.  Depois de digitar o nome, você deve clicar em  **Add** para adicioná\-lo a lista de parâmetros.  
  
 Depois de clicar em  **Add**, o nome do parâmetro aparece no  **lista de parâmetros**.  
  
> [!NOTE]
>  Se você fornecer um nome de parâmetro e, em seguida, clique em  **Concluir** antes de clicar em  **Add**, o parâmetro não será adicionada ao evento.  Você deve encontrar o método e inserir o parâmetro manualmente. **Lista de parâmetros**  
  
 **Add**  
 Adiciona o parâmetro especificado em  **o nome do parâmetro**e seu tipo, para  **lista de parâmetros**.  Você deve clicar em  **Add** para adicionar um parâmetro à lista.  
  
 **Remove**  
 Remove o parâmetro que você seleciona na  **lista de parâmetros** da lista.  
  
 **Lista de parâmetros**  
 Exibe todos os parâmetros e seus tipos atualmente adicionados para o método.  Conforme você adiciona parâmetros, o assistente atualiza  **lista de parâmetros** para exibir cada parâmetro com o seu tipo.  
  
## Consulte também  
 [Adicionando um evento](../Topic/Adding%20an%20Event%20\(Visual%20C++\).md)