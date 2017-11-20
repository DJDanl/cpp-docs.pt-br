---
title: 'Crowset:: MoveNext | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL.CRowset<TAccessor>.MoveNext
- ATL.CRowset.MoveNext
- ATL::CRowset<TAccessor>::MoveNext
- CRowset<TAccessor>.MoveNext
- CRowset.MoveNext
- CRowset<TAccessor>::MoveNext
- CRowset::MoveNext
- ATL::CRowset::MoveNext
dev_langs: C++
helpviewer_keywords: MoveNext method
ms.assetid: 0df3288c-2bce-494f-99c0-6344b54a4adf
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: e2b0a3a3a10ae2cc18ab83800cc50f25903a3607
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="crowsetmovenext"></a>CRowset::MoveNext
Move o cursor para o próximo registro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      HRESULT MoveNext( ) throw( );   
HRESULT MoveNext(   
   LONG lSkip,   
   bool bForward = true    
) throw( );  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `lSkip`  
 [in] O número de linhas a serem ignoradas antes de buscar.  
  
 `bForward`  
 [in] Passar **true** avance para o próximo registro, **false** para retroceder.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`. Quando for atingido o fim do conjunto de linhas, retorna **DB_S_ENDOFROWSET**.  
  
## <a name="remarks"></a>Comentários  
 Busca a próxima linha sequencial do `CRowset` objeto, lembre-se a posição anterior. Opcionalmente, você pode optar por ignorar `lSkip` linhas ou mover para trás.  
  
 Esse método requer que você defina as propriedades a seguir antes de chamar **abrir** na tabela ou que contém o conjunto de linhas de comando:  
  
-   **DBPROP_CANSCROLLBACKWARDS** devem ser `VARIANT_TRUE` se `lSkip` < 0  
  
-   **DBPROP_CANFETCHBACKWARDS** devem ser `VARIANT_TRUE` se `bForward` = false  
  
 Caso contrário (se `lSkip` > = 0 e `bForward` = true), você não precisa definir as propriedades adicionais.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRowset](../../data/oledb/crowset-class.md)   
 [Crowset:: MoveFirst](../../data/oledb/crowset-movefirst.md)   
 [Crowset:: Movetobookmark](../../data/oledb/crowset-movetobookmark.md)   
 [Crowset:: Moveprev](../../data/oledb/crowset-moveprev.md)   
 [CRowset::MoveLast](../../data/oledb/crowset-movelast.md)