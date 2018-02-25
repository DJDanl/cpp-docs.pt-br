---
title: 'Cdataconnection:: Operator CDataSource&amp; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDataSource&
- CDataConnection.operatorCDataSource&
- operatorCDataSource&
- CDataConnection::operatorCDataSource&
dev_langs:
- C++
helpviewer_keywords:
- CDataSource& operator
- operator & (CDataSource)
ms.assetid: 852faeee-f1b1-4465-9828-b261d1edf022
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 255d1fe1d6363277c300fee134c5c41473ee8c3b
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cdataconnectionoperator-cdatasourceamp"></a>Cdataconnection:: Operator CDataSource&amp;
Retorna uma referência para o contido `CDataSource` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
operator const CDataSource&() throw();  
  
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