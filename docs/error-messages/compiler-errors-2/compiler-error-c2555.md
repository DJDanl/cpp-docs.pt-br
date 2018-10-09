---
title: Erro do compilador C2555 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2555
dev_langs:
- C++
helpviewer_keywords:
- C2555
ms.assetid: 5e49ebb8-7c90-457a-aa12-7ca7ab6574b2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b0cd401aa1ee3611befb39d630f48f6aed36211c
ms.sourcegitcommit: d3c41b16bf05af2149090e996d8e71cd6cd55c7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/09/2018
ms.locfileid: "48889940"
---
# <a name="compiler-error-c2555"></a>Erro do compilador C2555

'class1::function1': função virtual de substituição retornar o tipo é diferente e não é covariante com 'class2::function2'

Uma função virtual e uma função de substituição derivada têm listas de parâmetro idênticos, mas tipos diferentes de retorno. Uma função de substituição em uma classe derivada não pode ser diferente de uma função virtual em uma classe base somente por seu tipo de retorno.

Para resolver esse erro, converta o valor de retorno após a função virtual tiver sido chamado.

Você também poderá ver esse erro se você compilar com /clr.   Por exemplo, o Visual C++ equivalente para a declaração c# a seguir:

```
Guid[] CheckSources(Guid sourceID, Guid[] carouselIDs);
```

is

```
Guid CheckSources(Guid sourceID, Guid carouselIDs[]) [];
```

O exemplo a seguir gera C2555:

```cpp
// C2555.cpp
// compile with: /c
struct X {
   virtual void func();
};
struct Y : X {
   char func();  // C2555
   void func2();   // OK
};
```