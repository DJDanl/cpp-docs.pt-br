---
title: C2299 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2299
dev_langs:
- C++
helpviewer_keywords:
- C2299
ms.assetid: d001c2bc-f6fd-47aa-8e42-0eb824d6441d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e21213f08e25050932274a64d0ed56db96f2a453
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33170837"
---
# <a name="compiler-error-c2299"></a>C2299 de erro do compilador
'function': alteração de comportamento: uma especialização explícita não pode ser um construtor de cópia ou operador de atribuição de cópia  
  
 Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual C++ 2005: as versões anteriores do Visual C++ permitiam especializações explícitas para um construtor de cópia ou um operador de atribuição de cópia.  
  
 Para resolver C2299, não faça o construtor de cópia ou operador de atribuição de uma função de modelo, mas em vez disso, uma função diferente do modelo que usa um tipo de classe. Qualquer código que chama o construtor de cópia ou operador de atribuição especificando explicitamente os argumentos de template precisa remover os argumentos de modelo.  
  
 O exemplo a seguir gera C2299:  
  
```  
// C2299.cpp  
// compile with: /c  
class C {  
   template <class T>  
   C (T t);  
  
   template <> C (const C&);   // C2299  
   C (const C&);   // OK  
};  
```