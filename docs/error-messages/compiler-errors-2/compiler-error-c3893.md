---
title: Erro do compilador C3893
ms.date: 11/04/2016
f1_keywords:
- C3893
helpviewer_keywords:
- C3893
ms.assetid: 90d52eae-6ef2-4db1-b7ad-92f9e8b140fb
ms.openlocfilehash: 45a140d3fd5f510ee2434950ca3c4b47c0756d75
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62385492"
---
# <a name="compiler-error-c3893"></a>Erro do compilador C3893

'var': uso l-value de membro de dados initonly só é permitido em um construtor de instância da classe 'type_name'

Estática [initonly](../../dotnet/initonly-cpp-cli.md) membros de dados só podem ter seus endereços obtidos em um construtor estático.

Membros de dados initonly (não estático) de instância só podem ter seus endereços obtidos em construtores de instância (não estático).

O exemplo a seguir gera C3893:

```
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