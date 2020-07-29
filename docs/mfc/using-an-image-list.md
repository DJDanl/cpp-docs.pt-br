---
title: Usando uma lista de imagens
ms.date: 11/04/2016
helpviewer_keywords:
- lists [MFC], image
- CImageList class [MFC], using
- image lists [MFC]
ms.assetid: e0aed188-a1e6-400e-9f51-033d61c5541f
ms.openlocfilehash: 710831ea8ef6b52292ba3e8eb84a69575c6c7508
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226821"
---
# <a name="using-an-image-list"></a>Usando uma lista de imagens

O uso típico de uma lista de imagens segue o padrão abaixo:

- Construa um objeto [CImageList](../mfc/reference/cimagelist-class.md) e chame uma das sobrecargas de sua função [Create](../mfc/reference/cimagelist-class.md#create) para criar uma lista de imagens e anexá-la ao `CImageList` objeto.

- Se você não adicionou imagens ao criar a lista de imagens, adicione imagens à lista de imagens chamando a função de membro [Adicionar](../mfc/reference/cimagelist-class.md#add) ou [ler](../mfc/reference/cimagelist-class.md#read) .

- Associe a lista de imagens a um controle chamando a função membro apropriada desse controle ou Desenhe imagens da lista de imagens por conta própria usando a função de membro [draw](../mfc/reference/cimagelist-class.md#draw) da lista de imagens.

- Talvez permita que o usuário arraste uma imagem, usando o suporte interno da lista de imagens para arrastar.

> [!NOTE]
> Se a lista de imagens tiver sido criada com o **`new`** operador, você deverá destruir o `CImageList` objeto quando terminar.

## <a name="see-also"></a>Confira também

[Usando CImageList](../mfc/using-cimagelist.md)<br/>
[Controles](../mfc/controls-mfc.md)
