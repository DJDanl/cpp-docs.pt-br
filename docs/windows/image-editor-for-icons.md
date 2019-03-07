---
title: Editor de imagens para ícones (C++)
ms.date: 02/15/2019
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
ms.openlocfilehash: 73fd4a8996bcfbaaf6fdd4018e524b66913d11cd
ms.sourcegitcommit: b4645761ce5acf8c2fc7a662334dd5a471ea976d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/07/2019
ms.locfileid: "57563076"
---
# <a name="image-editor-for-icons-c"></a>Editor de imagens para ícones (C++)

Quando você seleciona um arquivo de imagem (por exemplo,. ico,. bmp,. png) em **Gerenciador de soluções**, a imagem é aberto na **Editor de imagens** da mesma forma que arquivos de código aberto no **Editor de códigos** . Quando um **Editor de imagens** guia estiver ativa, você verá as barras de ferramentas com várias ferramentas para criar e editar imagens. Além de bitmaps, ícones e cursores, você pode editar imagens no formato GIF ou JPEG usando os comandos a **imagem** menu e as ferramentas na **Editor de imagens** barra de ferramentas.

Recursos gráficos são as imagens que você define para seu aplicativo. Você pode desenhar à mão livre ou desenhar usando formas. Você pode selecionar partes de uma imagem de edição, inversão ou redimensionamento, ou você pode criar um pincel personalizado de uma parte selecionada de uma imagem e desenhar com esse pincel. Você pode definir propriedades da imagem, salvar imagens em formatos diferentes e converter imagens de um formato para outro.

> [!NOTE]
> Usando o **Editor de imagens**, você pode exibir imagens de 32 bits, mas você não pode editá-los.

