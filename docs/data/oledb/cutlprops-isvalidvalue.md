---
title: 'Cutlprops:: Isvalidvalue | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CUtlProps::IsValidValue
- CUtlProps.IsValidValue
- IsValidValue
dev_langs: C++
helpviewer_keywords: IsValidValue method
ms.assetid: 1164556e-8d98-429c-a396-fc9a699e0e97
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 06193b8c560c5ac6006698813222e698a98bccc3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cutlpropsisvalidvalue"></a>CUtlProps::IsValidValue
Usado para validar um valor antes de definir uma propriedade.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      virtual HRESULT CUtlPropsBase::IsValidValue(  
   ULONG /* iCurSet */,  
   DBPROP* pDBProp   
);  
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