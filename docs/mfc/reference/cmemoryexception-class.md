---
title: Classe CMemoryException | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMemoryException
- AFX/CMemoryException
- AFX/CMemoryException::CMemoryException
dev_langs: C++
helpviewer_keywords: CMemoryException [MFC], CMemoryException
ms.assetid: 9af0ed57-d12a-45ca-82b5-c910a60f7edf
caps.latest.revision: "20"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 18947e40aefd2820816abd419440ff929feca2a2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmemoryexception-class"></a>Classe CMemoryException
Representa uma condição de exceção de falta de memória.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMemoryException : public CSimpleException  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMemoryException::CMemoryException](#cmemoryexception)|Constrói um objeto `CMemoryException`.|  
  
## <a name="remarks"></a>Comentários  
 Nenhuma qualificação adicional é necessário ou possíveis. Exceções de memória são geradas automaticamente pelo **novo**. Se você escrever suas próprias funções de memória, usando `malloc`, por exemplo, em seguida, você é responsável por gerar exceções de memória.  
  
 Para obter mais informações sobre `CMemoryException`, consulte o artigo [de tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 [CSimpleException](../../mfc/reference/csimpleexception-class.md)  
  
 `CMemoryException`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX  
  
##  <a name="cmemoryexception"></a>CMemoryException::CMemoryException  
 Constrói um objeto `CMemoryException`.  
  
```  
CMemoryException();  
```  
  
### <a name="remarks"></a>Comentários  
 Não use este construtor diretamente, mas em vez disso, chame a função global [AfxThrowMemoryException](exception-processing.md#afxthrowmemoryexception). Essa função global pode ter êxito em uma situação de falta de memória porque ele constrói o objeto de exceção de memória alocada anteriormente. Para obter mais informações sobre o processamento de exceção, consulte o artigo [exceções](../exception-handling-in-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CException](cexception-class.md)   
 [Gráfico da hierarquia](../hierarchy-chart.md)



