---
title: 'Como: Trabalhar com cores'
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
ms.openlocfilehash: f50d734ab35968aa107e23b8450d60f316b6002e
ms.sourcegitcommit: b4645761ce5acf8c2fc7a662334dd5a471ea976d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/07/2019
ms.locfileid: "57563141"
---
# <a name="how-to-work-with-color"></a>Como: Trabalhar com cores

O **Editor de imagens** contém muitos recursos que especificamente a lidar com e personalizar as cores. Você pode definir uma cor de primeiro plano ou segundo plano, preencher as áreas limitadas com cor ou selecione uma cor em uma imagem para usar como a cor de primeiro plano ou segundo plano atual. Você pode usar ferramentas o [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md) junto com a paleta de cores na **cores** janela para criar imagens.

Todas as cores para imagens de 16 cores e monocromático são mostradas na **cores** paleta na **cores** janela. Juntamente com 16 cores padrão, você pode criar suas próprias cores personalizadas. Alteração de qualquer uma das cores na paleta de alterar imediatamente a cor correspondente na imagem.

Ao trabalhar com o ícone de 256 cores e imagens de cursor, o **cores** propriedade no [janela propriedades](/visualstudio/ide/reference/properties-window) é usado. Para obter mais informações, consulte [criando um ícone de 256 cores ou cursor](creating-a-256-color-icon-or-cursor-image-editor-for-icons.md).

True color imagens também podem ser criadas. No entanto, amostras de cores true não são exibidos na paleta completa na **cores** janela; eles aparecem somente na área de indicador de cor do primeiro plano ou segundo plano. Cores True são criadas usando o **seletor de cores personalizada** caixa de diálogo.

Você pode salvar paletas de cores personalizada no disco e recarregá-los conforme necessário. A paleta de cores usado mais recentemente é salva no registro e carregada automaticamente na próxima vez que iniciar o Visual Studio.

O **cores** janela tem duas partes:

- O **paleta de cores**, que é uma matriz de amostras de cores que representam as cores que você pode usar. Você pode selecionar os exemplos para escolher as cores de primeiro e segundo plano quando você estiver usando as ferramentas de gráficos.

- O **indicador de cor**, que mostra as cores de primeiro e segundo plano e os seletores de cor da tela e o inverso.

   ![Janela de cores](../windows/media/vccolorswindow.gif "vcColorsWindow")<br/>
   **Cores** janela

> [!NOTE]
> O **cor da tela** e **cor inverso** ferramentas só estão disponíveis para os ícones e cursores.

Você pode usar o **cores** janela com o [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md).

- Para exibir o **cores** janela, o botão direito do mouse em um **Editor de imagens** painel e escolha **Mostrar janela de cores**, ou vá ao menu [imagem](../windows/image-menu-image-editor-for-icons.md)  >  **Mostrar janela de cores**.

- Para ocultar a **cores** janela, Desafixar a janela (esta ação permitirá a janela para ocultar automaticamente quando não está em uso) ou selecione o **fechar** botão.

O **cores** paleta exibe inicialmente 16 cores padrão. Com as cores exibidas, você também pode criar suas próprias cores personalizadas. Em seguida, você pode salvar e carregar uma paleta de cores personalizada.

O **seletor de cores personalizada** caixa de diálogo permite que você personalize as cores que você pode usar para sua imagem com as seguintes propriedades:

|Propriedade|Descrição|
|--------------------------|--------------------------|
|**Exibição em cores de gradiente**|Altera os valores de uma cor selecionada.<br/><br/>Posicione a cruz na cor que você deseja alterar e mova o controle deslizante para cima ou para baixo para alterar a luminosidade ou valores RGB da cor.|
|**Barra de luminosidade**|Define a luminosidade para a cor selecionada na **exibição em cores gradiente** caixa.<br/><br/>Selecione e arraste a seta branca a barra de brilho maior ou para baixo para o menor. O **cor** caixa exibe a cor que você selecionou e o efeito de luminosidade você definir.|
|**Cor**|Lista o matiz (valor de roda de cores) da cor que você está definindo. Os valores variam de 0 a 240, onde 0 é vermelho, 60 é amarelo, 120 é verde, 180 é ciano, 200 é magenta e 240 é azul.|
|**Matiz**|Lista o matiz (valor de roda de cores) da cor que você está definindo. Os valores variam de 0 a 240, onde 0 é vermelho, 60 é amarelo, 120 é verde, 180 é ciano, 200 é magenta e 240 é azul.|
|**Sat**|Especifica o valor de saturação da cor que você está definindo. A saturação é a quantidade de cor em um matiz especificado. Os valores variam de 0 a 240.|
|**Luminosidade**|Lista a luminosidade (brilho) da cor que você está definindo. Os valores variam de 0 a 240.|
|**Vermelho**|Especifica o valor de vermelho da cor que você está definindo. Os valores variam de 0 a 255.|
|**Verde**|Especifica o valor de verde da cor que você está definindo. Os valores variam de 0 a 255.|
|**Azul**|Especifica o valor de azul da cor que você está definindo. Os valores variam de 0 a 255.|

