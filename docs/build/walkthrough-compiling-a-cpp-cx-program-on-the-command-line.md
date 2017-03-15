---
title: "Instru&#231;&#245;es passo a passo: compilando um programa do C++/CX na linha de comando | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 626f5544-69ed-4736-83a9-f11389b371b2
caps.latest.revision: 8
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: compilando um programa do C++/CX na linha de comando
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode criar programas Visual C\+\+ destinados ao Windows Runtime e compilá\-los na linha de comando.  O Visual C\+\+ oferece suporte a extensões de componente do Visual C\+\+ \(C\+\+\/CX\), que possuem tipos e operadores adicionais destinados ao modelo de programação do Windows Runtime.  Você pode usar C\+\+\/CX para compilar aplicativos para Windows Phone 8.1, do Windows Store e do Windows Desktop.  Para obter mais informações, consulte [Um Tour pelo C\+\+\/CX](http://msdn.microsoft.com/magazine/dn166929.aspx) e [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md).  
  
 Neste passo a passo, você usa um editor de texto para criar um programa de C\+\+\/CX básico e, em seguida, o compila na linha de comandos.  \(Você pode usar seu próprio programa de C\+\+\/CX ao invés de digitar o que é mostrado ou, ainda, usar uma amostra de código de C\+\+\/CX de outro artigo de ajuda.  Essa técnica é útil para compilar e testar pequenos módulos que não contêm elementos de interface do usuário.\)  
  
> [!NOTE]
>  Você também pode usar o Visual Studio IDE para compilar programas em C\+\+\/CX.  Como o IDE inclui o design, depuração, emulação e suporte de implantação que não está disponível na linha de comandos, recomendamos que você use o IDE para complicar aplicativos da Windows Store.  Para obter mais informações, consulte [Create a basic C\+\+ Store app](http://msdn.microsoft.com/library/windows/apps/dn263168).  
  
## Pré-requisitos  
 Você deve conhecer os princípios básicos da linguagem C\+\+.  
  
## Compilando um programa C\+\+\/CX  
 Para habilitar a compilação para C\+\+\/CX, você deve usar a opção do compilador [\/ZW](../build/reference/zw-windows-runtime-compilation.md).  O compilador do Visual C\+\+ gera um arquivo .exe destinado ao Tempo de Execução do Windows e vincula às bibliotecas necessárias.  
  
#### Para compilar um aplicativo em C\+\+\/CX na linha de comando  
  
1.  Abra uma janela do **Prompt de Comando do Desenvolvedor**.  \(Na janela **Iniciar**, abra **Aplicativos**.  Abra a pasta **Ferramentas do Visual Studio** na versão do [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] e escolha o atalho **Prompt de Comando do Desenvolvedor**.\) Para obter mais informações sobre como abrir uma janela de Prompt de Comando, consulte [Definindo as variáveis de caminho e ambiente para compilações de linha de comando](../build/setting-the-path-and-environment-variables-for-command-line-builds.md).  
  
     As credenciais de administrador podem ser necessárias para compilar o código com êxito, dependendo do sistema operacional e da configuração do computador.  Para executar a janela do Prompt de Comando como administrador, abra o menu de atalho do **Prompt de Comando do Desenvolvedor** e escolha **Executar como administrador**.  
  
2.  No prompt de comando, digite **notepad basiccx.cpp**.  
  
     Escolha **Sim** quando for solicitada a criação de um arquivo.  
  
3.  No Bloco de Notas, insira estas linhas:  
  
    ```cpp  
    using namespace Platform;  
  
    int main(Platform::Array<Platform::String^>^ args)  
    {  
        Platform::Details::Console::WriteLine("This is a C++/CX program.");  
    }  
  
    ```  
  
4.  Na barra de menus, escolha **Arquivo**, **Salvar**.  
  
     Você criou um arquivo de origem do Visual C\+\+ que usa o namespace do Tempo de Execução do Windows [Namespace de plataforma](../Topic/Platform%20namespace%20\(C++-CX\).md).  
  
5.  No prompt de comando, digite **cl \/EHsc \/ZW basiccx.cpp \/link \/SUBSYSTEM:CONSOLE**.  O compilador cl.exe compila o código\-fonte em um arquivo .obj e executa o vinculador para gerar um programa executável denominado basiccx.exe.  \(A opção do compilador [\/EHsc](../build/reference/eh-exception-handling-model.md) especifica o modelo de gerenciamento de exceção C\+\+, e o sinalizador [\/link](../Topic/-link%20\(Pass%20Options%20to%20Linker\).md) especifica um aplicativo de console.\)  
  
6.  Para executar o programa basicclr.exe, no prompt de comando, insira **basiccx**.  
  
     O programa exibe este texto e é fechado:  
  
  **Esse é um programa C\+\+\/CX.**  
  
## Consulte também  
 [Visual C\+\+ Guided Tour](http://msdn.microsoft.com/pt-br/499cb66f-7df1-45d6-8b6b-33d94fd1f17c)   
 [Referência de linguagem C\+\+](../cpp/cpp-language-reference.md)   
 [Compilando programas do C\/C\+\+](../build/building-c-cpp-programs.md)   
 [Opções do compilador](../build/reference/compiler-options.md)