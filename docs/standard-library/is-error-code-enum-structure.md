---
title: Estrutura is_error_code_enum | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- future/std::is_error_code_enum
dev_langs:
- C++
ms.assetid: 84ae4b99-66d2-41ba-9b50-645fcbe14630
caps.latest.revision: 13
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: b76a484545b9e2c25e3b1ebecc5ba46353f7d18e
ms.lasthandoff: 02/25/2017

---
# <a name="iserrorcodeenum-structure"></a>Estrutura is_error_code_enum
Especialização que indica que [future_errc](../standard-library/future-enums.md#future_errc_enumeration) é adequado para armazenar um [error_code](../standard-library/error-code-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <>
struct is_error_code_enum<Future_errc> : public true_type;
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** future  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<future>](../standard-library/future.md)




