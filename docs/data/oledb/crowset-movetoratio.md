---
title: CRowset::MoveToRatio | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- MoveToRatio
- CRowset<TAccessor>::MoveToRatio
- CRowset::MoveToRatio
- CRowset<TAccessor>.MoveToRatio
- ATL.CRowset.MoveToRatio
- ATL::CRowset::MoveToRatio
- CRowset.MoveToRatio
- ATL.CRowset<TAccessor>.MoveToRatio
- ATL::CRowset<TAccessor>::MoveToRatio
dev_langs:
- C++
helpviewer_keywords:
- MoveToRatio method
ms.assetid: 1fa313bd-8fd1-4608-8e85-44993b97dd88
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 9c864933070af4f2a40572d0133027fb81f0855a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="crowsetmovetoratio"></a>CRowset::MoveToRatio
Busca de linhas a partir de uma posição fracionária no conjunto de linhas.  
  
## <a name="syntax"></a>Sintaxe  
  
```
HRESULT MoveToRatio(DBCOUNTITEM nNumerator,   
   DBCOUNTITEM nDenominator,bool bForward = true) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nNumerator`  
 [in] O numerador usado para determinar o fracionários posicional nele buscar dados.  
  
 `nDenominator`  
 [in] O denominador usado para determinar o fracionários posicional nele buscar dados.  
  
 `bForward`  
 [in] Indica se deve Avançar ou recuar. O padrão é encaminhar.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 `MoveToRatio` busca linhas de acordo com aproximadamente a fórmula a seguir:  
  
 `(nNumerator *  RowsetSize ) / nDenominator`  
  
 Onde `RowsetSize` é o tamanho do conjunto de linhas, medido em linhas. A precisão da fórmula depende do provedor específico. Para obter detalhes, consulte [irowsetscroll:: Getrowsatratio](https://msdn.microsoft.com/en-us/library/ms709602.aspx).  
  
 Esse método requer que a interface opcional `IRowsetScroll`, que talvez não tenha suporte em todos os provedores; se esse for o caso, o método retornará **E_NOINTERFACE**. Você também deve definir **DBPROP_IRowsetScroll** para `VARIANT_TRUE` antes de chamar **abrir** na tabela ou que contém o conjunto de linhas de comando.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRowset](../../data/oledb/crowset-class.md)