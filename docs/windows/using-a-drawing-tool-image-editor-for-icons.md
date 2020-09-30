---
title: 'Como: usar uma ferramenta de desenho'
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
ms.openlocfilehash: 46ba1f1057484f2b5b1e1286482d80fd96312caf
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91502929"
---
# <a name="how-to-use-a-drawing-tool"></a>Como: usar uma ferramenta de desenho

O **Editor de imagens** tem tarefas de desenhar e apagar ferramentas que funcionam da mesma maneira. Você seleciona a ferramenta e, se necessário, [seleciona as cores de primeiro e segundo](./image-editor-for-icons.md) plano e as opções de tamanho e forma. Em seguida, mova o ponteiro para a imagem e clique ou arraste para desenhar e apagar.

## <a name="drawing-tools"></a>Ferramentas de desenho

Você pode selecionar ferramentas de desenho na barra de ferramentas do **Editor de imagens** ou no menu **imagem** . Quando você seleciona a ferramenta **borracha** , a ferramenta **pincel** ou a ferramenta **aerógrafo** , o seletor de opção exibe as opções dessa ferramenta.

> [!TIP]
> As dicas de ferramenta são exibidas quando você passa o cursor sobre os botões na [barra de ferramentas do editor de imagem](./image-editor-for-icons.md). Essas dicas ajudarão você a identificar os botões específicos mencionados aqui.

### <a name="to-select-and-use-a-drawing-tool-from-the-image-editor-toolbar"></a>Para selecionar e usar uma ferramenta de desenho da barra de ferramentas do editor de imagens

1. Selecione um botão na barra de ferramentas do **Editor de imagem** .

   - A ferramenta de **borracha** pinta sobre a imagem com a cor de plano de fundo atual quando você pressiona o botão esquerdo do mouse.

      > [!TIP]
      > Em vez de usar a ferramenta de **borracha** , você pode achar mais conveniente desenhar na cor do plano de fundo com uma das ferramentas de desenho.

   - A ferramenta **lápis** desenha a mão livre em uma largura constante de um pixel.

   - A ferramenta **pincel** tem várias formas e tamanhos.

   - A ferramenta **aerógrafo** distribui aleatoriamente pixels de cor em todo o centro do pincel.

1. Se necessário, selecione cores e um pincel:

   - Na [paleta cores](./image-editor-for-icons.md), selecione o botão esquerdo do mouse para selecionar uma cor de primeiro plano ou o botão direito do mouse para selecionar uma cor de plano de fundo.

   - No [seletor de opções](./image-editor-for-icons.md), selecione uma forma que represente o pincel que você deseja usar.

1. Aponte para o local na imagem em que você deseja começar a desenhar ou pintar. O ponteiro muda de forma de acordo com a ferramenta selecionada.

1. Pressione o botão esquerdo do mouse (para a cor de primeiro plano) ou o botão direito do mouse (para a cor do plano de fundo) e mantenha-o à medida que você desenhar.

### <a name="to-select-and-use-a-drawing-tool-from-the-image-menu"></a>Para selecionar e usar uma ferramenta de desenho no menu imagem

1. Vá para menu **Image**  >  **ferramentas**de imagem.

1. No submenu em cascata, escolha a ferramenta que você deseja usar.

## <a name="lines-or-closed-figures"></a>Linhas ou figuras fechadas

As ferramentas do **Editor de imagem** para linhas de desenho e figuras fechadas funcionam da mesma maneira: você coloca o ponto de inserção em um ponto e arrasta para outro. Para linhas, esses pontos são os pontos de extremidade. Para figuras fechadas, esses pontos são cantos opostos de um retângulo que está delimitando a figura.

As linhas são desenhadas em uma largura determinada pela seleção de pincel atual, e os números de quadros são desenhados em uma largura determinada pela seleção de largura atual. Linhas e todas as figuras, emolduradas e preenchidas, serão desenhadas na cor do primeiro plano atual se você pressionar o botão esquerdo do mouse ou na cor do plano de fundo atual se pressionar o botão direito do mouse.

### <a name="to-draw-a-line"></a>Para desenhar uma linha

