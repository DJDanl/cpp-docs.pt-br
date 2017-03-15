---
title: "C&#243;digo de grava&#231;&#227;o e de refatora&#231;&#227;o (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 56ffb9e9-514f-41f4-a3cf-fd9ce2daf3b6
caps.latest.revision: 6
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# C&#243;digo de grava&#231;&#227;o e de refatora&#231;&#227;o (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O editor de códigos do Visual C\+\+ e o IDE fornecem muitos recursos de codificação.  Algumas são exclusivas para C\+\+ e alguns são essencialmente as mesmas para todos os idiomas do Visual Studio.  Opções para habilitar e configurar esses recursos estão localizadas na caixa de diálogo Editor de texto avançado de C\+\+ \(**Ferramentas &#124; Opções &#124; Editor de texto &#124; C\/C\+\+ &#124; Advanced**ou digite "C\+\+ Avançado"**início rápido**\).  Depois de escolher a opção que você deseja definir, você pode obter mais Ajuda pressionando**F1**quando a caixa de diálogo estiver em foco.  Para as opções de formatação de código geral, digite`Editor C++`em**QuickLaunch**.  
  
## Adicionar novo código  
 Depois de criar um projeto, você pode começar a codificar nos arquivos que foram gerados para você.  Para adicionar novos arquivos, clique com botão direito no nó do projeto no Solution Explorer e escolha**Adicionar &#124; Novo**.  
  
 Para definir opções de formatação como recuos, preenchimento de chaves e colorização, digite`formatação C++`para o**QuickLaunch**janela.  
  
