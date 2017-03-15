---
title: Estrutura SYSTEMTIME&1; | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- SYSTEMTIME
dev_langs:
- C++
helpviewer_keywords:
- SYSTEMTIME structure
ms.assetid: 9aaef4d6-de79-4fa1-8158-86b245ef5bff
caps.latest.revision: 15
author: mikeblome
ms.author: mblome
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 298b2673a3eb05525683f8269fcd415d5be1c80a
ms.lasthandoff: 02/25/2017

---
# <a name="systemtime-structure1"></a>Estrutura SYSTEMTIME&1;
O `SYSTEMTIME` estrutura representa uma data e hora usando membros individuais para o mês, dia, ano, dia da semana, hora, minuto, segundo e milissegundo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct _SYSTEMTIME {  
    WORD wYear;  
    WORD wMonth;  
    WORD wDayOfWeek;  
    WORD wDay;  
    WORD wHour;  
    WORD wMinute;  
    WORD wSecond;  
    WORD wMilliseconds;  
} SYSTEMTIME;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *wYear*  
 O ano atual.  
  
 *Wano*  
 O mês atual; Janeiro é 1.  
  
 *Wmês*  
 O dia atual da semana; Domingo é 0, a segunda é 1 e assim por diante.  
  
 *Wdiadasemana*  
 O dia atual do mês.  
  
 *Wdia*  
 A hora atual.  
  
 *Wminuto*  
 O minuto atual.  
  
 *Wsegundo*  
 O segundo atual.  
  
 *Wsegundo*  
 O milissegundo atual.  
  
## <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_Utilities&#39;](../../mfc/codesnippet/cpp/systemtime-structure1_1.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinBase  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CTime::CTime](../../atl-mfc-shared/reference/ctime-class.md#ctime)


