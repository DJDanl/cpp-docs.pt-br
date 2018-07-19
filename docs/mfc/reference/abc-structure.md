---
title: Estrutura ABC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- ABC
dev_langs:
- C++
helpviewer_keywords:
- ABC structure [MFC]
ms.assetid: 32663839-c3b7-4f47-896c-b15329c96bc8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2c9aac181edb12df8904a2bc6d891d59c0067ecc
ms.sourcegitcommit: 6408139d5f5ff8928f056bde93d20eecb3520361
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2018
ms.locfileid: "37339313"
---
# <a name="abc-structure"></a>Estrutura ABC
O `ABC` estrutura contém a largura de um caractere em uma fonte TrueType.  
  
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
 Especifica o espaçamento entre um caractere. O espaçamento de um é a distância para adicionar à posição atual antes de desenhar o glifo de caracteres.  
  
 *abcB*  
 Especifica o espaçamento de B do caractere. O espaçamento de B é a largura da parte desenhado de glifo de caracteres.  
  
 *abcC*  
 Especifica o espaçamento de C do caractere. O espaçamento de C é a distância para adicionar à posição atual para fornecer espaço em branco à direita do glifo de caracteres.  
  
## <a name="remarks"></a>Comentários  
 A largura total de um caractere é a soma dos espaços de A, B e C. O r ou o espaço de C pode ser negativo para indicar underhangs ou overhangs.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** wingdi  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDC::GetCharABCWidths](../../mfc/reference/cdc-class.md#getcharabcwidths)


