---
title: Compilador aviso (nível 1) C4794 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4794
dev_langs:
- C++
helpviewer_keywords:
- C4794
ms.assetid: badc9c36-fa1a-4fec-929b-7bfda7a7b79f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0c6e6b8aedacc71291afc2a34a6a11d7b19a126b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46027395"
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