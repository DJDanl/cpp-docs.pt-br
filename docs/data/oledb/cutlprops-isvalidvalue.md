---
title: "CUtlProps::IsValidValue | Microsoft Docs"
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
  - "CUtlProps::IsValidValue"
  - "CUtlProps.IsValidValue"
  - "IsValidValue"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método IsValidValue"
ms.assetid: 1164556e-8d98-429c-a396-fc9a699e0e97
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CUtlProps::IsValidValue
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado para validar um valor antes de definir uma propriedade.  
  
## Sintaxe  
  
```  
  
      virtual HRESULT CUtlPropsBase::IsValidValue(  
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
 Se você tiver qualquer rotinas de validação que você queira executar em um valor que você está prestes a ser usado para definir uma propriedade, você deve substituir essa função.  Por exemplo, você pode validar **DBPROP\_AUTH\_PASSWORD** em uma tabela de senha para determinar um valor válido.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe CUtlProps](../../data/oledb/cutlprops-class.md)