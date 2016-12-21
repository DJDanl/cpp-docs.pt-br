---
title: "Sem&#226;ntica de CString | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "instruções de atribuição, objetos de CString de atribuição"
  - "Objetos de CString, semântica de atribuição"
  - "semântica em Cstring"
ms.assetid: d4023480-526f-499a-85f6-324b4de5b85f
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Sem&#226;ntica de CString
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Embora os objetos de [CString](../atl-mfc-shared/reference/cstringt-class.md) são os objetos dinâmicos que podem aumentarem, atuam como tipos primitivos internos e classes simples.  Cada objeto de `CString` representa um único valor.  Os objetos de`CString` devem ser pensados como as cadeias de caracteres \(em vez de como ponteiros para cadeias de caracteres.  
  
 Você pode atribuir um objeto de **CString** para outro.  Em o entanto, quando você altera um dos dois objetos de `CString` , o outro objeto de `CString` não é alterado, como mostrado no exemplo a seguir:  
  
 [!code-cpp[NVC_ATLMFC_Utilities#188](../atl-mfc-shared/codesnippet/CPP/cstring-semantics_1.cpp)]  
  
 Em o exemplo observe que os dois objetos de `CString` são considerados “equals” porque representa a mesma cadeia de caracteres.  A classe de `CString` sobrecarrega o operador de igualdade \(`==`\) para comparar dois objetos de `CString` com base no seu valor \(conteúdo\) em vez de sua identidade \(endereço\).  
  
## Consulte também  
 [Cadeias de caracteres](../atl-mfc-shared/strings-atl-mfc.md)