Você pode salvar e carregar um **cores** paleta que contém cores personalizadas. Por padrão, o **cores** paleta usada mais recentemente é carregada automaticamente quando você inicia o Visual Studio.

> [!TIP]
> Uma vez que o **Editor de imagens** não tem meios para restaurar o padrão **cores** paleta, você deve salvar o padrão **cores** paleta sob um nome como  *Standard.PAL* ou *default.pal* para que você possa facilmente restaurar as configurações padrão.

Use o **carregar cores de paleta** caixa de diálogo Carregar paletas de cores especiais para usar em seu projeto de C++ com as seguintes propriedades:

|Propriedade|Descrição|
|-----------------|-----------------|
|**Examinar**|Especifica o local onde você deseja localizar um arquivo ou pasta.<br/><br/>Selecione a seta para escolher outro local, ou selecione o ícone de pasta na barra de ferramentas para mover para cima níveis.|
|**Nome do arquivo**|Fornece um espaço para você digitar o nome do arquivo que você deseja abrir.<br/><br/>Para localizar rapidamente um arquivo aberto anteriormente, selecione o nome do arquivo na lista suspensa, se disponível.<br/><br/>Se você estiver procurando por um arquivo, você pode usar asteriscos (*) como caracteres curinga. Por exemplo, você pode digitar \*.\* para ver uma lista de todos os arquivos. Você também pode digitar o caminho completo de um arquivo, por exemplo, *C:\My Documents\MyColorPalette.pal* ou  *\\\NetworkServer\MyFolder\MyColorPalette.pal*.|
|**Arquivos de tipo**|Lista os tipos de arquivos a serem exibidos.<br/><br/>Paleta (*. PAL) é o tipo de arquivo padrão para paletas de cores.|

## <a name="how-to"></a>Como

### <a name="to-select-foreground-or-background-colors"></a>Para selecionar cores de primeiro plano ou segundo plano

Exceto para o **borracha**, ferramentas na **Editor de imagens** desenho de barra de ferramentas com a atual cor de primeiro plano ou segundo plano quando você pressiona o botão esquerdo ou direito do mouse, respectivamente.

- Para selecionar uma cor de primeiro plano, com o botão esquerdo do mouse, selecione a cor desejada na **cores** paleta.

- Para selecionar uma cor de plano de fundo, com o botão direito do mouse, selecione a cor desejada na **cores** paleta.

### <a name="to-fill-a-bounded-area-of-an-image-with-a-color"></a>Para preencher uma área limitada de uma imagem com uma cor

O **Editor de imagens** fornece o **preencher** colocados de ferramenta para o preenchimento de qualquer área de imagem com a cor de desenho atual ou a cor de plano de fundo atual.

### <a name="to-use-the-fill-tool"></a>Para usar a ferramenta de preenchimento

1. Use o **Editor de imagens** barra de ferramentas ou vá até o menu **imagem** > **ferramentas** e selecione o **preencher** ferramenta.

1. Se necessário, escolha as cores de desenho. No [paleta de cores](../windows/colors-window-image-editor-for-icons.md), selecione o botão esquerdo do mouse para selecionar uma cor de primeiro plano ou o botão direito do mouse para selecionar uma cor de plano de fundo.

1. Mover o **preenchimento** ferramenta para a área que você deseja preencher.

1. Selecione o botão esquerdo ou direito do mouse para preencher com a cor de primeiro plano ou a cor do plano de fundo, respectivamente.

### <a name="to-pick-up-a-color-from-an-image-to-use-elsewhere"></a>Para selecionar uma cor de uma imagem para usar em outro lugar

O **selecionar cor**, ou seleção de cor, ferramenta faz com qualquer cor na imagem a cor de primeiro plano atual ou a cor do plano de fundo, dependendo se você pressionar a esquerda ou para o botão direito do mouse. Para cancelar a **selecionar cor** de ferramentas, escolha outra ferramenta.

