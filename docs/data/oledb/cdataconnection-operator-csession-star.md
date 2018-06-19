---
title: 'Cdataconnection:: Operator CSession * | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 97219418f18220cde84c80cb9052f17552a3a45d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33094463"
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