---
title: "CDynamicParameterAccessor::SetParamString | Microsoft Docs"
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
  - "ATL.CDynamicParameterAccessor.SetParamString"
  - "ATL::CDynamicParameterAccessor::SetParamString"
  - "SetParamString"
  - "CDynamicParameterAccessor::SetParamString"
  - "CDynamicParameterAccessor.SetParamString"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método SetParamString"
ms.assetid: 77a38d23-7e33-4e5a-bda6-c12c4c3fe2e4
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDynamicParameterAccessor::SetParamString
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define os dados de cadeia de caracteres do parâmetro especificado armazenado no buffer.  
  
## Sintaxe  
  
```  
  
      bool SetParamString(   
   DBORDINAL nParam,   
   const CHAR* pString,   
   DBSTATUS status = DBSTATUS_S_OK    
) throw( );  
bool SetParamString(   
   DBORDINAL nParam,   
   const WCHAR* pString,   
   DBSTATUS status = DBSTATUS_S_OK    
) throw( );  
```  
  
#### Parâmetros  
 `nParam`  
 \[in\] o número do parâmetro \(deslocamento de 1\).  O parâmetro 0 é reservado para valores de retorno.  O número do parâmetro for o índice do parâmetro com base na ordem de SQL ou na chamada do procedimento armazenado.  Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
 `pString`  
 \[in\] ponteiro da os dados de cadeia de caracteres ANSI \(**CHAR**\) ou Unicode \(**WCHAR**\) do parâmetro especificado.  Consulte `DBSTATUS` em oledb.h.  
  
 *status*  
 \[in\] o status de `DBSTATUS` do parâmetro especificado.  Para obter informações sobre valores de `DBSTATUS` , consulte [Status](https://msdn.microsoft.com/en-us/library/ms722617.aspx)*na referência do programador do*OLE DB, ou na pesquisa de `DBSTATUS` em oledb.h.  
  
## Comentários  
 Retorna **true** no êxito ou **false** a falha.  
  
 `SetParamString` falhará se você tentar definir uma cadeia de caracteres que seja maior que o tamanho máximo especificado para `pString`.  
  
 Use `SetParamString` para definir dados do parâmetro de cadeia de caracteres no buffer.  Use [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para definir dados não de parâmetros no buffer.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)