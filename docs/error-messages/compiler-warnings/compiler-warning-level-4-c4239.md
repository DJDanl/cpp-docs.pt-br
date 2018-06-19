---
title: Compilador C4239 de aviso (nível 4) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4239
dev_langs:
- C++
helpviewer_keywords:
- C4239
ms.assetid: a23dc16a-649e-4870-9a24-275de1584fcd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d756bba65100d3e5c2987527d7a0dd4cc3fdc050
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33296283"
---
# <a name="compiler-warning-level-4-c4239"></a>Compilador C4239 de aviso (nível 4)
extensão não padrão usada: 'token': conversão de 'type' em 'type'  
  
 Essa conversão de tipo não é permitido por padrão do C++, mas é permitido aqui como uma extensão. Esse aviso é sempre seguido pelo menos uma linha de explicação que descreve a regra de idioma que está sendo violada.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4239.  
  
```  
// C4239.cpp  
// compile with: /W4 /c  
struct C {  
   C() {}  
};  
  
void func(void) {  
   C & rC = C();   // C4239  
   const C & rC2 = C();   // OK  
   rC2;  
}  
```  
  
## <a name="example"></a>Exemplo  
 Conversão de tipo integral para tipo enum não é estritamente permitida.  
  
 O exemplo a seguir gera C4239.  
  
```  
// C4239b.cpp  
// compile with: /W4 /c  
enum E { value };   
struct S {   
   E e : 2;   
} s = { 5 };   // C4239   
// try the following line instead  
// } s = { (E)5 };  
```