---
title: Estrutura ABCFLOAT | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: ABCFLOAT
dev_langs: C++
helpviewer_keywords: ABCFLOAT structure [MFC]
ms.assetid: 338e7e15-9d2c-42d0-aa80-273acfde5cc5
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b58871df5a526455297dd6d092f98e9facd901ae
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="abcfloat-structure"></a>Estrutura ABCFLOAT
O `ABCFLOAT` estrutura contém as larguras de A, B e C de um caractere de fonte.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct _ABCFLOAT { /* abcf */  
    FLOAT abcfA;  
    FLOAT abcfB;  
    FLOAT abcfC;  
} ABCFLOAT;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *abcfA*  
 Especifica o espaçamento de um do caractere. O espaçamento de um é a distância para adicionar à posição atual antes de desenho no glifo do caractere.  
  
 *abcfB*  
 Especifica o espaçamento B do caractere. O espaçamento de B é a largura da parte desenhado de glifo de caracteres.  
  
 *abcfC*  
 Especifica o espaçamento de C do caractere. O espaçamento de C é a distância para adicionar à posição atual para fornecer espaço em branco à direita do glifo de caractere.  
  
## <a name="remarks"></a>Comentários  
 As larguras de A, B e C são medidas ao longo da linha de base da fonte. O incremento de caractere (largura total) de um caractere é a soma dos espaços de A, B e C. O ou o espaço de C pode ser negativo para indicar underhangs ou overhangs.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** wingdi  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDC::GetCharABCWidths](../../mfc/reference/cdc-class.md#getcharabcwidths)

