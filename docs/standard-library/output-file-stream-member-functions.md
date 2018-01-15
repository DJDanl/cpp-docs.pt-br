---
title: "Funções de Membro de Fluxo de Arquivo de Saída | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: output streams [C++], member functions
ms.assetid: 38aaf710-8035-4a34-a0c4-123a5327f28a
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 25313cce5d032c4c3975fffbf8ca89b232031661
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="output-file-stream-member-functions"></a>Funções de Membro de Fluxo de Arquivo de Saída
Funções de membro de fluxo de saída têm três tipos: aqueles que são equivalentes aos manipuladores, aqueles que executam operações de gravação sem formatação e aqueles que modificam o fluxo do estado e não têm nenhum manipulador ou operador de inserção equivalente. Para saída sequencial e formatada, você pode usar somente os operadores de inserção e manipuladores. Para saída de disco binário de acesso aleatório, você usar outras funções de membro, com ou sem operadores de inserção.  
  
## <a name="the-open-function-for-output-streams"></a>A função open para fluxos de saída  
 Para usar um fluxo de arquivo de saída ([ofstream](../standard-library/basic-ofstream-class.md)), você deve associar esse fluxo a um arquivo de disco específico no construtor ou na função **open**. Se você usar a função **open**, poderá reutilizar o mesmo objeto de fluxo com uma série de arquivos. Em ambos os casos, os argumentos que descrevem o arquivo são os mesmos.  
  
 Ao abrir o arquivo associado a um fluxo de saída, geralmente você especifica um sinalizador **open_mode**. Você pode combinar esses sinalizadores, que são definidos como enumeradores na classe `ios`, com o operador OR bit a bit ( &#124; ). Consulte [ios_base::openmode](../standard-library/ios-base-class.md#openmode) para obter uma lista dos enumeradores.  
  
 Três situações de fluxo de saída comuns envolvem as opções de modo:  
  
-   Criando um arquivo. Se o arquivo já existir, a versão antiga será excluída.  
  
 ```  
    ostream ofile("FILENAME");
// Default is ios::out  
    ofstream ofile("FILENAME", ios::out);

// Equivalent to above  
```  
  
-   Anexando registros a um arquivo existente ou criando um se ele não existir.  
  
 ```  
    ofstream ofile("FILENAME", ios::app);
```  
  
-   Abrindo os dois arquivos, um de cada vez, no mesmo fluxo.  
  
 ```  
    ofstream ofile();
ofile.open("FILE1",
    ios::in);
// Do some output  
    ofile.close();

// FILE1 closed  
    ofile.open("FILE2",
    ios::in);
// Do some more output  
    ofile.close();

// FILE2 closed  // When ofile goes out of scope it is destroyed.  
```  
  
## <a name="the-put"></a>O put
 A função **put** grava um caractere no fluxo de saída. As duas instruções a seguir são as mesmas por padrão, mas a segunda é afetada pelos argumentos de formatação do fluxo:  
  
```  
cout.put('A');

// Exactly one character written  
cout <<'A'; // Format arguments 'width' and 'fill' apply   
```  
  
## <a name="the-write"></a>A gravação
 A função **write** grava um bloco de memória para um fluxo de arquivo de saída. O argumento de tamanho especifica o número de bytes gravados. Este exemplo cria um fluxo de arquivo de saída e grava o valor binário da estrutura `Date` nele:  
  
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
  
 A função **write** não é interrompida quando atinge um caractere nulo, portanto, a estrutura de classe completa é gravada. A função adota dois argumentos: um ponteiro `char` e uma contagem de caracteres a serem gravados. Observe a conversão necessária para **char\*** antes do endereço do objeto de estrutura.  
  
## <a name="the-seekp-and-tellp-functions"></a>As funções seekp e tellp  
 Um fluxo de arquivo de saída mantém um ponteiro interno que aponta para a posição em que os dados serão serem gravados em seguida. A função membro `seekp` define esse ponteiro e, portanto, fornece a saída do arquivo de disco de acesso aleatório. A função membro `tellp` retorna a posição do arquivo. Para obter exemplos que usam os equivalentes de fluxo de entrada para `seekp` e `tellp`, consulte [As funções seekg e tellg](../standard-library/input-stream-member-functions.md).  
  
## <a name="the-close-function-for-output-streams"></a>A função close para fluxos de saída  
 A função membro **close** fecha o arquivo de disco associado a um fluxo de arquivo de saída. O arquivo deve ser fechado para concluir todas as saídas de disco. Se necessário, o destruidor `ofstream` fecha o arquivo para você, mas você pode usar a função **close** se precisar abrir um outro arquivo para o mesmo objeto de fluxo.  
  
 O destruidor de fluxo de saída fecha automaticamente um arquivo do fluxo somente se o construtor ou a função de membro **open** abriram o arquivo. Se você passar para o construtor um descritor de arquivo para um arquivo já aberto ou usar a função membro **attach**, será necessário fechá-lo explicitamente.  
  
##  <a name="vclrferrorprocessingfunctionsanchor10"></a> Erro ao processar funções  
 Use essas funções membro para testar se há erros ao gravar em um fluxo:  
  
|Função|Valor retornado|  
|--------------|------------------|  
|[bad](http://msdn.microsoft.com/Library/4038d331-e9c9-48b0-bf49-c6505744469c)|Retorna **true** se houver um erro irrecuperável.|  
|[fail](http://msdn.microsoft.com/Library/619f1b36-1e72-4551-8b48-888ae4e370d2)|Retorna **true** se houver um erro irrecuperável ou uma condição “esperada”, como um erro de conversão ou se o arquivo não for encontrado. O processamento geralmente pode retomar após uma chamada para **limpar** com um argumento zero.|  
|[good](http://msdn.microsoft.com/Library/77f0aa17-2ae1-48ae-8040-592d301e3972)|Retorna **true** não se houver nenhuma condição de erro (recuperável ou não) e o sinalizador de fim de arquivo não estiver definido.|  
|[eof](http://msdn.microsoft.com/Library/3087f631-1268-49cd-86cf-ff4108862329)|Retorna **true** na condição de fim de arquivo.|  
|[clear](http://msdn.microsoft.com/Library/dc172694-1267-45f8-8f5c-e822e16fc271)|Define o estado de erro interno. Se chamado com os argumentos padrão, limpa todos os bits de erro.|  
|[rdstate](http://msdn.microsoft.com/Library/e235e4e2-7e95-4777-a160-3938d263dd9c)|Retorna o estado de erro atual.|  
  
 O **!** operador está sobrecarregado para executar a mesma função que a função **fail**. Portanto, a expressão:  
  
```  
if(!cout)...  
```  
  
 equivale a:  
  
```  
if(cout.fail())...  
```  
  
 O operador **void\*()** está sobrecarregado para ser o oposto do operador **!** portanto, a expressão:  
  
```  
if(cout)...  
```  
  
 é igual a:  
  
```  
if(!cout.fail())...  
```  
  
 O operador **void\*()** não é equivalente a **good**, pois ele não testa o fim do arquivo.  
  
## <a name="see-also"></a>Consulte também  
 [Fluxos de saída](../standard-library/output-streams.md)

