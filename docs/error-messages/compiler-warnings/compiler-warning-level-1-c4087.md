---
title: Compilador (nível 1) de aviso C4087 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4087
dev_langs:
- C++
helpviewer_keywords:
- C4087
ms.assetid: 546e4d57-5c8e-422c-8ef1-92657336dad5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e5b9962abc29b94425f96c978f3dd7e8d3f7c251
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33278438"
---
# <a name="compiler-warning-level-1-c4087"></a>Compilador C4087 de aviso (nível 1)
'function': declarado com lista de parâmetros 'void'  
  
 A declaração da função não possui parâmetros formais, mas a chamada de função tem parâmetros reais. Parâmetros adicionais são passados de acordo com a convenção de chamada da função.  
  
 Esse aviso é para o compilador C.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4087.c  
// compile with: /W1  
int f1( void ) {  
}  
  
int main() {  
   f1( 10 );   // C4087  
}  
```