---
title: Como trabalhar com cores
ms.date: 02/15/2019
f1_keywords:
- vc.editors.image.color
- vc.editors.customcolorselector
- vc.editors.loadcolorpalette
- vc.editors.colorswindow
helpviewer_keywords:
- images [C++], background colors
- Image editor [C++], Colors Palette
- colors [C++], image
- Colors Palette, Image editor
- palettes, Image editor colors
- foreground colors [C++], Image editor
- colors [C++]
- Image editor [C++], colors
- colors [C++], Image editor
- colors [C++], image
- images [C++], colors
- Image editor [C++], colors
- Fill tool
- colors [C++], image
- images [C++], colors
- colors [C++], selection tools
- Image editor [C++], colors
- Select Color tool
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
- Image editor [C++], Colors Palette
- Colors Palette, Image editor
- colors [C++], inverting
- colors [C++]
- Color Indicator
- colors [C++], Colors window
- Colors window, hiding colors
- Show Colors Window command
- Colors window, displaying colors
- color palettes [C++]
- palettes
- palettes, Image editor
- colors [C++], Image editor
- Image editor [C++], palettes
- color palettes
- Load Palette Colors dialog box [C++]
- opaque backgrounds [C++]
- colors [C++], image
- Image editor [C++], transparent or opague backgrounds
- images [C++], transparency
- images [C++], opaque background
- colors [C++], image
- Image editor [C++], color inversion
- images [C++], colors
- colors [C++], inverting
ms.assetid: d34ff96f-241d-494f-abdd-13811ada8cd3
ms.openlocfilehash: 3c9134fde9053f57f8848a37b1442728f6111c98
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91502939"
---
# <a name="how-to-work-with-color"></a>Como trabalhar com cores

O **Editor de imagem** contém muitos recursos que manipulam e personalizam cores especificamente. Você pode definir uma cor de primeiro plano ou de plano de fundo, preencher áreas ligadas com cor ou selecionar uma cor em uma imagem para usar como a cor atual do primeiro plano ou do plano de fundo. Você pode usar ferramentas na [barra de ferramentas do editor de imagem](./image-editor-for-icons.md) junto com a paleta cores na janela **cores** para criar imagens.

Todas as cores para imagens monocromáticas e 16 cores são mostradas na paleta **cores** na janela **cores** . Juntamente com as 16 cores padrão, você pode criar suas próprias cores personalizadas. A alteração de qualquer uma das cores na paleta alterará imediatamente a cor correspondente na imagem.

Ao trabalhar com imagens de cursor e ícone de cor 256, a propriedade **Colors** no [janela Propriedades](/visualstudio/ide/reference/properties-window) é usada. Para obter mais informações, consulte [criando um ícone ou cursor de cor de 256](./creating-an-icon-or-other-image-image-editor-for-icons.md).

Imagens true-color também podem ser criadas. No entanto, as amostras de cor verdadeiras não aparecem na paleta inteira na janela **cores** ; Eles aparecem apenas na área do indicador de cor do primeiro plano ou do plano de fundo. As cores verdadeiras são criadas usando a caixa de diálogo **seletor de cores personalizado** .

Você pode salvar paletas de cores personalizadas no disco e recarregá-las conforme necessário. A paleta de cores usada mais recentemente é salva no registro e carregada automaticamente na próxima vez que você iniciar o Visual Studio.

A janela **cores** tem duas partes:

- A **paleta cores**, que é uma matriz de amostras de cor que representa as cores que você pode usar. Você pode selecionar os exemplos para escolher as cores do primeiro plano e do plano de fundo quando estiver usando as ferramentas de gráficos.

- O **indicador de cor**, que mostra as cores e os seletores do primeiro plano e do plano de fundo para a tela e a cor inversa.

   ![Janela cores](../windows/media/vccolorswindow.gif "vcColorsWindow")<br/>
   Janela **cores**

> [!NOTE]
> As ferramentas **cor da tela** e **cor inversa** estão disponíveis somente para ícones e cursores.

Você pode usar a janela **cores** com a [barra de ferramentas do editor de imagem](./image-editor-for-icons.md).

- Para exibir a janela **cores** , clique com o botão direito do mouse em um painel do **Editor de imagem** e escolha a **janela mostrar cores**ou vá até [imagem](./image-editor-for-icons.md)do menu  >  **Mostrar cores janela**.

- Para ocultar a janela **cores** , Desafixar a janela (essa ação permitirá que a janela seja ocultada automaticamente quando não estiver em uso) ou selecione o botão **fechar** .

A paleta **cores** exibe inicialmente 16 cores padrão. Com as cores exibidas, você também pode criar suas próprias cores personalizadas. Em seguida, você pode salvar e carregar uma paleta de cores personalizada.

A caixa de diálogo **seletor de cores personalizado** permite que você personalize as cores usadas para a imagem com as seguintes propriedades:

