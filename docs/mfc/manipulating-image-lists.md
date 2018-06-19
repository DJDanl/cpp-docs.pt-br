---
title: Manipulando listas de imagens | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- image lists [MFC], manipulating
- lists [MFC], image
- CImageList class [MFC], manipulating
ms.assetid: 043418f8-077e-4dce-b8bb-2b7b0d7b5156
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 559cb87dbed412e706cc85b3db1120083b694991
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33349152"
---
# <a name="manipulating-image-lists"></a>Manipulando listas de imagens
O [substituir](../mfc/reference/cimagelist-class.md#replace) função membro substitui uma imagem em uma lista de imagens ([CImageList](../mfc/reference/cimagelist-class.md)) com uma nova imagem. Essa função também é útil se você precisar aumentar dinamicamente o número de imagens em um objeto de lista de imagem. O [SetImageCount](../mfc/reference/cimagelist-class.md#setimagecount) função muda dinamicamente o número de imagens armazenadas na lista de imagens. Se você aumentar o tamanho da lista de imagens, chame **substituir** adicionar imagens aos novos slots de imagem. Se você diminuir o tamanho da lista de imagens, as imagens além do tamanho do novo são liberadas.  
  
 O [remover](../mfc/reference/cimagelist-class.md#remove) função membro remove uma imagem de uma lista de imagens. O [cópia](../mfc/reference/cimagelist-class.md#copy) copiar função de membro ou trocar imagens dentro de uma lista de imagens. Essa função permite que você indique se a imagem de origem deve ser copiada para o índice de destino ou as imagens de origem e destino devem ser permutadas.  
  
 Para criar uma nova lista de imagem mesclando duas listas de imagens, use a sobrecarga apropriada do [criar](../mfc/reference/cimagelist-class.md#create) função de membro. Esta sobrecarga do **criar** mesclagens lista a primeira imagem da imagem existente, armazenar a imagem resultante em um novo objeto de lista de imagem. A nova imagem é criada ao desenhar a segunda imagem transparente sobre o primeiro. A máscara para a nova imagem é o resultado da execução de uma operação OR lógico nos bits das máscaras para as duas imagens existentes.  
  
 Isso é repetido até que todas as imagens são mescladas e adicionadas ao novo objeto de lista de imagem.  
  
 Você pode gravar as informações da imagem para um arquivo morto chamando o [gravar](../mfc/reference/cimagelist-class.md#write) função de membro e leia-o novamente ao chamar o [leitura](../mfc/reference/cimagelist-class.md#read) função de membro.  
  
 O [GetSafeHandle](../mfc/reference/cimagelist-class.md#getsafehandle), [Attach](../mfc/reference/cimagelist-class.md#attach), e [desanexar](../mfc/reference/cimagelist-class.md#detach) funções de membro permitem que você manipule o identificador da lista de imagens anexado para o `CImageList` objeto, enquanto o [DeleteImageList](../mfc/reference/cimagelist-class.md#deleteimagelist) função membro exclui a lista de imagens sem destruir o `CImageList` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CImageList](../mfc/using-cimagelist.md)   
 [Controles](../mfc/controls-mfc.md)

