---
title: "OffsetToLineNumber | Microsoft Docs"
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
  - "OffsetToLineNumber"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função OffsetToLineNumber"
ms.assetid: ac7e3c22-6b3b-432c-85cc-b50bbef9ce8c
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# OffsetToLineNumber
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Chamado por  [InsertIntoFunction](../ide/insertintofunction.md) para converter um índice em um corpo de função em um número de linha.  
  
## Sintaxe  
  
```  
  
      function OffsetToLineNumber(   
   strString,   
   nPos    
);  
```  
  
#### Parâmetros  
 `strString`  
 A seqüência de caracteres que contém o corpo da função.  O corpo da função é uma seqüência de caracteres de várias linhas em que suas linhas são delimitadas por pares de caracteres cr\-lf.  
  
 `nPos`  
 Uma posição dentro da seqüência.  
  
## Valor de retorno  
 A linha dentro da função do corpo onde `nPos` está localizado.  A primeira linha na função é considerada como sendo a linha 1 \(não 0\).  
  
## Comentários  
 Localiza o número da linha para uma determinada posição no corpo da função.  
  
 Esta função é chamada `InsertIntoFunction` para converter o índice localizado em `nPos` em um corpo de função para um número de linha.  
  
## Exemplo  
  
```  
strString = "function DelFile(fso,  
 strWizTempFile)\r\n{\r\n\ttry\r\n\t{\r\nif   
(fso.FileExists(strWizTempFile))\r\nreturn true;\r\n";  
  
nLine =  OffsetToLineNumber(strString, 60);  
  
// The return value for the above is 5, because character 60 in the string   
// occurs in the 5th line within the string.  
```  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)   
 [LineBeginsWith](../ide/linebeginswith.md)