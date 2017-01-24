---
title: "CDynamicStringAccessor::SetString | Microsoft Docs"
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
  - "CDynamicStringAccessor::SetString"
  - "CDynamicStringAccessor.SetString"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método SetString"
ms.assetid: 94846d8b-4c1b-47fe-acdc-1752981cee25
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDynamicStringAccessor::SetString
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define os dados de coluna especificados como uma cadeia de caracteres.  
  
## Sintaxe  
  
```  
HRESULT SetString(  
   DBORDINAL nColumn,  
   BaseType* data  
) throw( );  
HRESULT SetString(  
   const CHAR* pColumnName,  
   BaseType* data  
) throw( );  
HRESULT SetString(  
   const WCHAR* pColumnName,  
   BaseType* data  
) throw( );  
```  
  
#### Parâmetros  
 `nColumn`  
 \[in\] o número da coluna.  Início dos números de coluna com 1.  O valor especial de 0 refere\-se à coluna do indicador, se houver.  
  
 `pColumnName`  
 \[in\] de ponteiro para uma cadeia de caracteres que contém o nome da coluna.  
  
 `data`  
 \[in\] ponteiro da os dados de cadeia de caracteres a ser gravados na coluna especificada.  
  
## Valor de retorno  
 Um ponteiro para o valor da cadeia de caracteres a ser definido para a coluna especificada.  O valor é do tipo `BaseType`, que é `CHAR` ou `WCHAR` dependendo se `_UNICODE` estiver definido ou não.  
  
## Comentários  
 O segundo formulário de substituição possui o nome da coluna como uma cadeia de caracteres ANSI e o terceiro formulário de substituição têm o nome da coluna como uma cadeia de caracteres Unicode.  
  
 Se `_SECURE_ATL` é definido para ter um valor diferente de zero, uma falha de asserção de tempo de execução será gerada se a cadeia de caracteres de `data` de entrada for maior que o máximo de comprimento máximo permitido de coluna de dados referenciada.  Caso contrário, a cadeia de caracteres de entrada será truncada se for maior que o máximo de comprimento máximo permitido.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md)