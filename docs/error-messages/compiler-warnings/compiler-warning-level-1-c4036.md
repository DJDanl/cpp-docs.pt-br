---
title: Aviso do compilador (nível 1) C4036
ms.date: 11/04/2016
f1_keywords:
- C4036
helpviewer_keywords:
- C4036
ms.assetid: f0b15359-4d62-48ec-8cb1-a7b36587a47f
ms.openlocfilehash: 858cf089d3f681438a221115c8758c38a5cf8d9a
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73626263"
---
# <a name="compiler-warning-level-1-c4036"></a>Aviso do compilador (nível 1) C4036

' type ' sem nome como parâmetro real

Nenhum nome de tipo é fornecido para uma estrutura, União, enumeração ou classe usada como um parâmetro real. Se você estiver usando [/ZG](../../build/reference/zg-generate-function-prototypes.md) para gerar protótipos de função, o compilador emite esse aviso e comenta o parâmetro formal no protótipo gerado.

Especifique um nome de tipo para resolver este aviso.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4036.

```c
// C4036.c
// compile with: /Zg /W1
// D9035 expected
typedef struct { int i; } T;
void f(T* t) {}   // C4036

// OK
typedef struct MyStruct { int i; } T2;
void f2(T2 * t) {}
```