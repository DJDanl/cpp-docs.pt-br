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
ms.openlocfilehash: 0ae9f772a68735555748e6edbeb6196f1a73d2c9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33164512"
---
# <a name="typeof-goes-to-ttypeid"></a>typeof vai até T::typeid
O `typeof` operador usado das extensões gerenciadas para C++ tem sido suplantado pelo `typeid` palavra-chave no Visual C++.  
  
 Em extensões gerenciadas, o `__typeof()` operador retorna associado `Type*` objeto passadas o nome de um tipo gerenciado. Por exemplo:  
  
```  
// Creates and initializes a new Array instance.  
Array* myIntArray =   
   Array::CreateInstance( __typeof(Int32), 5 );  
```  
  
 Na sintaxe de novo, `__typeof` foi substituída por uma forma adicional de `typeid` que retorna um `Type^` quando um tipo gerenciado é especificado.  
  
```  
// Creates and initializes a new Array instance.  
Array^ myIntArray =   
   Array::CreateInstance( Int32::typeid, 5 );  
```  
  
## <a name="see-also"></a>Consulte também  
 [Alterações gerais em linguagens (C + + CLI)](../dotnet/general-language-changes-cpp-cli.md)   
 [TypeId](../windows/typeid-cpp-component-extensions.md)