---
title: 'Como: Usar uma ferramenta de desenho'
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
ms.openlocfilehash: b0041124c35414a0c1c998642b5321319602c872
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81359849"
---
# <a name="how-to-use-a-drawing-tool"></a>Como: Usar uma ferramenta de desenho

O **Editor de Imagens** tem ferramentas de desenho e apagamento à mão livre que funcionam da mesma maneira. Você seleciona a ferramenta e, se necessário, [seleciona cores de primeiro plano e de fundo](../windows/selecting-foreground-or-background-colors-image-editor-for-icons.md) e opções de tamanho e forma. Em seguida, mova o ponteiro para a imagem e clique ou arraste para desenhar e apagar.

## <a name="drawing-tools"></a>Ferramentas de desenho

Você pode selecionar ferramentas de desenho na barra de ferramentas do **Editor de** imagens ou no menu **Imagem.** Quando você seleciona a ferramenta **Borracha,** **ferramenta Brush** ou **Airbrush,** o seletor de opções exibe as opções dessa ferramenta.

> [!TIP]
> As dicas de ferramenta aparecem quando você paira sobre o cursor sobre os botões na [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md). Essas dicas ajudarão você a identificar os botões específicos mencionados aqui.

### <a name="to-select-and-use-a-drawing-tool-from-the-image-editor-toolbar"></a>Para selecionar e usar uma ferramenta de desenho na barra de ferramentas do Image Editor

1. Selecione um botão na barra de ferramentas do **Editor de** imagens.

   - A ferramenta **Borracha** pinta sobre a imagem com a cor de fundo atual quando você pressiona o botão esquerdo do mouse.

      > [!TIP]
      > Em vez de usar a ferramenta **Borracha,** você pode achar mais conveniente desenhar na cor de fundo com uma das ferramentas de desenho.

   - A ferramenta **Lápis** desenha à mão livre em uma largura constante de um pixel.

   - A **ferramenta Pincel** tem várias formas e tamanhos.

   - A ferramenta **Airbrush** distribui aleatoriamente pixels de cor ao redor do centro do pincel.

1. Se necessário, selecione cores e um pincel:

   - Na [paleta Cores,](../windows/colors-window-image-editor-for-icons.md)selecione o botão esquerdo do mouse para selecionar uma cor de primeiro plano ou o botão direito do mouse para selecionar uma cor de fundo.

   - No [seletor De opções,](../windows/toolbar-image-editor-for-icons.md)selecione uma forma representando o pincel que deseja usar.

1. Aponte para o lugar na imagem onde você deseja começar a desenhar ou pintar. O ponteiro muda de forma de acordo com a ferramenta selecionada.

1. Pressione o botão esquerdo do mouse (para a cor do primeiro plano) ou o botão direito do mouse (para a cor de fundo) e segure-o para baixo enquanto você desenha.

### <a name="to-select-and-use-a-drawing-tool-from-the-image-menu"></a>Para selecionar e usar uma ferramenta de desenho no menu Imagem

1. Vá para o menu**Ferramentas** **de imagem** > .

1. No submenu em cascata, escolha a ferramenta que deseja usar.

## <a name="lines-or-closed-figures"></a>Linhas ou Figuras Fechadas

As ferramentas **do Image Editor** para desenhar linhas e figuras fechadas funcionam da mesma forma: você coloca o ponto de inserção em um ponto e arrasta para outro. Para linhas, esses pontos são os pontos finais. Para figuras fechadas, esses pontos são cantos opostos de um retângulo que limita a figura.

As linhas são desenhadas em uma largura determinada pela seleção atual do pincel, e as figuras emolduradas são desenhadas em uma largura determinada pela seleção de largura atual. Linhas e todas as figuras, emolduradas e preenchidas, são desenhadas na cor atual do primeiro plano se você pressionar o botão esquerdo do mouse ou na cor de fundo atual se você pressionar o botão direito do mouse.

### <a name="to-draw-a-line"></a>Para desenhar uma linha

1. Use a [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md) ou vá para o menu**Ferramentas** **de Imagem**> e escolha a ferramenta **Linha.**

