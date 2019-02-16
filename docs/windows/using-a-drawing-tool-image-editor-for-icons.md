---
title: Usando uma ferramenta de desenho
ms.date: 11/04/2016
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
ms.openlocfilehash: 72224581e021a22b31ec5e6fa5940ff5a568a4e0
ms.sourcegitcommit: 470de1337035dd33682d935b4b6c6d8b1bdb0bbb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/15/2019
ms.locfileid: "56320543"
---
# <a name="using-a-drawing-tool"></a>Usando uma ferramenta de desenho

O **imagem** do freehand desenhar e apagar todos funcionam da mesma forma de ferramentas editor: selecione a ferramenta e, se necessário, [selecionar cores de primeiro plano e plano de fundo](../windows/selecting-foreground-or-background-colors-image-editor-for-icons.md) e opções de tamanho e forma. Você, em seguida, mova o ponteiro para a imagem e clique ou arraste para desenhar e apagar.

Quando você seleciona os **borracha** ferramenta, **pincel** ferramenta, ou **spray** ferramenta, o seletor de opção exibe opções da ferramenta.

> [!TIP]
> Em vez de usar o **borracha** ferramenta, talvez seja mais conveniente para desenhar a cor do plano de fundo com uma das ferramentas de desenho.

Você pode selecionar ferramentas de desenho a **Editor de imagens** barra de ferramentas ou o **imagem** menu.

## <a name="to-select-and-use-a-drawing-tool-from-the-image-editor-toolbar"></a>Para selecionar e usar uma ferramenta de desenho da barra de ferramentas do Editor de imagens

1. Selecione um botão na **Editor de imagens** barra de ferramentas.

   - O **borracha** ferramenta pinta sobre a imagem com a cor de plano de fundo atual quando você pressiona o botão esquerdo do mouse.

   - O **Lápis** ferramenta desenha à mão livre em uma constante de largura de um pixel.

   - O **seletor de opção determina a forma e o tamanho da ferramenta Pincel**.

   - O **spray** ferramenta distribui aleatoriamente os pixels da cor em torno do centro do pincel.

        > [!TIP]
        >  Dicas de ferramenta aparecem quando você passa o cursor sobre os botões na [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md). Estas dicas ajudarão você a identificar os botões específicos mencionados aqui.

1. Se necessário, selecione as cores e um pincel:

   - No [paleta de cores](../windows/colors-window-image-editor-for-icons.md), selecione o botão esquerdo do mouse para selecionar uma cor de primeiro plano ou o botão direito do mouse para selecionar uma cor de plano de fundo.

   - No [seletor de opções](../windows/toolbar-image-editor-for-icons.md), selecione uma forma que representa o pincel que você deseja usar.

1. Aponte para o local na imagem para onde você deseja começar a desenhar ou pintura. O ponteiro muda a forma de acordo com a ferramenta que você selecionou.

1. Pressione o botão esquerdo do mouse (para a cor de primeiro plano) ou o botão direito do mouse (para a cor do plano de fundo) e mantenha-a pressionada enquanto você desenhar.

### <a name="to-select-and-use-a-drawing-tool-from-the-image-menu"></a>Para selecionar e usar uma ferramenta de desenho no menu imagem

1. Selecione o **imagem** menu e selecione o **ferramentas** comando.

1. No submenu em cascata, escolha a ferramenta que você deseja usar.

## <a name="drawing-lines-or-closed-figures"></a>Desenhando linhas ou figuras fechadas

Ferramentas do editor de imagens para desenhar linhas e de figuras fechadas todos funcionam da mesma forma: colocar o ponto de inserção em um ponto e arraste para outro. Para linhas, esses pontos são os pontos de extremidade. Para figuras fechadas, esses pontos são cantos opostos de um retângulo delimitador a figura.

Linhas são desenhadas em uma determinado pela seleção atual do pincel de largura e são enquadradas figuras são desenhadas em uma largura determinada pela seleção largura atual. Linhas e todas as figuras, enquadrados tanto preenchido, são desenhadas na cor de primeiro plano atual se você pressionar o botão esquerdo do mouse, ou na cor de plano de fundo atual se você pressionar o botão direito do mouse.

