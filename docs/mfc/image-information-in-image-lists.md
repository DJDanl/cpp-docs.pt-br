---
title: Informações da imagem em listas de imagens
ms.date: 11/04/2016
helpviewer_keywords:
- CImageList class [MFC], image information in
- image lists [MFC], image information in
ms.assetid: 73c41543-fa91-405d-b15b-0feffa6a72c1
ms.openlocfilehash: c12198c769585763095d22b73d11f7af3c9d6fc0
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84624507"
---
# <a name="image-information-in-image-lists"></a>Informações da imagem em listas de imagens

[CImageList](reference/cimagelist-class.md) inclui várias funções que recuperam informações de uma lista de imagens. A função membro [GetImageInfo](reference/cimagelist-class.md#getimageinfo) preenche uma `IMAGEINFO` estrutura com informações sobre uma única imagem, incluindo as alças dos bitmaps de imagem e máscara, o número de planos de cores e bits por pixel e o retângulo delimitador da imagem no bitmap de imagem. Você pode usar essas informações para manipular diretamente os bitmaps da imagem.

A função membro [GetImageCount](reference/cimagelist-class.md#getimagecount) recupera o número de imagens em uma lista de imagens.

Você pode criar um ícone com base em uma imagem e uma máscara em uma lista de imagens usando a função de membro [ExtractIcon](reference/cimagelist-class.md#extracticon) . A função retorna o identificador do novo ícone.

## <a name="see-also"></a>Consulte também

[Usando CImageList](using-cimagelist.md)<br/>
[Controles](controls-mfc.md)
