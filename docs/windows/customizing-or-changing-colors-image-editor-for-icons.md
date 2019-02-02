---
title: Personalizando ou alterando cores (editor de imagens para ícones)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.customcolorselector
helpviewer_keywords:
- dithered color, Image editor
- Custom Color Selector dialog box [C++]
- Image editor [C++], Colors Palette
- colors [C++], image
- bitmaps [C++], colors
- images [C++], colors
- HSL values
- Colors Palette, Image editor
- RGB color values
- Adjust Colors command [C++]
- Image editor [C++], dithered color
ms.assetid: e58f6b32-f435-4d9a-a570-7569433661ae
ms.openlocfilehash: 7ab353ad0aa22c74eeba58e9310d9bc0f8d5a832
ms.sourcegitcommit: efcc8c97570ddf7631570226c700e8f6ebb6c7be
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/01/2019
ms.locfileid: "55560277"
---
# <a name="customizing-or-changing-colors-image-editor-for-icons"></a>Personalizando ou alterando cores (editor de imagens para ícones)

O **imagem** do editor [paleta de cores](../windows/colors-window-image-editor-for-icons.md) exibe inicialmente 16 cores padrão. Com as cores exibidas, você também pode criar suas próprias cores personalizadas. Em seguida, você pode [salvar e carregar uma paleta de cores personalizada](../windows/saving-and-loading-different-color-palettes-image-editor-for-icons.md).

O **seletor de cores personalizada** caixa de diálogo permite que você personalize as cores que você pode usar para sua imagem. As propriedades a seguir incluídas são:

|Propriedade|Descrição|
|---|---|
|**Exibição em cores de gradiente**|Altera os valores de uma cor selecionada. Posicione a cruz na cor que você deseja alterar. Mova o controle deslizante para cima ou para baixo para alterar a luminosidade ou valores RGB da cor.|
|**Barra de luminosidade**|Define a luminosidade para a cor selecionada na **exibição em cores gradiente** caixa. Selecione e arraste a seta branca a barra de brilho maior ou para baixo para o menor. O **cor** caixa exibe a cor que você selecionou e o efeito de luminosidade você definir.|
|**Cor**|Lista o matiz (valor de roda de cores) da cor que você está definindo. Os valores variam de 0 a 240, onde 0 é vermelho, 60 é amarelo, 120 é verde, 180 é ciano, 200 é magenta e 240 é azul.|
|**Matiz**|Lista o matiz (valor de roda de cores) da cor que você está definindo. Os valores variam de 0 a 240, onde 0 é vermelho, 60 é amarelo, 120 é verde, 180 é ciano, 200 é magenta e 240 é azul.|
|**Sat**|Especifica o valor de saturação da cor que você está definindo. A saturação é a quantidade de cor em um matiz especificado. Os valores variam de 0 a 240.|
|**Luminosidade**|Lista a luminosidade (brilho) da cor que você está definindo. Os valores variam de 0 a 240.|
|**Vermelho**|Especifica o valor de vermelho da cor que você está definindo. Os valores variam de 0 a 255.|
|**Verde**|Especifica o valor de verde da cor que você está definindo. Os valores variam de 0 a 255.|
|**Azul**|Especifica o valor de azul da cor que você está definindo. Os valores variam de 0 a 255.|

## <a name="to-change-colors-on-the-colors-palette"></a>Para alterar as cores na paleta de cores

1. Dos **imagem** menu, escolha **ajustar cores**.

1. No **seletor de cores personalizada** diálogo caixa, defina a cor, digitando valores RGB ou HSL nas caixas de texto apropriado ou escolha uma cor na **exibição em cores gradiente** caixa.

1. Defina a luminosidade movendo o controle deslizante **luminosidade** barra.

1. Número de cores personalizada é pontilhada. Se você quiser a cor sólida mais próxima a cor pontilhada, clique duas vezes o **cor** caixa.

   Se você decidir que quer a cor pontilhada, mova o controle deslizante **luminosidade** barra ou mover a mira na **exibição de cor gradiente** novamente para restaurar o pontilhado.

1. Selecione **Okey** para adicionar a nova cor.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
[Trabalhando com cor](../windows/working-with-color-image-editor-for-icons.md)<br/>
[Menu imagem](../windows/image-menu-image-editor-for-icons.md)<br/>
[Janela cores](../windows/colors-window-image-editor-for-icons.md)