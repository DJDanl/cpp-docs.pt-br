---
title: "Estrutura CODBCFieldInfo | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CODBCFieldInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura CODBCFieldInfo"
  - "ODBC, informações de fonte de dados"
ms.assetid: 92598b4f-facc-4108-b282-63a179ff79ab
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura CODBCFieldInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `CODBCFieldInfo` contém informações sobre os campos em uma fonte de dados ODBC.  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 `m_strName`  
 O nome do campo.  
  
 *m\_nSQLType*  
 O tipo de dados SQL do campo.  Esse pode ser um tipo de dados ODBC SQL ou um tipo de dados específicos de driver do SQL.  Para obter uma lista de tipos de dados válidos ODBC SQL, consulte “tipos de dados SQL” em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  Para obter informações sobre os tipos de dados específicos de driver do SQL, consulte a documentação do driver.  
  
 *m\_nPrecision*  
 A precisão máxima do campo.  Para obter detalhes, consulte “precisão, escala, comprimento, e o tamanho da exibição” em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 *m\_nScale*  
 A escala do campo.  Para obter detalhes, consulte “precisão, escala, comprimento, e o tamanho da exibição” em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 *m\_nNullability*  
 Se o campo aceitar um valor nulo.  Esse pode ser um destes dois valores: **SQL\_NULLABLE** se o campo aceita valores nulos, ou **SQL\_NO\_NULLS** se o campo não aceita valores nulos.  
  
## Comentários  
 Para recuperar essas informações, chame [CRecordset::GetODBCFieldInfo](../Topic/CRecordset::GetODBCFieldInfo.md).  
  
## Requisitos  
 **Header:** afxdb.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CRecordset::GetODBCFieldInfo](../Topic/CRecordset::GetODBCFieldInfo.md)   
 [CRecordset::GetFieldValue](../Topic/CRecordset::GetFieldValue.md)