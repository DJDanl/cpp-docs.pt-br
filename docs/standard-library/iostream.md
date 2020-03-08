---
title: '&lt;iostream&gt;'
ms.date: 09/20/2017
f1_keywords:
- <iostream>
- iostream/std::cerr
- iostream/std::cin
- iostream/std::clog
- iostream/std::cout
- iostream/std::wcerr
- iostream/std::wcin
- iostream/std::wclog
- iostream/std::wcout
helpviewer_keywords:
- iostream header
ms.assetid: de5d39e1-7e77-4b55-bcd1-7c77b41515c8
ms.openlocfilehash: 2906e802072c43a93c59ca40d15e032adeeeef97
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78856449"
---
# <a name="ltiostreamgt"></a>&lt;iostream&gt;

Declara objetos que controlam a leitura e a gravação nos fluxos padrão. Essa inclusão é geralmente o único cabeçalho que você precisa para fazer a entrada e a C++ saída de um programa.

## <a name="syntax"></a>Sintaxe

```cpp
#include <iostream>
```

> [!NOTE]
> A biblioteca \<iostream > usa as instruções `#include <ios>`, `#include <streambuf>`, `#include <istream>`e `#include <ostream>`.

## <a name="remarks"></a>Comentários

Os objetos se encaixam em dois grupos:

