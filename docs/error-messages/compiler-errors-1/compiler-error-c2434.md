---
title: C2434 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2434
dev_langs:
- C++
helpviewer_keywords:
- C2434
ms.assetid: 01329e26-7c74-4219-b74f-69e3a40c9738
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 45f9ccdef84713883c53dab0e7caf3b1519628de
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34704221"
---
# <a name="compiler-error-c2434"></a>C2434 de erro do compilador

> '*símbolo*': um símbolo declarado com __declspec(process) não pode ser inicializado dinamicamente em /clr: pure modo

## <a name="remarks"></a>Comentários

O **/clr: pure** e **/CLR: safe** opções do compilador são substituídas no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

Não é possível inicializar dinamicamente uma variável de cada processo em **/clr: pure**. Para obter mais informações, consulte [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) e [processo](../../cpp/process.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2434. Para corrigir esse problema, use as constantes para inicializar `process` variáveis.

```cpp
// C2434.cpp
// compile with: /clr:pure /c
int f() { return 0; }
__declspec(process) int i = f();   // C2434
__declspec(process) int i2 = 0;   // OK
```