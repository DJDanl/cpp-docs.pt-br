---
title: "CAccessorRowset::GetColumnInfo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "GetColumnInfo"
  - "CAccessorRowset.GetColumnInfo"
  - "CAccessorRowset::GetColumnInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetColumnInfo"
ms.assetid: 8ade2388-3c58-43cd-8ed6-499ee0531291
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CAccessorRowset::GetColumnInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém as informações de coluna de conjunto de linhas aberto.  
  
## Sintaxe  
  
```  
  
      HRESULT GetColumnInfo(  
   DBORDINAL* pulColumns,  
   DBCOLUMNINFO** ppColumnInfo,  
   LPOLESTR* ppStrings   
) const;  
HRESULT GetColumnInfo(  
   DBORDINAL* pColumns,  
   DBCOLUMNINFO** ppColumnInfo   
);  
```  
  
#### Parâmetros  
 Consulte [IColumnsInfo::GetColumnInfo](https://msdn.microsoft.com/en-us/library/ms722704.aspx)*na referência do programador de OLE DB*.  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 O usuário deve liberar o buffer retornado e de informações da cadeia de caracteres da coluna.  Use a segunda versão deste método quando você usa [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) e precisa substituir as associações.  
  
 Para obter mais informações, consulte [IColumnsInfo::GetColumnInfo](https://msdn.microsoft.com/en-us/library/ms722704.aspx)*na referência do programador de OLE DB*.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CAccessorRowset](../Topic/CAccessorRowset%20Class.md)