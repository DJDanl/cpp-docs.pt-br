---
title: "Informa&#231;&#245;es da imagem em listas de imagens | Microsoft Docs"
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
  - "Classe CImageList, informações de imagem em"
  - "listas de imagens [C++], informações de imagem em"
ms.assetid: 73c41543-fa91-405d-b15b-0feffa6a72c1
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Informa&#231;&#245;es da imagem em listas de imagens
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

[CImageList](../Topic/CImageList%20Class.md) inclui várias funções que recuperam informações de uma lista de imagem.  A função de membro de [GetImageInfo](../Topic/CImageList::GetImageInfo.md) preenche uma estrutura de `IMAGEINFO` com informações sobre uma única imagem, incluindo identificadores dos bitmaps de imagem e de máscara, o número de planos e de bit de cor por pixels, e o retângulo delimitador da imagem no bitmap da imagem.  Você pode usar essas informações para manipular diretamente os bitmaps para a imagem.  
  
 A função de membro de [GetImageCount](../Topic/CImageList::GetImageCount.md) recupera o número de imagens em uma lista de imagem.  
  
 Você pode criar um ícone com base em uma imagem e uma máscara em uma lista de imagem usando a função de membro de [ExtractIcon](../Topic/CImageList::ExtractIcon.md) .  A função retorna o identificador do novo ícone.  
  
## Consulte também  
 [Usando CImageList](../mfc/using-cimagelist.md)   
 [Controles](../mfc/controls-mfc.md)