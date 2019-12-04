---
title: Erro do compilador C2732
ms.date: 11/04/2016
f1_keywords:
- C2732
helpviewer_keywords:
- C2732
ms.assetid: 01b7ad2c-93cf-456f-a4c0-c5f2fdc7c07c
ms.openlocfilehash: 61bac8c1b5c9e029cc5833f458669b490fed8c91
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74755792"
---
# <a name="compiler-error-c2732"></a>Erro do compilador C2732

a especificação de vinculação contradiz a especificação anterior para ' function '

A função já está declarada com um especificador de ligação diferente.

Esse erro pode ser causado por arquivos de inclusão com especificadores de ligação diferentes.

Para corrigir esse erro, altere as instruções de `extern` para que as ligações concordem. Em particular, não empacote `#include` diretivas em blocos de `extern "C"`.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2732:

```cpp
// C2732.cpp
extern void func( void );   // implicit C++ linkage
extern "C" void func( void );   // C2732
```
