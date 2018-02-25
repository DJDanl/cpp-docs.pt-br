---
title: 'Cdataconnection:: Cdataconnection | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDataConnection.CDataConnection
- ATL.CDataConnection.CDataConnection
- CDataConnection::CDataConnection
- ATL::CDataConnection::CDataConnection
dev_langs:
- C++
helpviewer_keywords:
- CDataConnection class, constructor
ms.assetid: ac25c9a0-44d3-4083-b13f-76c07772e12d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 4405e0dce66de9f006a23b5b680072b9562af06f
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cdataconnectioncdataconnection"></a>CDataConnection::CDataConnection
Cria e inicializa um `CDataConnection` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      CDataConnection();   

CDataConnection(const CDataConnection &ds);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `ds`  
 [in] Uma referência a uma conexão de dados existente.  
  
## <a name="remarks"></a>Comentários  
 A primeira substituição cria um novo `CDataConnection` objeto com as configurações padrão.  
  
 A substituição de segundo cria um novo `CDataConnection` objeto com as configurações equivalentes para o objeto de conexão de dados que você especificar.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDataConnection](../../data/oledb/cdataconnection-class.md)