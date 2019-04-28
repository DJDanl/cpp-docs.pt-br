---
title: Erro do compilador C2732
ms.date: 11/04/2016
f1_keywords:
- C2732
helpviewer_keywords:
- C2732
ms.assetid: 01b7ad2c-93cf-456f-a4c0-c5f2fdc7c07c
ms.openlocfilehash: 820a620b7e4414123c56433f84536393834f6fd6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62208396"
---
# <a name="compiler-error-c2732"></a>Erro do compilador C2732

especificação de vínculo contradiz especificação anterior para 'function'

A função já foi declarada com um especificador de vinculação diferentes.

Esse erro pode ser causado pela inclusão dos arquivos com especificadores de vínculo diferente.

Para corrigir esse erro, altere o `extern` instruções para que os vínculos concordam. Em particular, não encapsule `#include` diretivas no `extern "C"` blocos.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2732:

```
// C2732.cpp
extern void func( void );   // implicit C++ linkage
extern "C" void func( void );   // C2732
```