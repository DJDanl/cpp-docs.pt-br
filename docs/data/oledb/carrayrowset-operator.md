---
title: 'Carrayrowset:: Operator | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CArrayRowset::operator[]
- CArrayRowset.operator[]
dev_langs: C++
helpviewer_keywords:
- operator [], arrays
- '[] operator'
- operator[], arrays
ms.assetid: 3bb8c310-cc1e-46e8-9711-9b565488acaa
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 14d0c07f8d1b8ff5cef19620fc00d156e251bf80
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="carrayrowsetoperator"></a>Carrayrowset:: Operator
Fornece a sintaxe de matriz para acessar uma linha no conjunto de linhas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
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