---
title: 'Construtor Event:: Event (biblioteca de modelos C++ do Windows Runtime) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::Event::Event
dev_langs: C++
ms.assetid: 21495297-9612-4095-9256-16e168cc0021
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 63ca4f15dbbdd7f2423b34c0b7313a05976bcf77
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="eventevent-constructor-windows-runtime-c-template-library"></a>Construtor Event::Event (Biblioteca em Tempo de Execução C++ do Windows Runtime )
Inicializa uma nova instância da classe de evento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
explicit Event(  
   HANDLE h = HandleT::Traits::GetInvalidValue()  
);  
WRL_NOTHROW Event(  
   _Inout_ Event&& h  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `h`  
 Identificador para um evento. Por padrão, `h` é inicializado como `nullptr`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe Event (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](../windows/event-class-windows-runtime-cpp-template-library.md)