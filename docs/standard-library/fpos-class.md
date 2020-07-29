---
title: Classe fpos
ms.date: 03/27/2019
f1_keywords:
- iosfwd/std::fpos
- iosfwd/std::fpos::seekpos
- iosfwd/std::fpos::state
- iosfwd/std::fpos::operator streamoff
helpviewer_keywords:
- std::fpos [C++]
- std::fpos [C++], seekpos
- std::fpos [C++], state
ms.assetid: ffd0827c-fa34-47f4-b10e-5cb707fcde47
ms.openlocfilehash: 37536443455ca4ddc40568e15951b814982d4ad9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87193296"
---
# <a name="fpos-class"></a>Classe fpos

O modelo de classe descreve um objeto que pode armazenar todas as informações necessárias para restaurar um indicador de posição de arquivo arbitrário dentro de qualquer fluxo. Um objeto da classe fPos \< **St**> armazena efetivamente pelo menos dois objetos Membros:

- Um deslocamento de bytes, do tipo [streamoff](../standard-library/ios-typedefs.md#streamoff).

- Um estado de conversão, para uso por um objeto da classe basic_filebuf, do tipo `St` , normalmente `mbstate_t` .

Ele também pode armazenar uma posição de arquivo arbitrária, para uso por um objeto da classe [basic_filebuf](../standard-library/basic-filebuf-class.md), do tipo `fpos_t`. Para um ambiente com tamanho do arquivo limitado, no entanto, `streamoff` e `fpos_t` podem às vezes ser usados de maneira intercambiável. Para um ambiente sem fluxos com uma codificação dependente do estado, `mbstate_t` pode ficar sem uso. Portanto, o número de objetos membro armazenados pode variar.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Statetype>
class fpos
```

### <a name="parameters"></a>parâmetros

*Statetype*\
Informações de estado.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[fpos](#fpos)|Cria um objeto que contém informações sobre uma posição (deslocamento) em um fluxo.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[seekpos](#seekpos)|Usado internamente apenas pela Biblioteca Padrão C++. Não chame este método do seu código.|
|[state](#state)|Define ou retorna o estado da conversão.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador! =](#op_neq)|Testa indicadores de posição do arquivo quanto à desigualdade.|
|[operador +](#op_add)|Incrementa um indicador de posição de arquivo.|
|[operador + =](#op_add_eq)|Incrementa um indicador de posição de arquivo.|
|[operador](#operator-)|Diminui um indicador de posição de arquivo.|
|[operador-=](#operator-_eq)|Diminui um indicador de posição de arquivo.|
|[operador = =](#op_eq_eq)|Testa indicadores de posição do arquivo quanto à igualdade.|
|[operator streamoff](#op_streamoff)|Converte um objeto do tipo `fpos` para um objeto do tipo `streamoff`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<ios>

**Namespace:** std

## <a name="fposfpos"></a><a name="fpos"></a>fpos::fpos

Cria um objeto que contém informações sobre uma posição (deslocamento) em um fluxo.

```cpp
fpos(streamoff _Off = 0);

fpos(Statetype _State, fpos_t _Filepos);
```

### <a name="parameters"></a>parâmetros

*_Off*\
O deslocamento no fluxo.

*_State*\
O estado inicial do objeto `fpos`.

*_Filepos*\
O deslocamento no fluxo.

### <a name="remarks"></a>Comentários

O primeiro Construtor armazena o deslocamento *_Off*, em relação ao início do arquivo e no estado de conversão inicial (se isso for importante). Se *_Off* for-1, o objeto resultante representará uma posição de fluxo inválida.

O segundo Construtor armazena um deslocamento zero e o objeto *_State*.

## <a name="fposoperator"></a><a name="op_neq"></a>fPos:: Operator! =

Testa indicadores de posição do arquivo quanto à desigualdade.

```cpp
bool operator!=(const fpos<Statetype>& right) const;
```

### <a name="parameters"></a>parâmetros

*Certo*\
O indicador de posição do arquivo para comparação.

### <a name="return-value"></a>Valor retornado

**`true`** Se os indicadores de posição de arquivo não forem iguais, caso contrário **`false`** .

### <a name="remarks"></a>Comentários

A função membro retorna `!(*this == right)`.

### <a name="example"></a>Exemplo

```cpp
// fpos_op_neq.cpp
// compile with: /EHsc
#include <fstream>
#include <iostream>

int main( )
{
   using namespace std;

   fpos<int> pos1, pos2;
   ifstream file;
   char c;

   // Compare two fpos object
   if ( pos1 != pos2 )
      cout << "File position pos1 and pos2 are not equal" << endl;
   else
      cout << "File position pos1 and pos2 are equal" << endl;

   file.open( "fpos_op_neq.txt" );
   file.seekg( 0 );   // Goes to a zero-based position in the file
   pos1 = file.tellg( );
   file.get( c);
   cout << c << endl;

   // Increment pos1
   pos1 += 1;
   file.get( c );
   cout << c << endl;

   pos1 = file.tellg( ) - fpos<int>( 2);
   file.seekg( pos1 );
   file.get( c );
   cout << c << endl;

   // Increment pos1
   pos1 = pos1 + fpos<int>( 1 );
   file.get(c);
   cout << c << endl;

   pos1 -= fpos<int>( 2 );
   file.seekg( pos1 );
   file.get( c );
   cout << c << endl;

   file.close( );
}
```

## <a name="fposoperator"></a><a name="op_add"></a>fPos:: Operator +

Incrementa um indicador de posição de arquivo.

```cpp
fpos<Statetype> operator+(streamoff _Off) const;
```

### <a name="parameters"></a>parâmetros

*_Off*\
O deslocamento segundo o qual você deseja incrementar o indicador de posição do arquivo.

### <a name="return-value"></a>Valor retornado

A posição no arquivo.

### <a name="remarks"></a>Comentários

A função membro retorna **fpos(\*this) +=** `_Off`.

### <a name="example"></a>Exemplo

Consulte [operator!=](#op_neq) para ver uma amostra do uso de `operator+`.

## <a name="fposoperator"></a><a name="op_add_eq"></a>fPos:: Operator + =

Incrementa um indicador de posição de arquivo.

```cpp
fpos<Statetype>& operator+=(streamoff _Off);
```

### <a name="parameters"></a>parâmetros

*_Off*\
O deslocamento segundo o qual você deseja incrementar o indicador de posição do arquivo.

### <a name="return-value"></a>Valor retornado

A posição no arquivo.

### <a name="remarks"></a>Comentários

A função membro adiciona *_Off* ao objeto de membro de deslocamento armazenado e, em seguida, retorna ** \* isso**. Para o posicionamento dentro de um arquivo, o resultado normalmente é válido apenas para fluxos binários que não têm uma codificação dependente do estado.

### <a name="example"></a>Exemplo

Consulte [operator!=](#op_neq) para ver uma amostra do uso de `operator+=`.

## <a name="fposoperator-"></a><a name="operator-"></a>operador fPos:: Operator

Diminui um indicador de posição de arquivo.

```cpp
streamoff operator-(const fpos<Statetype>& right) const;

fpos<Statetype> operator-(streamoff _Off) const;
```

### <a name="parameters"></a>parâmetros

*Certo*\
Posição do arquivo.

*_Off*\
Deslocamento do fluxo.

### <a name="return-value"></a>Valor retornado

A primeira função membro retorna `(streamoff)*this - (streamoff) right`. A segunda função membro retorna `fpos(*this) -= _Off`.

### <a name="example"></a>Exemplo

Consulte [operator!=](#op_neq) para ver uma amostra do uso de `operator-`.

## <a name="fposoperator-"></a><a name="operator-_eq"></a>fPos:: Operator-=

Diminui um indicador de posição de arquivo.

```cpp
fpos<Statetype>& operator-=(streamoff _Off);
```

### <a name="parameters"></a>parâmetros

*_Off*\
Deslocamento do fluxo.

### <a name="return-value"></a>Valor retornado

A função membro retorna `fpos(*this) -= _Off`.

### <a name="remarks"></a>Comentários

Para o posicionamento dentro de um arquivo, o resultado normalmente é válido apenas para fluxos binários que não têm uma codificação dependente do estado.

### <a name="example"></a>Exemplo

Consulte [operator!=](#op_neq) para ver uma amostra do uso de `operator-=`.

## <a name="fposoperator"></a><a name="op_eq_eq"></a>fPos:: Operator = =

Testa indicadores de posição do arquivo quanto à igualdade.

```cpp
bool operator==(const fpos<Statetype>& right) const;
```

### <a name="parameters"></a>parâmetros

*Certo*\
O indicador de posição do arquivo para comparação.

### <a name="return-value"></a>Valor retornado

**`true`** Se os indicadores de posição do arquivo forem iguais; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

A função membro retorna `(streamoff)*this == (streamoff)right`.

### <a name="example"></a>Exemplo

Consulte [operator!=](#op_neq) para ver uma amostra do uso de `operator+=`.

## <a name="fposoperator-streamoff"></a><a name="op_streamoff"></a>operador fPos:: Operator streamoff

Converte um objeto do tipo `fpos` para um objeto do tipo `streamoff`.

```cpp
operator streamoff() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o objeto membro de deslocamento armazenado e qualquer deslocamento adicional armazenado como parte do objeto membro `fpos_t`.

### <a name="example"></a>Exemplo

```cpp
// fpos_op_streampos.cpp
// compile with: /EHsc
#include <ios>
#include <iostream>
#include <fstream>

int main( )
{
   using namespace std;
   streamoff s;
   ofstream file( "rdbuf.txt");

   fpos<mbstate_t> f = file.tellp( );
   // Is equivalent to ..
   // streampos f = file.tellp( );
   s = f;
   cout << s << endl;
}
```

```Output
0
```

## <a name="fposseekpos"></a><a name="seekpos"></a>fpos::seekpos

Este método é usado internamente apenas pela Biblioteca Padrão C++. Não chame este método do seu código.

```cpp
fpos_t seekpos() const;
```

## <a name="fposstate"></a><a name="state"></a>fPos:: State

Define ou retorna o estado da conversão.

```cpp
Statetype state() const;

void state(Statetype _State);
```

### <a name="parameters"></a>parâmetros

*_State*\
O novo estado de conversão.

### <a name="return-value"></a>Valor retornado

O estado de conversão.

### <a name="remarks"></a>Comentários

A primeira função de membro retorna o valor armazenado no `St` objeto member. A segunda função de membro armazena *_State* no `St` objeto de membro.

### <a name="example"></a>Exemplo

```cpp
// fpos_state.cpp
// compile with: /EHsc
#include <ios>
#include <iostream>
#include <fstream>

int main() {
   using namespace std;
   streamoff s;
   ifstream file( "fpos_state.txt" );

   fpos<mbstate_t> f = file.tellg( );
   char ch;
   while ( !file.eof( ) )
      file.get( ch );
   s = f;
   cout << f.state( ) << endl;
   f.state( 9 );
   cout << f.state( ) << endl;
}
```

## <a name="see-also"></a>Confira também

[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
