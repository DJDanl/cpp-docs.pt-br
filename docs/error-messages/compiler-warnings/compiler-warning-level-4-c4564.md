---
title: Aviso do compilador (nível 4) C4564
ms.date: 11/04/2016
f1_keywords:
- C4564
helpviewer_keywords:
- C4564
ms.assetid: 555b301b-313e-4262-9f81-eb878674be60
ms.openlocfilehash: 042eab1c125f2b98fd36257dfd8971262015ab92
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74990668"
---
# <a name="compiler-warning-level-4-c4564"></a>Aviso do compilador (nível 4) C4564

o método ' method ' da classe ' class ' define o parâmetro padrão sem suporte ' Parameter '

O compilador detectou um método com um ou mais parâmetros com valores padrão. Os valores padrão para os parâmetros serão ignorados quando o método for invocado; especifique explicitamente os valores para esses parâmetros. Se você não especificar valores explicitamente para esses parâmetros, o C++ compilador irá gerar um erro.

Dado o seguinte. dll criado com Visual Basic, que permite parâmetros padrão em argumentos de método:

```vb
' C4564.vb
' compile with: vbc /t:library C4564.vb
Public class TestClass
   Public Sub MyMethod (a as Integer, _
                        Optional c as Integer=1)
   End Sub
End class
```

E o exemplo C++ a seguir que usa o. dll criado com Visual Basic,

```cpp
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
