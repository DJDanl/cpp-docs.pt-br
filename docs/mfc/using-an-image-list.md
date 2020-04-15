---
title: Usando uma lista de imagens
ms.date: 11/04/2016
helpviewer_keywords:
- lists [MFC], image
- CImageList class [MFC], using
- image lists [MFC]
ms.assetid: e0aed188-a1e6-400e-9f51-033d61c5541f
ms.openlocfilehash: 0d9566739a15e5d216eb052a7265313850515648
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366568"
---
# <a name="using-an-image-list"></a>Usando uma lista de imagens

O uso típico de uma lista de imagens segue o padrão abaixo:

- Construa um objeto [CImageList](../mfc/reference/cimagelist-class.md) e chame [Create](../mfc/reference/cimagelist-class.md#create) uma das sobrecargas de sua função `CImageList` Criar para criar uma lista de imagens e anexá-la ao objeto.

- Se você não adicionou imagens quando criou a lista de imagens, adicione imagens à lista de imagens chamando a função [Adicionar](../mfc/reference/cimagelist-class.md#add) ou [Ler](../mfc/reference/cimagelist-class.md#read) membro.

- Associe a lista de imagens a um controle chamando a função de membro apropriada desse controle ou desenhe imagens da lista de imagens você mesmo usando a função [Draw](../mfc/reference/cimagelist-class.md#draw) member da lista de imagens.

- Talvez permita que o usuário arraste uma imagem, usando o suporte interno da lista de imagens para arrastar.

> [!NOTE]
> Se a lista de imagens foi criada com `CImageList` o **novo** operador, você deve destruir o objeto quando terminar com ele.

## <a name="see-also"></a>Confira também

[Usando CImageList](../mfc/using-cimagelist.md)<br/>
[Controles](../mfc/controls-mfc.md)
