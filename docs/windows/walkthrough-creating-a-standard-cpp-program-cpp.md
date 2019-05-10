---
title: 'Passo a passo: Criando um programa C++ padrão (C++)'
ms.custom: get-started-article
ms.date: 04/25/2019
helpviewer_keywords:
- command-line applications [C++], standard
- standard applications [C++]
ms.assetid: 48217e35-d892-46b7-93e3-f6f0b7e2da35
ms.openlocfilehash: ed9c19dad029f8fc9495d38ab6e5c0ba8ad6d529
ms.sourcegitcommit: 18d3b1e9cdb4fc3a76f7a650c31994bdbd2bde64
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/29/2019
ms.locfileid: "64877413"
---
# <a name="walkthrough-creating-a-standard-c-program-c"></a>Passo a passo: Criando um programa C++ padrão (C++)

Você pode usar o Visual Studio para criar o padrão C++ programas. Seguindo as etapas neste passo a passo, você pode criar um projeto, adicione um novo arquivo ao projeto, modificar o arquivo para adicionar o código C++ e, em seguida, compilar e executar o programa usando o Visual Studio.

Você pode digitar seu próprio programa C++ ou use um dos programas de exemplo. O programa de exemplo neste passo a passo é um aplicativo de console. Esse aplicativo usa o `set` contêiner na biblioteca padrão C++.

> [!NOTE]
> Se a conformidade com uma versão específica do C++ idioma padrão (ou seja, C + + 14 ou C + + 17) é necessário, use o `/std:C++14` ou `/std:c++17` opção de compilador. (Visual Studio 2017 e posterior.)

## <a name="prerequisites"></a>Pré-requisitos

Para concluir este passo a passo, você deve compreender os fundamentos da linguagem C++.

### <a name="to-create-a-project-and-add-a-source-file"></a>Para criar um projeto e adicionar um arquivo de origem

As seguintes etapas variam, dependendo de qual versão do Visual Studio que você está usando. Verifique se que o seletor de versão no canto superior esquerdo dessa página está definido corretamente.

::: moniker range="vs-2019"

### <a name="to-create-a-c-project-in-visual-studio-2019"></a>Para criar um C++ projeto no Visual Studio de 2019

1. No menu principal, escolha **arquivo** > **New** > **projeto** para abrir o **criar um novo projeto** caixa de diálogo caixa.

1. Na parte superior da caixa de diálogo, defina **linguagem** à **C++**, defina **plataforma** para **Windows**e defina **tipodeprojeto** ao **Console**. 

1. Na lista filtrada de tipos de projeto, escolha **aplicativo de Console** , em seguida, escolha **próxima**. Na próxima página, insira um nome para o projeto e especifique o local do projeto, se desejado.

1. Escolha o **criar** botão para criar o projeto.

::: moniker-end

::: moniker range="vs-2017"

### <a name="to-create-a-c-project-in-visual-studio-2017"></a>Para criar um C++ projeto no Visual Studio 2017

1. Criar um projeto apontando para **New** sobre o **arquivo** menu e, em seguida, clicando em **projeto**.

1. No **Visual C++** painel de tipos de projeto, clique em **área de trabalho do Windows**e, em seguida, clique em **aplicativo de Console do Windows**.

1. Digite um nome para o projeto. Por padrão, a solução que contém o projeto tem o mesmo nome que o projeto, mas você pode digitar um nome diferente. Você também pode digitar um local diferente para o projeto.

1. Clique em **OK** para criar o projeto.

::: moniker-end

::: moniker range="vs-2015"

### <a name="to-create-a-c-project-in-visual-studio-2015"></a>Para criar um C++ projeto no Visual Studio 2015

1. Criar um projeto apontando para **New** sobre o **arquivo** menu e, em seguida, clicando em **projeto**.

1. No **Visual C++** painel de tipos de projeto, clique em **área de trabalho do Windows**e, em seguida, clique em **aplicativo de Console do Windows**.

1. No **novo projeto** diálogo caixa, expanda **instalado** > **modelos** > **Visual C++** , e em seguida, selecione **Win32**. No painel central, selecione **aplicativo do Console Win32**.

1. Digite um nome para o projeto. Por padrão, a solução que contém o projeto tem o mesmo nome que o projeto, mas você pode digitar um nome diferente. Você também pode digitar um local diferente para o projeto.

1. Clique em **OK** para criar o projeto.

1. Conclua o **Assistente de aplicativo Win32**. 

1. Clique em **próxima**, certifique-se de **aplicativo de Console** está selecionado e desmarque a opção o **cabeçalhos pré-compilados** caixa. 

1. Clique em **Finalizar**.

::: moniker-end

## <a name="add-a-new-source-file"></a>Adicione um novo arquivo de origem

1. Se **Gerenciador de soluções** não for exibido, na **exibição** menu, clique em **Gerenciador de soluções**.

1. Adicione um novo arquivo de origem ao projeto, da seguinte maneira.

   1. No **Gerenciador de soluções**, clique com botão direito do **arquivos de origem** pasta, aponte para **adicionar**e, em seguida, clique em **Novo Item**.

   1. No **código** nó, clique em **arquivo do C++ (. cpp)**, digite um nome para o arquivo e, em seguida, clique em **adicionar**.

   O arquivo. cpp aparece na **arquivos de origem** pasta nos **Gerenciador de soluções**, e o arquivo é aberto no editor do Visual Studio.

1. No arquivo no editor, digite um programa C++ válido que usa a biblioteca padrão C++, ou copie um dos programas de exemplo e cole-o no arquivo.

1. Salve o arquivo.

1. No menu **Compilar**, clique em **Compilar Solução**.

   O **saída** janela exibe informações sobre o andamento da compilação, por exemplo, o local do log de compilação e uma mensagem que indica o status da compilação.

1. No menu **Depuração**, clique em **Iniciar sem Depurar**.

   Se você usou o programa de exemplo, uma janela de comando é exibida e mostra se determinados inteiros estão localizados no conjunto.

## <a name="next-steps"></a>Próximas etapas

**Anterior:** [Aplicativos de console no Visual C++](../windows/console-applications-in-visual-cpp.md)<br/>
**Avançar:** [Passo a passo: Compilando um programa do C++ nativo na linha de comando](../build/walkthrough-compiling-a-native-cpp-program-on-the-command-line.md)<br/>

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)<br/>
