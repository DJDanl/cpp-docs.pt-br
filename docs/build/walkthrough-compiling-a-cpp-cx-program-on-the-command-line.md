---
title: 'Passo a passo: Compilando um C + + CX programa na linha de comando | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 626f5544-69ed-4736-83a9-f11389b371b2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0963f70047ea42893b1169c5da7c614766406280
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="walkthrough-compiling-a-ccx-program-on-the-command-line"></a>Instruções passo a passo: compilando um programa do C++/CX na linha de comando
Você pode criar programas Visual C++ destinados ao Windows Runtime e compilá-los na linha de comando. O Visual C++ oferece suporte a extensões de componente do Visual C++ (C++/CX), que possuem tipos e operadores adicionais destinados ao modelo de programação do Windows Runtime. Você pode usar C + + para criar aplicativos para Windows UWP (plataforma Universal), Windows Phone 8.1 e Windows desktop. Para obter mais informações, consulte [um Tour do c++ /CLI CX](http://msdn.microsoft.com/magazine/dn166929.aspx) e [extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md).  
  
 Neste passo a passo, você usa um editor de texto para criar um programa de C++/CX básico e, em seguida, o compila na linha de comandos. (Você pode usar seu próprio programa de C++/CX ao invés de digitar o que é mostrado ou, ainda, usar uma amostra de código de C++/CX de outro artigo de ajuda. Essa técnica é útil para compilar e testar pequenos módulos que não contêm elementos de interface do usuário.)  
  
> [!NOTE]
>  Você também pode usar o Visual Studio IDE para compilar programas em C++/CX. Como o IDE inclui o design, depuração, emulação e suporte de implantação que não está disponível na linha de comando, é recomendável que você usar o IDE para criar aplicativos do Windows UWP (plataforma Universal). Para obter mais informações, consulte [criar um aplicativo UWP em C++](/windows/uwp/get-started/create-a-basic-windows-10-app-in-cpp).  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Você deve conhecer os princípios básicos da linguagem C++.  
  
## <a name="compiling-a-ccx-program"></a>Compilando um programa C++/CX  
 Para habilitar a compilação de C + + CX, você deve usar o [/ZW](../build/reference/zw-windows-runtime-compilation.md) opção de compilador. O compilador do Visual C++ gera um arquivo .exe destinado ao Tempo de Execução do Windows e vincula às bibliotecas necessárias.  
  
#### <a name="to-compile-a-ccx-application-on-the-command-line"></a>Para compilar um aplicativo em C++/CX na linha de comando  
  
1.  Abra um **Prompt de comando do desenvolvedor** janela. (No **iniciar** janela, abra **aplicativos**. Abra o **ferramentas do Visual Studio** pasta em sua versão do [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)]e, em seguida, escolha o **Prompt de comando do desenvolvedor** atalho.) Para obter mais informações sobre como abrir uma janela de Prompt de comando do desenvolvedor, consulte [código C/C++ compilar na linha de comando](../build/building-on-the-command-line.md).  
  
     As credenciais de administrador podem ser necessárias para compilar o código com êxito, dependendo do sistema operacional e da configuração do computador. Para executar a janela de Prompt de comando como administrador, abra o menu de atalho **Prompt de comando do desenvolvedor** e, em seguida, escolha **executar como administrador**.  
  
2.  No prompt de comando, digite **basiccx.cpp o bloco de notas**.  
  
     Escolha **Sim** quando for solicitado para criar um arquivo.  
  
3.  No Bloco de Notas, insira estas linhas:  
  
    ```cpp  
    using namespace Platform;  
  
    int main(Platform::Array<Platform::String^>^ args)  
    {  
        Platform::Details::Console::WriteLine("This is a C++/CX program.");  
    }  
  
    ```  
  
4.  Na barra de menus, escolha **arquivo**, **salvar**.  
  
     Você criou um arquivo de origem do Visual C++ que usa o tempo de execução do Windows [namespace de plataforma](../cppcx/platform-namespace-c-cx.md) namespace.  
  
5.  No prompt de comando, digite **cl /EHsc /ZW basiccx.cpp /link /Subsystem**. O compilador cl.exe compila o código-fonte em um arquivo .obj e executa o vinculador para gerar um programa executável denominado basiccx.exe. (O [/EHsc](../build/reference/eh-exception-handling-model.md) opção de compilador Especifica o modelo de tratamento de exceções do C++ e o [/link](../build/reference/link-pass-options-to-linker.md) sinalizador Especifica um aplicativo de console.)  
  
6.  Para executar o programa basiccx.exe, no prompt de comando, digite **basiccx**.  
  
     O programa exibe este texto e é fechado:  
  
    ```Output  
    This is a C++/CX program.  
    ```  
  
## <a name="see-also"></a>Consulte também  
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Compilando programas C/C++](../build/building-c-cpp-programs.md)   
 [Opções do Compilador](../build/reference/compiler-options.md)