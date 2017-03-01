---
title: "Compilador aviso (nível 1) C4944 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4944
dev_langs:
- C++
helpviewer_keywords:
- C4944
ms.assetid: e2905eb1-2e3b-4fab-a48b-c0cae0fd997f
caps.latest.revision: 8
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
ms.openlocfilehash: f8c6e857bf9b77cfcf0f0f0e511e71f7b9ecaa60
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4944"></a>Compilador C4944 de aviso (nível 1)
'symbol': não é possível importar o símbolo de 'assembly1': como 'symbol' já existe no escopo atual  
  
 Um símbolo foi definido em um arquivo de código fonte e, em seguida, um # instrução using um assembly que também definiu o símbolo referenciado. O símbolo no assembly é ignorado.  
  
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
