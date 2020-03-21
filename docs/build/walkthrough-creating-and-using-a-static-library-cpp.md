---
title: 'Instruções passo a passo: criando e usando uma biblioteca estática (C++)'
description: Use C++ para criar uma biblioteca estática (. lib) no Visual Studio.
ms.custom: get-started-article
ms.date: 04/25/2019
helpviewer_keywords:
- libraries [C++], static
- static libraries [C++]
ms.assetid: 3cc36411-7d66-4240-851e-dacb9a8fd6ac
ms.author: corob
ms.openlocfilehash: c81ccd970383c8571a7d0d1e77d4b8fe44900bcf
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80078190"
---
# <a name="walkthrough-creating-and-using-a-static-library-c"></a>Instruções passo a passo: criando e usando uma biblioteca estática (C++)

Este guia passo a passo mostra como criar uma biblioteca estática (arquivo. lib) para uso com C++ aplicativos. Usar uma biblioteca estática é uma ótima maneira de reutilizar o código. Em vez de reimplementar as mesmas rotinas em todos os aplicativos que exigem a funcionalidade, você as escreve uma vez em uma biblioteca estática e, em seguida, faz referência a ela a partir dos aplicativos. O código vinculado de uma biblioteca estática se torna parte do seu aplicativo – você não precisa instalar outro arquivo para usar o código.

Este passo a passo apresenta estas tarefas:

