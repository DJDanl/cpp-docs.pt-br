---
title: "Fun&#231;&#245;es de Membro de Fluxo de Arquivo de Sa&#237;da | Microsoft Docs"
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
  - "fluxos de saída, funções de membro"
ms.assetid: 38aaf710-8035-4a34-a0c4-123a5327f28a
caps.latest.revision: 8
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Fun&#231;&#245;es de Membro de Fluxo de Arquivo de Sa&#237;da
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As funções de membro do fluxo de saída tem três tipos: os que são equivalentes aos manipuladores, os que executam operações de gravação sem formatação, e esses que modificam de outra forma o estado de fluxo e não têm nenhum manipulador ou operador equivalente de inserção.  Para saída sequenciais, formatado, você pode usar apenas operadores e manipuladores de inserção.  Para saída binária de acesso aleatório de disco, você usa outras funções de membro, com ou sem operadores de inserção.  
  
## A função aberta para fluxos de saída  
 Para usar um fluxo de arquivo de saída \([ofstream](../Topic/ofstream.md)\), você deverá associar esse fluxo com um arquivo de disco específico no construtor ou na função de **open** .  Se você usar a função de **open** , você pode reutilizar o mesmo objeto de fluxo com uma série de arquivos.  Em ambos os casos, os argumentos que descrevem o arquivo são os mesmos.  
  
 Quando você abre o arquivo associado a um fluxo de saída, você geralmente especificará um sinalizador de **open\_mode** .  Você pode combinar essas sinalizadores, que são definidos como enumeradores da classe de `ios` , com o bit a bit OR \( &#124; operador\).  Consulte [ios\_base::openmode](../Topic/ios_base::openmode.md) para obter uma lista dos enumeradores.  
  
 Três situações comuns do fluxo de saída envolvem opções de modo:  
  
-   Criando um arquivo.  Se o arquivo já existir, a versão antiga é excluída.  
  
    ```  
    ostream ofile( "FILENAME" );  // Default is ios::out  
    ofstream ofile( "FILENAME", ios::out ); // Equivalent to above  
    ```  
  
-   Adicionando registros a um arquivo existente ou criar uma se não existir.  
  
    ```  
    ofstream ofile( "FILENAME", ios::app );  
    ```  
  
-   Abrindo dois arquivos, um de cada vez, no mesmo fluxo.  
  
    ```  
    ofstream ofile();  
    ofile.open( "FILE1", ios::in );  
    // Do some output  
    ofile.close(); // FILE1 closed  
    ofile.open( "FILE2", ios::in );  
    // Do some more output  
    ofile.close(); // FILE2 closed  
    // When ofile goes out of scope it is destroyed.  
    ```  
  
## A função colocada  
 A função de **put** grava um caractere ao fluxo de saída.  As duas instruções a seguir são as mesmas por padrão, mas a segunda são afetadas pelos argumentos de formato de fluxo:  
  
```  
cout.put( 'A' ); // Exactly one character written  
cout << 'A'; // Format arguments 'width' and 'fill' apply   
```  
  
## A função de gravação  
 A função de **write** grava um bloco de memória a um fluxo de arquivos de saída.  O comprimento do argumento especifica o número de bytes gravados.  Este exemplo cria um fluxo de arquivos de saída e escreve\-lhe o valor binário da estrutura de `Date` :  
  
```  
// write_function.cpp  
// compile with: /EHsc  
#include <fstream>  
using namespace std;  
  
struct Date  
{  
   int mo, da, yr;  
};  
  
int main( )  
{  
   Date dt = { 6, 10, 92 };  
   ofstream tfile( "date.dat" , ios::binary );  
   tfile.write( (char *) &dt, sizeof dt );  
}  
```  
  
 A função de **write** não para quando alcança um caractere nulo, a estrutura da classe completo é escrita.  A função usa dois argumentos: um ponteiro de `char` e uma contagem de caracteres a serem gravados.  Observe a conversão necessária a **char\*** para que o endereço do objeto da estrutura.  
  
## As funções de seekp e de tellp  
 Um fluxo de arquivo de saída mantém um ponteiro interno que aponta para a posição na qual os dados devem ser escrita em seguida.  A função de membro de `seekp` define esse ponteiro e fornece para saída de acesso aleatório do arquivo em disco.  A função de membro de `tellp` retorna a posição do arquivo.  Para obter exemplos que usam os equivalentes do fluxo de entrada a `seekp` e a `tellp`, consulte [As funções de seekg e de tellg](../standard-library/input-stream-member-functions.md).  
  
## Próximo a função para fluxos de saída  
 A função de membro de **close** fecha o arquivo em disco associado a um fluxo de arquivo de saída.  O arquivo deve ser fechado para concluir todas as saídas de disco.  Se necessário, o destruidor de `ofstream` fecha o arquivo para você, mas você pode usar a função de **close** se você precisar abrir outro arquivo para o mesmo objeto de fluxo.  
  
 O destruidor do fluxo de saída fecha automaticamente o arquivo de um fluxo apenas se o construtor ou a função de membro de **open** abertos o arquivo.  Se você passa o construtor um descritor de um arquivo de Abrir ou já usa a função de membro de **attach** , feche o arquivo explicitamente.  
  
##  <a name="vclrferrorprocessingfunctionsanchor10"></a> Funções de processamento de erro  
 Use essas funções de membro para testar se há erros gravados em um fluxo:  
  
|Função|Valor de retorno|  
|------------|----------------------|  
|[ruim](../Topic/basic_ios::bad.md)|Retorna **true** se houver um erro irrecuperável.|  
|[falha](../Topic/basic_ios::fail.md)|Retorna **true** se houver um erro irrecuperável ou uma condição prevista “”, como um erro de conversão, ou se o arquivo não é encontrado.  O processamento pode frequentemente continuar depois de uma chamada a **clear** com um argumento zero.|  
|[bom](../Topic/basic_ios::good.md)|Retorna **true** se não houver nenhuma condição de erro \(irrecuperável ou não\) e o sinalizador de participante de Arquivo não é definido.|  
|[EOF](../Topic/basic_ios::eof.md)|Retorna **true** na condição de participante de Arquivo.|  
|[limpar](../Topic/basic_ios::clear.md)|Define o estado do erro interno.  Se for chamado com os argumentos padrão, desmarcará todos os bits de erro.|  
|[rdstate](../Topic/basic_ios::rdstate.md)|Retorna o estado atual do erro.|  
  
 O operador de **\!** é sobrecarregado para executar a mesma função da função de **fail** .  Então a expressão:  
  
```  
if( !cout)...  
```  
  
 é equivalente a:  
  
```  
if( cout.fail() )...  
```  
  
 O operador de **void\*\(\)** é sobrecarregado para ser o oposto do operador de **\!** ; então a expressão:  
  
```  
if( cout)...  
```  
  
 é igual a:  
  
```  
if( !cout.fail() )...  
```  
  
 O operador de **void\*\(\)** não é equivalente a **good** porque não testa para a fim de arquivo.  
  
## Consulte também  
 [Fluxos de Saída](../standard-library/output-streams.md)