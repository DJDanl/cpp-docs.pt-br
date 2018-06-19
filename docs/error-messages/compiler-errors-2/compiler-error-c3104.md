---
title: C3104 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3104
dev_langs:
- C++
helpviewer_keywords:
- C3104
ms.assetid: b5648d47-e5d3-4b45-a3c0-f46e04eae731
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ded5185e3f87ce7f1b5a4a7015ce3c4476c949b5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33246461"
---
# <a name="compiler-error-c3104"></a>C3104 de erro do compilador
argumento de atributo inválido  
  
 Você especificou um argumento inválido para um atributo.  
  
 Consulte [tipos de parâmetro de atributo](../../windows/attribute-parameter-types-cpp-component-extensions.md) para obter mais informações.  
  
 Esse erro pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual C++ 2005: ao passar matrizes gerenciadas para atributos personalizados, o tipo da matriz não é deduzido da lista de inicialização de agregação. O compilador agora requer que você especifique o tipo de matriz, bem como a lista de inicializadores.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3104.  
  
```  
// C3104a.cpp  
// compile with: /clr /c  
using namespace System;  
  
[AttributeUsage(AttributeTargets::Class)]  
public ref struct ABC : public Attribute {  
   ABC(array<int>^){}  
   array<double> ^ param;  
};  
  
[ABC( {1,2,3}, param = {2.71, 3.14})]   // C3104  
// try the following line instead  
// [ABC( gcnew array<int> {1,2,3}, param = gcnew array<double>{2.71, 3.14})]   
ref struct AStruct{};  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3104.  
  
```  
// C3104b.cpp  
// compile with: /clr /c  
// C3104 expected  
using namespace System;  
  
int func() {  
   return 0;   
}  
  
[attribute(All)]  
ref class A {  
public:   
   A(int) {}  
};  
  
// Delete the following 2 lines to resolve.  
[A(func())]  
ref class B {};  
  
// OK  
[A(0)]  
ref class B {};  
```  
