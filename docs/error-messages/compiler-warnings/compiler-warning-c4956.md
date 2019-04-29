---
title: Aviso do compilador C4956
ms.date: 11/04/2016
f1_keywords:
- C4956
helpviewer_keywords:
- C4956
ms.assetid: 9154f2d1-d49f-4e07-90d2-0e9bc028011a
ms.openlocfilehash: c15de8b22f56a2555cc763a45153139b1df01a31
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62280835"
---
# <a name="compiler-warning-c4956"></a>Aviso do compilador C4956

> '*tipo*': esse tipo não é verificável

## <a name="remarks"></a>Comentários

Esse aviso é gerado quando [/CLR: safe](../../build/reference/clr-common-language-runtime-compilation.md) for especificado e seu código contém um tipo que não é verificável. O **/CLR: safe** opção do compilador é preterida no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Para obter mais informações, consulte [código puro e verificável (C++/CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).

Esse aviso é emitido como um erro e pode ser desabilitado com o [aviso](../../preprocessor/warning.md) pragma ou o [/wd](../../build/reference/compiler-option-warning-level.md) opção de compilador.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4956:

```cpp
// C4956.cpp
// compile with: /clr:safe
int* p;   // C4956
```