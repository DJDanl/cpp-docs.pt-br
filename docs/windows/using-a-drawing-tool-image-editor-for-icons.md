---
title: 'Como: Use uma ferramenta de desenho'
ms.date: 02/15/2019
f1_keywords:
- vc.editors.image.drawing
helpviewer_keywords:
- Image editor [C++], selecting drawing tools
- Image editor [C++], toolbar
- drawing tools
- Image editor [C++], drawing lines
- shapes, drawing
- colors [C++], brush
- brushes, colors
- brushes, creating custom
- images [C++], creating custom brushes
- graphics [C++], custom brushes
- custom brushes
ms.assetid: 1f8c6eef-7760-45a9-a5cb-9e15c6f91245
ms.openlocfilehash: 7b362749c9a5cb1c7ec77e5cac8625aa7eb260f0
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59037783"
---
# <a name="how-to-use-a-drawing-tool"></a>Como: Use uma ferramenta de desenho

O **Editor de imagens** tem desenho à mão livre e apagar as ferramentas que funcionam da mesma maneira. Selecione a ferramenta e, se necessário, [selecionar cores de primeiro plano e plano de fundo](../windows/selecting-foreground-or-background-colors-image-editor-for-icons.md) e opções de tamanho e forma. Você, em seguida, mova o ponteiro para a imagem e clique ou arraste para desenhar e apagar.

## <a name="drawing-tools"></a>Ferramentas de desenho

Você pode selecionar ferramentas de desenho a **Editor de imagens** barra de ferramentas ou o **imagem** menu. Quando você seleciona os **borracha** ferramenta, **pincel** ferramenta, ou **spray** ferramenta, o seletor de opção exibe opções da ferramenta.

> [!TIP]
>  Dicas de ferramenta aparecem quando você passa o cursor sobre os botões na [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md). Estas dicas ajudarão você a identificar os botões específicos mencionados aqui.

### <a name="to-select-and-use-a-drawing-tool-from-the-image-editor-toolbar"></a>Para selecionar e usar uma ferramenta de desenho da barra de ferramentas do Editor de imagens

1. Selecione um botão na **Editor de imagens** barra de ferramentas.

   - O **borracha** ferramenta pinta sobre a imagem com a cor de plano de fundo atual quando você pressiona o botão esquerdo do mouse.

      > [!TIP]
      > Em vez de usar o **borracha** ferramenta, talvez seja mais conveniente para desenhar a cor do plano de fundo com uma das ferramentas de desenho.

   - O **Lápis** ferramenta desenha à mão livre em uma constante de largura de um pixel.

   - O **pincel** ferramenta tem várias formas e tamanhos.

   - O **spray** ferramenta distribui aleatoriamente os pixels da cor em torno do centro do pincel.

1. Se necessário, selecione as cores e um pincel:

   - No [paleta de cores](../windows/colors-window-image-editor-for-icons.md), selecione o botão esquerdo do mouse para selecionar uma cor de primeiro plano ou o botão direito do mouse para selecionar uma cor de plano de fundo.

   - No [seletor de opções](../windows/toolbar-image-editor-for-icons.md), selecione uma forma que representa o pincel que você deseja usar.

1. Aponte para o local na imagem para onde você deseja começar a desenhar ou pintura. O ponteiro muda a forma de acordo com a ferramenta que você selecionou.

1. Pressione o botão esquerdo do mouse (para a cor de primeiro plano) ou o botão direito do mouse (para a cor do plano de fundo) e mantenha-a pressionada enquanto você desenhar.

### <a name="to-select-and-use-a-drawing-tool-from-the-image-menu"></a>Para selecionar e usar uma ferramenta de desenho no menu imagem

1. Vá ao menu **imagem** > **ferramentas**.

1. No submenu em cascata, escolha a ferramenta que você deseja usar.

## <a name="lines-or-closed-figures"></a>Linhas ou figuras fechadas

O **Editor de imagens** ferramentas para desenhar linhas e figuras fechadas funcionam da mesma forma: colocar o ponto de inserção em um ponto e arraste para outro. Para linhas, esses pontos são os pontos de extremidade. Para figuras fechadas, esses pontos são cantos opostos de um retângulo delimitador a figura.

