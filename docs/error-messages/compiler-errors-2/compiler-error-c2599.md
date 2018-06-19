---
title: C2599 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2599
dev_langs:
- C++
helpviewer_keywords:
- C2599
ms.assetid: 88515f36-7589-47e2-862e-0de8b18d6668
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ce7741e878b8743346bf9a088d973d65c4d7c290
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33232933"
---
# <a name="compiler-error-c2599"></a>C2599 de erro do compilador
'enum': declaração de encaminhamento do tipo enum não é permitida  
  
 O compilador não oferece suporte à declaração de encaminhamento de uma enumeração gerenciada.  
  
 Declaração de encaminhamento de um tipo enum não é permitida em [/Za](../../build/reference/za-ze-disable-language-extensions.md).  
  
 O exemplo a seguir gera C2599:  
  
```  
// C2599.cpp  
// compile with: /clr /c  
enum class Status;   // C2599  
  
enum class Status2 { stop2, hold2, go2};   
  
ref struct MyStruct {  
   // Delete the following line to resolve.  
   Status m_status;  
  
   Status2 m_status2;   // OK  
};  
  
enum class Status { stop, hold, go };  
```