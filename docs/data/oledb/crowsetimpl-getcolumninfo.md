---
title: "CRowsetImpl::GetColumnInfo | Microsoft Docs"
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
  - "GetColumnInfo"
  - "CRowsetImpl.GetColumnInfo"
  - "CRowsetImpl::GetColumnInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetColumnInfo"
ms.assetid: 9ef76525-f996-4c6f-81b9-68eb260350ef
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CRowsetImpl::GetColumnInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera informações de coluna para uma solicitação de cliente específica.  
  
## Sintaxe  
  
```  
  
      static ATLCOLUMNINFO* CRowsetBaseImpl::GetColumnInfo(  
   T* pv,  
   ULONG* pcCols   
);  
```  
  
#### Parâmetros  
 `pv`  
 \[in\] ponteiro da classe derivada de `CRowsetImpl` do usuário.  
  
 `pcCols`  
 \[in\] o ponteiro de saída \(\) ao número de colunas retornado.  
  
## Valor de retorno  
 Um ponteiro para uma estrutura de **ATLCOLUMNINFO** estático.  
  
## Comentários  
 Esse método é uma substituição avançada.  
  
 Este método é chamado por várias classes base de implementação para recuperar informações de coluna para uma solicitação de cliente específica.  Geralmente, esse método será chamado por `IColumnsInfoImpl`.  Se você substituir esse método, você deve colocar uma versão do método em seu `CRowsetImpl`\- classe derivada.  Como o método pode ser colocado em uma classe non\-templatized, você deve alterar `pv` a `CRowsetImpl`apropriado \- classe derivada.  
  
 O exemplo a seguir demonstra o uso de **GetColumnInfo's** .  Neste exemplo, **CMyRowset** é `CRowsetImpl`\- classe derivada.  Para substituir `GetColumnInfo` para todas as instâncias dessa classe, coloque o método a seguir na definição da classe de **CMyRowset** :  
  
 [!CODE [NVC_OLEDB_Provider#1](../CodeSnippet/VS_Snippets_Cpp/NVC_OLEDB_Provider#1)]  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe CRowsetImpl](../../data/oledb/crowsetimpl-class.md)