---
title: 'Passo a passo: Compilando um c++ CLI programa na linha de comando | Microsoft Docs'
ms.custom: ''
ms.date: 09/24/2018
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
ms.openlocfilehash: bdc09d5c1de2e74f7e24b72439910068fe9f6c1a
ms.sourcegitcommit: a738519aa491a493a8f213971354356c0e6a5f3a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/05/2018
ms.locfileid: "48820614"
---
# <a name="walkthrough-compiling-a-ccli-program-on-the-command-line"></a>Instruções passo a passo: compilando um programa do C++/CLI na linha de comando

É possível criar programas Visual C++ que tenham CLR (Common Language Runtime) como destino e usem .NET Framework e depois compilá-los na linha de comando. O Visual C++ tem suporte à linguagem de programação C++/CLI, que possui tipos e operadores adicionais para atingir o modelo de programação .NET. Para obter informações gerais sobre o C + + c++ /CLI linguagem CLI, consulte [programação do .NET com C + + c++ CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).

Neste passo a passo, você usa um editor de texto para criar um programa de C++/CLI básico e, em seguida, o compila na linha de comandos. (Você pode usar seu próprio programa de C++/CLI ao invés de digitar o que é mostrado ou, ainda, usar uma amostra de código de C++/CLI de outro artigo de ajuda. Essa técnica é útil para compilar e testar pequenos módulos que têm sem elementos de interface do usuário.)

> [!NOTE]
> Em seguida, é possível usar o Visual Studio IDE para compilar programas C++/CLI. Para obter mais informações, consulte [instruções passo a passo: compilando um programa C++ que se destina ao CLR no Visual Studio](../ide/walkthrough-compiling-a-cpp-program-that-targets-the-clr-in-visual-studio.md).

## <a name="prerequisites"></a>Pré-requisitos

Você entender os conceitos básicos da linguagem C++.

## <a name="compiling-a-ccli-program"></a>Compilando um programa C++/CLI

As etapas a seguir mostram como compilar um aplicativo de console C++/CLI que usa classes .NET Framework.

Para habilitar a compilação para c++ /CLI, você deve usar o [/clr](../build/reference/clr-common-language-runtime-compilation.md) opção de compilador. O compilador do Visual C++ gera um arquivo .exe contendo código MSIL — ou MSIL misto e código nativo — e links para as bibliotecas .NET Framework.

### <a name="to-compile-a-ccli-application-on-the-command-line"></a>Para compilar um aplicativo C++/CLI na linha de comando

1. Abra uma **Prompt de comando do desenvolvedor** janela. Para obter instruções específicas, consulte [para abrir uma janela de prompt de comando do desenvolvedor](../build/building-on-the-command-line.md#developer_command_prompt).

   As credenciais de administrador podem ser necessárias para compilar o código com êxito, dependendo do sistema operacional e da configuração do computador. Para executar a janela de prompt de comando como administrador, clique com botão direito para abrir o menu de atalho do prompt de comando e, em seguida, escolha **mais** > **executar como administrador**.

1. No prompt de comando, digite `notepad basicclr.cpp`.

   Escolher **Sim** quando você será solicitado a criar um arquivo.

1. No Bloco de Notas, insira estas linhas:

   ```cpp
   int main()
   {
       System::Console::WriteLine("This is a C++/CLI program.");
   }
   ```

1. Na barra de menus, escolha **arquivo** > **salvar**.

   Você criou um arquivo de origem do Visual C++ que usa uma classe do .NET Framework (<xref:System.Console>) na <xref:System> namespace.

1. No prompt de comando, digite `cl /clr basicclr.cpp`. O compilador cl.exe compila o código-fonte em um arquivo .obj contendo MSIL e executa o vinculador para gerar um programa executável chamado basicclr.exe.

1. Para executar o programa basicclr.exe, no prompt de comando, insira `basicclr`.

   O programa exibe este texto e é fechado:

   ```Output
   This is a C++/CLI program.
   ```

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Compilando programas do C/C++](../build/building-c-cpp-programs.md)<br/>
[Opções do Compilador](../build/reference/compiler-options.md)
