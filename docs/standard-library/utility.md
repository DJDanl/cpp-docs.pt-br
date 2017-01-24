---
title: "&lt;utility&gt; | Microsoft Docs"
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
  - "<utility>"
  - "utility/std::<utility>"
  - "std.<utility>"
  - "std::<utility>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho utility"
ms.assetid: c4491103-5da9-47a1-9c2b-ed8bc64b0599
caps.latest.revision: 18
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;utility&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define os tipos, funções e operadores que ajudam a construir e gerenciar os pares de objetos, que são úteis sempre que dois objetos precisam ser tratados como se fossem um modelo Biblioteca STL \(Standard\).  
  
## Sintaxe  
  
```  
  
#include <utility>  
  
```  
  
## Comentários  
 Pares são amplamente usadas na biblioteca C\+\+ padrão.  Eles são necessários, como os argumentos e valores de retorno para diversas funções e tipos de elemento para contêineres como[classe map](../Topic/map%20Class.md)e[classe multimap](../standard-library/multimap-class.md).  O cabeçalho \< utility \> é automaticamente incluído por \< map \> para auxiliar no gerenciamento de seus elementos de tipo de par chave\/valor.  
  
### Classes  
  
|||  
|-|-|  
|[tuple\_element](../standard-library/tuple-element-class-utility.md)|Uma classe que encapsula o tipo de um`pair`elemento.|  
|[tuple\_size](../standard-library/tuple-size-class-utility.md)|Uma classe que encapsula`pair`contagem de elementos.|  
  
### Funções  
  
|||  
|-|-|  
|[avançar](../Topic/forward.md)|Preserva o tipo de referência \(o`lvalue`ou`rvalue`\) do argumento de sendo disfarçada pelo encaminhamento perfeito.|  
|[obter](../Topic/get%20Function%20%3Cutility%3E.md)|Uma função que obtém um elemento de uma`pair`objeto.|  
|[make\_pair](../Topic/make_pair.md)|Uma função auxiliar do modelo usada para construir objetos do tipo`pair`onde os tipos de componente se baseiam nos tipos de dados passados como parâmetros.|  
|[mover](../Topic/move.md)|Retorna o que for passado no argumento como um`rvalue`referência.|  
|[swap](../Topic/swap%20\(%3Cutility%3E\).md)|Troca os elementos de dois`pair`objetos.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\!\=](../Topic/operator!=%20\(%3Cutility%3E\).md)|Testa se o objeto par no lado esquerdo do operador não é igual ao objeto par no lado direito.|  
|[operator\=\=](../Topic/operator==%20\(%3Cutility%3E\).md)|Testa se o objeto par no lado esquerdo do operador é igual ao objeto par no lado direito.|  
|[operador \<](../Topic/operator%3C%20\(%3Cutility%3E\).md)|Testa se o par de objetos no lado esquerdo do operador é menor que o objeto par no lado direito.|  
|[Operador \<\=](../Topic/operator%3C=%20\(%3Cutility%3E\).md)|Testa se o par de objetos no lado esquerdo do operador é menor ou igual ao objeto par no lado direito.|  
|[Operador \>](../Topic/operator%3E%20\(%3Cutility%3E\).md)|Testa se o objeto par no lado esquerdo do operador é maior que o objeto par no lado direito.|  
|[Operador \>\=](../Topic/operator%3E=%20\(%3Cutility%3E\).md)|Testa se o objeto par no lado esquerdo do operador é maior que ou igual ao objeto par no lado direito.|  
  
### Nome Forte  
  
|||  
|-|-|  
|[identidade](../Topic/identity%20Structure.md)||  
|[par](../standard-library/pair-structure.md)|Um tipo que fornece a capacidade de tratar os dois objetos como um único objeto.|  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)