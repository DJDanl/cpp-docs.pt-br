---
title: Estrutura CODBCFieldInfo | Documentos do Microsoft
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
- ODBC, data source information
- CODBCFieldInfo structure
ms.assetid: 92598b4f-facc-4108-b282-63a179ff79ab
caps.latest.revision: 12
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 1080eb323c599014d84acab94aee4622795fdb96
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

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
 O tipo de dados SQL do campo. Isso pode ser um tipo de dados SQL ODBC ou um tipo de dados SQL específica do driver. Para obter uma lista de tipos de dados SQL ODBC válidos, consulte "Tipos de dados SQL" o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Para obter informações sobre tipos de dados SQL específica do driver, consulte a documentação do driver.  
  
 *m_nPrecision*  
 A precisão máxima do campo. Para obter detalhes, consulte "Precisão, escala, comprimento e tamanho de exibição" o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 *m_nScale*  
 A escala do campo. Para obter detalhes, consulte "Precisão, escala, comprimento e tamanho de exibição" o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 *m_nNullability*  
 Se o campo aceita um valor nulo. Isso pode ser um dos dois valores: **SQL_NULLABLE** se o campo aceita valores nulos, ou **SQL_NO_NULLS** se o campo não aceita valores Null.  
  
## <a name="remarks"></a>Comentários  
 Para recuperar essa informação, chamada [CRecordset::GetODBCFieldInfo](../../mfc/reference/crecordset-class.md#getodbcfieldinfo).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CRecordset::GetODBCFieldInfo](../../mfc/reference/crecordset-class.md#getodbcfieldinfo)   
 [CRecordset::GetFieldValue](../../mfc/reference/crecordset-class.md#getfieldvalue)



