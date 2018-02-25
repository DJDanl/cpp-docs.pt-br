---
title: CDynamicParameterAccessor::CDynamicParameterAccessor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDynamicParameterAccessor::CDynamicParameterAccessor
- CDynamicParameterAccessor.CDynamicParameterAccessor
dev_langs:
- C++
helpviewer_keywords:
- CDynamicParameterAccessor class, constructor
- CDynamicParameterAccessor method
ms.assetid: a1cce5e4-dfb9-43a2-bfb8-0435c653674a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: e9befa8128aa54f300e5e7c8ff4b225f517e2fc0
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cdynamicparameteraccessorcdynamicparameteraccessor"></a>CDynamicParameterAccessor::CDynamicParameterAccessor
O construtor.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      typedef CDynamicParameterAccessor _ParamClass;  
CDynamicParameterAccessor(DBBLOBHANDLINGENUM eBlobHandling = DBBLOBHANDLING_DEFAULT,   
   DBLENGTH nBlobSize = 8000 )   
   : CDynamicAccessor(eBlobHandling, nBlobSize )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `eBlobHandling`  
 Especifica como os dados BLOB deve ser tratada. O valor padrão é **DBBLOBHANDLING_DEFAULT**. Consulte [cdynamicaccessor:: Setblobhandling](../../data/oledb/cdynamicaccessor-setblobhandling.md) para obter uma descrição de **DBBLOBHANDLINGENUM** valores.  
  
 `nBlobSize`  
 O tamanho máximo do BLOB em bytes. dados de coluna sobre esse valor são tratados como um BLOB. O valor padrão é de 8.000. Consulte [cdynamicaccessor:: Setblobsizelimit](../../data/oledb/cdynamicaccessor-setblobsizelimit.md) para obter detalhes.  
  
## <a name="remarks"></a>Comentários  
 Consulte o [cdynamicaccessor:: Cdynamicaccessor](../../data/oledb/cdynamicaccessor-cdynamicaccessor.md) construtor para obter mais informações sobre tratamento de BLOB.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)