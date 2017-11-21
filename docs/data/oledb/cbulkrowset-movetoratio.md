---
title: 'Cbulkrowset:: Movetoratio | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CBulkRowset.MoveToRatio
- ATL::CBulkRowset::MoveToRatio
- MoveToRatio
- CBulkRowset::MoveToRatio
- ATL.CBulkRowset<TAccessor>.MoveToRatio
- ATL::CBulkRowset<TAccessor>::MoveToRatio
- ATL.CBulkRowset.MoveToRatio
- CBulkRowset<TAccessor>::MoveToRatio
dev_langs: C++
helpviewer_keywords: MoveToRatio method
ms.assetid: 86be60f5-9341-44c1-8e1e-9174c082d0d5
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 49401bc59ef6858f501c2613199ab5a9114a1e8d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cbulkrowsetmovetoratio"></a>CBulkRowset::MoveToRatio
Busca de linhas a partir de uma posição fracionária no conjunto de linhas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      HRESULT MoveToRatio(  
   DBCOUNTITEM nNumerator,  
   DBCOUNTITEM nDenominator   
) throw( );  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nNumerator`  
 [in] O numerador usado para determinar a posição fracionária do que buscar dados.  
  
 `nDenominator`  
 [in] O denominador usado para determinar a posição fracionária do que buscar dados.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 `MoveToRatio`busque as linhas mais ou menos, de acordo com a seguinte fórmula:  
  
 `( nNumerator *  RowsetSize ) / nDenominator`  
  
 Onde `RowsetSize` é o tamanho do conjunto de linhas, medido em linhas. A precisão da fórmula depende do provedor específico. Para obter detalhes, consulte [irowsetscroll:: Getrowsatratio](https://msdn.microsoft.com/en-us/library/ms709602.aspx) no *referência do programador de DB OLE*.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CBulkRowset](../../data/oledb/cbulkrowset-class.md)