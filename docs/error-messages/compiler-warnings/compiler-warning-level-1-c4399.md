---
title: Compilador aviso (nível 1) C4399
ms.date: 11/04/2016
f1_keywords:
- C4399
helpviewer_keywords:
- C4399
ms.assetid: f58d9ba7-71a0-4c3b-b26f-f946dda8af30
ms.openlocfilehash: 56fe0f314142d873fc02136bc2c3fe65e71f4dda
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50544060"
---
# <a name="compiler-warning-level-1-c4399"></a>Compilador aviso (nível 1) C4399

> '*símbolo*': símbolo per-process não deve ser marcado com __declspec(dllimport) quando compilado com /clr: pure

## <a name="remarks"></a>Comentários

O **/clr: pure** opção do compilador é preterida no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Dados de uma imagem nativa ou uma imagem com nativo e construções CLR não podem ser importados para uma imagem pura. Para resolver este aviso, compile com **/clr** (não **/clr: pure**) ou excluir `__declspec(dllimport)`.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4399.

```cpp
// C4399.cpp
// compile with: /clr:pure /doc /W1 /c
__declspec(dllimport) __declspec(process) extern const int i;   // C4399
```