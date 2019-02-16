---
title: Editor de imagens para ícones
ms.date: 10/17/2018
f1_keywords:
- vc.editors.cursor.F1
- vc.editors.icon.F1
- vc.editors.cursor
- vc.editors.bitmap.F1
- vc.editors.bitmap
- vc.editors.dialog.GridSettings
- vc.editors.gridsettings
- vc.editors.bitmap
- vc.editors.icon
- vc.editors.texttool
- vc.editors.bitmap
- vc.editors.icon
helpviewer_keywords:
- editors, images
- resource editors [C++], graphics
- Image editor [C++]
- resource editors [C++], Image editor
- Image menu
- Grid Settings dialog box [C++]
- Graphics toolbar
- Image editor [C++], toolbar
- Image editor [C++], Option selector
- Properties window
- Option selector, Image editor
- toolbars [C++], showing
- toolbars [C++], hiding
- text, adding to an image
- Text Tool dialog box [C++]
- Text Tool Font dialog box [C++]
- fonts, changing on an image
- text, on images
- graphics editor [C++]
- Image editor [C++], panes
- Image editor [C++], magnification
- grids, pixel
- pixel grid, Image editor
- Image editor [C++], pixel grid
- Image editor [C++], grid settings
- grid settings, Image editor
ms.assetid: 586d2b8b-0348-4883-a85d-1ff0ddbf14dd
ms.openlocfilehash: 48b363b7b9021042fe6242be70c74f0daeade0c2
ms.sourcegitcommit: 470de1337035dd33682d935b4b6c6d8b1bdb0bbb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/15/2019
ms.locfileid: "56320699"
---
# <a name="image-editor-for-icons"></a>Editor de imagens para ícones

Quando você clica em um arquivo de imagem (por exemplo,. ico,. bmp,. png) no Gerenciador de soluções, a imagem é aberto no Editor de imagens da mesma forma que arquivos de código aberto no Editor de códigos. Quando uma guia do Editor de imagem estiver ativa, você verá as barras de ferramentas com várias ferramentas para criar e editar imagens. Além de bitmaps, ícones e cursores, você pode editar imagens no formato GIF ou JPEG usando os comandos a **imagem** menu e as ferramentas na **Editor de imagens** barra de ferramentas.

Recursos gráficos são as imagens que você define para seu aplicativo. Você pode desenhar à mão livre ou desenhar usando formas. Você pode selecionar partes de uma imagem de edição, inversão ou redimensionamento, ou você pode criar um pincel personalizado de uma parte selecionada de uma imagem e desenhar com esse pincel. Você pode definir propriedades da imagem, salvar imagens em formatos diferentes e converter imagens de um formato para outro.

Além de criar novos recursos gráficos, você pode [importar imagens existentes](../windows/how-to-import-and-export-resources.md) para edição e, em seguida, adicioná-los ao seu projeto. Você também pode abrir e editar imagens que não fazem parte de um projeto para [edição de imagem autônoma](../windows/editing-an-image-outside-of-a-project-image-editor-for-icons.md).

> [!NOTE]
> Usando o **Editor de imagens**, você pode exibir imagens de 32 bits, mas você não pode editá-los.

Com o Editor de Imagens, é possível:

- [Trabalhar com cores](../windows/working-with-color-image-editor-for-icons.md)

- [Trabalhar com ícones e cursores: Recursos de imagem para exibir dispositivos](../windows/icons-and-cursors-image-resources-for-display-devices-image-editor-for-icons.md)

- [Usar teclas aceleradoras para comandos do Editor de imagens](../windows/accelerator-keys-image-editor-for-icons.md)

O **Editor de imagens** janela mostra dois modos de exibição de uma imagem, com uma barra de divisão que separa os dois painéis. Você pode arrastar a barra de divisão de um lado para o outro para alterar o tamanho relativo dos painéis. O painel ativo exibe uma borda de seleção.

O **Editor de imagens** janela pode ser ajustada para atender às suas necessidades e preferências. Você pode [alterar o fator de ampliação](../windows/changing-the-magnification-factor-image-editor-for-icons.md) e [exibir ou ocultar a grade de pixels](../windows/displaying-or-hiding-the-pixel-grid-image-editor-for-icons.md).

