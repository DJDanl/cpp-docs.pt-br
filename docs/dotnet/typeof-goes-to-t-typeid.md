---
title: "TypeOf vai até t:: TypeId | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- typeid operator
- __typeof keyword
- typeid keyword [C++]
ms.assetid: 6a0d35a7-7a1a-4070-b187-cff37cfdc205
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 09ec4aef4c8bc68f8a808193b30d86b8519ba881
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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