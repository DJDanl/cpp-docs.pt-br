---
title: Sobreposições de imagem em listas de imagens
ms.date: 11/04/2016
helpviewer_keywords:
- overlays [MFC]
- image lists [MFC], image overlays in
- CImageList class [MFC], image overlays in
ms.assetid: aaf4e1c4-cd12-42c8-9af4-1bb458889b4e
ms.openlocfilehash: ec795193a28a68d8aee61e9932481a89c4b3e8e0
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69508381"
---
# <a name="image-overlays-in-image-lists"></a>Sobreposições de imagem em listas de imagens

Cada[CImageList](../mfc/reference/cimagelist-class.md)(lista de imagens) inclui uma lista de imagens a serem usadas como máscaras de sobreposição. Uma "máscara de sobreposição" é uma imagem desenhada de forma transparente sobre outra imagem. Qualquer imagem pode ser usada como uma máscara de sobreposição. Você pode especificar até quatro máscaras de sobreposição por lista de imagens.

Você adiciona o índice de uma imagem à lista de máscaras de sobreposição usando a função membro [SetOverlayImage](../mfc/reference/cimagelist-class.md#setoverlayimage) , o índice de uma imagem e o índice de uma máscara de sobreposição. Observe que os índices das máscaras de sobreposição são baseados em um, em vez de baseados em zero.

Você desenha uma máscara de sobreposição sobre uma imagem usando uma única `Draw`chamada para. Os parâmetros incluem o índice da imagem para desenhar e o índice de uma máscara de sobreposição. Você deve usar a macro [INDEXTOOVERLAYMASK](/windows/win32/api/commctrl/nf-commctrl-indextooverlaymask) para especificar o índice da máscara de sobreposição. Você também pode especificar uma imagem de sobreposição ao chamar a função de membro [DrawIndirect](../mfc/reference/cimagelist-class.md#drawindirect) .

## <a name="see-also"></a>Consulte também

[Usando CImageList](../mfc/using-cimagelist.md)<br/>
[Controles](../mfc/controls-mfc.md)