> [!NOTE]
> Usando o **Editor de imagens**, você pode exibir imagens de 32 bits, mas você não pode editá-los.

## <a name="image-menu"></a>Menu Imagem

O **imagem** menu, que é exibido apenas quando o **imagem** editor está ativo, tem comandos para edição de imagens, gerenciando paletas de cores e definindo **Editor de imagens** janela Opções. Além disso, os comandos para o uso de imagens de dispositivo estão disponíveis ao trabalhar com ícones e cursores.

|Comando|Descrição|
|---|---|
|**Inverter cores**|Inverte suas cores. Para obter mais informações, consulte [invertendo as cores em uma seleção](../windows/inverting-the-colors-in-a-selection-image-editor-for-icons.md).|
|**Inverter Horizontalmente**|Inverte a imagem ou seleção horizontalmente. Para obter mais informações, consulte [invertendo uma imagem](../windows/flipping-an-image-image-editor-for-icons.md).|
|**Inverter Verticalmente**|Inverte a imagem ou seleção verticalmente. Para obter mais informações, consulte [invertendo uma imagem](../windows/flipping-an-image-image-editor-for-icons.md).|
|**Girar 90 graus**|A imagem ou seleção gira 90 graus. Para obter mais informações, consulte [invertendo uma imagem](../windows/flipping-an-image-image-editor-for-icons.md).|
|**Mostrar janela de cores**|Abre o [janela de cores](../windows/colors-window-image-editor-for-icons.md), no qual você pode escolher as cores a ser usado para sua imagem. Para obter mais informações, consulte [trabalhando com cor](../windows/working-with-color-image-editor-for-icons.md).|
|**Usar seleção como Pincel**|Permite que você crie um pincel personalizado de uma parte de uma imagem. Sua seleção torna-se um pincel personalizado que distribui as cores na seleção entre a imagem. Cópias da seleção são deixadas ao longo do caminho de arrastamento. Quanto mais lentamente do que você arrastar, são feitas as cópias mais. Para obter mais informações, consulte [criando um pincel personalizado](../windows/creating-a-custom-brush-image-editor-for-icons.md).|
|**Cópia e a seleção de estrutura de tópicos**|Cria uma cópia da seleção atual e a contorna. Se a cor do plano de fundo estiver contida na seleção atual, ela será excluída se você já [transparente](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md) selecionado.
|**Ajustar cores**|Abre o [seletor de cores personalizada](../windows/custom-color-selector-dialog-box-image-editor-for-icons.md), que permite que você personalize as cores que você pode usar para sua imagem. Para obter mais informações, consulte [personalizando ou alterando cores](../windows/customizing-or-changing-colors-image-editor-for-icons.md).|
|**Carregar paleta**|Abre o [caixa de diálogo Carregar paleta de cores](../windows/load-palette-colors-dialog-box-image-editor-for-icons.md), que permite que você carregar cores de paleta salvas anteriormente para um arquivo. PAL.|
|**Salvar paleta**|Salva a paleta de cores em um arquivo. PAL.|
|**Desenhar opaco**|Quando selecionada, torna a seleção atual opaca. Quando desmarcada, torna transparente a seleção atual. Para obter mais informações, consulte [escolher um plano de fundo transparente ou um opaco](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md).|
|**Editor de barra de ferramentas**|Abre o [caixa de diálogo novo recurso da barra de ferramentas](../windows/new-toolbar-resource-dialog-box.md).|
|**Configurações da grade**|Abre o **configurações da grade** caixa de diálogo na qual você pode especificar grades para sua imagem.|
|**Novo tipo de imagem**|Abre o [New \<dispositivo > caixa de diálogo de tipo de imagem](../windows/new-device-image-type-dialog-box-image-editor-for-icons.md). Um recurso de ícone único pode conter várias imagens de tamanhos diferentes e windows podem usar o tamanho de ícone apropriado, dependendo de como ela será a ser exibido. Um novo tipo de dispositivo não modifica o tamanho do ícone, mas em vez disso, cria uma nova imagem dentro do ícone. Aplica-se somente a ícones e cursores.|
|**Tipo de imagem de ícone/Cursor atual**|Abre um submenu que lista os primeiro ícone ou cursor de imagens disponíveis (os primeiros nove). O último comando no submenu, **mais...** , abre o [aberto \<dispositivo > caixa de diálogo imagem](../windows/open-device-image-dialog-box-image-editor-for-icons.md).|
|**Excluir tipo de imagem**|Exclui a imagem do dispositivo selecionado.|
|**Ferramentas**|Inicia um submenu que contém todas as ferramentas disponíveis a partir de [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md).|

