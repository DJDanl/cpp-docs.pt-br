---
title: Editor de imagem para íconesC++()
ms.date: 02/15/2019
f1_keywords:
- vc.editors.cursor.F1
- vc.editors.icon.F1
- vc.editors.cursor
- vc.editors.bitmap.F1
- vc.editors.bitmap
- vc.editors.dialog.GridSettings
- vc.editors.gridsettings
- vc.editors.icon
- vc.editors.texttool
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
ms.openlocfilehash: 9c1c09f8ffe0ef8d4759b9242ba30e8fafaaeb01
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79443759"
---
# <a name="image-editor-for-icons-c"></a>Editor de imagem para íconesC++()

Quando você seleciona um arquivo de imagem (como. ico,. bmp,. png) no **Gerenciador de soluções**, a imagem é aberta no **Editor de imagem** da mesma maneira que os arquivos de código são abertos no **Editor de código**. Quando uma guia do **Editor de imagem** estiver ativa, você verá barras de ferramentas com muitas ferramentas para criar e editar imagens. Juntamente com bitmaps, ícones e cursores, você pode editar imagens no formato GIF ou JPEG usando comandos no menu **imagem** e ferramentas na barra de ferramentas do **Editor de imagem** .

Os recursos gráficos são as imagens que você define para seu aplicativo. Você pode desenhar à mão livre ou desenhar usando formas. Você pode selecionar partes de uma imagem para edição, inversão ou redimensionamento, ou pode criar um pincel personalizado de uma parte selecionada de uma imagem e desenhar com esse pincel. Você pode definir propriedades de imagem, salvar imagens em formatos diferentes e converter imagens de um formato para outro.

> [!NOTE]
> Usando o **Editor de imagem**, você pode exibir imagens de 32 bits, mas não pode editá-las.

