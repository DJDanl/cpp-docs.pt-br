---
title: 'Instruções passo a passo: compilando um programa do C++/CLI na linha de comando'
ms.date: 04/23/2019
ms.assetid: cef41c88-faf9-439d-8423-25aa3f5674dd
ms.openlocfilehash: 8a5c5659367350a80725b365ef9c431bbec209d1
ms.sourcegitcommit: 18d3b1e9cdb4fc3a76f7a650c31994bdbd2bde64
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/29/2019
ms.locfileid: "64877448"
---
# <a name="walkthrough-compiling-a-ccli-program-on-the-command-line"></a>Instruções passo a passo: compilando um programa do C++/CLI na linha de comando

É possível criar programas Visual C++ que tenham CLR (Common Language Runtime) como destino e usem .NET Framework e depois compilá-los na linha de comando. O Visual C++ tem suporte à linguagem de programação C++/CLI, que possui tipos e operadores adicionais para atingir o modelo de programação .NET. Para obter informações gerais sobre a linguagem C++/CLI, consulte [programação .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).

Neste passo a passo, você usa um editor de texto para criar um programa de C++/CLI básico e, em seguida, o compila na linha de comandos. (Você pode usar seu próprio programa de C++/CLI ao invés de digitar o que é mostrado ou, ainda, usar uma amostra de código de C++/CLI de outro artigo de ajuda. Essa técnica é útil para criar e testar módulos pequenos que não têm elementos de interface do usuário.)

## <a name="prerequisites"></a>Pré-requisitos

Você entende os conceitos básicos da linguagem C++.

## <a name="compiling-a-ccli-program"></a>Compilando um programa C++/CLI

As etapas a seguir mostram como compilar um aplicativo de console C++/CLI que usa classes .NET Framework.

Para habilitar a compilação para C++/CLI, você deve usar a opção de compilador [/CLR](reference/clr-common-language-runtime-compilation.md) . O compilador MSVC gera um arquivo. exe que contém o código MSIL — ou código nativo e MSIL misto — e links para as bibliotecas de .NET Framework necessárias.

### <a name="to-compile-a-ccli-application-on-the-command-line"></a>Para compilar um aplicativo C++/CLI na linha de comando

1. Abra uma janela de **prompt de comando do desenvolvedor** . Para obter instruções específicas, consulte [para abrir uma janela de prompt de comando do desenvolvedor](building-on-the-command-line.md#developer_command_prompt).

   As credenciais de administrador podem ser necessárias para compilar o código com êxito, dependendo do sistema operacional e da configuração do computador. Para executar a janela de prompt de comando como administrador, clique com o botão direito do mouse para abrir o menu de atalho do prompt de comando e escolha **mais** > **Executar como administrador**.

1. No prompt de comando, digite `notepad basicclr.cpp`.

   Escolha **Sim** quando for solicitado a criar um arquivo.

1. No Bloco de Notas, insira estas linhas:

   ```cpp
   int main()
   {
       System::Console::WriteLine("This is a C++/CLI program.");
   }
   ```

1. Na barra de menus, escolha **arquivo** > **salvar**.

   Você criou um arquivo de origem Visual C++ que usa uma classe .NET Framework (<xref:System.Console>) no <xref:System> namespace.

1. No prompt de comando, digite `cl /clr basicclr.cpp`. O compilador cl.exe compila o código-fonte em um arquivo .obj contendo MSIL e executa o vinculador para gerar um programa executável chamado basicclr.exe.

1. Para executar o programa basicclr.exe, no prompt de comando, insira `basicclr`.

   O programa exibe este texto e é fechado:

   ```Output
   This is a C++/CLI program.
   ```

## <a name="see-also"></a>Confira também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Sistemas de Compilação e Projetos](projects-and-build-systems-cpp.md)<br/>
[Opções do compilador MSVC](reference/compiler-options.md)