### IntelliSense  
 IntelliSense é o nome de um conjunto de recursos que fornecem informações embutidas sobre sobrecargas de função, tipos e membros.  A ilustração a seguir mostra a lista de membros lista suspensa que aparece à medida que você digita.  Você pode pressionar a tecla tab para inserir o texto do item selecionado em seu arquivo de código.  
  
 ![C&#43;&#43; member list drop down](../ide/media/vs2015_cpp_statement_completion.png "vs2015\_cpp\_statement\_completion")  
  
 Para obter mais informações, consulte[Intellisense do Visual C\+\+](../Topic/Visual%20C++%20Intellisense.md).  
  
### Inserir trechos  
 Um trecho é uma parte predefinida do código\-fonte.  Clique em um único ponto ou no texto selecionado para inserir um trecho de código ou colocar o texto selecionado com o trecho de código.  A ilustração a seguir mostra as três etapas para colocar uma instrução selecionada com um loop for.  Os destaques amarelos na imagem final são campos editáveis que você acesse com a tecla tab.  Para obter mais informações, consulte[trechos de código](../Topic/Code%20Snippets.md).  
  
 ![Visual C&#43;&#43; Insert Snippet Drop&#45;down](../ide/media/vs2015_cpp_surround_with.png "vs2015\_cpp\_surround\_with")  
  
### Adicionar Classe  
 Adicionar uma nova classe de**projeto**menu usando o Assistente de classe.  
  
 ![Add New Class in Visual C&#43;&#43;](../Image/vs2015_cpp_add_class.png "vs2015\_cpp\_add\_class")  
  
### Assistente de classe  
 Modificar ou examinar uma classe existente ou adicione uma nova classe usando o Assistente de classe.  Para obter mais informações, consulte[adicionando funcionalidade com assistentes de código \(C\+\+\)](../ide/adding-functionality-with-code-wizards-cpp.md).  
  
 ![Visual C&#43;&#43; Class Wizard](../Image/vs2015_cpp_class_wizard.png "vs2015\_cpp\_class\_wizard")  
  
## Refatoração  
 Refatorações estão disponíveis sob o item de menu de contexto da ação rápida ou clicando em um[lâmpada](../Topic/Perform%20quick%20actions%20with%20light%20bulbs.md)no editor.  
  
### Renomear  
 Renomear um tipo ou função ou variável sempre que ele é usado no escopo especificado.  Na ilustração a seguir, o`Eat`método será renomeado como`Devour`na classe base e derivada.  
  
 ![Rename Dialog in Visual C&#43;&#43;](../ide/media/vss2015_cpp_rename.png "vss2015\_cpp\_rename")  
  
### Rápida de ação: Local de definição de movimentação  
 Mova uma ou mais definições de função para o arquivo de cabeçalho que tem o mesmo nome do arquivo de código.  Um novo cabeçalho será criado se ele ainda não existir.  As definições de resultante está \(ão\) embutido mostrado em uma janela de inspeção.  
  
 ![Move Definition in Visual C&#43;&#43;](../ide/media/vs2015_cpp_move_definition.png "vs2015\_cpp\_move\_definition")  
  
### Ação rápida: Criar declaração \/ definição  
 Crie uma ou mais definições no arquivo de código associado para os ções cabeçalho selecionado.  
  
 ![Visual C&#43;&#43; Create Definition option](../ide/media/vs2015_cpp_create_declaration.png "vs2015\_cpp\_create\_declaration")  
  
### Ação rápida: Implementar todos os puros virtuais para uma classe  
 Gere stubs de implementação vazia para todas as funções virtuais herdadas rapidamente em uma classe.  Para implementar apenas as funções virtuais em uma classe base específica, basta destacar a classe base na declaração da classe derivada.  
  
 ![Visual C&#43;&#43; Implement Virtuals Window](../ide/media/vs2015_cpp_implement_virtuals.png "vs2015\_cpp\_implement\_virtuals")  
  
### Converter em um literal de cadeia de caracteres bruta  
 Quando você coloca o cursor sobre uma cadeia de caracteres literal, você pode clique com botão direito e escolha**rápida ações &#124; Converter em um literal de cadeia de caracteres bruta**para converter uma cadeia de caracteres comum em um literal de cadeia bruto C\+\+ 11.  
  
 ![C&#43;&#43; refactor to a raw string literal](../ide/media/vs2015_cpp_raw_string_literal.png "vs2015\_cpp\_raw\_string\_literal")  
  
### Extrair a função \(extensão do Visual Studio\)  
 Use o recurso de função extract \(disponível como um[extensão na Galeria do Visual Studio](https://visualstudiogallery.msdn.microsoft.com/a081dc8c-c805-4589-9b8b-c2c309a05789)\) para mover uma seção de código em sua própria função e substitua o código com uma chamada para essa função.  
  
 ![Visual C&#43;&#43; Extract Function dialog](../Image/vs2015_cpp_extract_function.png "vs2015\_cpp\_extract\_function")  
  
## Navegue e entender  
  
### Inforapida  
 Passe o mouse sobre uma variável para ver as informações de tipo.  Inforapida  
  
 ![Visual C&#43;&#43; QuickInfo](../ide/media/vs2015_cpp_quickinfo.png "vs2015\_cpp\_quickInfo")  
  
### Documento aberto \(navegar até o cabeçalho\)  
 Clique com o botão direito no nome do cabeçalho em um`#include`diretiva e abra o arquivo de cabeçalho.  
  
 ![Visual C&#43;&#43; Open Document menu option](../ide/media/vs2015_cpp_open_document.png "vs2015\_cpp\_open\_document")  
  
### Inspecionar Definição  
 Passe o mouse sobre uma variável ou função declaração, com o botão direito, em seguida, escolha**inspecionar definição**para ver uma exibição embutida de sua definição.  Para obter mais informações, consulte[inspecionar definição \(Alt \+ F12\)](../Topic/How%20to:%20View%20and%20Edit%20Code%20by%20Using%20Peek%20Definition%20\(Alt+F12\).md).  
  
 ![Visual C&#43;&#43; Peek Definition](../ide/media/vs2015_cpp_peek_definition.png "vs2015\_cpp\_peek\_definition")  
  
### Ir para definição  
 Passe o mouse sobre uma variável ou função declaração, com o botão direito, em seguida, escolha**Go To Definition**para abrir o documento em que o objeto é definido.  
  
### Exibir Hierarquia de Chamada  
 Clique com o botão direito em qualquer chamada de função e exibir uma lista de Recursive de todas as funções que ele chama e todas as funções que chamá\-lo.  Cada função na lista pode ser expandida da mesma maneira.  Para obter mais informações, consulte[Call Hierarchy](../Topic/Call%20Hierarchy.md).  
  
 ![Visual C&#43;&#43; Call Hierarchy](../Image/vs2015_cpp_call_hierarchy.png "vs2015\_cpp\_call\_hierarchy")  
  
### Alternar Cabeçalho\/Arquivo de Códigos  
 Com o botão direito e escolha Alternar cabeçalho \/ arquivo de código para alternar entre um arquivo de cabeçalho e seu arquivo de código associado.  
  
### Estrutura de tópicos  
 Clique duas vezes em um arquivo de código fonte e escolha**estrutura de tópicos**para recolher ou expandir as definições e\/ou regiões personalizadas para facilitar a procurar apenas as partes que lhe interessam.  Para obter mais informações, consulte[Estrutura de tópicos](../Topic/Outlining.md).  
  
 ![Visual C&#43;&#43; Outlining](../ide/media/vs2015_cpp_outlining.png "vs2015\_cpp\_outlining")  
  
### Modo de mapa da barra de rolagem  
 Modo de mapa do ScrollBar permite que você rapidamente role e procurar por meio de um arquivo de código sem realmente deixar seu local atual.  Ou clique em qualquer lugar no mapa de código para ir diretamente para esse local.  
  
 ![Code Map in Visual C&#43;&#43;](../ide/media/vs2015_cpp_code_map.png "vs2015\_cpp\_code\_map")  
  
### Gerar o gráfico de arquivos de inclusão  
 Clique com o botão direito em um arquivo de código no seu projeto e escolha**Gerar gráfico de arquivos de inclusão**para ver um gráfico dos quais arquivos são incluídos por outros arquivos.  
  
 ![Visual C&#43;&#43; graph of include files](../ide/media/vs2015_cpp_include_graph.png "vs2015\_cpp\_include\_graph")  
  
### F1 Ajuda  
 Coloque o cursor sobre ou imediatamente após qualquer tipo, a palavra\-chave ou a função e pressione F1 para ir diretamente para o tópico de referência relevante do MSDN.  F1 também funciona em itens na lista de erros e em muitas caixas de diálogo.  
  
### Início Rápido  
 Para navegar facilmente para qualquer janela ou uma ferramenta no Visual Studio, basta digite seu nome na janela de início rápido no canto superior direito da interface do usuário.  Filtre a lista de preenchimento automático à medida que você digita.  
  
 ![Visual Studio Quick Launch](../Image/vs2015_cpp_quick_launch.png "vs2015\_cpp\_quick\_launch")