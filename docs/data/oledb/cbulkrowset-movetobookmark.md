---
title: CBulkRowset::MoveToBookmark | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CBulkRowset<TAccessor>::MoveToBookmark
- CBulkRowset.MoveToBookmark
- MoveToBookmark
- ATL.CBulkRowset.MoveToBookmark
- CBulkRowset::MoveToBookmark
- ATL::CBulkRowset<TAccessor>::MoveToBookmark
- ATL::CBulkRowset::MoveToBookmark
dev_langs:
- C++
helpviewer_keywords:
- MoveToBookmark method
ms.assetid: 76aab025-819e-4ecd-ae0a-d8d3fb2d2099
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 4b1911fe170262e65ef06e65649f837a0b723d05
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cbulkrowsetmovetobookmark"></a>CBulkRowset::MoveToBookmark
Busca a linha marcada por um indicador ou a linha em um deslocamento especificado (`lSkip`) desse indicador.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT MoveToBookmark(const CBookmarkBase& bookmark,  
   DBCOUNTITEM lSkip = 0) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `bookmark`  
 [in] Um indicador que marca o local do qual você deseja obter dados.  
  
 `lSkip`  
 [in] A contagem do número de linhas de indicador para a linha de destino. Se `lSkip` for zero, a primeira linha buscada é a linha marcada. Se `lSkip` for 1, a primeira linha buscada é a linha após a linha marcada. Se `lSkip` é -1, a primeira linha buscada é a linha antes da linha indicada.  
  
## <a name="return-value"></a>Valor de retorno  
 Consulte [IRowset:: GetData](https://msdn.microsoft.com/en-us/library/ms716988.aspx) no *referência do programador de OLE DB*.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CBulkRowset](../../data/oledb/cbulkrowset-class.md)