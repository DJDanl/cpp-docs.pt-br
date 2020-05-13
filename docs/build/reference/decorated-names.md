---
title: Nomes decorados
ms.date: 09/05/2018
helpviewer_keywords:
- decorated names, definition
- name decoration [C++]
- names [C++], decorated
ms.assetid: a4e9ae8e-b239-4454-b401-4102793cb344
ms.openlocfilehash: f6d81029d20d9aaca96ff184f48e94a9ce35d56e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320509"
---
# <a name="decorated-names"></a>Nomes decorados

Funções, dados e objetos em programas C e C++ são representados internamente por seus nomes decorados. Um *nome decorado* é uma seqüência codificada criada pelo compilador durante a compilação de um objeto, dados ou definição de função. Registra convenções de chamada, tipos, parâmetros de função e outras informações, juntamente com o nome. A decoração deste nome, também conhecida como *mangling nome,* ajuda o linker a encontrar as funções e objetos corretos ao vincular um executável.

As convenções de nomeação decoradas mudaram em várias versões do Visual Studio, e também podem ser diferentes em diferentes arquiteturas de alvo. Para vincular corretamente com os arquivos de origem criados usando DLLs e bibliotecas do Visual Studio, C e C++ devem ser compilados usando o mesmo conjunto de ferramentas, sinalizadores e arquitetura de destino do compilor.

> [!NOTE]
> Bibliotecas construídas com o Visual Studio 2015 podem ser consumidas por aplicativos construídos com o Visual Studio 2017 ou visual Studio 2019.

## <a name="using-decorated-names"></a><a name="Using"></a>Usando nomes decorados

Normalmente, você não precisa saber o nome condecorado para escrever código que compila e vincula com sucesso. Nomes decorados são um detalhe de implementação interno para o compilador e linker. As ferramentas geralmente podem lidar com o nome em sua forma não decorada. No entanto, um nome decorado às vezes é necessário quando você especifica um nome de função para o linker e outras ferramentas. Por exemplo, para combinar funções C++ sobrecarregadas, membros de namespaces, construtores de classe, destruidores e funções especiais de membros, você deve especificar o nome decorado. Para obter detalhes sobre as bandeiras de opção e outras situações que requerem nomes decorados, consulte a documentação das ferramentas e opções que você está usando.

Se você alterar o nome da função, classe, convenção de chamadas, tipo de retorno ou qualquer parâmetro, o nome condecorado também mudará. Neste caso, você deve obter o novo nome decorado e usá-lo em todos os lugares que o nome decorado é especificado.

A decoração do nome também é importante ao vincular-se ao código escrito em outras linguagens de programação ou usando outros compiladores. Diferentes compiladores usam convenções de decoração de nomes diferentes. Quando seus links executáveis para código escrito em outro idioma, deve ser tomado cuidado especial para corresponder aos nomes exportados e importados e convenções de chamada. O código de linguagem de montagem deve usar os nomes decorados do MSVC e as convenções de chamada para vincular ao código fonte escrito usando o MSVC.

## <a name="format-of-a-c-decorated-name"></a><a name="Format"></a>Formato de um nome decorado C++

Um nome decorado para uma função C++ contém as seguintes informações:

- O nome da função.

- A classe da a que a função é membro, se for uma função de membro. Isso pode incluir a classe que inclui a classe que contém a função, e assim por diante.

- O namespace da função pertence, se faz parte de um namespace.

- Os tipos dos parâmetros de função.

- A convenção de chamada.

- O tipo de retorno da função.

Os nomes da função e da classe estão codificados no nome condecorado. O resto do nome condecorado é um código que tem significado interno apenas para o compilador e o linker. A seguir, exemplos de nomes C++ não decorados e decorados.

|Nome não decorado|Nome decorado|
|----------------------|--------------------|
|`int a(char){int i=3;return i;};`|`?a@@YAHD@Z`|
|`void __stdcall b::c(float){};`|`?c@b@@AAGXM@Z`|

## <a name="format-of-a-c-decorated-name"></a><a name="FormatC"></a>Formato de um nome decorado em C

A forma de decoração para uma função C depende da convenção de chamada utilizada em sua declaração, conforme mostrado na tabela a seguir. Este também é o formato de decoração que é usado `extern "C"` quando o código C++ é declarado ter linkage. A convenção de `__cdecl`chamada padrão é . Observe que em um ambiente de 64 bits, as funções não são decoradas.

|Convocação de convenção|Decoração|
|------------------------|----------------|
|`__cdecl`|Sublinhado líder (**_**)|
|`__stdcall`|Sublinhado líder (**_**) e**\@** um trailing no sinal ( ) seguido pelo número de bytes na lista de parâmetros em decimal|
|`__fastcall`|Liderando e seguindo**\@** em sinais ( ) seguido por um número decimal representando o número de bytes na lista de parâmetros|
|`__vectorcall`|Dois arrastando em**\@** placas ( ) seguido por um número decimal de bytes na lista de parâmetros|

## <a name="viewing-decorated-names"></a><a name="Viewing"></a>Visualização de nomes decorados

Você pode obter a forma decorada de um nome símbolo depois de compilar o arquivo de origem que contém a definição de dados, objeto ou função ou protótipo. Para examinar nomes decorados em seu programa, você pode usar um dos seguintes métodos:

#### <a name="to-use-a-listing-to-view-decorated-names"></a>Para usar uma listagem para exibir nomes decorados

1. Gerar uma listagem compilando o arquivo de origem que contém a definição de dados, objeto ou função ou protótipo com a opção de compilador [tipo de arquivo](fa-fa-listing-file.md) de listagem definida como Assembly with Source Code **(/FAs).**

   Por exemplo, `cl /c /FAs example.cpp` digite um prompt de comando do desenvolvedor para gerar um arquivo de listagem, exemplo.asm.

2. No arquivo de listagem resultante, encontre a linha que começa com PUBLIC e termina um ponto e vírgula seguido do nome de função ou dados não decorados. O símbolo entre PÚBLICO e ponto e vírgula é o nome condecorado.

#### <a name="to-use-dumpbin-to-view-decorated-names"></a>Para usar dumpbin para visualizar nomes decorados

1. Para ver os símbolos exportados em um arquivo `dumpbin /symbols` `objfile` .obj ou .lib, digite em um prompt de comando do desenvolvedor.

2. Para encontrar a forma decorada de um símbolo, procure o nome não decorado entre parênteses. O nome decorado está na mesma linha, depois de um personagem pipe (&#124;) e antes do nome não decorado.

## <a name="viewing-undecorated-names"></a><a name="Undecorated"></a>Visualização de nomes não decorados

Você pode usar undname.exe para converter um nome decorado em sua forma não decorada. Este exemplo mostra como ele funciona:

```
C:\>undname ?func1@a@@AAEXH@Z
Microsoft (R) C++ Name Undecorator
Copyright (C) Microsoft Corporation. All rights reserved.

Undecoration of :- "?func1@a@@AAEXH@Z"
is :- "private: void __thiscall a::func1(int)"
```

## <a name="see-also"></a>Confira também

[Ferramentas adicionais de construção de MSVC](c-cpp-build-tools.md)<br/>
[Usando extern para especificar a ligação](../../cpp/using-extern-to-specify-linkage.md)
