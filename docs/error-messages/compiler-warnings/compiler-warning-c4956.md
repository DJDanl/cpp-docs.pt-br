---
title: C4956 de aviso do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4956
dev_langs:
- C++
helpviewer_keywords:
- C4956
ms.assetid: 9154f2d1-d49f-4e07-90d2-0e9bc028011a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: be92eb948e31a0a5367f92f5c2ed59baac2bd39b
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34703698"
---
# <a name="compiler-warning-c4956"></a>C4956 de aviso do compilador

> '*tipo*': este tipo não é verificável

## <a name="remarks"></a>Comentários

Esse aviso é gerado quando [/CLR: safe](../../build/reference/clr-common-language-runtime-compilation.md) for especificado e seu código contém um tipo que não é verificável. O **/CLR: safe** opção de compilador foi preterida no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

Para obter mais informações, consulte [puro e código verificável (C + + CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).

Esse aviso é emitido como um erro e pode ser desabilitado com o [aviso](../../preprocessor/warning.md) pragma ou [/wd](../../build/reference/compiler-option-warning-level.md) opção de compilador.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4956:

```cpp
// C4956.cpp
// compile with: /clr:safe
int* p;   // C4956
```