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
ms.openlocfilehash: 03afb777dc3926284cf0dc625e94a716ecdf5413
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375344"
---
# <a name="ltiostreamgt"></a>&lt;iostream&gt;

Declara objetos que controlam a leitura e a gravação nos fluxos padrão. Isso inclui muitas vezes é o único cabeçalho que você precisa para fazer entrada e saída de um programa C++.

## <a name="syntax"></a>Sintaxe

```cpp
#include <iostream>
```

> [!NOTE]
> A \<biblioteca de> `#include <ios>`iostream usa as `#include <streambuf>` `#include <istream>`declarações e `#include <ostream>` declarações.

## <a name="remarks"></a>Comentários

Os objetos se encaixam em dois grupos:

- [cin,](#cin) [cout,](#cout) [cerr](#cerr)e [tamanco](#clog) são orientados por byte, fazendo transferências convencionais de byte-at-a-time.

- [wcin](#wcin), [wcout](#wcout), [wcerr](#wcerr) e [wclog](#wclog) são voltados aos caracteres largos, convertendo de e para os caracteres largos que o programa manipula internamente.

Uma vez que você faz certas operações em um fluxo, como a entrada padrão, você não pode fazer operações de uma orientação diferente no mesmo fluxo. Portanto, um programa não pode operar de forma intercambiável tanto em [cin](#cin) quanto [em wcin,](#wcin)por exemplo.

Todos os objetos declarados neste cabeçalho compartilham uma propriedade peculiar — você pode assumir que eles \<são construídos antes de qualquer objeto estático que você definir, em uma unidade de tradução que inclui iostream>. Da mesma forma, você pode assumir que esses objetos não são destruídos antes dos destruidores para quaisquer objetos estáticos que você definir. (Os fluxos de saída são, no entanto, liberados durante o término do programa.) Portanto, você pode ler ou escrever com segurança para os fluxos padrão antes da inicialização do programa e após o término do programa.

Essa garantia não é universal, no entanto. Um construtor estático pode chamar uma função em outra unidade de conversão. A função chamada não pode assumir que os objetos declarados neste cabeçalho foram construídos, dada a ordem incerta na qual as unidades de tradução participam da construção estática. Para usar esses objetos em tal contexto, primeiro você precisa criar um objeto da classe [ios_base::Init](../standard-library/ios-base-class.md#init).

### <a name="global-stream-objects"></a>Objetos de fluxo global

|||
|-|-|
|[cerr](#cerr)|Especifica o fluxo global `cerr`.|
|[Cin](#cin)|Especifica o fluxo global `cin`.|
|[Entupir](#clog)|Especifica o fluxo global `clog`.|
|[cout](#cout)|Especifica o fluxo global `cout`.|
|[wcerr](#wcerr)|Especifica o fluxo global `wcerr`.|
|[wcin](#wcin)|Especifica o fluxo global `wcin`.|
|[wclog](#wclog)|Especifica o fluxo global `wclog`.|
|[wcout](#wcout)|Especifica o fluxo global `wcout`.|

### <a name="cerr"></a><a name="cerr"></a>cerr

O objeto `cerr` controla a saída para um buffer de fluxo associado ao objeto `stderr`, declarado em \<cstdio>.

```cpp
extern ostream cerr;
```

#### <a name="return-value"></a>Valor retornado

Um objeto [ostream](../standard-library/ostream-typedefs.md#ostream).

#### <a name="remarks"></a>Comentários

O objeto controla inserções não armazenadas em buffer na saída de erro padrão como um fluxo de bytes. Após o objeto ser construído, a expressão `cerr.`[flags](../standard-library/ios-base-class.md#flags) `&` [unitbuf](../standard-library/ios-functions.md#unitbuf) é diferente de zero e `cerr.tie() == &cout`.

#### <a name="example"></a>Exemplo

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

### <a name="cin"></a><a name="cin"></a>Cin

Especifica o fluxo global `cin`.

```cpp
extern istream cin;
```

#### <a name="return-value"></a>Valor retornado

Um objeto [istream](../standard-library/istream-typedefs.md#istream).

#### <a name="remarks"></a>Comentários

O objeto controla extrações da entrada padrão como um fluxo de bytes. Após o objeto ser criado, a chamada `cin.`[tie](../standard-library/basic-ios-class.md#tie) retorna `&`[cout](#cout).

#### <a name="example"></a>Exemplo

Neste exemplo, `cin` define a parte de falha no fluxo quando se deparar com caracteres não numéricos. O programa limpa o bit de falha e tira o caractere inválido do fluxo para continuar.

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

### <a name="clog"></a><a name="clog"></a>Entupir

Especifica o fluxo global `clog`.

```cpp
extern ostream clog;
```

#### <a name="return-value"></a>Valor retornado

Um objeto [ostream](../standard-library/ostream-typedefs.md#ostream).

#### <a name="remarks"></a>Comentários

O objeto controla inserções armazenadas em buffer na saída de erro padrão como um fluxo de bytes.

#### <a name="example"></a>Exemplo

Consulte [cerr](#cerr) para ver um exemplo de como usar `clog`.

### <a name="cout"></a><a name="cout"></a>cout

Especifica o fluxo global `cout`.

```cpp
extern ostream cout;
```

#### <a name="return-value"></a>Valor retornado

Um objeto [ostream](../standard-library/ostream-typedefs.md#ostream).

#### <a name="remarks"></a>Comentários

O objeto controla inserções na saída padrão como um fluxo de bytes.

#### <a name="example"></a>Exemplo

Consulte [cerr](#cerr) para ver um exemplo de como usar `cout`.

### <a name="wcerr"></a><a name="wcerr"></a>wcerr

Especifica o fluxo global `wcerr`.

```cpp
extern wostream wcerr;
```

#### <a name="return-value"></a>Valor retornado

Um objeto [wostream](../standard-library/ostream-typedefs.md#wostream).

#### <a name="remarks"></a>Comentários

O objeto controla inserções não armazenadas em buffer na saída de erro padrão como um fluxo largo. Após o objeto ser construído, a expressão `wcerr.`[flags](../standard-library/ios-base-class.md#flags) `&` [unitbuf](../standard-library/ios-functions.md#unitbuf) é diferente de zero.

#### <a name="example"></a>Exemplo

Consulte [cerr](#cerr) para ver um exemplo de como usar `wcerr`.

### <a name="wcin"></a><a name="wcin"></a>wcin

Especifica o fluxo global `wcin`.

```cpp
extern wistream wcin;
```

#### <a name="return-value"></a>Valor retornado

Um objeto [wistream](../standard-library/istream-typedefs.md#wistream).

#### <a name="remarks"></a>Comentários

O objeto controla extrações da entrada padrão como um fluxo largo. Após o objeto ser criado, a chamada `wcin.`[tie](../standard-library/basic-ios-class.md#tie) retorna `&`[wcout](#wcout).

#### <a name="example"></a>Exemplo

Consulte [cerr](#cerr) para ver um exemplo de como usar `wcin`.

### <a name="wclog"></a><a name="wclog"></a>wclog

Especifica o fluxo global `wclog`.

```cpp
extern wostream wclog;
```

#### <a name="return-value"></a>Valor retornado

Um objeto [wostream](../standard-library/ostream-typedefs.md#wostream).

#### <a name="remarks"></a>Comentários

O objeto controla inserções armazenadas em buffer na saída de erro padrão como um fluxo largo.

#### <a name="example"></a>Exemplo

Consulte [cerr](#cerr) para ver um exemplo de como usar `wclog`.

### <a name="wcout"></a><a name="wcout"></a>wcout

Especifica o fluxo global `wcout`.

```cpp
extern wostream wcout;
```

#### <a name="return-value"></a>Valor retornado

Um objeto [wostream](../standard-library/ostream-typedefs.md#wostream).

#### <a name="remarks"></a>Comentários

O objeto controla inserções na saída padrão como um fluxo largo.

#### <a name="example"></a>Exemplo

Consulte [cerr](#cerr) para ver um exemplo de como usar `wcout`.

Instâncias de `CString` em uma instrução `wcout` devem ser convertidas em `const wchar_t*`, conforme mostrado no exemplo a seguir.

```cpp
CString cs("meow");

wcout <<(const wchar_t*) cs <<endl;
```

Para obter mais informações, consulte [Operações CString básicas](../atl-mfc-shared/basic-cstring-operations.md).

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Segurança do segmento na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação iostream](../standard-library/iostream-programming.md)\
[Convenções iostreams](../standard-library/iostreams-conventions.md)
