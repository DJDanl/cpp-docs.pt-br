---
title: C2993 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2993
dev_langs: C++
helpviewer_keywords: C2993
ms.assetid: 4ffd2b78-654b-46aa-95a6-b62101cf91c8
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3715e2183c8194fe7bcf2613cbee3a0052588385
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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