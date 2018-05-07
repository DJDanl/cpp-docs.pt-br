---
title: C2993 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2993
dev_langs:
- C++
helpviewer_keywords:
- C2993
ms.assetid: 4ffd2b78-654b-46aa-95a6-b62101cf91c8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e25e70a9d16ee166772cf03ea1837afaf14cae29
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2993"></a>C2993 de erro do compilador
'Identificador': tipo inválido para parâmetro de modelo de tipo não 'parameter'  
  
 Você não pode declarar um modelo com uma estrutura ou um argumento de união. Use ponteiros para passar estruturas e uniões como parâmetros de modelo.  
  
 O exemplo a seguir gera C2993:  
  
```  
// C2993.cpp  
// compile with: /c  
// C2993 expected  
struct MyStruct {  
   int a;char b;  
};  
  
template <class T, struct MyStruct S>   // C2993  
  
// try the following line instead  
// template <class T, struct MyStruct * S>  
class CMyClass {};  
```  
  
 Esse erro também será gerado como resultado do trabalho de conformidade do compilador que foi feito no Visual Studio .NET 2003: parâmetros de modelo sem tipo não pode mais de ponto flutuante. O padrão C++ não permitir ponto flutuante parâmetros de modelo sem tipo.  
  
 Se for um modelo de função, use um argumento de função para passar o flutuante ponto de parâmetro de modelo sem tipo (esse código será válido das versões do Visual Studio .NET 2003 e o Visual Studio .NET do Visual C++). Se for um modelo de classe, não há nenhuma solução alternativa mais simples.  
  
```  
// C2993b.cpp  
// compile with: /c  
template<class T, float f> void func(T) {}   // C2993  
  
// OK  
template<class T>   void func2(T, float) {}  
```