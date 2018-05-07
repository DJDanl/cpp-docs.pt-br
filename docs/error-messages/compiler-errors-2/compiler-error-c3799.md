---
title: C3799 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3799
dev_langs:
- C++
helpviewer_keywords:
- C3799
ms.assetid: 336a2811-9370-4e6e-b03b-325bda470805
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f5e13e1e92b3f821ffbed62b06bd601baac7aad9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3799"></a>C3799 de erro do compilador
propriedade indexada não pode ter uma lista de parâmetros vazia  
  
Uma propriedade indexada foi declarada incorretamente. Para obter mais informações, consulte [como: usar propriedades no C + + CLI](../../dotnet/how-to-use-properties-in-cpp-cli.md).  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir gera C3799 e mostra como corrigi-lo.  
  
```cpp  
// C3799.cpp  
// compile with: /clr /c  
ref struct C {  
   property int default[] {   // C3799  
   // try the following line instead  
   // property int default[int] {  
      int get(int index) { return 0; }  
      void set(int index, int value) {}  
   }  
};  
```