---
title: 'Carrayrowset:: Operator | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 755e484f430f47eb072e3c590bfbee8471984bb6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33089121"
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