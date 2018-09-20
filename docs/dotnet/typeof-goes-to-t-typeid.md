---
title: 'TypeOf vai até t:: TypeId | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- typeid operator
- __typeof keyword
- typeid keyword [C++]
ms.assetid: 6a0d35a7-7a1a-4070-b187-cff37cfdc205
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 4433061fceef455685b6588c81c8c2e434253433
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46374657"
---
# <a name="typeof-goes-to-ttypeid"></a>typeof vai até T::typeid

O `typeof` operador usado nas extensões gerenciadas para C++ tem sido suplantado pelo `typeid` palavra-chave no Visual C++.

Nas extensões gerenciadas, o `__typeof()` operador retorna associado `Type*` objeto quando passou o nome de um tipo gerenciado. Por exemplo:

```
// Creates and initializes a new Array instance.
Array* myIntArray =
   Array::CreateInstance( __typeof(Int32), 5 );
```

Na nova sintaxe `__typeof` foi substituído por uma forma adicional de `typeid` que retorna um `Type^` quando um tipo gerenciado é especificado.

```
// Creates and initializes a new Array instance.
Array^ myIntArray =
   Array::CreateInstance( Int32::typeid, 5 );
```

## <a name="see-also"></a>Consulte também

[Alterações gerais na linguagem (C++/CLI)](../dotnet/general-language-changes-cpp-cli.md)<br/>
[TypeId](../windows/typeid-cpp-component-extensions.md)