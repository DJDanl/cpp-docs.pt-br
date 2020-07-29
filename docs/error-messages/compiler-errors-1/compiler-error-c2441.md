---
title: Erro do compilador C2441
ms.date: 11/04/2016
f1_keywords:
- C2441
helpviewer_keywords:
- C2441
ms.assetid: ffbd6573-777a-48dd-892f-5cf4a758dcab
ms.openlocfilehash: aa55392e9f58caa4292cf5f96ef97f65a53bf913
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87207947"
---
# <a name="compiler-error-c2441"></a>Erro do compilador C2441

> '*Variable*': um símbolo declarado com __declspec (Process) deve ser const no modo/CLR: Pure

## <a name="remarks"></a>Comentários

As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Por padrão, as variáveis são por domínio de aplicativo sob **/CLR: Pure**. Uma variável marcada `__declspec(process)` em **/CLR: Pure** é propenso a erros se modificada em um domínio de aplicativo e lida em outra.

Portanto, o compilador impõe que as variáveis por processo estejam **`const`** sob **/CLR: Pure**, tornando-as somente leitura em todos os domínios de aplicativo.

Para obter mais informações, consulte [process](../../cpp/process.md) e [/CLR (compilação Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2441.

```cpp
// C2441.cpp
// compile with: /clr:pure /c
__declspec(process) int i;   // C2441
__declspec(process) const int j = 0;   // OK
```
