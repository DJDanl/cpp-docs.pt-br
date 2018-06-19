---
title: C2084 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2084
dev_langs:
- C++
helpviewer_keywords:
- C2084
ms.assetid: 990b107f-3721-4851-ae8b-4b69a8c149ed
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3ce1510dd6e78b8774d3cc433f583c16cdbb8d06
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33173871"
---
# <a name="compiler-error-c2084"></a>C2084 de erro do compilador
função '*função*' já tem um corpo  
  
 A função já foi definida.  
  
 Em versões do Visual C++, Visual Studio 2002, antes de  
  
-   O compilador aceite vários especializações de modelo que é resolvido para o mesmo tipo real, embora as definições adicionais nunca estarão disponíveis. Agora, o compilador detecta essas várias definições.  
  
-   `__int32` e `int` são tratadas como tipos separados. O compilador agora trata `__int32` como um sinônimo para `int`. Isso significa que o compilador detecta várias definições se uma função está sobrecarregada no `__int32` e `int` e retorna um erro.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2084:  
  
```cpp  
// C2084.cpp  
void Func(int);  
void Func(int) {}   // define function  
void Func(int) {}   // C2084 second definition  
```  
  
Para corrigir esse erro, remova a definição de duplicados:  
  
```  
// C2084b.cpp  
// compile with: /c  
void Func(int);  
void Func(int) {}  
```