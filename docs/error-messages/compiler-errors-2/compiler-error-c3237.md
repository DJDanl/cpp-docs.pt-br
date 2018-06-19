---
title: C3237 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3237
dev_langs:
- C++
helpviewer_keywords:
- C3237
ms.assetid: 690970c8-e13b-4ff3-96e3-5fd93c4d356b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f9e43fc9ecf79443cfbf8147ff5b3c227eda9404
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33251658"
---
# <a name="compiler-error-c3237"></a>C3237 de erro do compilador
'generic_class': uma classe genérica não pode ser um atributo personalizado  
  
 Classes genéricas não podem ser atributos definidos pelo usuário.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3237.  
  
```  
// C3237.cpp  
// compile with: /clr /c  
// C3237 expected  
using namespace System;  
  
generic <class T>  
// Delete the following line to resolve.  
[attribute(AttributeTargets::All, AllowMultiple=true)]  
public ref class GR {};  
```