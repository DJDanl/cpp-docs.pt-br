---
title: C3862 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3862
dev_langs:
- C++
helpviewer_keywords:
- C3862
ms.assetid: ba547366-4189-4077-8c00-ab45e08a9533
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5b21e457feb6d090e4abaf531293987eb3504457
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34704965"
---
# <a name="compiler-error-c3862"></a>C3862 de erro do compilador

> '*função*': não é possível compilar uma função não gerenciada com /clr: pure ou /CLR: safe

## <a name="remarks"></a>Comentários

O **/clr: pure** e **/CLR: safe** opções do compilador são substituídas no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

Uma compilação com **/clr: pure** ou **/CLR: safe** produzirá uma imagem do MSIL somente, uma imagem com nenhuma o código nativo (não gerenciado).  Portanto, você não pode usar o `unmanaged` pragma em um **/clr: pure** ou **/CLR: safe** compilação.

Para obter mais informações, consulte [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) e [gerenciado, não gerenciado](../../preprocessor/managed-unmanaged.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3862:

```cpp
// C3862.cpp
// compile with: /clr:pure /c
#pragma unmanaged
void f() {}   // C3862
```