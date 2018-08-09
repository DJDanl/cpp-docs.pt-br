---
title: Listas de argumentos variáveis (...) (C + + / CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- variable argument lists
- parameter arrays
ms.assetid: db1a27f4-02a8-4318-8690-1f2893f52b38
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 054d91881d136564cdfb956f240789ca5a425ef2
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39642936"
---
# <a name="variable-argument-lists--ccli"></a>Listas de Argumentos Variáveis (...) (C++/CLI)
Este exemplo mostra como você pode usar o `...` sintaxe no Visual C++ para implementar as funções que têm um número variável de argumentos.  
  
> [!NOTE]
>  Este tópico pertence ao C + + / CLI. Para obter informações sobre como usar o `...` em C++ padrão ISO, consulte [reticências e modelos Variadic](../cpp/ellipses-and-variadic-templates.md) e nas reticências e argumentos padrão em [expressões pós-fixadas](../cpp/postfix-expressions.md).  
  
 O parâmetro que usa `...` deve ser o último parâmetro na lista de parâmetros.  
  
## <a name="example"></a>Exemplo  
  
### <a name="code"></a>Código  
  
```cpp  
// mcppv2_paramarray.cpp  
// compile with: /clr  
using namespace System;  
double average( ... array<Int32>^ arr ) {  
   int i = arr->GetLength(0);  
   double answer = 0.0;  
  
   for (int j = 0 ; j < i ; j++)  
      answer += arr[j];  
  
   return answer / i;  
}  
  
int main() {  
   Console::WriteLine("{0}", average( 1, 2, 3, 6 ));  
}  
```  
  
### <a name="output"></a>Saída  
  
```  
3  
```  
  
## <a name="code-example"></a>Exemplo de código  
 O exemplo a seguir mostra como chamar de c# uma função do Visual C++ que usa um número variável de argumentos.  
  
```cpp  
// mcppv2_paramarray2.cpp  
// compile with: /clr:safe /LD  
using namespace System;  
  
public ref class C {  
public:   
   void f( ... array<String^>^ a ) {}  
};  
```  
  
 A função `f` pode ser chamado do c# ou Visual Basic, por exemplo, como se fosse uma função que pode ser um número variável de argumentos.  
  
 No c#, um argumento que é passado para um `ParamArray` parâmetro pode ser chamado por um número variável de argumentos. O exemplo de código a seguir está em c#.  
  
```cs  
// mcppv2_paramarray3.cs  
// compile with: /r:mcppv2_paramarray2.dll  
// a C# program  
  
public class X {  
   public static void Main() {  
      // Visual C# will generate a String array to match the   
      // ParamArray attribute  
      C myc = new C();  
      myc.f("hello", "there", "world");  
   }  
}  
```  
  
 Uma chamada para `f` no Visual C++ pode passar uma matriz inicializada ou uma matriz de comprimento variável.  
  
```cpp  
// mcpp_paramarray4.cpp  
// compile with: /clr  
using namespace System;  
  
public ref class C {  
public:   
   void f( ... array<String^>^ a ) {}  
};  
  
int main() {  
   C ^ myc = gcnew C();  
   myc->f("hello", "world", "!!!");  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Matrizes](../windows/arrays-cpp-component-extensions.md)