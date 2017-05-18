---
title: Estrutura ABC | Documentos do Microsoft
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
- ABC structure
ms.assetid: 32663839-c3b7-4f47-896c-b15329c96bc8
caps.latest.revision: 11
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: c8b49cd8a94c5ff580393814be08b1819a1eca52
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

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
 Especifica o espaçamento de um do caractere. O espaçamento de um é a distância para adicionar à posição atual antes do glifo de caracteres de desenho.  
  
 *abcB*  
 Especifica o espaçamento B do caractere. O espaçamento de B é a largura da parte desenhado de glifo de caracteres.  
  
 *abcC*  
 Especifica o espaçamento C do caractere. O espaçamento de C é a distância para adicionar à posição atual para fornecer espaço em branco à direita do glifo caracteres.  
  
## <a name="remarks"></a>Comentários  
 A largura total de um caractere é a soma dos espaços de A, B e C. A ou o espaço de C pode ser negativo para indicar underhangs ou overhangs.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** wingdi  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDC::GetCharABCWidths](../../mfc/reference/cdc-class.md#getcharabcwidths)



