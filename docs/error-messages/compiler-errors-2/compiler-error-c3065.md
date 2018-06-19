---
title: C3065 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3065
dev_langs:
- C++
helpviewer_keywords:
- C3065
ms.assetid: e7a0bc69-1c68-459e-a7c4-93c65609ff7c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b7a6bb966fd973a9ede675e98761e8649ca20c27
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33246951"
---
# <a name="compiler-error-c3065"></a>C3065 de erro do compilador
declaração de propriedade em escopo diferente de classe não é permitida  
  
 O [propriedade](../../cpp/property-cpp.md) modificador declspec foi usado fora de uma classe.  Uma propriedade só pode ser declarada dentro de uma classe.  
  
 O exemplo a seguir gera C3065:  
  
```  
// C3065.cpp  
// compile with: /c  
__declspec(property(get=get_i)) int i;   // C3065  
  
class x {  
public:  
   __declspec(property(get=get_i)) int i;   // OK  
};  
```