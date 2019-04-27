---
title: Erro fatal C1103
ms.date: 11/04/2016
f1_keywords:
- C1103
helpviewer_keywords:
- C1103
ms.assetid: 9d276939-9c47-4235-9d20-76b8434f9731
ms.openlocfilehash: b6253af9fcf400321fb58d4d8a6d7aacf461b926
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62174192"
---
# <a name="fatal-error-c1103"></a>Erro fatal C1103

Erro fatal ao importar progid: 'message'

O compilador detectou um problema ao importar uma biblioteca de tipos.  Por exemplo, você não pode especificar uma biblioteca de tipos com progid e também especificar `no_registry`.

Para obter mais informações, consulte [#import diretiva](../../preprocessor/hash-import-directive-cpp.md).

O exemplo a seguir gerará C1103:

```
// C1103.cpp
#import "progid:a.b.id.1.5" no_registry auto_search   // C1103
```