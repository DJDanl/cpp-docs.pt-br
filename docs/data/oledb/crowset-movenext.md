---
title: CRowset::MoveNext | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL.CRowset<TAccessor>.MoveNext
- ATL.CRowset.MoveNext
- ATL::CRowset<TAccessor>::MoveNext
- CRowset<TAccessor>.MoveNext
- CRowset.MoveNext
- CRowset<TAccessor>::MoveNext
- CRowset::MoveNext
- ATL::CRowset::MoveNext
dev_langs:
- C++
helpviewer_keywords:
- MoveNext method
ms.assetid: 0df3288c-2bce-494f-99c0-6344b54a4adf
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 493a9c44a582dc51831f72f54b936c3af1307783
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="crowsetmovenext"></a>CRowset::MoveNext
Move o cursor para o próximo registro.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT MoveNext() throw();HRESULT MoveNext(LONG lSkip,   
   bool bForward= true) throw();  
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
 [CRowset::MoveFirst](../../data/oledb/crowset-movefirst.md)   
 [CRowset::MoveToBookmark](../../data/oledb/crowset-movetobookmark.md)   
 [CRowset::MovePrev](../../data/oledb/crowset-moveprev.md)   
 [CRowset::MoveLast](../../data/oledb/crowset-movelast.md)