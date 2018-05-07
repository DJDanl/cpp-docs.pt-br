---
title: C2753 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2753
dev_langs:
- C++
helpviewer_keywords:
- C2753
ms.assetid: 92bfeeac-524a-4a8e-9a4f-fb8269055826
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: acbf5736c7c263293bc1c2782cab7df4f0af2083
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2753"></a>C2753 de erro do compilador
'*modelo*': especialização parcial não pode coincidir com a lista de argumentos para template primário  
  
 Se a lista de argumentos de modelo corresponde à lista de parâmetro, o compilador tratará como o mesmo modelo. Não é permitido definir duas vezes o mesmo modelo.  
  
## <a name="example"></a>Exemplo
 O exemplo a seguir gera C2753 e mostra uma maneira de corrigir isso:  
  
```cpp  
// C2753.cpp  
// compile with: cl /c C2753.cpp
template<class T>  
struct A {};  
  
template<class T>  
struct A<T> {};   // C2753  
// try the following line instead  
// struct A<int> {};  
  
template<class T, class U, class V, class W, class X>  
struct B {};  
```