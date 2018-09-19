---
title: Erro do compilador C2842 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2842
dev_langs:
- C++
helpviewer_keywords:
- C2842
ms.assetid: 8674f08d-9f50-46ad-9229-abc6b74fa0e5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 20967ab4cd047f62a5cf692c91fec90148b4f470
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46118811"
---
# <a name="compiler-error-c2842"></a>Erro do compilador C2842

'class': um gerenciado ou o tipo de WinRT não pode definir seu próprio 'operator new' ou 'operator delete'

Você pode definir seus próprios * * operador new ou **operador delete** para gerenciar a alocação de memória no heap nativo. No entanto, as classes de referência não é possível definir esses operadores, pois eles só serão alocados no heap gerenciado.


Para obter mais informações, consulte [operadores definidos pelo usuário (C + + / CLI)](../../dotnet/user-defined-operators-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2842.

```
// C2842.cpp
// compile with: /clr /c
ref class G {
   void* operator new( size_t nSize );   // C2842
};
```
