---
title: "Detalhes do suporte ATL adicionado pelo Assistente ATL | Microsoft Docs"
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
  - "vc.codewiz.atl.support"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ATL, projetos MFC"
  - "MFC, Suporte ATL"
ms.assetid: aa66bad0-008f-4886-94c1-2a0a0d04bce4
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Detalhes do suporte ATL adicionado pelo Assistente ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Quando você [adicionar suporte de ATL a um executável existente ou à DLL de MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md)Visual C\+\+, faça as seguintes alterações no projeto \(MFC existente neste exemplo, o projeto é chamado `MFCEXE`\):  
  
-   Dois novos arquivos \(um arquivo de .idl e .rgs, um arquivo usado para registrar o servidor\) são adicionados.  
  
-   No cabeçalho do aplicativo principal e em arquivos de implementação \(Mfcexe.h e Mfcexe.cpp\), uma nova classe derivada de **CAtlMFCModule**\(\) é adicionada.  Além da nova classe, o código será adicionado a `InitInstance` para o registro.  O código também é adicionado à função de `ExitInstance` para revogar o objeto da classe.  No arquivo de cabeçalho, finalmente, dois novos arquivos de cabeçalho \(Initguid.h e Mfcexe\_i.c\) são incluídos no arquivo de implementação, declarando e inicializando o novo GUIDs para **CAtlMFCModule**\- classe derivada.  
  
-   Para registrar o servidor corretamente, uma entrada para o novo arquivo de .rgs é adicionada ao arquivo de recurso do projeto.  
  
## Notas da DLL para projetos  
 Quando você adiciona suporte de ATL a um projeto da DLL MFC, você verá algumas diferenças.  O código é adicionado às funções de **DLLRegisterServer** e de **DLLUnregisterServer** para registrar e cancelar a DLL.  O código também é adicionado a [DllCanUnloadNow](../Topic/CAtlDllModuleT::DllCanUnloadNow.md) e a [DllGetClassObject](../Topic/CAtlDllModuleT::DllGetClassObject.md).  
  
## Consulte também  
 [Suporte ATL em um projeto MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md)   
 [Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)   
 [Substituindo uma função virtual](../Topic/Overriding%20a%20Virtual%20Function%20\(Visual%20C++\).md)   
 [Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)   
 [Navegando na estrutura da classe](../../ide/navigating-the-class-structure-visual-cpp.md)