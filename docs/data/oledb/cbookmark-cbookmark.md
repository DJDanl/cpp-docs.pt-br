---
title: 'Cbookmark:: Cbookmark | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
dev_langs: C++
helpviewer_keywords: CBookmark class, constructor
ms.assetid: 84f4ad2b-67d4-4ba3-8b2b-656a66fb6298
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: d0b38e91830157621835ad12edaeb37c24b8e11d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cbookmarkcbookmark"></a>CBookmark::CBookmark
O construtor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      CBookmark( );   
CBookmark(  
   DBLENGTH nSize   
);  
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