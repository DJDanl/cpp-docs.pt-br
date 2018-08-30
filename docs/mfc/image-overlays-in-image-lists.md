---
title: Sobreposições de imagem em listas de imagem | Microsoft Docs
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
ms.openlocfilehash: 4369fe312669f75eb8217be7a6a09c4287f7cc8b
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43210707"
---
# <a name="image-overlays-in-image-lists"></a>Sobreposições de imagem em listas de imagens
Cada lista de imagens ([CImageList](../mfc/reference/cimagelist-class.md)) inclui uma lista de imagens a serem usadas como máscaras de sobreposição. Uma máscara"sobreposição" é uma imagem desenhada de forma transparente sobre outra imagem. Qualquer imagem pode ser usada como uma máscara de sobreposição. Você pode especificar até quatro máscaras de sobreposição por lista de imagens.  
  
 Adicionar o índice de uma imagem à lista de máscaras de sobreposição usando o [SetOverlayImage](../mfc/reference/cimagelist-class.md#setoverlayimage) função de membro, o índice de uma imagem e o índice de uma máscara de sobreposição. Observe que os índices para as máscaras de sobreposição são baseados em um em vez de base zero.  
  
 Desenhar uma máscara de sobreposição ao longo de uma imagem usando uma única chamada para `Draw`. Os parâmetros incluem o índice da imagem para desenhar e o índice de uma máscara de sobreposição. Você deve usar o [INDEXTOOVERLAYMASK](/windows/desktop/api/commctrl/nf-commctrl-indextooverlaymask) macro para especificar o índice da máscara de sobreposição. Você também pode especificar uma imagem de sobreposição ao chamar o [DrawIndirect](../mfc/reference/cimagelist-class.md#drawindirect) função de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CImageList](../mfc/using-cimagelist.md)   
 [Controles](../mfc/controls-mfc.md)

