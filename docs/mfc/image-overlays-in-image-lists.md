---
title: Sobreposições de imagem em listas de imagens | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- overlays [MFC]
- image lists [MFC], image overlays in
- CImageList class [MFC], image overlays in
ms.assetid: aaf4e1c4-cd12-42c8-9af4-1bb458889b4e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 93d37b49a949ab29e0ae888d9c961da086ee4ca4
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36928590"
---
# <a name="image-overlays-in-image-lists"></a>Sobreposições de imagem em listas de imagens
Cada lista de imagens ([CImageList](../mfc/reference/cimagelist-class.md)) inclui uma lista de imagens a serem usadas como máscaras de sobreposição. Uma máscara de sobreposição"" é uma imagem que transparente se desenhada sobre outra imagem. Nenhuma imagem pode ser usada como uma máscara de sobreposição. Você pode especificar até quatro máscaras de sobreposição por lista de imagens.  
  
 Adicionar o índice de uma imagem à lista de máscaras de sobreposição usando o [SetOverlayImage](../mfc/reference/cimagelist-class.md#setoverlayimage) função de membro, o índice de uma imagem e o índice de uma máscara de sobreposição. Observe que os índices para as máscaras de sobreposição são baseados em vez de base zero.  
  
 Desenhar uma máscara de sobreposição em uma imagem usando uma única chamada para `Draw`. Os parâmetros incluem o índice da imagem para desenhar e o índice de uma máscara de sobreposição. Você deve usar o [INDEXTOOVERLAYMASK](http://msdn.microsoft.com/library/windows/desktop/bb761408) macro para especificar o índice da máscara de sobreposição. Você também pode especificar uma imagem de sobreposição ao chamar o [DrawIndirect](../mfc/reference/cimagelist-class.md#drawindirect) função de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CImageList](../mfc/using-cimagelist.md)   
 [Controles](../mfc/controls-mfc.md)

