---
title: "GetRuntimeErrorDesc | Microsoft Docs"
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
  - "GetRuntimeErrorDesc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método ConversionError"
  - "Método GetRuntimeErrorDesc"
  - "Método RangeError"
  - "Método ReferenceError"
  - "Método RegExpError"
  - "Método SyntaxError"
  - "Método TypeError"
  - "Método URIError"
ms.assetid: d56fdd2e-6ad0-4c49-9e98-bcf0105e1b12
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# GetRuntimeErrorDesc
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Retorna uma descrição para o tipo de exceção.  
  
## Sintaxe  
  
```  
  
      function GetRuntimeErrorDesc(   
   strRuntimeErrorName    
);  
```  
  
#### Parâmetros  
 *strRuntimeErrorName*  
 O nome do tipo de exceção que ocorreu.  
  
## Valor de retorno  
 Uma descrição do tipo de exceção.  
  
## Comentários  
 Retorna uma descrição para o tipo de exceção.  Pode ser um dos seguintes tipos de exceção:  
  
|Tipos de exceções|Descrição|  
|-----------------------|---------------|  
|ConversionError|Ocorre sempre que houver uma tentativa para converter um objeto em algo para o qual não pode ser convertido.|  
|RangeError|Ocorre quando uma função é fornecida com um argumento que excedeu o seu intervalo permitido.  Por exemplo, este erro ocorre se você tentar construir um `Array` o objeto com um comprimento que não é um número inteiro positivo válido.|  
|ReferenceError|Ocorre quando uma referência inválida foi detectada.  Este erro ocorrerá, por exemplo, se uma referência esperada for nula.|  
|RegExpError|Ocorre quando um erro de compilação com uma expressão regular.  Depois que a expressão regular é compilada, este erro não pode ocorrer.  Este exemplo ocorrerá, por exemplo, quando uma expressão regular é declarada com um padrão que tem uma sintaxe inválida ou sinalizadores diferente de  *i*,  *g*, ou  *m*, ou se contiver mais de uma vez o mesmo sinalizador.|  
|SyntaxError|Ocorre quando o texto de origem é analisado e esse texto de origem não segue a sintaxe correta.  Este erro ocorrerá, por exemplo, se a `eval` função é chamada com um argumento que não é um texto de programa válido.|  
|TypeError|Ocorre sempre que o tipo real de um operando não corresponde ao tipo esperado.  Um exemplo de quando este erro ocorre é uma chamada de função feita em algo que não é um objeto ou não oferece suporte a chamada.|  
|URIError|Ocorre quando um ilegal indicador URI \(Uniform Resource\) é detectado.  Por exemplo, este é o erro ocorre quando um caractere ilegal é encontrado em uma seqüência de caracteres que está sendo codificado ou decodificado.|  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)