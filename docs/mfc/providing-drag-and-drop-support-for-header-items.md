---
title: "Dando suporte a arrastar e soltar para itens de cabe&#231;alho | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CHeaderCtrl, suporte a operações arrastar e soltar"
  - "notificações HDN_"
  - "Estilo HDS_DRAGDROP"
  - "Itens de cabeçalho em controles de cabeçalho"
ms.assetid: 93a152ec-804f-488f-b260-b3a438d0dc0f
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Dando suporte a arrastar e soltar para itens de cabe&#231;alho
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para fornecer suporte de arrastar e soltar para itens de cabeçalho, especifique o estilo de `HDS_DRAGDROP` .  Suporte de arrastar e soltar para itens do cabeçalho da ao usuário a capacidade de reorganizar itens de cabeçalho de um controle de cabeçalho.  O comportamento padrão fornece uma imagem semitransparent de arrastamento do item de cabeçalho que estão sendo arrastados e um indicador visual da nova posição, se o item do cabeçalho é removido.  
  
 Como a funcionalidade comum de arrastar e soltar, você pode estender o comportamento padrão de arrastar e soltar para controlar as notificações de **HDN\_BEGINDRAG** e de **HDN\_ENDDRAG** .  Você também pode personalizar a aparência da imagem de arrastamento substituindo a função de membro de [CHeaderCtrl::CreateDragImage](../Topic/CHeaderCtrl::CreateDragImage.md) .  
  
> [!NOTE]
>  Se você estiver fornecendo suporte de arrastar e soltar para um controle de cabeçalho inserido em um controle de lista, consulte a seção estendido de estilo no tópico de [Alterando os estilos de controle de lista](../Topic/Changing%20List%20Control%20Styles.md) .  
  
## Consulte também  
 [Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)