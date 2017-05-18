---
title: C2084 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2084
dev_langs:
- C++
helpviewer_keywords:
- C2084
ms.assetid: 990b107f-3721-4851-ae8b-4b69a8c149ed
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0d9cbb01d1ad0f2ea65d59334cb88140ef18fce0
ms.openlocfilehash: 653dc7a4a5d330efc89942fbe4ddd07bff81f770
ms.contentlocale: pt-br
ms.lasthandoff: 04/12/2017

---
# <a name="compiler-error-c2084"></a>C2084 de erro do compilador
função '*função*' já tem um corpo  
  
 A função já foi definida.  
  
 Em versões do Visual C++, Visual Studio 2002, antes de  
  
-   O compilador aceite vários especializações de modelo que é resolvido para o mesmo tipo real, embora as definições adicionais nunca estarão disponíveis. Agora, o compilador detecta essas várias definições.  
  
-   `__int32`e `int` são tratadas como tipos separados. O compilador agora trata `__int32` como um sinônimo para `int`. Isso significa que o compilador detecta várias definições se uma função está sobrecarregada no `__int32` e `int` e retorna um erro.  
  
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
