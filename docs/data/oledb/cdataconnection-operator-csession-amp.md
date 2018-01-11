---
title: 'Cdataconnection:: Operator CSession&amp; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CSession&
- CDataConnection::operatorCSession&
- CDataConnection.operatorCSession&
- operatorCSession&
dev_langs: C++
helpviewer_keywords:
- operator CSession&
- CSession& operator
ms.assetid: fba1e498-e482-4dda-8e0f-2542163bf627
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 35e28b96c3daddcdf8a9ea4bdf06f9b1410463f2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdataconnectionoperator-csessionamp"></a>Cdataconnection:: Operator CSession&amp;
Retorna uma referência para o contido `CSession` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
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