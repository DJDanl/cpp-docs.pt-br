---
title: "Classe collate | Microsoft Docs"
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
  - "std::collate"
  - "locale/std::collate"
  - "std.collate"
  - "collate"
  - "Collate"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe collate"
ms.assetid: 92168798-9628-4a2e-be6e-fa62dcd4d6a6
caps.latest.revision: 18
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe collate
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe de modelo que descreve um objeto que pode funcionar como uma faceta de localidade para controlar a ordenação e o agrupamento de caracteres em uma cadeia de caracteres, as comparações entre eles e o hash de cadeias de caracteres.  
  
## Sintaxe  
  
```  
template <class CharType >  
   class collate : public locale::facet;  
```  
  
#### Parâmetros  
 `CharType`  
 O tipo usado em um programa para codificar caracteres.  
  
## Comentários  
 Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero.  A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo em **id.** Em algumas linguagens, os caracteres são agrupados e tratados como um único caractere e, em outras, caracteres individuais são tratados como se fossem dois caracteres.  Os serviços de agrupamento fornecidos pela classe collate fornecem o meio de classificar esses casos.  
  
### Construtores  
  
|||  
|-|-|  
|[collate](../Topic/collate::collate.md)|O construtor para objetos da classe `collate` que serve como uma faceta de localidade para tratar convenções de classificação de cadeia de caracteres.|  
  
### Typedefs  
  
|||  
|-|-|  
|[char\_type](../Topic/collate::char_type.md)|Um tipo que descreve um caractere do tipo `CharType`.|  
|[string\_type](../Topic/collate::string_type.md)|Um tipo que descreve uma cadeia de caracteres do tipo `basic_string` que contém caracteres do tipo `CharType`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[compare](../Topic/collate::compare.md)|Compara duas sequências de caracteres de acordo com as igualdades ou desigualdades das respectivas regras específicas de faceta.|  
|[do\_compare](../Topic/collate::do_compare.md)|Uma função virtual chamada para comparar duas sequências de caracteres de acordo com as igualdades ou desigualdades das respectivas regras específicas de faceta.|  
|[do\_hash](../Topic/collate::do_hash.md)|Uma função virtual chamada para determinar o valor de hash das sequências de acordo com as respectivas regras específicas de faceta.|  
|[do\_transform](../Topic/collate::do_transform.md)|Uma função virtual chamada para converter uma sequência de caracteres de uma localidade em uma cadeia de caracteres que pode ser usada em comparações lexicográficas com outras sequências de caracteres convertidas da mesma forma da mesma localidade.|  
|[hash](../Topic/collate::hash.md)|Determina o valor de hash da sequência de acordo com suas regras específicas de faceta.|  
|[transform](../Topic/collate::transform.md)|Converte uma sequência de caracteres de uma localidade em uma cadeia de caracteres que pode ser usada em comparações lexicográficas com outras sequências de caracteres convertidas da mesma forma da mesma localidade.|  
  
## Requisitos  
 **Cabeçalho:** \<locale\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<locale\>](../standard-library/locale.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)