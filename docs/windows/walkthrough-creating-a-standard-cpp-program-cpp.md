---
title: 'Passo a passo: criando um programa C++ padrão (C++)'
ms.custom: get-started-article
ms.date: 04/25/2019
helpviewer_keywords:
- command-line applications [C++], standard
- standard applications [C++]
ms.assetid: 48217e35-d892-46b7-93e3-f6f0b7e2da35
ms.openlocfilehash: 105ac62131b45afdea2a445b5888a344f1e4d46c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370220"
---
# <a name="walkthrough-creating-a-standard-c-program-c"></a>Passo a passo: criando um programa C++ padrão (C++)

Você pode usar o Visual Studio para criar programas Padrão C++. Seguindo as etapas deste passo a passo, você pode criar um projeto, adicionar um novo arquivo ao projeto, modificar o arquivo para adicionar código C++ e, em seguida, compilar e executar o programa usando o Visual Studio.

Você pode digitar seu próprio programa C++ ou usar um dos programas de amostra. O programa de exemplo neste passo a passo é um aplicativo de console. Este aplicativo `set` usa o recipiente na Biblioteca Padrão C++.

> [!NOTE]
> Se for necessária a conformidade com uma versão específica do padrão de idioma C++ (ou seja, `/std:c++14` `/std:c++17` C++14 ou C++17), use a opção ou compilador. (Visual Studio 2017 e posteriores.)

## <a name="prerequisites"></a>Pré-requisitos

Para concluir este passo a passo, você deve compreender os fundamentos da linguagem C++.

### <a name="to-create-a-project-and-add-a-source-file"></a>Para criar um projeto e adicionar um arquivo de origem

As etapas a seguir variam dependendo da versão do Visual Studio que você está usando. Para ver a documentação da sua versão preferida do Visual Studio, use o controle do seletor **de versão.** É encontrado no topo da tabela de conteúdo nesta página.

::: moniker range="vs-2019"

### <a name="to-create-a-c-project-in-visual-studio-2019"></a>Para criar um projeto C++ no Visual Studio 2019

1. No menu principal, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Criar um projeto**.

1. Na parte superior da caixa de diálogo, defina **Linguagem** como **C++**, **Plataforma** como **Windows** e **Tipo de projeto** como **Console**.

1. Na lista filtrada de tipos de projeto, escolha **Aplicativo de Console** e, em seguida, escolha **Avançar**. Na página seguinte, digite um nome para o projeto e especifique o local do projeto se desejar.

1. Escolha o botão **Criar** para criar o projeto.

::: moniker-end

::: moniker range="vs-2017"

### <a name="to-create-a-c-project-in-visual-studio-2017"></a>Para criar um projeto C++ no Visual Studio 2017

1. Crie um projeto apontando para **Novo** no menu **Arquivo** e, em seguida, clicando **em Projeto**.

1. No painel de tipos de projeto **Visual C++,** clique no **Windows Desktop**e clique em Aplicativo do Console **do Windows**.

1. Digite um nome para o projeto. Por padrão, a solução que contém o projeto tem o mesmo nome do projeto, mas você pode digitar um nome diferente. Você também pode digitar um local diferente para o projeto.

1. Clique em **OK** para criar o projeto.

::: moniker-end

::: moniker range="vs-2015"

### <a name="to-create-a-c-project-in-visual-studio-2015"></a>Para criar um projeto C++ no Visual Studio 2015

1. Crie um projeto apontando para **Novo** no menu **Arquivo** e, em seguida, clicando **em Projeto**.

1. No painel de tipos de projeto **Visual C++,** clique no **Windows Desktop**e clique em Aplicativo do Console **do Windows**.

1. Na caixa de diálogo **Novo Projeto,** expanda**os modelos** >  **instalados** > **Visual C++** e selecione **Win32**. No painel central, escolha **Aplicativo de Console Win32**.

1. Digite um nome para o projeto. Por padrão, a solução que contém o projeto tem o mesmo nome do projeto, mas você pode digitar um nome diferente. Você também pode digitar um local diferente para o projeto.

1. Clique em **OK** para criar o projeto.

1. Complete o **Assistente de Aplicativo Win32**.

1. Clique **em Next,** e **certifique-se de** que o aplicativo de console está selecionado e desmarcar a caixa De **cabeçalho pré-compilado.**

1. Clique em **Concluir**.

::: moniker-end

## <a name="add-a-new-source-file"></a>Adicionar um novo arquivo de origem

1. Se **o Solution Explorer** não for exibido, no menu **Exibir,** clique em **Solution Explorer**.

1. Adicione um novo arquivo de origem ao projeto, da seguinte forma.

   1. No **Solution Explorer,** clique com o botão direito do mouse na pasta **Arquivos de origem,** aponte para **Adicionar**e clique em **Novo Item**.

   1. No nó **Código,** clique em **Arquivo C++ (.cpp)**, digite um nome para o arquivo e clique em **Adicionar**.

   O arquivo .cpp aparece na pasta **Arquivos de origem** no Solution **Explorer**, e o arquivo é aberto no editor do Visual Studio.

1. No arquivo do editor, digite um programa C++ válido que use a Biblioteca Padrão C++ ou copie um dos programas de exemplo e cole-o no arquivo.

1. Salve o arquivo.

1. No menu **Compilar**, clique em **Compilar Solução**.

   A **janela Saída** exibe informações sobre o progresso da compilação, por exemplo, a localização do registro de compilação e uma mensagem que indica o status de compilação.

1. No menu **Depuração**, clique em **Iniciar sem Depurar**.

   Se você usou o programa de amostra, uma janela de comando será exibida e mostrará se certos inteiros são encontrados no conjunto.

## <a name="next-steps"></a>Próximas etapas

**Anterior:** [Aplicativos de console no Visual C++](../windows/console-applications-in-visual-cpp.md)<br/>
**Próximo passo** [a passo: compilando um programa Nativo C++ na Linha de Comando](../build/walkthrough-compiling-a-native-cpp-program-on-the-command-line.md)

## <a name="see-also"></a>Confira também

[Referência de linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca Padrão C++](../standard-library/cpp-standard-library-reference.md)
