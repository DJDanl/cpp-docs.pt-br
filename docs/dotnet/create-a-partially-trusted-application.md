---
title: "Como criar um aplicativo confi&#225;vel parcialmente removendo a depend&#234;ncia da DLL de biblioteca CRT | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /clr [C++], aplicativos parcialmente confiáveis"
  - "interoperabilidade [C++], aplicativos parcialmente confiáveis"
  - "interoperabilidade [C++], aplicativos parcialmente confiáveis"
  - "assemblies mistos [C++], aplicativos parcialmente confiáveis"
  - "msvcm90[d].dll"
  - "aplicativos parcialmente confiáveis [C++]"
ms.assetid: 4760cd0c-4227-4f23-a7fb-d25b51bf246e
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como criar um aplicativo confi&#225;vel parcialmente removendo a depend&#234;ncia da DLL de biblioteca CRT
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico discute como criar um aplicativo parcialmente confiável de Common Language Runtime usando [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] removendo a dependência em msvcm90.dll.  
  
 Um aplicativo do Visual C\+\+ compilado com **\/clr** terá uma dependência em msvcm90.dll, que faz parte da biblioteca do C \- tempo de execução.  Quando você deseja que seu aplicativo ser usado em um ambiente de confiança parcial, CLR impõe determinadas regras de segurança de acesso a código no seu DLL.  Consequentemente, será necessário remover essa dependência como msvcm90.dll contém o código nativo e política de segurança de acesso a código não pode ser aplicada nela.  
  
 Se seu aplicativo não usa nenhuma funcionalidade da biblioteca de C \- tempo de execução e você gostaria de remover a dependência nessa biblioteca em seu código, você terá que usar a opção do vinculador de **\/NODEFAULTLIB:msvcmrt.lib** e links com o ptrustm.lib ou o ptrustmd.lib.  Essas bibliotecas contêm arquivos de objeto para a inicialização e o uninitialization de um aplicativo, classes de exceção usadas pelo código de inicialização, e o código gerenciado de manipulação de exceção.  Vincular em uma dessas bibliotecas removerá qualquer dependência em msvcm90.dll.  
  
> [!NOTE]
>  A ordem de uninitialization de assembly pode ser diferente para os aplicativos que usam as bibliotecas de ptrust.  Para aplicativos comuns, os assemblies são descarregados normalmente em ordem inversa que estão carregados, mas isso não é garantido.  Para aplicativos parciais de confiança, os assemblies são descarregados normalmente na mesma ordem que estão carregados.  Isso não é garantido, também.  
  
### Para criar um aplicativo \(\/clr\) misto parcialmente confiável  
  
1.  Para remover a dependência em msvcm90.dll, você deve especificar ao vinculador para não incluir essa biblioteca usando a opção do vinculador de **\/NODEFAULTLIB:msvcmrt.lib** .  Para obter informações sobre como fazer isso usando o ambiente de desenvolvimento do Visual Studio ou programaticamente, consulte [\/NODEFAULTLIB \(ignorar bibliotecas\)](../build/reference/nodefaultlib-ignore-libraries.md).  
  
2.  Adicionar uma das bibliotecas de ptrustm as dependências de entrada do vinculador.  Use ptrustm.lib se você estiver criando o seu aplicativo no modo de versão.  Para o modo de depuração, use ptrustmd.lib.  Para obter informações sobre como fazer isso usando o ambiente de desenvolvimento do Visual Studio ou programaticamente, consulte [Arquivos .Lib como entrada de vinculador](../build/reference/dot-lib-files-as-linker-input.md).  
  
## Consulte também  
 [Assemblies mistos \(nativos e gerenciados\)](../Topic/Mixed%20\(Native%20and%20Managed\)%20Assemblies.md)   
 [Inicialização de assemblies mistos](../Topic/Initialization%20of%20Mixed%20Assemblies.md)   
 [Suporte de biblioteca para assemblies mistos](../dotnet/library-support-for-mixed-assemblies.md)   
 [\/link \(passar opções para o vinculador\)](../Topic/-link%20\(Pass%20Options%20to%20Linker\).md)   
 [Segurança no código nativo e do .NET Framework](http://msdn.microsoft.com/pt-br/bd61be84-c143-409a-a75a-44253724f784)