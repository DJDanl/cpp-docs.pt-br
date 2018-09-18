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
ms.openlocfilehash: 8f91ec33db2d3a7b6772556233a3c99b501ede76
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46017333"
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

Para obter mais informações sobre C2555, consulte o artigo da Base de dados de Conhecimento Q240862.

O exemplo a seguir gera C2555:

```
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