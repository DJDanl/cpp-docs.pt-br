---
title: Classe CNotSupportedException | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CNotSupportedException
- AFX/CNotSupportedException
- AFX/CNotSupportedException::CNotSupportedException
dev_langs:
- C++
helpviewer_keywords:
- CNotSupportedException [MFC], CNotSupportedException
ms.assetid: e517391b-eb94-4c39-ae32-87b45bf7d624
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4013b26e3c07d6ec2a729bf9868db48923e35f86
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cnotsupportedexception-class"></a>Classe CNotSupportedException
Representa uma exceção que é o resultado de uma solicitação para um recurso sem suporte.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CNotSupportedException : public CSimpleException  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CNotSupportedException::CNotSupportedException](#cnotsupportedexception)|Constrói um objeto `CNotSupportedException`.|  
  
## <a name="remarks"></a>Comentários  
 Nenhuma qualificação adicional é necessário ou possíveis.  
  
 Para obter mais informações sobre como usar `CNotSupportedException`, consulte o artigo [de tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 [CSimpleException](../../mfc/reference/csimpleexception-class.md)  
  
 `CNotSupportedException`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX  
  
##  <a name="cnotsupportedexception"></a>CNotSupportedException::CNotSupportedException  
 Constrói um objeto `CNotSupportedException`.  
  
```  
CNotSupportedException();
```  
  
### <a name="remarks"></a>Comentários  
 Não use este construtor diretamente, mas em vez disso, chame a função global [AfxThrowNotSupportedException](exception-processing.md#afxthrownotsupportedexception). Para obter mais informações sobre o processamento de exceção, consulte o artigo [tratamento de exceção MFC](../exception-handling-in-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CException](cexception-class.md)   
 [Gráfico da hierarquia](../hierarchy-chart.md)


