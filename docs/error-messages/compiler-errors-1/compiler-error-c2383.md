---
title: Erro do compilador C2383
ms.date: 11/04/2016
f1_keywords:
- C2383
helpviewer_keywords:
- C2383
ms.assetid: 6696221d-879c-477a-a0f3-a6edc15fd3d7
ms.openlocfilehash: e9c1774fe7cd4a6883aa79f384cc64521a57ed17
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65448012"
---
# <a name="compiler-error-c2383"></a>Erro do compilador C2383

'*símbolo*': argumentos padrão não são permitidos neste símbolo

O compilador do C++ não permite argumentos padrão em ponteiros para funções.

Esse código foi aceita pelo Microsoft C++ compilador em versões anteriores do Visual Studio 2005, mas agora retorna um erro. Para o código que funciona em todas as versões do Visual C++, não atribua um valor padrão para um argumento de ponteiro para função.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2383 e mostra uma solução possível:

```cpp
// C2383.cpp
// compile with: /c
void (*pf)(int = 0);   // C2383
void (*pf)(int);   // OK
```