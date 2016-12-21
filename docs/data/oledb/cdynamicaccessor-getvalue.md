---
title: "CDynamicAccessor::GetValue | Microsoft Docs"
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
  - "GetValue"
  - "CDynamicAccessor::GetValue<ctype>"
  - "ATL.CDynamicAccessor.GetValue<ctype>"
  - "CDynamicAccessor.GetValue"
  - "CDynamicAccessor::GetValue"
  - "ATL.CDynamicAccessor.GetValue"
  - "ATL::CDynamicAccessor::GetValue"
  - "ATL::CDynamicAccessor::GetValue<ctype>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetValue"
ms.assetid: 553f44af-68bc-4cb6-8774-e0940003fa90
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDynamicAccessor::GetValue
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera os dados para uma coluna especificada.  
  
## Sintaxe  
  
```  
  
      void* GetValue(   
   DBORDINAL nColumn    
) const throw( );  
void* GetValue(  
   const CHAR* pColumnName   
) const throw( );  
void* GetValue(  
   const WCHAR* pColumnName   
) const throw( );  
template < class ctype >  
bool GetValue(  
   DBORDINAL nColumn,  
   ctype* pData   
) const throw( );  
template < class ctype >  
bool GetValue(  
   const CHAR* pColumnName,  
   ctype* pData   
) const throw( );  
template < class ctype >  
bool GetValue(  
   const WCHAR* pColumnName,  
   ctype* pData   
) const throw( );  
```  
  
#### Parâmetros  
 `ctype`  
 \[in\] A templated o parâmetro que trata qualquer tipo de dados diferente que a cadeia de caracteres digitar \(**CHAR\***, **WCHAR\***\), que exigem tratamento especial.  `GetValue` usa o tipo de dados apropriado com base no que você especifica aqui.  
  
 `nColumn`  
 \[in\] o número da coluna.  Início dos números de coluna com 1.  Um valor de 0 se refere à coluna do indicador, se houver.  
  
 `pColumnName`  
 \[in\] o nome da coluna.  
  
 `pData`  
 \[out\] o ponteiro ao conteúdo da coluna especificada.  
  
## Valor de retorno  
 Se você quiser passar dados de cadeia de caracteres, use as versões nontemplated de `GetValue`.  As versões nontemplated esse método retorna **void\***, que aponta para a parte do buffer que contém os dados de coluna especificados.  Retorna **nulo** se a coluna não foi encontrada.  
  
 Para todos os outros tipos de dados, é mais simples usar as versões templated de `GetValue`.  As versões templated retornam **true** no êxito ou **false** a falha.  
  
## Comentários  
 Use as versões nontemplated para retornar as colunas que contêm cadeias de caracteres e as versões templated para colunas que contêm outros tipos de dados.  
  
 No modo de depuração, você obterá uma asserção se o tamanho de `pData` é diferente para o tamanho da coluna apontados por.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)