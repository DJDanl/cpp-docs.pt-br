---
title: Classe bad_function_call
ms.date: 11/04/2016
f1_keywords:
- functional/std::bad_function_call
helpviewer_keywords:
- bad_function_call class
ms.assetid: b70a0268-43ff-4f3b-a283-faf1cb172d4c
ms.openlocfilehash: 6d0a3f5f5b6ac48d23b937b04b4521799ba31502
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62376387"
---
# <a name="badfunctioncall-class"></a>Classe bad_function_call

Relata uma chamada de função inválida.

## <a name="syntax"></a>Sintaxe

```cpp
class bad_function_call : public std::exception {};
```

## <a name="remarks"></a>Comentários

A classe descreve uma exceção gerada para indicar uma chamada para `operator()` em uma [Classe function](../standard-library/function-class.md)
