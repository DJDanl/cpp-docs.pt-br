---
title: Erro do compilador C2434
ms.date: 11/04/2016
f1_keywords:
- C2434
helpviewer_keywords:
- C2434
ms.assetid: 01329e26-7c74-4219-b74f-69e3a40c9738
ms.openlocfilehash: 869db3b49075fa477860e045e59306e22a381ca4
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80205451"
---
# <a name="compiler-error-c2434"></a>Erro do compilador C2434

> '*Symbol*': um símbolo declarado com __declspec (Process) não pode ser inicializado dinamicamente no modo/CLR: Pure

## <a name="remarks"></a>Comentários

As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Não é possível inicializar dinamicamente uma variável por processo em **/CLR: Pure**. Para obter mais informações, consulte [/CLR (compilação em tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md) e [processo](../../cpp/process.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2434. Para corrigir esse problema, use constantes para inicializar `process` variáveis.

```cpp
// C2434.cpp
// compile with: /clr:pure /c
int f() { return 0; }
__declspec(process) int i = f();   // C2434
__declspec(process) int i2 = 0;   // OK
```
