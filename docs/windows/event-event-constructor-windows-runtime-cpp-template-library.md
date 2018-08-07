---
title: 'Construtor Event:: Event (biblioteca de modelos C++ do Windows Runtime) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Event::Event
dev_langs:
- C++
ms.assetid: 21495297-9612-4095-9256-16e168cc0021
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: de0f68ee3e27f2ac3a7f87e64489a05a16dcdc91
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39571406"
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
 *h*  
 Manipular um evento. Por padrão, *h* é inicializado como **nullptr**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe Event (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](../windows/event-class-windows-runtime-cpp-template-library.md)