---
title: 'Cbookmark:: Cbookmark | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CBookmark<0>.CBookmark<0>
- CBookmark::CBookmark
- ATL.CBookmark.CBookmark
- CBookmark.CBookmark
- CBookmark
- ATL::CBookmark<0>::CBookmark<0>
- ATL.CBookmark<0>.CBookmark<0>
- CBookmark<0>::CBookmark<0>
- ATL::CBookmark::CBookmark
dev_langs:
- C++
helpviewer_keywords:
- CBookmark class, constructor
ms.assetid: 84f4ad2b-67d4-4ba3-8b2b-656a66fb6298
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f7663c34fc9eea5f4262fea6b347c1b7899ace85
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33095229"
---
# <a name="cbookmarkcbookmark"></a>CBookmark::CBookmark
O construtor.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      CBookmark();   

CBookmark(DBLENGTH nSize);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nSize`  
 [in] Tamanho do buffer indicador em bytes.  
  
## <a name="remarks"></a>Comentários  
 A primeira função define o buffer **nulo** e o tamanho do buffer para 0. A segunda função define o tamanho do buffer `nSize`e o buffer de uma matriz de bytes `nSize` bytes.  
  
> [!NOTE]
>  Essa função só está disponível em **CBookmark\<0 >**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CBookmark](../../data/oledb/cbookmark-class.md)