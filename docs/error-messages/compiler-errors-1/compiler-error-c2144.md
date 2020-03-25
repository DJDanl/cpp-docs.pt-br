---
title: Erro do compilador C2144
ms.date: 11/04/2016
f1_keywords:
- C2144
helpviewer_keywords:
- C2144
ms.assetid: 49f3959b-324f-4c06-9588-c0ecef5dc5b3
ms.openlocfilehash: b917c0a2c15aeb70222c948bce9a6fb275c91068
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80207240"
---
# <a name="compiler-error-c2144"></a>Erro do compilador C2144

> erro de sintaxe: '*Type*' deve ser precedido por '*token*'

O compilador esperava o *token* e o *tipo* encontrado.

Esse erro pode ser causado por uma chave de fechamento ausente, um parêntese direito ou um ponto-e-vírgula.

C2144 também pode ocorrer ao tentar criar uma macro com base em uma palavra-chave CLR que contenha um caractere de espaço em branco.

Você também pode ver C2144 se estiver tentando fazer o encaminhamento de tipo. Consulte o [encaminhamento deC++tipo (/CLI)](../../extensions/type-forwarding-cpp-cli.md) para obter mais informações.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C2144 e mostra uma maneira de corrigi-lo:

```cpp
// C2144.cpp
// compile with: /clr /c
#define REF ref
REF struct MyStruct0;   // C2144

// OK
#define REF1 ref struct
REF1 MyStruct1;
```

O exemplo a seguir gera C2144 e mostra uma maneira de corrigi-lo:

```cpp
// C2144_2.cpp
// compile with: /clr /c
ref struct X {

   property double MultiDimProp[,,] {   // C2144
   // try the following line instead
   // property double MultiDimProp[int , int, int] {
      double get(int, int, int) { return 1; }
      void set(int i, int j, int k, double l) {}
   }

   property double MultiDimProp2[] {   // C2144
   // try the following line instead
   // property double MultiDimProp2[int] {
      double get(int) { return 1; }
      void set(int i, double l) {}
   }
};
```
