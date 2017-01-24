---
title: "Classe marshal_context | Microsoft Docs"
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
  - "marshal_context"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classe marshal_context [C++]"
ms.assetid: 241b0cf6-4ca4-4812-aaee-d671c11dc034
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe marshal_context
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essa classe converte dados entre o modo nativo e ambientes gerenciados.  
  
## Sintaxe  
  
```  
class marshal_context  
```  
  
## Comentários  
 Use a classe de `marshal_context` para as conversões de dados que exigem um contexto.  Consulte [Visão geral de marshaling no C\+\+](../dotnet/overview-of-marshaling-in-cpp.md) para obter mais informações sobre quais as conversões exigem um contexto e de que o arquivo marshaling tem que ser incluído.  O resultado do marshaling quando você usa um contexto é válido somente até que o objeto de `marshal_context` ser destruído.  Para preservar seu resultado, você deve copiar os dados.  
  
 Mesmo `marshal_context` pode ser usado para várias conversões de dados.  Reutilizar o contexto dessa maneira não afetará os resultados das chamadas marshaling anteriores.  
  
## Requisitos  
 msclr \<de**Arquivo de cabeçalho:** \\ marshal.h, msclr\>\<\\ marshal\_windows.h, msclr\>\\ \<marshal\_cppstd.h, ou msclr\>\\ marshal\_atl.h \<\>  
  
 msclr::interop de**Namespace:**  
  
## Consulte também  
 [Visão geral de marshaling no C\+\+](../dotnet/overview-of-marshaling-in-cpp.md)   
 [marshal\_as](../dotnet/marshal-as.md)