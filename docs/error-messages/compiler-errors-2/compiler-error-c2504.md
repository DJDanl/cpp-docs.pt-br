---
title: C2504 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2504
dev_langs:
- C++
helpviewer_keywords:
- C2504
ms.assetid: c9e002a6-a4ee-4ba7-970e-edf4adb83692
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bac0f8f28955af172590535568289182c3489d6d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2504"></a>C2504 de erro do compilador
'class': classe base indefinida  
  
 A classe base é declarada mas nunca foi definida.  Possíveis causas:  
  
1.  Faltando o arquivo de inclusão.  
  
2.  Classe base externo não declarado com [extern](../../cpp/using-extern-to-specify-linkage.md).  
  
 O exemplo a seguir gera C2504:  
  
```  
// C2504.cpp  
// compile with: /c  
class A;  
class B : public A {};   // C2504  
```  
  
 OKEY  
  
```  
class C{};  
class D : public C {};  
```