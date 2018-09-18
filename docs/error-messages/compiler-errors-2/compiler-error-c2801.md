---
title: Erro do compilador C2801 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2801
dev_langs:
- C++
helpviewer_keywords:
- C2801
ms.assetid: 35dfc7ea-9e37-4e30-baa1-944dc61302f5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d57ee5bf5f5152ef55852c9f9b829bc4a1d17d41
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46040629"
---
# <a name="compiler-error-c2801"></a>Erro do compilador C2801

'operador operator' deve ser um membro não estático

Os operadores a seguir podem ser sobrecarregados apenas como os membros não estáticos:

- Atribuição `=`

- Acesso de membro de classe `->`

- Subscripting `[]`

- Chamada de função `()`

Possíveis causas de C2801:

- Operador sobrecarregado não é uma classe, estrutura ou membro de união.

- Operador sobrecarregado é declarado `static`.

- O exemplo a seguir gera C2801:

```
// C2801.cpp
// compile with: /c
operator[]();   // C2801 not a member
class A {
   static operator->();   // C2801 static
   operator()();   // OK
};
```