Linhas são desenhadas em uma determinado pela seleção atual do pincel de largura e são enquadradas figuras são desenhadas em uma largura determinada pela seleção largura atual. Linhas e todas as figuras, enquadrados tanto preenchido, são desenhadas na cor de primeiro plano atual se você pressionar o botão esquerdo do mouse, ou na cor de plano de fundo atual se você pressionar o botão direito do mouse.

### <a name="to-draw-a-line"></a>Para desenhar uma linha

1. Use o [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md) ou vá para o menu **imagem**> **ferramentas** e escolha o **linha** ferramenta.

1. Se necessário, selecione as cores e um pincel:

   - No [paleta de cores](../windows/colors-window-image-editor-for-icons.md), selecione o botão esquerdo do mouse para selecionar uma cor de primeiro plano ou o botão direito do mouse para selecionar uma cor de plano de fundo.

   - No [seletor de opções](../windows/toolbar-image-editor-for-icons.md), selecione uma forma que representa o pincel que você deseja usar.

1. Coloque o ponteiro no ponto de partida da linha.

1. Arraste o ponto de extremidade da linha.

### <a name="to-draw-a-closed-figure"></a>Para desenhar uma figura fechada

1. Use o **Editor de imagens** barra de ferramentas ou vá até o menu **imagem** > **ferramentas** e selecione um **figura fechada desenho** ferramenta.

   O **fechado Figura desenho** ferramentas criam figuras conforme indicado em seus respectivos botões.

1. Se necessário, selecione as cores e uma largura de linha.

1. Mova o ponteiro para um canto da área retangular na qual você deseja desenhar a figura.

1. Arraste o ponteiro para o canto diagonal oposto.

## <a name="custom-brushes"></a>Pincéis personalizados

Um pincel personalizado é uma parte retangular de uma imagem que você pegue e usar como uma da **Editor de imagens**do pincéis prontas para uso. Todas as operações que você pode executar em uma seleção, você pode executar em um pincel personalizado também.

### <a name="to-create-a-custom-brush-from-a-portion-of-an-image"></a>Para criar um pincel personalizado de uma parte de uma imagem

1. Selecione a parte da imagem que você deseja usar para um pincel.

1. Mantenha os **Shift** para baixo da chave, escolha na seleção e arraste-o em toda a imagem ou vá ao menu **imagem** > **usar seleção como Pincel**.

   Sua seleção torna-se um pincel personalizado que distribui as cores na seleção entre a imagem. Cópias da seleção são deixadas ao longo do caminho de arrastamento. Quanto mais lentamente do que você arrastar, são feitas as cópias mais.

   > [!NOTE]
   > Selecionando o **usar uma seleção como Pincel** sem primeiro selecionar uma parte da imagem usará a imagem inteira como um pincel. O resultado do uso de um pincel personalizado também dependem se você selecionou uma [plano de fundo opaca ou transparente](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md).

Pixels em um pincel personalizado que correspondem à cor do plano de fundo atual são normalmente transparentes: eles não pinte sobre a imagem existente. Você pode alterar esse comportamento para que os pixels da cor de plano de fundo pinte sobre a imagem existente.

Você pode usar o pincel personalizado, como um carimbo de data / ou um estêncil para criar diferentes efeitos especiais.

### <a name="to-draw-custom-brush-shapes-in-the-background-color"></a>Para desenhar formas de pincel personalizado na cor da tela de fundo

1. Selecione um plano de fundo opaco ou transparente.

1. Defina a cor do plano de fundo para a cor em que você deseja desenhar.

1. Posicione o pincel personalizado no qual você deseja desenhar.

1. Selecione o botão direito do mouse. Quaisquer regiões opacos do pincel personalizado são desenhadas na cor da tela de fundo.

### <a name="to-double-or-halve-the-custom-brush-size"></a>Clique duas vezes ou reduz pela metade o tamanho do pincel personalizados

Pressione a **sinal de adição** (**+**) a chave para dobrar o tamanho do pincel, ou o **sinal de subtração** (**-**) chave para dividir a ele .

### <a name="to-cancel-the-custom-brush"></a>Para cancelar o pincel personalizado

Pressione **Esc** ou escolha outra ferramenta de desenho.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Editor de imagens para ícones](../windows/image-editor-for-icons.md)<br/>
[Como: Criar um ícone ou outra imagem](../windows/creating-an-icon-or-other-image-image-editor-for-icons.md)<br/>
[Como: Editar uma imagem](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md)<br/>
[Como: Trabalhar com cores](../windows/working-with-color-image-editor-for-icons.md)<br/>
[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>