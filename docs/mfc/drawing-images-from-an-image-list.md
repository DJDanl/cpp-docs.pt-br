---
title: Desenhando imagens a partir de uma lista de imagens
ms.date: 11/04/2016
helpviewer_keywords:
- CImageList class [MFC], drawing images from
- drawing [MFC], images from image lists
- image lists [MFC], drawing images from
- images [MFC], drawing
ms.assetid: 2f6063fb-1c28-45f8-a333-008c064db11c
ms.openlocfilehash: fb307d5557c0e136c1c44c29f08af6062bb1c19d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69508604"
---
# <a name="drawing-images-from-an-image-list"></a>Desenhando imagens a partir de uma lista de imagens

Para desenhar uma imagem, use a função de membro [bruto CImageList::D](../mfc/reference/cimagelist-class.md#draw) . Você especificará um ponteiro para um objeto de contexto do dispositivo, o índice da imagem a ser desenhado, o local no contexto do dispositivo no qual desenhar a imagem e um conjunto de sinalizadores para indicar o estilo do desenho.

Quando você especifica o estilo **ILD_TRANSPARENT** , `Draw` o usa um processo de duas etapas para desenhar uma imagem mascarada. Primeiro, ele executa uma operação AND lógica nos bits da imagem e nos bits da máscara. Em seguida, ele executa uma operação XOR lógico nos resultados da primeira operação e nos bits de segundo plano do contexto do dispositivo de destino. Esse processo cria áreas transparentes na imagem resultante; ou seja, cada bit branco na máscara faz com que o bit correspondente na imagem resultante seja transparente.

Antes de desenhar uma imagem mascarada em um plano de fundo de cor sólida, você deve usar a função de membro [SetBkColor](../mfc/reference/cimagelist-class.md#setbkcolor) para definir a cor do plano de fundo da lista de imagens com a mesma cor que o destino. A definição da cor elimina a necessidade de criar áreas transparentes na imagem `Draw` e permite simplesmente copiar a imagem para o contexto do dispositivo de destino, resultando em um aumento significativo no desempenho. Para desenhar a imagem, especifique o estilo **ILD_NORMAL** quando você chamar `Draw`.

Você pode definir a cor do plano de fundo para uma[CImageList](../mfc/reference/cimagelist-class.md)(lista de imagens mascaradas) a qualquer momento para que ela seja redesenhada corretamente em qualquer plano de fundo sólido. Definir a cor do plano de fundo como **CLR_NONE** faz com que as imagens sejam desenhadas de forma transparente por padrão. Para recuperar a cor do plano de fundo de uma lista de imagens, use a função de membro [GetBkColor](../mfc/reference/cimagelist-class.md#getbkcolor) .

Os estilos **ILD_BLEND25** e **ILD_BLEND50** pontilham a imagem com a cor de realce do sistema. Esses estilos serão úteis se você usar uma imagem mascarada para representar um objeto que o usuário pode selecionar. Por exemplo, você pode usar o estilo **ILD_BLEND50** para desenhar a imagem quando o usuário a seleciona.

Uma imagem não mascarada é copiada para o contexto do dispositivo de `SRCCOPY` destino usando a operação de varredura. As cores na imagem são iguais, independentemente da cor do plano de fundo do contexto do dispositivo. Os estilos de desenho especificados `Draw` em também não têm efeito sobre a aparência de uma imagem não mascarada.

Além da função de membro Draw, outra função, [DrawIndirect](../mfc/reference/cimagelist-class.md#drawindirect), estende a capacidade de renderizar uma imagem. `DrawIndirect`usa, como um parâmetro, uma estrutura [IMAGELISTDRAWPARAMS](/windows/win32/api/commctrl/ns-commctrl-imagelistdrawparams) . Essa estrutura pode ser usada para personalizar a renderização da imagem atual, incluindo o uso de códigos de operação de varredura (ROP). Para obter mais informações sobre códigos de ROP, consulte [rasterizar códigos de operação](/windows/win32/gdi/raster-operation-codes) e bitmaps [como pincéis](/windows/win32/gdi/bitmaps-as-brushes) na SDK do Windows.

## <a name="see-also"></a>Consulte também

[Usando CImageList](../mfc/using-cimagelist.md)<br/>
[Controles](../mfc/controls-mfc.md)
