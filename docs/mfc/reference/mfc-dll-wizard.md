---
title: "Assistente de DLL MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.appwiz.mfc.dll.overview"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de DLL [MFC]"
  - "DLLs [C++], criando"
  - "DLLs [C++], MFC"
  - "Assistente de DLL MFC"
  - "DLLs MFC [C++]"
  - "DLLs MFC [C++], criando"
ms.assetid: 4e936031-7e39-4f40-a295-42a09c5ff264
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente de DLL MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Quando você usa o assistente da DLL MFC para criar um projeto da DLL MFC, você obtém um aplicativo de trabalho do acionador de partida com funcionalidade interna que, quando criada, implementará os recursos básicos de [Dlls](../../build/dlls-in-visual-cpp.md).  O programa do acionador de partida MFC inclui arquivos de origem do C\+\+ \(.cpp\), arquivos de recursos \(.rc\), e um arquivo de projeto \(.vcxproj\).  O código gerado nesses arquivos do acionador de partida é baseado em MFC.  Para obter mais informações detalhadas, consulte os detalhes do arquivo no Readme.txt que é gerada para seu projeto no Visual Studio, e em [Classes e funções geradas pelo assistente da DLL MFC](../Topic/Classes%20and%20Functions%20Generated%20by%20the%20MFC%20DLL%20Wizard.md)  
  
## Visão Geral  
 Esta página do assistente descreve [configurações do aplicativo para o projeto da DLL MFC](../../mfc/reference/application-settings-mfc-dll-wizard.md) atual que você está criando.  Por padrão, o projeto é criado como um projeto normal da DLL \(MFC compartilhado\) sem configurações adicionais.  
  
 Para alterar estas opções, clique **Configurações do Aplicativo** na coluna esquerda do assistente e fazer alterações nessa página do assistente da DLL MFC.  
  
 Depois que você criar um projeto da DLL MFC, você pode adicionar objetos ou controla ao seu projeto usando o Visual C\+\+ [codificar assistentes](../../ide/adding-functionality-with-code-wizards-cpp.md).  
  
 Você pode executar as seguintes tarefas e os tipos de aprimoramentos para uma DLL básico de MFC projeto:  
  
-   [Exportar de uma DLL](../../build/exporting-from-a-dll.md)  
  
-   [Vincular um executável para uma DLL](../../build/linking-an-executable-to-a-dll.md)  
  
-   [Inicialize um DLL](../../build/initializing-a-dll.md)  
  
## Consulte também  
 [Criando e gerenciando projetos do Visual C\+\+](../../ide/creating-and-managing-visual-cpp-projects.md)   
 [Páginas de propriedade](../../ide/property-pages-visual-cpp.md)   
 [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md)   
 [Deploying Applications](http://msdn.microsoft.com/pt-br/4ff8881d-0daf-47e7-bfe7-774c625031b4)   
 [MFC Class](../../mfc/reference/adding-an-mfc-class.md)   
 [Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)   
 [Implementando uma interface](../../ide/implementing-an-interface-visual-cpp.md)   
 [Suporte do assistente para outros idiomas](../../ide/wizard-support-for-other-languages.md)