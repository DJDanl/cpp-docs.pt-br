---
title: "CanAddATLClass | Microsoft Docs"
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
  - "CanAddATLClass"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CanAddATLClass"
ms.assetid: 7a8abf90-c1b8-475c-af22-7948478084f9
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CanAddATLClass
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Chamado pelo Assistente para verificar que o usuário pode adicionar uma classe ATL ao projeto.  
  
## Sintaxe  
  
```  
  
      function CanAddATLClass(   
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
 **True** se a classe pode ser adicionada;  **False** se o usuário chama a função de um projeto que não é um projeto do ATL e não possui suporte ATL.  
  
## Comentários  
 Chamado pelo Assistente para verificar se o projeto é compatível com o Assistente de código que está prestes a ser executado \(em outras palavras, ele pode aceitar uma classe ATL\).  
  
 O assistente chama esta função quando o parâmetro PREPROCESS\_FUNCTION é na  [arquivo vsz do controle do projeto](../ide/dot-vsz-file-project-control.md) e verifica se o  [Modelo de código do Visual C\+\+](http://msdn.microsoft.com/pt-br/dd6452c2-1054-44a1-b0eb-639a94a1216b) está disponível.  Se o modelo de código não estiver disponível, a função reporta um erro e retorna  **false**.  
  
## Exemplo  
  
```  
// Determine if an ATL class can be added to the project  
if (CanAddATLClass(selProj, selObj))  
{  
   return true;  
}  
```  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)   
 [CanAddClass](../ide/canaddclass.md)   
 [IsMFCProject](../Topic/IsMFCProject.md)   
 [CanAddMFCClass](../ide/canaddmfcclass.md)