---
title: CXMLAccessor::GetXMLRowData | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CXMLAccessor::GetXMLRowData
- ATL.CXMLAccessor.GetXMLRowData
- CXMLAccessor::GetXMLRowData
- CXMLAccessor.GetXMLRowData
- GetXMLRowData
dev_langs:
- C++
helpviewer_keywords:
- GetXMLRowData method
ms.assetid: 156b66e3-42fd-491c-8943-38cf5e36f687
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 2e356be7a5ab7c125dc92a822384a3e6b02b8f8e
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cxmlaccessorgetxmlrowdata"></a>CXMLAccessor::GetXMLRowData
Recupera todo o conteúdo de uma tabela como dados de cadeia de caracteres formatada em XML, por linha.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT GetXMLRowData(CSimpleStringW& strOutput,   
   bool bAppend = false) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `strOutput`  
 [out] Uma referência a um buffer que contém os dados da tabela a ser recuperado. Os dados são formatados como dados de cadeia de caracteres com nomes de marca XML que correspondem aos nomes de coluna do repositório de dados.  
  
 *bAppend*  
 [in] Um valor booleano que especifica se deve acrescentar uma cadeia de caracteres até o final dos dados de saída.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valores.  
  
## <a name="remarks"></a>Comentários  
 O exemplo a seguir mostra como os dados da linha são formatados em XML. `DATA` abaixo representa os dados de linha. Use mover métodos para ir para a linha desejada.  
  
 `<row>`  
  
 `<column name>DATA</column name>`  
  
 `</row>`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CXMLAccessor](../../data/oledb/cxmlaccessor-class.md)