---
title: Nomes decorados
ms.date: 09/05/2018
helpviewer_keywords:
- decorated names, definition
- name decoration [C++]
- names [C++], decorated
ms.assetid: a4e9ae8e-b239-4454-b401-4102793cb344
ms.openlocfilehash: 3389b5466bf4a2a48c5e36b01da6818a523fec6f
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80077359"
---
# <a name="decorated-names"></a>Nomes decorados

Funções, dados e objetos em C e C++ programas são representados internamente por seus nomes decorados. Um *nome decorado* é uma cadeia de caracteres codificada criada pelo compilador durante a compilação de um objeto, dados ou definição de função. Ele registra convenções de chamada, tipos, parâmetros de função e outras informações junto com o nome. Essa decoração de nome, também conhecida como a destratação de *nome*, ajuda o vinculador a encontrar as funções e os objetos corretos ao vincular um executável.

As convenções de nomenclatura decoradas foram alteradas em várias versões do Visual Studio e também podem ser diferentes em arquiteturas de destino diferentes. Para vincular corretamente os arquivos de origem criados usando o Visual Studio, C C++ e DLLs e bibliotecas devem ser compiladas usando o mesmo conjunto de ferramentas de compilador, sinalizadores e arquitetura de destino.

> [!NOTE]
> Bibliotecas criadas com o Visual Studio 2015 podem ser consumidas por aplicativos criados com o Visual Studio 2017 ou o Visual Studio 2019.

##  <a name="using-decorated-names"></a><a name="Using"></a>Usando nomes decorados

Normalmente, você não precisa saber o nome decorado para escrever código que é compilado e vinculado com êxito. Nomes decorados são um detalhe de implementação interno ao compilador e ao vinculador. As ferramentas normalmente podem lidar com o nome em sua forma não decorada. No entanto, algumas vezes é necessário um nome decorado quando você especifica um nome de função para o vinculador e outras ferramentas. Por exemplo, para corresponder a C++ funções sobrecarregadas, membros de namespaces, construtores de classe, destruidores e funções de membro especiais, você deve especificar o nome decorado. Para obter detalhes sobre os sinalizadores de opção e outras situações que exigem nomes decorados, consulte a documentação para obter as ferramentas e as opções que você está usando.

Se você alterar o nome da função, a classe, a Convenção de chamada, o tipo de retorno ou qualquer parâmetro, o nome decorado também será alterado. Nesse caso, você deve obter o novo nome decorado e usá-lo em qualquer lugar em que o nome decorado for especificado.

A decoração de nome também é importante ao vincular a código escrito em outras linguagens de programação ou usando outros compiladores. Compiladores diferentes usam convenções de decoração de nome diferentes. Quando o executável é vinculado a código escrito em outra linguagem, deve-se tomar cuidado especial para corresponder os nomes exportados e importados e as convenções de chamada. O código de linguagem do assembly deve usar os nomes decorados MSVC e as convenções de chamada para vincular ao código-fonte escrito usando MSVC.

##  <a name="format-of-a-c-decorated-name"></a><a name="Format"></a>Formato de um C++ nome decorado

Um nome decorado para C++ uma função contém as seguintes informações:

- O nome da função.

- A classe da qual a função é membro, se for uma função membro. Isso pode incluir a classe que engloba a classe que contém a função e assim por diante.

- O namespace ao qual a função pertence, se fizer parte de um namespace.

- Os tipos dos parâmetros de função.

- A convenção de chamada.

- O tipo de retorno da função.

Os nomes de função e classe são codificados no nome decorado. O restante do nome decorado é um código que tem significado interno apenas para o compilador e o vinculador. Veja a seguir exemplos de nomes não decorados e C++ decorados.

|Nome não decorado|Nome decorado|
|----------------------|--------------------|
|`int a(char){int i=3;return i;};`|`?a@@YAHD@Z`|
|`void __stdcall b::c(float){};`|`?c@b@@AAGXM@Z`|

##  <a name="format-of-a-c-decorated-name"></a><a name="FormatC"></a>Formato de um nome decorado C

A forma de decoração para uma função C depende da Convenção de chamada usada em sua declaração, conforme mostrado na tabela a seguir. Esse também é o formato de decoração usado quando C++ o código é declarado como tendo `extern "C"` vinculação. A Convenção de chamada padrão é `__cdecl`. Observe que em um ambiente de 64 bits, as funções não são decoradas.

|Convenção de chamada|Modificação|
|------------------------|----------------|
|`__cdecl`|Sublinhado à esquerda ( **_** )|
|`__stdcall`|Sublinhado à esquerda ( **_** ) e um sinal ( **\@** ) à direita seguido pelo número de bytes na lista de parâmetros em decimal|
|`__fastcall`|Sinais de entrada ( **\@** ) à esquerda e à direita seguidos por um número decimal que representa o número de bytes na lista de parâmetros|
|`__vectorcall`|Dois sinais de entrada à direita ( **\@\@** ) seguidos por um número decimal de bytes na lista de parâmetros|

##  <a name="viewing-decorated-names"></a><a name="Viewing"></a>Exibindo nomes decorados

Você pode obter a forma decorada de um nome de símbolo depois de compilar o arquivo de origem que contém os dados, o objeto ou a definição de função ou protótipo. Para examinar nomes decorados em seu programa, você pode usar um dos seguintes métodos:

#### <a name="to-use-a-listing-to-view-decorated-names"></a>Para usar uma listagem para exibir nomes decorados

1. Gere uma listagem compilando o arquivo de origem que contém os dados, objeto ou definição de função ou protótipo com a opção de compilador de [tipo de arquivo de listagem](fa-fa-listing-file.md) definida como assembly com código-fonte ( **/FAS**).

   Por exemplo, digite `cl /c /FAs example.cpp` em um prompt de comando do desenvolvedor para gerar um arquivo de listagem, example. asm.

2. No arquivo de listagem resultante, localize a linha que começa com PUBLIC e termina um ponto e vírgula seguido pelo nome de função ou dados não decorados. O símbolo entre público e ponto e vírgula é o nome decorado.

#### <a name="to-use-dumpbin-to-view-decorated-names"></a>Para usar DUMPBIN para exibir nomes decorados

1. Para ver os símbolos exportados em um arquivo. obj ou. lib, insira `dumpbin /symbols` `objfile` em um prompt de comando do desenvolvedor.

2. Para localizar a forma decorada de um símbolo, procure o nome não decorado entre parênteses. O nome decorado está na mesma linha, após um caractere de&#124;pipe () e antes do nome não decorado.

##  <a name="viewing-undecorated-names"></a><a name="Undecorated"></a>Exibindo nomes não decorados

Você pode usar undname. exe para converter um nome decorado em sua forma não decorada. Este exemplo mostra como funciona:

```
C:\>undname ?func1@a@@AAEXH@Z
Microsoft (R) C++ Name Undecorator
Copyright (C) Microsoft Corporation. All rights reserved.

Undecoration of :- "?func1@a@@AAEXH@Z"
is :- "private: void __thiscall a::func1(int)"
```

## <a name="see-also"></a>Confira também

[Ferramentas de build adicionais do MSVC](c-cpp-build-tools.md)<br/>
[Usando extern para especificar a ligação](../../cpp/using-extern-to-specify-linkage.md)
