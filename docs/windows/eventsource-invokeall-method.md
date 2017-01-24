---
title: "M&#233;todo EventSource::InvokeAll | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "event/Microsoft::WRL::EventSource::InvokeAll"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método InvokeAll"
ms.assetid: 1506618f-0421-4428-a4d0-4ea2b10a3bf6
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo EventSource::InvokeAll
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Chama cada manipulador de eventos associado atual [EventSource](../windows/eventsource-class.md) usando os argumentos e os tipos de argumento especificado do objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
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
  
#### <a name="parameters"></a>Parâmetros  
 `T0`  
 O tipo de argumento do manipulador de evento inicial.  
  
 `T1`  
 O tipo do primeiro argumento do manipulador de eventos.  
  
 `T2`  
 O tipo do segundo argumento do manipulador de eventos.  
  
 `T3`  
 O tipo do terceiro argumento de manipulador de eventos.  
  
 `T4`  
 O tipo do quarto argumento do manipulador de eventos.  
  
 `T5`  
 O tipo do quinto argumento de manipulador de eventos.  
  
 `T6`  
 O tipo de argumento do manipulador de evento sexto.  
  
 `T7`  
 O tipo de argumento do manipulador de evento sétimo.  
  
 `T8`  
 O tipo de argumento do manipulador de evento oitavo.  
  
 `T9`  
 O tipo de argumento do manipulador de evento nono.  
  
 `arg0`  
 O argumento do manipulador de evento inicial.  
  
 `arg1`  
 O primeiro argumento de manipulador de eventos.  
  
 `arg2`  
 O segundo argumento de manipulador de eventos.  
  
 `arg3`  
 O terceiro argumento de manipulador de eventos.  
  
 `arg4`  
 O quarto argumento de manipulador de eventos.  
  
 `arg5`  
 O quinto argumento de manipulador de eventos.  
  
 `arg6`  
 Sexto argumento do manipulador de eventos.  
  
 `arg7`  
 Sétimo argumento do manipulador de eventos.  
  
 `arg8`  
 O argumento do manipulador de evento oitavo.  
  
 `arg9`  
 O nono argumento de manipulador de eventos.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft:: wrl
 
 ## <a name="see-also"></a>Consulte também
 [Classe EventSource](../windows/eventsource-class.md)