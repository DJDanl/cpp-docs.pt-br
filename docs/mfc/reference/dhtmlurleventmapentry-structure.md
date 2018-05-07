---
title: Estrutura DHtmlUrlEventMapEntry | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- DHtmlUrlEventMapEntry
dev_langs:
- C++
helpviewer_keywords:
- DHtmlUrlEventMapEntry structure [MFC]
ms.assetid: 43117c1f-1a51-406c-aa2f-fea647080049
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d038fa188ac431f20b0b19ca8ad8bf675943954c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="dhtmlurleventmapentry-structure"></a>Estrutura DHtmlUrlEventMapEntry
O `DHtmlUrlEventMapEntry` estrutura oferece suporte ao mapa de evento de multi-URL.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct DHtmlUrlEventMapEntry  
{  
LPCTSTR szUrl;  
const DHtmlEventMapEntry *pEventMap;  
};  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `szUrl`  
 A URL.  
  
 *pEventMap*  
 O mapa de evento associado à URL.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdhtml.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)

