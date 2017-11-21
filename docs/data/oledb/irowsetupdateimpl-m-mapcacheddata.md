---
title: 'Irowsetupdateimpl:: M_mapcacheddata | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IRowsetUpdateImpl.m_mapCachedData
- IRowsetUpdateImpl::m_mapCachedData
- m_mapCachedData
dev_langs: C++
helpviewer_keywords: m_mapCachedData
ms.assetid: 65131743-8580-48c8-bb22-68f17c9dfa13
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 6007498d85160124484860726d09523b9340bd14
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="irowsetupdateimplmmapcacheddata"></a>IRowsetUpdateImpl::m_mapCachedData
Um mapa que contém os dados originais para a operação adiada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      CAtlMap<   
   HROW hRow,    
   Storage* pData   
>   
m_mapCachedData;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `hRow`  
 Identificador para as linhas de dados.  
  
 `pData`  
 Um ponteiro para os dados sejam armazenados em cache. Os dados são do tipo *armazenamento* (a classe de registro de usuário). Consulte o *armazenamento* argumento de modelo em [classe IRowsetUpdateImpl](../../data/oledb/irowsetupdateimpl-class.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IRowsetUpdateImpl](../../data/oledb/irowsetupdateimpl-class.md)