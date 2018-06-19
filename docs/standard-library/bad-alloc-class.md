---
title: Classe bad_alloc | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- new/std::bad_alloc
dev_langs:
- C++
helpviewer_keywords:
- bad_alloc class
ms.assetid: 6429a8e6-5a49-4907-8d56-f4a4ec8131d0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9ab496a5de8062f6888b92b318788ff72345bc7c
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33850724"
---
# <a name="badalloc-class"></a>Classe bad_alloc

A classe descreve uma exceção gerada para indicar que uma solicitação de alocação não teve êxito.

## <a name="syntax"></a>Sintaxe

```cpp
class bad_alloc : public exception {
    bad_alloc();
virtual ~bad_alloc();

};
```

## <a name="remarks"></a>Comentários

O valor retornado por **o quê** é uma cadeia de caracteres C definida pela implementação. Nenhuma das funções de membro lança exceções.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<new>

**Namespace:** std

## <a name="example"></a>Exemplo

```cpp
// bad_alloc.cpp
// compile with: /EHsc
#include<new>
#include<iostream>
using namespace std;

int main() {
   char* ptr;
   try {
      ptr = new char[(~unsigned int((int)0)/2) - 1];
      delete[] ptr;
   }
   catch( bad_alloc &ba) {
      cout << ba.what( ) << endl;
   }
}
```

## <a name="sample-output"></a>Saída de Exemplo

```Output
bad allocation
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<new>

## <a name="see-also"></a>Consulte também

[Classe de exceção](../standard-library/exception-class.md) [segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
