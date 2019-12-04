---
title: Erro fatal C1103
ms.date: 11/04/2016
f1_keywords:
- C1103
helpviewer_keywords:
- C1103
ms.assetid: 9d276939-9c47-4235-9d20-76b8434f9731
ms.openlocfilehash: f037d1acb281b5997e3486a542784abc4b4b7542
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74747378"
---
# <a name="fatal-error-c1103"></a>Erro fatal C1103

erro fatal ao importar ProgID: ' message '

O compilador detectou um problema ao importar uma biblioteca de tipos.  Por exemplo, você não pode especificar uma biblioteca de tipos com ProgID e também especificar `no_registry`.

Para obter mais informações, consulte [#import diretiva](../../preprocessor/hash-import-directive-cpp.md).

O exemplo a seguir gerará C1103:

```cpp
// C1103.cpp
#import "progid:a.b.id.1.5" no_registry auto_search   // C1103
```
