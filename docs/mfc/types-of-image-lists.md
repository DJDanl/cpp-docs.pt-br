---
title: Tipos de listas de imagens | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- lists [MFC], image
- image lists [MFC], types of
- CImageList class [MFC], types
ms.assetid: bee5e7c3-78f5-4037-a136-9c50d67cdee5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8988dc55bbbaa1d446ee14bf78a0cd799b422834
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="types-of-image-lists"></a>Tipos de listas de imagens
Há dois tipos de listas de imagens ([CImageList](../mfc/reference/cimagelist-class.md)): nonmasked e mascarada. Uma "lista de imagens nonmasked" consiste em um bitmap de cor que contém uma ou mais imagens. Uma "lista de imagens mascaradas" consiste em dois bitmaps de tamanhos iguais. A primeira é um bitmap de cor que contém as imagens e o segundo é um bitmap monocromático que contém uma série de máscaras — um para cada imagem de bitmap primeiro.  
  
 Uma das sobrecargas do **criar** função de membro usa um sinalizador para indicar se a lista de imagens é mascarada. (Outras sobrecargas criar listas de imagens mascaradas.)  
  
 Quando uma imagem nonmasked é desenhada, ele simplesmente é copiado para o contexto de dispositivo de destino; ou seja, ela é desenhada sobre a cor de plano de fundo existente do contexto do dispositivo. Quando uma imagem mascarada é desenhada, os bits da imagem são combinados com os bits da máscara, produzindo normalmente áreas transparentes no bitmap onde a cor de plano de fundo do contexto do dispositivo de destino mostra por meio de. Você pode especificar vários estilos de desenho ao desenhar uma imagem mascarada. Por exemplo, você pode especificar que a imagem ser pontilhada para indicar que um objeto selecionado.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CImageList](../mfc/using-cimagelist.md)   
 [Controles](../mfc/controls-mfc.md)

