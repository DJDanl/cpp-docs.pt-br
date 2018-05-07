---
title: CUtlProps::GetPropValue | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CUtlProps::GetPropValue
- CUtlProps.GetPropValue
- GetPropValue
dev_langs:
- C++
helpviewer_keywords:
- GetPropValue method
ms.assetid: 9a3fbadb-7814-48f7-96a4-b960fc4ecf2e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 00f56c317f9325fa51f7165fc3872b1e4ca6e9da
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cutlpropsgetpropvalue"></a>CUtlProps::GetPropValue
Obtém uma propriedade de um conjunto de propriedades.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      OUT_OF_LINE HRESULT GetPropValue(const GUID* pguidPropSet,  
   DBPROPID dwPropId,  
   VARIANT* pvValue);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pguidPropSet`  
 [in] O GUID do conjunto de propriedades.  
  
 `dwPropId`  
 [in] O índice da propriedade.  
  
 `pvValue`  
 [out] Um ponteiro para um tipo variant que contém o novo valor da propriedade.  
  
## <a name="return-value"></a>Valor de retorno  
 `Failure` em caso de falha e `S_OK` se for bem-sucedido.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CUtlProps](../../data/oledb/cutlprops-class.md)