---
title: C2897 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2897
dev_langs:
- C++
helpviewer_keywords:
- C2897
ms.assetid: a88349e2-823f-42a0-8660-0653b677afa4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1c3de4c0d3e6a93a783dfb660bc26f07be6fcacf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33245878"
---
# <a name="compiler-error-c2897"></a>C2897 de erro do compilador
um destruidor/finalizador não pode ser um template de função  
  
 Destruidores ou finalizadores não podem ser sobrecarregados, para que declarar um destruidor como um modelo (que define um conjunto de destruidores) não é permitido.  
  
 O exemplo a seguir gera C2897:  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2897.  
  
```  
// C2897.cpp  
// compile with: /c  
class X {  
public:  
   template<typename T> ~X() {}   // C2897  
};  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2897.  
  
```  
// C2897_b.cpp  
// compile with: /c /clr  
ref struct R2 {  
protected:  
   template<typename T> !R2(){}   // C2897 error  
};  
```