---
title: "&lt; hash_set &gt; | Microsoft Docs"
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
  - "<hash_set>"
  - "std.<hash_set>"
  - "std::<hash_set>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho hash_set"
ms.assetid: 6b556967-c808-4869-9b4d-f9e030864435
caps.latest.revision: 22
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt; hash_set &gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  Esse cabeçalho é obsoleto. A alternativa é [\<unordered\_set\>](../standard-library/unordered-set.md).  
  
 Define o hash\_set de classes de modelo do contêiner e hash\_multiset e seus modelos de suporte.  
  
## Sintaxe  
  
```  
  
#include <hash_set>  
  
```  
  
## Comentários  
 No Visual C\+\+ .NET 2003, membros de [\< hash\_map \>](../standard-library/hash-map.md) e [\< hash\_set \>](#vclrfhash_set_header_file) arquivos de cabeçalho não estão mais no namespace padrão, mas em vez disso, foram movidos para o namespace stdext. Consulte [o Namespace stdext](../Topic/stdext%20Namespace.md) para obter mais informações.  
  
### Operadores  
  
|Versão Hash\_set|Versão Hash\_multiset|Descrição|  
|----------------------|---------------------------|---------------|  
|[operator\!\= \(hash\_set\)](../Topic/operator!=%20\(hash_set\).md)|[operator\!\= \(hash\_multiset\)](../Topic/operator!=%20\(hash_multiset\).md)|Testa se o objeto hash\_set ou hash\_multiset no lado esquerdo do operador não é igual ao objeto hash\_set ou hash\_multiset no lado direito.|  
|[operator\=\= \(hash\_set\)](http://msdn.microsoft.com/pt-br/791b95bd-f917-4716-aea6-add50badbfac)|[operator\=\= \(hash\_multiset\)](http://msdn.microsoft.com/pt-br/cfa9aa0c-d5f6-403a-9441-35c2a4cee0fb)|Testa se o objeto hash\_set ou hash\_multiset no lado esquerdo do operador é igual ao objeto hash\_set ou hash\_multiset no lado direito.|  
  
### Funções de Modelo Especializadas  
  
|Versão Hash\_set|Versão Hash\_multiset|Descrição|  
|----------------------|---------------------------|---------------|  
|[swap \(hash\_set\)](../Topic/swap%20\(hash_set\).md)|[swap \(hash\_multiset\)](../Topic/swap%20\(hash_multiset\).md)|Troca os elementos de dois hash\_sets ou hash\_multisets.|  
  
### Classes  
  
|||  
|-|-|  
|[Classe hash\_compare](../standard-library/hash-compare-class.md)|Descreve um objeto que pode ser usado por qualquer um dos contêineres associativos hash — hash\_map, hash\_multimap, hash\_set, ou hash\_multiset — como um padrão **características** objeto de parâmetro para solicitar e o hash de elementos que eles contêm.|  
|[Classe hash\_set](../standard-library/hash-set-class.md)|Usado para o armazenamento e recuperação rápida de dados de uma coleção na qual os valores dos elementos contidos são exclusivos em servem como os valores de chave.|  
|[Classe hash\_multiset](../Topic/hash_multiset%20Class.md)|Usado para o armazenamento e recuperação rápida de dados de uma coleção na qual os valores dos elementos contidos são exclusivos em servem como os valores de chave.|  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)