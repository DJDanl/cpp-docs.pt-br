---
title: "Compilador aviso (nível 4) C4564 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4564
dev_langs:
- C++
helpviewer_keywords:
- C4564
ms.assetid: 555b301b-313e-4262-9f81-eb878674be60
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: c6f8d7640b0a59cb7eaeae180235038150704110
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4564"></a>Compilador C4564 de aviso (nível 4)
método de método da classe 'class' define ' parâmetro padrão sem suporte '  
  
 O compilador detectou um método com um ou mais parâmetros com valores padrão. Os valores padrão para os parâmetros serão ignorados quando o método é chamado; Especifica valores para esses parâmetros explicitamente. Se você não especificar valores para esses parâmetros explicitamente, o compilador C++ gerará um erro.  
  
 Dado o seguinte arquivo. dll criado com o Visual Basic, que permite parâmetros padrão em argumentos de método:  
  
```  
' C4564.vb  
' compile with: vbc /t:library C4564.vb  
Public class TestClass  
   Public Sub MyMethod (a as Integer, _  
                        Optional c as Integer=1)  
   End Sub  
End class  
```  
  
 E o seguinte exemplo de C++ que usa o arquivo. dll criado com o Visual Basic  
  
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
