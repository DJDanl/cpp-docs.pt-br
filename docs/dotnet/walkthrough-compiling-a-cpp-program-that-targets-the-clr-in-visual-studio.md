---
title: Compilar um c++ /CLI programa que tem como alvo o CLR
description: Usar o Microsoft C++ para criar programas e bibliotecas que podem se conectar nativo C++ código e programas .NET.
ms.date: 04/23/2019
helpviewer_keywords:
- command-line applications [C++], managed code
- compiling programs [C++]
- Visual C++, managed code
- managed code [C++]
ms.assetid: 339f89df-a5d2-4040-831a-ddbe25b5dce4
ms.openlocfilehash: 8462b2b031bdcdebf65d58974c521d80e57d856d
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65221814"
---
# <a name="walkthrough-compile-a-ccli-program-that-targets-the-clr-in-visual-studio"></a>Passo a passo: Compilar um c++ /CLI programa que se destina ao CLR no Visual Studio

Usando C++/CLI, você pode criar C++ programas que usam classes do .NET, bem como nativo C++ tipos. C++E CLI é destinada para uso em aplicativos de console e em DLLs que encapsulam nativo C++ de código e torná-lo acessível a partir de programas .NET. Para criar uma interface de usuário do Windows com base em .NET, use C# ou Visual Basic. 

Para este procedimento, você pode digitar seu próprio programa C++ ou use um dos programas de exemplo. O programa de exemplo que usamos neste procedimento cria um arquivo de texto chamado textfile.txt e salva-o no diretório do projeto.

## <a name="prerequisites"></a>Pré-requisitos

- Um entendimento dos fundamentos da linguagem C++.
- No Visual Studio 2017 e posterior, C++suporte da CLI é um componente opcional. Para instalá-lo, abra o **instalador do Visual Studio** no menu Iniciar do Windows. Certifique-se de que o **desenvolvimento para Desktop com C++**  lado a lado é marcada e, na **opcional** seção componentes, também Verifique se há  **C++suporte à CLI**.

## <a name="create-a-new-project"></a>Criar um novo projeto

As seguintes etapas variam, dependendo de qual versão do Visual Studio que você está usando. Verifique se que o seletor de versão no canto superior esquerdo dessa página está definido corretamente.

::: moniker range="vs-2019"

### <a name="to-create-a-ccli-project-in-visual-studio-2019"></a>Para criar um C++projeto /CLI no Visual Studio de 2019

1. Na **Gerenciador de soluções**, clique com botão direito na parte superior para abrir o **criar um novo projeto** caixa de diálogo.

1. Na parte superior da caixa de diálogo, digite **CLR** na pesquisa de caixa e, em seguida, escolha **projeto CLR vazio** na lista de resultados. 

1. Escolha o **criar** botão para criar o projeto.

::: moniker-end

::: moniker range="vs-2017"

### <a name="to-create-a-ccli-project-in-visual-studio-2017"></a>Para criar um C++projeto /CLI no Visual Studio 2017

1. Crie um novo projeto. No menu **Arquivo**, aponte para **Novo** e clique em **Projeto**.

1. Entre os tipos de projeto do Visual C++, clique em **CLR** e, em seguida, **Projeto CLR Vazio**.

1. Digite um nome de projeto. Por padrão, a solução que contém o projeto tem o mesmo nome do novo projeto, mas você pode inserir outro nome. Insira outro local para o projeto se desejar.

1. Clique em **OK** para criar o projeto.

::: moniker-end

::: moniker range="vs-2015"

### <a name="to-create-a-ccli-project-in-visual-studio-2015"></a>Para criar um C++projeto /CLI no Visual Studio 2015

1. Crie um novo projeto. No menu **Arquivo**, aponte para **Novo** e clique em **Projeto**.

1. Entre os tipos de projeto do Visual C++, clique em **CLR** e, em seguida, **Projeto CLR Vazio**.

1. Digite um nome de projeto. Por padrão, a solução que contém o projeto tem o mesmo nome do novo projeto, mas você pode inserir outro nome. Insira outro local para o projeto se desejar.

1. Clique em **OK** para criar o projeto.

::: moniker-end

## <a name="add-a-source-file"></a>Adicionar um arquivo de origem

1. Se o **Gerenciador de Soluções** não estiver visível, clique no **Gerenciador de Soluções** no menu **Exibir**.

1. Adicione um novo arquivo de origem ao projeto:

   - Clique com o botão direito do mouse na pasta **Arquivos de origem** no **Gerenciador de Soluções**, aponte para **Adicionar** e clique em **Novo Item**.

   - Clique em **Arquivo C++ (.cpp)**, digite um nome de arquivo e, em seguida, clique em **Adicionar**.

   O arquivo **.cpp** é exibido na pasta **Arquivos de Origem** do **Gerenciador de Soluções** e uma janela com guias é exibida no campo no qual você digita o código que deseja inserir nesse arquivo.

1. Clique na guia recém-criada no Visual Studio e digite um programa válido do Visual C++ ou copie e cole um dos programas de exemplo.

   Por exemplo, você pode usar o programa de exemplo [Como gravar um arquivo de texto (C++/CLI)](how-to-write-a-text-file-cpp-cli.md) (no nó **Manipulação de Arquivos e E/S** do Guia de Programação).

   Se você usar o programa de exemplo, observe que você usará a palavra-chave `gcnew` em vez de `new` durante a criação de um objeto .NET e que `gcnew` retorna um identificador (`^`) em vez de um ponteiro (`*`):

   `StreamWriter^ sw = gcnew StreamWriter(fileName);`

   Para obter mais informações sobre C++sintaxe /CLI, consulte [extensões de componentes para plataformas de tempo de execução](../extensions/component-extensions-for-runtime-platforms.md).

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
[Sistemas de Compilação e Projetos](../build/projects-and-build-systems-cpp.md)<br/>
