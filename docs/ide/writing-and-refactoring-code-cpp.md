---
title: Editar e refatorar o código C++ no Visual Studio
description: Use o editor de código C++ no Visual Studio para formatar, navegar, entender e refatorar seu código.
ms.date: 05/31/2019
ms.assetid: 56ffb9e9-514f-41f4-a3cf-fd9ce2daf3b6
ms.topic: overview
ms.openlocfilehash: da3f4e7d783561dba8250652a0715e51e71cc387
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79438154"
---
# <a name="edit-and-refactor-c-code-in-visual-studio"></a>Editar e refatorar o código C++ no Visual Studio

O Visual Studio fornece várias ferramentas para ajudá-lo a escrever, editar e refatorar o código.

##  <a name="intellisense"></a>IntelliSense

O IntelliSense é uma ferramenta eficiente de preenchimento de código que sugere símbolos e snippets de código para você conforme você digita. O C++ IntelliSense no Visual Studio é executado em tempo real, analisando a base de código conforme você a atualiza e fornecendo recomendações. Conforme você digita mais caracteres, a lista de resultados recomendados é restringida.

![Lista suspensa de membros no C&#43;&#43;](../ide/media/cpp-statement-completion.png)

Alguns símbolos são omitidos automaticamente para ajudar a restringir os resultados. Por exemplo, ao acessar membros de um objeto de classe de fora da classe, você não poderá ver membros privados por padrão ou membros protegidos (se você não estiver no contexto de uma classe filho). Ajuste a filtragem usando os botões na parte inferior.

Depois de escolher o símbolo na lista suspensa, você pode completá-lo com **Tab**, **Inserir**ou um dos outros caracteres de confirmação (por padrão: `{ } [ ] ( ) . , : ; + - * / % & | ^ ! = ? @ # \`). Para adicionar ou remover caracteres dessa lista, pesquise "IntelliSense" em **Início Rápido** (Ctrl+Q) e escolha a opção **Editor de Texto > C/C++ > Avançado**. A opção **Caracteres de Confirmação da Lista de Membros** permite que você personalize a lista com as alterações desejadas.

A opção **Modo de Filtro da Lista de Membros** controla quais tipos de sugestões de preenchimento automático do IntelliSense são exibidos. Por padrão, ele está definido como **Difuso**. Em uma pesquisa difusa, se você tiver um símbolo chamado *MyAwesomeClass*, poderá digitar "MAC" e localizar a classe nas sugestões de preenchimento automático. O algoritmo difuso define um limite mínimo ao qual os símbolos precisam atender para serem mostrados na lista. A filtragem **inteligente** exibe todos os símbolos que contêm subcadeias de caracteres que correspondem ao que foi digitado. A filtragem de **prefixo** pesquisa cadeias de caracteres que começam com o que foi digitado.

Para obter mais informações sobre o C++ IntelliSense, confira [Visual C++ IntelliSense](/visualstudio/ide/visual-cpp-intellisense) e [Configurar um projeto C++ para o IntelliSense](/visualstudio/ide/visual-cpp-intellisense-configuration).

## <a name="intellicode"></a>IntelliCode

O IntelliCode é o IntelliSense assistido por IA. Ele coloca o candidato mais provável no início da lista de conclusão. As recomendações do IntelliCode são baseadas em milhares de projetos open-source no GitHub, cada um com mais de 100 estrelas. Quando combinada com o contexto do código, a lista de conclusão é adaptada para promover práticas comuns.

Ao escrever em C++, o IntelliCode ajudará durante o uso de bibliotecas populares, como a Biblioteca Padrão C++. O contexto do código é usado para fornecer as recomendações mais úteis primeiro. No exemplo a seguir, a função de membro `size` é comumente usada com a função `sort` e, portanto, ela é exibida no início da lista de resultados.

![IntelliCode&#43; &#43; C](../ide/media/intellicode-cpp.png "C++IntelliCode")

::: moniker range="vs-2019"

No Visual Studio 2019, o IntelliCode está disponível como um componente opcional na carga de trabalho **Desenvolvimento para desktop com C++** . Para verificar se o IntelliCode está ativo para o C++, acesse **Ferramentas** > **Opções** > **IntelliCode** > **Geral** e defina **Modelo base do C++** como **Habilitado**.

::: moniker-end

::: moniker range="vs-2017"

No Visual Studio 2017, o IntelliCode está disponível como uma extensão no Visual Studio Marketplace.

::: moniker-end

## <a name="predictive-intellisense-experimental"></a>IntelliSense Preditivo (experimental)

O **IntelliSense Preditivo** é um recurso experimental que usa o reconhecimento contextual para limitar o número de resultados exibidos na lista suspensa do IntelliSense. O algoritmo aplica a correspondência de tipos, de modo que ele mostre somente os resultados que correspondem ao tipo esperado. No caso mais simples, se você digitar `int x =` e invocar a lista suspensa do IntelliSense, verá apenas inteiros ou funções que retornam inteiros. Esse recurso está desativado por padrão porque ainda está em desenvolvimento. Ela funciona melhor com símbolos globais; ainda não há suporte para funções de membro. Você pode ativá-la digitando "Preditivo" em **Início Rápido** ou acessando **Ferramentas** > **Opções** > **Editor de Texto** > **C/C++**  > **Experimental** > **Habilitar IntelliSense Preditivo**.

Para substituir o **IntelliSense preditiva** e mostrar a lista mais longa, pressione **Ctrl + J**. Se o **IntelliSense preditiva** estiver ativado, invocar **Ctrl + J** removerá o filtro de previsão. Pressionar **Ctrl+J** novamente removerá o filtro de acessibilidade dos resultados da Lista de Membros quando relevante. O botão ([+]) na lista suspensa do IntelliSense faz a mesma coisa que **Ctrl + J**. Passe o mouse sobre o botão para ver as informações de dica de ferramenta sobre o que está sendo mostrado.

![C&#43; &#43; IntelliSense preditiva](../ide/media/predictive-intellisense-cpp.png "IntelliSense preditiva")

A captura de tela anterior mostra vários botões na lista suspensa. Eles habilitam filtros do IntelliSense para diferentes tipos de resultados:

- Variáveis e constantes
- {1&gt;Funções&lt;1}
- Tipos
- Macros
- Enums
- {1&gt;Namespaces&lt;1}

Um botão é exibido somente se ele é relevante para a sessão atual do IntelliSense. Normalmente, você não verá todos os botões ao mesmo tempo.

## <a name="template-intellisense"></a>IntelliSense de modelo

Quando o cursor estiver dentro de uma definição de modelo, uma **Barra de Modelo** será exibida, que permite fornecer argumentos de modelo de exemplo para o IntelliSense. 

![Modelo&#43; &#43; C o IntelliSense mostrar instanciações existentes](../ide/media/template-intellisense-cpp-1.png "Modelo IntelliSense mostrar instanciações existentes")

Clique no ícone **\<t >** para expandir/recolher a **barra de modelos**. Clique no ícone de lápis ou clique duas vezes na **Barra de Modelo** para abrir a janela **Editar**. 

![IntelliSense&#43; &#43; do modelo C](../ide/media/template-intellisense-cpp-3.png "IntelliSense de modelo")

As edições feitas na janela são aplicadas diretamente ao código-fonte, para que você possa ver os efeitos em tempo real. 

A Barra de Modelo pode preencher candidatos automaticamente com base nas instanciações no código. Clique em **Adicionar Todas as Instanciações Existentes** para ver uma lista de todos os argumentos concretos que foram usados para criar uma instância do modelo em toda a base de código.

![Lista&#43; &#43; de resultados do IntelliSense do modelo C](../ide/media/template-intellisense-cpp-2.png "Lista de resultados do IntelliSense de modelo")

Uma janela na parte inferior do editor mostra o local em que cada instanciação foi encontrada e quais eram os argumentos.

![Mapa&#43; &#43; de instanciação do IntelliSense do modelo C](../ide/media/template-intellisense-cpp-4.png "Mapa de instanciação do IntelliSense de modelo")

As informações da **Barra de Modelo** são tratadas como específicas do usuário. Elas são armazenadas na pasta .vs e não são confirmadas no controle do código-fonte.

##  <a name="error-squiggles-and-quick-fixes"></a>Rabiscos de erro e correções rápidas

Se o editor detectar problemas com o código, ele adicionará rabiscos coloridos sob o problema. Rabiscos vermelhos indicam um código que não será compilado. Rabiscos verdes indicam outros tipos de problemas que podem ser graves. Abra a janela **Lista de Erros** para obter mais informações sobre os problemas.

Para alguns tipos de erros, bem como padrões de codificação comuns, o editor oferecerá uma **Correção Rápida** na forma de uma lâmpada que é exibida quando você focaliza o rabisco. Clique na seta para baixo para ver as sugestões. 

No exemplo a seguir, um `vector` foi declarado, mas nenhuma definição foi encontrada e, portanto, o editor oferece a inclusão do arquivo de cabeçalho necessário:

![Correção&#43; &#43; rápida C](../ide/media/quick-fix-for-header-cpp.png "C++Correção rápida")

O editor também oferece Correções Rápidas para algumas oportunidades de refatoração. Por exemplo, se você declarar uma classe em um arquivo de cabeçalho, o Visual Studio oferecerá a criação de uma definição para ele em um arquivo .cpp separado. 

![Correção&#43; &#43; rápida C](../ide/media/quick-fix.png "C++Correção rápida")

## <a name="change-tracking"></a>Change tracking

Sempre que você fizer uma alteração em um arquivo, uma barra amarela será exibida à esquerda para indicar que alterações não salvas foram feitas. Quando você salvar o arquivo, a barra ficará verde. As barras verde e amarela serão preservadas, desde que o documento esteja aberto no editor. Elas representam as alterações feitas desde que você abriu o documento pela última vez.

![Controle&#43; &#43; de alterações C](../ide/media/change-tracking-cpp.png "Change tracking")

## <a name="move-code"></a>Mover o código

Você pode mover as linhas de código para cima e para baixo selecionando-as, mantendo pressionada a tecla Alt e pressionando as teclas de direção **Para Cima/Para Baixo**.

##  <a name="insert-snippets"></a>Inserir snippets

Um snippet é uma parte predefinida do código-fonte. Clique com o botão direito do mouse em um único ponto ou no texto selecionado para inserir um snippet ou colocar o texto selecionado entre o snippet. A ilustração a seguir mostra as três etapas para colocar uma instrução selecionada entre um loop for. Os realces em amarelo na imagem final são campos editáveis acessados com a tecla TAB. Para obter mais informações, consulte [Snippets de Código](/visualstudio/ide/code-snippets).

![Menu&#43; &#43; suspenso&#45;de inserção de trecho de C](../ide/media/vs2015_cpp_surround_with.png "vs2015_cpp_surround_with")

##  <a name="add-class"></a>Adicionar Classe

Adicione uma nova classe por meio do menu **Projeto** ou do menu de contexto em **Gerenciador de Soluções**:

![Adicionar nova classe em C&#43;&#43;](../ide/media/vs2017-add-class.png "vs2015_cpp_add_class")

Use também o Assistente de Classe para modificar ou examinar uma classe existente.

![Assistente de Classe do C&#43;&#43;](../ide/media/vs2017-class-wizard.png)

Para obter mais informações, confira [Adicionando funcionalidade com assistentes de código (C++)](../ide/adding-functionality-with-code-wizards-cpp.md).

##  <a name="refactoring"></a>Refatoração

As refatorações estão disponíveis no menu de contexto de Ação Rápida ou clicando em uma [lâmpada](/visualstudio/ide/perform-quick-actions-with-light-bulbs) no editor.  Algumas também são encontradas no menu **Editar > Refatorar**.  Esses recursos incluem:

* [Renomear](refactoring/rename.md)
* [Extrair função](refactoring/extract-function.md)
* [Implementar virtuais puras](refactoring/implement-pure-virtuals.md)
* [Criar declaração/definição](refactoring/create-declaration-definition.md)
* [Mover definição de função](refactoring/move-definition-location.md)
* [Converter para literal de cadeia de caracteres bruta](refactoring/convert-to-raw-string-literal.md)
* [Alterar assinatura](refactoring/change-signature.md)

## <a name="code-style-enforcement-with-clangformat-and-editorconfig"></a>Imposição de estilo de código com o ClangFormat e o EditorConfig

O Visual Studio 2017 e posterior vem com suporte interno para o [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html), um utilitário de formatação de código popular para o C++ baseado no Clang/LLVM. Digite "ClangFormat" em [Início Rápido](/visualstudio/ide/reference/quick-launch-environment-options-dialog-box) para defini-lo para usar um destes formatos comuns:

- LLVM
- Google
- Chromium
- Mozilla
- WebKit
- {1&gt;Visual Studio&lt;1}

Forneça também seu próprio arquivo .clang-format ou _clang-format para aplicar regras personalizadas a todos os arquivos de código no mesmo nível ou abaixo.

Os arquivos podem ser compartilhados com facilidade por meio do controle do código-fonte e, portanto, você pode impor convenções de codificação a toda a equipe de desenvolvimento.

![Formato&#43; &#43; C Clang](../ide/media/clang-format-cpp.png "Formato Clang")

O Visual Studio 2017 e posterior também dá suporte ao [EditorConfig](https://editorconfig.org/), que funciona de maneira semelhante. No entanto, o ClangFormat traz mais opções de estilo do que o EditorConfig, incluindo regras específicas do C++. Com o **EditorConfig**, você cria arquivos **.editorconfig** e coloca-os em pastas diferentes da base de código para especificar estilos de código para essas pastas e suas subpastas. Um arquivo **.editorconfig** substitui qualquer outro arquivo **.editorconfig** nas pastas pai e substitui as configurações de formatação definidas por meio de **Ferramentas** > **Opções**. Defina regras para tabulações vs. espaços, o tamanho do recuo, entre outros. Para obter mais informações, confira [Criar configurações portáteis do editor personalizado com o EditorConfig](/visualstudio/ide/create-portable-custom-editor-options).

## <a name="other-formatting-options"></a>Outras opções de formatação

A caixa de pesquisa **Início Rápido** fornece a maneira mais rápida de localizar uma configuração ou ferramenta. Ela está localizada no menu principal. Basta começar a digitar e a lista de preenchimento automático filtrará os resultados.

![Início rápido do Visual Studio](../ide/media/vs2015_cpp_quick_launch.png "Início Rápido")

Para definir opções de formatação como recuos, preenchimento de chaves e colorização, digite "Formatação do C++" na janela **Início Rápido**.

![Opções de formatação do C++](media/cpp-formatting-options.png)

Outras opções de formatação estão localizadas em **Editar** > **Avançado** no menu principal.

![Opções de edição avançadas do C++](media/edit-advanced-cpp.png)

As opções para habilitar e configurar recursos de edição específicos do C++ estão localizadas em **Ferramentas** > **Opções** > **Editor de Texto** > **C/C++** . Depois de escolher a opção que deseja definir, você obtenha mais ajuda pressionando **F1** quando a caixa de diálogo estiver no foco. Para obter opções gerais de formatação de código, digite `Editor C++` em **Início Rápido**.

![Opções de > de Ferramentas do Visual Studio](../ide/media/tools-options.png "Opções do editor")

As funcionalidades experimentais, que podem ou não ser incluídas em uma versão futura do Visual Studio, são encontradas na caixa de diálogo [Experimental do C++ do Editor de Texto](/visualstudio/ide/reference/options-text-editor-c-cpp-experimental). No Visual Studio 2017 e posterior, você pode habilitar o **IntelliSense Preditivo** nessa caixa de diálogo.

## <a name="see-also"></a>Veja também

[Ler e entender o código C++](read-and-understand-code-cpp.md)</br>
[Navegar pela base de código C++ no Visual Studio](navigate-code-cpp.md)</br>
[Colaborar com o Live Share para C++](live-share-cpp.md)
