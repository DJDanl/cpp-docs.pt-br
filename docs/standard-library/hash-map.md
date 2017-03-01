---
title: '&lt;hash_map&gt; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std.<hash_map>
- <hash_map>
- std::<hash_map>
dev_langs:
- C++
helpviewer_keywords:
- hash_map header
ms.assetid: 0765708a-a668-42a2-9800-654c857bdcc2
caps.latest.revision: 27
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 51fbd09793071631985720550007dddbe16f598f
ms.openlocfilehash: 3f9a4705d946831ddee15116676fde9e433288f7
ms.lasthandoff: 02/25/2017

---
# <a name="lthashmapgt"></a>&lt;hash_map&gt;
> [!NOTE]
>  Este cabeçalho é obsoleto. A alternativa é a [<unordered_map>](../standard-library/unordered-map.md).  
  
 Define as classes de modelo do contêiner hash_map e hash_multimap e seus modelos de suporte.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho <hash_map> e <hash_set> não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <hash_map>  
  
```  
  
### <a name="operators"></a>Operadores  
  
|Versão hash_map|Versão hash_multimap|Descrição|  
|-----------------------|----------------------------|-----------------|  
|[operator!= (hash_map)](../standard-library/hash-map-operators.md#operator_neq__hash_map_)|[operator!= (hash_multimap)](../standard-library/hash-map-operators.md#operator_neq)|Testa se o objeto hash_map ou hash_multimap no lado esquerdo do operador não é igual ao objeto hash_map ou hash_multimap no lado direito.|  
|[operator== (hash_map)](http://msdn.microsoft.com/en-us/f933cb1c-934d-43f5-aa9e-0b325eb95b85)|[operator== (hash_multimap)](http://msdn.microsoft.com/en-us/3fa378b1-0250-4e3f-a130-dc14103fc5e9)|Testa se o objeto hash_map ou hash_multimap no lado esquerdo do operador é igual ao objeto hash_map ou hash_multimap no lado direito.|  
  
### <a name="specialized-template-functions"></a>Funções de Modelo Especializadas  
  
|Versão hash_map|Versão hash_multimap|Descrição|  
|-----------------------|----------------------------|-----------------|  
|[swap (hash_map)](../standard-library/hash-map-class.md#hash_map__swap)|[swap (hash_multimap)](../standard-library/hash-multimap-class.md#hash_multimap__swap)|Troca os elementos de dois hash_maps ou hash_multimaps.|  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[Classe hash_compare](../standard-library/hash-compare-class.md)|Descreve um objeto que pode ser usado por qualquer um dos contêineres associativos de hash — hash_map, hash_multimap, hash_set ou hash_multiset — como um objeto de parâmetro **Traits** padrão para ordenar e fazer o hash dos elementos que eles contêm.|  
|[Classe value_compare](../standard-library/value-compare-class.md)|Fornece um objeto de função que pode comparar os elementos de um hash_map comparando os valores de suas chaves para determinar sua ordem relativa no hash_map.|  
|[Classe hash_map](../standard-library/hash-map-class.md)|Usado para o armazenamento e a recuperação rápida de dados de uma coleção em que cada elemento é um par que tem uma chave de classificação cujo valor é único, bem como um valor de dados associado.|  
|[Classe hash_multimap](../standard-library/hash-multimap-class.md)|Usado para o armazenamento e a recuperação rápida de dados de uma coleção em que cada elemento é um par que tem uma chave de classificação cujo valor não precisa ser único e ser um valor de dados associado.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<hash_map>  
  
 **Namespace:** stdext  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)




