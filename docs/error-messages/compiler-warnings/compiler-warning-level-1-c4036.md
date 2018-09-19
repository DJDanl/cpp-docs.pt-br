---
title: Compilador aviso (nível 1) C4036 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4036
dev_langs:
- C++
helpviewer_keywords:
- C4036
ms.assetid: f0b15359-4d62-48ec-8cb1-a7b36587a47f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5be923193723168a474ad7403dc85cfbade28a70
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46032839"
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