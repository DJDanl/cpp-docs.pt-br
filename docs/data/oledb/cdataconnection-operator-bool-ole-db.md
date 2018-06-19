---
title: 'Cdataconnection:: Operator bool (OLE DB) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CDataConnection::operatorBOOL
- ATL::CDataConnection::operatorBOOL
- CDataConnection.operatorBOOL
- ATL.CDataConnection.operatorBOOL
dev_langs:
- C++
helpviewer_keywords:
- BOOL operator
- operator bool
ms.assetid: e0791faf-2ed2-4dbb-9e68-3b9b5da2b7a7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 1f466085f1003ca14f9df6db648ba7a3f833b3b8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33093435"
---
# <a name="cdataconnectionoperator-bool-ole-db"></a>CDataConnection::operator bool (banco de dados OLE)
Determina se a sessão atual está aberta ou não.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
operator bool() throw();  
  
```  
  
## <a name="remarks"></a>Comentários  
 Retorna um `bool` valor (tipo de dados C++). **True** significa que a sessão atual está aberta. **false** significa que a sessão atual é fechada.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDataConnection](../../data/oledb/cdataconnection-class.md)   
 [CDataConnection::operator BOOL](../../data/oledb/cdataconnection-operator-bool.md)