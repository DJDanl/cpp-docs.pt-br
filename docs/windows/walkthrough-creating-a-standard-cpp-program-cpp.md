---
title: 'Walkthrough: Criando um programa C++ padrão (C++)'
ms.custom: get-started-article
ms.date: 04/25/2019
helpviewer_keywords:
- command-line applications [C++], standard
- standard applications [C++]
ms.assetid: 48217e35-d892-46b7-93e3-f6f0b7e2da35
ms.openlocfilehash: 381fa347a4ca2872ef0697d76a1e788c97e8a014
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80075436"
---
# <a name="walkthrough-creating-a-standard-c-program-c"></a>Walkthrough: Criando um programa C++ padrão (C++)

Você pode usar o Visual Studio para criar C++ programas padrão. Seguindo as etapas neste passo a passos, você pode criar um projeto, adicionar um novo arquivo ao projeto, modificar o arquivo para adicionar C++ código e, em seguida, compilar e executar o programa usando o Visual Studio.

Você pode digitar seu próprio C++ programa ou usar um dos programas de exemplo. O programa de exemplo neste passo a passo é um aplicativo de console. Esse aplicativo usa o contêiner `set` na biblioteca C++ padrão.

> [!NOTE]
> Se a conformidade com uma versão específica do C++ padrão de idioma (ou seja, c++ 14 ou c++ 17) for necessária, use a opção de compilador `/std:c++14` ou `/std:c++17`. (Visual Studio 2017 e posterior.)

## <a name="prerequisites"></a>Prerequisites

Para concluir este passo a passo, você deve compreender os fundamentos da linguagem C++.

### <a name="to-create-a-project-and-add-a-source-file"></a>Para criar um projeto e adicionar um arquivo de origem

As etapas a seguir variam dependendo da versão do Visual Studio que você está usando. Verifique se o seletor de versão no canto superior esquerdo desta página está definido corretamente.

::: moniker range="vs-2019"

### <a name="to-create-a-c-project-in-visual-studio-2019"></a>Para criar um C++ projeto no Visual Studio 2019

1. No menu principal, escolha **arquivo** > **novo** **projeto** de > para abrir a caixa de diálogo **criar um novo projeto** .

1. Na parte superior da caixa de diálogo, defina **Linguagem** como **C++** , **Plataforma** como **Windows** e **Tipo de projeto** como **Console**.

1. Na lista filtrada de tipos de projeto, escolha **Aplicativo de Console** e, em seguida, escolha **Avançar**. Na próxima página, insira um nome para o projeto e especifique o local do projeto, se desejado.

1. Escolha o botão **Criar** para criar o projeto.

::: moniker-end

::: moniker range="vs-2017"

### <a name="to-create-a-c-project-in-visual-studio-2017"></a>Para criar um C++ projeto no Visual Studio 2017

1. Crie um projeto apontando para **novo** no menu **arquivo** e, em seguida, clicando em **projeto**.

1. No painel tipos de projeto  **C++ Visual** , clique em **área de trabalho do Windows**e em aplicativo de console do **Windows**.

1. Digite um nome para o projeto. Por padrão, a solução que contém o projeto tem o mesmo nome que o projeto, mas você pode digitar um nome diferente. Você também pode digitar um local diferente para o projeto.

1. Clique em **OK** para criar o projeto.

::: moniker-end

::: moniker range="vs-2015"

### <a name="to-create-a-c-project-in-visual-studio-2015"></a>Para criar um C++ projeto no Visual Studio 2015

1. Crie um projeto apontando para **novo** no menu **arquivo** e, em seguida, clicando em **projeto**.

1. No painel tipos de projeto  **C++ Visual** , clique em **área de trabalho do Windows**e em aplicativo de console do **Windows**.

1. Na caixa de diálogo **novo projeto** , expanda **instalado** os **modelos** de >  > **Visual C++** e, em seguida, selecione **Win32**. No painel central, escolha **Aplicativo de Console Win32**.

1. Digite um nome para o projeto. Por padrão, a solução que contém o projeto tem o mesmo nome que o projeto, mas você pode digitar um nome diferente. Você também pode digitar um local diferente para o projeto.

1. Clique em **OK** para criar o projeto.

1. Conclua o **Assistente de aplicativo Win32**.

1. Clique em **Avançar**e verifique se **aplicativo de console** está selecionado e desmarque a caixa **cabeçalhos pré-compilados** .

1. Clique em **Concluir**.

::: moniker-end

## <a name="add-a-new-source-file"></a>Adicionar um novo arquivo de origem

1. Se **Gerenciador de soluções** não for exibido, no menu **Exibir** , clique em **Gerenciador de soluções**.

1. Adicione um novo arquivo de origem ao projeto, da seguinte maneira.

   1. Em **Gerenciador de soluções**, clique com o botão direito do mouse na pasta **arquivos de origem** , aponte para **Adicionar**e clique em **novo item**.

   1. No nó de **código** , clique em  **C++ arquivo (. cpp)** , digite um nome para o arquivo e clique em **Adicionar**.

   O arquivo. cpp aparece na pasta **arquivos de origem** em **Gerenciador de soluções**e o arquivo é aberto no editor do Visual Studio.

1. No arquivo no editor, digite um programa válido C++ que use a C++ biblioteca padrão ou copie um dos programas de exemplo e cole-o no arquivo.

1. Salve o arquivo.

1. No menu **Compilar**, clique em **Compilar Solução**.

   A janela **saída** exibe informações sobre o progresso da compilação, por exemplo, o local do log de compilação e uma mensagem que indica o status da compilação.

1. No menu **Depuração**, clique em **Iniciar sem Depurar**.

   Se você usou o programa de exemplo, uma janela de comando será exibida e mostrará se determinados inteiros foram encontrados no conjunto.

## <a name="next-steps"></a>Próximas etapas

**Anterior:** [aplicativos de console no C++ Visual](../windows/console-applications-in-visual-cpp.md)<br/>
**Próximo:** [passo a passos: Compilando um programa nativo C++ na linha de comando](../build/walkthrough-compiling-a-native-cpp-program-on-the-command-line.md)

## <a name="see-also"></a>Confira também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
