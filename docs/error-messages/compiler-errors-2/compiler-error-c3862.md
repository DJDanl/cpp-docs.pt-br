---
title: Erro do compilador C3862
ms.date: 11/04/2016
f1_keywords:
- C3862
helpviewer_keywords:
- C3862
ms.assetid: ba547366-4189-4077-8c00-ab45e08a9533
ms.openlocfilehash: 0b9c1e1213949d7d700094caa6687232df881ce6
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80165477"
---
# <a name="compiler-error-c3862"></a>Erro do compilador C3862

> '*Function*': não é possível compilar uma função não gerenciada com/CLR: pure ou/CLR: safe

## <a name="remarks"></a>Comentários

As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Uma compilação com **/CLR: Pure** ou **/CLR: safe** produzirá uma imagem somente MSIL, uma imagem sem código nativo (não gerenciado).  Portanto, você não pode usar o `unmanaged` pragma em uma compilação **/CLR: Pure** ou **/CLR: safe** .

Para obter mais informações, consulte [/CLR (compilação do Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md) e [gerenciados, não](../../preprocessor/managed-unmanaged.md)gerenciados.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3862:

```cpp
// C3862.cpp
// compile with: /clr:pure /c
#pragma unmanaged
void f() {}   // C3862
```
