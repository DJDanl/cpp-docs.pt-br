---
title: Sobreposições de imagem em listas de imagens
ms.date: 11/04/2016
helpviewer_keywords:
- overlays [MFC]
- image lists [MFC], image overlays in
- CImageList class [MFC], image overlays in
ms.assetid: aaf4e1c4-cd12-42c8-9af4-1bb458889b4e
ms.openlocfilehash: 861bcd5165ad0938ae6bbd77fc4a9f09095ce789
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84624470"
---
# <a name="image-overlays-in-image-lists"></a>Sobreposições de imagem em listas de imagens

Cada[CImageList](reference/cimagelist-class.md)(lista de imagens) inclui uma lista de imagens a serem usadas como máscaras de sobreposição. Uma "máscara de sobreposição" é uma imagem desenhada de forma transparente sobre outra imagem. Qualquer imagem pode ser usada como uma máscara de sobreposição. Você pode especificar até quatro máscaras de sobreposição por lista de imagens.

Você adiciona o índice de uma imagem à lista de máscaras de sobreposição usando a função membro [SetOverlayImage](reference/cimagelist-class.md#setoverlayimage) , o índice de uma imagem e o índice de uma máscara de sobreposição. Observe que os índices das máscaras de sobreposição são baseados em um, em vez de baseados em zero.

Você desenha uma máscara de sobreposição sobre uma imagem usando uma única chamada para `Draw` . Os parâmetros incluem o índice da imagem para desenhar e o índice de uma máscara de sobreposição. Você deve usar a macro [INDEXTOOVERLAYMASK](/windows/win32/api/commctrl/nf-commctrl-indextooverlaymask) para especificar o índice da máscara de sobreposição. Você também pode especificar uma imagem de sobreposição ao chamar a função de membro [DrawIndirect](reference/cimagelist-class.md#drawindirect) .

## <a name="see-also"></a>Consulte também

[Usando CImageList](using-cimagelist.md)<br/>
[Controles](controls-mfc.md)
