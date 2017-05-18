---
title: Classe CMemoryException | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMemoryException
- AFX/CMemoryException
- AFX/CMemoryException::CMemoryException
dev_langs:
- C++
helpviewer_keywords:
- CMemoryException class
- memory exceptions
- exceptions, memory type
- C++ exception handling, memory
- memory, exception handling
ms.assetid: 9af0ed57-d12a-45ca-82b5-c910a60f7edf
caps.latest.revision: 20
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
ms.openlocfilehash: 87be1b16d546791d24bbffa62207ec9ccb350139
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cmemoryexception-class"></a>Classe CMemoryException
Representa uma condição de exceção de memória insuficiente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMemoryException : public CSimpleException  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMemoryException::CMemoryException](#cmemoryexception)|Constrói um objeto `CMemoryException`.|  
  
## <a name="remarks"></a>Comentários  
 Sem qualificação adicional é necessário ou possíveis. Exceções de memória são geradas automaticamente pelo **novo**. Se você escrever suas próprias funções de memória, usando `malloc`, por exemplo, você é responsável por gerar exceções de memória.  
  
 Para obter mais informações sobre `CMemoryException`, consulte o artigo [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 [CSimpleException](../../mfc/reference/csimpleexception-class.md)  
  
 `CMemoryException`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h  
  
##  <a name="cmemoryexception"></a>CMemoryException::CMemoryException  
 Constrói um objeto `CMemoryException`.  
  
```  
CMemoryException();  
```  
  
### <a name="remarks"></a>Comentários  
 Não use esse construtor diretamente, mas em vez disso, chame a função global [AfxThrowMemoryException](exception-processing.md#afxthrowmemoryexception). Essa função global pode ser bem-sucedida em uma situação de falta de memória porque ele cria o objeto de exceção de memória alocado anteriormente. Para obter mais informações sobre o processamento de exceção, consulte o artigo [exceções](../exception-handling-in-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CException](cexception-class.md)   
 [Gráfico de hierarquia](../hierarchy-chart.md)




