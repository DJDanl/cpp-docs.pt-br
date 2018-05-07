---
title: Estrutura SYSTEMTIME 1 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- SYSTEMTIME
dev_langs:
- C++
helpviewer_keywords:
- SYSTEMTIME structure [MFC]
ms.assetid: 9aaef4d6-de79-4fa1-8158-86b245ef5bff
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 97a0042adaa223fc5898c057f191f7b750fa230f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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

