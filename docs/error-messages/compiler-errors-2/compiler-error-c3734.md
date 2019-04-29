---
title: Erro do compilador C3734
ms.date: 11/04/2016
f1_keywords:
- C3734
helpviewer_keywords:
- C3734
ms.assetid: 4e2afdcc-7da9-45a1-9c96-85f25e2986e8
ms.openlocfilehash: 78b3d1a57d358eb11ba2f01ec184c5487a578228
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62327919"
---
# <a name="compiler-error-c3734"></a>Erro do compilador C3734

'class': um gerenciado ou classe WinRT não pode ser uma coclass

O [coclass](../../windows/coclass.md) atributo não pode ser usado com gerenciado ou classes do WinRT.

O exemplo a seguir gera C3734 e mostra como corrigi-lo:

```
// C3734.cpp
// compile with: /clr /c
[module(name="x")];

[coclass]
ref class CMyClass {   // C3734 remove the ref keyword to resolve
};
```
