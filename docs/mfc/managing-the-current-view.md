---
title: "Gerenciando a exibi&#231;&#227;o atual | Microsoft Docs"
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
  - "exibição atual na janela com moldura"
  - "desativando exibições"
  - "janelas com moldura, exibição atual"
  - "Método OnActivateView"
  - "modos de exibição, ativando"
  - "modos de exibição, e método OnActivateView "
  - "modos de exibição, atual"
  - "modos de exibição, desativando"
ms.assetid: 0a1cc22d-d646-4536-9ad2-3cb6d7092e4a
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Gerenciando a exibi&#231;&#227;o atual
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Como parte da implementação padrão do windows do quadro, uma janela do quadro mantém acompanha de uma exibição atualmente ativo.  Se a janela do quadro contiver mais de uma exibição, como por exemplo em uma janela do divisor, a exibição atual é a exibição mais recente em uso.  A exibição ativa é independente da janela ativa no windows ou no foco de entrada atual.  
  
 Quando a exibição ativa for alterada, a estrutura notifica a exibição atual chamando a função de membro de [OnActivateView](../Topic/CView::OnActivateView.md) .  Você pode saber se a exibição está sendo ativada ou desativada examinando o parâmetro de `OnActivateView``bActivate` .  Por padrão, `OnActivateView` define o foco para a exibição atual da ativação.  Você pode substituir `OnActivateView` para executar qualquer processamento especial quando a exibição é desativada ou reativados.  Por exemplo, você pode fornecer sugestões visuais especiais para distinguir a exibição ativa de outro, exibições inativas.  
  
 Uma janela do quadro encaminha comandos à exibição ativa \(\) atual, conforme descrito em [Roteamento de comando](../mfc/command-routing.md), como parte do roteamento de comando padrão.  
  
## Consulte também  
 [Usando janelas com moldura](../Topic/Using%20Frame%20Windows.md)