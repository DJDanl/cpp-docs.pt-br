---
title: "Instru&#231;&#245;es passo a passo: compilando um programa do C++/CLI na linha de comando | Microsoft Docs"
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
ms.assetid: cef41c88-faf9-439d-8423-25aa3f5674dd
caps.latest.revision: 11
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: compilando um programa do C++/CLI na linha de comando
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

É possível criar programas Visual C\+\+ que tenham CLR \(Common Language Runtime\) como destino e usem .NET Framework e depois compilá\-los na linha de comando.  O Visual C\+\+ tem suporte à linguagem de programação C\+\+\/CLI, que possui tipos e operadores adicionais para atingir o modelo de programação .NET.  Para uma introdução à linguagem C\+\+\/CLI, consulte [Pure C\+\+: Hello, C\+\+\/CLI](http://msdn.microsoft.com/magazine/cc163681.aspx).  Para obter informações gerais, consulte [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).  
  
 Neste passo a passo, você usa um editor de texto para criar um programa de C\+\+\/CLI básico e, em seguida, o compila na linha de comandos.  \(Você pode usar seu próprio programa de C\+\+\/CLI ao invés de digitar o que é mostrado ou, ainda, usar uma amostra de código de C\+\+\/CLI de outro artigo de ajuda.  Essa técnica é útil para compilar e testar pequenos módulos que não contêm elementos de interface do usuário.\)  
  
> [!NOTE]
>  Em seguida, é possível usar o Visual Studio IDE para compilar programas C\+\+\/CLI.  Para obter mais informações, consulte [Instruções passo a passo: compilando um programa C\+\+ que se destina ao CLR no Visual Studio](../ide/walkthrough-compiling-a-cpp-program-that-targets-the-clr-in-visual-studio.md).  
  
## Pré-requisitos  
 Você deve conhecer os princípios básicos da linguagem C\+\+.  
  
## Compilando um programa C\+\+\/CLI  
 As etapas a seguir mostram como compilar um aplicativo de console C\+\+\/CLI que usa classes .NET Framework.  
  
 Para habilitar a compilação para C\+\+\/CLI, é preciso usar a opção do compilador [\/clr](../build/reference/clr-common-language-runtime-compilation.md).  O compilador do Visual C\+\+ gera um arquivo .exe contendo código MSIL — ou MSIL misto e código nativo — e links para as bibliotecas .NET Framework.  
  
#### Para compilar um aplicativo C\+\+\/CLI na linha de comando  
  
1.  Abra uma janela do **Prompt de Comando do Desenvolvedor**.  \(Na janela **Iniciar**, abra **Aplicativos**.  Abra a pasta **Ferramentas do Visual Studio** na versão do [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] e escolha o atalho **Prompt de Comando do Desenvolvedor**.\) Para obter mais informações sobre como abrir uma janela de Prompt de Comando, consulte [Definindo as variáveis de caminho e ambiente para compilações de linha de comando](../build/setting-the-path-and-environment-variables-for-command-line-builds.md).  
  
     As credenciais de administrador podem ser necessárias para compilar o código com êxito, dependendo do sistema operacional e da configuração do computador.  Para executar a janela do Prompt de Comando como administrador, abra o menu de atalho do **Prompt de Comando do Desenvolvedor** e escolha **Executar como administrador**.  
  
2.  No prompt de comando, digite **notepad basicclr.cpp**.  
  
     Escolha **Sim** quando for solicitada a criação de um arquivo.  
  
3.  No Bloco de Notas, insira estas linhas:  
  
    ```  
    int main()  
    {  
        System::Console::WriteLine("This is a C++/CLI program.");  
    }  
    ```  
  
4.  Na barra de menus, escolha **Arquivo**, **Salvar**.  
  
     Você criou um arquivo de origem do Visual C\+\+ que usa uma classe .NET Framework \(<xref:System.Console>\) no namespace <xref:System>.  
  
5.  No prompt de comando, digite **cl \/clr basicclr.cpp**.  O compilador cl.exe compila o código\-fonte em um arquivo .obj contendo MSIL e executa o vinculador para gerar um programa executável chamado basicclr.exe.  
  
6.  Para executar o programa basicclr.exe, no prompt de comando, insira **basicclr**.  
  
     O programa exibe este texto e é fechado:  
  
  **Este é um programa C\+\+\/CLI.**  
  
## Consulte também  
 [Visual C\+\+ Guided Tour](http://msdn.microsoft.com/pt-br/499cb66f-7df1-45d6-8b6b-33d94fd1f17c)   
 [Referência de linguagem C\+\+](../cpp/cpp-language-reference.md)   
 [Compilando programas do C\/C\+\+](../build/building-c-cpp-programs.md)   
 [Opções do compilador](../build/reference/compiler-options.md)