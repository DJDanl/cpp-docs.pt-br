---
title: Defina suas preferências de codificação C++ no Visual Studio
ms.description: Customize C++ formatting, colors, layout, line numbers, and menus in the Visual Studio IDE.
ms.topic: overview
ms.date: 09/27/2019
ms.openlocfilehash: e3a665ead7a314b343ec3320e95b189f83a38a47
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365383"
---
# <a name="set-your-c-coding-preferences-in-visual-studio"></a>Defina suas preferências de codificação C++ no Visual Studio

Você pode tornar sua experiência de codificação C++ mais conveniente, produtiva e prazerosa personalizando o Visual Studio. Você pode:

- Personalize os menus e as barras de ferramentas.
- Organize o layout da janela.
- Defina temas de cores.
- Especifique as regras de formatação C++, incluindo vários estilos de ClangFormat.
- Crie atalhos de teclado personalizados.

Você pode sincronizar suas preferências em várias máquinas e criar e armazenar vários conjuntos de preferências e compartilhá-las com colegas de equipe. Você pode instalar extensões do Visual Studio Marketplace, dando-lhe opções adicionais para personalizar o comportamento. Para obter mais informações, consulte [Personalizar o Visual Studio IDE](/visualstudio/ide/personalizing-the-visual-studio-ide).

## <a name="arrange-window-layout"></a>Organizar o layout da janela

Dentro da janela do Visual Studio, o espaço é dividido no menu principal, na barra de ferramentas, no editor de códigos (ou na janela do documento) e nas janelas das ferramentas (como O Explorador de Soluções e lista de erros). Algumas janelas se sobrepõem umas às outras na mesma posição. Por exemplo, o Solution Explorer, o Class View, o Resource View e o Source Control Explorer compartilham a mesma posição padrão. Você alterna entre eles selecionando as guias na parte inferior do quadro. Para tornar duas ou mais dessas janelas visíveis ao mesmo tempo, basta arrastar uma delas pela barra de título para uma nova posição. Você pode encaixá-lo contra uma das bordas da janela principal do Visual Studio, ou você pode flutuar.

A captura de tela a seguir mostra a janela **do Team Explorer** sendo arrastada de sua posição padrão para uma nova posição ancorada no lado esquerdo do editor de código. A área sombreada azul mostra onde a janela será colocada quando o botão do mouse for liberado.

![Captura de tela da janela Visual Studio Team Explorer, com mudança de layout destacada](media/window-layout-move-team-explorer.png)

Na janela do documento, cada arquivo aberto está contido em um quadro com guias. Você pode flutuar ou bloquear essas abas, assim como janelas de ferramentas. Para obter mais informações, consulte [Personalização de layouts de janela no Visual Studio](/visualstudio/ide/customizing-window-layouts-in-visual-studio).

Para ocultar todas as janelas da ferramenta e maximizar a janela do Editor de Código,**pressione** **Alt** + **Shift** + Enter para alternar o *modo de tela cheia*.

## <a name="set-c-coding-styles-and-formatting"></a>Definir estilos de codificação C++ e formatação

Você pode especificar muitas opções individuais de formatação de código, como posições de recuo e suporte. Para isso, vá para **Tools** > **Options** > **Text Editor** > **C/C++** > **Formatting** (ou digite **Ctrl + Q** e procure por "Formatação"). Alternativamente, você pode especificar um dos estilos [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html) (ou seu próprio estilo ClangFormat personalizado).

![Captura de tela das opções ClangFormat](media/clang-format-ide.png)

Para obter mais informações sobre todas as opções de formatação, consulte [Opções, Editor de Texto, C/C++, Formatação](/visualstudio/ide/reference/options-text-editor-c-cpp-formatting).

## <a name="set-the-color-theme"></a>Definir o tema de cores

Para definir um fundo claro ou escuro, digite **Ctrl + Q** e procure por "Tema de Cor". Você também pode encontrá-los indo para O**Ambiente****de Opções de** >  **Ferramentas** > e escolhendo **O Tema de Cores**.

![Captura de tela de temas de cores](media/tools-options-color-theme.png)

Por exemplo, aqui está o tema escuro:

