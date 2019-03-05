---
title: Tipos de listas de imagens
ms.date: 11/04/2016
helpviewer_keywords:
- lists [MFC], image
- image lists [MFC], types of
- CImageList class [MFC], types
ms.assetid: bee5e7c3-78f5-4037-a136-9c50d67cdee5
ms.openlocfilehash: 939aad78b7cf8cca9c940bae11892d23dbb659cb
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57304750"
---
# <a name="types-of-image-lists"></a>Tipos de listas de imagens

Há dois tipos de listas de imagens ([CImageList](../mfc/reference/cimagelist-class.md)): nonmasked e mascarado. Uma "lista de imagens nonmasked" consiste em um bitmap colorido que contém uma ou mais imagens. Uma "lista de imagens mascarada" consiste em dois bitmaps de tamanho igual. A primeira é um bitmap colorido que contém as imagens e o segundo é um bitmap monocromático que contém uma série de máscaras — uma para cada imagem em bitmap primeiro.

Uma das sobrecargas do `Create` função de membro usa um sinalizador para indicar se a lista de imagens é mascarada. (As outras sobrecargas criar listas de imagens mascarado.)

Quando uma imagem nonmasked é desenhada, ele simplesmente é copiado para o contexto de dispositivo de destino; ou seja, ela é desenhada sobre a cor do plano de fundo existente do contexto do dispositivo. Quando uma imagem mascarada é desenhada, os bits da imagem são combinados com os bits da máscara, produzindo normalmente áreas transparentes no bitmap em que a cor do plano de fundo do contexto do dispositivo de destino mostra por meio de. Você pode especificar vários estilos de desenho ao desenhar uma imagem mascarada. Por exemplo, você pode especificar que a imagem ser pontilhada para indicar que um objeto selecionado.

## <a name="see-also"></a>Consulte também

[Usando CImageList](../mfc/using-cimagelist.md)<br/>
[Controles](../mfc/controls-mfc.md)
