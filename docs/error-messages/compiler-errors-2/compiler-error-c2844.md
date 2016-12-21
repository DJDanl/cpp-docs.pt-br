---
title: "Erro do Compilador C2844 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C2844"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2844"
ms.assetid: dcaf4cd2-21b0-4280-ae42-0a706c524d83
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2844
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“membro”: não pode ser um membro da interface de “interface”  
  
 [interface class](../../windows/interface-class-cpp-component-extensions.md) não pode conter um membro de dados a menos que também seja uma propriedade.  
  
 Algo diferente de uma propriedade ou uma função de membro não é permitido em uma interface.  Além disso, não são permitidos, os construtores destruidores, e operadores.  
  
 O seguinte exemplo gera C2844:  
  
```  
// C2844a.cpp  
// compile with: /clr /c  
public interface class IFace {  
   int i;   // C2844  
   // try the following line instead  
   // property int Size;  
};  
```  
  
 O seguinte exemplo gera C2844:  
  
```  
// C2844b.cpp  
// compile with: /clr:oldSyntax /c  
#using <mscorlib.dll>  
__gc __interface IFace {  
   int i;   // C2844  
   // try the following line instead  
   // __property int Size { get; set; };  
};  
```