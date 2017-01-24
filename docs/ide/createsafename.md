---
title: "CreateSafeName | Microsoft Docs"
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
  - "CreateSafeName"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CreateSafeName"
ms.assetid: 3a0dd4af-776d-4c25-aff9-4c539f173cb8
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CreateSafeName
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Gera um nome amigável do C\+\+.  
  
## Sintaxe  
  
```  
  
      function CreateSafeName(   
   strName    
);  
```  
  
#### Parâmetros  
 `strName`  
 O nome antigo.  
  
## Valor de retorno  
 O nome novo e seguro.  
  
## Comentários  
 Chame essa função para criar um nome amigável do C\+\+ a partir de um nome que contenha caracteres que não podem ser usados pelo C\+\+.  Um nome de C\+\+ aceitável pode conter maiúsculas ou minúsculas, dígitos ou um sublinhado \("\_"\).  
  
 Esta função verifica o nome antigo do caractere por caractere, ignorando quaisquer caracteres inutilizáveis.  Se o nome antigo contiver caracteres amigáveis, a função retorna o novo nome como "Meu".  Se o novo nome amigável começar com um dígito, essa função precederá o novo nome com "Meu".  
  
## Exemplo  
  
```  
// Get the project name  
var strProjectName = wizard.FindSymbol("PROJECT_NAME");  
  
// Set the project name to the safe project name.   
var strSafeProjectName = CreateSafeName(strProjectName);  
```  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)