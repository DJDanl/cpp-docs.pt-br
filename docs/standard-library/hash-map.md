---
title: "&lt; hash_map &gt; | Microsoft Docs"
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
  - "std.<hash_map>"
  - "<hash_map>"
  - "std::<hash_map>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho hash_map"
ms.assetid: 0765708a-a668-42a2-9800-654c857bdcc2
caps.latest.revision: 27
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt; hash_map &gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  Esse cabeçalho é obsoleto. A alternativa é [\<unordered\_map\>](../standard-library/unordered-map.md).  
  
 Define o hash\_map de classes de modelo do contêiner e hash\_multimap e seus modelos de suporte.  
  
 No Visual C\+\+ .NET 2003, membros de [\< hash\_map \>](#vclrfhash_map_header_file) e [\< hash\_set \>](../standard-library/hash-set.md) arquivos de cabeçalho não estão mais no namespace padrão, mas em vez disso, foram movidos para o namespace stdext. Consulte [Namespace stdext](../Topic/stdext%20Namespace.md) para obter mais informações.  
  
## Sintaxe  
  
```  
  
#include <hash_map>  
  
```  
  
### Operadores  
  
|Versão Hash\_map|Versão Hash\_multimap|Descrição|  
|----------------------|---------------------------|---------------|  
|[operator\!\= \(hash\_map\)](../Topic/operator!=%20\(hash_map\).md)|[operator\!\= \(hash\_multimap\)](../Topic/operator!=%20\(hash_multimap\).md)|Testa se o objeto hash\_map ou hash\_multimap no lado esquerdo do operador não é igual ao objeto hash\_map ou hash\_multimap no lado direito.|  
|[operator\=\= \(hash\_map\)](http://msdn.microsoft.com/pt-br/f933cb1c-934d-43f5-aa9e-0b325eb95b85)|[operator\=\= \(hash\_multimap\)](http://msdn.microsoft.com/pt-br/3fa378b1-0250-4e3f-a130-dc14103fc5e9)|Testa se o objeto hash\_map ou hash\_multimap no lado esquerdo do operador é igual ao objeto hash\_map ou hash\_multimap no lado direito.|  
  
### Funções de Modelo Especializadas  
  
|Versão Hash\_map|Versão Hash\_multimap|Descrição|  
|----------------------|---------------------------|---------------|  
|[swap \(hash\_map\)](../Topic/hash_map::swap.md)|[swap \(hash\_multimap\)](../Topic/hash_multimap::swap.md)|Troca os elementos de dois hash\_maps ou hash\_multimaps.|  
  
### Classes  
  
|||  
|-|-|  
|[Classe hash\_compare](../standard-library/hash-compare-class.md)|Descreve um objeto que pode ser usado por qualquer um dos contêineres associativos hash — hash\_map, hash\_multimap, hash\_set, ou hash\_multiset — como um padrão **características** objeto de parâmetro para solicitar e o hash de elementos que eles contêm.|  
|[Classe value\_compare](../Topic/value_compare%20Class.md)|Fornece um objeto de função que pode comparar os elementos de um hash\_map, comparando os valores de suas chaves para determinar sua ordem relativa no hash\_map.|  
|[Classe hash\_map](../standard-library/hash-map-class.md)|Usado para o armazenamento e recuperação rápida de dados de uma coleção na qual cada elemento é um par que contém uma chave de classificação cujo valor é exclusivo e um valor de dados associados.|  
|[Classe hash\_multimap](../standard-library/hash-multimap-class.md)|Usado para o armazenamento e recuperação rápida de dados de uma coleção na qual cada elemento é um par que contém uma chave de classificação cujo valor não precisa ser exclusivo e um valor de dados associados.|  
  
## Requisitos  
 **Cabeçalho:** \< hash\_map \>  
  
 **Namespace:** stdext  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)