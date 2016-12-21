---
title: "CDynamicAccessor::GetColumnInfo | Microsoft Docs"
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
  - "ATL.CDynamicAccessor.GetColumnInfo"
  - "ATL::CDynamicAccessor::GetColumnInfo"
  - "CDynamicAccessor.GetColumnInfo"
  - "CDynamicAccessor::GetColumnInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetColumnInfo"
ms.assetid: 7f2102ea-b7cc-4714-812f-3ca2857f4b9a
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDynamicAccessor::GetColumnInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna os metadados da coluna necessários para a maioria dos consumidores.  
  
## Sintaxe  
  
```  
  
      HRESULT GetColumnInfo(   
   IRowset* pRowset,   
   DBORDINAL* pColumns,   
   DBCOLUMNINFO** ppColumnInfo,   
   OLECHAR** ppStringsBuffer    
) throw( );  
```  
  
#### Parâmetros  
 `pRowset`  
 \[in\] ponteiro da interface de [IRowset](https://msdn.microsoft.com/en-us/library/ms720986.aspx) .  
  
 *pColumns*  
 \[out\] ponteiro para a memória no qual retornar o número de colunas no conjunto de linhas; esse número inclui a coluna do indicador, se houver.  
  
 *ppColumnInfo*  
 \[out\] ponteiro para a memória no qual uma matriz de **DBCOLUMNINFO** estrutura.  Consulte “estrutura DBCOLUMNINFO” em [IColumnsInfo::GetColumnInfo](https://msdn.microsoft.com/en-us/library/ms722704.aspx)*na referência do programador de OLE DB*.  
  
 `ppStringsBuffer`  
 \[out\] ponteiro para a memória no qual retornar um ponteiro para o armazenamento de todos os valores da cadeia de caracteres \(os nomes usados no *columnid* ou para *o pwszName*\) dentro de um único bloco de alocação.  
  
## Valor de retorno  
 Um dos valores padrão de `HRESULT` .  
  
## Comentários  
 Consulte [IColumnsInfo::GetColumnInfo](https://msdn.microsoft.com/en-us/library/ms722704.aspx)*na referência do programador de OLE DB* para obter informações sobre os tipos de dados **DBORDINAL**, **DBCOLUMNINFO**, e **OLECHAR**.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)