O **configurações da grade** caixa de diálogo permite que você especifique as configurações de grade para a sua imagem e exibe linhas de grade sobre a imagem editada. As linhas são úteis para a imagem de edição, mas não são salvas como parte da imagem em si.

|Propriedade|Descrição|
|---|---|
|**Grade de pixels**|Quando marcada, exibe uma grade em torno de cada pixel no editor de imagem. A grade aparece apenas em 4 × e resoluções mais altas.|
|**Grade lado a lado**|Quando selecionado, exibe uma grade de blocos de pixels no editor de imagens, especificado pelos valores de espaçamento da grade.|
|**Largura**|Especifica a largura de cada bloco lado a lado. Essa propriedade é útil ao desenhar bitmaps que contém várias imagens são organizadas em intervalos regulares.|
|**Altura**|Especifica a altura de cada bloco lado a lado. Essa propriedade é útil ao desenhar bitmaps que contém várias imagens são organizadas em intervalos regulares.|

## <a name="toolbar"></a>Barra de ferramentas

O **Editor de imagens** barra de ferramentas contém ferramentas para desenho, pintura, inserir texto, apagar e manipulação de exibições. Ele também contém um seletor de opção, com a qual você pode selecionar opções para usar cada ferramenta. Por exemplo, você pode escolher entre várias larguras de pincel, fatores de ampliação e estilos de linha.

> [!NOTE]
> Todas as ferramentas disponíveis na **Editor de imagens** barra de ferramentas também estão disponíveis na **imagem** menu (sob o **ferramentas** comando).

![Barra de ferramentas do Editor de imagens](../mfc/media/vcimageeditortoolbar.gif "vcImageEditorToolbar") barra de ferramentas do Editor de imagens

Para usar o **Editor de imagens** barra de ferramentas e **opção** seletor, selecione a ferramenta ou opção que você deseja.

> [!TIP]
> Dicas de ferramenta aparecem quando você passa o cursor sobre um botão de barra de ferramentas. Estas dicas podem ajudá-lo a identificar a função de cada botão.

Com o **opção** seletor, você pode especificar a largura de uma linha, o pincelada e muito mais. O ícone na **opção** alterações de botão de seletor, dependendo de qual ferramenta você selecionou.

