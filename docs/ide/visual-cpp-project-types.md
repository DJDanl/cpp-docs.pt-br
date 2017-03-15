---
title: "Tipos de projeto do Visual C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "programas [C++], projetos"
  - "modelos de projeto [Visual Studio], C++"
  - "Comentários TODO [C++]"
  - "projetos [C++], tipos"
  - "modelos [C++], projetos"
  - "aplicativos [C++], projetos"
  - "Projetos do Visual C++, tipos"
ms.assetid: 7337987e-1e7b-4120-9a4b-94f0401f15e7
caps.latest.revision: 20
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tipos de projeto do Visual C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode usar um modelo de projeto para criar a estrutura básica do programa, menus, barras de ferramentas, ícones, referências, e `#include` instruções que são apropriadas para o tipo de projeto que você deseja criar. Visual Studio inclui vários tipos de modelos de projeto do Visual C\+\+ e fornece assistentes para muitos deles, para que você possa personalizar seus projetos como criá\-los. Imediatamente depois de criar um projeto, você pode criá\-la e executar o aplicativo — é uma boa prática compilar de forma intermitente conforme você desenvolve seu aplicativo.  
  
 Você não precisa usar um modelo para criar um projeto, mas na maioria dos casos é mais eficiente para fazê\-lo porque é mais fácil de modificar os arquivos de projeto fornecidos e a estrutura que criá\-los a partir do zero.  
  
> [!NOTE]
>  Você pode criar um projeto de linguagem C usando modelos de projeto C\+\+. No projeto gerado, localize arquivos que tenham um. cpp extensão de nome de arquivo e altere\-o para. c. Em seguida, no **Propriedades do projeto** página do projeto \(não para a solução\), expanda **Propriedades de configuração**, **C\/C\+\+** e selecione **Avançado**. Alterar o **Compilar como** definir como **Compilar como código C \(\/ TC\)**.  
  
## Modelos de projeto  
 Modelos de projeto do Visual Studio do Visual C\+\+ a seguir.  
  
### Armazenar aplicativos  
  
||  
|-|  
|[Modelos de projeto c\#, VB e C\+\+ para aplicativos de armazenamento](http://go.microsoft.com/fwlink/p/?LinkID=262279)|  
  
### ATL  
  
|Modelo de projeto|Como criar um projeto|  
|-----------------------|---------------------------|  
|Projeto ATL|[Criando um projeto ATL](../atl/reference/creating-an-atl-project.md)|  
  
### CLR  
  
|Modelo de projeto|  
|-----------------------|  
|[\(NOTINBUILD\) Modelo de biblioteca de classe \(C\+\+\)](http://msdn.microsoft.com/pt-br/0d779bfa-5c5a-4b10-a9d5-a6791764a78f)|  
|[Como criar aplicativos do console CLR](../Topic/How%20to:%20Create%20CLR%20Console%20Applications%20\(C++-CLI\).md)|  
|[Modelo de projeto vazio NOTINBUILD CLR \(C\+\+\)](http://msdn.microsoft.com/pt-br/f57c5572-5581-440f-b684-eec646764f08)|  
  
### Geral  
  
|Modelo de projeto|Como criar um projeto|  
|-----------------------|---------------------------|  
|Projeto vazio|[Criando soluções e projetos](../Topic/Creating%20Solutions%20and%20Projects.md)|  
|Assistente personalizado|[Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)|  
|Projeto makefile|[Criando um projeto de makefile](../ide/creating-a-makefile-project.md)|  
  
### MFC  
  
|Modelo de projeto|Como criar um projeto|  
|-----------------------|---------------------------|  
|Controle ActiveX do MFC|[Criando um controle ActiveX MFC](../mfc/reference/creating-an-mfc-activex-control.md)|  
|Aplicativo MFC|[Criando um aplicativo MFC](../mfc/reference/creating-an-mfc-application.md)|  
|DLL DO MFC|[Criando um projeto DLL MFC](../mfc/reference/creating-an-mfc-dll-project.md)|  
  
### Testar  
  
|Modelo de projeto|Como criar um projeto|  
|-----------------------|---------------------------|  
|Projeto de teste gerenciado|[Crie um projeto de teste de unidade](../Topic/Create%20a%20unit%20test%20project.md)|  
|Projeto de teste de unidade nativa|[Teste o código nativo com o Gerenciador de testes de unidade](http://msdn.microsoft.com/pt-br/8a09d6d8-3613-49d8-9ffe-11375ac4736c)|  
  
### Win32  
  
|Modelo de projeto|Como criar um projeto|  
|-----------------------|---------------------------|  
|Projeto de Console Win32|[Criando um aplicativo de Console](../windows/creating-a-console-application.md)|  
|Projeto Win32|[Como: criar um aplicativo de área de trabalho do Windows](../Topic/How%20to:%20Create%20a%20Windows%20Desktop%20Application.md)|  
  
## Comentários TODO  
 Muitos dos arquivos gerados por um modelo de projeto contêm comentários TODO para ajudar a identificar onde você pode fornecer seu próprio código\-fonte. Para obter mais informações sobre como adicionar código, consulte [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md) e [Trabalhando com arquivos de recurso](../mfc/working-with-resource-files.md).  
  
## Consulte também  
 [Criando projetos para desktop com Assistentes de Aplicativo](../ide/creating-desktop-projects-by-using-application-wizards.md)   
 [Usando projetos para criar aplicativos](http://msdn.microsoft.com/pt-br/3339fa90-bac2-4b95-8361-662a2e0e7dfe)   
 [Projetos CLR](../ide/files-created-for-clr-projects.md)