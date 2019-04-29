---
title: Aviso do compilador C4936
ms.date: 11/04/2016
f1_keywords:
- C4936
helpviewer_keywords:
- C4936
ms.assetid: 6676de35-bf1b-4d0b-a70f-b5734130336c
ms.openlocfilehash: bbb69cccbf93be6e97d13db5008780f57e63f9da
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62280841"
---
# <a name="compiler-warning-c4936"></a>Aviso do compilador C4936

> Este declspec é suportado apenas quando compilado com /clr ou /clr: pure

## <a name="remarks"></a>Comentários

O **/clr: pure** opção do compilador é preterida no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Um `__declspec` modificador foi usado, mas que `__declspec` modificador só é válido quando compilado com uma da [/clr](../../build/reference/clr-common-language-runtime-compilation.md) opções.

Para obter mais informações, consulte [appdomain](../../cpp/appdomain.md) e [processo](../../cpp/process.md).

C4936 sempre é emitido como um erro.  Você pode desabilitar C4936 com o [aviso](../../preprocessor/warning.md) pragma.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4936:

```cpp
// C4936.cpp
// compile with: /c
// #pragma warning (disable : 4936)
__declspec(process) int i;   // C4936
__declspec(appdomain) int j;   // C4936
```