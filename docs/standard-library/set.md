---
title: '&lt;set&gt; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std.<set>
- std::<set>
- <set>
dev_langs:
- C++
helpviewer_keywords:
- set header
ms.assetid: 43cb1ab2-6383-48cf-8bdc-2b96d7203596
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 2d05749ba2837a3879c91886b9266de47dd2ece6
ms.openlocfilehash: 1295a8c71464b7cc9d204c807c3492000b73ffa1
ms.lasthandoff: 02/25/2017

---
# <a name="ltsetgt"></a>&lt;set&gt;
Define as classes de modelo do contêiner set e multiset e seus modelos de suporte.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <set>  
  
```  
  
## <a name="members"></a>Membros  
  
### <a name="operators"></a>Operadores  
  
|Versão do set|Versão do multiset|Descrição|  
|-----------------|----------------------|-----------------|  
|[operator!= (set)](../standard-library/set-operators.md#operator_neq)|[operator!= (multiset)](../standard-library/set-operators.md#operator_neq)|Testa se o objeto set ou multiset à esquerda do operador é diferente do objeto set ou multiset à direita.|  
|[operator< (set)](../standard-library/set-operators.md#operator_lt_)|[operator< (multiset)](../standard-library/set-operators.md#operator_lt_)|Testa se o objeto set ou multiset à esquerda do operador é menor que o objeto set ou multiset à direita.|  
|[operator<= (set)](../standard-library/set-operators.md#operator_lt__eq)|[operator\<= (multiset)](../standard-library/set-operators.md#operator_lt__eq)|Testa se o objeto set ou multiset à esquerda do operador é menor ou igual ao objeto set ou multiset à direita.|  
|[operator== (set)](../standard-library/set-operators.md#operator_eq_eq)|[operator== (multiset)](../standard-library/set-operators.md#operator_eq_eq)|Testa se o objeto set ou multiset à esquerda do operador é igual ao objeto set ou multiset à direita.|  
|[operator> (set)](../standard-library/set-operators.md#operator_gt_)|[operator> (multiset)](../standard-library/set-operators.md#operator_gt_)|Testa se o objeto set ou multiset à esquerda do operador é maior que o objeto set ou multiset à direita.|  
|[operator>= (set)](../standard-library/set-operators.md#operator_gt__eq)|[operator>= (multiset)](../standard-library/set-operators.md#operator_gt__eq)|Testa se o objeto set ou multiset à esquerda do operador é maior ou igual ao objeto set ou multiset à direita.|  
  
### <a name="specialized-template-functions"></a>Funções de Modelo Especializadas  
  
|Versão do set|Versão do multiset|Descrição|  
|-----------------|----------------------|-----------------|  
|[swap](../standard-library/set-functions.md#swap)|[swap](../standard-library/set-functions.md#swap)|Troca os elementos de dois sets ou multisets.|  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[Classe set](../standard-library/set-class.md)|Usada para o armazenamento e a recuperação de dados de uma coleção na qual os valores dos elementos contidos são exclusivos e funcionam como os valores de chave, de acordo com os quais os dados são automaticamente ordenados.|  
|[Classe multiset](../standard-library/multiset-class.md)|Usada para o armazenamento e a recuperação de dados de uma coleção na qual os valores dos elementos contidos não precisam ser exclusivos e na qual funcionam como os valores de chave, de acordo com os quais os dados são automaticamente ordenados.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)




