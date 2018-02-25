---
title: CRowset::Compare | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CRowset<TAccessor>.Compare
- CRowset<TAccessor>::Compare
- ATL.CRowset<TAccessor>.Compare
- ATL::CRowset<TAccessor>::Compare
- CRowset.Compare
- ATL::CRowset::Compare
- ATL.CRowset.Compare
- CRowset::Compare
dev_langs:
- C++
helpviewer_keywords:
- Compare method
ms.assetid: a8117b40-7abd-4867-b0ba-eb9e9808204e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 1d77c24847a58bace5ff5aca8276dc605811ab7a
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="crowsetcompare"></a>CRowset::Compare
Compara dois indicadores usando [IRowsetLocate::Compare](https://msdn.microsoft.com/en-us/library/ms709539.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT Compare(const CBookmarkBase& bookmark1,   
   const CBookmarkBase& bookmark2,   
   DBCOMPARE* pComparison) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Bookmark1*  
 [in] O primeiro indicador a ser comparado.  
  
 *Bookmark2*  
 [in] O segundo indicador a ser comparado.  
  
 `pComparison`  
 [out] Um ponteiro para o resultado da comparação.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Esse método requer que a interface opcional `IRowsetLocate`, que talvez não tenha suporte em todos os provedores; se esse for o caso, o método retornará **E_NOINTERFACE**. Você também deve definir **DBPROP_IRowsetLocate** para `VARIANT_TRUE` antes de chamar **abrir** na tabela ou que contém o conjunto de linhas de comando.  
  
 Para obter informações sobre como usar indicadores em clientes, consulte [usando indicadores](../../data/oledb/using-bookmarks.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRowset](../../data/oledb/crowset-class.md)