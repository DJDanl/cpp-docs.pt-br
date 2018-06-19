---
title: Classe CResourceException | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6fdbfb29b00eaac40b4da2b78753df6a0596764f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33371524"
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
  
##  <a name="cresourceexception"></a>  CResourceException::CResourceException  
 Constrói um objeto `CResourceException`.  
  
```  
CResourceException();
```  
  
### <a name="remarks"></a>Comentários  
 Não use este construtor diretamente, mas em vez disso, chame a função global [AfxThrowResourceException](exception-processing.md#afxthrowresourceexception). Para obter mais informações sobre exceções, consulte o artigo [tratamento de exceção MFC](../exception-handling-in-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CException](cexception-class.md)   
 [Gráfico da hierarquia](../hierarchy-chart.md)