- [CIN](#cin), [cout](#cout), [cerr](#cerr)e [obstruir](#clog) são orientados por byte, fazendo transferências convencionais de byte em tempo.

- [wcin](#wcin), [wcout](#wcout), [wcerr](#wcerr) e [wclog](#wclog) são voltados aos caracteres largos, convertendo de e para os caracteres largos que o programa manipula internamente.

Depois de realizar determinadas operações em um fluxo, como a entrada padrão, não é possível realizar operações de uma orientação diferente no mesmo fluxo. Portanto, um programa não pode operar de maneira intercambiável em [CIN](#cin) e [wcin](#wcin), por exemplo.

Todos os objetos declarados nesse cabeçalho compartilham uma propriedade peculiar — você pode presumir que eles são construídos antes de qualquer objeto estático que você definir, em uma unidade de tradução que inclua \<iostream >. Igualmente, você pode pressupor que esses objetos não sejam destruídos antes dos destruidores para esses objetos estáticos que você definir. (No entanto, os fluxos de saída são liberados durante o encerramento do programa.) Portanto, você pode ler ou gravar com segurança nos fluxos padrão antes da inicialização do programa e após o encerramento do programa.

No entanto, essa garantia não é universal. Um construtor estático pode chamar uma função em outra unidade de conversão. A função chamada não pode assumir que os objetos declarados neste cabeçalho foram construídos, considerando a ordem incerta em que as unidades de tradução participam da construção estática. Para usar esses objetos em tal contexto, primeiro você precisa criar um objeto da classe [ios_base::Init](../standard-library/ios-base-class.md#init).

### <a name="global-stream-objects"></a>Objetos de fluxo global

|||
|-|-|
|[cerr](#cerr)|Especifica o fluxo global `cerr`.|
|[cin](#cin)|Especifica o fluxo global `cin`.|
|[clog](#clog)|Especifica o fluxo global `clog`.|
|[cout](#cout)|Especifica o fluxo global `cout`.|
|[wcerr](#wcerr)|Especifica o fluxo global `wcerr`.|
|[wcin](#wcin)|Especifica o fluxo global `wcin`.|
|[wclog](#wclog)|Especifica o fluxo global `wclog`.|
|[wcout](#wcout)|Especifica o fluxo global `wcout`.|

###  <a name="cerr"></a>cerr

O objeto `cerr` controla a saída para um buffer de fluxo associado ao objeto `stderr`, declarado em \<cstdio>.

```cpp
extern ostream cerr;
```

#### <a name="return-value"></a>Valor retornado

Um objeto [ostream](../standard-library/ostream-typedefs.md#ostream).

#### <a name="remarks"></a>Comentários

O objeto controla inserções não armazenadas em buffer na saída de erro padrão como um fluxo de bytes. Depois que o objeto é construído, a expressão `cerr.`[sinalizadores](../standard-library/ios-base-class.md#flags) `&` [unitbuf](../standard-library/ios-functions.md#unitbuf) é diferente de zero e `cerr.tie() == &cout`.

#### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// iostream_cerr.cpp
// compile with: /EHsc
#include <iostream>
#include <fstream>

using namespace std;

void TestWide( )
{
   int i = 0;
   wcout << L"Enter a number: ";
   wcin >> i;
   wcerr << L"test for wcerr" << endl;
   wclog << L"test for wclog" << endl;
}

int main( )
{
   int i = 0;
   cout << "Enter a number: ";
   cin >> i;
   cerr << "test for cerr" << endl;
   clog << "test for clog" << endl;
   TestWide( );
}
```

###  <a name="cin"></a>cin

Especifica o fluxo global `cin`.

```cpp
extern istream cin;
```

#### <a name="return-value"></a>Valor retornado

Um objeto [istream](../standard-library/istream-typedefs.md#istream).

#### <a name="remarks"></a>Comentários

O objeto controla extrações da entrada padrão como um fluxo de bytes. Após o objeto ser criado, a chamada `cin.`[tie](../standard-library/basic-ios-class.md#tie) retorna `&`[cout](#cout).

#### <a name="example"></a>{1&gt;Exemplo&lt;1}

Neste exemplo, `cin` define o bit de falha no fluxo quando ele é fornecido entre caracteres não numéricos. O programa limpa o bit de falha e remove o caractere inválido do fluxo para continuar.

```cpp
// iostream_cin.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

int main()
{
   int x;
   cout << "enter choice:";
   cin >> x;
   while (x < 1 || x > 4)
   {
      cout << "Invalid choice, try again:";
      cin >> x;
      // not a numeric character, probably
      // clear the failure and pull off the non-numeric character
      if (cin.fail())
      {
         cin.clear();
         char c;
         cin >> c;
      }
   }
}
```

```Output
2
```

###  <a name="clog"></a>obstruir

Especifica o fluxo global `clog`.

```cpp
extern ostream clog;
```

#### <a name="return-value"></a>Valor retornado

Um objeto [ostream](../standard-library/ostream-typedefs.md#ostream).

#### <a name="remarks"></a>Comentários

O objeto controla inserções armazenadas em buffer na saída de erro padrão como um fluxo de bytes.

#### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte [cerr](#cerr) para ver um exemplo de como usar `clog`.

###  <a name="cout"></a>cout

Especifica o fluxo global `cout`.

```cpp
extern ostream cout;
```

#### <a name="return-value"></a>Valor retornado

Um objeto [ostream](../standard-library/ostream-typedefs.md#ostream).

#### <a name="remarks"></a>Comentários

O objeto controla inserções na saída padrão como um fluxo de bytes.

#### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte [cerr](#cerr) para ver um exemplo de como usar `cout`.

### <a name="wcerr"></a>wcerr

Especifica o fluxo global `wcerr`.

```cpp
extern wostream wcerr;
```

#### <a name="return-value"></a>Valor retornado

Um objeto [wostream](../standard-library/ostream-typedefs.md#wostream).

#### <a name="remarks"></a>Comentários

O objeto controla inserções não armazenadas em buffer na saída de erro padrão como um fluxo largo. Depois que o objeto é construído, a expressão `wcerr.`[sinalizadores](../standard-library/ios-base-class.md#flags) `&` [unitbuf](../standard-library/ios-functions.md#unitbuf) é diferente de zero.

#### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte [cerr](#cerr) para ver um exemplo de como usar `wcerr`.

### <a name="wcin"></a>wcin

Especifica o fluxo global `wcin`.

```cpp
extern wistream wcin;
```

#### <a name="return-value"></a>Valor retornado

Um objeto [wistream](../standard-library/istream-typedefs.md#wistream).

#### <a name="remarks"></a>Comentários

O objeto controla extrações da entrada padrão como um fluxo largo. Após o objeto ser criado, a chamada `wcin.`[tie](../standard-library/basic-ios-class.md#tie) retorna `&`[wcout](#wcout).

#### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte [cerr](#cerr) para ver um exemplo de como usar `wcin`.

### <a name="wclog"></a>wclog

Especifica o fluxo global `wclog`.

```cpp
extern wostream wclog;
```

#### <a name="return-value"></a>Valor retornado

Um objeto [wostream](../standard-library/ostream-typedefs.md#wostream).

#### <a name="remarks"></a>Comentários

O objeto controla inserções armazenadas em buffer na saída de erro padrão como um fluxo largo.

#### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte [cerr](#cerr) para ver um exemplo de como usar `wclog`.

### <a name="wcout"></a>wcout

Especifica o fluxo global `wcout`.

```cpp
extern wostream wcout;
```

#### <a name="return-value"></a>Valor retornado

Um objeto [wostream](../standard-library/ostream-typedefs.md#wostream).

#### <a name="remarks"></a>Comentários

O objeto controla inserções na saída padrão como um fluxo largo.

#### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte [cerr](#cerr) para ver um exemplo de como usar `wcout`.

Instâncias de `CString` em uma instrução `wcout` devem ser convertidas em `const wchar_t*`, conforme mostrado no exemplo a seguir.

```cpp
CString cs("meow");

wcout <<(const wchar_t*) cs <<endl;
```

Para obter mais informações, consulte [Operações CString básicas](../atl-mfc-shared/basic-cstring-operations.md).

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
