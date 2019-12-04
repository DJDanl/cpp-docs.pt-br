---
title: Erro do compilador C3893
ms.date: 11/04/2016
f1_keywords:
- C3893
helpviewer_keywords:
- C3893
ms.assetid: 90d52eae-6ef2-4db1-b7ad-92f9e8b140fb
ms.openlocfilehash: 20c17eaa6555b5511ecbc930eacdb2ec92475b23
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74749497"
---
# <a name="compiler-error-c3893"></a>Erro do compilador C3893

' var ': o uso de l-Value de membro de dados InitOnly só é permitido em um construtor de instância da classe ' type_name '

Membros de dados [InitOnly](../../dotnet/initonly-cpp-cli.md) estáticos só podem ter seu endereço Obtido em um construtor estático.

Membros de dados InitOnly de instância (não estáticos) só podem ter seu endereço levado em construtores de instância (não estáticos).

O exemplo a seguir gera C3893:

```cpp
// C3893.cpp
// compile with: /clr
ref struct Y1 {
   Y1() : data_var(0) {
      int% i = data_var;   // OK
   }
   initonly int data_var;
};

int main(){
   Y1^ y= gcnew Y1;
   int% i = y->data_var;   // C3893
}
```
