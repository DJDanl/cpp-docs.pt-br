---
title: Estrutura ABC | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ABC
dev_langs:
- C++
helpviewer_keywords:
- ABC structure [MFC]
ms.assetid: 32663839-c3b7-4f47-896c-b15329c96bc8
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8ba8add08fcd5ff3d7343477aafa7d910885b0b8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="abc-structure"></a>Estrutura ABC
O **ABC** estrutura contém a largura de um caractere em uma fonte TrueType.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct _ABC { /* abc */  
    int abcA;  
    UINT abcB;  
    int abcC;  
} ABC;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *abcA*  
 Especifica o espaçamento de um do caractere. O espaçamento de um é a distância para adicionar à posição atual antes de desenho no glifo do caractere.  
  
 *abcB*  
 Especifica o espaçamento B do caractere. O espaçamento de B é a largura da parte desenhado de glifo de caracteres.  
  
 *abcC*  
 Especifica o espaçamento de C do caractere. O espaçamento de C é a distância para adicionar à posição atual para fornecer espaço em branco à direita do glifo de caractere.  
  
## <a name="remarks"></a>Comentários  
 A largura total de um caractere é a soma dos espaços de A, B e C. O ou o espaço de C pode ser negativo para indicar underhangs ou overhangs.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** wingdi  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDC::GetCharABCWidths](../../mfc/reference/cdc-class.md#getcharabcwidths)


