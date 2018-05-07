---
title: CRowset::MoveToBookmark | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL::CRowset::MoveToBookmark
- ATL::CRowset<TAccessor>::MoveToBookmark
- ATL.CRowset.MoveToBookmark
- ATL.CRowset<TAccessor>.MoveToBookmark
- MoveToBookmark
- CRowset::MoveToBookmark
- CRowset.MoveToBookmark
- CRowset<TAccessor>::MoveToBookmark
dev_langs:
- C++
helpviewer_keywords:
- MoveToBookmark method
ms.assetid: 90124723-8daf-4692-ae2f-0db26b5db920
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 9f638f928c9fee0383e5ed50cd4b3dd547ad4939
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="crowsetmovetobookmark"></a>CRowset::MoveToBookmark
Busca a linha marcada por um indicador ou a linha em um deslocamento especificado (`lSkip`) desse indicador.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT MoveToBookmark(const CBookmarkBase& bookmark,   
   LONG lSkip = 0) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `bookmark`  
 [in] Um indicador que marca o local do qual você deseja obter dados.  
  
 `lSkip`  
 [in] A contagem do número de linhas de indicador para a linha de destino. Se `lSkip` for zero, a primeira linha buscada é a linha marcada. Se `lSkip` for 1, a primeira linha buscada é a linha após a linha marcada. Se `lSkip` é -1, a primeira linha buscada é a linha antes da linha indicada.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Esse método requer que a interface opcional `IRowsetLocate`, que talvez não tenha suporte em todos os provedores; se esse for o caso, o método retornará **E_NOINTERFACE**. Você também deve definir **DBPROP_IRowsetLocate** para `VARIANT_TRUE` e defina **DBPROP_CANFETCHBACKWARDS** para `VARIANT_TRUE` antes de chamar **abrir** na tabela ou comando que contém o conjunto de linhas.  
  
 Para obter informações sobre como usar indicadores em clientes, consulte [usando indicadores](../../data/oledb/using-bookmarks.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRowset](../../data/oledb/crowset-class.md)   
 [CRowset::MoveNext](../../data/oledb/crowset-movenext.md)   
 [CRowset::MoveFirst](../../data/oledb/crowset-movefirst.md)   
 [IRowsetLocate::GetRowsAt](https://msdn.microsoft.com/en-us/library/ms723031.aspx)   
 [CRowset::MovePrev](../../data/oledb/crowset-moveprev.md)   
 [CRowset::MoveLast](../../data/oledb/crowset-movelast.md)