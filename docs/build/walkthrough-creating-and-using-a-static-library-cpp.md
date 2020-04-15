---
title: 'Passo a passo: Crie e use uma biblioteca estática (C++)'
description: Use C++ para criar uma biblioteca estática (.lib) no Visual Studio.
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
# <a name="walkthrough-create-and-use-a-static-library"></a>Passo a passo: Crie e use uma biblioteca estática

Este passo a passo mostra como criar uma biblioteca estática (arquivo.lib) para uso com aplicativos C++. Usar uma biblioteca estática é uma ótima maneira de reutilizar o código. Em vez de reimplementar as mesmas rotinas em todos os aplicativos que exigem a funcionalidade, você as escreve uma vez em uma biblioteca estática e, em seguida, referencia-as a partir dos aplicativos. O código vinculado a partir de uma biblioteca estática torna-se parte do seu aplicativo — você não precisa instalar outro arquivo para usar o código.

Este passo a passo apresenta estas tarefas:

- [Crie um projeto de biblioteca estática](#CreateLibProject)

- [Adicione uma classe à biblioteca estática](#AddClassToLib)

- [Crie um aplicativo de console C++ que faz referência à biblioteca estática](#CreateAppToRefTheLib)

- [Use a funcionalidade da biblioteca estática no aplicativo](#UseLibInApp)

- [Executar o aplicativo](#RunApp)

## <a name="prerequisites"></a>Pré-requisitos

Uma compreensão dos fundamentos da linguagem C++.

## <a name="create-a-static-library-project"></a><a name="CreateLibProject"></a>Crie um projeto de biblioteca estática

As instruções de como criar o projeto variam dependendo da sua versão do Visual Studio. Para ver a documentação da sua versão preferida do Visual Studio, use o controle do seletor **de versão.** É encontrado no topo da tabela de conteúdo nesta página.

::: moniker range="vs-2019"

### <a name="to-create-a-static-library-project-in-visual-studio-2019"></a>Para criar um projeto de biblioteca estática no Visual Studio 2019

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Criar um novo projeto**.

1. Na parte superior da caixa de diálogo, defina **Linguagem** como **C++**, **Plataforma** como **Windows** e **Tipo de projeto** como **Biblioteca**.

1. Na lista filtrada de tipos de projeto, selecione **O Assistente de Desktop do Windows**e escolha **Next**.

1. Na **página Configurar sua nova** página de projeto, digite *MathLibrary* na caixa **nome do Projeto** para especificar um nome para o projeto. Digite *StaticMath* na **caixa de nome da solução.** Escolha o botão **Criar** para abrir a caixa de diálogo Projeto de Desktop do **Windows.**

1. Na caixa de diálogo Projeto de Desktop do **Windows,** no **tipo de aplicativo,** selecione **Biblioteca Estática (.lib)**.

1. Em **opções adicionais,** desverifique a caixa de seleção **de cabeçalho pré-compilada** se ela for verificada. Verifique a caixa **do projeto Vazio.**

1. Escolha **OK** para criar o projeto.

::: moniker-end

::: moniker range="vs-2017"

### <a name="to-create-a-static-library-project-in-visual-studio-2017"></a>Para criar um projeto de biblioteca estática no Visual Studio 2017

1. Na barra de menu, escolha **Arquivo** > **Novo** > **Projeto**.

1. Na caixa de diálogo **Novo Projeto,** selecione **Visual** > **C++** > **Windows Desktop**instalado . No painel central, escolha **Assistente do Windows Desktop**.

1. Especifique um nome para o projeto — por exemplo, *MathLibrary*— na caixa **Nome.** Especifique um nome para a solução — por exemplo, *StaticMath*— na **caixa Nome da solução.** Clique no botão **OK**.

1. Na caixa de diálogo Projeto de Desktop do **Windows,** no **tipo de aplicativo,** selecione **Biblioteca Estática (.lib)**.

1. Em **Opções adicionais,** desverifique a caixa de seleção **de cabeçalho pré-compilada** se ela for verificada. Verifique a caixa **do projeto Vazio.**

1. Escolha **OK** para criar o projeto.

::: moniker-end

::: moniker range="vs-2015"

### <a name="to-create-a-static-library-project-in-visual-studio-2015"></a>Para criar um projeto de biblioteca estática no Visual Studio 2015

1. Na barra de menu, escolha **Arquivo** > **Novo** > **Projeto**.

1. Na caixa de diálogo **Novo Projeto,** selecione**Modelos** >  **instalados** > **Visual C++** > **Win32**. No painel central, escolha **Aplicativo de Console Win32**.

1. Especifique um nome para o projeto — por exemplo, *MathLibrary*— na caixa **Nome.** Especifique um nome para a solução — por exemplo, *StaticMath*— na **caixa Nome da solução.** Clique no botão **OK**.

1. No **assistente de aplicativo Win32,** escolha **Next**.

1. Na página **Configurações** do aplicativo, em **tipo de aplicativo,** selecione **Biblioteca estática**. Em **opções adicionais,** desverifique a caixa de seleção **de cabeçalho pré-compilada.** Escolha **Terminar** para criar o projeto.

::: moniker-end

## <a name="add-a-class-to-the-static-library"></a><a name="AddClassToLib"></a>Adicione uma classe à biblioteca estática

### <a name="to-add-a-class-to-the-static-library"></a>Para adicionar uma classe à biblioteca estática

1. Para criar um arquivo de cabeçalho para uma nova classe, clique com o botão direito do mouse para abrir o menu de atalho para o projeto **MathLibrary** no **Solution Explorer**e, em seguida, escolha **Adicionar** > **novo item**.

1. Na caixa de diálogo **Adicionar novo item,** selecione **Código Visual C++.** > **Code** No painel central, escolha **Arquivo de Cabeçalho (.h)**. Especifique um nome para o arquivo de cabeçalho — por exemplo, *MathLibrary.h*— e escolha o botão **Adicionar.** Um arquivo de cabeçalho quase em branco é exibido.

1. Adicione uma declaração `Arithmetic` para uma classe nomeada para fazer operações matemáticas comuns, como adição, subtração, multiplicação e divisão. O código deve se assemelhar:

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

1. Para criar um arquivo de origem para a nova classe, abra o menu de atalho para o projeto **MathLibrary** no **Solution Explorer**e escolha **Adicionar** > **novo item**.

1. Na caixa de diálogo **Adicionar novo item,** no painel central, selecione **Arquivo C++ (.cpp)**. Especifique um nome para o arquivo de origem — por exemplo, *MathLibrary.cpp*— e escolha o botão **Adicionar.** Um arquivo de origem em branco é exibido.

1. Use este arquivo de origem para `Arithmetic`implementar a funcionalidade para classe . O código deve se assemelhar:

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

1. Para construir a biblioteca estática, selecione **Build** > **Build Solution** na barra de menus. A compilação cria uma biblioteca estática, *MathLibrary.lib*, que pode ser usada por outros programas.

   > [!NOTE]
   > Quando você constrói na linha de comando do Visual Studio, você deve construir o programa em duas etapas. Primeiro, `cl /c /EHsc MathLibrary.cpp` execute para compilar o código e criar um arquivo de objeto chamado *MathLibrary.obj*. (O `cl` comando invoca o compilador, Cl.exe, e a `/c` opção especifica compilação sem vinculação. Para obter mais informações, consulte [/c (Compilar sem vincular)](../build/reference/c-compile-without-linking.md).) Em segundo `lib MathLibrary.obj` lugar, execute para vincular o código e criar a biblioteca estática *MathLibrary.lib*. (O `lib` comando invoca o Gerente da Biblioteca, Lib.exe. Para obter mais informações, consulte [REFERÊNCIA LIB](../build/reference/lib-reference.md).)

## <a name="create-a-c-console-app-that-references-the-static-library"></a><a name="CreateAppToRefTheLib"></a>Crie um aplicativo de console C++ que faz referência à biblioteca estática

::: moniker range="vs-2019"

### <a name="to-create-a-c-console-app-that-references-the-static-library-in-visual-studio-2019"></a>Para criar um aplicativo de console C++ que faz referência à biblioteca estática no Visual Studio 2019

1. No **Solution Explorer**, clique com o botão direito do mouse no nó superior, Solução **'StaticMath'**, para abrir o menu de atalho. Escolha **Adicionar** > **novo projeto** para abrir a caixa de diálogo Adicionar um novo **projeto.**

1. Na parte superior da caixa de diálogo, defina o filtro **tipo Projeto** como **Console**.

1. Na lista filtrada de tipos de projeto, escolha **Aplicativo de Console** e, em seguida, escolha **Avançar**. Na página seguinte, *digite MathClient* na caixa **Nome** para especificar um nome para o projeto.

1. Escolha o botão **Criar** para criar o projeto do cliente.

1. Depois que você cria um aplicativo de console, o sistema cria um programa vazio para você. O nome do arquivo de origem será o mesmo que você escolheu anteriormente. No exemplo, é chamado `MathClient.cpp`.

::: moniker-end

::: moniker range="vs-2017"

### <a name="to-create-a-c-console-app-that-references-the-static-library-in-visual-studio-2017"></a>Para criar um aplicativo de console C++ que faz referência à biblioteca estática no Visual Studio 2017

1. No **Solution Explorer**, clique com o botão direito do mouse no nó superior, Solução **'StaticMath'**, para abrir o menu de atalho. Escolha **Adicionar** > **novo projeto** para abrir a caixa de diálogo Adicionar um novo **projeto.**

1. Na caixa de diálogo **Adicionar novo projeto,** selecione **Visual** > **C++** > **Windows Desktop**instalado . No painel central, escolha **Assistente do Windows Desktop**.

1. Especifique um nome para o projeto — por exemplo, *MathClient*— na caixa **Nome.** Clique no botão **OK**.

1. Na caixa de diálogo Do Projeto de Trabalho do **Windows,** no **tipo de aplicativo,** selecione **Aplicativo de console (.exe)**.

1. Em **Opções adicionais,** desverifique a caixa de seleção **de cabeçalho pré-compilada** se ela for verificada.

1. Escolha **OK** para criar o projeto.

1. Depois que você cria um aplicativo de console, o sistema cria um programa vazio para você. O nome do arquivo de origem será o mesmo que você escolheu anteriormente. No exemplo, é chamado `MathClient.cpp`.

::: moniker-end

::: moniker range="vs-2015"

### <a name="to-create-a-c-console-app-that-references-the-static-library-in-visual-studio-2015"></a>Para criar um aplicativo de console C++ que faz referência à biblioteca estática no Visual Studio 2015

1. No **Solution Explorer**, clique com o botão direito do mouse no nó superior, Solução **'StaticMath'**, para abrir o menu de atalho. Escolha **Adicionar** > **novo projeto** para abrir a caixa de diálogo Adicionar um novo **projeto.**

1. Na caixa de diálogo **Adicionar novo projeto,** selecione**Visual C++** > **Win32** **instalado** > . No painel central, escolha **Aplicativo de Console Win32**.

1. Especifique um nome para o projeto — por exemplo, *MathClient*— na caixa **Nome.** Clique no botão **OK**.

1. Na caixa de diálogo **Assistente do aplicativo Win32,** escolha **Next**.

1. Na página Configurações do **aplicativo,** em **Tipo de aplicativo,** **certifique-se de** que o aplicativo console esteja selecionado. Em **Opções adicionais,** desmarcar **cabeçalho pré-compilado**e, em seguida, verifique a caixa de seleção **Do Projeto Vazio.** Escolha **Terminar** para criar o projeto.

1. Para adicionar um arquivo de origem ao projeto vazio, clique com o botão direito do mouse para abrir o menu de atalho para o projeto **MathClient** no **Solution Explorer**e, em seguida, escolha **Adicionar** > **novo item**.

1. Na caixa de diálogo **Adicionar novo item,** selecione **Código Visual C++.** > **Code** No painel central, selecione **Arquivo C++ (.cpp)**. Especifique um nome para o arquivo de origem — por exemplo, *MathClient.cpp*— e escolha o botão **Adicionar.** Um arquivo de origem em branco é exibido.

::: moniker-end

## <a name="use-the-functionality-from-the-static-library-in-the-app"></a><a name="UseLibInApp"></a>Use a funcionalidade da biblioteca estática no aplicativo

### <a name="to-use-the-functionality-from-the-static-library-in-the-app"></a>Para usar a funcionalidade da biblioteca estática no aplicativo

1. Antes de usar as rotinas matemáticas na biblioteca estática, você deve referenciar. Abra o menu de atalho para o projeto **MathClient** no **Solution Explorer**e, em seguida, escolha **Adicionar** > **referência**.

1. A caixa de diálogo **Adicionar referência** lista as bibliotecas que você pode referenciar. A guia **Projetos** lista os projetos na solução atual e as bibliotecas que eles referenciam. Abra a guia **Projetos,** selecione a caixa de seleção **MathLibrary** e escolha o botão **OK.**

1. Para referenciar o `MathLibrary.h` arquivo de cabeçalho, você deve modificar o caminho dos diretórios incluídos. No **Solution Explorer,** clique com o botão direito do mouse no **MathClient** para abrir o menu de atalho. Escolha **Propriedades** para abrir a caixa de diálogo **MathClient Property Pages.**

1. Na caixa de diálogo **MathClient Property Pages,** defina a **invasões** de configuração em **todas as configurações**. Defina a **plataforma** de down-down para **todas as plataformas**.

1. Selecione a página de propriedade**C/C++** > **Geral** **de configuração.** >  Na propriedade **Adicional Incluir Diretórios,** especifique o caminho do diretório **MathLibrary** ou navegue por ele.

   Para procurar o caminho do diretório:

   1. Abra a lista de isto de valor de propriedade **''Incluir diretórios adicionais'** e, em seguida, escolha **Editar**.

   1. Na caixa de diálogo **Incluir diretórios adicionais,** clique duas vezes na parte superior da caixa de texto. Em seguida, escolha o botão ellipsis (**...**) no final da linha.

   1. Na caixa de diálogo **Selecionar diretório,** navegue até um nível e selecione o diretório **MathLibrary.** Em seguida, escolha o botão **Selecionar pasta** para salvar sua seleção.

   1. Na caixa de diálogo **Incluir diretórios adicionais,** escolha o botão **OK.**

   1. Na caixa de diálogo **Páginas** de propriedade, escolha o botão **OK** para salvar suas alterações no projeto.

1. Agora você pode `Arithmetic` usar a classe `#include "MathLibrary.h"` neste aplicativo, incluindo o cabeçalho em seu código. Substitua o `MathClient.cpp` conteúdo de este código:

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

1. Para construir o executável, escolha **Build** > **Build Solution** na barra de menus.

## <a name="run-the-app"></a><a name="RunApp"></a>Execute o aplicativo

### <a name="to-run-the-app"></a>Para executar o aplicativo

1. Certifique-se de que **o MathClient** seja selecionado como o projeto padrão. Para selecioná-lo, clique com o botão direito do mouse para abrir o menu de atalho para **MathClient** no **Solution Explorer**e, em seguida, escolha **Definir como Projeto startup**.

1. Para executar o projeto, na barra de menu, escolha **Depurar** > **Iniciar Sem Depuração**. A saída deve se assemelhar:

    ```Output
    a + b = 106.4
    a - b = -91.6
    a * b = 732.6
    a / b = 0.0747475
    ```

## <a name="see-also"></a>Confira também

[Passo a passo: Criando e Usando uma Biblioteca de Links Dinâmicos (C++)](../build/walkthrough-creating-and-using-a-dynamic-link-library-cpp.md)<br/>
[Aplicativos de área de trabalho (Visual C++)](../windows/desktop-applications-visual-cpp.md)<br/>
