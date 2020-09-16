---
title: Ler e entender o código C++ no Visual Studio
description: Use o editor de código C++ no Visual Studio para formatar e entender o código.
ms.date: 05/28/2019
ms.openlocfilehash: 3da4224592cabd11e449fa4be395eba046c0e554
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90686123"
---
# <a name="read-and-understand-c-code-in-visual-studio"></a>Ler e entender o código C++ no Visual Studio

O editor de códigos e o IDE do Visual Studio fornecem muitos recursos de codificação. Alguns são exclusivos ao C++ e outros são essencialmente os mesmos para todas as linguagens Visual Studio. Para obter mais informações sobre as funcionalidades compartilhadas, confira [Escrevendo um código no Editor de Códigos e de Texto](/visualstudio/ide/writing-code-in-the-code-and-text-editor).  

## <a name="colorization"></a>Colorização

O Visual Studio colore elementos de sintaxe para diferenciar entre tipos de símbolos, como palavras-chave de linguagem, nomes de tipos, nomes de variáveis, parâmetros de função, literais de cadeia de caracteres e assim por diante.

![Colorização de código](../ide/media/code-outline-colorization.png "Colorização de C++")

O código não utilizado (como o código em um #if 0) tem uma cor mais esmaecida.

![Código inativo](../ide/media/inactive-code-cpp.png "Código inativo C++")

Personalize as cores digitando "Fontes" em **Início Rápido** e, em seguida, escolhendo **Fontes e Cores**. Na caixa de diálogo **Fontes e Cores**, role a página para baixo até as opções do C/C++ e, em seguida, escolha uma fonte e/ou uma cor personalizada.

## <a name="outlining"></a>Estrutura de tópicos

Clique com o botão direito do mouse em qualquer lugar em um arquivo de código-fonte e escolha **Estrutura de Tópicos** para recolher ou expandir blocos de código e/ou regiões personalizadas, a fim de facilitar a navegação apenas pelo código de seu interesse. Para obter mais informações, consulte [Estrutura de tópicos](/visualstudio/ide/outlining).

![Estrutura de tópicos do C&#43;&#43; ](../ide/media/vs2015_cpp_outlining.png "Estrutura de tópicos")

Quando você coloca o cursor na frente de uma chave, '{' ou '}', o editor realça seu equivalente correspondente.

Outras opções de estrutura de tópicos estão localizadas em **Editar**  >  **estrutura de tópicos** no menu principal.

## <a name="line-numbers"></a>Números de linha

Você pode adicionar números de linha ao seu projeto acessando **ferramentas**  >  **Opções**  >  **Editor de texto**  >  **todos os idiomas**  >  **geral** ou procurando por "número de linha" com **início rápido (Ctrl + Q)**. Os números de linha podem ser definidos para todas as linguagens ou para linguagens específicas, incluindo C++.

## <a name="scroll-and-zoom"></a>Rolar e aplicar zoom

Você pode ampliar ou reduzir a página no editor pressionando a tecla **Ctrl** e rolando a página com o botão de rolagem do mouse. Também é possível aplicar zoom usando a configuração de zoom no canto inferior esquerdo.

![Controle de zoom em C&#43;&#43; ](../ide/media/zoom-control.png "Controle de zoom")

O **Modo de Mapa** da barra de rolagem permite que você role a página e navegue por um arquivo de código rapidamente sem sair da localização atual. Clique em qualquer lugar no mapa de códigos para ir diretamente para essa localização.

![Mapa de códigos em C&#43;&#43;](../ide/media/vs2015-cpp-code-map.png "Mapa de Códigos")

Para ativar o **modo de mapa**, digite "mapa" na caixa de pesquisa **início rápido** na barra de ferramentas principal e escolha **usar modo de mapa de rolagem**. Para obter mais informações, confira [Como acompanhar o código personalizando a barra de rolagem](/visualstudio/ide/how-to-track-your-code-by-customizing-the-scrollbar).

Quando o **Modo de Mapa** estiver desativado, a barra de rolagem ainda realçará as alterações feitas no arquivo. A cor verde indica as alterações salvas e a cor amarela indica as alterações não salvas.

## <a name="quick-info-and-parameter-info"></a>Informações Rápidas e Informações de Parâmetro

Passe o mouse sobre qualquer variável, função ou outro símbolo para obter informações sobre ele, incluindo a declaração e os comentários localizados logo antes dela.

::: moniker range="vs-2019"

![Captura de tela mostrando o dica de ferramenta Informações Rápidas no Visual Studio 2019.](../ide/media/quick-info-vs2019.png "Informação Rápida")

A dica de ferramenta **Informações Rápidas** tem um link **Pesquisar Online**. Vá para **ferramentas**  >  **Opções**  >  **Editor de texto**  >  **C++**  >  **Exibir** para especificar o provedor de pesquisa.

Se houver um erro no código, passe o mouse sobre ele, e as **Informações Rápidas** exibirão a mensagem de erro. Encontre também a mensagem de erro na janela Lista de Erros.

![Informações rápidas sobre erro](../ide/media/quickinfo-on-error.png "Informações rápidas sobre erro")

::: moniker-end

::: moniker range="<=vs-2017"

![Captura de tela mostrando o dica de ferramenta Informações Rápidas no Visual Studio 2017.](../ide/media/quick-info.png "Informação Rápida")

Se houver um erro no código, passe o mouse sobre ele, e as **Informações Rápidas** exibirão a mensagem de erro. Encontre também a mensagem de erro na janela **Lista de Erros**.

![Informações rápidas sobre erro](../ide/media/quickinfo-on-error.png "Informações rápidas sobre erro")

::: moniker-end

Quando você chama uma função, a opção **Informações de Parâmetro** mostra os tipos de parâmetros e a ordem na qual eles são esperados.

![Informações de parâmetro em C&#43;&#43;](../ide/media/parameter-info.png "Informações de Parâmetro")

## <a name="peek-definition"></a>Inspecionar Definição

Passe o mouse sobre uma variável ou uma declaração da função, clique com o botão direito do mouse e, em seguida, escolha **Inspecionar Definição** para ver uma exibição embutida de sua definição sem sair da localização atual. Para obter mais informações, confira [Inspecionar Definição (Alt+F12)](/visualstudio/ide/how-to-view-and-edit-code-by-using-peek-definition-alt-plus-f12).

![C&#43;&#43; definição de Peek](../ide/media/vs2015_cpp_peek_definition.png "vs2015_cpp_peek_definition")

## <a name="f1-help"></a>Ajuda F1

Posicione o cursor sobre qualquer tipo, palavra-chave ou função ou imediatamente após eles e pressione **F1** para ir diretamente para o tópico de referência relevante em docs.microsoft.com. **F1** também funciona em itens da Lista de Erros e em muitas caixas de diálogo.

## <a name="class-view"></a>Exibição de Classe

O **Modo de Exibição de Classe** exibe um conjunto pesquisável de árvores de todos os símbolos de códigos e suas hierarquias de pai/filho e escopo, organizadas por projeto. Configure o que o **Modo de Exibição de Classe** exibe em **Configurações do Modo de Exibição de Classe** (clique no ícone da caixa de engrenagem na parte superior da janela).

![Modo de Exibição de Classe em C&#43;&#43;](../ide/media/class-view.png "Exibição de Classe")

## <a name="generate-graph-of-include-files"></a>Gerar grafo de arquivos de inclusão

Clique com o botão direito do mouse em um arquivo de código no projeto e escolha **Gerar grafo de arquivos de inclusão** para ver um grafo de quais arquivos são incluídos por outros arquivos.

![C&#43;&#43; grafo de arquivos de inclusão](../ide/media/vs2015_cpp_include_graph.png "vs2015_cpp_include_graph")

## <a name="view-call-hierarchy"></a>Exibir Hierarquia de Chamada

Clique com o botão direito do mouse em qualquer chamada de função e exiba uma lista recursiva de todas as funções chamadas por ela e de todas as funções que a chamam. Cada função na lista pode ser expandida da mesma maneira. Para obter mais informações, confira [Hierarquia de chamada](/visualstudio/ide/reference/call-hierarchy).

![C&#43;&#43; hierarquia de chamadas](../ide/media/vs2015_cpp_call_hierarchy.png "vs2015_cpp_call_hierarchy")

## <a name="see-also"></a>Consulte Também

[Editar e refatorar o código (C++)](writing-and-refactoring-code-cpp.md)</br>
[Navegar pela base de código C++ no Visual Studio](navigate-code-cpp.md)</br>
[Colaborar com o Live Share para C++](live-share-cpp.md)
