---
title: 'Walkthrough: criar e usar uma biblioteca estática (C++)'
description: Use C++ para criar uma biblioteca estática (. lib) no Visual Studio.
ms.custom: get-started-article
ms.date: 04/13/2020
helpviewer_keywords:
- libraries [C++], static
- static libraries [C++]
ms.assetid: 3cc36411-7d66-4240-851e-dacb9a8fd6ac
ms.openlocfilehash: 7148cc1de7c06ae57d61560311b342a1fc9dda1f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81335146"
---
# <a name="walkthrough-create-and-use-a-static-library"></a>Walkthrough: criar e usar uma biblioteca estática

Este guia passo a passo mostra como criar uma biblioteca estática (arquivo. lib) para uso com aplicativos C++. Usar uma biblioteca estática é uma ótima maneira de reutilizar o código. Em vez de reimplementar as mesmas rotinas em todos os aplicativos que exigem a funcionalidade, você as escreve uma vez em uma biblioteca estática e, em seguida, faz referência a ela a partir dos aplicativos. O código vinculado de uma biblioteca estática se torna parte do seu aplicativo – você não precisa instalar outro arquivo para usar o código.

Este passo a passo apresenta estas tarefas:

- [Criar um projeto de biblioteca estática](#CreateLibProject)

- [Adicionar uma classe à biblioteca estática](#AddClassToLib)

- [Criar um aplicativo de console C++ que faz referência à biblioteca estática](#CreateAppToRefTheLib)

- [Usar a funcionalidade da biblioteca estática no aplicativo](#UseLibInApp)

- [Executar o aplicativo](#RunApp)

## <a name="prerequisites"></a>Pré-requisitos

Uma compreensão dos conceitos básicos da linguagem C++.

## <a name="create-a-static-library-project"></a><a name="CreateLibProject"></a>Criar um projeto de biblioteca estática

As instruções sobre como criar o projeto variam de acordo com sua versão do Visual Studio. Para ver a documentação da sua versão preferida do Visual Studio, use o controle seletor de **versão** . Ele é encontrado na parte superior do Sumário nesta página.

::: moniker range="vs-2019"

### <a name="to-create-a-static-library-project-in-visual-studio-2019"></a>Para criar um projeto de biblioteca estática no Visual Studio 2019

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Criar um novo projeto**.

1. Na parte superior da caixa de diálogo, defina **Linguagem** como **C++**, **Plataforma** como **Windows** e **Tipo de projeto** como **Biblioteca**.

1. Na lista filtrada de tipos de projeto, selecione **Assistente de área de trabalho do Windows**e escolha **Avançar**.

1. Na página **configurar seu novo projeto** , digite *MathLibrary* na caixa **nome do projeto** para especificar um nome para o projeto. Insira *StaticMath* na caixa **nome da solução** . Escolha o botão **criar** para abrir a caixa de diálogo de **projeto da área de trabalho do Windows** .

1. Na caixa de diálogo **projeto de área de trabalho do Windows** , em tipo de **aplicativo**, selecione **biblioteca estática (. lib)**.

1. Em **Opções adicionais**, desmarque a caixa de seleção **cabeçalho pré-compilado** se ela estiver marcada. Marque a caixa **projeto vazio** .

1. Escolha **OK** para criar o projeto.

::: moniker-end

::: moniker range="vs-2017"

### <a name="to-create-a-static-library-project-in-visual-studio-2017"></a>Para criar um projeto de biblioteca estática no Visual Studio 2017

1. Na barra de menus, escolha **arquivo** > **novo** > **projeto**.

1. Na caixa de diálogo **novo projeto** , selecione **instalado** > **Visual C++** > **área de trabalho do Windows**. No painel central, escolha **Assistente do Windows Desktop**.

1. Especifique um nome para o projeto — por exemplo, *MathLibrary*— na caixa **nome** . Especifique um nome para a solução — por exemplo, *StaticMath*— na caixa **nome da solução** . Clique no botão **OK**.

1. Na caixa de diálogo **projeto de área de trabalho do Windows** , em tipo de **aplicativo**, selecione **biblioteca estática (. lib)**.

1. Em **Opções adicionais**, desmarque a caixa de seleção **cabeçalho pré-compilado** se ela estiver marcada. Marque a caixa **projeto vazio** .

1. Escolha **OK** para criar o projeto.

::: moniker-end

::: moniker range="vs-2015"

### <a name="to-create-a-static-library-project-in-visual-studio-2015"></a>Para criar um projeto de biblioteca estática no Visual Studio 2015

1. Na barra de menus, escolha **arquivo** > **novo** > **projeto**.

1. Na caixa de diálogo **novo projeto** , selecione **Installed** > **modelos** > instalados**Visual C++** > **Win32**. No painel central, escolha **Aplicativo de Console Win32**.

1. Especifique um nome para o projeto — por exemplo, *MathLibrary*— na caixa **nome** . Especifique um nome para a solução — por exemplo, *StaticMath*— na caixa **nome da solução** . Clique no botão **OK**.

1. No **Assistente de aplicativo Win32**, escolha **Avançar**.

1. Na página **configurações do aplicativo** , em **tipo de aplicativo**, selecione **biblioteca estática**. Em **Opções adicionais**, desmarque a caixa de seleção **cabeçalho pré-compilado** . Escolha **concluir** para criar o projeto.

::: moniker-end

## <a name="add-a-class-to-the-static-library"></a><a name="AddClassToLib"></a>Adicionar uma classe à biblioteca estática

### <a name="to-add-a-class-to-the-static-library"></a>Para adicionar uma classe à biblioteca estática

1. Para criar um arquivo de cabeçalho para uma nova classe, clique com o botão direito do mouse para abrir o menu de atalho do projeto **MathLibrary** no **Gerenciador de soluções**e escolha **Adicionar** > **novo item**.

1. Na caixa de diálogo **Adicionar novo item** , selecione **Visual C++** > **código**. No painel central, escolha **Arquivo de Cabeçalho (.h)**. Especifique um nome para o arquivo de cabeçalho — por exemplo, *MathLibrary. h*— e, em seguida, escolha o botão **Adicionar** . Um arquivo de cabeçalho quase em branco é exibido.

1. Adicione uma declaração para uma classe chamada `Arithmetic` para fazer operações matemáticas comuns, como adição, subtração, multiplicação e divisão. O código deve ser semelhante a:

    ```cpp
    // MathLibrary.h
    #pragma once

    namespace MathLibrary
    {
        class Arithmetic
        {
        public:
            // Returns a + b
            static double Add(double a, double b);

            // Returns a - b
            static double Subtract(double a, double b);

            // Returns a * b
            static double Multiply(double a, double b);

            // Returns a / b
            static double Divide(double a, double b);
        };
    }
    ```

1. Para criar um arquivo de origem para a nova classe, abra o menu de atalho do projeto **MathLibrary** no **Gerenciador de soluções**e, em seguida, escolha **Adicionar** > **novo item**.

1. Na caixa de diálogo **Adicionar novo item** , no painel central, selecione **arquivo C++ (. cpp)**. Especifique um nome para o arquivo de origem — por exemplo, *MathLibrary. cpp*— e, em seguida, escolha o botão **Adicionar** . Um arquivo de origem em branco é exibido.

1. Use esse arquivo de origem para implementar a funcionalidade da `Arithmetic`classe. O código deve ser semelhante a:

    ```cpp
    // MathLibrary.cpp
    // compile with: cl /c /EHsc MathLibrary.cpp
    // post-build command: lib MathLibrary.obj

    #include "MathLibrary.h"

    namespace MathLibrary
    {
        double Arithmetic::Add(double a, double b)
        {
            return a + b;
        }

        double Arithmetic::Subtract(double a, double b)
        {
            return a - b;
        }

        double Arithmetic::Multiply(double a, double b)
        {
            return a * b;
        }

        double Arithmetic::Divide(double a, double b)
        {
            return a / b;
        }
    }
    ```

1. Para criar a biblioteca estática, selecione **criar** > **solução de compilação** na barra de menus. A compilação cria uma biblioteca estática, *MathLibrary. lib*, que pode ser usada por outros programas.

   > [!NOTE]
   > Ao criar na linha de comando do Visual Studio, você deve compilar o programa em duas etapas. Primeiro, execute `cl /c /EHsc MathLibrary.cpp` para compilar o código e criar um arquivo de objeto chamado *MathLibrary. obj*. (O `cl` comando invoca o compilador, CL. exe, e a `/c` opção especifica compile sem vinculação. Para obter mais informações, consulte [/c (compilar sem vinculação)](../build/reference/c-compile-without-linking.md).) Em segundo lugar `lib MathLibrary.obj` , execute para vincular o código e criar a biblioteca estática *MathLibrary. lib*. (O `lib` comando invoca o Gerenciador de biblioteca, lib. exe. Para obter mais informações, consulte [referência de lib](../build/reference/lib-reference.md).)

## <a name="create-a-c-console-app-that-references-the-static-library"></a><a name="CreateAppToRefTheLib"></a>Criar um aplicativo de console C++ que faz referência à biblioteca estática

::: moniker range="vs-2019"

### <a name="to-create-a-c-console-app-that-references-the-static-library-in-visual-studio-2019"></a>Para criar um aplicativo de console C++ que faça referência à biblioteca estática no Visual Studio 2019

1. Em **Gerenciador de soluções**, clique com o botão direito do mouse no nó superior, **solução ' StaticMath '**, para abrir o menu de atalho. Escolha **Adicionar** > **novo projeto** para abrir a caixa de diálogo **Adicionar um novo projeto** .

1. Na parte superior da caixa de diálogo, defina o filtro de **tipo de projeto** como **console**.

1. Na lista filtrada de tipos de projeto, escolha **Aplicativo de Console** e, em seguida, escolha **Avançar**. Na próxima página, digite *MathClient* na caixa **nome** para especificar um nome para o projeto.

1. Escolha o botão **Criar** para criar o projeto do cliente.

1. Depois que você cria um aplicativo de console, o sistema cria um programa vazio para você. O nome do arquivo de origem será o mesmo que você escolheu anteriormente. No exemplo, ele é nomeado `MathClient.cpp`.

::: moniker-end

::: moniker range="vs-2017"

### <a name="to-create-a-c-console-app-that-references-the-static-library-in-visual-studio-2017"></a>Para criar um aplicativo de console C++ que faça referência à biblioteca estática no Visual Studio 2017

1. Em **Gerenciador de soluções**, clique com o botão direito do mouse no nó superior, **solução ' StaticMath '**, para abrir o menu de atalho. Escolha **Adicionar** > **novo projeto** para abrir a caixa de diálogo **Adicionar um novo projeto** .

1. Na caixa de diálogo **Adicionar novo projeto** , selecione **instalado** > **Visual C++** > **área de trabalho do Windows**. No painel central, escolha **Assistente do Windows Desktop**.

1. Especifique um nome para o projeto — por exemplo, *MathClient*— na caixa **nome** . Clique no botão **OK**.

1. Na caixa de diálogo **projeto de área de trabalho do Windows** , em tipo de **aplicativo**, selecione **aplicativo de console (. exe)**.

1. Em **Opções adicionais**, desmarque a caixa de seleção **cabeçalho pré-compilado** se ela estiver marcada.

1. Escolha **OK** para criar o projeto.

1. Depois que você cria um aplicativo de console, o sistema cria um programa vazio para você. O nome do arquivo de origem será o mesmo que você escolheu anteriormente. No exemplo, ele é nomeado `MathClient.cpp`.

::: moniker-end

::: moniker range="vs-2015"

### <a name="to-create-a-c-console-app-that-references-the-static-library-in-visual-studio-2015"></a>Para criar um aplicativo de console C++ que faça referência à biblioteca estática no Visual Studio 2015

1. Em **Gerenciador de soluções**, clique com o botão direito do mouse no nó superior, **solução ' StaticMath '**, para abrir o menu de atalho. Escolha **Adicionar** > **novo projeto** para abrir a caixa de diálogo **Adicionar um novo projeto** .

1. Na caixa de diálogo **Adicionar novo projeto** , selecione **instalado** > **Visual C++** > **Win32**. No painel central, escolha **Aplicativo de Console Win32**.

1. Especifique um nome para o projeto — por exemplo, *MathClient*— na caixa **nome** . Clique no botão **OK**.

1. Na caixa de diálogo **Assistente de aplicativo Win32** , escolha **Avançar**.

1. Na página **configurações do aplicativo** , em **tipo de aplicativo**, verifique se **aplicativo de console** está selecionado. Em **Opções adicionais**, desmarque **cabeçalho pré-compilado**e marque a caixa de seleção **projeto vazio** . Escolha **concluir** para criar o projeto.

1. Para adicionar um arquivo de origem ao projeto vazio, clique com o botão direito do mouse para abrir o menu de atalho do projeto **MathClient** no **Gerenciador de soluções**e escolha **Adicionar** > **novo item**.

1. Na caixa de diálogo **Adicionar novo item** , selecione **Visual C++** > **código**. No painel central, selecione **arquivo C++ (. cpp)**. Especifique um nome para o arquivo de origem — por exemplo, *MathClient. cpp*— e, em seguida, escolha o botão **Adicionar** . Um arquivo de origem em branco é exibido.

::: moniker-end

## <a name="use-the-functionality-from-the-static-library-in-the-app"></a><a name="UseLibInApp"></a>Usar a funcionalidade da biblioteca estática no aplicativo

### <a name="to-use-the-functionality-from-the-static-library-in-the-app"></a>Para usar a funcionalidade da biblioteca estática no aplicativo

1. Antes de poder usar as rotinas matemáticas na biblioteca estática, você deve fazer referência a ela. Abra o menu de atalho do projeto **MathClient** no **Gerenciador de soluções**e, em seguida, escolha **Adicionar** > **referência**.

1. A caixa de diálogo **Adicionar referência** lista as bibliotecas que você pode referenciar. A guia **projetos** lista os projetos na solução atual e todas as bibliotecas que eles referenciam. Abra a guia **projetos** , marque a caixa de seleção **MathLibrary** e escolha o botão **OK** .

1. Para fazer referência `MathLibrary.h` ao arquivo de cabeçalho, você deve modificar o caminho dos diretórios incluídos. No **Gerenciador de soluções**, clique com o botão direito do mouse em **MathClient** para abrir o menu de atalho. Escolha **Propriedades** para abrir a caixa de diálogo **páginas de propriedades do MathClient** .

1. Na caixa de diálogo **páginas de propriedades do MathClient** , defina a lista suspensa **configuração** para **todas as configurações**. Defina a lista suspensa **plataforma** para **todas as plataformas**.

1. Selecione a página de propriedade**geral** **C/C++** >  **Propriedades** > de configuração. Na propriedade **incluir diretórios adicionais** , especifique o caminho do diretório **MathLibrary** ou procure-o.

   Para procurar o caminho do diretório:

   1. Abra a lista suspensa valor da propriedade de **diretórios de inclusão adicionais** e escolha **Editar**.

   1. Na caixa de diálogo **diretórios de inclusão adicionais** , clique duas vezes na parte superior da caixa de texto. Em seguida, escolha o botão de reticências (**...**) no final da linha.

   1. Na caixa de diálogo **Selecionar diretório** , navegue até um nível e selecione o diretório **MathLibrary** . Em seguida, escolha o botão **Selecionar pasta** para salvar sua seleção.

   1. Na caixa de diálogo **diretórios de inclusão adicionais** , escolha o botão **OK** .

   1. Na caixa de diálogo **páginas de propriedades** , escolha o botão **OK** para salvar as alterações no projeto.

1. Agora você pode usar a `Arithmetic` classe neste aplicativo incluindo o `#include "MathLibrary.h"` cabeçalho em seu código. Substitua o conteúdo de `MathClient.cpp` por este código:

    ```cpp
    // MathClient.cpp
    // compile with: cl /EHsc MathClient.cpp /link MathLibrary.lib

    #include <iostream>
    #include "MathLibrary.h"

    int main()
    {
        double a = 7.4;
        int b = 99;

        std::cout << "a + b = " <<
            MathLibrary::Arithmetic::Add(a, b) << std::endl;
        std::cout << "a - b = " <<
            MathLibrary::Arithmetic::Subtract(a, b) << std::endl;
        std::cout << "a * b = " <<
            MathLibrary::Arithmetic::Multiply(a, b) << std::endl;
        std::cout << "a / b = " <<
            MathLibrary::Arithmetic::Divide(a, b) << std::endl;

        return 0;
    }
    ```

1. Para criar o executável, escolha **criar** > **solução de compilação** na barra de menus.

## <a name="run-the-app"></a><a name="RunApp"></a>Executar o aplicativo

### <a name="to-run-the-app"></a>Para executar o aplicativo

1. Verifique se **MathClient** está selecionado como o projeto padrão. Para selecioná-lo, clique com o botão direito do mouse para abrir o menu de atalho para **MathClient** em **Gerenciador de soluções**e escolha **definir como projeto de inicialização**.

1. Para executar o projeto, na barra de menus, escolha **depurar** > **Iniciar sem depuração**. A saída deve ser semelhante a:

    ```Output
    a + b = 106.4
    a - b = -91.6
    a * b = 732.6
    a / b = 0.0747475
    ```

## <a name="see-also"></a>Confira também

[Walkthrough: Criando e usando uma biblioteca de vínculo dinâmico (C++)](../build/walkthrough-creating-and-using-a-dynamic-link-library-cpp.md)<br/>
[Aplicativos de área de trabalho (Visual C++)](../windows/desktop-applications-visual-cpp.md)<br/>
