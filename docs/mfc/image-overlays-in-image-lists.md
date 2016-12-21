---
title: "Sobreposi&#231;&#245;es de imagem em listas de imagens | Microsoft Docs"
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
  - "Classe CImageList, sobreposições de imagens em"
  - "listas de imagens [C++], sobreposições de imagens em"
  - "sobreposições"
ms.assetid: aaf4e1c4-cd12-42c8-9af4-1bb458889b4e
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Sobreposi&#231;&#245;es de imagem em listas de imagens
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cada lista de imagem \([CImageList](../Topic/CImageList%20Class.md)\) inclui uma lista de imagens a serem usadas como máscaras de sobreposição.  “Uma sobreposição de máscara” é uma imagem desenhada transparente em outra imagem.  Qualquer imagem pode ser usada como uma máscara de sobreposição.  Você pode especificar até quatro máscaras cobertas pela lista da imagem.  
  
 Você adiciona o índice de uma imagem à lista de máscaras de sobreposição usando a função de membro de [SetOverlayImage](../Topic/CImageList::SetOverlayImage.md) , o índice de uma imagem, e o índice de uma máscara de sobreposição.  Observe que os índices das máscaras de sobreposição é baseado em um em vez de base zero.  
  
 Você desenha uma máscara de sobreposição sobre uma imagem usando uma única chamada para **Desenhar**.  Os parâmetros incluindo o índice de imagem para desenhar e o índice de uma máscara de sobreposição.  Você deve usar a macro de [INDEXTOOVERLAYMASK](http://msdn.microsoft.com/library/windows/desktop/bb761408) para especificar o índice da máscara de sobreposição.  Você também pode especificar uma imagem de sobreposição ao chamar a função de membro de [DrawIndirect](../Topic/CImageList::DrawIndirect.md) .  
  
## Consulte também  
 [Usando CImageList](../mfc/using-cimagelist.md)   
 [Controles](../mfc/controls-mfc.md)