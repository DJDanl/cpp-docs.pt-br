---
title: Erro do compilador C2785 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2785
dev_langs:
- C++
helpviewer_keywords:
- C2785
ms.assetid: d8d13360-0d00-4815-8475-b49c7f0dc0f3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: cfae8a58d9c42c9ddc3ef7779fc86f7157ba41b0
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46080851"
---
# <a name="compiler-error-c2785"></a>Erro do compilador C2785

'declaration1' e 'declaration2' têm diferentes tipos de retorno

O tipo de retorno de especialização de modelo de função é diferente do tipo de retorno do modelo da função primária.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Verifique se todas as especializações do modelo da função para manter a consistência.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2785:

```
// C2785.cpp
// compile with: /c
template<class T> void f(T);

template<> int f(int); // C2785
template<> void f(int); // OK
```