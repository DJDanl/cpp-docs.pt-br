---
title: 'Cbulkrowset:: Movetobookmark | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CBulkRowset<TAccessor>::MoveToBookmark
- CBulkRowset.MoveToBookmark
- MoveToBookmark
- ATL.CBulkRowset.MoveToBookmark
- CBulkRowset::MoveToBookmark
- ATL::CBulkRowset<TAccessor>::MoveToBookmark
- ATL::CBulkRowset::MoveToBookmark
dev_langs: C++
helpviewer_keywords: MoveToBookmark method
ms.assetid: 76aab025-819e-4ecd-ae0a-d8d3fb2d2099
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 1671a0b03b3dbc637d83fd1e0f5125bc4abb1f1d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cbulkrowsetmovetobookmark"></a>CBulkRowset::MoveToBookmark
Busca a linha marcada por um indicador ou a linha em um deslocamento especificado (`lSkip`) desse indicador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      HRESULT MoveToBookmark(  
   const CBookmarkBase& bookmark,  
   DBCOUNTITEM lSkip = 0   
) throw( );  
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