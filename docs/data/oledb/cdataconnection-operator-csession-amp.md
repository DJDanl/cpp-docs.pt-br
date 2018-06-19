---
title: 'Cdataconnection:: Operator CSession&amp; | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CSession&
- CDataConnection::operatorCSession&
- CDataConnection.operatorCSession&
- operatorCSession&
dev_langs:
- C++
helpviewer_keywords:
- operator CSession&
- CSession& operator
ms.assetid: fba1e498-e482-4dda-8e0f-2542163bf627
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 7d46aeb352016c41dddaee972d438be8c28e22a9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33095415"
---
# <a name="cdataconnectionoperator-csessionamp"></a>Cdataconnection:: Operator CSession&amp;
Retorna uma referência para o contido `CSession` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
operator const CSession&();  
  
```  
  
## <a name="remarks"></a>Comentários  
 Esse operador retorna uma referência para o contido `CSession` objeto, permitindo que você passe uma `CDataConnection` objeto onde um `CSession` referência é esperada.  
  
## <a name="example"></a>Exemplo  
 Se você tiver uma função (como `func` abaixo) que leva um `CSession` referência, você pode usar **CSession &** para passar um `CDataConnection` do objeto em vez disso.  
  
 [!code-cpp[NVC_OLEDB_Consumer#5](../../data/oledb/codesnippet/cpp/cdataconnection-operator-csession-amp_1.cpp)]  
  
 [!code-cpp[NVC_OLEDB_Consumer#6](../../data/oledb/codesnippet/cpp/cdataconnection-operator-csession-amp_2.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDataConnection](../../data/oledb/cdataconnection-class.md)   
 [CDataConnection::operator CSession*](../../data/oledb/cdataconnection-operator-csession-star.md)