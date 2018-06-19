---
title: 'Cdataconnection:: Operator CDataSource * | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CDataSource*
- CDataConnection::operatorCDataSource*
- CDataConnection.operatorCDataSource*
- operatorCDataSource*
dev_langs:
- C++
helpviewer_keywords:
- CDataSource* operator
- operator * (CDataSource)
ms.assetid: 9118e324-e68d-45c5-a791-03f041d420ed
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: bade9d813fb9804ae353f7c5139f063f278da225
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33095333"
---
# <a name="cdataconnectionoperator-cdatasource"></a>CDataConnection::operator CDataSource*
Retorna um ponteiro para o contido `CDataSource` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
operator const CDataSource*() throw();  
  
```  
  
## <a name="remarks"></a>Comentários  
 Esse operador retorna um ponteiro para o contido `CDataSource` objeto, permitindo que você passe uma `CDataConnection` objeto onde um `CDataSource` ponteiro é esperado.  
  
 Consulte [operador CDataSource &](../../data/oledb/cdataconnection-operator-cdatasource-amp.md) para obter um exemplo de uso.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDataConnection](../../data/oledb/cdataconnection-class.md)   
 [CDataConnection::operator CDataSource&](../../data/oledb/cdataconnection-operator-cdatasource-amp.md)