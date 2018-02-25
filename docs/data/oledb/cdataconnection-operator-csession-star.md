---
title: 'Cdataconnection:: Operator CSession * | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDataConnection.operatorCSession*
- CDataConnection::operatorCSession*
- operatorCSession*
- CSession*
dev_langs:
- C++
helpviewer_keywords:
- operator CSession*
- CSession* operator
ms.assetid: 0b0feede-5c3e-4835-be5b-03651597014d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 957e13346cb187540c21cbec71a642a917b69908
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cdataconnectionoperator-csession"></a>CDataConnection::operator CSession*
Retorna um ponteiro para o contido `CSession` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
operator const CSession*() throw();  
  
```  
  
## <a name="remarks"></a>Comentários  
 Esse operador retorna um ponteiro para o contido `CSession` objeto, permitindo que você passe uma `CDataConnection` objeto onde um `CSession` ponteiro é esperado.  
  
## <a name="example"></a>Exemplo  
 Consulte [operador CSession &](../../data/oledb/cdataconnection-operator-csession-amp.md) para obter um exemplo de uso.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDataConnection](../../data/oledb/cdataconnection-class.md)   
 [CDataConnection::operator CSession&](../../data/oledb/cdataconnection-operator-csession-amp.md)