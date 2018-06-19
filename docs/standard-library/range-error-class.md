---
title: Classe range_error | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- stdexcept/std::range_error
dev_langs:
- C++
helpviewer_keywords:
- range_error class
ms.assetid: 8afb3e88-fc49-4213-b096-ed63d7aea37c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 63d6497dda220723587623cb42551366ddcbef80
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33853080"
---
# <a name="rangeerror-class"></a>Classe range_error

A classe serve como a classe base para todas as exceções geradas para relatar um erro de alcance.

## <a name="syntax"></a>Sintaxe

```cpp
class range_error : public runtime_error {
public:
    explicit range_error(const string& message);

    explicit range_error(const char *message);

};
```

## <a name="remarks"></a>Comentários

O valor retornado por [what](../standard-library/exception-class.md) é uma cópia de **message**`.`[data](../standard-library/basic-string-class.md#data).

## <a name="example"></a>Exemplo

```cpp
// range_error.cpp
// compile with: /EHsc /GR
#include <iostream>
using namespace std;
int main()
{
   try
   {
      throw range_error( "The range is in error!" );
   }
   catch (exception &e)
   {
      cerr << "Caught: " << e.what( ) << endl;
      cerr << "Type: " << typeid( e ).name( ) << endl;
   };
}
\* Output:
Caught: The range is in error!
Type: class std::range_error
*\
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<stdexcept>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Classe runtime_error](../standard-library/runtime-error-class.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
