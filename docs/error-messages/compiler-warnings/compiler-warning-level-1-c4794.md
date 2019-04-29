---
title: Compilador aviso (nível 1) C4794
ms.date: 11/04/2016
f1_keywords:
- C4794
helpviewer_keywords:
- C4794
ms.assetid: badc9c36-fa1a-4fec-929b-7bfda7a7b79f
ms.openlocfilehash: d44e3af88de9457fdc5c2df905ccbae22d3562da
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62280367"
---
# <a name="compiler-warning-level-1-c4794"></a>Compilador aviso (nível 1) C4794

segmento da variável de armazenamento local de thread 'variável' alterado de 'nome da seção' para '$ TLS Section'

Você usou [#pragma data_seg](../../preprocessor/data-seg.md) para colocar uma variável de tls em uma seção não começando com $ TLS Section.

O $ TLS Section*x* seção continuará a existir no arquivo de objeto no qual [__declspec(thread)](../../cpp/thread.md) variáveis são definidas. Uma seção do TLS Section no EXE ou DLL resultarão essas seções.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4794:

```
// C4794.cpp
// compile with: /W1 /c
#pragma data_seg(".someseg")
__declspec(thread) int i;   // C4794

// OK
#pragma data_seg(".tls$9")
__declspec(thread) int j;
```