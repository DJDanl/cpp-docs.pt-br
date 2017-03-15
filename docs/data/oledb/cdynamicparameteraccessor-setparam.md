---
title: "CDynamicParameterAccessor::SetParam | Microsoft Docs"
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
  - "ATL::CDynamicParameterAccessor::SetParam"
  - "ATL::CDynamicParameterAccessor::SetParam<ctype>"
  - "CDynamicParameterAccessor.SetParam"
  - "ATL.CDynamicParameterAccessor.SetParam"
  - "SetParam"
  - "CDynamicParameterAccessor:SetParam"
  - "CDynamicParameterAccessor::SetParam<ctype>"
  - "CDynamicParameterAccessor::SetParam"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método SetParam"
ms.assetid: e2349220-545c-46ad-90da-9113ac52551a
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDynamicParameterAccessor::SetParam
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define o buffer de parâmetro usando os dados especificados \(diferente de cadeia de caracteres\).  
  
## Sintaxe  
  
```  
  
      template < class   
      ctype >  
bool SetParam(  
   DBORDINAL nParam,  
   const ctype* pData,  
   DBSTATUS status = DBSTATUS_S_OK  
) throw( );  
template < class ctype >  
bool SetParam(  
   TCHAR* pParamName,  
   const ctype* pData,  
   DBSTATUS status = DBSTATUS_S_OK  
) throw( );  
```  
  
#### Parâmetros  
 `ctype`  
 Um parâmetro templated que é o tipo de dados.  
  
 `nParam`  
 \[in\] o número do parâmetro \(deslocamento de 1\).  O parâmetro 0 é reservado para valores de retorno.  O número do parâmetro for o índice do parâmetro com base na ordem de SQL ou na chamada do procedimento armazenado.  Por exemplo:  
  
 [!code-cpp[NVC_OLEDB_Consumer#8](../../data/oledb/codesnippet/CPP/cdynamicparameteraccessor-setparam_1.cpp)]  
  
 `pParamName`  
 \[in\] o nome do parâmetro.  
  
 `pData`  
 \[in\] o ponteiro de memória que contém os dados a serem gravados no buffer.  
  
 *status*  
 \[in\] o status da coluna de `DBSTATUS` .  Para obter informações sobre valores de `DBSTATUS` , consulte [Status](https://msdn.microsoft.com/en-us/library/ms722617.aspx)*na referência do programador do*OLE DB, ou na pesquisa de `DBSTATUS` em oledb.h.  
  
## Valor de retorno  
 Retorna **true** no êxito ou **false** a falha.  
  
 Use `SetParam` para definir dados não de parâmetros no buffer.  Use [SetParamString](../../data/oledb/cdynamicparameteraccessor-setparamstring.md) para definir dados do parâmetro de cadeia de caracteres no buffer.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)