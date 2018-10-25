---
title: 'Passo a passo: Criando um programa C++ padrão (C++) | Microsoft Docs'
ms.custom: get-started-article
ms.date: 09/18/2018
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vcfirstapp
- vccreatefirst
dev_langs:
- C++
helpviewer_keywords:
- command-line applications [C++], standard
- standard applications [C++]
ms.assetid: 48217e35-d892-46b7-93e3-f6f0b7e2da35
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 800dd3b626a03ec3b04910f6c4c1bbea3e1ab17d
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50053513"
---
# <a name="walkthrough-creating-a-standard-c-program-c"></a>Passo a passo: Criando um programa C++ padrão (C++)

Você pode usar o Visual C++ no ambiente de desenvolvimento integrado (IDE) do Visual Studio para criar programas em C++ padrão. Seguindo as etapas neste passo a passo, você pode criar um projeto, adicione um novo arquivo ao projeto, modificar o arquivo para adicionar o código C++ e, em seguida, compilar e executar o programa usando o Visual Studio.

Você pode digitar seu próprio programa C++ ou use um dos programas de exemplo. O programa de exemplo neste passo a passo é um aplicativo de console. Esse aplicativo usa o `set` contêiner na biblioteca padrão C++.

Visual C++ segue o padrão de C++ de 2003, com as seguintes exceções principais: pesquisa de nome de dois estágios, especificações de exceção e exportação. Além disso, o Visual C++ oferece suporte a vários recursos do c++0x, por exemplo, lambdas, auto, static_assert, referências de rvalue e modelos extern.

> [!NOTE]
> Se a conformidade com o padrão é necessária, use o `/Za` opção de compilador desabilitar extensões da Microsoft para o padrão. Para obter mais informações, consulte [/Za, /Ze (desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md).

## <a name="prerequisites"></a>Pré-requisitos

Para concluir este passo a passo, você deve compreender os fundamentos da linguagem C++.

### <a name="to-create-a-project-and-add-a-source-file"></a>Para criar um projeto e adicionar um arquivo de origem

1. Criar um projeto apontando para **New** sobre o **arquivo** menu e, em seguida, clicando em **projeto**.

1. No **Visual C++** painel de tipos de projeto, clique em **área de trabalho do Windows**e, em seguida, clique em **aplicativo de Console do Windows**.

   > [!NOTE]
   > Para versões do Visual Studio anteriores a 2017, nos **novo projeto** diálogo caixa, expanda **instalado** > **modelos**  >  **Visual C++** e, em seguida, selecione **Win32**. No painel central, selecione **aplicativo do Console Win32**.

   Digite um nome para o projeto.

   Por padrão, a solução que contém o projeto tem o mesmo nome que o projeto, mas você pode digitar um nome diferente. Você também pode digitar um local diferente para o projeto.

   Clique em **OK** para criar o projeto.

   > [!NOTE]
   > Para versões do Visual Studio anteriores a 2017, conclua o **Assistente de aplicativo Win32**. Clique em **próxima**, certifique-se de **aplicativo de Console** está selecionado e desmarque a opção o **cabeçalhos pré-compilados** caixa. Clique em **Finalizar**.

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

**Anterior:** [Console aplicativos no Visual C++](../windows/console-applications-in-visual-cpp.md)<br/>
**Em seguida:** [passo a passo: compilando um programa C++ nativo na linha de comando](../build/walkthrough-compiling-a-native-cpp-program-on-the-command-line.md)<br/>

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)<br/>
