---
title: "CRowset::SetData | Microsoft Docs"
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
  - "ATL.CRowset<TAccessor>.SetData"
  - "SetData"
  - "ATL::CRowset::SetData"
  - "CRowset<TAccessor>.SetData"
  - "CRowset::SetData"
  - "ATL.CRowset.SetData"
  - "CRowset.SetData"
  - "CRowset<TAccessor>::SetData"
  - "ATL::CRowset<TAccessor>::SetData"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método SetData"
ms.assetid: 68125142-8510-4132-9393-e39efd39c784
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CRowset::SetData
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define valores de dados em uma ou mais colunas de uma linha.  
  
## Sintaxe  
  
```  
  
      HRESULT SetData( ) const throw( );   
HRESULT SetData(  
   int nAccessor   
) const throw( );  
```  
  
#### Parâmetros  
 `nAccessor`  
 \[in\] o número de acessador a ser usado para acessar os dados.  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 Para o formato de `SetData` que não aceita nenhum argumento, todos os acessadores são usados atualizando.  Você normalmente chama **SetData** para definir valores em uma linha de dados nas colunas, em seguida chama [Atualização](../Topic/CRowset::Update.md) para passar essas alterações.  
  
 Esse método exige a interface opcional `IRowsetChange`, que pode não haver suporte em todos os provedores; nesse caso, o método retornará **E\_NOINTERFACE**.  Você também deve definir **DBPROP\_IRowsetChange** a `VARIANT_TRUE` antes de chamar **Abrir** na tabela ou o comando que contém o conjunto de linhas.  
  
 A operação de instalação pode falhar se uma ou mais colunas não são gravável.  Modifique seu mapa de cursor para corrigir isso.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CRowset](../Topic/CRowset%20Class.md)   
 [CRowset::Update](../Topic/CRowset::Update.md)