---
title: Sobreposições de imagem em listas de imagens
ms.date: 11/04/2016
helpviewer_keywords:
- overlays [MFC]
- image lists [MFC], image overlays in
- CImageList class [MFC], image overlays in
ms.assetid: aaf4e1c4-cd12-42c8-9af4-1bb458889b4e
ms.openlocfilehash: 8dd0b30ef29a48ebc763564e6fe23632cd300831
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57262773"
---
# <a name="image-overlays-in-image-lists"></a>Sobreposições de imagem em listas de imagens

Cada lista de imagens ([CImageList](../mfc/reference/cimagelist-class.md)) inclui uma lista de imagens a serem usadas como máscaras de sobreposição. Uma máscara"sobreposição" é uma imagem desenhada de forma transparente sobre outra imagem. Qualquer imagem pode ser usada como uma máscara de sobreposição. Você pode especificar até quatro máscaras de sobreposição por lista de imagens.

Adicionar o índice de uma imagem à lista de máscaras de sobreposição usando o [SetOverlayImage](../mfc/reference/cimagelist-class.md#setoverlayimage) função de membro, o índice de uma imagem e o índice de uma máscara de sobreposição. Observe que os índices para as máscaras de sobreposição são baseados em um em vez de base zero.

Desenhar uma máscara de sobreposição ao longo de uma imagem usando uma única chamada para `Draw`. Os parâmetros incluem o índice da imagem para desenhar e o índice de uma máscara de sobreposição. Você deve usar o [INDEXTOOVERLAYMASK](/windows/desktop/api/commctrl/nf-commctrl-indextooverlaymask) macro para especificar o índice da máscara de sobreposição. Você também pode especificar uma imagem de sobreposição ao chamar o [DrawIndirect](../mfc/reference/cimagelist-class.md#drawindirect) função de membro.

## <a name="see-also"></a>Consulte também

[Usando CImageList](../mfc/using-cimagelist.md)<br/>
[Controles](../mfc/controls-mfc.md)
