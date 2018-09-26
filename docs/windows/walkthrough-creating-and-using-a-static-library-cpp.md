---
title: 'Passo a passo: Criando e usando uma biblioteca estática (C++) | Microsoft Docs'
ms.custom: get-started-article
ms.date: 09/18/2018
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- libraries [C++], static
- static libraries [C++]
ms.assetid: 3cc36411-7d66-4240-851e-dacb9a8fd6ac
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a85789123b1dd9129916683c08484bf6607a0687
ms.sourcegitcommit: 9799816278ffa3e6b64199862ec57143c1b1ea56
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/26/2018
ms.locfileid: "47188113"
---
# <a name="walkthrough-creating-and-using-a-static-library-c"></a>Instruções passo a passo: criando e usando uma biblioteca estática (C++)

Este passo a passo mostra como criar uma biblioteca estática (arquivo. lib) para uso com aplicativos do C++. Usando uma biblioteca estática é uma ótima maneira de reutilizar o código. Em vez de reimplementar as mesmas rotinas em todos os aplicativos que exige a funcionalidade, você grava uma vez em uma biblioteca estática e, em seguida, referenciá-lo a partir dos aplicativos. Código vinculado de uma biblioteca estática torna-se parte do seu aplicativo — você não precisa instalar outro arquivo para usar o código.

Este passo a passo apresenta estas tarefas:

