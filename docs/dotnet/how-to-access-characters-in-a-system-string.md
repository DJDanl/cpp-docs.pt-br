---
title: Como acessar caracteres em um System::String
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- characters [C++], accessing in System::String
- examples [C++], strings
- strings [C++], accessing characters
ms.assetid: cfc89756-aef3-4988-907e-fb236dcb7087
ms.openlocfilehash: a91f82d0377b9065c2927e61e9f2a558a49985f0
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221361"
---
# <a name="how-to-access-characters-in-a-systemstring"></a>Como acessar caracteres em um System::String

Você pode acessar os caracteres de um <xref:System.String> objeto para chamadas de alto desempenho para funções não gerenciadas que usam `wchar_t*` cadeias. O método gera um ponteiro interior para o primeiro caractere do <xref:System.String> objeto. Esse ponteiro pode ser manipulado diretamente ou fixado e passado para uma função que espera uma **`wchar_t`** cadeia de caracteres comum.

## <a name="example"></a>Exemplo

`PtrToStringChars`Retorna um <xref:System.Char> , que é um ponteiro interior (também conhecido como um `byref` ). Assim, ele está sujeito à coleta de lixo. Você não precisa fixar esse ponteiro, a menos que você vai passá-lo para uma função nativa.

Considere o código a seguir.  A fixação não é necessária porque `ppchar` é um ponteiro interior e, se o coletor de lixo mover a cadeia de caracteres para a qual aponta, ele também será atualizado `ppchar` . Sem um [pin_ptr (C++/CLI)](../extensions/pin-ptr-cpp-cli.md), o código funcionará e não terá o possível impacto no desempenho causado pela fixação.

Se você passar `ppchar` para uma função nativa, ele deverá ser um ponteiro de fixação; o coletor de lixo não poderá atualizar nenhum ponteiro no quadro de pilha não gerenciado.

```cpp
// PtrToStringChars.cpp
// compile with: /clr
#include<vcclr.h>
using namespace System;

int main() {
   String ^ mystring = "abcdefg";

   interior_ptr<const Char> ppchar = PtrToStringChars( mystring );

   for ( ; *ppchar != L'\0'; ++ppchar )
      Console::Write(*ppchar);
}
```

```Output
abcdefg
```

## <a name="example"></a>Exemplo

Este exemplo mostra onde a fixação é necessária.

```cpp
// PtrToStringChars_2.cpp
// compile with: /clr
#include <string.h>
#include <vcclr.h>
// using namespace System;

size_t getlen(System::String ^ s) {
   // Since this is an outside string, we want to be secure.
   // To be secure, we need a maximum size.
   size_t maxsize = 256;
   // make sure it doesn't move during the unmanaged call
   pin_ptr<const wchar_t> pinchars = PtrToStringChars(s);
   return wcsnlen(pinchars, maxsize);
};

int main() {
   System::Console::WriteLine(getlen("testing"));
}
```

```Output
7
```

## <a name="example"></a>Exemplo

Um ponteiro interior tem todas as propriedades de um ponteiro C++ nativo. Por exemplo, você pode usá-lo para percorrer uma estrutura de dados vinculada e fazer inserções e exclusões usando apenas um ponteiro:

```cpp
// PtrToStringChars_3.cpp
// compile with: /clr /LD
using namespace System;
ref struct ListNode {
   Int32 elem;
   ListNode ^ Next;
};

void deleteNode( ListNode ^ list, Int32 e ) {
   interior_ptr<ListNode ^> ptrToNext = &list;
   while (*ptrToNext != nullptr) {
      if ( (*ptrToNext) -> elem == e )
         *ptrToNext = (*ptrToNext) -> Next;   // delete node
      else
         ptrToNext = &(*ptrToNext) -> Next;   // move to next node
   }
}
```

## <a name="see-also"></a>Confira também

[Usando a interoperabilidade C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)
