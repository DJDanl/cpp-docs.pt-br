---
title: Erro do compilador C2435
ms.date: 11/04/2016
f1_keywords:
- C2435
helpviewer_keywords:
- C2435
ms.assetid: be6aa8f8-579b-42ea-bdd8-2d01393646ad
ms.openlocfilehash: 7ef22711884dabb83efa8c7ebfdb7648316c12ee
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80205407"
---
# <a name="compiler-error-c2435"></a>Erro do compilador C2435

> '*var*': a inicialização dinâmica requer CRT gerenciado, não é possível compilar com/CLR: safe

## <a name="remarks"></a>Comentários

As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

A inicialização da variável de domínio global por aplicativo requer que o CRT compilado com `/clr:pure`, que não produz uma imagem verificável.

Para obter mais informações, consulte [AppDomain](../../cpp/appdomain.md) e [process](../../cpp/process.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2435:

```cpp
// C2435.cpp
// compile with: /clr:safe /c
int globalvar = 0;   // C2435

__declspec(process)
int globalvar2 = 0;
```
