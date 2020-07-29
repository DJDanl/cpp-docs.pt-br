---
title: Funções de Membro de Fluxo de Arquivo de Saída
ms.date: 11/04/2016
helpviewer_keywords:
- output streams [C++], member functions
ms.assetid: 38aaf710-8035-4a34-a0c4-123a5327f28a
ms.openlocfilehash: f20ed4e238d23211a6eeec4a3091daeb4d02a9b3
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217669"
---
# <a name="output-file-stream-member-functions"></a>Funções de Membro de Fluxo de Arquivo de Saída

Funções de membro de fluxo de saída têm três tipos: aqueles que são equivalentes aos manipuladores, aqueles que executam operações de gravação sem formatação e aqueles que modificam o fluxo do estado e não têm nenhum manipulador ou operador de inserção equivalente. Para saída sequencial e formatada, você pode usar somente os operadores de inserção e manipuladores. Para saída de disco binário de acesso aleatório, você usar outras funções de membro, com ou sem operadores de inserção.

## <a name="the-open-function-for-output-streams"></a>A função open para fluxos de saída

Para usar um fluxo de arquivo de saída ([ofstream](../standard-library/basic-ofstream-class.md)), você deve associar esse fluxo a um arquivo de disco específico no construtor ou na `open` função. Se você usar a `open` função, poderá reutilizar o mesmo objeto de fluxo com uma série de arquivos. Em ambos os casos, os argumentos que descrevem o arquivo são os mesmos.

Quando você abre o arquivo associado a um fluxo de saída, geralmente especifica um `open_mode` sinalizador. Você pode combinar esses sinalizadores, que são definidos como enumeradores na classe `ios`, com o operador OR bit a bit ( &#124; ). Consulte [ios_base::openmode](../standard-library/ios-base-class.md#openmode) para obter uma lista dos enumeradores.

Três situações de fluxo de saída comuns envolvem as opções de modo:

- Criando um arquivo. Se o arquivo já existir, a versão antiga será excluída.

   ```cpp
   ostream ofile("FILENAME");
   // Default is ios::out

   ofstream ofile("FILENAME", ios::out);
   // Equivalent to above
   ```

- Anexando registros a um arquivo existente ou criando um se ele não existir.

   ```cpp
   ofstream ofile("FILENAME", ios::app);
   ```

- Abrindo os dois arquivos, um de cada vez, no mesmo fluxo.

   ```cpp
   ofstream ofile();
   ofile.open("FILE1", ios::in);
   // Do some output
   ofile.close();    // FILE1 closed
   ofile.open("FILE2", ios::in);
   // Do some more output
   ofile.close();    // FILE2 closed
   // When ofile goes out of scope it is destroyed.
   ```

## <a name="the-put"></a>O put

A função **put** grava um caractere no fluxo de saída. As duas instruções a seguir são as mesmas por padrão, mas a segunda é afetada pelos argumentos de formatação do fluxo:

```cpp
cout.put('A');

// Exactly one character written
cout <<'A'; // Format arguments 'width' and 'fill' apply
```

## <a name="the-write"></a>A gravação

A `write` função grava um bloco de memória em um fluxo de arquivo de saída. O argumento de tamanho especifica o número de bytes gravados. Este exemplo cria um fluxo de arquivo de saída e grava o valor binário da estrutura `Date` nele:

```cpp
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

A `write` função não é interrompida quando atinge um caractere nulo, portanto, a estrutura de classe completa é gravada. A função usa dois argumentos: um **`char`** ponteiro e uma contagem de caracteres a serem gravados. Observe a conversão necessária para **`char`** <strong>\*</strong> antes do endereço do objeto de estrutura.

## <a name="the-seekp-and-tellp-functions"></a>As funções seekp e tellp

Um fluxo de arquivo de saída mantém um ponteiro interno que aponta para a posição em que os dados serão serem gravados em seguida. A função membro `seekp` define esse ponteiro e, portanto, fornece a saída do arquivo de disco de acesso aleatório. A função membro `tellp` retorna a posição do arquivo. Para obter exemplos que usam os equivalentes de fluxo de entrada para `seekp` e `tellp`, consulte [As funções seekg e tellg](../standard-library/input-stream-member-functions.md).

## <a name="the-close-function-for-output-streams"></a>A função close para fluxos de saída

A `close` função membro fecha o arquivo de disco associado a um fluxo de arquivo de saída. O arquivo deve ser fechado para concluir todas as saídas de disco. Se necessário, o `ofstream` destruidor fecha o arquivo para você, mas você pode usar a `close` função se precisar abrir outro arquivo para o mesmo objeto de fluxo.

O destruidor de fluxo de saída fechará automaticamente o arquivo de um fluxo somente se o construtor ou a `open` função de membro abrir o arquivo. Se você passar o construtor de um descritor de arquivo para um arquivo já aberto ou usar a `attach` função membro, deverá fechar o arquivo explicitamente.

## <a name="error-processing-functions"></a><a name="vclrferrorprocessingfunctionsanchor10"></a> Erro ao processar funções

Use essas funções membro para testar se há erros ao gravar em um fluxo:

|Função|Valor retornado|
|--------------|------------------|
|[bad](basic-ios-class.md#bad)|Retorna **`true`** se houver um erro irrecuperável.|
|[recuperação](basic-ios-class.md#fail)|Retorna **`true`** se houver um erro irrecuperável ou uma condição "esperada", como um erro de conversão, ou se o arquivo não for encontrado. O processamento pode ser retomado com frequência após uma chamada para `clear` com um argumento zero.|
|[recomendá](basic-ios-class.md#good)|Retorna **`true`** se não houver nenhuma condição de erro (irrecuperável ou não) e o sinalizador de fim de arquivo não estiver definido.|
|[EOF](basic-ios-class.md#eof)|Retorna **`true`** na condição de fim de arquivo.|
|[formatação](basic-ios-class.md#clear)|Define o estado de erro interno. Se chamado com os argumentos padrão, limpa todos os bits de erro.|
|[rdstate] (Basic-Ios-Class. MD # rdstate|Retorna o estado de erro atual.|

O **!** o operador está sobrecarregado para executar a mesma função que a `fail` função. Portanto, a expressão:

```cpp
if(!cout)...
```

é equivalente a:

```cpp
if(cout.fail())...
```

O operador **void\*()** está sobrecarregado para ser o oposto do operador **!** portanto, a expressão:

```cpp
if(cout)...
```

é igual a:

```cpp
if(!cout.fail())...
```

O operador **void \* ()** não é equivalente a `good` porque não é testado para o final do arquivo.

## <a name="see-also"></a>Confira também

[Fluxos de saída](../standard-library/output-streams.md)
