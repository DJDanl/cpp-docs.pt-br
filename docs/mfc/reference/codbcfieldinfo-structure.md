---
title: Estrutura CODBCFieldInfo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CODBCFieldInfo
dev_langs:
- C++
helpviewer_keywords:
- ODBC [MFC], data source information
- CODBCFieldInfo structure [MFC]
ms.assetid: 92598b4f-facc-4108-b282-63a179ff79ab
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5b2b5d707b9915aa0d5e3fd1362746fe30a99a22
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="codbcfieldinfo-structure"></a>Estrutura CODBCFieldInfo
O `CODBCFieldInfo` estrutura contém informações sobre os campos em uma fonte de dados ODBC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct CODBCFieldInfo  
{  
    CString m_strName;  
    SWORD m_nSQLType;  
    UDWORD m_nPrecision;  
    SWORD m_nScale;  
    SWORD m_nNullability;  
};  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `m_strName`  
 O nome do campo.  
  
 *m_nSQLType*  
 O tipo de dados SQL do campo. Isso pode ser um tipo de dados SQL ODBC ou um tipo de dados SQL específico do driver. Para obter uma lista de tipos de dados ODBC SQL válidos, consulte "Tipos de dados SQL" no SDK do Windows. Para obter informações sobre tipos de dados SQL específico do driver, consulte a documentação do driver.  
  
 *m_nPrecision*  
 A precisão máxima do campo. Para obter detalhes, consulte "Precisão, escala, comprimento e tamanho de exibição" no SDK do Windows.  
  
 *m_nScale*  
 A escala do campo. Para obter detalhes, consulte "Precisão, escala, comprimento e tamanho de exibição" no SDK do Windows.  
  
 *m_nNullability*  
 Se o campo aceita um valor nulo. Isso pode ser um dos dois valores: **SQL_NULLABLE** se o campo aceita valores nulos, ou **SQL_NO_NULLS** se o campo não aceita valores Null.  
  
## <a name="remarks"></a>Comentários  
 Para recuperar essas informações, chame [CRecordset::GetODBCFieldInfo](../../mfc/reference/crecordset-class.md#getodbcfieldinfo).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CRecordset::GetODBCFieldInfo](../../mfc/reference/crecordset-class.md#getodbcfieldinfo)   
 [CRecordset::GetFieldValue](../../mfc/reference/crecordset-class.md#getfieldvalue)


