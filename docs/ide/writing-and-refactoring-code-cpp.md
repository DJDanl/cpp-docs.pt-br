---
title: Gravando e refatoração do código (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/27/2017
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 56ffb9e9-514f-41f4-a3cf-fd9ce2daf3b6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 02a028ddf5cbd4ac33f1ff9b148e7f20e5114c69
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="writing-and-refactoring-code-c"></a>Gravando e refatoração do código (C++)

O editor de códigos do Visual C++ e o IDE fornecem muitos recursos de codificação. Algumas são exclusivas para C++, e alguns são essencialmente as mesmas para todos os idiomas do Visual Studio. Para obter mais informações sobre os recursos compartilhados, consulte [escrevendo código no Editor de texto de código e](/visualstudio/ide/writing-code-in-the-code-and-text-editor). Opções para habilitar e configurar recursos específicos do C++ estão localizadas no [avançado do Editor de texto C++](/visualstudio/ide/reference/options-text-editor-c-cpp-advanced) caixa de diálogo (**ferramentas &#124; opções &#124; Editor de texto &#124; C/C++ &#124; avançado** ou digite "Avançadas do C++" **início rápido**). Depois de escolher a opção que você deseja definir, você pode obter mais Ajuda pressionando **F1** quando a caixa de diálogo estiver no foco. Para opções de formatação de código geral, digite `Editor C++` em **início rápido**.

Recursos experimentais, que podem ou não podem ser incluídos em uma versão futura do Visual Studio, encontram-se no [Editor de texto C++ Experimental](/visualstudio/ide/reference/options-text-editor-c-cpp-experimental) caixa de diálogo. No Visual Studio de 2017, você pode habilitar **Intellisense previsão** nesta caixa de diálogo.

## <a name="adding-new-code"></a>Adicionando novo código

Depois de criar um projeto, você pode iniciar a codificação nos arquivos que foram gerados para você. Para adicionar novos arquivos, clique com botão direito no nó do projeto no Gerenciador de soluções e escolha **adicionar &#124; novo**.

Para definir opções de formatação como recuos, conclusão de chave e colorização, digite `C++ Formatting` para o **início rápido** janela.

### <a name="intellisense"></a>IntelliSense

O IntelliSense é o nome de um conjunto de recursos que fornecem informações embutidas sobre sobrecargas de função, tipos e membros. A ilustração a seguir mostra a lista de membros suspensa aparece conforme você digita. Você pode pressionar a tecla tab para inserir o texto do item selecionado em seu arquivo de código.

![C&#43; &#43; membro lista suspensa](../ide/media/vs2015_cpp_statement_completion.png "vs2015_cpp_statement_completion")

Para obter mais informações, consulte [Visual C++ Intellisense](/visualstudio/ide/visual-cpp-intellisense).

### <a name="insert-snippets"></a>Inserir trechos de código

Um trecho de código é uma parte predefinida do código-fonte. Clique com botão direito em um único ponto ou no texto selecionado para inserir um trecho de código ou coloque o texto selecionado com o trecho de código. A ilustração a seguir mostra as três etapas para cercar uma instrução selecionada com um loop for. Os realces amarelos na imagem final são campos editáveis que você acessa com a tecla tab. Para obter mais informações, consulte [Trechos de Código](/visualstudio/ide/code-snippets).

![Visual C#&#43; &#43; Inserir trecho Drop&#45;para baixo](../ide/media/vs2015_cpp_surround_with.png "vs2015_cpp_surround_with")

### <a name="add-class"></a>Adicionar classe

Adicionar uma nova classe do **projeto** menu usando o Assistente de classe.

![Adicionar nova classe no Visual C#&#43;&#43;](../ide/media/vs2015_cpp_add_class.png "vs2015_cpp_add_class")

### <a name="class-wizard"></a>Assistente de classe

Modificar ou examinar uma classe existente ou adicionar uma nova classe usando o Assistente de classe. Para obter mais informações, consulte [adicionando funcionalidade com assistentes de código (C++)](../ide/adding-functionality-with-code-wizards-cpp.md).

![Visual C#&#43; &#43; classe assistente](../ide/media/vs2015_cpp_class_wizard.png "vs2015_cpp_class_wizard")

## <a name="refactoring"></a>Refatoração

Refatorações estão disponíveis no menu de contexto de ação rápida ou clicando em um [lâmpada](/visualstudio/ide/perform-quick-actions-with-light-bulbs) no editor.  Alguns também são encontradas no **Editar > refatorar** menu.  Esses recursos incluem:

* [Renomear](refactoring/rename.md)
* [Extrair função](refactoring/extract-function.md)
* [Implementar virtuais puras](refactoring/implement-pure-virtuals.md)
* [Criar declaração/definição](refactoring/create-declaration-definition.md)
* [Mover definição de função](refactoring/move-definition-location.md)
* [Converter para literal de cadeia de caracteres bruta](refactoring/convert-to-raw-string-literal.md)
* [Alterar assinatura](refactoring/change-signature.md)

## <a name="navigate-and-understand"></a>Navegue e entender

Visual C++ compartilha muitos recursos de navegação de código com outras linguagens. Para obter mais informações, consulte [navegando em código](/visualstudio/ide/navigating-code) e [exibindo a estrutura do código](/visualstudio/ide/viewing-the-structure-of-code).

### <a name="quickinfo"></a>QuickInfo

Passe o mouse sobre uma variável para ver as informações de tipo.

![Informações Rápidas do Visual C&#43;&#43;](../ide/media/vs2015_cpp_quickinfo.png "vs2015_cpp_quickInfo")

### <a name="open-document-navigate-to-header"></a>Documentos abertos (Navegue até o cabeçalho)

Clique com o botão direito no nome do cabeçalho em um `#include` diretiva e abra o arquivo de cabeçalho.

![Visual C#&#43; &#43; opção de menu Abrir documento](../ide/media/vs2015_cpp_open_document.png "vs2015_cpp_open_document")

### <a name="peek-definition"></a>Inspecionar Definição

Passe o mouse sobre uma variável ou função declaração, com o botão direito, em seguida, escolha **inspecionar definição** para ver uma exibição embutida de sua definição. Para obter mais informações, consulte [inspecionar definição (Alt + F12)](/visualstudio/ide/how-to-view-and-edit-code-by-using-peek-definition-alt-plus-f12).

![Visual C#&#43; &#43; inspecionar definição](../ide/media/vs2015_cpp_peek_definition.png "vs2015_cpp_peek_definition")

### <a name="go-to-definition"></a>Ir para definição

Passe o mouse sobre uma variável ou função declaração, com o botão direito, em seguida, escolha **ir para definição** para abrir o documento em que o objeto está definido.

### <a name="view-call-hierarchy"></a>Exibir Hierarquia de Chamada

Clique com o botão direito em qualquer chamada de função e exibir uma lista de resursive de todas as funções que ele chama e todas as funções que chamá-lo. Cada função na lista pode ser expandida da mesma maneira. Para obter mais informações, consulte [hierarquia de chamada](/visualstudio/ide/reference/call-hierarchy).

![Visual C#&#43; &#43; hierarquia de chamadas](../ide/media/vs2015_cpp_call_hierarchy.png "vs2015_cpp_call_hierarchy")

### <a name="toggle-header--code-file"></a>Alternar cabeçalho / arquivo de código

Clique com botão direito e escolha **alternar cabeçalho / arquivo de código** para alternar entre um arquivo de cabeçalho e seu arquivo de código associado.

### <a name="outlining"></a>Estrutura de tópicos

Clique em qualquer lugar em um arquivo de código fonte e escolha **estrutura de tópicos** para recolher ou expandir as definições de e/ou em regiões personalizadas para facilitar procurar apenas as partes que você está interessado. Para obter mais informações, consulte [Estrutura de tópicos](/visualstudio/ide/outlining).

![Visual C#&#43; &#43; de estrutura de tópicos](../ide/media/vs2015_cpp_outlining.png "vs2015_cpp_outlining")

### <a name="scroll-bar-map-mode"></a>Modo de mapa da barra de rolagem

Modo de mapa de barra de rolagem permite que você rapidamente role e procurar por meio de um arquivo de código sem realmente sair de seu local atual. Ou clique em qualquer lugar no mapa de código para ir diretamente para esse local.

![Código de mapa em Visual C#&#43;&#43;](../ide/media/vs2015_cpp_code_map.png "vs2015_cpp_code_map")

### <a name="generate-graph-of-include-files"></a>Gerar gráfico de inclusão de arquivos

Clique com o botão direito em um arquivo de código em seu projeto e escolha **gerar gráfico de inclusão de arquivos** para ver um gráfico dos quais arquivos são incluídos por outros arquivos.

![Visual C#&#43; &#43; gráfico de inclusão de arquivos](../ide/media/vs2015_cpp_include_graph.png "vs2015_cpp_include_graph")

### <a name="f1-help"></a>F1 Ajuda

Posicione o cursor sobre ou imediatamente após qualquer tipo, a palavra-chave ou a função e pressione F1 para ir diretamente para o tópico de referência do MSDN relevante. F1 também funciona em itens na lista de erros e muitas caixas de diálogo.

### <a name="quick-launch"></a>Início Rápido

Para navegar facilmente para qualquer janela ou a ferramenta no Visual Studio, basta digite seu nome na janela de início rápido no canto superior direito da interface do usuário. Filtra a lista de preenchimento automático conforme você digita.

![Início rápido do Visual Studio](../ide/media/vs2015_cpp_quick_launch.png "vs2015_cpp_quick_launch")
