---
title: 'Crowset:: SetData | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL.CRowset<TAccessor>.SetData
- SetData
- ATL::CRowset::SetData
- CRowset<TAccessor>.SetData
- CRowset::SetData
- ATL.CRowset.SetData
- CRowset.SetData
- CRowset<TAccessor>::SetData
- ATL::CRowset<TAccessor>::SetData
dev_langs: C++
helpviewer_keywords: SetData method
ms.assetid: 68125142-8510-4132-9393-e39efd39c784
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 0aafc521e130a7f737083390fe5f825c88aa5844
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="crowsetsetdata"></a>CRowset::SetData
Define valores de dados em uma ou mais colunas de uma linha.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      HRESULT SetData( ) const throw( );   
HRESULT SetData(  
   int nAccessor   
) const throw( );  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nAccessor`  
 [in] O número de acessador a ser usado para acessar os dados.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Para o `SetData` formulário que aceita nenhum argumento, todos os acessadores são usadas para a atualização. Normalmente você chama **SetData** para definir valores de dados em colunas em uma linha, em seguida, chame [atualização](../../data/oledb/crowset-update.md) para transmitir as alterações.  
  
 Esse método requer que a interface opcional `IRowsetChange`, que talvez não tenha suporte em todos os provedores; se esse for o caso, o método retornará **E_NOINTERFACE**. Você também deve definir **DBPROP_IRowsetChange** para `VARIANT_TRUE` antes de chamar **abrir** na tabela ou que contém o conjunto de linhas de comando.  
  
 A operação de configuração pode falhar se uma ou mais colunas não é gravável. Modifique seu mapa de cursor para corrigir o problema.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRowset](../../data/oledb/crowset-class.md)   
 [CRowset::Update](../../data/oledb/crowset-update.md)