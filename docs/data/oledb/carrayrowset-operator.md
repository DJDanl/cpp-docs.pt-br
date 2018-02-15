---
title: CArrayRowset::operator | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CArrayRowset::operator[]
- CArrayRowset.operator[]
dev_langs:
- C++
helpviewer_keywords:
- operator [], arrays
- '[] operator'
- operator[], arrays
ms.assetid: 3bb8c310-cc1e-46e8-9711-9b565488acaa
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 0921ad4c574c496656ec616d1d569158c596c5ad
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="carrayrowsetoperator"></a>CArrayRowset::operator
Fornece a sintaxe de matriz para acessar uma linha no conjunto de linhas.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      TAccessor  
      & operator[](int nrow);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `TAccessor`  
 Um parâmetro de modelo que especifica o tipo de acessador armazenado no conjunto de linhas.  
  
 `nRow`  
 [in] Número da linha (elemento de matriz) que você deseja acessar.  
  
## <a name="return-value"></a>Valor de retorno  
 O conteúdo da linha solicitada.  
  
## <a name="remarks"></a>Comentários  
 Se `nRow` excede o número de linhas no conjunto de linhas, uma exceção será lançada.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CArrayRowset](../../data/oledb/carrayrowset-class.md)