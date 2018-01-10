---
title: 'Cdataconnection:: Operator bool (OLE DB) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDataConnection::operatorBOOL
- ATL::CDataConnection::operatorBOOL
- CDataConnection.operatorBOOL
- ATL.CDataConnection.operatorBOOL
dev_langs: C++
helpviewer_keywords:
- BOOL operator
- operator bool
ms.assetid: e0791faf-2ed2-4dbb-9e68-3b9b5da2b7a7
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: d446e0082381a927e139fc803a0c5ee17ce610f6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdataconnectionoperator-bool-ole-db"></a>CDataConnection::operator bool (banco de dados OLE)
Determina se a sessão atual está aberta ou não.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
operator bool( ) throw( );  
  
```  
  
## <a name="remarks"></a>Comentários  
 Retorna um `bool` valor (tipo de dados C++). **True** significa que a sessão atual está aberta. **false** significa que a sessão atual é fechada.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDataConnection](../../data/oledb/cdataconnection-class.md)   
 [CDataConnection::operator BOOL](../../data/oledb/cdataconnection-operator-bool.md)