![Captura de tela do Visual Studio com tema de cor escura](media/tools-options-dark-theme.png)

## <a name="customize-code-colorization"></a>Personalizar a coloração do código

No Visual Studio 2019, você pode escolher entre três *esquemas*de cores predefinidos . Estes especificam como os elementos de código são coloridos no editor. Para escolher um tema, vá para **Tools** > **Options** > **Text Editor** > **C/C++** > **View**e escolha Esquema **de cores**:

![Captura de tela das opções de Esquema de Cores C++, com destaque aprimorado](media/color-schemes.png)

No esquema de cores chamado **Visual Studio 2017**, a maioria dos elementos de código são simplesmente pretos. No esquema de cores **aprimorada,** funções, variáveis locais, macros e outros elementos são coloridos. No esquema **Enhanced (Globals vs. Members),** funções e variáveis globais são coloridas para contrastar com os membros da classe. O modo padrão é **Enhanced**, e ele se parece com isso:

![Captura de tela do esquema de cores aprimorado](media/color-scheme-enhanced.png)

Independentemente de qual tema ou esquema de cores esteja ativo, você pode personalizar a fonte e as cores para elementos de código individuais. Para isso, vá para **Ferramentas** > **Opções** > **De Ambiente** > **Fontes e Cores** (ou digite **Ctrl + Q** e procure por "Fontes"). Role a lista de itens de exibição até ver as opções C++.

![Captura de tela de opções de fonte e cores C++](media/tools-options-cpp-colors.png)

As cores que você define aqui sobrepõem os valores definidos para os esquemas de cores. Se você quiser voltar às cores padrão para o esquema de cores, defina uma cor de volta para **Padrão**.

## <a name="customize-the-toolbars"></a>Personalize as barras de ferramentas

As barras de ferramentas fornecem uma maneira conveniente de emitir comandos com um único clique, em vez de usar os menus ou atalhos de teclado. Visual Studio inclui um conjunto padrão de barras de ferramentas. Para o desenvolvimento padrão do C++, as barras de ferramentas mais úteis provavelmente são Standard, Text Editor, Build, Debug, Source Control e Compare Files. Para o desenvolvimento do Windows, o Editor de Diálogo e o Editor de Imagens são úteis para definir caixas de diálogo e ícones de edição.

Passar o tempo sobre os ícones na barra de ferramentas para ver qual comando ele representa:

![Captura de tela de ícones da barra de ferramentas, com exemplo de informações de comando disponíveis no hover](media/toolbar-mouse-hover.png)

Você pode adicionar ou remover comandos ou criar uma barra de ferramentas personalizada, selecionando a seta para baixo. Para mover a barra de ferramentas para um novo local, arraste-a pela barra pontilhada à esquerda.

![Captura de tela da barra de ferramentas, com seta baixa e barra pontilhada destacada](media/toolbar-move-edit.png).

Para obter mais informações, consulte [Como: Personalizar menus e barras de ferramentas no Visual Studio](/visualstudio/ide/how-to-customize-menus-and-toolbars-in-visual-studio).

## <a name="show-or-hide-line-numbers"></a>Mostrar ou ocultar números de linha

Você pode especificar se os números de linha são exibidos à esquerda das janelas do editor. Em **Opções,** em **C/C++,** selecione **Geral**. Na seção **Configurações,** selecione ou limpe **números de linha,** dependendo da sua preferência.

![Captura de tela das opções gerais, com números de linha destacados](media/tools-options-line-numbers.png)

## <a name="create-keyboard-shortcuts"></a>Criar atalhos de teclado

Muitos comandos no Visual Studio têm *atalhos de teclado,* combinações de teclas com as teclas Ctrl, Alt e Shift. Você pode modificar esses atalhos de teclado ou criar novos próprios no Visual Studio. Vá para **Ferramentas** > **Opções** > **De Ambiente Teclado** > **Keyboard** (ou **digite Ctrl + Q** e procure por "atalhos"). Para obter mais informações, consulte [Identificar e personalizar atalhos de teclado no Visual Studio](/visualstudio/ide/identifying-and-customizing-keyboard-shortcuts-in-visual-studio).
