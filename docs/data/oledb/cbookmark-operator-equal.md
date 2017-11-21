---
title: 'Cbookmark:: Operator = | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CBookmark<0>::operator=
- CBookmark<0>.operator=
- ATL.CBookmark.operator=
- CBookmark::operator=
- ATL.CBookmark<0>.operator=
- ATL::CBookmark<0>::operator=
- CBookmark.operator=
- ATL::CBookmark::operator=
dev_langs: C++
helpviewer_keywords:
- = operator, with OLE DB templates
- operator =, bookmarks
- operator=, bookmarks
ms.assetid: 23805af4-aedd-47ad-bef4-21d902463797
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 4225917ffb57c8c3e792a05c81f81dce1b6009cd
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cbookmarkoperator-"></a>CBookmark::operator =
Atribui um `CBookmark` objeto para outro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      CBookmark& operator =(   
   const CBookmark& bookmark    
) throw( );  
```  
  
## <a name="remarks"></a>Comentários  
 Esse operador é necessária somente em **CBookmark\<0 >**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CBookmark](../../data/oledb/cbookmark-class.md)