Você também pode usar o **Editor de imagens** e o [Editor binário](binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte a edição de recursos inseridos.

Além de criar novos recursos gráficos, você pode [importar imagens existentes](/windows/how-to-copy-resources#import-and-export-resources) para edição e, em seguida, adicioná-los ao seu projeto. Você também pode abrir e editar imagens que não fazem parte de um projeto para [edição de imagem autônoma](../windows/editing-an-image-outside-of-a-project-image-editor-for-icons.md).

Para obter informações sobre o **Editor de imagens**, consulte como [criar um ícone ou outra imagem](../windows/creating-an-icon-or-other-image-image-editor-for-icons.md), [editar uma imagem](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md), [usar uma ferramenta de desenho](../windows/using-a-drawing-tool-image-editor-for-icons.md), [Trabalhar com cores](../windows/working-with-color-image-editor-for-icons.md), e [teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md).

> [!NOTE]
> Download sem nenhum custo a **biblioteca de imagens do Visual Studio** que contém várias animações, bitmaps e ícones que você pode usar em seus aplicativos. Para obter mais informações sobre como baixar a biblioteca, consulte a [biblioteca de imagens do Visual Studio](/visualstudio/designers/the-visual-studio-image-library).

## <a name="image-menu"></a>Menu Imagem

O **imagem** menu, que é exibido apenas quando o **Editor de imagens** estiver ativa, tem comandos para edição de imagens, gerenciando paletas de cores e definindo **Editor de imagens** janela Opções. Além disso, os comandos para o uso de imagens de dispositivo estão disponíveis ao trabalhar com ícones e cursores.

|Comando|Descrição|
|---|---|
|**Inverter cores**|Inverte suas cores.|
|**Inverter Horizontalmente**|Inverte a imagem ou seleção horizontalmente.|
|**Inverter Verticalmente**|Inverte a imagem ou seleção verticalmente.|
|**Girar 90 graus**|A imagem ou seleção gira 90 graus.|
|**Mostrar janela de cores**|Abre o **cores** janela, em que você pode escolher as cores a ser usado para sua imagem.|
|**Usar seleção como Pincel**|Permite que você crie um pincel personalizado de uma parte de uma imagem.<br/><br/>Sua seleção torna-se um pincel personalizado que distribui as cores na seleção entre a imagem. Cópias da seleção são deixadas ao longo do caminho de arrastamento. Quanto mais lentamente do que você arrastar, são feitas as cópias mais.|
|**Cópia e a seleção de estrutura de tópicos**|Cria uma cópia da seleção atual e a contorna.<br/><br/>Se a cor do plano de fundo estiver contida na seleção atual, ela será excluída se você tiver transparente selecionada.
|**Ajustar cores**|Abre o **seletor de cores personalizada**, que permite que você personalize as cores que você pode usar para sua imagem.|
|**Carregar paleta**|Abre o **carregar paleta de cores** caixa de diálogo que permite que você carregue as cores da paleta salvas anteriormente para um arquivo. PAL.|
|**Salvar paleta**|Salva a paleta de cores em um arquivo. PAL.|
|**Desenhar opaco**|Quando selecionada, torna a seleção atual opaca.<br/><br/>Quando desmarcada, torna transparente a seleção atual.|
|**Editor de barra de ferramentas**|Abre o [caixa de diálogo novo recurso da barra de ferramentas](../windows/new-toolbar-resource-dialog-box.md).|
|**Configurações da grade**|Abre o **configurações da grade** caixa de diálogo na qual você pode especificar grades para sua imagem.|
|**Novo tipo de imagem**|Abre o [New \<dispositivo > caixa de diálogo de tipo de imagem](../windows/new-device-image-type-dialog-box-image-editor-for-icons.md).<br/><br/>Um recurso de ícone único pode conter várias imagens de tamanhos diferentes e windows podem usar o tamanho de ícone apropriado, dependendo de como ela será a ser exibido. Um novo tipo de dispositivo não modifica o tamanho do ícone, mas em vez disso, cria uma nova imagem dentro do ícone. Aplica-se somente a ícones e cursores.|
|**Tipo de imagem de ícone/Cursor atual**|Abre um submenu que lista as imagens de ícone ou cursor disponíveis nove primeiros. O último comando no submenu, **mais**, abre o [abra \<dispositivo > caixa de diálogo imagem](../windows/open-device-image-dialog-box-image-editor-for-icons.md).|
|**Excluir tipo de imagem**|Exclui a imagem do dispositivo selecionado.|
|**Ferramentas**|Inicia um submenu que contém todas as ferramentas disponíveis a partir de **Editor de imagens** barra de ferramentas.|

O **configurações da grade** caixa de diálogo permite que você especifique as configurações de grade para a sua imagem e exibe linhas de grade sobre a imagem editada. As linhas são úteis para a imagem de edição, mas não são salvas como parte da imagem em si.

|Propriedade|Descrição|
|---|---|
|**Grade de pixels**|Quando marcada, exibe uma grade em torno de cada pixel a **Editor de imagens**.<br/><br/>A grade aparece apenas em 4 × e resoluções mais altas.|
|**Grade lado a lado**|Quando selecionado, exibe uma grade de blocos de pixels a **Editor de imagens**, especificado pelos valores de espaçamento da grade.|
|**Largura**|Especifica a largura de cada bloco lado a lado.<br/><br/>Essa propriedade é útil ao desenhar bitmaps que contém várias imagens são organizadas em intervalos regulares.|
|**Altura**|Especifica a altura de cada bloco lado a lado.<br/><br/>Essa propriedade é útil ao desenhar bitmaps que contém várias imagens são organizadas em intervalos regulares.|

## <a name="toolbar"></a>Barra de ferramentas

O **Editor de imagens** barra de ferramentas contém ferramentas para desenho, pintura, inserir texto, apagar e manipulação de exibições. Ele também contém um seletor de opção, com a qual você pode selecionar opções para usar cada ferramenta. Por exemplo, você pode escolher entre várias larguras de pincel, fatores de ampliação e estilos de linha.

Disponível em todas as ferramentas, o **Editor de imagens** barra de ferramentas também estão disponíveis no menu **imagem** > **ferramentas**. Para usar o **Editor de imagens** barra de ferramentas e **opção** seletor, selecione a ferramenta ou opção que você deseja.

![Barra de ferramentas do Editor de imagens](../mfc/media/vcimageeditortoolbar.gif "vcImageEditorToolbar")<br/>
**Editor de imagens** barra de ferramentas

> [!TIP]
> Dicas de ferramenta aparecem quando você passa o cursor sobre um botão de barra de ferramentas. Estas dicas podem ajudá-lo a identificar a função de cada botão.

Uma vez que muitas das ferramentas de desenho estão disponíveis na [teclado](../windows/accelerator-keys-image-editor-for-icons.md), às vezes é útil ocultar o **Editor de imagens** barra de ferramentas.

- Para exibir ou ocultar a **Editor de imagens** barra de ferramentas, vá ao menu **exibição** > **barras de ferramentas** e escolha **Editor de imagens**.

> [!NOTE]
> Elementos nessa barra de ferramentas serão exibida não está disponíveis quando um arquivo de imagem do projeto atual ou a solução não estiver aberta na **Editor de imagens**.

### <a name="option-selector"></a>Seletor de opção

Com o **opção** seletor, você pode especificar a largura de uma linha, o pincelada e muito mais. O ícone na **opção** alterações de botão de seletor, dependendo de qual ferramenta você selecionou.

![Desenho de&#45;seletor de forma na barra de ferramentas do Editor de imagens](../mfc/media/vcimageeditortoolbaroptionselector.gif "vcImageEditorToolbarOptionSelector")<br/>
**Opção** seletor do **Editor de imagens** barra de ferramentas

### <a name="text-tool"></a>Ferramenta de texto

Use o **ferramenta de texto** caixa de diálogo para adicionar texto a um recurso de cursor, bitmap ou ícone.

Para acessar essa caixa de diálogo, abra o **Editor de imagens** e vá para o menu **imagem** > **ferramentas**, em seguida, selecione o **ferramenta texto** comando.

> [!TIP]
> Clique duas vezes no **ferramenta de texto** caixa de diálogo para acessar um menu de atalho padrão que contém uma lista de comandos do Windows padrão.

Abra o **da fonte de dados da ferramenta texto** caixa de diálogo para alterar a fonte, estilo ou tamanho da fonte do cursor. As alterações são aplicadas ao texto exibido na **texto** área.

Para acessar essa caixa de diálogo, selecione a **Font** botão na **ferramenta texto** caixa de diálogo. As propriedades disponíveis são:

|Propriedade|Descrição|
|---|---|
|**Fonte**|Lista as fontes disponíveis.|
|**Estilo da fonte**|Lista os estilos disponíveis para a fonte especificada.|
|**Size**|Lista os tamanhos de ponto disponíveis para a fonte especificada.|
|**Amostra**|Mostra um exemplo de como o texto será exibido com as configurações de fonte especificada.|
|**script**|Lista os scripts de linguagem disponíveis para a fonte especificada.<br/><br/>Quando você seleciona um script de idioma diferente, o conjunto de caracteres desse idioma ficará disponível para a criação de documentos multilíngues.|

#### <a name="to-change-the-font-of-text-on-an-image"></a>Para alterar a fonte do texto em uma imagem

Aqui está um exemplo de como adicionar texto a um ícone em um aplicativo do Windows e manipular a fonte do texto.

1. Crie um aplicativo de formulários do Windows do C++. Para obter detalhes, consulte [criando um projeto de aplicativo do Windows](/previous-versions/visualstudio/visual-studio-2010/42wc9kk5). Uma *app.ico* arquivo é adicionado ao seu projeto por padrão.

1. Na **Gerenciador de soluções**, clique duas vezes no arquivo *app.ico*. O **Editor de imagens** será aberta.

1. Vá ao menu **imagem** > **ferramentas** e selecione **ferramenta texto**.

1. No **ferramenta de texto** caixa de diálogo, digite *C++* na área de texto vazio. Esse texto será exibido em uma caixa redimensionável localizada no canto superior esquerdo do *app.ico* na **Editor de imagens**.

1. No **Editor de imagens**, arraste a caixa redimensionável para o centro da *app.ico* para melhorar a legibilidade do texto.

1. No **ferramenta de texto** caixa de diálogo, selecione o **fonte** botão.

1. No **da fonte de dados da ferramenta texto** caixa de diálogo:

   - Selecione **Times New Roman** na lista de fontes disponíveis que estão listados na **fonte** caixa de listagem.

   - Selecione **Bold** na lista de estilos de fonte disponíveis listadas na **estilo da fonte** caixa de listagem.

   - Selecione **10** na lista de disponíveis de tamanhos listados no ponto de **tamanho** caixa de listagem.

   - Escolha **OK**. O **da fonte de dados da ferramenta texto** caixa de diálogo será fechada e as novas configurações de fonte serão aplicada ao texto.

1. Escolha **feche** sobre o **ferramenta de texto** caixa de diálogo. A caixa ao redor do texto de redimensionável desaparecerá dos **Editor de imagens**.

A área de texto exibe o texto que aparece como parte do recurso. Inicialmente, essa área está vazia.

> [!NOTE]
> Se **plano de fundo transparente** for definido, somente o texto será colocado na imagem. Se **tela de fundo opaca** for definido, um retângulo delimitador, preenchido com a cor do plano de fundo, será colocado atrás do texto.

## <a name="window-panes"></a>Painéis Janela

O **Editor de imagens** janela mostra dois modos de exibição de uma imagem, com uma barra de divisão que separa os dois painéis. Você pode arrastar a barra de divisão de um lado para o outro para alterar o tamanho relativo dos painéis. O painel ativo exibe uma borda de seleção.

Um modo de exibição é o tamanho real e a outra é ampliada por um fator de ampliação de padrão de 6. As exibições desses dois painéis são atualizadas automaticamente, as alterações feitas em um único painel imediatamente são mostradas no outro. Os dois painéis tornam fácil para você trabalhar em uma exibição ampliada da imagem, na qual você pode distinguir pixels individuais e, ao mesmo tempo, observar o efeito de seu trabalho no modo de exibição de tamanho real da imagem.

O painel esquerdo usa tanto espaço quanto for necessário (até metade dos **imagem** janela) para exibir o modo de exibição padrão 1:1 ampliação da imagem. O painel direito exibe uma imagem ampliada de 6:1 ampliação padrão. Você pode alterar a ampliação em cada painel usando o **ampliar** ferramenta sobre o **Editor de imagens** barra de ferramentas ou usando as teclas de aceleração.

Você pode ampliar o painel de menor do **Editor de imagens** janela e usar os dois painéis para mostrar diferentes regiões de uma imagem grande. Selecione dentro do painel para escolhê-lo.

Você pode alterar o tamanho relativo dos painéis de posicionando o ponteiro na barra de divisão e mover a barra de divisão para a direita ou esquerda. A barra de divisão pode mover todo o caminho para ambos os lados se você quiser trabalhar em somente um painel.

Se o **Editor de imagens** painel é ampliada por um fator de 4 ou superior, você pode exibir uma grade de pixels que delimita os pixels individuais na imagem.

### <a name="to-change-the-magnification-factor"></a>Para alterar o fator de ampliação

Por padrão, o **Editor de imagens** exibe o modo de exibição no painel esquerdo em tamanho real e o modo de exibição no painel à direita em tamanho real de 6 vezes. O fator de ampliação (visto na barra de status na parte inferior do espaço de trabalho) é a proporção entre o tamanho real da imagem e o tamanho exibido. O fator de padrão é 6 e o intervalo é de 1 a 10.

1. Selecione o **Editor de imagens** painel cujo fator de ampliação que você deseja alterar.

1. Sobre o **Editor de imagens** barra de ferramentas, selecione a seta à direita do **ampliar** de ferramentas e selecione o fator de ampliação do submenu: **1 X**, **2 X**, **6 X**, ou **8 X**.

   > [!NOTE]
   > Para selecionar um fator de ampliação diferente das listadas as **ampliar** ferramenta, use as teclas de aceleração.

### <a name="to-display-or-hide-the-pixel-grid"></a>Para exibir ou ocultar a grade de pixels

Para todos os **Editor de imagens** painéis com um fator de ampliação de 4 ou superior, você pode exibir uma grade que delimita os pixels individuais na imagem.

1. Vá ao menu **imagem** > **configurações da grade**.

1. Selecione o **grade de pixels** caixa de seleção para exibir a grade, ou desmarque a caixa para ocultar a grade.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)<br/>

<!--[Icons](https://msdn.microsoft.com/library/windows/desktop/ms646973.aspx)-->