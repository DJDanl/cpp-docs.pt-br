---
title: "CDynamicAccessor::SetValue | Microsoft Docs"
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
  - "ATL.CDynamicAccessor.SetValue"
  - "ATL::CDynamicAccessor::SetValue"
  - "ATL::CDynamicAccessor::SetValue<ctype>"
  - "CDynamicAccessor.SetValue"
  - "ATL.CDynamicAccessor.SetValue<ctype>"
  - "CDynamicAccessor::SetValue"
  - "CDynamicAccessor::SetValue<ctype>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método SetValue"
ms.assetid: ecc18850-96e5-4845-abe5-ab34ad467238
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDynamicAccessor::SetValue
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Armazena dados para uma coluna especificada.  
  
## Sintaxe  
  
```  
  
      template < class ctype >    
bool SetValue(   
   DBORDINAL nColumn,   
   const ctype& data    
) throw( );  
template < class ctype >    
bool SetValue(   
   const CHAR * pColumnName,   
   const ctype& data    
) throw( );  
template <class ctype>   
bool SetValue(  
   const WCHAR *pColumnName,  
   const ctype& data   
) throw( );  
```  
  
#### Parâmetros  
 `ctype`  
 \[in\] A templated o parâmetro que trata qualquer tipo de dados diferente que a cadeia de caracteres digitar \(**CHAR\***, **WCHAR\***\), que exigem tratamento especial.  `GetValue` usa o tipo de dados apropriado com base no que você especifica aqui.  
  
 `pColumnName`  
 \[in\] de ponteiro para uma cadeia de caracteres que contém o nome da coluna.  
  
 `data`  
 \[in\] o ponteiro de memória que contém os dados.  
  
 `nColumn`  
 \[in\] o número da coluna.  Início dos números de coluna com 1.  Um valor de 0 se refere à coluna do indicador, se houver.  
  
## Valor de retorno  
 Se você quiser definir dados de cadeia de caracteres, use as versões nontemplated de `GetValue`.  As versões nontemplated esse método retorna **void\***, que aponta para a parte do buffer que contém os dados de coluna especificados.  Retorna **nulo** se a coluna não foi encontrada.  
  
 Para todos os outros tipos de dados, é mais simples usar as versões templated de `GetValue`.  As versões templated retornam **true** no êxito ou **false** a falha.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)