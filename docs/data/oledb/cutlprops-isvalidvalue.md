---
title: CUtlProps::IsValidValue | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CUtlProps::IsValidValue
- CUtlProps.IsValidValue
- IsValidValue
dev_langs:
- C++
helpviewer_keywords:
- IsValidValue method
ms.assetid: 1164556e-8d98-429c-a396-fc9a699e0e97
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: bd02ef7c27926b2be99ed900b82d53c77d8d6dd0
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cutlpropsisvalidvalue"></a>CUtlProps::IsValidValue
Usado para validar um valor antes de definir uma propriedade.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      virtual HRESULT CUtlPropsBase::IsValidValue(ULONG /* iCurSet */,  
   DBPROP* pDBProp);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `iCurSet`  
 O índice na matriz de conjunto de propriedades; zero se houver apenas uma propriedade.  
  
 `pDBProp`  
 A ID de propriedade e o novo valor em uma [DBPROP](https://msdn.microsoft.com/en-us/library/ms717970.aspx) estrutura.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`. O padrão é valor de retorno `S_OK`.  
  
## <a name="remarks"></a>Comentários  
 Se você tiver qualquer rotinas de validação que você deseja executar em um valor que você está prestes a usar para definir uma propriedade, você deve substituir essa função. Por exemplo, você pode validar **DBPROP_AUTH_PASSWORD** em uma tabela de senha para determinar um valor válido.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CUtlProps](../../data/oledb/cutlprops-class.md)