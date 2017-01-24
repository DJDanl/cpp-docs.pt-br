---
title: "M&#233;todo AsyncBase::TryTransitionToError | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "async/Microsoft::WRL::AsyncBase::TryTransitionToError"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método TryTransitionToError"
ms.assetid: f6d11c25-1ce3-43f9-af1c-97c4dc0f6f0f
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo AsyncBase::TryTransitionToError
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Indica se o código de erro especificado é possível alterar o estado de erro interno.  
  
## Sintaxe  
  
```  
bool TryTransitionToError(  
   const HRESULT error  
);  
```  
  
#### Parâmetros  
 `error`  
 Um erro HRESULT.  
  
## Valor de retorno  
 `true` se o estado de erro interno foi alterado; caso contrário, `false`.  
  
## Comentários  
 Essa operação altera o estado de erro somente se o estado de erro já estará definido como S\_OK.  Essa operação não tem nenhum efeito se o estado do erro é já erro, cancelado, concluído, ou fechada.  
  
## Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)