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
ms.openlocfilehash: 0e76bd39477c92d075f1dba8cf14b912c0f616e0
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38955904"
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

O valor retornado por `what` é uma cadeia de caracteres C definida pela implementação. Nenhuma das funções de membro lança exceções.

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

[Classe Exception](../standard-library/exception-class.md) [acesso Thread-Safe na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
