---
title: Definir suas C++ preferências de codificação no Visual Studio
ms.description: Customize C++ formatting, colors, layout, line numbers, and menus in the Visual Studio IDE.
ms.topic: overview
ms.date: 09/27/2019
ms.openlocfilehash: f1d222dc38720ea897cfbf2fb9fa0dd2727e7720
ms.sourcegitcommit: 4517932a67bbf2db16cfb122d3bef57a43696242
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/02/2019
ms.locfileid: "71816568"
---
# <a name="set-your-c-coding-preferences-in-visual-studio"></a>Definir suas C++ preferências de codificação no Visual Studio

Você pode tornar sua C++ experiência de codificação mais conveniente, produtiva e pleasurable por meio da personalização do Visual Studio. Você pode:

- Personalize os menus e as barras de ferramentas.
- Organizar o layout da janela.
- Definir temas de cor.
- Especifique C++ regras de formatação, incluindo vários estilos de ClangFormat.
- Crie atalhos de teclado personalizados.

Você pode sincronizar suas preferências em vários computadores e criar e armazenar vários conjuntos de preferências e compartilhá-los com os colegas de equipe. Você pode instalar extensões do Visual Studio Marketplace, fornecendo opções adicionais para personalizar o comportamento. Para obter mais informações, confira [Personalizar o IDE do Visual Studio](/visualstudio/ide/personalizing-the-visual-studio-ide).

## <a name="arrange-window-layout"></a>Organizar layout da janela

Na janela do Visual Studio, o espaço é dividido no menu principal, na barra de ferramentas, no editor de código (ou na janela do documento) e no Windows de ferramentas (como Gerenciador de Soluções e Lista de Erros). Algumas janelas se sobrepõem na mesma posição. Por exemplo, Gerenciador de Soluções, Modo de Exibição de Classe, Modo de Exibição de Recursos e Source Control Explorer todos compartilham a mesma posição padrão. Você alterna entre eles selecionando as guias na parte inferior do quadro. Para tornar duas ou mais dessas janelas visíveis ao mesmo tempo, basta arrastar uma delas por sua barra de título para uma nova posição. Você pode encaixá-lo em uma das bordas da janela principal do Visual Studio ou pode esfloatá-lo.

A captura de tela a seguir mostra a janela **Team Explorer** que está sendo arrastada de sua posição padrão para uma nova posição encaixada no lado esquerdo do editor de código. A área sombreada azul mostra onde a janela será colocada quando o botão do mouse for liberado.

![Captura de tela da janela de Team Explorer do Visual Studio, com alteração de layout realçada](media/window-layout-move-team-explorer.png)

Na janela do documento, cada arquivo aberto está contido em um quadro com guias. Você pode flutuar ou bloquear essas guias, exatamente como janelas de ferramentas. Para obter mais informações, consulte [Personalização de layouts de janela no Visual Studio](/visualstudio/ide/customizing-window-layouts-in-visual-studio).

Para ocultar todas as janelas de ferramentas e maximizar a janela do editor de códigos, pressione **Alt** + **Shift** + **Enter** para alternar o *modo de tela inteira*.

## <a name="set-c-coding-styles-and-formatting"></a>Definir C++ estilos e formatação de codificação