- [Criando um projeto de biblioteca estática](#CreateLibProject)

- [Adicionando uma classe à biblioteca estática](#AddClassToLib)

- [Criando um C++ aplicativo de console que faz referência à biblioteca estática](#CreateAppToRefTheLib)

- [Usando a funcionalidade da biblioteca estática no aplicativo](#UseLibInApp)

- [Executando o aplicativo](#RunApp)

## <a name="prerequisites"></a>Prerequisites

Uma compreensão dos conceitos básicos do C++ idioma.

##  <a name="creating-a-static-library-project"></a><a name="CreateLibProject"></a>Criando um projeto de biblioteca estática

As instruções sobre como criar o projeto variam dependendo se você estiver usando o Visual Studio 2019 ou uma versão anterior. Verifique se você tem a versão correta definida no canto superior esquerdo desta página.

::: moniker range="vs-2019"

### <a name="to-create-a-static-library-project-in-visual-studio-2019"></a>Para criar um projeto de biblioteca estática no Visual Studio 2019

1. Na barra de menus, escolha **arquivo** > **novo** **projeto** de > para abrir a caixa de diálogo **criar um novo projeto** .

1. Na parte superior da caixa de diálogo, defina **Linguagem** como **C++** , **Plataforma** como **Windows** e **Tipo de projeto** como **Biblioteca**.

1. Na lista filtrada de tipos de projeto, escolha **biblioteca estática** e escolha **Avançar**. Na página seguinte, digite *MathFuncsLib* na caixa **nome** para especificar um nome para o projeto e especifique o local do projeto, se desejado.

1. Escolha o botão **Criar** para criar o projeto do cliente.

::: moniker-end

::: moniker range="vs-2017"

### <a name="to-create-a-static-library-project-in-visual-studio-2017"></a>Para criar um projeto de biblioteca estática no Visual Studio 2017

1. Na barra de menus, escolha **arquivo** > **novo** **projeto**de >.

1. No painel esquerdo da caixa de diálogo **novo projeto** , expanda **instalado** > **Visual C++** e, em seguida, selecione **área de trabalho do Windows**. No painel central, escolha **Assistente do Windows Desktop**.

1. Especifique um nome para o projeto — por exemplo, *MathFuncsLib*— na caixa **nome** . Especifique um nome para a solução — por exemplo, *StaticLibrary*— na caixa **nome da solução** . Escolha o botão **OK** .

1. Em **tipo de aplicativo**, selecione **biblioteca estática (. lib)** .

1. Em **Opções adicionais**, desmarque a caixa de seleção **cabeçalho pré-compilado** .

1. Escolha **OK** para criar o projeto.

::: moniker-end

::: moniker range="vs-2015"

### <a name="to-create-a-static-library-project-in-visual-studio-2015"></a>Para criar um projeto de biblioteca estática no Visual Studio 2015

1. Na barra de menus, escolha **arquivo** > **novo** **projeto**de >.

1. Na caixa de diálogo **novo projeto** , expanda **instalado** os **modelos** de >  > **Visual C++** e, em seguida, selecione **Win32**. No painel central, escolha **Aplicativo de Console Win32**.

1. Especifique um nome para o projeto — por exemplo, *MathFuncsLib*— na caixa **nome** . Especifique um nome para a solução — por exemplo, *StaticLibrary*— na caixa **nome da solução** . Escolha o botão **OK** .

1. Clique em **Próximo**.

1. Em **tipo de aplicativo**, selecione **biblioteca estática**. Em seguida, desmarque a caixa de **cabeçalho pré-compilado** e escolha **concluir**.

::: moniker-end

##  <a name="adding-a-class-to-the-static-library"></a><a name="AddClassToLib"></a>Adicionando uma classe à biblioteca estática

### <a name="to-add-a-class-to-the-static-library"></a>Para adicionar uma classe à biblioteca estática

1. Para criar um arquivo de cabeçalho para uma nova classe, abra o menu de atalho do projeto **MathFuncsLib** no **Gerenciador de soluções**e, em seguida, escolha **Adicionar** > **novo item**. Na caixa de diálogo **Adicionar novo item** , no painel esquerdo, em **C++Visual**, selecione **código**. No painel central, escolha **Arquivo de Cabeçalho (.h)** . Especifique um nome para o arquivo de cabeçalho — por exemplo, *MathFuncsLib. h*— e, em seguida, escolha o botão **Adicionar** . Um arquivo de cabeçalho em branco é exibido.

1. Adicione uma classe chamada `MyMathFuncs` para realizar operações matemáticas comuns, como adição, subtração, multiplicação e divisão. O código deve ser semelhante a:

   [!code-cpp[NVC_Walkthrough_Create_Static_Lib#100](../windows/codesnippet/CPP/walkthrough-creating-and-using-a-static-library-cpp_1.h)]

1. Para criar um arquivo de origem para a nova classe, abra o menu de atalho do projeto **MathFuncsLib** no **Gerenciador de soluções**e, em seguida, escolha **Adicionar** > **novo item**. Na caixa de diálogo **Adicionar novo item** , no painel esquerdo, em **C++Visual**, selecione **código**. No painel central, selecione  **C++ arquivo (. cpp)** . Especifique um nome para o arquivo de origem — por exemplo, *MathFuncsLib. cpp*— e, em seguida, escolha o botão **Adicionar** . Um arquivo de origem em branco é exibido.

1. Use esse arquivo de origem para implementar a funcionalidade para **MyMathFuncs**. O código deve ser semelhante a:

   [!code-cpp[NVC_Walkthrough_Create_Static_Lib#110](../windows/codesnippet/CPP/walkthrough-creating-and-using-a-static-library-cpp_2.cpp)]

1. Compile a biblioteca estática selecionando **criar** > **solução de Build** na barra de menus. A compilação cria uma biblioteca estática que pode ser usada por outros programas.

   > [!NOTE]
   > Ao criar na linha de comando do Visual Studio, você deve compilar o programa em duas etapas. Primeiro, execute `cl /c /EHsc MathFuncsLib.cpp` para compilar o código e criar um arquivo de objeto chamado `MathFuncsLib.obj`. (O comando `cl` invoca o compilador, CL. exe e a opção `/c` especifica compilar sem vinculação. Para obter mais informações, consulte [/c (compilar sem vinculação)](../build/reference/c-compile-without-linking.md).) Em segundo lugar, execute `lib MathFuncsLib.obj` para vincular o código e criar a biblioteca estática `MathFuncsLib.lib`. (O comando `lib` invoca o Gerenciador de biblioteca, lib. exe. Para obter mais informações, consulte [referência de lib](../build/reference/lib-reference.md).)

##  <a name="creating-a-c-console-app-that-references-the-static-library"></a><a name="CreateAppToRefTheLib"></a>Criando um C++ aplicativo de console que faz referência à biblioteca estática

::: moniker range="vs-2019"

### <a name="to-create-a-c-console-app-that-references-the-static-library-in-visual-studio-2019"></a>Para criar um C++ aplicativo de console que faça referência à biblioteca estática no Visual Studio 2019

1. Em **Gerenciador de soluções**, clique com o botão direito do mouse no nó superior da solução e escolha **Adicionar** > **novo projeto** para abrir a caixa de diálogo **Adicionar um novo projeto** .

1. Na parte superior da caixa de diálogo, defina **Linguagem** como **C++** , **Plataforma** como **Windows** e **Tipo de projeto** como **Console**.

1. Na lista filtrada de tipos de projeto, escolha **Aplicativo de Console** e, em seguida, escolha **Avançar**. Na página seguinte, digite *MyExecRefsLib* na caixa **nome** para especificar um nome para o projeto e especifique o local do projeto, se desejado.

1. Escolha o botão **Criar** para criar o projeto do cliente.

::: moniker-end

::: moniker range="vs-2017"

### <a name="to-create-a-c-console-app-that-references-the-static-library-in-visual-studio-2017"></a>Para criar um C++ aplicativo de console que faça referência à biblioteca estática no Visual Studio 2017

1. Na barra de menus, escolha **arquivo** > **novo** **projeto**de >.

1. No painel esquerdo da caixa de diálogo **novo projeto** , expanda **instalado** > **Visual C++** e, em seguida, selecione **área de trabalho do Windows**. No painel central, escolha **Assistente do Windows Desktop**.

1. Especifique um nome para o projeto — por exemplo, *MyExecRefsLib*— na caixa **nome** . Na lista suspensa ao lado de **solução**, selecione **Adicionar à solução**. O comando adiciona o novo projeto à solução que contém a biblioteca estática. Escolha o botão **OK** .

1. Em **tipo de aplicativo**, selecione **aplicativo de console (. exe)** .

1. Em **Opções adicionais**, desmarque a caixa de seleção **cabeçalho pré-compilado** .

1. Escolha **OK** para criar o projeto.

::: moniker-end

::: moniker range="vs-2015"

### <a name="to-create-a-c-console-app-that-references-the-static-library-in-visual-studio-2015"></a>Para criar um C++ aplicativo de console que faça referência à biblioteca estática no Visual Studio 2015

1. Na barra de menus, escolha **arquivo** > **novo** **projeto**de >.

1. Na caixa de diálogo **novo projeto** , expanda **instalado** os **modelos** de >  > **Visual C++** e, em seguida, selecione **Win32**. No painel central, escolha **Aplicativo de Console Win32**.

1. Especifique um nome para o projeto — por exemplo, *MyExecRefsLib*— na caixa **nome** . Na lista suspensa ao lado de **solução**, selecione **Adicionar à solução**. O comando adiciona o novo projeto à solução que contém a biblioteca estática. Escolha o botão **OK** .

1. Clique em **Próximo**.

1. Verifique se o **aplicativo de console** está selecionado. Em seguida, marque a caixa **projeto vazio** e escolha **concluir**.

::: moniker-end

##  <a name="using-the-functionality-from-the-static-library-in-the-app"></a><a name="UseLibInApp"></a>Usando a funcionalidade da biblioteca estática no aplicativo

### <a name="to-use-the-functionality-from-the-static-library-in-the-app"></a>Para usar a funcionalidade da biblioteca estática no aplicativo

1. Depois que você cria um aplicativo de console, o sistema cria um programa vazio para você. O nome do arquivo de origem será o mesmo que você escolheu anteriormente. No exemplo, ele é nomeado `MyExecRefsLib.cpp`.

1. Antes de poder usar as rotinas matemáticas na biblioteca estática, você deve fazer referência a ela. Abra o menu de atalho do projeto **MyExecRefsLib** no **Gerenciador de soluções**e escolha **Adicionar** **referência** > .

1. A caixa de diálogo **Adicionar referência** lista as bibliotecas que você pode referenciar. A guia **projetos** lista os projetos na solução atual e todas as bibliotecas que eles referenciam. Na guia **projetos** , marque a caixa de seleção **MathFuncsLib** e escolha o botão **OK** .

1. Para fazer referência ao arquivo de cabeçalho de `MathFuncsLib.h`, você deve modificar o caminho dos diretórios incluídos. Na caixa de diálogo **páginas de propriedades** para **MyExecRefsLib**, expanda o nó **Propriedades de configuração** , expanda o **C/C++**  node e, em seguida, selecione **geral**. Ao lado de **diretórios de inclusão adicionais**, especifique o caminho do diretório **MathFuncsLib** ou procure por ele.

   Para procurar o caminho do diretório, abra a lista suspensa valor da propriedade e escolha **Editar**. Na caixa de diálogo **diretórios de inclusão adicionais** , na caixa de texto, selecione uma linha em branco e, em seguida, escolha o botão de reticências ( **...** ) no final da linha. Na caixa de diálogo **Selecionar diretório** , selecione o diretório **MathFuncsLib** e escolha o botão **Selecionar pasta** para salvar sua seleção e feche a caixa de diálogo. Na caixa de diálogo **diretórios de inclusão adicionais** , escolha o botão **OK** e, em seguida, na caixa de diálogo **páginas de propriedades** , escolha o botão **OK** para salvar as alterações no projeto.

1. Agora você pode usar a classe `MyMathFuncs` nesse aplicativo, incluindo o cabeçalho `#include "MathFuncsLib.h"` em seu código. Substitua o conteúdo de `MyExecRefsLib.cpp` com este código:

   [!code-cpp[NVC_Walkthrough_Create_Static_Lib#120](../windows/codesnippet/CPP/walkthrough-creating-and-using-a-static-library-cpp_3.cpp)]

1. Crie o executável escolhendo **compilar** > **criar solução** na barra de menus.

##  <a name="running-the-app"></a><a name="RunApp"></a>Executando o aplicativo

### <a name="to-run-the-app"></a>Para executar o aplicativo

1. Verifique se **MyExecRefsLib** está selecionado como o projeto padrão abrindo o menu de atalho para **MyExecRefsLib** em **Gerenciador de soluções**e, em seguida, escolhendo **definir como projeto de inicialização**.

1. Para executar o projeto, na barra de menus, escolha **Depurar** > **Iniciar sem Depuração**. A saída deve ser semelhante a:

    ```Output
    a + b = 106.4
    a - b = -91.6
    a * b = 732.6
    a / b = 0.0747475
    ```

## <a name="see-also"></a>Confira também

[Instruções passo a passo: criando e usando uma biblioteca de vínculo dinâmico (C++)](../build/walkthrough-creating-and-using-a-dynamic-link-library-cpp.md)<br/>
[Aplicativos de área de trabalho (Visual C++)](../windows/desktop-applications-visual-cpp.md)<br/>
