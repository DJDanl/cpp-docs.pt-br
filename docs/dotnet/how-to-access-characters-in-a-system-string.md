---
title: Como acessar caracteres em um System::String
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- characters [C++], accessing in System::String
- examples [C++], strings
- strings [C++], accessing characters
ms.assetid: cfc89756-aef3-4988-907e-fb236dcb7087
ms.openlocfilehash: 3c44c5e7651bb1c5b4c28654b896cbe64bd5bec7
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988647"
---
# <a name="how-to-access-characters-in-a-systemstring"></a>Como acessar caracteres em um System::String

Você pode acessar caracteres de um objeto <xref:System.String> para chamadas de alto desempenho para funções não gerenciadas que usam cadeias de caracteres `wchar_t*`. O método gera um ponteiro interior para o primeiro caractere do objeto <xref:System.String>. Esse ponteiro pode ser manipulado diretamente ou fixado e passado para uma função que espera uma cadeia de caracteres `wchar_t` comum.

## <a name="example"></a>Exemplo

`PtrToStringChars` retorna um <xref:System.Char>, que é um ponteiro interior (também conhecido como um `byref`). Assim, ele está sujeito à coleta de lixo. Você não precisa fixar esse ponteiro, a menos que você vai passá-lo para uma função nativa.

Considere o código a seguir.  A fixação não é necessária porque `ppchar` é um ponteiro interior e, se o coletor de lixo mover a cadeia de caracteres para a qual aponta, ele também atualizará `ppchar`. Sem um [pin_ptr (C++/CLI)](../extensions/pin-ptr-cpp-cli.md), o código funcionará e não terá o possível impacto no desempenho causado pela fixação.

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

## <a name="see-also"></a>Consulte também

[Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)