Você pode especificar muitas opções de formatação de código individuais, como recuo e posições de chave. Para fazer isso, vá para **ferramentas** > **Opções** > **Editor de texto**@no__t-**5 CC++/**  > **formatação** (ou digite **Ctrl + Q** e procure "formatação"). Como alternativa, você pode especificar um dos estilos de [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html) (ou seu próprio estilo ClangFormat personalizado).

![Captura de tela das opções de ClangFormat](media/clang-format-ide.png)

Para obter mais informações sobre todas as opções de formatação, consulte [Opções, editor de textoC++, C/, formatação](/visualstudio/ide/reference/options-text-editor-c-cpp-formatting).

## <a name="set-the-color-theme"></a>Definir o tema de cores

Para definir um plano de fundo claro ou escuro, digite **Ctrl + Q** e procure "Color Theme". Você também pode encontrá-los indo para **ferramentas** > **Opções** > **ambiente**e escolhendo **tema de cores**.

![Captura de tela de temas de cor](media/tools-options-color-theme.png)

Por exemplo, aqui está o tema escuro:

![Captura de tela do Visual Studio com tema de cor escura](media/tools-options-dark-theme.png)

## <a name="customize-code-colorization"></a>Personalizar a colorização de código

No Visual Studio 2019, você pode escolher entre três *esquemas de cores*predefinidos. Eles especificam como os elementos de código são coloridos no editor. Para escolher um tema, vá para **ferramentas** > **Opções** > **Editor de texto**@no__t-**5 CC++/**  > **exibição**e escolha **esquema de cores**:

![Captura de C++ tela das opções de esquema de cores, com realce avançado](media/color-schemes.png)

No esquema de cores chamado **Visual Studio 2017**, a maioria dos elementos de código é simplesmente preta. No esquema de cores **avançado** , as funções, as variáveis locais, as macros e outros elementos são colored. No **Enhanced (Globals vs. Members)** , as funções globais e as variáveis são coloridas para o contraste com os membros da classe. O modo padrão é **avançado**e tem esta aparência:

![Captura de tela do esquema de cores avançado](media/color-scheme-enhanced.png)

Independentemente de qual tema ou esquema de cores estiver ativo, você poderá personalizar a fonte e as cores para elementos de código individuais. Para fazer isso, vá para **ferramentas** > **Opções** > **ambiente** > **fontes e cores** (ou digite **Ctrl + Q** e pesquise por "fontes"). Role a lista de itens de exibição até ver as C++ opções.

![Captura de C++ tela das opções de fonte e cor](media/tools-options-cpp-colors.png)

As cores definidas aqui substituem os valores definidos para os esquemas de cores. Se você quiser voltar às cores padrão do esquema de cores, defina uma cor de volta como **padrão**.

## <a name="customize-the-toolbars"></a>Personalizar as barras de ferramentas

As barras de ferramentas fornecem uma maneira conveniente de emitir comandos com um único clique, em vez de usar os menus ou atalhos de teclado. O Visual Studio inclui um conjunto padrão de barras de ferramentas. Para o C++ desenvolvimento padrão, as barras de ferramentas mais úteis são provavelmente padrão, editor de texto, compilar, depurar, controle do código-fonte e comparar arquivos. Para o desenvolvimento do Windows, o editor de caixa de diálogo e o editor de imagem são úteis para dispor caixas de diálogo e ícones de edição.

Focalize os ícones na barra de ferramentas para ver qual comando ele representa:

![Captura de tela de ícones de barra de ferramentas, com exemplo de informações de comando disponíveis ao focalizar](media/toolbar-mouse-hover.png)

Você pode adicionar ou remover comandos ou criar uma barra de ferramentas personalizada selecionando a seta para baixo. Para mover a barra de ferramentas para um novo local, arraste-a pela barra pontilhada à esquerda.

![Captura de tela da barra de ferramentas, com seta para baixo e barra pontilhada realçada](media/toolbar-move-edit.png).

Para obter mais informações, confira [Como: Personalize menus e barras de ferramentas no Visual Studio @ no__t-0.

## <a name="show-or-hide-line-numbers"></a>Mostrar ou ocultar números de linha

Você pode especificar se os números de linha são mostrados à esquerda das janelas do editor. Em **Opções**, em **C/C++** , selecione **geral**. Na seção **configurações** , marque ou desmarque **números de linha**, dependendo de sua preferência.

![Captura de tela das opções gerais, com números de linha realçados](media/tools-options-line-numbers.png)

## <a name="create-keyboard-shortcuts"></a>Criar atalhos de teclado

Muitos comandos no Visual Studio têm *atalhos de teclado*, combinações de teclas com as teclas CTRL, ALT e Shift. Você pode modificar esses atalhos de teclado ou criar novos próprios no Visual Studio. Vá para **ferramentas** > **Opções** > **ambiente** > **teclado** (ou digite **Ctrl + Q** e procure "atalhos"). Para obter mais informações, consulte [identificar e personalizar atalhos de teclado no Visual Studio](/visualstudio/ide/identifying-and-customizing-keyboard-shortcuts-in-visual-studio).
