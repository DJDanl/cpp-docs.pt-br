---
title: "Fun&#231;&#245;es de Membro de Fluxo de Entrada | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "objetos de fluxo de entrada"
  - "fluxos de entrada, funções de membro"
ms.assetid: b4b9465d-0da9-4ccf-859d-72a68418982e
caps.latest.revision: 7
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Fun&#231;&#245;es de Membro de Fluxo de Entrada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As funções de membro do fluxo de entrada são usadas para entrada de disco.  As funções de membro incluem:  
  
-   [A função aberta para fluxos de entrada](#vclrftheopenfunctionforinputstreamsanchor11)  
  
-   [A função obter](#vclrfthegetfunctionanchor12)  
  
-   [A função de getline](#vclrfthegetlinefunctionanchor13)  
  
-   [A função de leitura](#vclrfthereadfunctionanchor14)  
  
-   [As funções de seekg e de tellg](#vclrftheseekgandtellgfunctionsanchor7)  
  
-   [Próximo a função para fluxos de entrada](#vclrftheclosefunctionforinputstreamsanchor15)  
  
##  <a name="vclrftheopenfunctionforinputstreamsanchor11"></a> A função aberta para fluxos de entrada  
 Se você estiver usando um fluxo de arquivo de entrada \(ifstream\), você deverá associar esse fluxo com um arquivo de disco específico.  Você pode fazer isso no construtor, ou você pode usar a função de **open** .  Em ambos os casos, os argumentos forem os mesmos.  
  
 Você geralmente especificará um sinalizador de [ios\_base::openmode](../Topic/ios_base::openmode.md) quando você abre o arquivo associado a um fluxo de entrada \(o modo padrão é **ios::in**\).  Para obter uma lista de sinalizadores de **open\_mode** , consulte [A função aberta](#vclrftheopenfunctionforinputstreamsanchor11).  Os sinalizadores podem ser combinados com o bit a bit OR \( &#124; operador\).  
  
 Para ler um arquivo, primeiro use a função de membro de **fail** para determinar se existe:  
  
```  
istream ifile( "FILENAME" );  
if ( ifile.fail() )  
// The file does not exist ...  
```  
  
##  <a name="vclrfthegetfunctionanchor12"></a> A função obter  
 A função de membro sem formatação de **get** funciona como o operador de **\>\>** com duas exceções.  Primeiro, a função de **get** inclui caracteres de espaço em branco, enquanto o extrator exclui o espaço em branco quando o sinalizador de [skipws](../Topic/skipws.md) é definido como \(o padrão\).  Segundo, a função de **get** é menos prováveis que causam um fluxo de saída vinculado \(`cout`, por exemplo\) seja liberado.  
  
 Uma variação da função de **get** especifica um endereço de um buffer e o número máximo de caracteres a serem lidos.  Isso é útil para limitar o número de caracteres enviados a uma variável específica, pois esse exemplo mostra:  
  
```  
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
  
### Entrada  
  
```  
1234  
```  
  
### Saída de Exemplo  
  
```  
1234  
```  
  
##  <a name="vclrfthegetlinefunctionanchor13"></a> A função de getline  
 A função de membro de **getline** é semelhante à função de **get** .  Ambas as funções permitem um terceiro argumento que especifica o caractere terminador para a entrada.  O valor padrão é o caractere de nova linha.  Ambas as funções permitem um caractere por caractere terminador necessário.  No entanto, **get** permite que o caractere terminador no fluxo e **getline** remove o caractere terminador.  
  
 O exemplo a seguir especifica um caractere terminador para o fluxo de entrada:  
  
```  
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
  
### Entrada  
  
```  
test  
```  
  
##  <a name="vclrfthereadfunctionanchor14"></a> A função de leitura  
 A função de membro de **read** bytes de leitura de um arquivo em uma área especificada de memória.  O argumento de comprimento determina o número de bytes lidos.  Se você não incluir o argumento, para ler quando a fim de arquivo físico é atingida ou, no caso de um arquivo de modo gráfico, quando um caractere inserida de `EOF` será lido.  
  
 Este exemplo lê um registro binária de um arquivo de folha de pagamento em uma estrutura:  
  
```  
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
  
 O programa supõe que os registros de dados são formatados exatamente conforme especificado pela estrutura sem finalizar caracteres de retorno ou de alimentação de linha.  
  
##  <a name="vclrftheseekgandtellgfunctionsanchor7"></a> As funções de seekg e de tellg  
 Os fluxos do arquivo de entrada mantém um ponteiro interno à posição no arquivo onde os dados devem ser lidas em seguida.  Você definir esse ponteiro com a função de `seekg` , como mostrado a seguir:  
  
```  
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
  
 Para usar `seekg` para implementar interfaces orientou sistemas de gerenciamento de dados, multiplica o tamanho de registro de comprimento fixo pelo número do registro para obter a posição de bytes relacionado ao final do arquivo, e depois usa o objeto de **get** para ler o registro.  
  
 A função de membro de `tellg` retorna a posição atual do arquivo para leitura.  Esse valor é do tipo `streampos`, `typedef` definido \<em iostream\>.  O exemplo a seguir lê um arquivo e exibe mensagens que mostram as posições de espaços.  
  
```  
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
  
##  <a name="vclrftheclosefunctionforinputstreamsanchor15"></a> Próximo a função para fluxos de entrada  
 A função de membro de **close** fecha o arquivo em disco associado a um fluxo de arquivo de entrada e libera o identificador de arquivo do sistema operacional.  O destruidor de [ifstream](../standard-library/basic-ifstream-class.md) fecha o arquivo para você, mas você pode usar a função de **close** se você precisar abrir outro arquivo para o mesmo objeto de fluxo.  
  
## Consulte também  
 [Fluxos de entrada](../standard-library/input-streams.md)