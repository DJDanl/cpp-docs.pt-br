---
title: Erro do compilador C2664
ms.date: 11/04/2016
f1_keywords:
- C2664
helpviewer_keywords:
- C2664
ms.assetid: 3595d66e-cf87-4fda-a896-c0cd81f95db4
ms.openlocfilehash: d9ebea5c955dcf89308654feec9866d4fdc924cd
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50501355"
---
# <a name="compiler-error-c2664"></a>Erro do compilador C2664

'function': não é possível converter a n de argumento de 'type1' para 'type2'

Esse problema de conversão de parâmetro poderá acontecer se uma instância de classe for criada e houver uma tentativa de conversão implícita em um construtor marcado com a palavra-chave `explicit`. Para obter mais informações sobre conversões explícitas, consulte [conversões de tipo definidas pelo usuário](../../cpp/user-defined-type-conversions-cpp.md).

Se um objeto temporário é passado para uma função que usa uma referência a um objeto como parâmetro, essa referência deve ser uma referência `const`.

Se a função é passada para um parâmetro que não é do tipo que a função espera, um objeto temporário é criado usando o construtor apropriado. Em seguida, esse objeto temporário é passado para a função. Nesse caso, o objeto temporário é usado para inicializar a referência. Em versões anteriores da linguagem, todas as referências podiam ser inicializadas por objetos temporários.

Para corrigir o C2664,

- Verifique novamente o protótipo para a função fornecida e corrija o argumento indicado na mensagem de erro.

- Forneça uma conversão explícita, se necessário.

O C2664 também pode ser gerado quando uma classe oculta um membro de uma de suas classes base.

