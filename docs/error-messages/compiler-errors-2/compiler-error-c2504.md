---
title: C2504 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2504
dev_langs:
- C++
helpviewer_keywords:
- C2504
ms.assetid: c9e002a6-a4ee-4ba7-970e-edf4adb83692
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 7a2692fc41ad328b4e44dafdd62e690ad5c36f49
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2504"></a>C2504 de erro do compilador
'class': indefinido de classe base  
  
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
