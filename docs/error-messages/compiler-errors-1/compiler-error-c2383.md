---
title: Erro do compilador C2383 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2383
dev_langs:
- C++
helpviewer_keywords:
- C2383
ms.assetid: 6696221d-879c-477a-a0f3-a6edc15fd3d7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9c529c22636f112291fa53b852899cad78dac589
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46113221"
---
# <a name="compiler-error-c2383"></a>Erro do compilador C2383

'*símbolo*': argumentos padrão não são permitidos neste símbolo

O compilador do C++ não permite argumentos padrão em ponteiros para funções.

Esse código foi aceita pelo compilador do Visual C++ em versões anteriores do Visual Studio 2005, mas agora retorna um erro. Para o código que funciona em todas as versões do Visual C++, não atribua um valor padrão para um argumento de ponteiro para função.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2383 e mostra uma solução possível:

```cpp
// C2383.cpp
// compile with: /c
void (*pf)(int = 0);   // C2383
void (*pf)(int);   // OK
```