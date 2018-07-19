---
title: Funções de Membro de Fluxo de Entrada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- input stream objects
- input streams, member functions
ms.assetid: b4b9465d-0da9-4ccf-859d-72a68418982e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 57288e7eb85e3d23fe8790ac3097cab82acdcf8b
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38954663"
---
# <a name="input-stream-member-functions"></a>Funções de Membro de Fluxo de Entrada

Funções de membro de fluxo de entrada são usadas para entrada de disco. As funções de membro incluem:

- [A função open para fluxos de entrada](#vclrftheopenfunctionforinputstreamsanchor11)

- [Get](#vclrfthegetfunctionanchor12)

- [A getline](#vclrfthegetlinefunctionanchor13)

- [A leitura](#vclrfthereadfunctionanchor14)

- [As funções seekg e tellg](#vclrftheseekgandtellgfunctionsanchor7)

- [A função close para fluxos de entrada](#vclrftheclosefunctionforinputstreamsanchor15)

## <a name="vclrftheopenfunctionforinputstreamsanchor11"></a> A função open para fluxos de entrada

Se estiver usando um fluxo de arquivo de entrada (ifstream), você deverá associar o fluxo a um arquivo de disco específico. Você pode fazer isso no construtor, ou você pode usar o `open` função. Nos dois casos, os argumentos são os mesmos.

Normalmente, você especifica um [ios_base:: OpenMode](../standard-library/ios-base-class.md#openmode) sinalizador quando você abre o arquivo associado a um fluxo de entrada (o modo padrão é `ios::in`). Para obter uma lista de `open_mode` sinalizadores, consulte [abrir](#vclrftheopenfunctionforinputstreamsanchor11). Os sinalizadores podem ser combinados com o operador bit a bit OR ( &#124; ).

Para ler um arquivo, primeiro use o `fail` a função de membro para determinar se ele existe:

```cpp
istream ifile("FILENAME");

if (ifile.fail())
// The file does not exist ...
```

## <a name="vclrfthegetfunctionanchor12"></a> Get

Não formatada `get` função de membro funciona como o `>>` operador com duas exceções. Primeiro, o `get` função inclui caracteres de espaço em branco, enquanto o extrator exclui espaços em branco quando o `skipws` sinalizador é definido (o padrão). Segundo, o `get` função tem menos probabilidade de causar um fluxo de saída associado (`cout`, por exemplo) para ser liberado.

Uma variação do `get` função especifica um endereço do buffer e o número máximo de caracteres a serem lidos. Isso é útil para limitar o número de caracteres enviados para uma variável específica, como este exemplo mostra:

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

## <a name="vclrfthegetlinefunctionanchor13"></a> A getline

O `getline` função de membro é semelhante ao `get` função. As duas funções permitem um terceiro argumento que especifica o caractere de encerramento para a entrada. O valor padrão é o caractere newline. As duas funções reservam um caractere para o caractere de encerramento necessário. No entanto, `get` deixa o caractere de terminação no fluxo e `getline` remove o caractere de terminação.

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

## <a name="vclrfthereadfunctionanchor14"></a> A leitura

O `read` função de membro lê bytes de um arquivo para uma área de memória especificada. O argumento de tamanho especifica o número de bytes lidos. Se você não incluir esse argumento, a leitura para quando o final de arquivo físico é atingido ou, no caso de um arquivo de modo de texto, quando o caractere `EOF` inserido é lido.

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

O programa presume que os registros de dados estão formatados exatamente conforme especificado pela estrutura, sem nenhum caractere de avanço de linha ou de retorno de carro de encerramento.

## <a name="vclrftheseekgandtellgfunctionsanchor7"></a> As funções seekg e tellg

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

Para usar `seekg` para implementar sistemas de gerenciamento de dados orientados a registros, multiplique o tamanho de registro de comprimento fixo pelo número do registro para obter a posição do byte em relação ao final do arquivo e, em seguida, usar o `get` objeto para ler o registro.

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

## <a name="vclrftheclosefunctionforinputstreamsanchor15"></a> A função close para fluxos de entrada

O `close` fecha o arquivo de disco associado a um fluxo de arquivo de entrada de função de membro e libera o identificador de arquivo do sistema operacional. O [ifstream](../standard-library/basic-ifstream-class.md) destruidor fecha o arquivo para você, mas você pode usar o `close` funcionar se você precisar abrir um outro arquivo para o mesmo objeto de fluxo.

## <a name="see-also"></a>Consulte também

[Fluxos de entrada](../standard-library/input-streams.md)<br/>
