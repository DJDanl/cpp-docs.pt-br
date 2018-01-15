---
title: "Informações de imagem em listas de imagens | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- CImageList class [MFC], image information in
- image lists [MFC], image information in
ms.assetid: 73c41543-fa91-405d-b15b-0feffa6a72c1
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 33248c1bbc225d8d1ccf55c126d1657d0b0e4cad
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="image-information-in-image-lists"></a>Informações da imagem em listas de imagens
[CImageList](../mfc/reference/cimagelist-class.md) inclui um número de funções que recuperam informações de uma lista de imagens. O [GetImageInfo](../mfc/reference/cimagelist-class.md#getimageinfo) membro função preenche uma `IMAGEINFO` estrutura com informações sobre uma única imagem, incluindo os identificadores dos bitmaps de imagem e máscara, o número de planos de cores e bits por pixel e o retângulo delimitador da imagem dentro do bitmap de imagem. Você pode usar essas informações para manipular diretamente os bitmaps para a imagem.  
  
 O [GetImageCount](../mfc/reference/cimagelist-class.md#getimagecount) membro função recupera o número de imagens em uma lista de imagens.  
  
 Você pode criar um ícone com base em uma imagem e uma máscara em uma lista de imagens usando o [ExtractIcon](../mfc/reference/cimagelist-class.md#extracticon) função de membro. A função retorna o identificador do ícone de novo.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CImageList](../mfc/using-cimagelist.md)   
 [Controles](../mfc/controls-mfc.md)

