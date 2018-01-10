---
title: Classe CInvalidArgException | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CInvalidArgException
- AFX/CInvalidArgException
- AFX/CInvalidArgException::CInvalidArgException
dev_langs: C++
helpviewer_keywords: CInvalidArgException [MFC], CInvalidArgException
ms.assetid: e43d7c67-1157-47f8-817a-804083e8186e
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 03f9bea1c9e5e88856bbf5a5aa2e824a2c99963c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cinvalidargexception-class"></a>Classe CInvalidArgException
Essa classe representa uma condição de exceção de argumento inválido.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CInvalidArgException : public CSimpleException  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CInvalidArgException::CInvalidArgException](#cinvalidargexception)|O construtor.|  
  
## <a name="remarks"></a>Comentários  
 Um `CInvalidArgException` objeto representa uma condição de exceção de argumento inválido.  
  
 Para obter mais informações sobre o tratamento de exceção, consulte o [classe CException](../../mfc/reference/cexception-class.md) tópico e [de tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 [CSimpleException](../../mfc/reference/csimpleexception-class.md)  
  
 `CInvalidArgException`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX  
  
##  <a name="cinvalidargexception"></a>CInvalidArgException::CInvalidArgException  
 O construtor.  
  
```  
CInvalidArgException();
```  
  
### <a name="remarks"></a>Comentários  
 Não use este construtor diretamente. Chame a função global **AfxThrowInvalidArgException**.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CSimpleException](../../mfc/reference/csimpleexception-class.md)
