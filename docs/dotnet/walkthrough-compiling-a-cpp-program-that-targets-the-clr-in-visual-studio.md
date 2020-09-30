---
title: Compilação de um programa em CLI/C++ que se destina ao CLR
description: Use o Microsoft C++ para criar programas e bibliotecas que podem conectar código C++ nativo e programas .NET.
ms.date: 04/23/2019
helpviewer_keywords:
- command-line applications [C++], managed code
- compiling programs [C++]
- Visual C++, managed code
- managed code [C++]
ms.assetid: 339f89df-a5d2-4040-831a-ddbe25b5dce4
ms.openlocfilehash: 2fceb57e062b9179245ba235fb497ff526a6660e
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91501686"
---
# <a name="walkthrough-compile-a-ccli-program-that-targets-the-clr-in-visual-studio"></a>Walkthrough: compilar um programa C++/CLI que tem como alvo o CLR no Visual Studio

Usando C++/CLI, você pode criar programas C++ que usam classes .NET, bem como tipos C++ nativos. O C++/CLI destina-se ao uso em aplicativos de console e em DLLs que encapsulam código C++ nativo e os tornam acessíveis a partir de programas .NET. Para criar uma interface do usuário do Windows baseada em .NET, use C# ou Visual Basic.

Para este procedimento, você pode digitar seu próprio programa C++ ou usar um dos programas de exemplo. O programa de exemplo que usamos neste procedimento cria um arquivo de texto chamado textfile.txt e salva-o no diretório do projeto.

## <a name="prerequisites"></a>Pré-requisitos

- Uma compreensão dos conceitos básicos da linguagem C++.
- No Visual Studio 2017 e posterior, o suporte a C++/CLI é um componente opcional. Para instalá-lo, abra o **instalador do Visual Studio** no menu Iniciar do Windows. Verifique se o bloco **desenvolvimento de área de trabalho com C++** está marcado e, na seção componentes **opcionais** , verifique também **suporte a C++/CLI**.

## <a name="create-a-new-project"></a>Criar um novo projeto

As etapas a seguir variam dependendo da versão do Visual Studio que você está usando. Para ver a documentação da sua versão preferida do Visual Studio, use o controle seletor de **versão** . Ele é encontrado na parte superior do Sumário nesta página.

::: moniker range="vs-2019"

### <a name="to-create-a-ccli-project-in-visual-studio-2019"></a>Para criar um projeto C++/CLI no Visual Studio 2019

1. Em **Gerenciador de soluções**, clique com o botão direito do mouse na parte superior para abrir a caixa de diálogo **criar um novo projeto** .

1. Na parte superior do diálogo, digite **CLR** na caixa de pesquisa e escolha projeto do **CLR vazio** na lista de resultados.

1. Escolha o botão **Criar** para criar o projeto.

::: moniker-end

::: moniker range="vs-2017"

### <a name="to-create-a-ccli-project-in-visual-studio-2017"></a>Para criar um projeto C++/CLI no Visual Studio 2017

1. Criar um novo projeto. No menu **Arquivo** , aponte para **Novo**e clique em **Projeto**.

1. Entre os tipos de projeto do Visual C++, clique em **CLR** e, em seguida, **Projeto CLR Vazio**.

1. Digite um nome de projeto. Por padrão, a solução que contém o projeto tem o mesmo nome do novo projeto, mas você pode inserir outro nome. Insira outro local para o projeto se desejar.

1. Clique em **OK** para criar o projeto.

::: moniker-end

::: moniker range="vs-2015"

### <a name="to-create-a-ccli-project-in-visual-studio-2015"></a>Para criar um projeto C++/CLI no Visual Studio 2015

1. Criar um novo projeto. No menu **Arquivo** , aponte para **Novo**e clique em **Projeto**.

1. Entre os tipos de projeto do Visual C++, clique em **CLR** e, em seguida, **Projeto CLR Vazio**.

1. Digite um nome de projeto. Por padrão, a solução que contém o projeto tem o mesmo nome do novo projeto, mas você pode inserir outro nome. Insira outro local para o projeto se desejar.

1. Clique em **OK** para criar o projeto.

::: moniker-end

## <a name="add-a-source-file"></a>Adicionar um arquivo de origem

1. Se o **Gerenciador de Soluções** não estiver visível, clique no **Gerenciador de Soluções** no menu **Exibir**.

1. Adicione um novo arquivo de origem ao projeto:

   - Clique com o botão direito do mouse na pasta **arquivos de origem** em **Gerenciador de soluções**, aponte para **Adicionar**e clique em **novo item**.

   - Clique em **Arquivo C++ (.cpp)**, digite um nome de arquivo e, em seguida, clique em **Adicionar**.

   O arquivo **. cpp** aparece na pasta **arquivos de origem** em **Gerenciador de soluções** e uma janela com guias aparece onde você digita o código desejado nesse arquivo.

1. Clique na guia recém-criada no Visual Studio e digite um programa válido do Visual C++ ou copie e cole um dos programas de exemplo.

   Por exemplo, use o programa de exemplo [Como escrever um arquivo de texto (C++/CLI)](./file-handling-and-i-o-cpp-cli.md#write_text) (no nó **Manipulação de Arquivos e E/S** do Guia de Programação).

   Se você usar o programa de exemplo, observe que você usa a **`gcnew`** palavra-chave em vez de **`new`** ao criar um objeto .net e que **`gcnew`** retorna um Handle ( `^` ) em vez de um ponteiro ( `*` ):

   `StreamWriter^ sw = gcnew StreamWriter(fileName);`

   Para obter mais informações sobre a sintaxe C++/CLI, consulte [extensões de componente para plataformas de tempo de execução](../extensions/component-extensions-for-runtime-platforms.md).

1. No menu **Compilar**, clique em **Compilar Solução**.

   A janela de **Saída** exibe informações sobre o progresso da compilação, como o local do log de build e uma mensagem que indica o status do build.

   Se você fizer alterações e executar o programa sem fazer um build, uma caixa de diálogo poderá indicar que o projeto está desatualizado. Marque a caixa de seleção nessa caixa de diálogo antes de clicar em **OK** se desejar que o Visual Studio sempre use as versões atuais dos arquivos, em vez de exibir uma solicitação sempre que compilar o aplicativo.

1. No menu **Depuração**, clique em **Iniciar sem Depurar**.

1. Se você usou o programa de exemplo, quando executar o programa, será exibida uma janela Comando que indica que o arquivo de texto foi criado.

   O arquivo de texto **textfile.txt** agora está localizado no diretório do projeto. Abra esse arquivo usando o Bloco de notas.

   > [!NOTE]
   > A escolha do modelo de projeto CLR vazio define automaticamente a opção do compilador `/clr`. Para verificar isso, clique com o botão direito do mouse no projeto no **Gerenciador de Soluções**, clique em **Propriedades** e, em seguida, marque a opção **Suporte a Common Language Runtime** no nó **Geral** de **Propriedades de Configuração**.

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Sistemas de build e projetos](../build/projects-and-build-systems-cpp.md)<br/>
