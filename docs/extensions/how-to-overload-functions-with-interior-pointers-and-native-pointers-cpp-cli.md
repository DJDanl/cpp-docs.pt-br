---
title: Como sobrecarregar funções com ponteiros internos e nativos (C++/CLI)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- Functions with interior and native pointers, overloading
ms.assetid: d70df625-4aad-457c-84f5-70a0a290cc1f
ms.openlocfilehash: d4e7ee1140942b0168c8ae94baabd938d6923c7c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80172238"
---
# <a name="how-to-overload-functions-with-interior-pointers-and-native-pointers-ccli"></a>Como sobrecarregar funções com ponteiros internos e nativos (C++/CLI)

As funções podem ser sobrecarregadas dependendo de o tipo de parâmetro ser um ponteiro interno ou um ponteiro nativo.

> [!IMPORTANT]
> Esse recurso de linguagem é compatível com a opção do compilador `/clr`, mas não pela opção do compilador `/ZW`.

## <a name="example"></a>Exemplo

### <a name="code"></a>Código

```cpp
// interior_ptr_overload.cpp
// compile with: /clr
using namespace System;

// C++ class
struct S {
   int i;
};

// managed class
ref struct G {
   int i;
};

// can update unmanaged storage
void f( int* pi ) {
   *pi = 10;
   Console::WriteLine("in f( int* pi )");
}

// can update managed storage
void f( interior_ptr<int> pi ) {
   *pi = 10;
   Console::WriteLine("in f( interior_ptr<int> pi )");
}

int main() {
   S *pS = new S;   // C++ heap
   G ^pG = gcnew G;   // common language runtime heap
   f( &pS->i );
   f( &pG->i );
};
```

```Output
in f( int* pi )
in f( interior_ptr<int> pi )
```

## <a name="see-also"></a>Confira também

[interior_ptr (C++/CLI)](interior-ptr-cpp-cli.md)
