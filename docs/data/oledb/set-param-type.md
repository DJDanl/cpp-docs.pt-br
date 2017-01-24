---
title: "SET_PARAM_TYPE | Microsoft Docs"
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
  - "SET_PARAM_TYPE"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro SET_PARAM_TYPE"
ms.assetid: 85979070-2d55-4c67-94b1-9b9058babc59
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# SET_PARAM_TYPE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica `COLUMN_ENTRY` macros que seguem o `SET_PARAM_TYPE` macro entrada, saída ou entrada\/saída.  
  
## Sintaxe  
  
```  
  
SET_PARAM_TYPE(  
type  
 )  
  
```  
  
#### Parâmetros  
 `type`  
 \[in\] O tipo para definir o parâmetro.  
  
## Comentários  
 Provedores oferecem suporte apenas tipos de entrada\/saída parâmetros que são suportados pela fonte de dados subjacente. O tipo é uma combinação de um ou mais **DBPARAMIO** valores \(consulte [estruturas DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx) no *referência do programador DB OLE*\):  
  
-   **DBPARAMIO\_NOTPARAM** o acessador não tem parâmetros. Normalmente, você define **eParamIO** para esse valor nos acessadores de linha para lembrar o usuário que os parâmetros são ignorados.  
  
-   **DBPARAMIO\_INPUT** um parâmetro de entrada.  
  
-   **DBPARAMIO\_OUTPUT** um parâmetro de saída.  
  
-   **DBPARAMIO\_INPUT &#124; DBPARAMIO\_OUTPUT** o parâmetro é de entrada e um parâmetro de saída.  
  
## Exemplo  
 [!CODE [NVC_OLEDB_Consumer#18](../CodeSnippet/VS_Snippets_Cpp/NVC_OLEDB_Consumer#18)]  
  
## Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## Consulte também  
 [Macros e funções globais para modelos de consumidor de banco de dados OLE](../Topic/Macros%20and%20Global%20Functions%20for%20OLE%20DB%20Consumer%20Templates.md)