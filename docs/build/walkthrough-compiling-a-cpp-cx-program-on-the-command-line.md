---
title: 'Instruções passo a passo: compilando um programa do C++/CX na linha de comando'
ms.date: 04/23/2019
ms.assetid: 626f5544-69ed-4736-83a9-f11389b371b2
ms.openlocfilehash: 456373fc9009920b734243f6a6c1af3d2c0301d4
ms.sourcegitcommit: 31a443c9998cf5cfbaff00fcf815b133f55b2426
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/14/2020
ms.locfileid: "86373678"
---
# <a name="walkthrough-compiling-a-ccx-program-on-the-command-line"></a>Instruções passo a passo: compilando um programa do C++/CX na linha de comando

> [!NOTE]
> Para novos aplicativos e componentes UWP, recomendamos que você use [C++/WinRT](/windows/uwp/cpp-and-winrt-apis/), uma projeção de linguagem c++ 17 padrão para APIs de Windows Runtime. O C++/WinRT está disponível no SDK do Windows 10 da versão 1803 em diante. O C++/WinRT é implementado inteiramente em arquivos de cabeçalho e foi projetado para fornecer a você acesso de primeira classe à API moderna do Windows.

O compilador do Microsoft C++ (MSVC) dá suporte a extensões de componente do C++ (C++/CX), que tem tipos e operadores adicionais para direcionar o modelo de programação de Windows Runtime. Você pode usar C++/CX para criar aplicativos para Plataforma Universal do Windows (UWP) e área de trabalho do Windows. Para obter mais informações, consulte [um tour pelo C++/CX](https://docs.microsoft.com/archive/msdn-magazine/2013/april/component-extensions-a-tour-of-c-cx) e [extensões de componente para plataformas de tempo de execução](../extensions/component-extensions-for-runtime-platforms.md).

Neste passo a passo, você usa um editor de texto para criar um programa de C++/CX básico e, em seguida, o compila na linha de comandos. (Você pode usar seu próprio programa de C++/CX ao invés de digitar o que é mostrado ou, ainda, usar uma amostra de código de C++/CX de outro artigo de ajuda. Essa técnica é útil para criar e testar módulos pequenos que não têm elementos de interface do usuário.)

> [!NOTE]
> Você também pode usar o Visual Studio IDE para compilar programas em C++/CX. Como o IDE inclui o suporte de design, depuração, emulação e implantação que não está disponível na linha de comando, recomendamos que você use o IDE para criar aplicativos Plataforma Universal do Windows (UWP). Para obter mais informações, consulte [criar um aplicativo UWP em C++](/windows/uwp/get-started/create-a-basic-windows-10-app-in-cpp).

## <a name="prerequisites"></a>Pré-requisitos

Você entende os conceitos básicos da linguagem C++.

## <a name="compiling-a-ccx-program"></a>Compilando um programa C++/CX

Para habilitar a compilação para C++/CX, você deve usar a opção de compilador [/zw](reference/zw-windows-runtime-compilation.md) . O compilador MSVC gera um arquivo. exe que tem como destino a Windows Runtime e links para as bibliotecas necessárias.

#### <a name="to-compile-a-ccx-application-on-the-command-line"></a>Para compilar um aplicativo em C++/CX na linha de comando

1. Abra uma janela de **prompt de comando do desenvolvedor** . (Na janela **Iniciar** , abra **aplicativos**. Abra a pasta **Ferramentas do Visual Studio** em sua versão do Visual Studio e escolha o atalho **prompt de comando do desenvolvedor** .) Para obter mais informações sobre como abrir uma janela de Prompt de Comando do Desenvolvedor, consulte [usar o conjunto de ferramentas MSVC na linha de comando](building-on-the-command-line.md).

   As credenciais de administrador podem ser necessárias para compilar o código com êxito, dependendo do sistema operacional e da configuração do computador. Para executar a janela de prompt de comando como administrador, abra o menu de atalho para **prompt de comando do desenvolvedor** e, em seguida, escolha **Executar como administrador**.

1. No prompt de comando, digite **notepad basiccx. cpp**.

   Escolha **Sim** quando for solicitado a criar um arquivo.

1. No Bloco de Notas, insira estas linhas:

    ```cpp
    using namespace Platform;

    int main(Platform::Array<Platform::String^>^ args)
    {
        Platform::Details::Console::WriteLine("This is a C++/CX program.");
    }
    ```

1. Na barra de menus, escolha **arquivo**  >  **salvar**.

   Você criou um arquivo de origem C++ que usa o namespace do Windows Runtime [Platform](../cppcx/platform-namespace-c-cx.md) namespace.

1. No prompt de comando, digite **CL/EHSC/zw basiccx. cpp/link/SUBSYSTEM: console**. O compilador cl.exe compila o código-fonte em um arquivo .obj e executa o vinculador para gerar um programa executável denominado basiccx.exe. (A opção de compilador [/EHsc](reference/eh-exception-handling-model.md) especifica o modelo de manipulação de exceções do C++ e o sinalizador [/link](reference/link-pass-options-to-linker.md) especifica um aplicativo de console.)

1. Para executar o programa basiccx.exe, no prompt de comando, digite **basiccx**.

   O programa exibe este texto e é fechado:

    ```Output
    This is a C++/CX program.
    ```

## <a name="see-also"></a>Confira também

[Sistemas de build e projetos](projects-and-build-systems-cpp.md)<br/>
[Opções do compilador MSVC](reference/compiler-options.md)
