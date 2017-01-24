---
title: "Classe CNoRowset | Microsoft Docs"
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
  - "ATL.CNoRowset"
  - "ATL::CNoRowset<TAccessor>"
  - "CNoRowset"
  - "ATL.CNoRowset<TAccessor>"
  - "ATL::CNoRowset"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CNoRowset"
ms.assetid: 55c6c7a4-9e3a-4775-a2dd-c8b333012fa6
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CNoRowset
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Pode ser usado como um argumento de modelo \(`TRowset`\) para [CCommand](../../data/oledb/ccommand-class.md) ou [CTable](../../data/oledb/ctable-class.md).  
  
## Sintaxe  
  
```  
template <class TAccessor = CAccessorBase>  
class CNoRowset  
```  
  
#### Parâmetros  
 `TAccessor`  
 Uma classe do acessador.  O padrão é `CAccessorBase`.  
  
## Comentários  
 Use `CNoRowset` como um argumento de modelo se o comando não retorna um conjunto de linhas.  
  
 `CNoRowset` implementa os métodos de stub, que correspondem a outros métodos da classe do acessador:  
  
-   **BindFinished** \- indica quando a associação for concluída \(\) retorna `S_OK`.  
  
-   **Fechar** \- Linhas das versões e a interface IRowset atual.  
  
-   `GetIID` \- recupera a ID da interface de um ponto de conexão.  
  
-   **GetInterface** \- recupera uma interface.  
  
-   `GetInterfacePtr` \- recupera um ponteiro encapsulado da interface.  
  
-   **SetAccessor** \- define um ponteiro para o acessador.  
  
-   **SetupOptionalRowsetInterfaces** \- configura as interfaces opcionais para o conjunto de linhas.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)