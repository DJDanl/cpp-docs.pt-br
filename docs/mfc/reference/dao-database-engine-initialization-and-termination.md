---
title: "Inicialização do mecanismo de banco de dados DAO e encerramento | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros.data
dev_langs:
- C++
helpviewer_keywords:
- DAO (Data Access Objects), termination
- DAO (Data Access Objects), initialization
ms.assetid: a7edf31c-e7c2-4f3e-aada-63c3e48781da
caps.latest.revision: 13
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: b6119279234558998fad1f220239a29618c69cc5
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

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
 Na maioria dos casos, você não precisa chamar `AfxDaoInit` porque o aplicativo automaticamente chama quando for necessário.  
  
 Para obter informações relacionadas e um exemplo de chamada `AfxDaoInit`, consulte [técnico 54 Observação](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdao.h  
  
##  <a name="afxdaoterm"></a>AfxDaoTerm  
 Essa função encerra o mecanismo de banco de dados DAO.  
  
```  
 
void AfxDaoTerm();  
```  
  
### <a name="remarks"></a>Comentários  
 Normalmente, você só precisa chamar essa função em uma DLL normal; um aplicativo chamará automaticamente `AfxDaoTerm` quando ela for necessária.  
  
 Em DLLs regulares, chame `AfxDaoTerm` antes de `ExitInstance` função, mas depois que todos os objetos DAO MFC tiverem sido destruídos.  
  
 Para obter informações relacionadas, consulte [técnico 54 Observação](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).  

### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdao.h  

## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

