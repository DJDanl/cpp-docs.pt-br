---
title: Usando uma lista de imagens | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- lists [MFC], image
- CImageList class [MFC], using
- image lists [MFC]
ms.assetid: e0aed188-a1e6-400e-9f51-033d61c5541f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5722a2ef8c4e93e4996ee243b3c01b6dd6aeca78
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33381599"
---
# <a name="using-an-image-list"></a>Usando uma lista de imagens
Um uso típico de uma lista de imagens segue o padrão abaixo:  
  
-   Construir um [CImageList](../mfc/reference/cimagelist-class.md) do objeto e chame uma das sobrecargas de seu [criar](../mfc/reference/cimagelist-class.md#create) função para criar uma lista de imagens e anexá-lo para o `CImageList` objeto.  
  
-   Se você não adicionar imagens ao criar a lista de imagens, adicionar imagens à lista de imagens, chamando o [adicionar](../mfc/reference/cimagelist-class.md#add) ou [leitura](../mfc/reference/cimagelist-class.md#read) função de membro.  
  
-   Associar a lista de imagens um controle chamando a função de membro de controle ou desenhar imagens da lista de imagens usando a lista de imagens [desenhar](../mfc/reference/cimagelist-class.md#draw) função de membro.  
  
-   Talvez permitir que o usuário arrasta uma imagem, usando o suporte interno da lista de imagens para arrastar.  
  
> [!NOTE]
>  Se a lista de imagem foi criada com o **novo** operador, você deverá destruir o `CImageList` objeto quando tiver terminado com ele.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CImageList](../mfc/using-cimagelist.md)   
 [Controles](../mfc/controls-mfc.md)

