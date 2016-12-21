---
title: "&lt;set&gt; | Microsoft Docs"
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
  - "std.<set>"
  - "std::<set>"
  - "<set>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho set"
ms.assetid: 43cb1ab2-6383-48cf-8bdc-2b96d7203596
caps.latest.revision: 20
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;set&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define o conjunto de classes de modelo do contêiner e seus modelos de suporte e multiset.  
  
## Sintaxe  
  
```  
  
#include <set>  
  
```  
  
## Membros  
  
### Operadores  
  
|Versão do conjunto|Versão multiset|Descrição|  
|------------------------|---------------------|---------------|  
|[operador\!\= \(set\)](../Topic/operator!=%20\(set\).md)|[operador\!\= \(multiset\)](../Topic/operator!=%20\(multiset\).md)|Testa se o conjunto ou objeto multiset no lado esquerdo do operador não é igual ao conjunto ou objeto multiset no lado direito.|  
|[operador\< \(set\)](../Topic/operator%3C%20\(set\).md)|[operador\< \(multiset\)](../Topic/operator%3C%20\(multiset\).md)|Testa se o conjunto ou objeto multiset no lado esquerdo do operador é menor que o conjunto ou objeto multiset no lado direito.|  
|[operador\<\= \(set\)](../Topic/operator%3C=%20\(set\).md)|[operador\<\= \(multiset\)](../Topic/operator%3C=%20\(multiset\).md)|Testa se o conjunto ou objeto multiset no lado esquerdo do operador é menor ou igual ao conjunto ou objeto multiset no lado direito.|  
|[operador\=\= \(set\)](../Topic/operator==%20\(set\).md)|[operador\=\= \(multiset\)](../Topic/operator==%20\(multiset\).md)|Testa se o conjunto ou objeto multiset no lado esquerdo do operador é igual ao conjunto ou objeto multiset no lado direito.|  
|[operador\> \(set\)](../Topic/operator%3E%20\(set\).md)|[operador\> \(multiset\)](../Topic/operator%3E%20\(multiset\).md)|Testa se o conjunto ou objeto multiset no lado esquerdo do operador é maior do que o conjunto ou objeto multiset no lado direito.|  
|[operador\>\= \(set\)](../Topic/operator%3E=%20\(set\).md)|[operador\>\= \(multiset\)](../Topic/operator%3E=%20\(multiset\).md)|Testa se o conjunto ou objeto multiset no lado esquerdo do operador é maior que ou igual ao conjunto ou objeto multiset no lado direito.|  
  
### Funções de Modelo Especializadas  
  
|Versão do conjunto|Versão multiset|Descrição|  
|------------------------|---------------------|---------------|  
|[swap \(set\)](../Topic/swap%20\(set\).md)|[swap \(multiconjunto\)](../Topic/swap%20\(multiset\).md)|Troca os elementos de dois conjuntos ou vários conjuntos.|  
  
### Classes  
  
|||  
|-|-|  
|[Classe set](../standard-library/set-class.md)|Usado para o armazenamento e recuperação de dados de uma coleção na qual os valores dos elementos contidos são exclusivos e servem como valores de chave de acordo com os quais os dados são automaticamente ordenados.|  
|[Classe multiset](../Topic/multiset%20Class.md)|Usado para o armazenamento e recuperação de dados de uma coleção na qual os valores dos elementos contidos não precisam ser exclusivos e na qual eles atuam como valores de chave de acordo com os quais os dados são automaticamente ordenados.|  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)