---
title: CXMLAccessor::GetXMLColumnData | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL.CXMLAccessor.GetXMLColumnData
- CXMLAccessor::GetXMLColumnData
- CXMLAccessor.GetXMLColumnData
- ATL::CXMLAccessor::GetXMLColumnData
- GetXMLColumnData
dev_langs:
- C++
helpviewer_keywords:
- GetXMLColumnData method
ms.assetid: 719e8efe-8758-4af7-a855-0e44ea196546
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ad3921a25e01f3269fe50f37fbc227a60e12cb43
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33100649"
---
# <a name="cxmlaccessorgetxmlcolumndata"></a>CXMLAccessor::GetXMLColumnData
Recupera as informações de tipo de coluna de uma tabela como dados de cadeia de caracteres formatada em XML, por coluna.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT GetXMLColumnData(CSimpleStringW& strOutput) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `strOutput`  
 [out] Uma referência a um buffer de cadeia de caracteres que contém as informações de tipo de coluna a ser recuperado. A cadeia de caracteres é formatada com nomes de marca XML que correspondem aos nomes de coluna do repositório de dados.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valores.  
  
## <a name="remarks"></a>Comentários  
 O exemplo a seguir mostra como as informações de tipo de coluna são formatadas em XML. `type` Especifica o tipo de dados da coluna. Observe que os tipos de dados são baseados em tipos de dados OLE DB, não os do banco de dados que está sendo acessado.  
  
 `<columninfo>`  
  
 `<column type = I2/> ColumnName`  
  
 `</columninfo>`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CXMLAccessor](../../data/oledb/cxmlaccessor-class.md)