---
title: '&lt;hash_set&gt; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- <hash_set>
- std::<hash_set>
dev_langs: C++
helpviewer_keywords: hash_set header
ms.assetid: 6b556967-c808-4869-9b4d-f9e030864435
caps.latest.revision: "22"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 33e24abf65219d7dbf8d9095529278079cdb3acd
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="lthashsetgt"></a>&lt;hash_set&gt;
> [!NOTE]
>  Este cabeçalho é obsoleto. A alternativa é [<unordered_set>](../standard-library/unordered-set.md).  
  
 Define as classes de modelo do contêiner hash_set e hash_multiset e seus modelos de suporte.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <hash_set>  
  
```  
  
## <a name="remarks"></a>Comentários  
  
### <a name="operators"></a>Operadores  
  
|Versão hash_set|Versão hash_multiset|Descrição|  
|-----------------------|----------------------------|-----------------|  
|[operator!= (hash_set)](../standard-library/hash-set-operators.md#op_neq)|[operator!= (hash_multiset)](../standard-library/hash-set-operators.md#op_neq)|Testa se o objeto hash_set ou hash_multiset no lado esquerdo do operador não é igual ao objeto hash_set ou hash_multiset no lado direito.|  
|[operator== (hash_set)](../standard-library/hash-set-operators.md#op_eq_eq)|[operator== (hash_multiset)](../standard-library/hash-set-operators.md#op_eq_eq)|Testa se o objeto hash_set ou hash_multiset no lado esquerdo do operador é igual ao objeto hash_set ou hash_multiset no lado direito.|  
  
### <a name="specialized-template-functions"></a>Funções de Modelo Especializadas  
  
|Versão hash_set|Versão hash_multiset|Descrição|  
|-----------------------|----------------------------|-----------------|  
|[swap (hash_set)](../standard-library/hash-set-functions.md#swap)|[swap (hash_multiset)](../standard-library/hash-set-functions.md#swap_hash_multiset)|Troca os elementos de dois hash_sets ou hash_multisets.|  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[Classe hash_compare](../standard-library/hash-compare-class.md)|Descreve um objeto que pode ser usado por qualquer um dos contêineres associativos de hash — hash_map, hash_multimap, hash_set ou hash_multiset — como um objeto de parâmetro **Traits** padrão para ordenar e fazer o hash dos elementos que eles contêm.|  
|[Classe hash_set](../standard-library/hash-set-class.md)|Usado para o armazenamento e a recuperação rápida de dados de uma coleção na qual os valores dos elementos contidos são exclusivos e funcionam como valores chave.|  
|[Classe hash_multiset](../standard-library/hash-multiset-class.md)|Usado para o armazenamento e a recuperação rápida de dados de uma coleção na qual os valores dos elementos contidos são exclusivos e funcionam como valores chave.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)



