---
title: C2505 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2505
dev_langs:
- C++
helpviewer_keywords:
- C2505
ms.assetid: b19f5c53-399d-425e-90db-fe3ca9b40858
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: e703a5f36a5edd5febbcfaf4b75394bbbb28ee4d
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2505"></a>C2505 de erro do compilador
'symbol': '__declspec(modifer)' só pode ser aplicado a declarações ou definições de objetos globais ou membros de dados estáticos  
  
 Um `__declspec` modificador que foi projetado para ser usada somente no escopo global foi usada em uma função.  
  
 Para obter mais informações, consulte [appdomain](../../cpp/appdomain.md) e [processo](../../cpp/process.md).  
  
 O exemplo a seguir gera C2505:  
  
```  
// C2505.cpp  
// compile with: /clr  
  
// OK  
__declspec(process) int ii;  
__declspec(appdomain) int jj;  
  
int main() {  
   __declspec(process) int i;   // C2505  
   __declspec(appdomain) int j;   // C2505  
}  
```
