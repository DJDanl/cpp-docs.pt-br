---
title: Classe type_index | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- typeindex/std::type_index
dev_langs:
- C++
helpviewer_keywords:
- type_index class
ms.assetid: db366119-74cb-43e8-aacf-9679e561fa2f
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 384a3387110d1de51ec32735ad23280ddc60bf70
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="typeindex-class"></a>Classe type_index
A classe `type_index` encapsula um ponteiro para a [Classe type_info](../cpp/type-info-class.md) para auxiliar na indexação por esses objetos.  
  
classe type_index { public: type_index(const type_info& tinfo); const char *name() const; size_t hash_code() const; bool operator==(const type_info& right) const; bool operator!=(const type_info& right) const; bool operator<(const type_info& right) const; bool operator\<=(const type_info& right) const; bool operator>(const type_info& right) const; bool operator>=(const type_info& right) const; };  
  
 O construtor inicializa `ptr` para `&tinfo`.  
  
 `name` retorna `ptr->name()`.  
  
 `hash_code` retorna `ptr->hash_code().`  
  
 `operator==` retorna `*ptr == right.ptr`.  
  
 `operator!=` retorna `!(*this == right)`.  
  
 `operator<` retorna `*ptr->before(*right.ptr)`.  
  
 `operator<=` retorna `!(right < *this).`  
  
 `operator>` retorna `right < *this`.  
  
 `operator>=` retorna `!(*this < right)`.  
  
## <a name="see-also"></a>Consulte também  
 [Informações de tipo em tempo de execução](../cpp/run-time-type-information.md)   
 [\<typeindex>](../standard-library/typeindex.md)



