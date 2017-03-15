---
title: "Classe CColumnAccessor | Microsoft Docs"
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
  - "CColumnAccessor"
  - "ATL::CColumnAccessor"
  - "ATL.CColumnAccessor"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CColumnAccessor"
ms.assetid: 6ce1e67f-6a20-490d-9326-c168b43eee7e
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CColumnAccessor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Generates injetou o código do consumidor.  
  
## Sintaxe  
  
```  
class CColumnAccessor : public CAccessorBase  
```  
  
## Comentários  
 No código SQL injetado, cada coluna é associada como um acessador separado.  Lembre\-se de que essa classe é usada no código SQL injetado \(por exemplo, você pode localizar o durante a depuração\), mas normalmente você nunca deve usar o ou seus métodos diretamente.  
  
 `CColumnAccessor` implementa os métodos de stub, que correspondem à funcionalidade a outros métodos da classe do acessador:  
  
-   `CColumnAccessor` o construtor; cria uma instância e inicializa o objeto de `CColumnAccessor` .  
  
-   `CreateAccessor` aloca memória para as estruturas da associação de coluna e inicializa os membros de dados da coluna.  
  
-   Colunas de associações de**BindColumns**aos acessadores.  
  
-   **SetParameterBuffer** aloca buffers para parâmetros.  
  
-   `AddParameter` adiciona uma entrada de parâmetro para as estruturas de entrada de parâmetro.  
  
-   **HasOutputColumns** determina se o acessador tem colunas de saída  
  
-   **HasParameters** determina se o acessador tiver parâmetros.  
  
-   `BindParameters` associa parâmetros criados para as colunas.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)