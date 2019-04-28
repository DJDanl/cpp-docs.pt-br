---
title: Compilador aviso (nível 4) C4564
ms.date: 11/04/2016
f1_keywords:
- C4564
helpviewer_keywords:
- C4564
ms.assetid: 555b301b-313e-4262-9f81-eb878674be60
ms.openlocfilehash: 1948bdec5367fa7943f5a0de4338fd4ecd6c6581
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62220501"
---
# <a name="compiler-warning-level-4-c4564"></a>Compilador aviso (nível 4) C4564

método 'method' da classe 'class' define parâmetro padrão não suportado 'parameter'

O compilador detectou um método com um ou mais parâmetros com valores padrão. Os valores padrão para os parâmetros serão ignorados quando o método é invocado; Especifica explicitamente valores para esses parâmetros. Se você não especificar explicitamente valores para esses parâmetros, o compilador do C++ gerará um erro.

Dado o seguinte arquivo. dll criado com o Visual Basic, que permite que os parâmetros padrão em argumentos de método:

```
' C4564.vb
' compile with: vbc /t:library C4564.vb
Public class TestClass
   Public Sub MyMethod (a as Integer, _
                        Optional c as Integer=1)
   End Sub
End class
```

E o seguinte exemplo do C++ que usa o arquivo. dll criado com o Visual Basic

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