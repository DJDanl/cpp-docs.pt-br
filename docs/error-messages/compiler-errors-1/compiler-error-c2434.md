---
title: Erro do compilador C2434
ms.date: 11/04/2016
f1_keywords:
- C2434
helpviewer_keywords:
- C2434
ms.assetid: 01329e26-7c74-4219-b74f-69e3a40c9738
ms.openlocfilehash: c73a8d4fcde945ddf2495cc2d0d7dc47216f2db3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62166328"
---
# <a name="compiler-error-c2434"></a>Erro do compilador C2434

> '*símbolo*': um símbolo declarado com __declspec(process) não pode ser inicializado dinamicamente em /clr: pure modo

## <a name="remarks"></a>Comentários

O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Não é possível inicializar dinamicamente uma variável per-process sob **/clr: pure**. Para obter mais informações, consulte [/clr (compilação de tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md) e [processo](../../cpp/process.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2434. Para corrigir esse problema, use constantes para inicializar `process` variáveis.

```cpp
// C2434.cpp
// compile with: /clr:pure /c
int f() { return 0; }
__declspec(process) int i = f();   // C2434
__declspec(process) int i2 = 0;   // OK
```