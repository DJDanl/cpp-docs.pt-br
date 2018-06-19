---
title: C2144 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2144
dev_langs:
- C++
helpviewer_keywords:
- C2144
ms.assetid: 49f3959b-324f-4c06-9588-c0ecef5dc5b3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 60a6b0a6019ab6ddf1a403d2cbd4f6ef96b2a865
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33171137"
---
# <a name="compiler-error-c2144"></a>C2144 de erro do compilador

> Erro de sintaxe: '*tipo*'deve ser precedido por'*token*'

O compilador esperado *token* e encontrado *tipo* em vez disso.

Esse erro pode ser causado por uma chave de fechamento ausente, parêntese direito ou ponto e vírgula.

C2144 também pode ocorrer ao tentar criar uma macro de uma palavra-chave CLR que contém um caractere de espaço em branco.

Você também pode ver C2144 se você estiver tentando encaminhamento de tipos. Consulte [encaminhamento de tipo (C + + CLI)](../../windows/type-forwarding-cpp-cli.md) para obter mais informações.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C2144 e mostra uma maneira de corrigir isso:

```cpp
// C2144.cpp
// compile with: /clr /c
#define REF ref
REF struct MyStruct0;   // C2144

// OK
#define REF1 ref struct
REF1 MyStruct1;
```

O exemplo a seguir gera C2144 e mostra uma maneira de corrigir isso:

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