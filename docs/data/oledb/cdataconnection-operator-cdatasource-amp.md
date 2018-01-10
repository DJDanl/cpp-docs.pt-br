---
title: 'Cdataconnection:: Operator CDataSource&amp; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDataSource&
- CDataConnection.operatorCDataSource&
- operatorCDataSource&
- CDataConnection::operatorCDataSource&
dev_langs: C++
helpviewer_keywords:
- CDataSource& operator
- operator & (CDataSource)
ms.assetid: 852faeee-f1b1-4465-9828-b261d1edf022
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5cd6c1821f49ba56b8d6ca27932b6cd7f0e17bf6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdataconnectionoperator-cdatasourceamp"></a>Cdataconnection:: Operator CDataSource&amp;
Retorna uma referência para o contido `CDataSource` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
operator const CDataSource&() throw( );  
  
```  
  
## <a name="remarks"></a>Comentários  
 Esse operador retorna uma referência para o contido `CDataSource` objeto, permitindo que você passe uma `CDataConnection` objeto onde um `CDataSource` referência é esperada.  
  
## <a name="example"></a>Exemplo  
 Se você tiver uma função (como `func` abaixo) que leva um `CDataSource` referência, você pode usar **CDataSource &** para passar um `CDataConnection` do objeto em vez disso.  
  
 [!code-cpp[NVC_OLEDB_Consumer#3](../../data/oledb/codesnippet/cpp/cdataconnection-operator-cdatasource-amp_1.cpp)]  
  
 [!code-cpp[NVC_OLEDB_Consumer#4](../../data/oledb/codesnippet/cpp/cdataconnection-operator-cdatasource-amp_2.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDataConnection](../../data/oledb/cdataconnection-class.md)   
 [CDataConnection::operator CDataSource*](../../data/oledb/cdataconnection-operator-cdatasource-star.md)