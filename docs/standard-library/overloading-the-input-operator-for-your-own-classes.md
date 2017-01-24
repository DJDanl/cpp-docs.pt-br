---
title: "Sobrecarregando o operador &gt;&gt; para as suas pr&#243;prias classes | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador >>, sobrecarregando para suas próprias classes"
  - "operator>>"
  - "operator>>, sobrecarregando para suas próprias classes"
ms.assetid: 40dab4e0-3f97-4745-9cc8-b86e740fa246
caps.latest.revision: 8
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Sobrecarregando o operador &gt;&gt; para as suas pr&#243;prias classes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os fluxos de entrada usam o operador de extração`>>`\(\) para tipos padrão.  Você pode escrever operadores semelhantes de extração para seus próprios tipos; seu êxito depende do uso do espaço em branco com precisão.  
  
 Eis um exemplo de um operador de extração para a classe de `Date` apresentadas anterior:  
  
```  
istream& operator>> ( istream& is, Date& dt )  
{  
   is >> dt.mo >> dt.da >> dt.yr;  
   return is;  
}  
```  
  
## Consulte também  
 [Fluxos de entrada](../standard-library/input-streams.md)