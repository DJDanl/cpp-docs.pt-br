---
title: "operator&gt;= | Microsoft Docs"
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
  - "operator>="
  - "std::>="
  - "std.operator>="
  - ">="
  - "std.>="
  - "std::operator>="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador >=, comparando objetos específicos"
  - "Operador >="
  - "operator>="
ms.assetid: 14fbebf5-8b75-4afa-a51b-3112d31c07cf
caps.latest.revision: 9
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# operator&gt;=
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  Este tópico está na documentação do Visual C\+\+ como um exemplo nonfunctional contêineres usados na biblioteca padrão C\+\+.  Para obter mais informações, consulte [Contêineres STL](../standard-library/stl-containers.md).  
  
 As sobrecargas **operator\>\=** para comparar dois objetos de modelo [Contêiner](../Topic/Sample%20Container%20Class.md)classe.  
  
## Sintaxe  
  
```  
  
   template<class Ty>  
bool operator>=(  
   const Container <Ty>& _Left,  
   const Container <Ty>& _Right  
);  
```  
  
## Valor de retorno  
 Retorna **\!**\(\_*Left*\< \_*Right*\).  
  
## Consulte também  
 [\<sample container\>](../standard-library/sample-container.md)