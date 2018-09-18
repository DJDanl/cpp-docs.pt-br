---
title: Erro do compilador C2483 | Microsoft Docs
ms.custom: ''
ms.date: 09/15/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2483
dev_langs:
- C++
helpviewer_keywords:
- C2483
ms.assetid: 5762b325-914b-442d-a604-e4617ba04038
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: be2a2caef9e1252bf1ab36253a7f5f715b94d5a3
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46031607"
---
# <a name="compiler-error-c2483"></a>Erro do compilador C2483

>'*identificador*': objeto com o construtor ou destruidor não pode ser declarado 'thread'

Essa mensagem de erro está obsoleta no Visual Studio 2015 e versões posteriores. Nas versões anteriores, as variáveis declaradas com o `thread` atributo não pode ser inicializado com um construtor ou outra expressão que requer avaliação de tempo de execução. Uma expressão estática é necessário para inicializar `thread` dados.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2483 no Visual Studio 2013 e versões anteriores.

```cpp
// C2483.cpp
// compile with: /c
__declspec(thread) struct A {
   A(){}
   ~A(){}
} aa;   // C2483 error

__declspec(thread) struct B {} b;   // OK
```

## <a name="see-also"></a>Consulte também

[thread](../../cpp/thread.md)