---
title: Aviso do compilador C4956
ms.date: 11/04/2016
f1_keywords:
- C4956
helpviewer_keywords:
- C4956
ms.assetid: 9154f2d1-d49f-4e07-90d2-0e9bc028011a
ms.openlocfilehash: 474bdfa6eb670f39a2876b0c1490e7254cf216e7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80164892"
---
# <a name="compiler-warning-c4956"></a>Aviso do compilador C4956

> '*Type*': este tipo não é verificável

## <a name="remarks"></a>Comentários

Esse aviso é gerado quando [/CLR: safe](../../build/reference/clr-common-language-runtime-compilation.md) é especificado e seu código contém um tipo que não é verificável. A opção de compilador **/CLR: safe** foi preterida no visual Studio 2015 e não tem suporte no visual Studio 2017.

Para obter mais informações, consulte [puro e verificável CodeC++(/CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).

Esse aviso é emitido como um erro e pode ser desabilitado com o pragma de [aviso](../../preprocessor/warning.md) ou a opção de compilador [/WD](../../build/reference/compiler-option-warning-level.md) .

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4956:

```cpp
// C4956.cpp
// compile with: /clr:safe
int* p;   // C4956
```
