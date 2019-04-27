---
title: Compilador aviso (nível 1) C4036
ms.date: 11/04/2016
f1_keywords:
- C4036
helpviewer_keywords:
- C4036
ms.assetid: f0b15359-4d62-48ec-8cb1-a7b36587a47f
ms.openlocfilehash: 632e88bb64568c97e937e83e177598054a954f22
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62151780"
---
# <a name="compiler-warning-level-1-c4036"></a>Compilador aviso (nível 1) C4036

sem nome 'type' como parâmetro real

Nenhum nome de tipo é fornecido para uma estrutura, união, enumeração ou classe usada como um parâmetro real. Se você estiver usando [/Zg](../../build/reference/zg-generate-function-prototypes.md) para gerar protótipos de função, o compilador emite esse aviso e comenta o parâmetro formal no protótipo gerado.

Especifique um nome de tipo para resolver este aviso.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4036.

```
// C4036.c
// compile with: /Zg /W1
// D9035 expected
typedef struct { int i; } T;
void f(T* t) {}   // C4036

// OK
typedef struct MyStruct { int i; } T2;
void f2(T2 * t) {}
```