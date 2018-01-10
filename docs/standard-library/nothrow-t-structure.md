---
title: Estrutura nothrow_t | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: nothrow_t
dev_langs: C++
helpviewer_keywords: nothrow_t class
ms.assetid: dc7d5d42-ed5a-4919-88fe-bbad519b7a1d
caps.latest.revision: "20"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9975df6ca866ce45a0e4859d19c6cfd6f3f96db2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="nothrowt-structure"></a>Estrutura nothrow_t
O struct é usado como um parâmetro de função para o operador new para indicar que a função deve retornar um ponteiro nulo para relatar uma falha de alocação, em vez de lançar uma exceção.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct std::nothrow_t {};
```  
  
## <a name="remarks"></a>Comentários  
 O struct ajuda o compilador a selecionar a versão correta do construtor. [nothrow](../standard-library/new-functions.md#nothrow) é um sinônimo para objetos do tipo `std::nothrow_t`.  
  
## <a name="example"></a>Exemplo  
 Consulte [operador new](../standard-library/new-operators.md#op_new) e [operador new&#91;&#93;](../standard-library/new-operators.md#op_new_arr) para obter exemplos de como `std::nothrow_t` é usado como um parâmetro de função.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<new>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)



