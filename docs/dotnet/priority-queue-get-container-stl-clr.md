---
title: priority_queue::get_container (STL/CLR) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: cliext::priority_queue::get_container
dev_langs: C++
helpviewer_keywords: get_container member [STL/CLR]
ms.assetid: bd3cc63b-776f-495c-bf81-a9e8ba189a56
caps.latest.revision: "15"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 3832a43b3286a63553a16df0c127f2f991e5d1f7
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="priorityqueuegetcontainer-stlclr"></a>priority_queue::get_container (STL/CLR)
Acessa o contêiner subjacente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
container_type get_container();  
```  
  
## <a name="remarks"></a>Comentários  
 A função de membro retorna o contêiner subjacente. Você pode usá-lo para ignorar as restrições impostas pelo wrapper do contêiner.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_priority_queue_get_container.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::priority_queue<wchar_t> Mypriority_queue;   
int main()   
    {   
    Mypriority_queue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
c a b  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/fila >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [priority_queue (STL/CLR)](../dotnet/priority-queue-stl-clr.md)   
 [priority_queue::container_type (STL/CLR)](../dotnet/priority-queue-container-type-stl-clr.md)