Você também pode usar o **Editor de imagem** e o [Editor binário](binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos.

Além de criar novos recursos gráficos, você pode [importar imagens existentes](../windows/how-to-copy-resources.md#import-and-export-resources) para edição e, em seguida, adicioná-las ao seu projeto. Você também pode abrir e editar imagens que não fazem parte de um projeto para [edição de imagem](../windows/editing-an-image-outside-of-a-project-image-editor-for-icons.md)autônoma.

Para obter informações sobre o **Editor de imagem**, consulte como [criar um ícone ou outra imagem](../windows/creating-an-icon-or-other-image-image-editor-for-icons.md), [Editar uma imagem](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md), [usar uma ferramenta de desenho](../windows/using-a-drawing-tool-image-editor-for-icons.md), [trabalhar com cores](../windows/working-with-color-image-editor-for-icons.md)e [teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md).

> [!NOTE]
> Baixe sem custo a **biblioteca de imagens do Visual Studio** que contém várias animações, bitmaps e ícones que você pode usar em seus aplicativos. Para obter mais informações sobre como baixar a biblioteca, consulte a [biblioteca de imagens do Visual Studio](/visualstudio/designers/the-visual-studio-image-library).

## <a name="image-menu"></a>Menu Imagem

O menu **imagem** , que aparece somente quando o **Editor de imagem** está ativo, tem comandos para editar imagens, gerenciar paletas de cores e definir opções de janela do **Editor de imagem** . Além disso, os comandos para usar imagens de dispositivo estão disponíveis ao trabalhar com ícones e cursores.

|{1&gt;Comando&lt;1}|Descrição|
|---|---|
|**Inverter cores**|Inverte suas cores.|
|**Inverter Horizontalmente**|Inverte a imagem ou a seleção horizontalmente.|
|**Inverter Verticalmente**|Inverte a imagem ou a seleção verticalmente.|
|**Girar 90 graus**|Gira a imagem ou a seleção de 90 graus.|
|**Mostrar janela de cores**|Abre a janela **cores** , na qual você pode escolher as cores a serem usadas para a imagem.|
|**Usar seleção como pincel**|Permite que você crie um pincel personalizado de uma parte de uma imagem.<br/><br/>Sua seleção se torna um pincel personalizado que distribui as cores na seleção na imagem. As cópias da seleção são deixadas ao longo do caminho de arrasto. Quanto mais lentamente você arrastar, mais cópias serão feitas.|
|**Copiar e estruturar seleção**|Cria uma cópia da seleção atual e a descreve.<br/><br/>Se a cor do plano de fundo estiver contida na seleção atual, ela será excluída se você tiver selecionado transparentemente.
|**Ajustar cores**|Abre o **seletor de cores personalizado**, que permite que você personalize as cores usadas para a imagem.|
|**Carregar paleta**|Abre a caixa de diálogo da **paleta de cores de carregamento** , que permite carregar as cores da paleta salvas anteriormente em um arquivo. PAL.|
|**Salvar paleta**|Salva as cores da paleta em um arquivo. PAL.|
|**Desenho opaco**|Quando selecionado, torna a seleção atual opaca.<br/><br/>Quando desmarcada, torna a seleção atual transparente.|
|**Editor de barra de ferramentas**|Abre a [caixa de diálogo novo recurso de barra de ferramentas](../windows/new-toolbar-resource-dialog-box.md).|
|**Configurações de grade**|Abre a caixa de diálogo **configurações de grade** , na qual é possível especificar grades para a imagem.|
|**Novo tipo de imagem**|Abre a [caixa de diálogo novo tipo de imagem do dispositivo \<>](../windows/new-device-image-type-dialog-box-image-editor-for-icons.md).<br/><br/>Um único recurso de ícone pode conter várias imagens de tamanhos diferentes e o Windows pode usar o tamanho de ícone apropriado dependendo de como será exibido. Um novo tipo de dispositivo não modifica o tamanho do ícone, mas, em vez disso, cria uma nova imagem dentro do ícone. Aplica-se somente a ícones e cursores.|
|**Ícone atual/tipo de imagem do cursor**|Abre um submenu que lista as nove primeiras imagens de cursor ou ícone disponíveis. O último comando no submenu, **mais**, abre a [caixa de diálogo abrir \<dispositivo > imagem](../windows/open-device-image-dialog-box-image-editor-for-icons.md).|
|**Excluir tipo de imagem**|Exclui a imagem de dispositivo selecionada.|
|**Ferramentas**|Inicia um submenu que contém todas as ferramentas disponíveis na barra de ferramentas do **Editor de imagem** .|

A caixa de diálogo **configurações de grade** permite que você especifique as configurações de grade para a imagem e exibe linhas de grade sobre a imagem editada. As linhas são úteis para editar a imagem, mas não são salvas como parte da própria imagem.

|Propriedade|Descrição|
|---|---|
|**Grade de pixel**|Quando marcada, exibe uma grade em volta de cada pixel no **Editor de imagem**.<br/><br/>A grade aparece apenas a 4 × e resoluções superiores.|
|**Grade de blocos**|Quando selecionado, exibe uma grade em volta de blocos de pixels no **Editor de imagens**, especificado pelos valores de espaçamento da grade.|
|**Largura**|Especifica a largura de cada bloco de blocos.<br/><br/>Essa propriedade é útil ao desenhar bitmaps que contêm várias imagens que são organizadas em intervalos regulares.|
|**Altura**|Especifica a altura de cada bloco de blocos.<br/><br/>Essa propriedade é útil ao desenhar bitmaps que contêm várias imagens que são organizadas em intervalos regulares.|

## <a name="toolbar"></a>Barra de Ferramentas

A barra de ferramentas do **Editor de imagem** contém ferramentas para desenhar, pintar, inserir texto, apagar e manipular exibições. Ele também contém um seletor de opção, com o qual você pode selecionar opções para usar cada ferramenta. Por exemplo, você pode escolher entre várias larguras de pincel, fatores de ampliação e estilos de linha.

Todas as ferramentas disponíveis na barra de ferramentas do **Editor de imagens** também estão disponíveis na **imagem** do menu > **ferramentas**. Para usar a barra de ferramentas e o seletor de **Opções** do **Editor de imagem** , selecione a ferramenta ou a opção desejada.

![Barra de ferramentas do editor de imagem](../mfc/media/vcimageeditortoolbar.gif "vcImageEditorToolbar")<br/>
Barra de ferramentas do **Editor de imagem**

> [!TIP]
> As dicas de ferramenta são exibidas quando você passa o cursor do mouse sobre um botão da barra de ferramentas. Essas dicas podem ajudá-lo a identificar a função de cada botão.

Como muitas das ferramentas de desenho estão disponíveis no [teclado](../windows/accelerator-keys-image-editor-for-icons.md), às vezes é útil ocultar a barra de ferramentas do **Editor de imagem** .

- Para exibir ou ocultar a barra de ferramentas do **Editor de imagens** , vá até **modo de exibição** de menu > barras de **ferramentas** e escolha **Editor de imagem**.

> [!NOTE]
> Os elementos dessa barra de ferramentas aparecerão indisponíveis quando um arquivo de imagem do projeto ou da solução atual não estiver aberto no **Editor de imagem**.

### <a name="option-selector"></a>Seletor de opção

Com o seletor de **opção** , você pode especificar a largura de uma linha, um traço de pincel e muito mais. O ícone no botão seletor de **Opções** é alterado dependendo de qual ferramenta você selecionou.

![Seletor de forma de desenho&#45;na barra de ferramentas do editor de imagens](../mfc/media/vcimageeditortoolbaroptionselector.gif "vcImageEditorToolbarOptionSelector")<br/>
Seletor de **opção** na barra de ferramentas do **Editor de imagem**

### <a name="text-tool"></a>Ferramenta de texto

Use a caixa de diálogo **ferramenta de texto** para adicionar texto a um recurso de cursor, bitmap ou ícone.

Para acessar essa caixa de diálogo, abra o **Editor de imagem** e vá para o menu **imagem** > **ferramentas**e, em seguida, selecione o comando **ferramenta de texto** .

> [!TIP]
> Você pode clicar com o botão direito do mouse na caixa de diálogo **ferramenta de texto** para acessar um menu de atalho padrão que contém uma lista de comandos padrão do Windows.

Abra a caixa de diálogo **fonte da ferramenta de texto** para alterar a fonte, o estilo ou o tamanho da fonte do cursor. As alterações são aplicadas ao texto exibido na área de **texto** .

Para acessar essa caixa de diálogo, selecione o botão **fonte** na caixa de diálogo **ferramenta de texto** . As propriedades disponíveis são:

|Propriedade|Descrição|
|---|---|
|**Fonte**|Lista as fontes disponíveis.|
|**Estilo da fonte**|Lista os estilos disponíveis para a fonte especificada.|
|**Size**|Lista os tamanhos de pontos disponíveis para a fonte especificada.|
|**Amostra**|Mostra um exemplo de como o texto será exibido com as configurações de fonte especificadas.|
|**script**|Lista os scripts de idioma disponíveis para a fonte especificada.<br/><br/>Quando você seleciona um script de idioma diferente, o conjunto de caracteres para esse idioma fica disponível para a criação de documentos multilíngües.|

#### <a name="to-change-the-font-of-text-on-an-image"></a>Para alterar a fonte do texto em uma imagem

Aqui está um exemplo de como adicionar texto a um ícone em um aplicativo do Windows e manipular a fonte do seu texto.

1. Crie um C++ aplicativo Windows Forms. Para obter detalhes, consulte [como criar Windows Forms aplicativos](/previous-versions/visualstudio/visual-studio-2008/s69bf10x(v%3dvs.90)). Um arquivo *app. ico* é adicionado ao seu projeto por padrão.

1. Em **Gerenciador de soluções**, clique duas vezes no arquivo *app. ico*. O **Editor de imagem** será aberto.

1. Vá para o menu **imagem** > **ferramentas** e selecione **ferramenta de texto**.

1. Na caixa de diálogo **ferramenta de texto** , *C++* digite a área de texto vazia. Esse texto será exibido em uma caixa redimensionável localizada no canto superior esquerdo do *app. ico* no **Editor de imagem**.

1. No **Editor de imagem**, arraste a caixa redimensionável para o centro de *app. ico* para melhorar a legibilidade do seu texto.

1. Na caixa de diálogo **ferramenta de texto** , selecione o botão **fonte** .

1. Na caixa de diálogo **fonte da ferramenta de texto** :

   - Selecione **Times New Roman** na lista de fontes disponíveis listadas na caixa de listagem **fonte** .

   - Selecione **negrito** na lista de estilos de fonte disponíveis listados na caixa de listagem **estilo de fonte** .

   - Selecione **10** na lista de tamanhos de pontos disponíveis listados na caixa de listagem **tamanho** .

   - Escolha **OK**. A caixa de diálogo **fonte da ferramenta de texto** será fechada e as novas configurações de fonte serão aplicadas ao seu texto.

1. Escolha **fechar** na caixa de diálogo **ferramenta de texto** . A caixa redimensionável em volta do texto desaparecerá do **Editor de imagem**.

A área de texto exibe o texto que aparece como parte do recurso. Inicialmente, essa área está vazia.

> [!NOTE]
> Se o **plano de fundo transparente** estiver definido, somente o texto será colocado na imagem. Se o **plano de fundo opaco** for definido, um retângulo delimitador, preenchido com a cor do plano de fundo, será colocado atrás do texto.

## <a name="window-panes"></a>Painéis Janela

A janela do **Editor de imagens** mostra duas exibições de uma imagem, com uma barra de divisão separando os dois painéis. Você pode arrastar a barra de divisão de um lado para o outro para alterar o tamanho relativo dos painéis. O painel ativo exibe uma borda de seleção.

Uma exibição é o tamanho real e a outra é ampliada por um fator de ampliação padrão de 6. As exibições nesses dois painéis são atualizadas automaticamente, todas as alterações feitas em um painel são exibidas imediatamente no outro. Os dois painéis facilitam a tarefa de trabalhar em uma exibição ampliada da imagem, na qual você pode distinguir pixels individuais e, ao mesmo tempo, observar o efeito do seu trabalho na exibição de tamanho real da imagem.

O painel esquerdo usa o máximo de espaço necessário (até metade da janela de **imagem** ) para exibir a exibição de ampliação 1:1 padrão da imagem. O painel direito exibe uma imagem de ampliação de 6:1 com zoom padrão. Você pode alterar a ampliação em cada painel usando a ferramenta de **ampliação** na barra de ferramentas do **Editor de imagens** ou usando as teclas de aceleração.

Você pode ampliar o painel menor da janela do **Editor de imagem** e usar os dois painéis para mostrar regiões diferentes de uma imagem grande. Selecione dentro do painel para selecioná-lo.

Você pode alterar os tamanhos relativos dos painéis posicionando o ponteiro na barra de divisão e movendo a barra de divisão para a direita ou esquerda. A barra de divisão pode mover-se para cada lado se você quiser trabalhar em apenas um painel.

Se o painel do **Editor de imagem** for ampliado por um fator de 4 ou maior, você poderá exibir uma grade de pixels que delimite os pixels individuais na imagem.

### <a name="to-change-the-magnification-factor"></a>Para alterar o fator de ampliação

Por padrão, o **Editor de imagem** exibe a exibição no painel esquerdo em tamanho real e a exibição no painel direito em tamanho real de 6 vezes. O fator de ampliação (visto na barra de status na parte inferior do espaço de trabalho) é a razão entre o tamanho real da imagem e o tamanho exibido. O fator padrão é 6 e o intervalo é de 1 a 10.

1. Selecione o painel do **Editor de imagens** cujo fator de ampliação você deseja alterar.

1. Na barra de ferramentas do **Editor de imagem** , selecione a seta à direita da ferramenta de **ampliação** e selecione o fator de ampliação no submenu: **1x**, **2x**, **6 vezes**ou **8x**.

   > [!NOTE]
   > Para selecionar um fator de ampliação diferente daqueles listados na ferramenta de **ampliação** , use as teclas de aceleração.

### <a name="to-display-or-hide-the-pixel-grid"></a>Para exibir ou ocultar a grade de pixels

Para todos os painéis do **Editor de imagem** com um fator de ampliação de 4 ou superior, você pode exibir uma grade que delimita os pixels individuais na imagem.

1. Vá para a **imagem** do menu > **configurações da grade**.

1. Marque a caixa de seleção **grade de pixels** para exibir a grade ou desmarque a caixa para ocultar a grade.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

Nenhum

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)<br/>
[Ícones](/windows/win32/menurc/icons)