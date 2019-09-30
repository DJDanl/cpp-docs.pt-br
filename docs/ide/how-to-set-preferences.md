---
title: Definir suas C++ preferências de codificação no Visual Studio
ms.description: Customize C++ formatting, colors, layout, line numbers, menus and more in the Visual Studio IDE.
ms.topic: overview
ms.date: 09/27/2019
ms.openlocfilehash: 90c9f39135b90a2c5015861a78dd8760b9a8aeed
ms.sourcegitcommit: 1e6386be9084f70def7b3b8b4bab319a117102b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2019
ms.locfileid: "71686883"
---
# <a name="set-your-c-coding-preferences-in-visual-studio"></a>Definir suas C++ preferências de codificação no Visual Studio

Você pode tornar sua C++ experiência de codificação mais conveniente, produtiva e pleasurable por meio da personalização do Visual Studio. Você pode personalizar os menus e as barras de ferramentas, organizar o layout da janela, definir temas C++ de cor, especificar regras de formatação, incluindo vários tipos de ClangFormat e criar atalhos de teclado personalizados. Você pode sincronizar suas preferências em vários computadores e criar e armazenar vários conjuntos de preferências e compartilhá-los com os colegas de equipe. Você pode instalar extensões do Visual Studio Marketplace que fornecem comportamento personalizado adicional. Muitas dessas opções estão documentadas em [Personalizar o IDE do Visual Studio](/visualstudio/ide/personalizing-the-visual-studio-ide).

## <a name="arrange-window-layout"></a>Organizar layout da janela

Na janela do Visual Studio, o espaço é dividido no menu principal, na barra de ferramentas, no editor de código (ou na janela do documento) e no Windows de ferramentas (**Gerenciador de soluções**, **lista de erros**e assim por diante). Algumas janelas se sobrepõem na mesma posição. Por exemplo, **Gerenciador de soluções**, **modo de exibição de classe**, **modo de exibição de recursos**e **Source Control Explorer** todos compartilham a mesma posição padrão. Você alterna entre eles clicando nas guias na parte inferior do quadro. Para tornar duas ou mais dessas janelas visíveis ao mesmo tempo, basta arrastar uma delas por sua barra de título para uma nova posição. Você pode encaixá-lo em uma das bordas da janela principal do Visual Studio ou pode esfloatá-lo. A ilustração a seguir mostra a janela **Team Explorer** no processo de ser arrastada de sua posição padrão para uma nova posição encaixada no lado esquerdo do editor de código. A área sombreada azul mostra onde a janela será colocada quando o botão do mouse for liberado.

![Modificando layout da janela](media/window-layout-move-team-explorer.png)

Na janela do documento, cada arquivo aberto está contido em um quadro com guias. Você pode flutuar ou bloquear essas guias exatamente como janelas de ferramentas. Para obter mais informações, consulte [Personalização de layouts de janela no Visual Studio](/visualstudio/ide/customizing-window-layouts-in-visual-studio).

Para ocultar todas as janelas de ferramentas e maximizar a janela do editor de códigos, pressione **Alt** + **Shift** + **Enter** para alternar o *modo de tela inteira*.

## <a name="set-c-coding-styles-and-formatting"></a>Definir C++ estilos e formatação de codificação

Você pode especificar muitas opções de formatação de código individuais, como recuo e posições de chave, navegando até **ferramentas** > **Opções** > **Editor de texto** > **C/C++**  > **formatação** (ou tipo **Ctrl + Q** e pesquise "Formatting"). Como alternativa, você pode especificar um dos estilos de [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html) (ou seu próprio estilo ClangFormat personalizado):

![Opções de ClangFormat](media/clang-format-ide.png)

Para obter mais informações sobre todas as opções de formatação, consulte [Opções, editor de textoC++, C/, formatação](/visualstudio/ide/reference/options-text-editor-c-cpp-formatting).

## <a name="set-the-color-theme"></a>Definir o tema de cores

