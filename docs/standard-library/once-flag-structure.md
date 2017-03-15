---
title: Estrutura once_flag | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- mutex/std::once_flag
dev_langs:
- C++
ms.assetid: 71bfb88d-ca8c-4082-a6e1-ff52151e8629
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
ms.openlocfilehash: 5f9efb15e4d50d87439b3e696b3b9e52f4656f3e
ms.lasthandoff: 02/25/2017

---
# <a name="onceflag-structure"></a>Estrutura once_flag
Representa um `struct` que é usado com a função de modelo [call_once](../standard-library/mutex-functions.md#call_once_function) para garantir que o código de inicialização seja chamado apenas uma vez, mesmo na presença de vários threads de execução.  
  
## <a name="syntax"></a>Sintaxe  
  
struct once_flag { constexpr once_flag() noexcept; once_flag(const once_flag&); once_flag& operator=(const once_flag&); };  
  
## <a name="remarks"></a>Comentários  
 O `once_flag``struct` tem somente um construtor padrão.  
  
 Objetos do tipo `once_flag` podem ser criados, mas não podem ser copiados.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** mutex  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<mutex>](../standard-library/mutex.md)