- [Criando um projeto de biblioteca estática](#CreateLibProject)

- [Adicionando uma classe à biblioteca estática](#AddClassToLib)

- [Criar um aplicativo de console C++ que faz referência à biblioteca estática](#CreateAppToRefTheLib)

- [Usando a funcionalidade da biblioteca estática no aplicativo](#UseLibInApp)

- [Executando o aplicativo](#RunApp)

## <a name="prerequisites"></a>Pré-requisitos

Um entendimento dos fundamentos da linguagem C++.

##  <a name="CreateLibProject"></a> Criando um projeto de biblioteca estática

### <a name="to-create-a-static-library-project"></a>Para criar um projeto de biblioteca estática

1. Na barra de menus, selecione **Arquivo** > **Novo** > **Projeto**.

1. No painel esquerdo do **novo projeto** diálogo caixa, expanda **instalado** > **Visual C++** e, em seguida, selecione **área de trabalho do Windows**. No painel central, selecione **Assistente de área de trabalho do Windows**.

   > [!NOTE]
   > Para versões do Visual Studio anteriores a 2017, nos **novo projeto** diálogo caixa, expanda **instalado** > **modelos**  >  **Visual C++** e, em seguida, selecione **Win32**. No painel central, selecione **aplicativo do Console Win32**.

1. Especifique um nome para o projeto — por exemplo, *MathFuncsLib*— na **nome** caixa. Especifique um nome para a solução — por exemplo, *StaticLibrary*— na **nome da solução** caixa. Escolha o botão **OK**.

    - Para o Visual Studio 2017

        1. Sob **tipo de aplicativo**, selecione **biblioteca estática (. lib)**.

        1. Sob **opções adicionais**, desmarque as **cabeçalho pré-compilado** caixa de seleção.

        1. Escolher **Okey** para criar o projeto.

    - Para versões do Visual Studio anteriores a 2017,

        1. Clique em **Avançar**.

        1. Sob **tipo de aplicativo**, selecione **biblioteca estática**. Em seguida, desmarque a **cabeçalho pré-compilado** caixa e escolha **concluir**.

##  <a name="AddClassToLib"></a> Adicionando uma classe à biblioteca estática

### <a name="to-add-a-class-to-the-static-library"></a>Para adicionar uma classe à biblioteca estática

1. Para criar um arquivo de cabeçalho para uma nova classe, abra o menu de atalho para o **MathFuncsLib** project no **Gerenciador de soluções**e, em seguida, escolha **Add**  >   **Novo Item**. No **Adicionar Novo Item** caixa de diálogo, no painel esquerdo, em **Visual C++**, selecione **código**. No painel central, selecione **arquivo de cabeçalho (. h)**. Especifique um nome para o arquivo de cabeçalho — por exemplo, *Mathfuncslib*— e, em seguida, escolha o **Add** botão. Um arquivo de cabeçalho em branco é exibido.

1. Adicione uma classe chamada `MyMathFuncs` para executar operações matemáticas comuns, como adição, subtração, multiplicação e divisão. O código deve ser parecido com este:

   [!code-cpp[NVC_Walkthrough_Create_Static_Lib#100](../windows/codesnippet/CPP/walkthrough-creating-and-using-a-static-library-cpp_1.h)]

1. Para criar um arquivo de origem para a nova classe, abra o menu de atalho para o **MathFuncsLib** project no **Gerenciador de soluções**e, em seguida, escolha **Add**  >   **Novo Item**. No **Adicionar Novo Item** caixa de diálogo, no painel esquerdo, em **Visual C++**, selecione **código**. No painel central, selecione **arquivo C++ (. cpp)**. Especifique um nome para o arquivo de origem — por exemplo, *MathFuncsLib.cpp*— e, em seguida, escolha o **Add** botão. Um arquivo de origem em branco é exibido.

1. Use esse arquivo de origem para implementar a funcionalidade para **MyMathFuncs**. O código deve ser parecido com este:

   [!code-cpp[NVC_Walkthrough_Create_Static_Lib#110](../windows/codesnippet/CPP/walkthrough-creating-and-using-a-static-library-cpp_2.cpp)]

1. Compilar a biblioteca estática selecionando **construir** > **compilar solução** na barra de menus. Isso cria uma biblioteca estática que pode ser usada por outros programas.

   > [!NOTE]
   > Quando você compila na linha de comando do Visual Studio, você deve compilar o programa em duas etapas. Primeiro, execute `cl /c /EHsc MathFuncsLib.cpp` para compilar o código e criar um arquivo de objeto que é denominado `MathFuncsLib.obj`. (O `cl` comando chama o compilador, Cl.exe e o `/c` opção especifica compilar sem vincular. Para obter mais informações, consulte [/c (compilar sem vinculação)](../build/reference/c-compile-without-linking.md).) Segundo, executa `lib MathFuncsLib.obj` para vincular o código e criar a biblioteca estática `MathFuncsLib.lib`. (O `lib` comando chama o Gerenciador de biblioteca, Lib.exe. Para obter mais informações, consulte [referência de LIB](../build/reference/lib-reference.md).)

##  <a name="CreateAppToRefTheLib"></a> Criar um aplicativo de console C++ que faz referência à biblioteca estática

### <a name="to-create-a-c-console-app-that-references-the-static-library"></a>Para criar um aplicativo de console C++ que faz referência à biblioteca estática

1. Na barra de menus, selecione **Arquivo** > **Novo** > **Projeto**.

1. No painel esquerdo do **novo projeto** diálogo caixa, expanda **instalado** > **Visual C++** e, em seguida, selecione **área de trabalho do Windows**. No painel central, selecione **Assistente de área de trabalho do Windows**. 

   > [!NOTE]
   > Para versões do Visual Studio anteriores a 2017, nos **novo projeto** diálogo caixa, expanda **instalado** > **modelos**  >  **Visual C++** e, em seguida, selecione **Win32**. No painel central, selecione **aplicativo do Console Win32**.

1. Especifique um nome para o projeto — por exemplo, *MyExecRefsLib*— na **nome** caixa. Na lista suspensa lista ao lado **Solution**, selecione **adicionar à solução**. Isso adiciona o novo projeto à solução que contém a biblioteca estática. Escolha o botão **OK**.

    - Para o Visual Studio 2017

        1. Sob **tipo de aplicativo**, selecione **aplicativo de Console (.exe)**.

        1. Sob **opções adicionais**, desmarque as **cabeçalho pré-compilado** caixa de seleção.

        1. Escolher **Okey** para criar o projeto.

    - Para versões do Visual Studio anteriores a 2017,

        1. Clique em **Avançar**.

        1. Certifique-se **aplicativo de Console** está selecionado. Em seguida, verifique as **projeto vazio** caixa e escolha **concluir**.

##  <a name="UseLibInApp"></a> Usando a funcionalidade da biblioteca estática no aplicativo

### <a name="to-use-the-functionality-from-the-static-library-in-the-app"></a>Para usar a funcionalidade da biblioteca estática no aplicativo

1. Depois que você cria um aplicativo de console, o sistema cria um programa vazio para você. O nome do arquivo de origem será o mesmo que você escolheu anteriormente. Neste exemplo, ela é nomeada `MyExecRefsLib.cpp`.

1. Antes de usar as rotinas de matemática na biblioteca estática, você deve fazer referência a ele. Para fazer isso, abra o menu de atalho para o **MyExecRefsLib** project no **Gerenciador de soluções**e, em seguida, escolha **Add** > **referência**.

1. O **adicionar referência** caixa de diálogo lista as bibliotecas que você pode fazer referência. O **projetos** guia lista os projetos na solução atual e todas as bibliotecas que eles contêm. Sobre o **projetos** guia, selecione o **MathFuncsLib** caixa de seleção e, em seguida, escolha o **Okey** botão.

1. A referência a `MathFuncsLib.h` arquivo de cabeçalho, você deve modificar o caminho de diretório incluído. No **páginas de propriedades** caixa de diálogo **MyExecRefsLib**, expanda o **propriedades de configuração** nó, expanda o **C/C++** nó, e em seguida, selecione **geral**. Lado **diretórios de inclusão adicionais**, especifique o caminho da **MathFuncsLib** diretório ou procurá-lo.

   Para procurar o caminho do diretório, abra a lista de lista suspensa de valores de propriedade e, em seguida, escolha **editar**. No **diretórios de inclusão adicionais** caixa de diálogo, na caixa de texto, selecione uma linha em branco e, em seguida, escolha o botão de reticências (**...** ) no final da linha. No **Selecionar diretório** caixa de diálogo, selecione o **MathFuncsLib** diretório e, em seguida, escolha **Selecionar pasta** botão para salvar sua seleção e fechar a caixa de diálogo. No **diretórios de inclusão adicionais** caixa de diálogo, escolha o **Okey** botão e, em seguida, no **páginas de propriedades** caixa de diálogo, escolha o **Okey**botão para salvar suas alterações ao projeto.

1. Agora você pode usar o `MyMathFuncs` classe nesse aplicativo. Para fazer isso, substitua o conteúdo do `MyExecRefsLib.cpp` com este código:

   [!code-cpp[NVC_Walkthrough_Create_Static_Lib#120](../windows/codesnippet/CPP/walkthrough-creating-and-using-a-static-library-cpp_3.cpp)]

1. Compile o executável escolhendo **construir** > **compilar solução** na barra de menus.

##  <a name="RunApp"></a> Executando o aplicativo

### <a name="to-run-the-app"></a>Para executar o aplicativo

1. Certifique-se de que **MyExecRefsLib** está selecionado como o projeto padrão, abrindo o menu de atalho **MyExecRefsLib** na **Gerenciador de soluções**e, em seguida, escolhendo  **Definir como projeto de inicialização**.

1. Para executar o projeto, na barra de menus, escolha **Debug** > **Start Without Debugging**. O resultado deve ser semelhante a este:

    ```Output
    a + b = 106.4
    a - b = -91.6
    a * b = 732.6
    a / b = 0.0747475
    ```

## <a name="see-also"></a>Consulte também

[Instruções passo a passo: criando e usando uma biblioteca de vínculo dinâmico (C++)](../build/walkthrough-creating-and-using-a-dynamic-link-library-cpp.md)<br/>
[Aplicativos de área de trabalho (Visual C++)](../windows/desktop-applications-visual-cpp.md)<br/>
