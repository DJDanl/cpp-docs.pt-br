---
title: Aviso do compilador (nível 1) C4612
ms.date: 08/27/2018
f1_keywords:
- C4612
helpviewer_keywords:
- C4612
ms.assetid: 21ac02b2-51cd-4aff-9b70-d543511d5962
ms.openlocfilehash: f9478caef9eaba9c72dc282179100daf2d94c6d5
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80185978"
---
# <a name="compiler-warning-level-1-c4612"></a>Aviso do compilador (nível 1) C4612

> erro no nome de arquivo de inclusão

## <a name="remarks"></a>Comentários

Esse aviso ocorre com **#pragma include_alias** quando um nome de arquivo está incorreto ou ausente.

Os argumentos para a instrução **#pragma include_alias** podem usar o formulário de aspas ("*filename*") ou o formato de ângulo (\<*nome de arquivo*>), mas ambos devem usar o mesmo formulário.

## <a name="example"></a>Exemplo

```cpp
// C4612.cpp
// compile with: /W1 /LD
#pragma include_alias("StandardIO", <stdio.h>) // C4612
```
