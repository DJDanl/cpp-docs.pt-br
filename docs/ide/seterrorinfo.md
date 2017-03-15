---
title: "SetErrorInfo | Microsoft Docs"
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
  - "SetErrorInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método SetErrorInfo"
ms.assetid: 78bca763-3f90-4e04-b566-b4b7fe2431b1
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# SetErrorInfo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Chamado por  [OnWizFinish](../Topic/OnWizFinish.md) e  [CanUseFileName](../ide/canusefilename.md) para fornecer informações de erro atual.  
  
## Sintaxe  
  
```  
  
      function SetErrorInfo(   
   oErrorObj   
);  
```  
  
#### Parâmetros  
 *oErrorObj*  
 O objeto de erro.  
  
## Comentários  
 Chamado por  [OnWizFinish](../Topic/OnWizFinish.md) e  [CanUseFileName](../ide/canusefilename.md) para fornecer informações de erro atual.  Consulte <xref:Microsoft.VisualStudio.VsWizard.VCWizCtlClass.SetErrorInfo%2A> na documentação do modelo de Assistente do Visual C\+\+ para obter mais informações.  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)