![Desenho de&#45;seletor de forma na barra de ferramentas do Editor de imagens](../mfc/media/vcimageeditortoolbaroptionselector.gif "vcImageEditorToolbarOptionSelector") seletor de opção na barra de ferramentas do Editor de imagens

### <a name="use-the-text-tool-dialog-box"></a>Use a caixa de diálogo Ferramenta de texto

Use o **ferramenta de texto** caixa de diálogo para adicionar texto a um recurso de cursor, bitmap ou ícone.

Para acessar essa caixa de diálogo, abra o [Editor de imagens](../windows/window-panes-image-editor-for-icons.md). Selecione **ferramentas** da **imagem** menu e, em seguida, selecione o **ferramenta de texto** comando.

#### <a name="font-button"></a>Botão de fonte

Abre o **da fonte de dados da ferramenta texto** caixa de diálogo, na qual você pode alterar a fonte, estilo ou tamanho da fonte do cursor. As alterações são aplicadas ao texto exibido na **texto** área.

Para acessar essa caixa de diálogo, selecione a **Font** botão na **ferramenta texto** caixa de diálogo. As propriedades disponíveis são:

|Propriedade|Descrição|
|---|---|
|**Fonte**|Lista as fontes disponíveis.|
|**Estilo da fonte**|Lista os estilos disponíveis para a fonte especificada.|
|**Size**|Lista os tamanhos de ponto disponíveis para a fonte especificada.|
|**Amostra**|Mostra um exemplo de como o texto será exibido com as configurações de fonte especificada.|
|**script**|Lista os scripts de linguagem disponíveis para a fonte especificada. Quando você seleciona um script de idioma diferente, o conjunto de caracteres desse idioma ficará disponível para a criação de documentos multilíngues.|

Para alterar a fonte do texto em uma imagem:

O procedimento a seguir é um exemplo de como adicionar texto a um ícone em um aplicativo do Windows e manipular a fonte do texto.

1. Crie um aplicativo de formulários do Windows do C++. Para obter detalhes, consulte [criando um projeto de aplicativo do Windows](/previous-versions/visualstudio/visual-studio-2010/42wc9kk5). Uma *app.ico* arquivo é adicionado ao seu projeto por padrão.

1. Na **Gerenciador de soluções**, clique duas vezes no arquivo *app.ico*. O [Editor de imagens](../windows/image-editor-for-icons.md) será aberta.

1. Dos **imagem** menu, selecione **ferramentas** e, em seguida, selecione **ferramenta de texto**. O **ferramenta de texto** caixa de diálogo será exibida.

1. No **ferramenta de texto** caixa de diálogo, digite *C++* na área de texto vazio. Esse texto será exibido em uma caixa redimensionável localizada no canto superior esquerdo do *app.ico*, no **Editor de imagens**.

1. No **Editor de imagens**, arraste a caixa redimensionável para o centro do app.ico, para melhorar a legibilidade do texto.

1. No **ferramenta de texto** caixa de diálogo, selecione o **fonte** botão. O **da fonte de dados da ferramenta texto** caixa de diálogo será exibida.

1. No **fonte da ferramenta de texto** caixa de diálogo, selecione **Times New Roman** da lista de fontes disponíveis que estão listados no **fonte** caixa de listagem.

1. Selecione **Bold** na lista de estilos de fonte disponíveis listadas na **estilo da fonte** caixa de listagem.

1. Selecione **10** na lista de disponíveis de tamanhos listados no ponto de **tamanho** caixa de listagem.

1. Selecione o botão **OK**. O **da fonte de dados da ferramenta texto** caixa de diálogo será fechada e as novas configurações de fonte serão aplicada ao texto.

1. Selecione o **feche** botão a **ferramenta texto** caixa de diálogo. A caixa ao redor do texto de redimensionável desaparecerá dos **Editor de imagens**.

#### <a name="text-area"></a>Área de texto

Exibe o texto que aparece como parte do recurso. Inicialmente, essa área está vazia.

> [!NOTE]
> Se **plano de fundo transparente** for definido, somente o texto será colocado na imagem. Se **tela de fundo opaca** estiver definido, um retângulo delimitador, preenchido com as [cor do plano de fundo](../windows/selecting-foreground-or-background-colors-image-editor-for-icons.md), será colocado atrás do texto. Para obter mais informações, consulte [escolhendo opaco e planos de fundo transparentes](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md).

Clique duas vezes no **ferramenta de texto** caixa de diálogo para acessar um menu de atalho padrão que contém uma lista de comandos do Windows padrão.

### <a name="to-display-or-hide-the-image-editor-toolbar"></a>Para exibir ou ocultar a barra de ferramentas do Editor de imagens

Uma vez que muitas das ferramentas de desenho estão disponíveis na [teclado](../windows/accelerator-keys-image-editor-for-icons.md), às vezes é útil ocultar o **Editor de imagens** barra de ferramentas.

Sobre o **modo de exibição** menu, selecione **barras de ferramentas** , em seguida, escolha **Editor de imagens**.

   > [!NOTE]
   > Elementos nessa barra de ferramentas serão exibida não está disponíveis quando um arquivo de imagem do projeto atual ou a solução não está aberto na **Editor de imagens**. Ver [criando um ícone ou outra imagem](../windows/creating-an-icon-or-other-image-image-editor-for-icons.md), para obter informações sobre como adicionar arquivos de imagem aos seus projetos.

## <a name="window-panes"></a>Painéis Janela

O **Editor de imagens** janela normalmente exibe uma imagem em dois painéis separados por uma barra divisória. Um modo de exibição é o tamanho real e a outra é ampliada (o fator de ampliação padrão é 6). As exibições desses dois painéis são atualizadas automaticamente: as alterações feitas em um único painel imediatamente são mostradas no outro. Os dois painéis tornam fácil para você trabalhar em uma exibição ampliada da imagem, na qual você pode distinguir pixels individuais e, ao mesmo tempo, observar o efeito de seu trabalho no modo de exibição de tamanho real da imagem.

O painel esquerdo usa tanto espaço quanto for necessário (até metade dos **imagem** janela) para mostrar a exibição de ampliação 1:1 (o padrão) da sua imagem. O painel direito exibe a imagem ampliada (6:1 ampliação por padrão). Você pode alterar a ampliação em cada painel usando o **ampliar** ferramenta sobre o [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md) ou usando as teclas de aceleração.

Você pode ampliar o painel de menor do **Editor de imagens** janela e usar os dois painéis para mostrar diferentes regiões de uma imagem grande. Selecione dentro do painel para escolhê-lo.

Você pode alterar o tamanho relativo dos painéis de posicionando o ponteiro na barra de divisão e mover a barra de divisão para a direita ou esquerda. A barra de divisão pode mover todo o caminho para ambos os lados se você quiser trabalhar em somente um painel.

Se o **Editor de imagens** painel é ampliada por um fator de 4 ou superior, você pode exibir uma grade de pixels que delimita os pixels individuais na imagem.

### <a name="to-change-the-magnification-factor"></a>Para alterar o fator de ampliação

Por padrão, o **imagem** editor exibe o modo de exibição no painel esquerdo em tamanho real e o modo de exibição no painel direito, em 6 vezes o tamanho real. O fator de ampliação (visto na barra de status na parte inferior do espaço de trabalho) é a proporção entre o tamanho real da imagem e o tamanho exibido. O fator de padrão é 6 e o intervalo é de 1 a 10.

1. Selecione o **Editor de imagens** painel cujo fator de ampliação que você deseja alterar.

1. Sobre o [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md), selecione a seta à direita do [ferramenta ampliar](../windows/toolbar-image-editor-for-icons.md) e selecione o fator de ampliação do submenu: **1 X**, **2 X**, **6 X**, ou **8 X**.

   > [!NOTE]
   > Para selecionar um fator de ampliação diferente das listadas as **ampliar** ferramenta, use as teclas de aceleração.

### <a name="to-display-or-hide-the-pixel-grid"></a>Para exibir ou ocultar a grade de pixels

Para todos os **Editor de imagens** painéis com um fator de ampliação de 4 ou superior, você pode exibir uma grade que delimita os pixels individuais na imagem.

1. Sobre o **imagem** menu, selecione **configurações da grade**.

1. Selecione o **grade de pixels** caixa de seleção para exibir a grade, ou desmarque a caixa para ocultar a grade.

> [!TIP]
> Dicas de ferramenta aparecem quando você passa o cursor sobre um botão de barra de ferramentas. Estas dicas podem ajudá-lo a identificar a função de cada botão.

## <a name="visual-studio-image-library"></a>Biblioteca de Imagens do Visual Studio

Você pode fazer o download sem nenhum custo a **biblioteca de imagens do Visual Studio** que contém várias animações, bitmaps e ícones que você pode usar em seus aplicativos. Para obter mais informações sobre como baixar a biblioteca, consulte [a biblioteca de imagens do Visual Studio](/visualstudio/designers/the-visual-studio-image-library).

## <a name="managed-resources"></a>Recursos gerenciados

Você pode usar o **imagem** editor e o [editor binário](binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte a edição de recursos inseridos.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)<br/>
[Ícones](https://msdn.microsoft.com/library/windows/desktop/ms646973.aspx)