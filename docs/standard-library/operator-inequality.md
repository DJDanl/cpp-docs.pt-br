---
title: "operator!= | Microsoft Docs"
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
  - "std::!="
  - "!="
  - "std::operator!="
  - "std.operator!="
  - "std.!="
  - "operator!="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador !="
  - "Operador !="
  - "operator!="
ms.assetid: ef2be7f0-1c94-4edc-b65c-731fddd519f4
caps.latest.revision: 8
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# operator!=
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  Este tópico está na documentação do Visual C\+\+ como um exemplo nonfunctional contêineres usados na biblioteca padrão C\+\+.  Para obter mais informações, consulte [Contêineres STL](../standard-library/stl-containers.md).  
  
 Sobrecargas `operator!=` para comparar dois objetos da classe [Contêiner](../Topic/Sample%20Container%20Class.md)do modelo.  
  
## Sintaxe  
  
```  
  
   template<class Ty>  
bool operator!=(  
   const Container <Ty>& _Left,  
   const Container <Ty>& _Right  
);  
```  
  
## Valor de retorno  
 Retorna **\!**\(\_*Left* **\=\=** `_Right`\).  
  
## Consulte também  
 [\<sample container\>](../standard-library/sample-container.md)