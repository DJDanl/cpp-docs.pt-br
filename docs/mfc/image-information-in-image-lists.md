---
title: Informações da imagem em listas de imagens
ms.date: 11/04/2016
helpviewer_keywords:
- CImageList class [MFC], image information in
- image lists [MFC], image information in
ms.assetid: 73c41543-fa91-405d-b15b-0feffa6a72c1
ms.openlocfilehash: 7b83b7e5f7de6f8ccca95d732f71a5d73a97e943
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62363512"
---
# <a name="image-information-in-image-lists"></a>Informações da imagem em listas de imagens

[CImageList](../mfc/reference/cimagelist-class.md) inclui várias funções que recuperam informações de uma lista de imagens. O [GetImageInfo](../mfc/reference/cimagelist-class.md#getimageinfo) função de membro preenche um `IMAGEINFO` estrutura com informações sobre uma única imagem, incluindo os identificadores de bitmaps de imagem e máscara, o número de planos de cores e bits por pixel e o retângulo delimitador da imagem dentro do bitmap de imagem. Você pode usar essas informações para manipular diretamente os bitmaps para a imagem.

O [GetImageCount](../mfc/reference/cimagelist-class.md#getimagecount) função de membro recupera o número de imagens em uma lista de imagens.

Você pode criar um ícone com base em uma imagem e uma máscara em uma lista de imagens usando o [ExtractIcon](../mfc/reference/cimagelist-class.md#extracticon) função de membro. A função retorna o identificador do novo ícone.

## <a name="see-also"></a>Consulte também

[Usando CImageList](../mfc/using-cimagelist.md)<br/>
[Controles](../mfc/controls-mfc.md)
