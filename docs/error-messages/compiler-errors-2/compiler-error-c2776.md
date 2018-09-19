---
title: Erro do compilador C2776 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2776
dev_langs:
- C++
helpviewer_keywords:
- C2776
ms.assetid: 9d80addc-62c7-40fc-a2cc-60303abb87df
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 705f6930b18483c1a449fec4b50163cc658249d7
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46029228"
---
# <a name="compiler-error-c2776"></a>Erro do compilador C2776

somente um método 'get' pode ser especificado por propriedade

Você pode especificar apenas uma `get` funcionar a [propriedade](../../cpp/property-cpp.md) atributo estendido. Esse erro ocorre quando várias `get` funções são especificadas.

O exemplo a seguir gera C2776:

```
// C2776.cpp
struct A {
   __declspec(property(get=GetProp,get=GetPropToo))
   // try the following line instead
   // __declspec(property(get=GetProp))
      int prop;   // C2776
   int GetProp(void);
   int GetPropToo(void);
};
```