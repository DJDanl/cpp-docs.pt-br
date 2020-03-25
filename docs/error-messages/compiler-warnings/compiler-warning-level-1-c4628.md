---
title: Aviso do compilador (nível 1) C4628
ms.date: 11/04/2016
f1_keywords:
- C4628
helpviewer_keywords:
- C4628
ms.assetid: 20fdc6f8-5f6a-40cc-aff8-c7ccf3d8ec26
ms.openlocfilehash: affb2b5231d3745d4826e92657e355ec99570e7e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80199661"
---
# <a name="compiler-warning-level-1-c4628"></a>Aviso do compilador (nível 1) C4628

dígrafos não suportados com -Ze. A sequência de caracteres 'digraph' não é interpretada como token alternativo para 'char'

Não há suporte para gráficos em [/ze](../../build/reference/za-ze-disable-language-extensions.md). Esse aviso será seguido por um erro.

Esse aviso está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

O exemplo a seguir gera C4628:

```cpp
// C4628.cpp
// compile with: /WX
#pragma warning(default : 4628)
int main()
<%   // C4628 <% digraph for {
}
```
