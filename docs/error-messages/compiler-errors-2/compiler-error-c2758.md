---
title: C2758 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2758
dev_langs:
- C++
helpviewer_keywords:
- C2758
ms.assetid: 1d273034-194c-4926-9869-142d1b219cbe
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2a67a978883153e0de81e864bf01e8cf9ee2e13c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2758"></a>C2758 de erro do compilador
'member': um membro de tipo de referência deve ser inicializado  
  
 Erro de compilador C2758 é causado quando o construtor não inicializar um membro de tipo de referência em uma lista de inicializadores. O compilador deixa o membro indefinido. Membro de referência devem variáveis inicializado quando declarados ou receberá um valor na lista de inicialização do construtor.  
  
 O exemplo a seguir gera C2758:  
  
```  
// C2758.cpp  
// Compile by using: cl /W3 /c C2758.cpp  
struct A {  
   const int i;  
  
   A(int n) { };   // C2758  
   // try the following line instead  
   // A(int n) : i{n} {};  
};  
```