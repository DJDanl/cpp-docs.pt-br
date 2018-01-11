---
title: Estrutura SYSTEMTIME 1 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: SYSTEMTIME
dev_langs: C++
helpviewer_keywords: SYSTEMTIME structure [MFC]
ms.assetid: 9aaef4d6-de79-4fa1-8158-86b245ef5bff
caps.latest.revision: "15"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 07af222a3d51ff1cc71076d5bbcc3513a3d6cad4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="systemtime-structure1"></a>Estrutura SYSTEMTIME 1
O `SYSTEMTIME` estrutura representa uma data e hora usando membros individuais para o mês, dia, ano, dia da semana, hora, minuto, segundo e milissegundos.  
  
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
  
 *Whora*  
 O minuto atual.  
  
 *Wminuto*  
 O segundo atual.  
  
 *Wsegundo*  
 O milissegundo atual.  
  
## <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_Utilities#39](../../mfc/codesnippet/cpp/systemtime-structure1_1.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinBase  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CTime::CTime](../../atl-mfc-shared/reference/ctime-class.md#ctime)

