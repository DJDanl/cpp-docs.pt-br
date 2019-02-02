---
title: Barra de ferramentas (Editor de C++ imagens para ícones)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.bitmap
- vc.editors.icon
- vc.editors.texttool
helpviewer_keywords:
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
ms.assetid: a0af4209-6273-4106-a7c1-0edecc9b5755
ms.openlocfilehash: dfbd721afd997f3151b1c20a7e0e1fb60e0c83e4
ms.sourcegitcommit: efcc8c97570ddf7631570226c700e8f6ebb6c7be
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/01/2019
ms.locfileid: "55560316"
---
# <a name="toolbar-c-image-editor-for-icons"></a>Barra de ferramentas (Editor de C++ imagens para ícones)

O **Editor de imagens** barra de ferramentas contém ferramentas para desenho, pintura, inserir texto, apagar e manipulação de exibições. Ele também contém um seletor de opção, com a qual você pode selecionar opções para usar cada ferramenta. Por exemplo, você pode escolher entre várias larguras de pincel, fatores de ampliação e estilos de linha.

> [!NOTE]
> Todas as ferramentas disponíveis na **Editor de imagens** barra de ferramentas também estão disponíveis na **imagem** menu (sob o **ferramentas** comando).

![Barra de ferramentas do Editor de imagens](../mfc/media/vcimageeditortoolbar.gif "vcImageEditorToolbar") barra de ferramentas do Editor de imagens

Para usar o **Editor de imagens** barra de ferramentas e **opção** seletor, selecione a ferramenta ou opção que você deseja.

> [!TIP]
> Dicas de ferramenta aparecem quando você passa o cursor sobre um botão de barra de ferramentas. Estas dicas podem ajudá-lo a identificar a função de cada botão.

Com o **opção** seletor, você pode especificar a largura de uma linha, o pincelada e muito mais. O ícone na **opção** alterações de botão de seletor, dependendo de qual ferramenta você selecionou.

![Desenho de&#45;seletor de forma na barra de ferramentas do Editor de imagens](../mfc/media/vcimageeditortoolbaroptionselector.gif "vcImageEditorToolbarOptionSelector") seletor de opção na barra de ferramentas do Editor de imagens

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="use-the-text-tool-dialog-box"></a>Use a caixa de diálogo Ferramenta de texto

Use o **ferramenta de texto** caixa de diálogo para adicionar texto a um recurso de cursor, bitmap ou ícone.

Para acessar essa caixa de diálogo, abra o [Editor de imagens](../windows/window-panes-image-editor-for-icons.md). Selecione **ferramentas** da **imagem** menu e, em seguida, selecione o **ferramenta de texto** comando.

### <a name="font-button"></a>Botão de fonte

Abre o **da fonte de dados da ferramenta texto** caixa de diálogo, na qual você pode alterar a fonte, estilo ou tamanho da fonte do cursor. As alterações são aplicadas ao texto exibido na **texto** área.

Para acessar essa caixa de diálogo, selecione a **Font** botão na **ferramenta texto** caixa de diálogo. As propriedades disponíveis são:

|Propriedade|Descrição|
|---|---|
|**Fonte**|Lista as fontes disponíveis.|
|**Estilo da fonte**|Lista os estilos disponíveis para a fonte especificada.|
|**Size**|Lista os tamanhos de ponto disponíveis para a fonte especificada.|
|**Amostra**|Mostra um exemplo de como o texto será exibido com as configurações de fonte especificada.|
|**script**|Lista os scripts de linguagem disponíveis para a fonte especificada. Quando você seleciona um script de idioma diferente, o conjunto de caracteres desse idioma ficará disponível para a criação de documentos multilíngues.|

#### <a name="to-change-the-font-of-text-on-an-image"></a>Para alterar a fonte do texto em uma imagem

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

### <a name="text-area"></a>Área de texto

Exibe o texto que aparece como parte do recurso. Inicialmente, essa área está vazia.

> [!NOTE]
> Se **plano de fundo transparente** for definido, somente o texto será colocado na imagem. Se **tela de fundo opaca** estiver definido, um retângulo delimitador, preenchido com as [cor do plano de fundo](../windows/selecting-foreground-or-background-colors-image-editor-for-icons.md), será colocado atrás do texto. Para obter mais informações, consulte [escolhendo opaco e planos de fundo transparentes](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md).

Clique duas vezes no **ferramenta de texto** caixa de diálogo para acessar um menu de atalho padrão que contém uma lista de comandos do Windows padrão.

## <a name="to-display-or-hide-the-image-editor-toolbar"></a>Para exibir ou ocultar a barra de ferramentas do Editor de imagens

Uma vez que muitas das ferramentas de desenho estão disponíveis na [teclado](../windows/accelerator-keys-image-editor-for-icons.md), às vezes é útil ocultar o **Editor de imagens** barra de ferramentas.

Sobre o **modo de exibição** menu, selecione **barras de ferramentas** , em seguida, escolha **Editor de imagens**.

   > [!NOTE]
   > Elementos nessa barra de ferramentas serão exibida não está disponíveis quando um arquivo de imagem do projeto atual ou a solução não está aberto na **Editor de imagens**. Ver [criando um ícone ou outra imagem](../windows/creating-an-icon-or-other-image-image-editor-for-icons.md), para obter informações sobre como adicionar arquivos de imagem aos seus projetos.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Janela cores](../windows/colors-window-image-editor-for-icons.md)<br/>
[Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)<br/>
[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>