1. Se necessário, selecione cores e um pincel:

   - Na [paleta Cores,](../windows/colors-window-image-editor-for-icons.md)selecione o botão esquerdo do mouse para selecionar uma cor de primeiro plano ou o botão direito do mouse para selecionar uma cor de fundo.

   - No [seletor De opções,](../windows/toolbar-image-editor-for-icons.md)selecione uma forma representando o pincel que deseja usar.

1. Coloque o ponteiro no ponto de partida da linha.

1. Arraste até o ponto final da linha.

### <a name="to-draw-a-closed-figure"></a>Para desenhar uma figura fechada

1. Use a barra de ferramentas **do Editor de** imagens ou vá para o menu **Ferramentas de imagem** > **Tools** e selecione uma ferramenta Desenho de **Figura Fechada.**

   As ferramentas **De desenho de figura fechada** criam figuras conforme indicado em seus respectivos botões.

1. Se necessário, selecione cores e uma largura de linha.

1. Mova o ponteiro para um canto da área retangular em que você deseja desenhar a figura.

1. Arraste o ponteiro para o canto diagonalmente oposto.

## <a name="custom-brushes"></a>Pincéis personalizados

Um pincel personalizado é uma parte retangular de uma imagem que você pega e usa como um dos pincéis prontos do Editor de **Imagens.** Todas as operações que você pode executar em uma seleção, você pode executar em um pincel personalizado também.

### <a name="to-create-a-custom-brush-from-a-portion-of-an-image"></a>Para criar um pincel personalizado a partir de uma parte de uma imagem

1. Selecione a parte da imagem que deseja usar para um pincel.

1. Mantenha a tecla **Shift** para baixo, escolha na seleção e arraste-a pela imagem ou vá para o menu **'Seleção de uso de** **imagem'** > como Pincel .

   Sua seleção se torna um pincel personalizado que distribui as cores na seleção em toda a imagem. Cópias da seleção são deixadas ao longo do caminho de arrasto. Quanto mais lentamente você arrasta, mais cópias são feitas.

   > [!NOTE]
   > Selecionar o **Use a Selection as Brush** sem antes selecionar uma parte da imagem usará toda a imagem como um pincel. O resultado do uso de um pincel personalizado também dependerá se você selecionou um [fundo opaco ou transparente](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md).

Pixels em um pincel personalizado que correspondem à cor de fundo atual são normalmente transparentes: eles não pintam sobre a imagem existente. Você pode alterar esse comportamento para que os pixels de cor de fundo pintem sobre a imagem existente.

Você pode usar o pincel personalizado como um selo ou um estêncil para criar diferentes efeitos especiais.

### <a name="to-draw-custom-brush-shapes-in-the-background-color"></a>Para desenhar formas personalizadas de pincel na cor de fundo

1. Selecione um fundo opaco ou transparente.

1. Defina a cor de fundo para a cor em que você deseja desenhar.

1. Posicione o pincel personalizado onde deseja desenhar.

1. Selecione o botão do mouse direito. Todas as regiões opacas do pincel personalizado são desenhadas na cor de fundo.

### <a name="to-double-or-halve-the-custom-brush-size"></a>Para dobrar ou reduzir pela metade o tamanho da escova personalizada

Pressione a**+** tecla Sinal **mais** ( ) para**-** dobrar o tamanho da escova, ou a tecla Menos **Sinal** ( ) para reduzi-lo pela metade.

### <a name="to-cancel-the-custom-brush"></a>Para cancelar o pincel personalizado

Pressione **Esc** ou escolha outra ferramenta de desenho.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Confira também

[Editor de imagens para ícones](../windows/image-editor-for-icons.md)<br/>
[Como: Criar um ícone ou outra imagem](../windows/creating-an-icon-or-other-image-image-editor-for-icons.md)<br/>
[Como: Editar uma imagem](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md)<br/>
[Como: Trabalhar com cor](../windows/working-with-color-image-editor-for-icons.md)<br/>
[Chaves do acelerador](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
