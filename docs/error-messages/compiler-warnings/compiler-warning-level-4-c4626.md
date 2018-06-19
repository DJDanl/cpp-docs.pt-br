---
title: Compilador (nível 4) de aviso C4626 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4626
dev_langs:
- C++
helpviewer_keywords:
- C4626
ms.assetid: 7f822ff4-a4a3-4f17-b45b-e8b7b4659a14
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4e43aa93a2f40d97ef3db5c2f556b04e84512724
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33295130"
---
# <a name="compiler-warning-level-4-c4626"></a>Compilador C4626 de aviso (nível 4)
'classe derivada': operador de atribuição foi implicitamente definido como excluído, pois um operador de atribuição de classe base é inacessível ou excluídos  
  
 Um operador de atribuição foi excluído ou não está acessível na classe base e, portanto, não foi gerado para uma classe derivada. Qualquer tentativa de atribuir objetos desse tipo causará um erro do compilador.  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.  
  
 O exemplo a seguir gera C4626 e mostra como corrigi-lo:  
  
```  
// C4626  
// compile with: /W4  
#pragma warning(default : 4626)  
class B  
{  
// public:  
   B& operator = (const B&)  
   {  
      return *this;  
   }  
};  
  
class D : public B  
{  
  
}; // C4626 - to fix, make B's copy constructor public  
  
int main()  
{  
   D m;  
   D n;  
   // m = n;   // this line will cause an error  
}  
```