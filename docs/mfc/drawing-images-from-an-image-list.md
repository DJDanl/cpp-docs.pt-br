---
title: Desenhando imagens a partir de uma lista de imagens | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- CImageList class [MFC], drawing images from
- drawing [MFC], images from image lists
- image lists [MFC], drawing images from
- images [MFC], drawing
ms.assetid: 2f6063fb-1c28-45f8-a333-008c064db11c
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: deb9a96d5096b489f8e4dcbaf987509d60bd5024
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="drawing-images-from-an-image-list"></a>Desenhando imagens a partir de uma lista de imagens
Para desenhar uma imagem, use o [CImageList::Draw](../mfc/reference/cimagelist-class.md#draw) função de membro. Você especificará um ponteiro para um objeto de contexto de dispositivo, o índice da imagem para desenhar o local no contexto do dispositivo no qual desenhar a imagem e um conjunto de sinalizadores para indicar o estilo de desenho.  
  
 Quando você especifica o `ILD_TRANSPARENT` estilo, **desenhar** usa um processo de duas etapas para desenhar uma imagem mascarada. Primeiro, ele executa uma operação lógica- e operação em bits da imagem e os bits da máscara. Em seguida, ele executa uma operação lógica XOR sobre os resultados da primeira operação e os bits de plano de fundo do contexto do dispositivo de destino. Esse processo cria áreas transparentes na imagem resultante. ou seja, cada branco bit da máscara faz com que o bit correspondente a imagem resultante para ser transparente.  
  
 Antes de desenho uma imagem mascarada em um plano de fundo de cor sólida, você deve usar o [SetBkColor](../mfc/reference/cimagelist-class.md#setbkcolor) a função de membro para definir a cor de plano de fundo da lista de imagens para a mesma cor como o destino. Definindo a cor elimina a necessidade de criar áreas transparentes na imagem e permite **desenhar** simplesmente copiar a imagem para o contexto de dispositivo de destino, resultando em um aumento significativo no desempenho. Para desenhar a imagem, especifique o `ILD_NORMAL` estilo quando você chamar **desenhar**.  
  
 Você pode definir a cor de fundo de uma lista de imagens mascaradas ([CImageList](../mfc/reference/cimagelist-class.md)) a qualquer momento para que ele desenha corretamente em qualquer plano de fundo sólido. Definir a cor de plano de fundo `CLR_NONE` faz com que imagens a ser desenhada de forma transparente por padrão. Para recuperar a cor de plano de fundo de uma lista de imagens, use o [GetBkColor](../mfc/reference/cimagelist-class.md#getbkcolor) função de membro.  
  
 O `ILD_BLEND25` e `ILD_BLEND50` estilos pontilhada a imagem com a cor de realce do sistema. Esses estilos são úteis se você usar uma imagem mascarada para representar um objeto que o usuário pode selecionar. Por exemplo, você pode usar o `ILD_BLEND50` estilo para desenhar a imagem quando o usuário o seleciona.  
  
 Uma imagem nonmasked é copiada para o contexto de dispositivo de destino usando o **SRCCOPY** operação de varredura. As cores da imagem aparecem as mesmas, independentemente da cor de plano de fundo do contexto do dispositivo. Os estilos de desenho especificados em **desenhar** também não têm nenhum efeito sobre a aparência de uma imagem nonmasked.  
  
 Além de função de membro Draw, outra função, [DrawIndirect](../mfc/reference/cimagelist-class.md#drawindirect), estende a capacidade de processar uma imagem. `DrawIndirect`usa, como um parâmetro, uma [IMAGELISTDRAWPARAMS](http://msdn.microsoft.com/library/windows/desktop/bb761395) estrutura. Essa estrutura pode ser usada para personalizar a renderização da imagem atual, incluindo o uso de códigos de operação (ROP) de varredura. Para obter mais informações sobre códigos ROP, consulte [códigos de operação de varredura](http://msdn.microsoft.com/library/windows/desktop/dd162892) e [Bitmaps como pincéis](http://msdn.microsoft.com/library/windows/desktop/dd183378) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CImageList](../mfc/using-cimagelist.md)   
 [Controles](../mfc/controls-mfc.md)

