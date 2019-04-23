---
title: Erro do compilador C3622
ms.date: 11/04/2016
f1_keywords:
- C3622
helpviewer_keywords:
- C3622
ms.assetid: 02836f78-0cf2-4947-b87e-710187d81014
ms.openlocfilehash: ed307f46db1261d79d5b0ec6b36852cac2e6d13e
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59776113"
---
# <a name="compiler-error-c3622"></a>Erro do compilador C3622

'class': uma classe declarada como 'palavra-chave' não pode ser instanciada.

Foi feita uma tentativa de instanciar uma classe marcada como [abstrata](../../extensions/abstract-cpp-component-extensions.md). Uma classe marcada como `abstract` pode ser uma classe base, mas ele não pode ser instanciado.

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
