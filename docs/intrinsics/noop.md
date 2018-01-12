---
title: NOOP | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- __noop_cpp
- __noop
dev_langs: C++
helpviewer_keywords: __noop keyword [C++]
ms.assetid: 81ac6e97-7bf8-496b-b3c4-fd02837573e5
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 348dc23e5ef3744ef1a3f152bf4d4fc5a22d2222
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="noop"></a>__noop
**Seção específica da Microsoft**  
  
 O `__noop` intrínseco Especifica que uma função deve ser ignorada e a lista de argumentos ser analisados, mas nenhum código gerado para os argumentos. Ele é destinado ao uso em funções de depuração global que possuem um número variável de argumentos.  
  
 O compilador converte o `__noop` intrínseco como 0 no tempo de compilação.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra como você poderia usar `__noop`.  
  
```  
// compiler_intrinsics__noop.cpp  
// compile with or without /DDEBUG  
#include <stdio.h>  
  
#if DEBUG  
   #define PRINT   printf_s  
#else  
   #define PRINT   __noop  
#endif  
  
int main() {  
   PRINT("\nhello\n");  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)