|Propriedade|Descrição|
|--------------------------|--------------------------|
|**Exibição de cor de gradiente**|Altera os valores de uma cor selecionada.<br/><br/>Posicione o cruzado na cor que você deseja alterar e mova o controle deslizante para cima ou para baixo para alterar os valores de luminosidade ou RGB da cor.|
|**Barra de luminosidade**|Define a luminosidade da cor selecionada na caixa de exibição de **cor do gradiente** .<br/><br/>Selecione e arraste a seta branca para cima na barra para obter mais brilho ou para menos. A caixa de **cores** exibe a cor que você selecionou e o efeito da luminosidade que você definiu.|
|**Cor**|Lista o matiz (valor da roda de cores) da cor que você está definindo. Os valores variam de 0 a 240, em que 0 é vermelho, 60 é amarelo, 120 é verde, 180 é ciano, 200 é magenta e 240 é azul.|
|**Matiz**|Lista o matiz (valor da roda de cores) da cor que você está definindo. Os valores variam de 0 a 240, em que 0 é vermelho, 60 é amarelo, 120 é verde, 180 é ciano, 200 é magenta e 240 é azul.|
|**Sat**|Especifica o valor de saturação da cor que você está definindo. Saturação é a quantidade de cores em um matiz especificado. Os valores variam de 0 a 240.|
|**Luminosidade**|Lista a luminosidade (brilho) da cor que você está definindo. Os valores variam de 0 a 240.|
|**Vermelho**|Especifica o valor vermelho da cor que você está definindo. Os valores variam de 0 a 255.|
|**Verde**|Especifica o valor verde da cor que você está definindo. Os valores variam de 0 a 255.|
|**Azul**|Especifica o valor azul da cor que você está definindo. Os valores variam de 0 a 255.|

Você pode salvar e carregar uma paleta de **cores** que contém cores personalizadas. Por padrão, a paleta **cores** usada mais recentemente é carregada automaticamente quando você inicia o Visual Studio.

> [!TIP]
> Como o **Editor de imagem** não tem meios para restaurar a paleta de **cores** padrão, você deve salvar a paleta de **cores** padrão em um nome como *standard. PAL* ou *Default. PAL* para que você possa restaurar facilmente as configurações padrão.

Use a caixa de diálogo **carregar cores da paleta** para carregar paletas de cores especiais para usar em seu projeto C++ com as seguintes propriedades:

|Propriedade|Descrição|
|-----------------|-----------------|
|**Look in**|Especifica o local onde você deseja localizar um arquivo ou uma pasta.<br/><br/>Selecione a seta para escolher outro local ou selecione o ícone de pasta na barra de ferramentas para mover os níveis para cima.|
|**Nome do arquivo**|Fornece um espaço para digitar o nome do arquivo que você deseja abrir.<br/><br/>Para localizar rapidamente um arquivo que você abriu anteriormente, selecione o nome do arquivo na lista suspensa, se disponível.<br/><br/>Se você estiver procurando um arquivo, poderá usar asteriscos (*) como curingas. Por exemplo, você pode digitar \* . \* para ver uma lista de todos os arquivos. Você também pode digitar o caminho completo de um arquivo, por exemplo, *C:\Meus Documents\MyColorPalette.PAL* ou * \\ \NetworkServer\MyFolder\MyColorPalette.PAL*.|
|**Arquivos do tipo**|Lista os tipos de arquivos a serem exibidos.<br/><br/>A paleta (*. PAL) é o tipo de arquivo padrão para paletas de cores.|

## <a name="how-to"></a>Instruções

### <a name="to-select-foreground-or-background-colors"></a>Para selecionar cores de primeiro plano ou plano de fundo

Exceto para o **apagador**, as ferramentas na barra de ferramentas do **Editor de imagens** são desenhadas com a cor atual do primeiro plano ou do plano de fundo quando você pressiona o botão esquerdo ou direito do mouse, respectivamente.

- Para selecionar uma cor de primeiro plano, com o botão esquerdo do mouse, selecione a cor desejada na paleta **cores** .

- Para selecionar uma cor de plano de fundo, com o botão direito do mouse, selecione a cor desejada na paleta **cores** .

### <a name="to-fill-a-bounded-area-of-an-image-with-a-color"></a>Para preencher uma área limitada de uma imagem com uma cor

O **Editor de imagem** fornece a ferramenta **preencher** para preencher qualquer área de imagem fechada com a cor de desenho atual ou a cor de plano de fundo atual.

### <a name="to-use-the-fill-tool"></a>Para usar a ferramenta preencher

1. Use a barra de ferramentas do **Editor de imagem** ou vá para menu ferramentas de **imagem**  >  **Tools** e selecione a ferramenta **preencher** .

1. Se necessário, escolha desenhar cores. Na [paleta cores](./image-editor-for-icons.md), selecione o botão esquerdo do mouse para selecionar uma cor de primeiro plano ou o botão direito do mouse para selecionar uma cor de plano de fundo.

1. Mova a ferramenta **preenchimento** para a área que você deseja preencher.

1. Selecione o botão esquerdo ou direito do mouse para preencher com a cor do primeiro plano ou a cor do plano de fundo, respectivamente.

