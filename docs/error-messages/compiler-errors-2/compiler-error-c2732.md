---
title: Erro do compilador C2732 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2732
dev_langs:
- C++
helpviewer_keywords:
- C2732
ms.assetid: 01b7ad2c-93cf-456f-a4c0-c5f2fdc7c07c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 040fd73bcb69ef032d5c6150bb157337f34a2088
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46079655"
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