---
title: "Pain&#233;is Janela (editor de imagens para &#237;cones) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.editors.bitmap"
  - "vc.editors.icon"
dev_langs: 
  - "C++"
  - "C++"
helpviewer_keywords: 
  - "editor gráfico [C++]"
  - "Editor de imagem [C++], painéis"
ms.assetid: d66ea5b3-e2e2-4fc4-aa99-f50022cc690e
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Pain&#233;is Janela (editor de imagens para &#237;cones)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A janela do Editor de imagem normalmente exibe uma imagem em dois painéis separados por uma barra divisória.  Um modo de exibição é o tamanho real e o outro é ampliado \(o fator de ampliação padrão é 6\).  Os modos de exibição esses dois painéis são atualizados automaticamente: as alterações feitas em um painel são mostradas imediatamente na outra.  Os dois painéis facilitam para você trabalhar em uma exibição ampliada de sua imagem, na qual você pode distinguir pixels individuais e, ao mesmo tempo, observar o efeito do seu trabalho no modo de exibição de tamanho real da imagem.  
  
 O painel esquerdo usa como a quantidade de espaço é necessário \(até a metade da janela de imagens\) para exibir o modo de ampliação de 1: 1 \(padrão\) da imagem.  O painel direito exibe a imagem aumentada \(6: 1 ampliação por padrão\).  Você pode  [alterar a ampliação](../mfc/changing-the-magnification-factor-image-editor-for-icons.md) em cada painel usando a  **ampliação** ferramenta na  [barra de ferramentas do Editor de imagens](../mfc/toolbar-image-editor-for-icons.md) ou usando as teclas de aceleração.  
  
 Você pode ampliar o painel menor da janela do Editor de imagens e usar os dois painéis para mostrar diferentes regiões de uma imagem grande.  Clique no painel para selecioná\-lo.  
  
 Você pode alterar os tamanhos relativos dos painéis posicionando o ponteiro na barra de divisão e mover a barra de divisão para a direita ou esquerda.  A barra de divisão pode mover todo o caminho para os dois lados se você desejar trabalhar em apenas um painel.  
  
 Se o painel do editor de imagem é ampliado por um fator de 4 ou superior, você pode  [Exibir uma grade de pixels](../mfc/displaying-or-hiding-the-pixel-grid-image-editor-for-icons.md) que delimita os pixels individuais da imagem.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
## Requisitos  
 Nenhum  
  
## Consulte também  
 [Teclas de aceleração](../mfc/accelerator-keys-image-editor-for-icons.md)   
 [Editor de imagens para ícones](../mfc/image-editor-for-icons.md)