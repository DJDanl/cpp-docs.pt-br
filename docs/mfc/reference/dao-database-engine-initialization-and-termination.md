---
title: "Inicialização do mecanismo de banco de dados DAO e encerramento | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.mfc.macros.data
dev_langs: C++
helpviewer_keywords:
- DAO (Data Access Objects), termination
- DAO (Data Access Objects), initialization
ms.assetid: a7edf31c-e7c2-4f3e-aada-63c3e48781da
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 4e32930b53c6e05abf692474fdb1236fe007a1eb
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="dao-database-engine-initialization-and-termination"></a>Inicialização e término do mecanismo de banco de dados DAO
Ao usar objetos DAO MFC, o mecanismo de banco de dados DAO deve primeiro ser inicializado e, em seguida, encerrado antes de seu aplicativo ou a DLL é fechado. Duas funções, `AfxDaoInit` e `AfxDaoTerm`, executar essas tarefas.  
  
### <a name="dao-database-engine-initialization-and-termination"></a>Inicialização e término do mecanismo de banco de dados DAO  
  
|||  
|-|-|  
|[AfxDaoInit](#afxdaoinit)|Inicializa o mecanismo de banco de dados DAO.|  
|[AfxDaoTerm](#afxdaoterm)|Encerra o mecanismo de banco de dados DAO.|  
  
##  <a name="afxdaoinit"></a>AfxDaoInit  
 Essa função inicializa o mecanismo de banco de dados DAO.  
  
```  
 
void AfxDaoInit();

throw(CDaoException*);  
```  
  
### <a name="remarks"></a>Comentários  
 Na maioria dos casos, você não precisa chamar `AfxDaoInit` porque o aplicativo automaticamente chamá-lo quando necessário.  
  
 Para obter informações relacionadas e um exemplo de chamada `AfxDaoInit`, consulte [54 de observação técnica](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdao.h  
  
##  <a name="afxdaoterm"></a>AfxDaoTerm  
 Essa função encerra o mecanismo de banco de dados DAO.  
  
```  
 
void AfxDaoTerm();  
```  
  
### <a name="remarks"></a>Comentários  
 Normalmente, você só precisa chamar essa função em uma DLL MFC; regular um aplicativo chamará automaticamente `AfxDaoTerm` quando ela for necessária.  
  
 Em DLLs normais do MFC, chame `AfxDaoTerm` antes do `ExitInstance` função, mas depois que todos os objetos DAO MFC tem sido destruídos.  
  
 Para obter informações relacionadas, consulte [54 de observação técnica](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).  

### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdao.h  

## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
