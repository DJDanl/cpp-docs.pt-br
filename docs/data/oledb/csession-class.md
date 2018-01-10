---
title: Classe CSession | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CSession
- ATL::CSession
- ATL.CSession
dev_langs: C++
helpviewer_keywords: CSession class
ms.assetid: 83cd798f-b45d-4f11-a23c-29183390450c
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: d8b6bb75d12b4ab96c3a44c74f4487eb8a70efc6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="csession-class"></a>Classe CSession
Representa uma sessão de acesso único banco de dados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSession  
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[Anular](../../data/oledb/csession-abort.md)|Cancela (encerra) a transação.|  
|[Fechar](../../data/oledb/csession-close.md)|Fecha a sessão.|  
|[Confirmação](../../data/oledb/csession-commit.md)|Confirma a transação.|  
|[GetTransactionInfo](../../data/oledb/csession-gettransactioninfo.md)|Retorna informações relativas a uma transação.|  
|[Abrir](../../data/oledb/csession-open.md)|Abre uma nova sessão para o objeto de fonte de dados.|  
|[StartTransaction](../../data/oledb/csession-starttransaction.md)|Inicia uma nova transação para esta sessão.|  
  
## <a name="remarks"></a>Comentários  
 Uma ou mais sessões podem ser associadas a cada conexão de provedor (fonte de dados), que é representado por um [CDataSource](../../data/oledb/cdatasource-class.md) objeto. Para criar um novo `CSession` para um `CDataSource`, chame [csession:: Open](../../data/oledb/csession-open.md). Para iniciar uma transação de banco de dados, `CSession` fornece o `StartTransaction` método. Depois que uma transação é iniciada, você poderá confirmar a ele usando o **confirmação** método, ou cancele-o usando o **anular** método.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [CatDB](../../visual-cpp-samples.md)   
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)