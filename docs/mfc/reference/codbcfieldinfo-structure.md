---
title: Estrutura CODBCFieldInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CODBCFieldInfo
dev_langs:
- C++
helpviewer_keywords:
- ODBC [MFC], data source information
- CODBCFieldInfo structure [MFC]
ms.assetid: 92598b4f-facc-4108-b282-63a179ff79ab
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c1723e93320129fae232bb850caa123d1638a37b
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37853076"
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
 *m_strName*  
 O nome do campo.  
  
 *m_nSQLType*  
 O tipo de dados SQL do campo. Isso pode ser um tipo de dados SQL ODBC ou um tipo de dados SQL específica do driver. Para obter uma lista dos tipos de dados SQL ODBC válidos, consulte "Tipos de dados SQL" no SDK do Windows. Para obter informações sobre tipos de dados SQL específico do driver, consulte a documentação do driver.  
  
 *m_nPrecision*  
 A precisão máxima do campo. Para obter detalhes, consulte "Precisão, escala, comprimento e tamanho de exibição" no SDK do Windows.  
  
 *m_nScale*  
 A escala do campo. Para obter detalhes, consulte "Precisão, escala, comprimento e tamanho de exibição" no SDK do Windows.  
  
 *m_nNullability*  
 Se o campo aceita um valor Null. Isso pode ser um dos dois valores: SQL_NULLABLE se o campo aceita valores nulos, SQL_NO_NULLS se o campo não aceita valores nulos ou.  
  
## <a name="remarks"></a>Comentários  
 Para recuperar essas informações, chame [CRecordset::GetODBCFieldInfo](../../mfc/reference/crecordset-class.md#getodbcfieldinfo).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CRecordset::GetODBCFieldInfo](../../mfc/reference/crecordset-class.md#getodbcfieldinfo)   
 [CRecordset::GetFieldValue](../../mfc/reference/crecordset-class.md#getfieldvalue)


