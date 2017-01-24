---
title: "operator&lt;= (&lt;sample container&gt;) | Microsoft Docs"
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
  - "std::<="
  - "std.operator<="
  - "operator<="
  - "std.<="
  - "std::operator<="
  - "<="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador <="
  - "Operador <=, com objetos específicos"
  - "Operador <="
  - "operator<="
ms.assetid: 338577dd-dc88-4a2b-9e12-0379c54fc8a2
caps.latest.revision: 9
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# operator&lt;= (&lt;sample container&gt;)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  Este tópico está na documentação do Visual C\+\+ como um exemplo nonfunctional contêineres usados na biblioteca padrão C\+\+.  Para obter mais informações, consulte [Contêineres STL](../standard-library/stl-containers.md).  
  
 Sobrecargas **operator\<\=** para comparar dois objetos da classe [Contêiner](../Topic/Sample%20Container%20Class.md)do modelo.  
  
## Sintaxe  
  
```  
  
   template<class Ty>  
bool operator<=(  
   const Container <Ty>& _Left,  
   const Container <Ty>& _Right  
);  
```  
  
## Valor de retorno  
 Retorna **\!**\(\_*Right*\< \_*Left*\).  
  
## Consulte também  
 [\<sample container\>](../standard-library/sample-container.md)