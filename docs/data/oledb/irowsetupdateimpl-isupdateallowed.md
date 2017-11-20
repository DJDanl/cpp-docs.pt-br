---
title: 'Irowsetupdateimpl:: Isupdateallowed | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IRowsetUpdateImpl::IsUpdateAllowed
- IRowsetUpdateImpl.IsUpdateAllowed
- IsUpdateAllowed
dev_langs: C++
helpviewer_keywords: IsUpdateAllowed method
ms.assetid: d6daf3b3-a8e0-4275-a67d-897dea01e297
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: feaa5b397989667da62bbf979603391c08eada2c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="irowsetupdateimplisupdateallowed"></a>IRowsetUpdateImpl::IsUpdateAllowed
Substitua este método para verificar a segurança, integridade e assim por diante antes das atualizações.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      HRESULT IsUpdateAllowed(  
   DBPENDINGSTATUS /* [in] *//* status */,  
   HROW /* [in] *//* hRowUpdate */,  
   DBROWSTATUS* /* [out] *//* pRowStatus */  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *status*  
 [in] O status de operações pendentes nas linhas.  
  
 *hRowUpdate*  
 [in] Identificador para as linhas que o usuário deseja atualizar.  
  
 *pRowStatus*  
 [out] O status retornado para o usuário.  
  
## <a name="remarks"></a>Comentários  
 Se você determinar que uma atualização deve ser permitida, retorna `S_OK`; caso contrário, retornará **E_FAIL**. Se você permitir que uma atualização, você também precisará definir o **DBROWSTATUS** na [irowsetupdateimpl:: Update](../../data/oledb/irowsetupdateimpl-update.md) com um número apropriado [linha estado](https://msdn.microsoft.com/en-us/library/ms722752.aspx).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IRowsetUpdateImpl](../../data/oledb/irowsetupdateimpl-class.md)