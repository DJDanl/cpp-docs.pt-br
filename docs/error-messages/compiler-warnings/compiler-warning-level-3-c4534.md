---
title: Compilador aviso (nível 3) C4534 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- c4534
dev_langs:
- C++
helpviewer_keywords:
- C4534
ms.assetid: ec2adf3b-d7a1-4005-bb0c-5d219df78dc8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1b765f5f654c8d533b0ae22d874e7657cd10d667
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33293027"
---
# <a name="compiler-warning-level-3-c4534"></a>Compilador C4534 de aviso (nível 3)
'construtor' não será um construtor padrão para a classe 'class' devido ao argumento padrão  
  
 Uma classe não gerenciada pode ter um construtor com parâmetros que têm valores padrão e o compilador usará isso como o construtor padrão. Uma classe marcada com o `value` palavra-chave não usará um construtor com valores padrão para os parâmetros como um construtor padrão.  
  
 Para obter mais informações, consulte [Classes e estruturas](../../windows/classes-and-structs-cpp-component-extensions.md).  
  
 O exemplo a seguir gera C4534:  
  
```  
// C4534.cpp  
// compile with: /W3 /clr /WX  
value class MyClass {  
public:  
   int ii;  
   MyClass(int i = 9) {   // C4534, will not be the default constructor  
      i++;  
   }  
};  
  
int main() {  
   MyClass ^ xx = gcnew MyClass;  
   xx->ii = 0;  
}  
```