Para definir um plano de fundo claro ou escuro, digite **Ctrl + Q** e procure "Color Theme". Você também pode chegar lá por meio das **ferramentas** > **opções**de**ambiente**  >  e escolher **tema de cores**:

![Temas de cor](media/tools-options-color-theme.png)

A imagem a seguir mostra o tema escuro:

![Tema escuro](media/tools-options-dark-theme.png)

## <a name="customize-code-colorization"></a>Personalizar a colorização de código

No Visual Studio 2019, você pode escolher entre três *esquemas de cores* predefinidos que especificam como os elementos de código são coloridos no editor. Para escolher um tema, navegue até **ferramentas** > **Opções** > **Editor de texto**@no__t-**5 CC++/**  > **Exibir** e escolha o **esquema de cores**:

![C++Esquemas de cores](media/color-schemes.png)

No esquema de cores do **Visual Studio 2017** , a maioria dos elementos de código é simplesmente preta. No esquema de cores **avançado** , as funções, as variáveis locais, as macros e outros elementos são colored. No **Enhanced (Globals vs. Members)** , as funções globais e as variáveis são coloridas para o contraste com os membros da classe. O modo padrão é **avançado** e tem a seguinte aparência:

![Esquema de cores avançado](media/color-scheme-enhanced.png)

Independentemente de qual tema ou esquema de cores estiver ativo, você poderá personalizar a fonte e as cores de elementos de código individuais navegando até **ferramentas** > **Opções** > **ambiente** > **fontes e cores** (ou tipo  **CTRL + Q** e Pesquisar por "fontes"). Role para baixo na lista de itens de exibição até ver C++ as opções:

![C++opções de fonte e cor](media/tools-options-cpp-colors.png)

As cores definidas aqui substituem os valores definidos para os esquemas de cores. Você precisará definir uma cor de volta como **padrão** se a tiver alterado, mas quiser usar as cores padrão para o esquema de cores.

## <a name="customize-the-toolbars"></a>Personalizar as barras de ferramentas

As barras de ferramentas fornecem uma maneira conveniente de emitir comandos com um único clique do mouse, em vez de usar os menus ou atalhos de teclado. O Visual Studio inclui um conjunto padrão de barras de ferramentas. Para o C++ desenvolvimento padrão, as barras de ferramentas mais úteis provavelmente são padrão, editor de texto, compilar, depurar, controle do código-fonte e, possivelmente, comparar arquivos. Para o desenvolvimento do Windows, o editor de caixa de diálogo e o editor de imagem são úteis para dispor caixas de diálogo e ícones de edição.

Focalize os ícones na barra de ferramentas para ver qual comando ele representa:

![QuickInfo da barra de ferramentas](media/toolbar-mouse-hover.png)

Você pode adicionar ou remover comandos ou criar uma barra de ferramentas personalizada clicando na seta para baixo. Para mover a barra de ferramentas para um novo local, arraste-a pela barra pontilhada à esquerda:

![Personalizar ou mover uma barra de ferramentas](media/toolbar-move-edit.png).

Para obter mais informações, confira [Como: Personalize menus e barras de ferramentas no Visual Studio @ no__t-0.

## <a name="show-or-hide-line-numbers"></a>Mostrar ou ocultar números de linha

Para especificar se os números de linha são mostrados à esquerda das janelas do editor, navegue até e marque ou desmarque os **números de linha**:

![Os números de linha](media/tools-options-line-numbers.png)

## <a name="create-keyboard-shortcuts"></a>Criar atalhos de teclado

Todos os comandos no Visual Studio podem ser feitos com atalhos de teclado usando várias combinações de chaves com as teclas CTRL, ALT e Shift. Você pode criar seus próprios atalhos navegando até **ferramentas** > **Opções** > **ambiente** > **teclado** (ou digite **Ctrl + Q** e pesquise por "atalhos"). Para obter mais informações, consulte [identificar e personalizar atalhos de teclado no Visual Studio](/visualstudio/ide/identifying-and-customizing-keyboard-shortcuts-in-visual-studio).