Para obter mais informações, consulte [como: converter System:: String em wchar_t * ou char\*](../../dotnet/how-to-convert-system-string-to-wchar-t-star-or-char-star.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2664 e mostra como corrigi-lo.

```
// C2664.cpp
// C2664
struct A {
   void f(int i) {};
};

struct B : public A {
   // To fix, uncomment the following line.
   // using A::f;
   void f(A a) {};
};

int main() {
   B b;
   int i = 1;
   b.f(i);   // B::F hides A::f Uncomment the using declaration in B.
}
```

## <a name="example"></a>Exemplo

Este exemplo também gera C2664 e mostra como corrigi-lo.

```
// C2664b.cpp
// C2664 expected
struct A {
   // To fix, uncomment the following line.
   // A(int i){}
};

void func( int, A ) {}

int main() {
   func( 1, 1 );   // No conversion from int to A.
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra o C2664 usando um literal de cadeia de caracteres para chamar `Test`e mostra como corrigi-lo. Como o parâmetro é uma referência `szString`, um objeto deve ser criado pelo construtor apropriado. O resultado é um objeto temporário que não pode ser usado para inicializar a referência.

```
// C2664c.cpp
// compile with: /EHsc
// C2664 expected
#include <iostream>
#include <string.h>
using namespace std;

class szString {
   int slen;
   char *str;

public:
   szString(const char *);
   int len() const {
      return slen;
   }
};

// Simple reference cannot bind to temp var.
void Test(szString &a) {}

// To fix, uncomment the following line.
// void Test(const szString &a) {}

szString::szString(const char * newstr) : slen(0), str(NULL) {
   slen=strlen(newstr);
   str = new char[slen + 1];
   if (str)
      strcpy_s(str, (slen + 1), newstr);
}

int main() {
   Test("hello");
}
```

## <a name="example"></a>Exemplo

O compilador força os requisitos padrão C++ para aplicar `const`. Este exemplo gera C2664:

```
// C2664d.cpp
// C2664 expected
#include <windows.h>

void func1(LPCSTR &s)
{

}

void func2(LPSTR &s)
{
   func1(s);
}

int main()
{
   return 0;
}
```

## <a name="example"></a>Exemplo

Aqui está uma situação mais complexa, em que C2664 é gerado, incluindo instruções sobre como corrigi-lo:

```
// C2664e.cpp
// compile with: /EHsc
// C2664 expected
#define _INTL
#include <locale>
#include <iostream>

using namespace std;
#define LEN 90

int main( ) {
   char* pszExt = "This is the string to be converted!";
   wchar_t pwszInt [LEN+1];
   memset(&pwszInt[0], 0, (sizeof(wchar_t))*(LEN+1));

   // To fix, delete the following line.
   char* pszNext;

   // To fix, uncomment the following line.
   // const char* pszNext;

   wchar_t* pwszNext;
   mbstate_t state;
   locale loc("C");
   int res = use_facet<codecvt<wchar_t, char, mbstate_t> >
      ( loc ).in( state,
      pszExt, &pszExt[strlen(pszExt)], pszNext,
      pwszInt, &pwszInt[strlen(pszExt)], pwszNext );
   // See earlier comment.
      pwszInt[strlen(pszExt)] = 0;
   wcout << ( (res!=codecvt_base::error) ?
                       L"It worked! " : L"It didn't work! " )
   << L"The converted string is:\n ["
   << &pwszInt[0]
   << L"]" << endl;

   exit(-1);
}
```

## <a name="example"></a>Exemplo

Uma variável enum não é convertida em seu tipo subjacente para que uma chamada de função seja atendida. Para obter mais informações, consulte [classe enum](../../windows/enum-class-cpp-component-extensions.md). O exemplo a seguir gera C2664 e mostra como corrigi-lo.

```
// C2664f.cpp
// compile with: /clr
using namespace System;
public enum class A : Char {
   None = 0,
   NonSilent = 1,
};

void Test(Char c) {}

int main() {
   A aa = A::None;
   Test(aa);   // C2664
   Test(Char(aa));   // OK - fix by using a conversion cast
}
```

## <a name="example"></a>Exemplo

Um bug no compilador midl causa a emissão de um tipo wchar_t como unsigned short na biblioteca de tipos. Para resolver esse erro, converta o tipo em seu código-fonte C++ ou defina o tipo como uma cadeia de caracteres no arquivo idl.

```
// C2664g.idl
import "prsht.idl";

[ object, uuid(8402B8F1-BF7F-4B49-92D4-C2B9DF4543E9) ]

interface IMyObj1 : IUnknown {
   HRESULT  teststr([in, string] wchar_t *wstr);
   HRESULT  testarr([in, size_is(len)] wchar_t wstr[], [in] int len);
   HRESULT  testbstr([in] BSTR bstr);
};

[  uuid(44463307-CBFC-47A6-8B4F-13CD0A83B436) ]
library myproj1 {
   [  version(1.0), uuid(D8622C12-5448-42B8-8F0E-E3AD6B8470C1) ]
   coclass CMyObj1 { interface IMyObj1; };
}
```

O C2664 também é lançado usando `wchar_t` ao mover o código do Visual C++ 6.0 para versões posteriores. No Visual C++ 6.0 e versões anteriores, `wchar_t` era `typedef` para `unsigned short` e, portanto, podia ser convertido implicitamente nesse tipo. Depois do Visual C++ 6.0, `wchar_t` é seu próprio tipo interno, conforme especificado no padrão C++, e não pode mais ser convertido implicitamente em `unsigned short`. Ver [/ZC: wchar_t (wchar_t Is Native Type)](../../build/reference/zc-wchar-t-wchar-t-is-native-type.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2664 e mostra como corrigi-lo.

```
// C2664h.cpp
#import "C2664g.tlb"
using namespace myproj1;

int main() {
   IMyObj1Ptr ptr;

   wchar_t * mybuff = 0;
   BSTR bstr = 0;
   int len;
   ptr->teststr(mybuff);
   ptr->testbstr(bstr);
   ptr->testarr(mybuff, len);   // C2664
   ptr->testarr((unsigned short *)mybuff, len);   // OK - Fix by using a cast
}
```

## <a name="example"></a>Exemplo

O C2664 também é causado quando o compilador não pode deduzir argumentos do modelo.

```
// C2664i.cpp
#include <stdio.h>
template <class T, int iType=0>
class CTypedImg {
public:
   CTypedImg() {}
   void run() {}

   operator CTypedImg<T>& () {
      return *((CTypedImg<T>*)this);
    }
};

template <class t1>
void test(CTypedImg<t1>& myarg) {
   myarg.run();
}

int main() {
   CTypedImg<float,2> img;

   test((CTypedImg<float>&)img);   // OK
   test<float>(img);   // OK
   test(img);   // C2664 - qualify as above to fix
}
```