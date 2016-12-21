---
title: "CanAddClass | Microsoft Docs"
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
  - "CanAddClass"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CanAddClass"
ms.assetid: 76739742-1e34-470c-910d-8784f0adfbf0
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CanAddClass
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Chamado pelo Assistente para verificar se o projeto é compatível com o Assistente de código que o usuário está tentando ser executado.  
  
## Sintaxe  
  
```  
  
      function CanAddClass(   
   oProj,   
   oObject    
);  
```  
  
#### Parâmetros  
 `oProj`  
 O projeto selecionado.  
  
 `oObject`  
 O objeto selecionado.  Nesse caso, o projeto atual.  
  
## Valor de retorno  
 **True** se a classe pode ser adicionada; Caso contrário,  **false**.  
  
## Comentários  
 O assistente chama esta função quando o parâmetro PREPROCESS\_FUNCTION é na  [arquivo de vsz do controle do projeto](../ide/dot-vsz-file-project-control.md).  
  
 Ele verifica se o  [Modelo de código do Visual C\+\+](http://msdn.microsoft.com/pt-br/dd6452c2-1054-44a1-b0eb-639a94a1216b) o objeto está disponível.  Se o modelo de código não estiver disponível, a função reporta um erro e retorna  **false**.  
  
## Exemplo  
  
```  
// Determine if a class can be added to the project  
if (CanAddClass(selProj, selObj))  
{  
   return true;  
}  
```  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)   
 [CanAddMFCClass](../ide/canaddmfcclass.md)   
 [CanAddATLClass](../ide/canaddatlclass.md)   
 [IsMFCProject](../Topic/IsMFCProject.md)