### <a name="to-draw-a-line"></a>Para desenhar uma linha

1. Sobre o [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md) (ou do **imagem** menu, **ferramentas** comando), escolha o **linha** ferramenta.

1. Se necessário, selecione as cores e um pincel:

   - No [paleta de cores](../windows/colors-window-image-editor-for-icons.md), selecione o botão esquerdo do mouse para selecionar uma cor de primeiro plano ou o botão direito do mouse para selecionar uma cor de plano de fundo.

   - No [seletor de opções](../windows/toolbar-image-editor-for-icons.md), selecione uma forma que representa o pincel que você deseja usar.

1. Coloque o ponteiro no ponto de partida da linha.

1. Arraste o ponto de extremidade da linha.

### <a name="to-draw-a-closed-figure"></a>Para desenhar uma figura fechada

1. No **Editor de imagens** barra de ferramentas (ou do **imagem** menu, **ferramentas** comando), selecione um **figura fechada desenho** ferramenta.

   O **fechado Figura desenho** ferramentas criam figuras conforme indicado em seus respectivos botões.

1. Se necessário, selecione as cores e uma largura de linha.

1. Mova o ponteiro para um canto da área retangular na qual você deseja desenhar a figura.

1. Arraste o ponteiro para o canto diagonal oposto.

## <a name="create-a-custom-brush"></a>Criar um pincel personalizado

Um pincel personalizado é uma parte retangular de uma imagem que você pegue e usar como uma da **imagem** pincéis de prontas para uso do editor. Todas as operações que você pode executar em uma seleção, você pode executar em um pincel personalizado também.

### <a name="to-create-a-custom-brush-from-a-portion-of-an-image"></a>Para criar um pincel personalizado de uma parte de uma imagem

1. [Selecione a parte da imagem](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md) que você deseja usar para um pincel.

1. Mantendo os **Shift** para baixo da chave, escolha na seleção e arraste-o em toda a imagem.

   \- ou -

1. Dos **imagem** menu, escolha **usar seleção como Pincel**.

   Sua seleção torna-se um pincel personalizado que distribui as cores na seleção entre a imagem. Cópias da seleção são deixadas ao longo do caminho de arrastamento. Quanto mais lentamente do que você arrastar, são feitas as cópias mais.

   > [!NOTE]
   > Selecionando o **usar uma seleção como Pincel** sem primeiro selecionar uma parte da imagem usará a imagem inteira como um pincel. O resultado do uso de um pincel personalizado também dependem se você selecionou uma [plano de fundo opaca ou transparente](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md).

Pixels em um pincel personalizado que correspondem à cor do plano de fundo atual são normalmente transparentes: eles não pinte sobre a imagem existente. Você pode alterar esse comportamento para que os pixels da cor de plano de fundo pinte sobre a imagem existente.

Você pode usar o pincel personalizado, como um carimbo de data / ou um estêncil para criar diferentes efeitos especiais.

### <a name="to-draw-custom-brush-shapes-in-the-background-color"></a>Para desenhar formas de pincel personalizado na cor da tela de fundo

1. [Selecione um plano de fundo opaco ou transparente](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md).

1. [Definir a cor do plano de fundo](../windows/selecting-foreground-or-background-colors-image-editor-for-icons.md) para a cor em que você deseja desenhar.

1. Posicione o pincel personalizado no qual você deseja desenhar.

1. Selecione o botão direito do mouse. Quaisquer regiões opacos do pincel personalizado são desenhadas na cor da tela de fundo.

### <a name="to-double-or-halve-the-custom-brush-size"></a>Clique duas vezes ou reduz pela metade o tamanho do pincel personalizados

Pressione a **sinal de adição** (**+**) a chave para dobrar o tamanho do pincel, ou o **sinal de subtração** (**-**) chave para dividir a ele .

### <a name="to-cancel-the-custom-brush"></a>Para cancelar o pincel personalizado

Pressione **Esc** ou escolha outra ferramenta de desenho.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
[Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)<br/>
[Editor de imagens para ícones](../windows/image-editor-for-icons.md)<br/>
[Trabalhando com cor](../windows/working-with-color-image-editor-for-icons.md)