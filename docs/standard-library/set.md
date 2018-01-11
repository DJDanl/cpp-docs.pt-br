---
title: '&lt;set&gt; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: <set>
dev_langs: C++
helpviewer_keywords: set header
ms.assetid: 43cb1ab2-6383-48cf-8bdc-2b96d7203596
caps.latest.revision: "20"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 16338888d64155ddeab188159030ac060ebb2b17
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
|[operator!= (set)](../standard-library/set-operators.md#op_neq)|[operator!= (multiset)](../standard-library/set-operators.md#op_neq)|Testa se o objeto set ou multiset à esquerda do operador é diferente do objeto set ou multiset à direita.|  
|[operator< (set)](../standard-library/set-operators.md#op_lt)|[operator< (multiset)](../standard-library/set-operators.md#op_lt_multiset)|Testa se o objeto set ou multiset à esquerda do operador é menor que o objeto set ou multiset à direita.|  
|[operator<= (set)](../standard-library/set-operators.md#op_lt_eq)|[operator\<= (multiset)](../standard-library/set-operators.md#op_lt_eq_multiset)|Testa se o objeto set ou multiset à esquerda do operador é menor ou igual ao objeto set ou multiset à direita.|  
|[operator== (set)](../standard-library/set-operators.md#op_eq_eq)|[operator== (multiset)](../standard-library/set-operators.md#op_eq_eq_multiset)|Testa se o objeto set ou multiset à esquerda do operador é igual ao objeto set ou multiset à direita.|  
|[operator> (set)](../standard-library/set-operators.md#op_gt)|[operator> (multiset)](../standard-library/set-operators.md#op_gt_multiset)|Testa se o objeto set ou multiset à esquerda do operador é maior que o objeto set ou multiset à direita.|  
|[operator>= (set)](../standard-library/set-operators.md#op_gt_eq)|[operator>= (multiset)](../standard-library/set-operators.md#op_gt_eq_multiset)|Testa se o objeto set ou multiset à esquerda do operador é maior ou igual ao objeto set ou multiset à direita.|  
  
### <a name="specialized-template-functions"></a>Funções de Modelo Especializadas  
  
|Versão do set|Versão do multiset|Descrição|  
|-----------------|----------------------|-----------------|  
|[swap](../standard-library/set-functions.md#swap)|[swap (multiset)](../standard-library/set-functions.md#swap_multiset)|Troca os elementos de dois sets ou multisets.|  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[Classe set](../standard-library/set-class.md)|Usada para o armazenamento e a recuperação de dados de uma coleção na qual os valores dos elementos contidos são exclusivos e funcionam como os valores de chave, de acordo com os quais os dados são automaticamente ordenados.|  
|[Classe multiset](../standard-library/multiset-class.md)|Usada para o armazenamento e a recuperação de dados de uma coleção na qual os valores dos elementos contidos não precisam ser exclusivos e na qual funcionam como os valores de chave, de acordo com os quais os dados são automaticamente ordenados.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)



