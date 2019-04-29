---
title: Erro do compilador C3862
ms.date: 11/04/2016
f1_keywords:
- C3862
helpviewer_keywords:
- C3862
ms.assetid: ba547366-4189-4077-8c00-ab45e08a9533
ms.openlocfilehash: 2ba130862b1debbe2991ca7cbcae50192f900cd8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62302308"
---
# <a name="compiler-error-c3862"></a>Erro do compilador C3862

> '*função*': não é possível compilar uma função não gerenciada com /clr: pure ou /CLR: safe

## <a name="remarks"></a>Comentários

O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Uma compilação com **/clr: pure** ou **/CLR: safe** produzirá uma imagem única do MSIL, uma imagem sem nenhum código (não gerenciado) nativo.  Portanto, é possível usar o `unmanaged` pragma em um **/clr: pure** ou **/CLR: safe** compilação.

Para obter mais informações, consulte [/clr (compilação de tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md) e [gerenciado, não gerenciado](../../preprocessor/managed-unmanaged.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3862:

```cpp
// C3862.cpp
// compile with: /clr:pure /c
#pragma unmanaged
void f() {}   // C3862
```