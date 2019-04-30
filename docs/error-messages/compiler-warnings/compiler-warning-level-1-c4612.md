---
title: Compilador aviso (nível 1) C4612
ms.date: 08/27/2018
f1_keywords:
- C4612
helpviewer_keywords:
- C4612
ms.assetid: 21ac02b2-51cd-4aff-9b70-d543511d5962
ms.openlocfilehash: ed5458fc52c1c9c9f12187095e4658204613d1a1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62406360"
---
# <a name="compiler-warning-level-1-c4612"></a>Compilador aviso (nível 1) C4612

> Erro ao incluir o nome de arquivo

## <a name="remarks"></a>Comentários

Este aviso ocorre com **#pragma include_alias** quando um nome de arquivo está incorreta ou ausente.

Os argumentos para o **#pragma include_alias** instrução pode usar o formulário de cotação ("*filename*") ou a forma de colchete (\<*filename*>), mas ambas devem Use o mesmo formulário.

## <a name="example"></a>Exemplo

```cpp
// C4612.cpp
// compile with: /W1 /LD
#pragma include_alias("StandardIO", <stdio.h>) // C4612
```