1. Use a [barra de ferramentas do editor de imagem](./image-editor-for-icons.md) ou vá para menu **Image** >  **ferramentas** de imagem e escolha a ferramenta **linha** .

1. Se necessário, selecione cores e um pincel:

   - Na [paleta cores](./image-editor-for-icons.md), selecione o botão esquerdo do mouse para selecionar uma cor de primeiro plano ou o botão direito do mouse para selecionar uma cor de plano de fundo.

   - No [seletor de opções](./image-editor-for-icons.md), selecione uma forma que represente o pincel que você deseja usar.

1. Coloque o ponteiro no ponto de partida da linha.

1. Arraste para o ponto de extremidade da linha.

### <a name="to-draw-a-closed-figure"></a>Para desenhar uma figura fechada

1. Use a barra de ferramentas do **Editor de imagem** ou vá para menu ferramentas de **imagem**  >  **Tools** e selecione uma ferramenta **de desenho de figura fechada** .

   As ferramentas de **desenho de figura fechada** criam figuras conforme indicado em seus respectivos botões.

1. Se necessário, selecione cores e uma largura de linha.

1. Mova o ponteiro para um canto da área retangular na qual você deseja desenhar a figura.

1. Arraste o ponteiro para o canto diagonal oposto.

## <a name="custom-brushes"></a>Pincéis personalizados

Um pincel personalizado é uma parte retangular de uma imagem que você pega e usa como um dos pincéis prontos para o **Editor de imagem**. Todas as operações que você pode executar em uma seleção também podem ser executadas em um pincel personalizado.

### <a name="to-create-a-custom-brush-from-a-portion-of-an-image"></a>Para criar um pincel personalizado de uma parte de uma imagem

1. Selecione a parte da imagem que você deseja usar para um pincel.

1. Mantenha a tecla **Shift** pressionada, escolha na seleção e arraste-a pela imagem ou vá para a **imagem**do menu  >  **usar seleção como pincel**.

   Sua seleção se torna um pincel personalizado que distribui as cores na seleção na imagem. As cópias da seleção são deixadas ao longo do caminho de arrasto. Quanto mais lentamente você arrastar, mais cópias serão feitas.

   > [!NOTE]
   > A seleção de **usar uma seleção como pincel** sem primeiro selecionar uma parte da imagem usará a imagem inteira como um pincel. O resultado do uso de um pincel personalizado também dependerá do fato de você ter selecionado um [plano de fundo opaco ou transparente](./image-editor-for-icons.md).

Os pixels em um pincel personalizado que corresponde à cor do plano de fundo atual são normalmente transparentes: eles não pintam a imagem existente. Você pode alterar esse comportamento para que os pixels de cor de segundo plano sejam pintados sobre a imagem existente.

Você pode usar o pincel personalizado como um carimbo ou um estêncil para criar efeitos especiais diferentes.

### <a name="to-draw-custom-brush-shapes-in-the-background-color"></a>Para desenhar formas de pincel personalizadas na cor do plano de fundo

1. Selecione um plano de fundo opaco ou transparente.

1. Defina a cor do plano de fundo como a cor na qual você deseja desenhar.

1. Posicione o pincel personalizado onde você deseja desenhar.

1. Selecione o botão direito do mouse. Todas as regiões opacas do pincel personalizado são desenhadas na cor do plano de fundo.

### <a name="to-double-or-halve-the-custom-brush-size"></a>Para dobrar ou metade do tamanho do pincel personalizado

Pressione a tecla **sinal de adição** ( **+** ) para dobrar o tamanho do pincel ou a tecla sinal de **menos** ( **-** ) para metade dela.

### <a name="to-cancel-the-custom-brush"></a>Para cancelar o pincel personalizado

Pressione **ESC** ou escolha outra ferramenta de desenho.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Editor de imagem para ícones](../windows/image-editor-for-icons.md)<br/>
[Como: criar um ícone ou outra imagem](../windows/creating-an-icon-or-other-image-image-editor-for-icons.md)<br/>
[Como: editar uma imagem](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md)<br/>
[Como trabalhar com cores](../windows/working-with-color-image-editor-for-icons.md)<br/>
[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
