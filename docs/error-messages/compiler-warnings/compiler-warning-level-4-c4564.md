---
title: Compilador (nível 4) de aviso C4564 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4564
dev_langs:
- C++
helpviewer_keywords:
- C4564
ms.assetid: 555b301b-313e-4262-9f81-eb878674be60
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1f0cf68eb75d420a0d23c04687d4f9492910b53f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33293667"
---
# <a name="compiler-warning-level-4-c4564"></a>Compilador C4564 de aviso (nível 4)
método de método da classe 'class' define parâmetro padrão não suportado 'parameter'  
  
 O compilador detectou um método com um ou mais parâmetros com valores padrão. Os valores padrão para os parâmetros serão ignorados quando o método é invocado; Especifica explicitamente valores para esses parâmetros. Se você não especificar explicitamente valores para esses parâmetros, o compilador do C++ gerará um erro.  
  
 Fornecido o seguinte arquivo. dll criado com o Visual Basic, que permite que os parâmetros padrão em argumentos de método:  
  
```  
' C4564.vb  
' compile with: vbc /t:library C4564.vb  
Public class TestClass  
   Public Sub MyMethod (a as Integer, _  
                        Optional c as Integer=1)  
   End Sub  
End class  
```  
  
 O seguinte exemplo de C++ que usa o arquivo. dll criado com o Visual Basic, e  
  
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