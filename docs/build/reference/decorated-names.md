---
title: Nomes decorados | Microsoft Docs
ms.custom: ''
ms.date: 09/05/2018
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- decorated names, definition
- name decoration [C++]
- names [C++], decorated
ms.assetid: a4e9ae8e-b239-4454-b401-4102793cb344
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 32c8a91442e55325b35d1067ec5009c9bd5cf4a6
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45700720"
---
# <a name="decorated-names"></a>Nomes decorados

Funções, dados e objetos em programas C e C++ são representados internamente por seus nomes decorados. Um *nome decorado* é uma cadeia de caracteres codificada criada pelo compilador durante a compilação de um objeto, dados ou definição de função. Ela registra as convenções de chamada, tipos, parâmetros de função e outras informações junto com o nome. Este decoração de nome, também conhecida como *a desconfiguração de nome*, ajuda o vinculador a localizar as funções corretas e objetos ao vincular um executável.

As convenções de nomenclatura decoradas foram alterados em várias versões do Visual C++ e também podem ser diferentes em arquiteturas de destino diferente. Para vincular corretamente com arquivos de código-fonte criados usando o Visual C++, C e C++ DLLs e bibliotecas deve ser compilado usando o mesmo conjunto de ferramentas do compilador, sinalizadores e arquitetura de destino.

##  <a name="Using"></a> Usando nomes decorados

Normalmente, você não precisa saber o nome decorado escrever código que compila e links com êxito. Nomes decorados são um detalhe de implementação interno no compilador e vinculador. As ferramentas geralmente podem lidar com o nome em seu formato não decorado. No entanto, um nome decorado, às vezes, é necessário quando você especifica um nome de função para o vinculador e outras ferramentas. Por exemplo, de acordo com funções sobrecarregadas de C++, os membros de namespaces, construtores de classe, os destruidores e funções de membro especial, você deve especificar o nome decorado. Para obter detalhes sobre os sinalizadores de opção e outras situações que exigem nomes decorados, consulte a documentação para as ferramentas e opções que você está usando.

Se você alterar o nome da função, classe, convenção de chamada, tipo de retorno ou qualquer parâmetro, o nome decorado também será alterado. Nesse caso, você deve obter o novo nome decorado e usá-lo em qualquer lugar, que o nome decorado é especificado.

Decoração de nome também é importante ao vincular ao código escrito em outras linguagens de programação ou usando outros compiladores. Compiladores diferentes usam diferentes convenções de decoração de nome. Quando o executável vincula ao código escrito em outra linguagem, um cuidado especial cuidado correspondem aos nomes exportados e importados e convenções de chamada. Código de linguagem assembly deve usar o Visual C++ decoradas nomes e as convenções de chamada para vincular ao código-fonte escrito usando o Visual C++.

##  <a name="Format"></a> Nome decorado do formato de c++

Um nome decorado de uma função C++ contém as seguintes informações:

- O nome da função.

- A classe que a função é um membro, se for uma função de membro. Isso pode incluir a classe que inclui a classe que contém a função e assim por diante.

- O namespace a função pertence, se ele fizer parte de um namespace.

- Os tipos dos parâmetros de função.

- A convenção de chamada.

- O tipo de retorno da função.

Os nomes de classe e função são codificados no nome decorado. O restante do nome decorado é um código que tem um significado interno somente para o compilador e vinculador. A seguir estão exemplos de nomes de C++ não decorados e decorados.

|Nome não decorado|Nome decorado|
|----------------------|--------------------|
|`int a(char){int i=3;return i;};`|`?a@@YAHD@Z`|
|`void __stdcall b::c(float){};`|`?c@b@@AAGXM@Z`|

##  <a name="FormatC"></a> Nome decorado do formato de um C

O formulário de decoração para uma função C depende a convenção de chamada usada na sua declaração, conforme mostrado na tabela a seguir. Isso também é o formato de decoração usado quando o código C++ é declarado para ter `extern "C"` vinculação. O padrão de convenção de chamada é `__cdecl`. Observe que, em um ambiente de 64 bits, funções não são decoradas.

|Convenção de chamada|Decoração|
|------------------------|----------------|
|`__cdecl`|Levando o sublinhado (**_**)|
|`__stdcall`|Levando o sublinhado (**_**) e à direita sinal de arroba (**\@**) seguido pelo número de bytes na lista de parâmetros em decimal|
|`__fastcall`|À direita e sinais de arroba (**\@**) seguido por um número decimal que representa o número de bytes na lista de parâmetros|
|`__vectorcall`|Duas à direita sinais de arroba (**\@\@**) seguido por um número decimal de bytes na lista de parâmetros|

##  <a name="Viewing"></a> Nomes de exibição decorado

Depois de compilar o arquivo de origem que contém os dados, o objeto, ou a definição de função ou o protótipo, você pode obter a forma decorada do nome de um símbolo. Para examinar nomes decorados no seu programa, você pode usar um dos seguintes métodos:

#### <a name="to-use-a-listing-to-view-decorated-names"></a>Usar uma lista para exibir nomes decorados

1. Gerar uma lista ao compilar o arquivo de origem que contém os dados, o objeto, ou a definição de função ou o protótipo com o [tipo de arquivo de listagem](../../build/reference/fa-fa-listing-file.md) opção de compilador definida como Assembly com código-fonte (**/FAs**).

   Por exemplo, digite `cl /c /FAs example.cpp` em um prompt de comando do desenvolvedor para gerar um arquivo de listagem, example.asm.

2. No arquivo de listagem resultante, localize a linha que começa com o público e termina um ponto e vírgula seguido do nome não decorado de dados ou função. O símbolo entre público e o ponto e vírgula é o nome decorado.

#### <a name="to-use-dumpbin-to-view-decorated-names"></a>Usar o DUMPBIN para exibir nomes decorados

1. Para ver os símbolos exportados em um arquivo. obj ou. lib, insira `dumpbin /symbols` `objfile` em um prompt de comando do desenvolvedor.

2. Para localizar o formulário decorado de um símbolo, procure o nome não decorado entre parênteses. O nome decorado é na mesma linha, após um pipe (&#124;) caracteres e antes do nome não decorado.

##  <a name="Undecorated"></a> Nomes de exibição não decorado

Você pode usar undname.exe para converter um nome decorado em seu formato não decorado. Este exemplo mostra como ele funciona:

```
C:\>undname ?func1@a@@AAEXH@Z
Microsoft (R) C++ Name Undecorator
Copyright (C) Microsoft Corporation. All rights reserved.

Undecoration of :- "?func1@a@@AAEXH@Z"
is :- "private: void __thiscall a::func1(int)"
```

## <a name="see-also"></a>Consulte também

[Ferramentas de build de C/C++](../../build/reference/c-cpp-build-tools.md)<br/>
[Usando extern para especificar a ligação](../../cpp/using-extern-to-specify-linkage.md)