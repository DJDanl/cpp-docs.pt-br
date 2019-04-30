---
title: Erro do compilador C2530
ms.date: 11/04/2016
f1_keywords:
- C2530
helpviewer_keywords:
- C2530
ms.assetid: b790a312-48df-4a6a-9e27-be2c5f32f16c
ms.openlocfilehash: 2c8164cad25d68ee61ff9fed7170482d5dfc9505
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386987"
---
# <a name="compiler-error-c2530"></a>Erro do compilador C2530

'identifier': as referências devem ser inicializadas.

Você deve inicializar uma referência quando ele tiver sido declarado, a menos que ela é declarada já:

- Com a palavra-chave [extern](../../cpp/using-extern-to-specify-linkage.md).

- Como um membro de uma classe, estrutura ou união (e ele é inicializado no construtor).

- Como um parâmetro em uma definição ou declaração de função.

- Como o tipo de retorno de uma função.

O exemplo a seguir gera C2530:

```
// C2530.cpp
int main() {
   int i = 0;
   int &j;   // C2530
   int &k = i;   // OK
}
```