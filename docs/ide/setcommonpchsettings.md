---
title: "SetCommonPchSettings | Microsoft Docs"
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
  - "SetCommonPchSettings"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método SetCommonPchSettings"
ms.assetid: 12f5524b-f654-4222-b979-8ee0d9f58c14
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# SetCommonPchSettings
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Estabelece as configurações de cabeçalho pré\-compilado para o projeto.  
  
## Sintaxe  
  
```  
  
      function SetCommonPchSettings(   
   oProj    
);  
```  
  
#### Parâmetros  
 `oProj`  
 O projeto selecionado.  
  
## Comentários  
 Chame essa função para estabelecer as configurações de cabeçalho pré\-compilado para o projeto.  
  
 Essa função define a <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.UsePrecompiledHeader%2A> propriedade para o seguinte:  
  
-   **pchUseUsingSpecific** usa o  [\/Yu \(uso pré\-compilado cabeçalho de arquivo\)](../build/reference/yu-use-precompiled-header-file.md) configuração do compilador.  
  
-   **pchCreateUsingSpecific** usa o  [\/Yc \(criar a arquivo de cabeçalho pré\-compilado\)](../build/reference/yc-create-precompiled-header-file.md) configuração do compilador.  
  
## Exemplo  
  
```  
if ((strAppType == "LIB" || ((strAppType == "CONSOLE") &&   
   wizard.FindSymbol(SUPPORT_MFC"))) && !Pch)  
   {  
      AddFilesToProject(selProj, strProjectName, InfFile);  
      SetNoCommonPchSettings(selProj);  
   }  
else  
   {  
      AddFilesToProject(selProj, strProjectName, InfFile);  
      SetcommonPchSettings(selProj);  
   }  
```  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)   
 [SetNoPchSettings](../ide/setnopchsettings.md)   
 [AddCommonConfig](../ide/addcommonconfig.md)