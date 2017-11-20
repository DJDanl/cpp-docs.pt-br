---
title: 'Crowset:: Movetobookmark | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL::CRowset::MoveToBookmark
- ATL::CRowset<TAccessor>::MoveToBookmark
- ATL.CRowset.MoveToBookmark
- ATL.CRowset<TAccessor>.MoveToBookmark
- MoveToBookmark
- CRowset::MoveToBookmark
- CRowset.MoveToBookmark
- CRowset<TAccessor>::MoveToBookmark
dev_langs: C++
helpviewer_keywords: MoveToBookmark method
ms.assetid: 90124723-8daf-4692-ae2f-0db26b5db920
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 4edbfd018cadeb47691ac4fd70d5e518f8008f04
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="crowsetmovetobookmark"></a>CRowset::MoveToBookmark
Busca a linha marcada por um indicador ou a linha em um deslocamento especificado (`lSkip`) desse indicador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      HRESULT MoveToBookmark(   
   const CBookmarkBase& bookmark,   
   LONG lSkip = 0    
) throw( );  
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
 [Crowset:: MoveNext](../../data/oledb/crowset-movenext.md)   
 [Crowset:: MoveFirst](../../data/oledb/crowset-movefirst.md)   
 [Irowsetlocate:: Getrowsat](https://msdn.microsoft.com/en-us/library/ms723031.aspx)   
 [Crowset:: Moveprev](../../data/oledb/crowset-moveprev.md)   
 [CRowset::MoveLast](../../data/oledb/crowset-movelast.md)