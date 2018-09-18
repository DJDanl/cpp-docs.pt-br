---
title: Erro do compilador C3195 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3195
dev_langs:
- C++
helpviewer_keywords:
- C3195
ms.assetid: 97e4f681-812b-49e8-ba57-24b7817e3cd8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3c299704b595ca6e6f6b81fb56ffad5534f81e6b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46040590"
---
# <a name="compiler-error-c3195"></a>Erro do compilador C3195

'operator': é reservado e não pode ser usado como um membro de um tipo de valor ou classe ref. Operadores CLR ou WinRT devem ser definidos usando a palavra-chave 'operator'

O compilador detectou uma definição de operador, usando as extensões gerenciadas para a sintaxe de C++. Você deve usar a sintaxe do C++ para operadores.

O exemplo a seguir gera C3195 e mostra como corrigi-lo:

```
// C3195.cpp
// compile with: /clr /LD
#using <mscorlib.dll>
value struct V {
   static V op_Addition(V v, int i);   // C3195
   static V operator +(V v, char c);   // OK for new C++ syntax
};
```