### <a name="to-pick-up-a-color-from-an-image-to-use-elsewhere"></a>Para selecionar uma cor de uma imagem a ser usada em outro lugar

A ferramenta **selecionar cor**, ou retirada de cor, faz qualquer cor na imagem da cor do primeiro plano ou da cor do plano de fundo atual, dependendo se você pressiona o botão esquerdo ou direito do mouse. Para cancelar a ferramenta **selecionar cor** , escolha outra ferramenta.

1. Use a barra de ferramentas do **Editor de imagem** ou vá para menu ferramentas de **imagem**  >  **Tools** e selecione a ferramenta **selecionar cor** .

1. Selecione a cor que você deseja escolher na imagem.

   > [!NOTE]
   > Depois de selecionar uma cor, o **Editor de imagem** reativa a ferramenta usada mais recentemente.

1. Desenhe usando o botão esquerdo do mouse para a cor de primeiro plano ou o botão direito do mouse para a cor do plano de fundo.

### <a name="to-choose-the-background"></a>Para escolher o plano de fundo

Quando você move ou copia uma seleção de uma imagem, todos os pixels na seleção que correspondem à cor do plano de fundo atual são, por padrão, transparentes e não obscurecem os pixels no local de destino.

Você pode alternar de um plano de fundo transparente (o padrão) para um plano de fundo opaco e voltar novamente. Quando você usa uma ferramenta de seleção, as opções de **plano de fundo transparente** e de **plano de fundo opaco** aparecem no seletor de **opção** na barra de ferramentas do **Editor de imagem** .

![Opções em segundo plano &#45; opaca ou transparente](../windows/media/vcimageeditoropaqtranspback.gif "Opções em segundo plano &#45; opaca ou transparente")<br/>
**Opções transparentes e opacas** na **barra de ferramentas do editor de imagem**

#### <a name="to-switch-between-a-transparent-and-opaque-background"></a>Para alternar entre um plano de fundo transparente e opaco

Na barra de ferramentas do **Editor de imagem** , selecione o seletor de **opção** e, em seguida, escolha o plano de fundo apropriado:

- **Plano de fundo opaco (O)**: a imagem existente é obscurecida por todas as partes da seleção.

- **Plano de fundo transparente (T)**: imagem existente mostra as partes da seleção que correspondem à cor de plano de fundo atual.

> [!TIP]
> Para um atalho, no menu **imagem** , selecione ou desmarque **desenhar opaco**.

Você pode alterar a cor do plano de fundo enquanto uma seleção já estiver em vigor para alterar quais partes da imagem são transparentes.

### <a name="to-invert-the-colors-in-a-selection"></a>Para inverter as cores em uma seleção

O **Editor de imagem** fornece uma maneira conveniente de inverter as cores na parte selecionada da imagem para que você possa saber como uma imagem seria exibida com cores invertidas.

Para inverter as cores na seleção atual, vá para menu **imagem**  >  **inverter cores**.

### <a name="to-customize-or-change-colors-on-the-colors-palette"></a>Para personalizar ou alterar cores na paleta cores

1. Ir para **imagem**de menu  >  **ajustar cores**.

1. Na caixa de diálogo **seletor de cores personalizado** , defina a cor digitando os valores RGB ou HSL nas caixas de texto apropriadas ou escolha uma cor na caixa de **exibição cor do gradiente** .

1. Defina a luminosidade movendo o controle deslizante na barra de **luminosidade** .

1. Muitas cores personalizadas são dificadas. Se você quiser que a cor sólida fique mais próxima da cor diquerda, clique duas vezes na caixa de **cores** .

   Se, posteriormente, você decidir que deseja a cor pontilhada, mova o controle deslizante na barra de **luminosidade** ou mova os cabelos na caixa de **exibição cor do gradiente** novamente para restaurar o pontilhado.

1. Selecione **OK** para adicionar a nova cor.

### <a name="to-save-a-custom-colors-palette"></a>Para salvar uma paleta de cores personalizadas

1. Vá até **imagem**de menu  >  **salvar paleta**.

1. Navegue até o diretório em que você deseja salvar a paleta e digite um nome para a paleta.

1. Clique em **Salvar**.

### <a name="to-load-a-custom-colors-palette"></a>Para carregar uma paleta de cores personalizadas

1. Ir para menu **imagem**  >  **carregar paleta**.

1. Na caixa de diálogo **paleta de cores de carregamento** , navegue até o diretório correto e selecione a paleta que deseja carregar. As paletas de **cores** são salvas com uma extensão de arquivo. PAL.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Editor de imagem para ícones](../windows/image-editor-for-icons.md)<br/>
[Como: criar um ícone ou outra imagem](../windows/creating-an-icon-or-other-image-image-editor-for-icons.md)<br/>
[Como: editar uma imagem](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md)<br/>
[Como: usar uma ferramenta de desenho](../windows/using-a-drawing-tool-image-editor-for-icons.md)<br/>
[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
