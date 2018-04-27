---
title: '&lt;iostream&gt; | Microsoft Docs'
ms.custom: ''
ms.date: 09/20/2017
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- iostream header
ms.assetid: de5d39e1-7e77-4b55-bcd1-7c77b41515c8
caps.latest.revision: 23
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 40b74dea33bbd4ed8436e8e90c35fb054974d0c7
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="ltiostreamgt"></a>&lt;iostream&gt;

Declara objetos que controlam a leitura e a gravação nos fluxos padrão. Frequentemente, este é o único cabeçalho que você precisa incluir para executar a entrada e a saída de um programa C++.

## <a name="syntax"></a>Sintaxe

```cpp
#include <iostream>

```

## <a name="remarks"></a>Comentários

Os objetos se encaixam em dois grupos:

- [cin](#cin), [cout](#cout), [cerr](#cerr) e [clog](#clog) são voltados ao byte, executando transferências convencionais de um byte por vez.

- [wcin](#wcin), [wcout](#wcout), [wcerr](#wcerr) e [wclog](#wclog) são voltados aos caracteres largos, convertendo de e para os caracteres largos que o programa manipula internamente.

Depois de executar determinadas operações em um fluxo, como a entrada padrão, você não pode executar operações de uma orientação diferente no mesmo fluxo. Portanto, um programa não pode operar de forma intercambiável em [cin](#cin) e [wcin](#wcin), por exemplo.

Todos os objetos declarados nesse cabeçalho compartilham uma propriedade peculiar — você pode presumir que eles foram construídos antes de qualquer objeto estático que você definir, em uma unidade de conversão que inclui \<iostream>. Da mesma forma, você pode presumir que esses objetos não são destruídos antes dos destruidores de qualquer um desses objetos estáticos que você definir. (Os fluxos de saída são, no entanto, liberados durante o encerramento do programa.) Portanto, você pode, com segurança, ler ou gravar em fluxos padrão antes da inicialização do programa e após o encerramento do programa.

No entanto, essa garantia não é universal. Um construtor estático pode chamar uma função em outra unidade de conversão. A função chamada não pode presumir que os objetos declarados nesse cabeçalho foram construídos, dada a ordem incerta na qual as unidades de conversão participam da construção estática. Para usar esses objetos em tal contexto, primeiro você precisa criar um objeto da classe [ios_base::Init](../standard-library/ios-base-class.md#init).

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

###  <a name="cerr"></a>  cerr

O objeto `cerr` controla a saída para um buffer de fluxo associado ao objeto `stderr`, declarado em \<cstdio>.

```cpp
extern ostream cerr;
```

#### <a name="return-value"></a>Valor de retorno

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

###  <a name="cin"></a>  cin

Especifica o fluxo global `cin`.

```cpp
extern istream cin;
```

#### <a name="return-value"></a>Valor de retorno

Um objeto [istream](../standard-library/istream-typedefs.md#istream).

#### <a name="remarks"></a>Comentários

O objeto controla extrações da entrada padrão como um fluxo de bytes. Após o objeto ser criado, a chamada `cin.`[tie](../standard-library/basic-ios-class.md#tie) retorna `&`[cout](#cout).

#### <a name="example"></a>Exemplo

Neste exemplo, `cin` define o bit de falha no fluxo quando encontra caracteres não numéricos. O programa limpa o bit de falha e retira o caractere inválido do fluxo para continuar.

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

###  <a name="clog"></a>  clog

Especifica o fluxo global `clog`.

```cpp
extern ostream clog;
```

#### <a name="return-value"></a>Valor de retorno

Um objeto [ostream](../standard-library/ostream-typedefs.md#ostream).

#### <a name="remarks"></a>Comentários

O objeto controla inserções armazenadas em buffer na saída de erro padrão como um fluxo de bytes.

#### <a name="example"></a>Exemplo

Consulte [cerr](#cerr) para ver um exemplo de como usar `clog`.

###  <a name="cout"></a>  cout

Especifica o fluxo global `cout`.

```cpp
extern ostream cout;
```

#### <a name="return-value"></a>Valor de retorno

Um objeto [ostream](../standard-library/ostream-typedefs.md#ostream).

#### <a name="remarks"></a>Comentários

O objeto controla inserções na saída padrão como um fluxo de bytes.

#### <a name="example"></a>Exemplo

Consulte [cerr](#cerr) para ver um exemplo de como usar `cout`.

###  <a name="wcerr"></a>  wcerr

Especifica o fluxo global `wcerr`.

```cpp
extern wostream wcerr;
```

#### <a name="return-value"></a>Valor de retorno

Um objeto [wostream](../standard-library/ostream-typedefs.md#wostream).

#### <a name="remarks"></a>Comentários

O objeto controla inserções não armazenadas em buffer na saída de erro padrão como um fluxo largo. Após o objeto ser construído, a expressão `wcerr.`[flags](../standard-library/ios-base-class.md#flags) `&` [unitbuf](../standard-library/ios-functions.md#unitbuf) é diferente de zero.

#### <a name="example"></a>Exemplo

Consulte [cerr](#cerr) para ver um exemplo de como usar `wcerr`.

###  <a name="wcin"></a>  wcin

Especifica o fluxo global `wcin`.

```cpp
extern wistream wcin;
```

#### <a name="return-value"></a>Valor de retorno

Um objeto [wistream](../standard-library/istream-typedefs.md#wistream).

#### <a name="remarks"></a>Comentários

O objeto controla extrações da entrada padrão como um fluxo largo. Após o objeto ser criado, a chamada `wcin.`[tie](../standard-library/basic-ios-class.md#tie) retorna `&`[wcout](#wcout).

#### <a name="example"></a>Exemplo

Consulte [cerr](#cerr) para ver um exemplo de como usar `wcin`.

###  <a name="wclog"></a>  wclog

Especifica o fluxo global `wclog`.

```cpp
extern wostream wclog;
```

#### <a name="return-value"></a>Valor de retorno

Um objeto [wostream](../standard-library/ostream-typedefs.md#wostream).

#### <a name="remarks"></a>Comentários

O objeto controla inserções armazenadas em buffer na saída de erro padrão como um fluxo largo.

#### <a name="example"></a>Exemplo

Consulte [cerr](#cerr) para ver um exemplo de como usar `wclog`.

###  <a name="wcout"></a>  wcout

Especifica o fluxo global `wcout`.

```cpp
extern wostream wcout;
```

#### <a name="return-value"></a>Valor de retorno

Um objeto [wostream](../standard-library/ostream-typedefs.md#wostream).

#### <a name="remarks"></a>Comentários

O objeto controla inserções na saída padrão como um fluxo largo.

#### <a name="example"></a>Exemplo

Consulte [cerr](#cerr) para ver um exemplo de como usar `wcout`.

Instâncias de `CString` em uma instrução `wcout` devem ser convertidas em `const wchar_t*`, conforme mostrado no exemplo a seguir.

```

    CString cs("meow");

    wcout <<(const wchar_t*) cs <<endl;
```

Para obter mais informações, consulte [Operações CString básicas](../atl-mfc-shared/basic-cstring-operations.md).

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Programação de iostream](../standard-library/iostream-programming.md)<br/>
[Convenções de iostreams](../standard-library/iostreams-conventions.md)<br/>
