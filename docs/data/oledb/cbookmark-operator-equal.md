---
title: 'Cbookmark:: Operator = | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CBookmark<0>::operator=
- CBookmark<0>.operator=
- ATL.CBookmark.operator=
- CBookmark::operator=
- ATL.CBookmark<0>.operator=
- ATL::CBookmark<0>::operator=
- CBookmark.operator=
- ATL::CBookmark::operator=
dev_langs:
- C++
helpviewer_keywords:
- = operator, with OLE DB templates
- operator =, bookmarks
- operator=, bookmarks
ms.assetid: 23805af4-aedd-47ad-bef4-21d902463797
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: e8ce68afa83694b3471223e32b1b629075665599
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cbookmarkoperator-"></a>CBookmark::operator =
Atribui um `CBookmark` objeto para outro.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      CBookmark& operator =(const CBookmark& bookmark) throw();  
```  
  
## <a name="remarks"></a>Comentários  
 Esse operador é necessária somente em **CBookmark\<0 >**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CBookmark](../../data/oledb/cbookmark-class.md)