---
title: Aviso do compilador (nível 1) C4794
ms.date: 11/04/2016
f1_keywords:
- C4794
helpviewer_keywords:
- C4794
ms.assetid: badc9c36-fa1a-4fec-929b-7bfda7a7b79f
ms.openlocfilehash: 7f7ea7555937069caf5f83c9bf00f0fa980ef020
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175110"
---
# <a name="compiler-warning-level-1-c4794"></a>Aviso do compilador (nível 1) C4794

o segmento da variável de armazenamento local do thread ' variável ' mudou de ' nome da seção ' para '. TLS $ '

Você usou [#pragma data_seg](../../preprocessor/data-seg.md) para colocar uma variável TLS em uma seção que não começa com. TLS $.

A seção. TLS $*x* existirá no arquivo de objeto em que as variáveis [de __declspec (thread)](../../cpp/thread.md) são definidas. Uma seção. TLS no EXE ou DLL resultará nessas seções.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4794:

```cpp
// C4794.cpp
// compile with: /W1 /c
#pragma data_seg(".someseg")
__declspec(thread) int i;   // C4794

// OK
#pragma data_seg(".tls$9")
__declspec(thread) int j;
```