1. Use o **Editor de imagens** barra de ferramentas ou vá até o menu **imagem** > **ferramentas** e selecione o **selecionar cor** ferramenta.

1. Selecione a cor que você deseja acompanhar a partir da imagem.

   > [!NOTE]
   > Depois que você selecionar uma cor, o **Editor de imagens** ferramenta reativa usadas mais recentemente.

1. Desenhe usando o botão esquerdo do mouse para a cor de primeiro plano ou o botão direito do mouse para a cor do plano de fundo.

### <a name="to-choose-the-background"></a>Para escolher o plano de fundo

Quando você mover ou copia uma seleção de uma imagem, os pixels da seleção que correspondem à cor do plano de fundo atual são, por padrão, de modo transparente e eles não ocultam pixels no local de destino.

Você pode alternar de um plano de fundo transparente (o padrão) para um plano de fundo opaco e vice-versa. Quando você usa uma ferramenta de seleção, o **plano de fundo transparente** e **tela de fundo opaca** opções aparecem no **opção** seletor do **doEditordeimagens** barra de ferramentas.

![Opções de plano de fundo &#45; opaca ou transparente](../windows/media/vcimageeditoropaqtranspback.gif "opções de plano de fundo &#45; opaca ou transparente")<br/>
**Opções de transparentes e opacas** sobre o **barra de ferramentas do Editor de imagens**

#### <a name="to-switch-between-a-transparent-and-opaque-background"></a>Para alternar entre um plano de fundo transparente e opaco

No **Editor de imagens** barra de ferramentas, selecione a **opção** seletor e, em seguida, escolha o plano de fundo apropriado:

- **Tela de fundo opaca (O)**: Imagem existente é obscurecida por todas as partes da seleção.

- **Plano de fundo transparente (T)**: Mostra a imagem existente por meio de partes da seleção que correspondem à cor do plano de fundo atual.

> [!TIP]
> Para um atalho, sobre o **imagem** menu, marque ou desmarque **desenho opaco**.

Você pode alterar a cor do plano de fundo enquanto uma seleção já estiver em vigor para alterar quais partes da imagem são transparentes.

### <a name="to-invert-the-colors-in-a-selection"></a>Para inverter as cores em uma seleção

O **Editor de imagens** fornece uma maneira conveniente de Inverter cores na parte da imagem selecionada para que você possa fazer como uma imagem apareceria com cores invertidas.

Para inverter cores na seleção atual, acesse o menu **imagem** > **Inverter cores**.

### <a name="to-customize-or-change-colors-on-the-colors-palette"></a>Para personalizar ou alterar as cores na paleta de cores

1. Vá ao menu **imagem** > **ajustar cores**.

1. No **seletor de cores personalizada** diálogo caixa, defina a cor, digitando valores RGB ou HSL nas caixas de texto apropriado ou escolha uma cor na **exibição em cores gradiente** caixa.

1. Defina a luminosidade movendo o controle deslizante **luminosidade** barra.

1. Número de cores personalizada é pontilhada. Se você quiser a cor sólida mais próxima a cor pontilhada, clique duas vezes o **cor** caixa.

   Se você decidir que quer a cor pontilhada, mova o controle deslizante **luminosidade** barra ou mover a mira na **exibição de cor gradiente** novamente para restaurar o pontilhado.

1. Selecione **Okey** para adicionar a nova cor.

### <a name="to-save-a-custom-colors-palette"></a>Para salvar uma paleta de cores personalizadas

1. Vá ao menu **imagem** > **Salvar paleta**.

1. Navegue até o diretório onde você deseja salvar a paleta e digite um nome para a paleta.

1. Selecione **Salvar**.

### <a name="to-load-a-custom-colors-palette"></a>Para carregar uma paleta de cores personalizadas

1. Vá ao menu **imagem** > **carregar paleta**.

1. No **carregar paleta de cores** caixa de diálogo caixa, navegue até o diretório correto e selecione a paleta que você deseja carregar. **Cor** paletas são salvos com uma extensão de arquivo. PAL.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Editor de imagens para ícones](../windows/image-editor-for-icons.md)<br/>
[Como: Criar um ícone ou outra imagem](../windows/creating-an-icon-or-other-image-image-editor-for-icons.md)<br/>
[Como: Editar uma imagem](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md)<br/>
[Como: Usar uma ferramenta de desenho](../windows/using-a-drawing-tool-image-editor-for-icons.md)<br/>
[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
