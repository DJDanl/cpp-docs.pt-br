---
title: 'Método EventSource:: Invokeall | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::EventSource::InvokeAll
dev_langs:
- C++
helpviewer_keywords:
- InvokeAll method
ms.assetid: 1506618f-0421-4428-a4d0-4ea2b10a3bf6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9ea378f75f100bce02cd486139fb0aac5ea5a5ff
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39648627"
---
# <a name="eventsourceinvokeall-method"></a>Método EventSource::InvokeAll
Chama cada manipulador de eventos associado ao atual [EventSource](../windows/eventsource-class.md) usando os argumentos e tipos de argumento especificados do objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
void InvokeAll();  
template <  
   typename T0  
>  
void InvokeAll(  
   T0arg0  
);  
template <  
   typename T0,  
   typename T1  
>  
void InvokeAll(  
   T0arg0,  
   T1arg1  
);  
template <  
   typename T0,  
   typename T1,  
   typename T2  
>  
void InvokeAll(  
   T0arg0,  
   T1arg1,  
   T2arg2  
);  
template <  
   typename T0,  
   typename T1,  
   typename T2,  
   typename T3  
>  
void InvokeAll(  
   T0arg0,  
   T1arg1,  
   T2arg2,  
   T3arg3  
);  
template <  
   typename T0,  
   typename T1,  
   typename T2,  
   typename T3,  
   typename T4  
>  
void InvokeAll(  
   T0arg0,  
   T1arg1,  
   T2arg2,  
   T3arg3,  
   T4arg4  
);  
template <  
   typename T0,  
   typename T1,  
   typename T2,  
   typename T3,  
   typename T4,  
   typename T5  
>  
void InvokeAll(  
   T0arg0,  
   T1arg1,  
   T2arg2,  
   T3arg3,  
   T4arg4,  
   T5arg5  
);  
template <  
   typename T0,  
   typename T1,  
   typename T2,  
   typename T3,  
   typename T4,  
   typename T5,  
   typename T6  
>  
void InvokeAll(  
   T0arg0,  
   T1arg1,  
   T2arg2,  
   T3arg3,  
   T4arg4,  
   T5arg5,  
   T6arg6  
);  
template <  
   typename T0,  
   typename T1,  
   typename T2,  
   typename T3,  
   typename T4,  
   typename T5,  
   typename T6,  
   typename T7  
>  
void InvokeAll(  
   T0arg0,  
   T1arg1,  
   T2arg2,  
   T3arg3,  
   T4arg4,  
   T5arg5,  
   T6arg6,  
   T7arg7  
);  
template <  
   typename T0,  
   typename T1,  
   typename T2,  
   typename T3,  
   typename T4,  
   typename T5,  
   typename T6,  
   typename T7,  
   typename T8  
>  
void InvokeAll(  
   T0arg0,  
   T1arg1,  
   T2arg2,  
   T3arg3,  
   T4arg4,  
   T5arg5,  
   T6arg6,  
   T7arg7,  
   T8arg8  
);  
template <  
   typename T0,  
   typename T1,  
   typename T2,  
   typename T3,  
   typename T4,  
   typename T5,  
   typename T6,  
   typename T7,  
   typename T8,  
   typename T9  
>  
void InvokeAll(  
   T0arg0,  
   T1arg1,  
   T2arg2,  
   T3arg3,  
   T4arg4,  
   T5arg5,  
   T6arg6,  
   T7arg7,  
   T8arg8,  
   T9arg9  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *T0*  
 O tipo de argumento do manipulador de evento inicial.  
  
 *T1*  
 O tipo do primeiro argumento do manipulador de eventos.  
  
 *T2*  
 O tipo do segundo argumento do manipulador de eventos.  
  
 *T3*  
 O tipo do terceiro argumento de manipulador de eventos.  
  
 *T4*  
 O tipo do quarto argumento de manipulador de eventos.  
  
 *T5*  
 O tipo do quinto argumento do manipulador de eventos.  
  
 *T6*  
 O tipo do sexto argumento do manipulador de eventos.  
  
 *T7*  
 O tipo do sétimo argumento do manipulador de eventos.  
  
 *T8*  
 O tipo de argumento do manipulador de evento oitava.  
  
 *T9*  
 O tipo do nono argumento do manipulador de eventos.  
  
 *arg0*  
 O argumento do manipulador de evento inicial.  
  
 *arg1*  
 O primeiro argumento de manipulador de eventos.  
  
 *Arg2*  
 O segundo argumento de manipulador de eventos.  
  
 *arg3*  
 O terceiro argumento de manipulador de eventos.  
  
 *Arg4*  
 O quarto argumento de manipulador de eventos.  
  
 *arg5*  
 O quinto argumento de manipulador de eventos.  
  
 *arg6*  
 O sexto argumento de manipulador de eventos.  
  
 *arg7*  
 O sétimo argumento de manipulador de eventos.  
  
 *arg8*  
 O argumento de manipulador de eventos do oitavo.  
  
 *arg9*  
 O nono argumento de manipulador de eventos.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Event. h  
  
 **Namespace:** Microsoft::WRL
 
 ## <a name="see-also"></a>Consulte também
 [Classe EventSource](../windows/eventsource-class.md)