---
title: Classe CResourceException | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CResourceException
- AFXWIN/CResourceException
- AFXWIN/CResourceException::CResourceException
dev_langs:
- C++
helpviewer_keywords:
- CResourceException [MFC], CResourceException
ms.assetid: af6ae043-d124-4bfd-b35e-7bb0db67d289
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e2e17b859042a5712a998eaeebe9f16f81c91200
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cresourceexception-class"></a>Classe CResourceException
Gerado quando o Windows não pode localizar ou alocar um recurso solicitado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CResourceException : public CSimpleException  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CResourceException::CResourceException](#cresourceexception)|Constrói um objeto `CResourceException`.|  
  
## <a name="remarks"></a>Comentários  
 Nenhuma qualificação adicional é necessário ou possíveis.  
  
 Para obter mais informações sobre como usar `CResourceException`, consulte o artigo [de tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 [CSimpleException](../../mfc/reference/csimpleexception-class.md)  
  
 `CResourceException`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="cresourceexception"></a>CResourceException::CResourceException  
 Constrói um objeto `CResourceException`.  
  
```  
CResourceException();
```  
  
### <a name="remarks"></a>Comentários  
 Não use este construtor diretamente, mas em vez disso, chame a função global [AfxThrowResourceException](exception-processing.md#afxthrowresourceexception). Para obter mais informações sobre exceções, consulte o artigo [tratamento de exceção MFC](../exception-handling-in-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CException](cexception-class.md)   
 [Gráfico da hierarquia](../hierarchy-chart.md)


