---
title: Aviso do compilador C4936
ms.date: 11/04/2016
f1_keywords:
- C4936
helpviewer_keywords:
- C4936
ms.assetid: 6676de35-bf1b-4d0b-a70f-b5734130336c
ms.openlocfilehash: 9b1c3d1de662451432fe4fa0f058c503dc1f7b39
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220113"
---
# <a name="compiler-warning-c4936"></a>Aviso do compilador C4936

> Este __declspec só tem suporte quando compilado com/CLR ou/CLR: Pure

## <a name="remarks"></a>Comentários

A opção de compilador **/CLR: Pure** foi preterida no visual Studio 2015 e não tem suporte no visual Studio 2017.

Um **`__declspec`** modificador foi usado, mas esse **`__declspec`** modificador só é válido quando compilado com uma das opções [/CLR](../../build/reference/clr-common-language-runtime-compilation.md) .

Para obter mais informações, consulte [AppDomain](../../cpp/appdomain.md) e [process](../../cpp/process.md).

C4936 é sempre emitido como um erro.  Você pode desabilitar C4936 com o pragma de [aviso](../../preprocessor/warning.md) .

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4936:

```cpp
// C4936.cpp
// compile with: /c
// #pragma warning (disable : 4936)
__declspec(process) int i;   // C4936
__declspec(appdomain) int j;   // C4936
```
