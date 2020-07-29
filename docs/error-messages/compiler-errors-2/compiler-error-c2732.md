---
title: Erro do compilador C2732
ms.date: 11/04/2016
f1_keywords:
- C2732
helpviewer_keywords:
- C2732
ms.assetid: 01b7ad2c-93cf-456f-a4c0-c5f2fdc7c07c
ms.openlocfilehash: 78be424040c7315271d0880c6678584f698b5be8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218176"
---
# <a name="compiler-error-c2732"></a>Erro do compilador C2732

a especificação de vinculação contradiz a especificação anterior para ' function '

A função já está declarada com um especificador de ligação diferente.

Esse erro pode ser causado por arquivos de inclusão com especificadores de ligação diferentes.

Para corrigir esse erro, altere as **`extern`** instruções para que as ligações concordem. Em particular, não empacote as `#include` diretivas em `extern "C"` blocos.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2732:

```cpp
// C2732.cpp
extern void func( void );   // implicit C++ linkage
extern "C" void func( void );   // C2732
```
