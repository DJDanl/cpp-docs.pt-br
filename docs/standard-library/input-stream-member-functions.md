---
title: Funções de Membro de Fluxo de Entrada
ms.date: 07/19/2019
helpviewer_keywords:
- input stream objects
- input streams, member functions
ms.assetid: b4b9465d-0da9-4ccf-859d-72a68418982e
ms.openlocfilehash: b846ff177f3032d81e5c81a39a0111c73a1750fb
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68452065"
---
# <a name="input-stream-member-functions"></a>Funções de Membro de Fluxo de Entrada

Funções de membro de fluxo de entrada são usadas para entrada de disco.

## <a name="vclrftheopenfunctionforinputstreamsanchor11"></a>abrir

Se você estiver usando um fluxo de arquivo de`ifstream`entrada (), deverá associar esse fluxo a um arquivo de disco específico. Você pode fazer isso no construtor ou pode usar a `open` função. Nos dois casos, os argumentos são os mesmos.

Geralmente, você especifica um sinalizador [ios_base:: OpenMode](../standard-library/ios-base-class.md#openmode) quando abre o arquivo associado a um fluxo de entrada (o modo padrão `ios::in`é). Para obter uma lista dos `openmode` sinalizadores, consulte [ios_base:: OpenMode](../standard-library/ios-base-class.md#openmode). Os sinalizadores podem ser combinados com o operador bit a bit OR ( &#124; ).

Para ler um arquivo, primeiro use a `fail` função de membro para determinar se ele existe:

```cpp
istream ifile("FILENAME");

if (ifile.fail())
// The file does not exist ...
```

## <a name="vclrfthegetfunctionanchor12"></a>Obter

A função de `get` membro não formatada funciona como `>>` o operador com duas exceções. Primeiro, a `get` função inclui caracteres de espaço em branco, enquanto o extrator exclui espaço em branco `skipws` quando o sinalizador é definido (o padrão). Em segundo lugar `get` , a função tem menos probabilidade de fazer com que um`cout`fluxo de saída associado (, por exemplo) seja liberado.

Uma variação da `get` função especifica um endereço de buffer e o número máximo de caracteres a serem lidos. Isso é útil para limitar o número de caracteres enviados para uma variável específica, como este exemplo mostra:

```cpp
// ioo_get_function.cpp
// compile with: /EHsc
// Type up to 24 characters and a terminating character.
// Any remaining characters can be extracted later.
#include <iostream>
using namespace std;

int main()
{
   char line[25];
   cout << " Type a line terminated by carriage return\n>";
   cin.get( line, 25 );
   cout << line << endl;
}
```

### <a name="input"></a>Entrada

```Input
1234
```

### <a name="sample-output"></a>Saída de Exemplo

```Output
1234
```

## <a name="vclrfthegetlinefunctionanchor13"></a>getline

A `getline` função de membro é semelhante `get` à função. As duas funções permitem um terceiro argumento que especifica o caractere de encerramento para a entrada. O valor padrão é o caractere newline. As duas funções reservam um caractere para o caractere de encerramento necessário. No entanto, `get` deixa o caractere de terminação `getline` no fluxo e remove o caractere de terminação.

O exemplo a seguir especifica um caractere de encerramento para o fluxo de entrada:

```cpp
// getline_func.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

int main( )
{
   char line[100];
   cout << " Type a line terminated by 't'" << endl;
   cin.getline( line, 100, 't' );
   cout << line;
}
```

### <a name="input"></a>Entrada

```Input
test
```

## <a name="vclrfthereadfunctionanchor14"></a>leitura

A `read` função de membro lê bytes de um arquivo para uma área especificada da memória. O argumento de tamanho especifica o número de bytes lidos. Se você não incluir esse argumento, a leitura para quando o final de arquivo físico é atingido ou, no caso de um arquivo de modo de texto, quando o caractere `EOF` inserido é lido.

Este exemplo lê um registro binário de um arquivo de folha de pagamento em uma estrutura:

```cpp
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
   struct
   {
      double salary;
      char name[23];
   } employee;

   ifstream is( "payroll" );
   if( is ) {  // ios::operator void*()
      is.read( (char *) &employee, sizeof( employee ) );
      cout << employee.name << ' ' << employee.salary << endl;
   }
   else {
      cout << "ERROR: Cannot open file 'payroll'." << endl;
   }
}
```

O programa pressupõe que os registros de dados sejam formatados exatamente conforme especificado pela estrutura sem retorno de carro de encerramento ou caracteres de alimentação de linha.

## <a name="vclrftheseekgandtellgfunctionsanchor7"></a>seekg e tellg

Fluxos de arquivo de entrada mantêm um ponteiro interno para a posição no arquivo em que os dados devem ser lidos em seguida. Defina esse ponteiro com a função `seekg`, conforme mostrado aqui:

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main( )
{
   char ch;

   ifstream tfile( "payroll" );
   if( tfile ) {
      tfile.seekg( 8 );        // Seek 8 bytes in (past salary)
      while ( tfile.good() ) { // EOF or failure stops the reading
         tfile.get( ch );
         if( !ch ) break;      // quit on null
         cout << ch;
      }
   }
   else {
      cout << "ERROR: Cannot open file 'payroll'." << endl;
   }
}
```

Para usar `seekg` o para implementar sistemas de gerenciamento de dados orientados a registros, multiplique o tamanho do registro de comprimento fixo pelo número do registro para obter a posição do byte em relação ao final do arquivo `get` e, em seguida, use o objeto para ler o registro.

A função membro `tellg` retorna a posição do arquivo atual para leitura. Esse valor é do tipo `streampos`, um `typedef` definido em \<iostream>. O exemplo a seguir lê um arquivo e exibe mensagens mostrando as posições de espaços.

```cpp
#include <fstream>
#include <iostream>
using namespace std;

int main( )
{
   char ch;
   ifstream tfile( "payroll" );
   if( tfile ) {
       while ( tfile.good( ) ) {
          streampos here = tfile.tellg();
          tfile.get( ch );
          if ( ch == ' ' )
             cout << "\nPosition " << here << " is a space";
       }
   }
   else {
      cout << "ERROR: Cannot open file 'payroll'." << endl;
   }
}
```

## <a name="vclrftheclosefunctionforinputstreamsanchor15"></a>inclui

A `close` função membro fecha o arquivo de disco associado a um fluxo de arquivo de entrada e libera o identificador de arquivo do sistema operacional. O [`ifstream`](../standard-library/basic-ifstream-class.md) destruidor fecha o arquivo para você, mas você pode usar a `close` função se precisar abrir outro arquivo para o mesmo objeto de fluxo.

## <a name="see-also"></a>Consulte também

[Fluxos de entrada](../standard-library/input-streams.md)
