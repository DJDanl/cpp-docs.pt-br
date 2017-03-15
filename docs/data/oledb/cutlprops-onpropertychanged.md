---
title: "CUtlProps::OnPropertyChanged | Microsoft Docs"
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
  - "OnPropertyChanged"
  - "CUtlProps.OnPropertyChanged"
  - "CUtlProps::OnPropertyChanged"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método OnPropertyChanged"
ms.assetid: c5924210-b685-46c4-87f8-1b81e5bd3378
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CUtlProps::OnPropertyChanged
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Chamado depois de definir uma propriedade para tratar encadeou propriedades.  
  
## Sintaxe  
  
```  
  
      virtual HRESULT OnPropertyChanged(  
   ULONG /* iCurSet */,  
   DBPROP* pDBProp   
);  
```  
  
#### Parâmetros  
 `iCurSet`  
 O índice na matriz do conjunto de propriedades; zero se houver apenas um conjunto de propriedades.  
  
 `pDBProp`  
 A ID da propriedade e o novo valor em uma estrutura de [DBPROP](https://msdn.microsoft.com/en-us/library/ms717970.aspx) .  
  
## Valor de retorno  
 `HRESULT`padrão.  O valor de retorno padrão é `S_OK`.  
  
## Comentários  
 Se você quiser tratar propriedades encadeadas, como os indicadores ou atualiza dos quais valores são dependentes em outro valor da propriedade, você deve substituir essa função.  
  
## Exemplo  
 Nessa função, o usuário obtém a ID de propriedade do parâmetro de `DBPROP*` .  Agora, é possível comparar a ID em uma propriedade da cadeia.  Quando a propriedade for localizada, `SetProperties` é chamado com a propriedade que será definida agora junto com outra propriedade.  Nesse caso, se obtém `DBPROP_IRowsetLocate`, `DBPROP_LITERALBOOKMARKS`, ou a propriedade de `DBPROP_ORDEREDBOOKMARKS` , uma possível definir a propriedade de `DBPROP_BOOKMARKS` .  
  
 [!CODE [NVC_OLEDB_Provider#2](../CodeSnippet/VS_Snippets_Cpp/NVC_OLEDB_Provider#2)]  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe CUtlProps](../../data/oledb/cutlprops-class.md)