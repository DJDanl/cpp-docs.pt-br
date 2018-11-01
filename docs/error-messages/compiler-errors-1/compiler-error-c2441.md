---
title: Erro do compilador C2441
ms.date: 11/04/2016
f1_keywords:
- C2441
helpviewer_keywords:
- C2441
ms.assetid: ffbd6573-777a-48dd-892f-5cf4a758dcab
ms.openlocfilehash: 7fcf333f62253eb676c0f0ada1c927ab962ae1ca
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50551245"
---
# <a name="compiler-error-c2441"></a>Erro do compilador C2441

> '*variável*': um símbolo declarado com __declspec(process) deve ser const em /clr: pure modo

## <a name="remarks"></a>Comentários

O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Por padrão, variáveis são definidas por domínio de aplicativo sob **/clr: pure**. Marcado como uma variável `__declspec(process)` sob **/clr: pure** é propensa a erros, se modificado em um domínio de aplicativo e lidos em outra diferente.

Portanto, o compilador impõe por processo de ser variáveis `const` sob **/clr: pure**, tomada-los de leitura somente em todos os domínios de aplicativo.

Para obter mais informações, consulte [processo](../../cpp/process.md) e [/clr (compilação de tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2441.

```cpp
// C2441.cpp
// compile with: /clr:pure /c
__declspec(process) int i;   // C2441
__declspec(process) const int j = 0;   // OK
```