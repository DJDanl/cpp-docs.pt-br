---
title: CDynamicAccessor::GetColumnFlags | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CDynamicAccessor.GetColumnFlags
- ATL::CDynamicAccessor::GetColumnFlags
- ATL.CDynamicAccessor.GetColumnFlags
- CDynamicAccessor::GetColumnFlags
- GetColumnFlags
dev_langs:
- C++
helpviewer_keywords:
- GetColumnFlags method
ms.assetid: b2ba2f3a-2c61-4a49-abfb-75823908ccf4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 9cb4e439ab650793dcbafa79092d03b53271e45a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33094690"
---
# <a name="cdynamicaccessorgetcolumnflags"></a>CDynamicAccessor::GetColumnFlags
Recupera as características da coluna.  
  
## <a name="syntax"></a>Sintaxe  
  
```
bool GetColumnFlags(DBORDINAL nColumn,   
  DBCOLUMNFLAGS* pFlags) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nColumn`  
 [in] O número da coluna. Coluna de números começam com 1. Um valor de 0 se refere à coluna de indicador, se houver.  
  
 `pFlags`  
 [out] Um ponteiro para uma máscara de bits que descreve as características da coluna. Consulte "Tipo enumerado DBCOLUMNFLAGS" [icolumnsinfo:: Getcolumninfo](https://msdn.microsoft.com/en-us/library/ms722704.aspx) no *referência do programador de OLE DB*.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna **true** se as características de coluna são recuperadas com êxito. Caso contrário, retornará **false**.  
  
## <a name="remarks"></a>Comentários  
 O número da coluna é deslocado de um. Coluna zero é um caso especial; é o indicador se disponível.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)