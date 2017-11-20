---
title: 'Cutlprops:: Getpropvalue | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CUtlProps::GetPropValue
- CUtlProps.GetPropValue
- GetPropValue
dev_langs: C++
helpviewer_keywords: GetPropValue method
ms.assetid: 9a3fbadb-7814-48f7-96a4-b960fc4ecf2e
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 857738960ff6a141bbde363a7db1193e6f5e21f7
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cutlpropsgetpropvalue"></a>CUtlProps::GetPropValue
Obtém uma propriedade de um conjunto de propriedades.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      OUT_OF_LINE HRESULT GetPropValue(  
   const GUID* pguidPropSet,  
   DBPROPID dwPropId,  
   VARIANT* pvValue   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pguidPropSet`  
 [in] O GUID do conjunto de propriedades.  
  
 `dwPropId`  
 [in] O índice da propriedade.  
  
 `pvValue`  
 [out] Um ponteiro para um tipo variant que contém o novo valor da propriedade.  
  
## <a name="return-value"></a>Valor de retorno  
 `Failure`em caso de falha e `S_OK` se for bem-sucedido.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CUtlProps](../../data/oledb/cutlprops-class.md)