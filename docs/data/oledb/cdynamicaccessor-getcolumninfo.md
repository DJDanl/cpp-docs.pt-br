---
title: CDynamicAccessor::GetColumnInfo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- GetColumnInfo
- ATL.CDynamicAccessor.GetColumnInfo
- ATL::CDynamicAccessor::GetColumnInfo
- CDynamicAccessor.GetColumnInfo
- CDynamicAccessor::GetColumnInfo
dev_langs:
- C++
helpviewer_keywords:
- GetColumnInfo method
ms.assetid: 7f2102ea-b7cc-4714-812f-3ca2857f4b9a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: a9f311e9fc5330a68edba4fd5029e97b75033406
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cdynamicaccessorgetcolumninfo"></a>CDynamicAccessor::GetColumnInfo
Retorna os metadados de coluna necessários para a maioria dos consumidores.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT GetColumnInfo(IRowset* pRowset,   
   DBORDINAL* pColumns,   
   DBCOLUMNINFO** ppColumnInfo,   
   OLECHAR** ppStringsBuffer) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pRowset`  
 [in] Um ponteiro para o [IRowset](https://msdn.microsoft.com/en-us/library/ms720986.aspx) interface.  
  
 *pColumns*  
 [out] Um ponteiro de memória no qual retornar o número de colunas no conjunto de linhas; Esse número inclui a coluna de indicador, se houver um.  
  
 *ppColumnInfo*  
 [out] Um ponteiro de memória no qual retornar uma matriz de **DBCOLUMNINFO** estruturas. Consulte "Estruturas DBCOLUMNINFO" [icolumnsinfo:: Getcolumninfo](https://msdn.microsoft.com/en-us/library/ms722704.aspx) no *referência do programador de OLE DB*.  
  
 `ppStringsBuffer`  
 [out] Um ponteiro de memória no qual retornar um ponteiro para o armazenamento de todos os valores de cadeia de caracteres (nomes usados nos *columnid* ou *pwszName*) dentro de um único bloco de alocação.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valores.  
  
## <a name="remarks"></a>Comentários  
 Consulte [icolumnsinfo:: Getcolumninfo](https://msdn.microsoft.com/en-us/library/ms722704.aspx) no *referência do programador de DB OLE* para obter informações sobre os tipos de dados **DBORDINAL**, **DBCOLUMNINFO**, e **OLECHAR**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)