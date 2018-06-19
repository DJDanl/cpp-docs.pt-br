---
title: C3920 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3920
dev_langs:
- C++
helpviewer_keywords:
- C3920
ms.assetid: 66e91f28-ed82-4ce2-bf22-c0c74905b1ed
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6ced0a0f8fa2b6694de4dd901d71f6721e12493b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33270274"
---
# <a name="compiler-error-c3920"></a>C3920 de erro do compilador
' operador ': não é possível definir um incremento/decremento de sufixo WinRT ou um operador CLR chamando o sufixo prefixo correspondente será chamada de operador de WinRT ou CLR WinRT ou CLR operador (op_Increment/op_Decrement), mas com semântica de pós-fixo  
  
 O tempo de execução do Windows e o CLR não dão suporte para o operador de sufixo e operadores de sufixo definida pelo usuário não são permitidas.  Você pode definir um operador de prefixo e o operador de prefixo que será usado para operações de pré e pós-incrementos.  
  
 O exemplo a seguir gera C3920 e mostra como corrigi-lo:  
  
```  
// C3920.cpp  
// compile with: /clr /LD  
public value struct V {  
   static V operator ++(V me, int)  
   // try the following line instead  
   // static V operator ++(V me)  
   {   // C3920  
      me.m_i++;  
      return me;  
   }  
  
   int m_i;  
};  
  
```