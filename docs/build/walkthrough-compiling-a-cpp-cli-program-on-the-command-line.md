---
title: 'Passo a passo: Compilando um C + + CLI programa na linha de comando | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: cef41c88-faf9-439d-8423-25aa3f5674dd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 46e4b8d6341ad659596f7e83ab3cdcb89b18df2d
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34705300"
---
# <a name="walkthrough-compiling-a-ccli-program-on-the-command-line"></a>Instruções passo a passo: compilando um programa do C++/CLI na linha de comando

É possível criar programas Visual C++ que tenham CLR (Common Language Runtime) como destino e usem .NET Framework e depois compilá-los na linha de comando. O Visual C++ tem suporte à linguagem de programação C++/CLI, que possui tipos e operadores adicionais para atingir o modelo de programação .NET. Para obter informações gerais sobre o C + + linguagem CLI, consulte [programação .NET com C + + CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).

Neste passo a passo, você usa um editor de texto para criar um programa de C++/CLI básico e, em seguida, o compila na linha de comandos. (Você pode usar seu próprio programa de C++/CLI ao invés de digitar o que é mostrado ou, ainda, usar uma amostra de código de C++/CLI de outro artigo de ajuda. Essa técnica é útil para compilar e testar pequenos módulos que não contêm elementos de interface do usuário.)

> [!NOTE]
> Em seguida, é possível usar o Visual Studio IDE para compilar programas C++/CLI. Para obter mais informações, consulte [passo a passo: compilando um programa C++ que tem como alvo o CLR no Visual Studio](../ide/walkthrough-compiling-a-cpp-program-that-targets-the-clr-in-visual-studio.md).

## <a name="prerequisites"></a>Pré-requisitos

Você deve conhecer os princípios básicos da linguagem C++.

## <a name="compiling-a-ccli-program"></a>Compilando um programa C++/CLI

As etapas a seguir mostram como compilar um aplicativo de console C++/CLI que usa classes .NET Framework.

Para habilitar a compilação de C + + CLI, você deve usar o [/clr](../build/reference/clr-common-language-runtime-compilation.md) opção de compilador. O compilador do Visual C++ gera um arquivo .exe contendo código MSIL — ou MSIL misto e código nativo — e links para as bibliotecas .NET Framework.

### <a name="to-compile-a-ccli-application-on-the-command-line"></a>Para compilar um aplicativo C++/CLI na linha de comando

1. Abra um **Prompt de comando do desenvolvedor** janela. Para obter instruções específicas, consulte [para abrir uma janela de prompt de comando do desenvolvedor](../build/building-on-the-command-line.md#developer_command_prompt).

   As credenciais de administrador podem ser necessárias para compilar o código com êxito, dependendo do sistema operacional e da configuração do computador. Para executar a janela de prompt de comando como administrador, clique para abrir o menu de atalho do prompt de comando e, em seguida, escolha **mais**, **executar como administrador**.

1. No prompt de comando, digite **basicclr.cpp o bloco de notas**.

   Escolha **Sim** quando for solicitado para criar um arquivo.

1. No Bloco de Notas, insira estas linhas:

   ```cpp
   int main()
   {
       System::Console::WriteLine("This is a C++/CLI program.");
   }
   ```

1. Na barra de menus, escolha **arquivo**, **salvar**.

   Você criou um arquivo de origem do Visual C++ que usa uma classe .NET Framework (<xref:System.Console>) no namespace <xref:System>.

1. No prompt de comando, digite **cl /clr basicclr.cpp**. O compilador cl.exe compila o código-fonte em um arquivo .obj contendo MSIL e executa o vinculador para gerar um programa executável chamado basicclr.exe.

1. Para executar o programa basicclr.exe, no prompt de comando, digite **basicclr**.

   O programa exibe este texto e é fechado:

   ```Output
   This is a C++/CLI program.
   ```

## <a name="see-also"></a>Consulte também

- [Referência da linguagem C++](../cpp/cpp-language-reference.md)
- [Compilando programas do C/C++](../build/building-c-cpp-programs.md)
- [Opções do Compilador](../build/reference/compiler-options.md)
