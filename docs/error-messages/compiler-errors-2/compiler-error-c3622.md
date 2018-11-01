---
title: Erro do compilador C3622
ms.date: 11/04/2016
f1_keywords:
- C3622
helpviewer_keywords:
- C3622
ms.assetid: 02836f78-0cf2-4947-b87e-710187d81014
ms.openlocfilehash: 69565a1a2d159623bca927a94543834d18c13299
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50518086"
---
# <a name="compiler-error-c3622"></a>Erro do compilador C3622

'class': uma classe declarada como 'palavra-chave' não pode ser instanciada.

Foi feita uma tentativa de instanciar uma classe marcada como [abstrata](../../windows/abstract-cpp-component-extensions.md). Uma classe marcada como `abstract` pode ser uma classe base, mas ele não pode ser instanciado.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3622.

```
// C3622.cpp
// compile with: /clr
ref class a abstract {};

int main() {
   a aa;   // C3622
}
```
