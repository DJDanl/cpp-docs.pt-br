---
title: Erro do compilador C2665 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2665
dev_langs:
- C++
helpviewer_keywords:
- C2665
ms.assetid: a7f99b61-2eae-4f2b-ba75-ea68fd1e8312
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b442e1de0481ef3d00742ed201575526332decff
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46109139"
---
# <a name="compiler-error-c2665"></a>Erro do compilador C2665

'function': nenhuma das sobrecargas Número1 pode converter Número2 de parâmetro de tipo 'type'

Um parâmetro da função sobrecarregada não pode ser convertido para o tipo solicitado.  Possíveis resoluções:

- Forneça um operador de conversão.

- Use conversão explícita.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2665.

```
// C2665.cpp
void func(short, char*){}
void func(char*, char*){}

int main() {
   func(0, 1);   // C2665
   func((short)0, (char*)1);   // OK
}
```