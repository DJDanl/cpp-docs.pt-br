---
title: "CDynamicParameterAccessor::GetParamString | Microsoft Docs"
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
  - "CDynamicParameterAccessor.GetParamString"
  - "GetParamString"
  - "CDynamicParameterAccessor::GetParamString"
  - "ATL.CDynamicParameterAccessor.GetParamString"
  - "ATL::CDynamicParameterAccessor::GetParamString"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetParamString"
ms.assetid: 078c2b1c-7072-47c1-a203-f47e75363f91
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDynamicParameterAccessor::GetParamString
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera os dados de cadeia de caracteres do parâmetro especificado armazenado no buffer.  
  
## Sintaxe  
  
```  
  
      bool GetParamString(  
   DBORDINAL nParam,  
   CSimpleStringA& strOutput  
) throw( );  
bool GetParamString(  
   DBORDINAL nParam,  
   CSimpleStringW& strOutput  
) throw( );  
bool GetParamString(  
   DBORDINAL nParam,  
   CHAR* pBuffer,  
   size_t* pMaxLen  
) throw( );  
bool GetParamString(  
   DBORDINAL nParam,  
   WCHAR* pBuffer,  
   size_t* pMaxLen  
) throw( );  
```  
  
#### Parâmetros  
 `nParam`  
 \[in\] o número do parâmetro \(deslocamento de 1\).  O parâmetro 0 é reservado para valores de retorno.  O número do parâmetro for o índice do parâmetro com base na ordem de SQL ou na chamada do procedimento armazenado.  Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
 `strOutput`  
 \[out\] os dados de cadeia de caracteres ANSI \(**CSimpleStringA**\) ou Unicode \(**CSimpleStringW**\) do parâmetro especificado.  Você deve transmitir um parâmetro de tipo `CString`, por exemplo:  
  
 [!code-cpp[NVC_OLEDB_Consumer#9](../../data/oledb/codesnippet/CPP/cdynamicparameteraccessor-getparamstring_1.cpp)]  
  
 `pBuffer`  
 \[out\] ponteiro da os dados de cadeia de caracteres ANSI \(**CHAR**\) ou Unicode \(**WCHAR**\) do parâmetro especificado.  
  
 `pMaxLen`  
 \[out\] ponteiro da o tamanho do buffer apontado por `pBuffer` \(em caracteres, incluindo o encerramento NULL\).  
  
## Comentários  
 Retorna **true** no êxito ou **false** a falha.  
  
 Se `pBuffer` for NULL, esse método definirá o tamanho de buffer necessário na memória apontada por `pMaxLen` e a **true** de retorno sem copiar os dados.  
  
 Esse método `pBuffer` falhará se o buffer não seja grande o suficiente para conter a cadeia de caracteres inteira.  
  
 Use `GetParamString` para recuperar dados do parâmetro de cadeia de caracteres de buffer.  Use [GetParam](../Topic/CDynamicParameterAccessor::GetParam.md) para recuperar dados não do parâmetro de buffer.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)