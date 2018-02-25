---
title: 'Cenumerator:: Find | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CEnumerator::Find
- ATL::CEnumerator::Find
- ATL.CEnumerator.Find
- CEnumerator.Find
dev_langs:
- C++
helpviewer_keywords:
- Find method
ms.assetid: 69a153af-d6c3-40fd-9018-27c7d2f344c6
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 66298c4be2bb1e43aa37899fe652ccbf6694faae
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cenumeratorfind"></a>CEnumerator::Find
Procura um nome especificado entre os provedores disponíveis.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      bool Find(TCHAR* szSearchName) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *szSearchName*  
 [in] O nome a ser pesquisado.  
  
## <a name="return-value"></a>Valor de retorno  
 **True** se o nome foi encontrado. Caso contrário, **false**.  
  
## <a name="remarks"></a>Comentários  
 Esse nome é mapeado para o **SOURCES_NAME** membro o [ISourcesRowset da](https://msdn.microsoft.com/en-us/library/ms715969.aspx) interface.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CEnumerator](../../data/oledb/cenumerator-class.md)