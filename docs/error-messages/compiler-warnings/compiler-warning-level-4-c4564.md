---
title: "Aviso do compilador (n&#237;vel 4) C4564 | Microsoft Docs"
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
  - "C4564"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4564"
ms.assetid: 555b301b-313e-4262-9f81-eb878674be60
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4564
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o método método “” das classes das classes define o parâmetro padrão sem suporte “parâmetro”  
  
 O compilador detectou um método com um ou mais parâmetros com valores padrão.  O valor padrão para os parâmetros será ignorado quando o método é invocado; especificar explicitamente os valores para esses parâmetros.  Se você não especificar explicitamente os valores para os parâmetros, o compilador C\+\+ gerará um erro.  
  
 Dada a seguinte .dll criado com o Visual Basic, que permite parâmetros padrão nos argumentos de método:  
  
```  
' C4564.vb  
' compile with: vbc /t:library C4564.vb  
Public class TestClass  
   Public Sub MyMethod (a as Integer, _  
                        Optional c as Integer=1)  
   End Sub  
End class  
```  
  
 O exemplo a seguir e C\+\+ que usa o .dll criou com o Visual Basic,  
  
```  
// C4564.cpp  
// compile with: /clr /W4 /WX  
#using <C4564.dll>  
  
int main() {  
   TestClass ^ myx = gcnew TestClass();   // C4564  
   myx->MyMethod(9);  
   // try the following line instead, to avoid an error  
   // myx->MyMethod(9, 1);  
}  
```