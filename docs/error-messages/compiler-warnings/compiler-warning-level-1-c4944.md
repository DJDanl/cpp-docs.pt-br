---
title: Compilador (nível 1) de aviso C4944 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4944
dev_langs:
- C++
helpviewer_keywords:
- C4944
ms.assetid: e2905eb1-2e3b-4fab-a48b-c0cae0fd997f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 57ddad7aa383cfd6f8716d6b12fa56627c1ee0e0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4944"></a>Compilador C4944 de aviso (nível 1)
'symbol': não é possível importar símbolo de 'assembly1': como 'symbol' já existe no escopo atual  
  
 Um símbolo foi definido em um arquivo de código fonte e, em seguida, um #using instrução referenciado a um assembly que também definido o símbolo. O símbolo no assembly é ignorado.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir cria um componente com um tipo chamado ClassA.  
  
```  
// C4944.cs  
// compile with: /target:library  
// C# source code to create a dll  
public class ClassA {  
   public int i;  
}  
```  
  
## <a name="example"></a>Exemplo  
 Os exemplos a seguir geram C4944.  
  
```  
// C4944b.cpp  
// compile with: /clr /W1  
class ClassA {  
public:  
   int u;  
};  
  
#using "C4944.dll"   // C4944 ClassA also defined C4944.dll  
  
int main() {  
   ClassA * x = new ClassA();  
   x->u = 9;  
   System::Console::WriteLine(x->u);  
}  
```