---
title: Compilador aviso (nível 3) C4161 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4161
dev_langs:
- C++
helpviewer_keywords:
- C4161
ms.assetid: 03d3be61-83f1-4009-8310-8758ab67055f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1c81072c5121bea4a323c3eb16cc58c6f28c06f7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-3-c4161"></a>Compilador C4161 de aviso (nível 3)
\#pragma pragma(pop...): mais ativações do que envios  
  
 Porque seu código-fonte contém um mais pop que envios para pragma ***pragma***, a pilha não pode se comportar conforme o esperado. Para evitar o aviso, certifique-se de que o número de ativações não exceder o número de envios por push.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4161:  
  
```  
// C4161.cpp  
// compile with: /W3 /LD  
#pragma pack(push, id)  
#pragma pack(pop, id)  
#pragma pack(pop, id)   // C4161, an extra pop  
  
#pragma bss_seg(".my_data1")  
int j;  
  
#pragma bss_seg(push, stack1, ".my_data2")     
int l;  
  
#pragma bss_seg(pop, stack1)  
int m;  
  
#pragma bss_seg(pop, stack1)   // C4161  
```