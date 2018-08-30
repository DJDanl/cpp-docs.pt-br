---
title: Desenhando imagens a partir de uma lista de imagens | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CImageList class [MFC], drawing images from
- drawing [MFC], images from image lists
- image lists [MFC], drawing images from
- images [MFC], drawing
ms.assetid: 2f6063fb-1c28-45f8-a333-008c064db11c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2f626b0dc4a8177268e72bc01f7d05ca00e326ba
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43217821"
---
# <a name="drawing-images-from-an-image-list"></a>Desenhando imagens a partir de uma lista de imagens
Para desenhar uma imagem, use o [CImageList::Draw](../mfc/reference/cimagelist-class.md#draw) função de membro. Você especificará um ponteiro para um objeto de contexto de dispositivo, o índice da imagem para desenhar o local no contexto de dispositivo no qual desenhar a imagem e um conjunto de sinalizadores para indicar o estilo de desenho.  
  
 Quando você especifica o **ILD_TRANSPARENT** estilo, `Draw` usa um processo em duas etapas para desenhar uma imagem mascarada. Primeiro, ele executa uma operação lógica – e operação nos bits da imagem e os bits da máscara. Em seguida, ele executa uma operação de XOR lógico sobre os resultados da primeira operação e os bits de plano de fundo do contexto de dispositivo de destino. Esse processo cria áreas transparentes na imagem resultante. ou seja, cada branco bit na máscara faz com que o bit correspondente na imagem resultante para ser transparente.  
  
 Antes de desenhar uma imagem mascarada em um plano de fundo de cor sólida, você deve usar o [SetBkColor](../mfc/reference/cimagelist-class.md#setbkcolor) a função de membro para definir a cor de plano de fundo da lista de imagens para a mesma cor como o destino. Configurando a cor elimina a necessidade de criar áreas transparentes da imagem e habilita `Draw` simplesmente copiar a imagem para o contexto de dispositivo de destino, resultando em um aumento significativo no desempenho. Para desenhar a imagem, especifique o **ILD_NORMAL** estilo quando você chamar `Draw`.  
  
 Você pode definir a cor de plano de fundo para obter uma lista de imagem mascarado ([CImageList](../mfc/reference/cimagelist-class.md)) a qualquer momento para que ele desenha corretamente em qualquer tela de fundo sólida. Definir a cor do plano de fundo como **CLR_NONE** faz com que imagens a ser desenhado de forma transparente por padrão. Para recuperar a cor do plano de fundo de uma lista de imagens, use o [GetBkColor](../mfc/reference/cimagelist-class.md#getbkcolor) função de membro.  
  
 O **ILD_BLEND25** e **ILD_BLEND50** estilos pontilhamento a imagem com a cor de realce do sistema. Esses estilos são úteis se você usar uma imagem mascarada para representar um objeto que o usuário pode selecionar. Por exemplo, você pode usar o **ILD_BLEND50** estilo para desenhar a imagem quando o usuário seleciona a ele.  
  
 Uma imagem nonmasked é copiada para o contexto de dispositivo de destino usando o `SRCCOPY` operação de varredura. As cores da imagem aparecem o mesmo, independentemente da cor do plano de fundo do contexto do dispositivo. Os estilos de desenho especificados no `Draw` também não têm nenhum efeito na aparência de uma imagem nonmasked.  
  
 A função de membro Draw, outra função, além de [DrawIndirect](../mfc/reference/cimagelist-class.md#drawindirect), estende a capacidade de renderizar uma imagem. `DrawIndirect` aceita, como um parâmetro, uma [IMAGELISTDRAWPARAMS](/windows/desktop/api/commctrl/ns-commctrl-_imagelistdrawparams) estrutura. Essa estrutura pode ser usada para personalizar a renderização da imagem atual, incluindo o uso de códigos de operação (ROP) de varredura. Para obter mais informações sobre códigos de ROP, consulte [códigos de operação de varredura](/windows/desktop/gdi/raster-operation-codes) e [Bitmaps como pincéis](/windows/desktop/gdi/bitmaps-as-brushes) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CImageList](../mfc/using-cimagelist.md)   
 [Controles](../mfc/controls-mfc.md)

