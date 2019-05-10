---
title: 'Passo a passo: Compilando um c++ /CLI programa CX na linha de comando'
ms.date: 04/23/2019
ms.assetid: 626f5544-69ed-4736-83a9-f11389b371b2
ms.openlocfilehash: cbf5a48de3c029e36fc6daabe2b3f0db55dc173c
ms.sourcegitcommit: 18d3b1e9cdb4fc3a76f7a650c31994bdbd2bde64
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/29/2019
ms.locfileid: "64877172"
---
# <a name="walkthrough-compiling-a-ccx-program-on-the-command-line"></a>Passo a passo: Compilando um c++ /CLI programa CX na linha de comando

> [!NOTE] 
> Para novos aplicativos UWP e componentes, é recomendável que você use [ C++/WinRT](/windows/uwp/cpp-and-winrt-apis/), uma padrão C + + 17 projeção de linguagem para APIs do Windows Runtime. C++/ WinRT está disponível no SDK do Windows 10, versão 1803 em diante. C++/ WinRT é implementado inteiramente em arquivos de cabeçalho e foi projetado para fornecer acesso de primeira classe à moderna API do Windows.

O Microsoft C++ dá suporte ao compilador (MSVC) C++ extensões de componentes (C++/CX), que tem tipos e operadores adicionais destinados ao modelo de programação do tempo de execução do Windows. Você pode usar C++/CX para criar aplicativos para a plataforma Universal do Windows (UWP) e área de trabalho do Windows. Para obter mais informações, consulte [um Tour do c++ c++ /CX](https://msdn.microsoft.com/magazine/dn166929.aspx) e [extensões de componentes para plataformas de tempo de execução](../extensions/component-extensions-for-runtime-platforms.md).

Neste passo a passo, você usa um editor de texto para criar um programa de C++/CX básico e, em seguida, o compila na linha de comandos. (Você pode usar seu próprio programa de C++/CX ao invés de digitar o que é mostrado ou, ainda, usar uma amostra de código de C++/CX de outro artigo de ajuda. Essa técnica é útil para compilar e testar pequenos módulos que têm sem elementos de interface do usuário.)

> [!NOTE]
> Você também pode usar o Visual Studio IDE para compilar programas em C++/CX. Como o IDE inclui o design, depuração, emulação e suporte à implantação que não está disponível na linha de comando, é recomendável que você use o IDE para criar aplicativos de plataforma Universal do Windows (UWP). Para obter mais informações, consulte [criar um aplicativo UWP em C++](/windows/uwp/get-started/create-a-basic-windows-10-app-in-cpp).

## <a name="prerequisites"></a>Pré-requisitos

Você entender os conceitos básicos da linguagem C++.

## <a name="compiling-a-ccx-program"></a>Compilando um programa C++/CX

Para habilitar a compilação para C++/CX, você deve usar o [/ZW](reference/zw-windows-runtime-compilation.md) opção de compilador. O compilador MSVC gera um arquivo de .exe que tem como alvo o tempo de execução do Windows e contém links para as bibliotecas necessárias.

#### <a name="to-compile-a-ccx-application-on-the-command-line"></a>Para compilar um aplicativo em C++/CX na linha de comando

1. Abra uma **Prompt de comando do desenvolvedor** janela. (Sobre o **inicie** janela, abra **aplicativos**. Abra o **ferramentas do Visual Studio** pasta em sua versão do Visual Studio e, em seguida, escolha o **Prompt de comando do desenvolvedor** atalho.) Para obter mais informações sobre como abrir uma janela de Prompt de comando do desenvolvedor, consulte [usar o conjunto de ferramentas da linha de comando MSVC](building-on-the-command-line.md).

   As credenciais de administrador podem ser necessárias para compilar o código com êxito, dependendo do sistema operacional e da configuração do computador. Para executar a janela de Prompt de comando como administrador, abra o menu de atalho **Prompt de comando do desenvolvedor** e, em seguida, escolha **executar como administrador**.

1. No prompt de comando, digite **notepad basiccx**.

   Escolher **Sim** quando você será solicitado a criar um arquivo.

1. No Bloco de Notas, insira estas linhas:

    ```cpp
    using namespace Platform;

    int main(Platform::Array<Platform::String^>^ args)
    {
        Platform::Details::Console::WriteLine("This is a C++/CX program.");
    }
    ```

1. Na barra de menus, escolha **arquivo** > **salvar**.

   Você criou um C++ arquivo de origem que usa o tempo de execução do Windows [namespace Platform](../cppcx/platform-namespace-c-cx.md) namespace.

1. No prompt de comando, digite **cl /EHsc /ZW basiccx /link /Subsystem: console**. O compilador cl.exe compila o código-fonte em um arquivo .obj e executa o vinculador para gerar um programa executável denominado basiccx.exe. (O [/EHsc](reference/eh-exception-handling-model.md) opção de compilador Especifica o modelo de tratamento de exceções do C++ e o [/link](reference/link-pass-options-to-linker.md) sinalizador Especifica que um aplicativo de console.)

1. Para executar o programa basiccx.exe, no prompt de comando, digite **basiccx**.

   O programa exibe este texto e é fechado:

    ```Output
    This is a C++/CX program.
    ```

## <a name="see-also"></a>Consulte também

[Sistemas de Compilação e Projetos](projects-and-build-systems-cpp.md)<br/>
[Opções do compilador MSVC](reference/compiler-options.md)
