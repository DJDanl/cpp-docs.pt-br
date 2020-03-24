---
title: Aviso do compilador C4936
ms.date: 11/04/2016
f1_keywords:
- C4936
helpviewer_keywords:
- C4936
ms.assetid: 6676de35-bf1b-4d0b-a70f-b5734130336c
ms.openlocfilehash: c6d54cf8b6704eec2a9e6af890c5c80c67106995
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80164996"
---
# <a name="compiler-warning-c4936"></a>Aviso do compilador C4936

> Este __declspec só tem suporte quando compilado com/CLR ou/CLR: Pure

## <a name="remarks"></a>Comentários

A opção de compilador **/CLR: Pure** foi preterida no visual Studio 2015 e não tem suporte no visual Studio 2017.

Um modificador de `__declspec` foi usado, mas esse modificador de `__declspec` só é válido quando compilado com uma das opções de [/CLR](../../build/reference/clr-common-language-runtime-compilation.md) .

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
