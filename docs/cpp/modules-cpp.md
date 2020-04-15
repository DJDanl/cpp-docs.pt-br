---
title: Visão geral dos módulos no C++
ms.date: 12/13/2019
helpviewer_keywords:
- modules [C++]
- modules [C++], overview
description: Módulos em C++20 fornecem uma alternativa moderna aos arquivos de cabeçalho.
ms.openlocfilehash: cd45be1dee888c8caeb65b7ff002ac8fee1ecbe1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370752"
---
# <a name="overview-of-modules-in-c"></a>Visão geral dos módulos no C++

C++20 introduz *módulos,* uma solução moderna para componentes de bibliotecas e programas C++. Um módulo é um conjunto de arquivos de código-fonte que são compilados independentemente das unidades de [tradução](https://wikipedia.org/wiki/Translation_unit_(programming)) que os importam. Os módulos eliminam ou reduzem muito muitos dos problemas associados ao uso de arquivos de cabeçalho, e também potencialmente reduzem os tempos de compilação. As macros, as diretivas de pré-processador e os nomes não exportados declarados em um módulo não são visíveis e, portanto, não têm efeito na compilação da unidade de tradução que importa o módulo. Você pode importar módulos em qualquer ordem sem preocupação com redefinições de macro. As declarações na unidade de tradução de importação não participam da resolução de sobrecarga ou pesquisa de nomes no módulo importado. Depois que um módulo é compilado uma vez, os resultados são armazenados em um arquivo binário que descreve todos os tipos, funções e modelos exportados. Esse arquivo pode ser processado muito mais rápido do que um arquivo de cabeçalho, e pode ser reutilizado pelo compilador em todos os lugares onde o módulo é importado em um projeto.

Os módulos podem ser usados lado a lado com arquivos de cabeçalho. Um arquivo de origem C++ pode importar módulos e também #include arquivos de cabeçalho. Em alguns casos, um arquivo de cabeçalho pode ser importado como um módulo em vez de #included textualmente pelo pré-processador. Recomendamos que novos projetos usem módulos em vez de arquivos de cabeçalho tanto quanto possível. Para projetos maiores existentes em desenvolvimento ativo, sugerimos que você experimente converter cabeçalhos legados em módulos para ver se você recebe uma redução significativa nos tempos de compilação.

## <a name="enable-modules-in-the-microsoft-c-compiler"></a>Habilitar módulos no compilador Microsoft C++

A partir do Visual Studio 2019 versão 16.2, os módulos não são totalmente implementados no compilador Microsoft C++. Você pode usar o recurso de módulos para criar módulos de partição única e importar os módulos da Biblioteca Padrão fornecidos pela Microsoft. Para habilitar o suporte para módulos, compile com [/experimental:module](../build/reference/experimental-module.md) e [/std:c++mais recente](../build/reference/std-specify-language-standard-version.md). Em um projeto do Visual Studio, clique com o botão direito do mouse no nó do projeto no **Solution Explorer** e escolha **Propriedades**. Defina a **lista de configuração** em todas **as configurações**e escolha **Propriedades de configuração** > **C/C++** > **Language** > Enable**C++ Modules (experimental)**.

Um módulo e o código que o consome devem ser compilados com as mesmas opções de compilador.

## <a name="consume-the-c-standard-library-as-modules"></a>Consumir a Biblioteca Padrão C++ como módulos

Embora não seja especificado pelo padrão C++20, a Microsoft permite que sua implementação da Biblioteca Padrão C++ seja importada como módulos. Ao importar a Biblioteca Padrão C++ como módulos em vez de #including-la através de arquivos de cabeçalho, você pode potencialmente acelerar os tempos de compilação, dependendo do tamanho do seu projeto. A biblioteca é componenteda nos seguintes módulos:

- std.regex fornece o \<conteúdo de cabeçalho regex>
- o sistema de arquivos std.filesystem fornece o conteúdo do sistema de arquivos de cabeçalho \<>
- a memória std.fornece \<o conteúdo de memória de cabeçalho>
- o std.threading fornece o \<conteúdo \<de cabeçalhos> atômicos, condition_variable>, \<> \<futuros,> mutex, \<> de shared_mutex e \<> de threads
- o std.core fornece tudo o resto na Biblioteca Padrão C++

Para consumir esses módulos, basta adicionar uma declaração de importação ao topo do arquivo de código fonte. Por exemplo:

```cpp
import std.core;
import std.regex;
```

Para consumir o módulo Microsoft Standard Library, compile seu programa com opções [/EHsc](../build/reference/eh-exception-handling-model.md) e [/MD.](../build/reference/md-mt-ld-use-run-time-library.md)

## <a name="basic-example"></a>Exemplo básico

O exemplo a seguir mostra uma definição de módulo simples em um arquivo de origem chamado **Foo.ixx**. A extensão **.ixx** é necessária para arquivos de interface de módulo no Visual Studio. Neste exemplo, o arquivo de interface contém a definição da função, bem como a declaração. No entanto, as definições também podem ser colocadas em um ou mais arquivos separados (como mostrado em um exemplo posterior). A declaração **do módulo de exportação Foo** indica `Foo`que este arquivo é a interface principal de um módulo chamado . O modificador `f()` de **exportação** em indica `Foo` que esta função será visível quando for importada por outro programa ou módulo. Observe que o módulo faz `Bar`referência a um namespace .

```cpp
export module Foo;

#define ANSWER 42

namespace Bar
{
   int f_internal() {
        return ANSWER;
      }

   export int f() {
      return f_internal();
   }
}
```

O arquivo **MyProgram.cpp** usa a declaração **de** importação `Foo`para acessar o nome exportado por . Note que `Bar` o nome é visível aqui, mas não todos os seus membros. Observe também que `ANSWER` a macro não é visível.

```cpp

import Foo;
import std.core;

using namespace std;

int main()
{
   cout << "The result of f() is " << Bar::f() << endl; // 42
   // int i = Bar::f_internal(); // C2039
   // int j = ANSWER; //C2065
}

```

A declaração de importação só pode aparecer no âmbito global.

## <a name="implementing-modules"></a>Implementando módulos

Você pode criar um módulo com um único arquivo de interface (.ixx) que exporta nomes e inclui implementações de todas as funções e tipos. Você também pode colocar as implementações em um ou mais arquivos de implementação separados, semelhante à forma como os arquivos .h e .cpp são usados. A **palavra-chave de exportação** é usada apenas no arquivo de interface. Um arquivo de implementação pode **importar** outro módulo, mas não pode **exportar** nenhum nome. Os arquivos de implementação podem ser nomeados com qualquer extensão. Um arquivo de interface e o conjunto de arquivos de implementação que o reemtratam são tratados como um tipo especial de unidade de tradução chamada unidade *de módulo*. Um nome que é declarado em qualquer arquivo de implementação é automaticamente visível em todos os outros arquivos dentro da mesma unidade de módulo.

Para módulos maiores, você pode dividir o módulo em unidades de vários módulos chamadas *partições*. Cada partição consiste em um arquivo de interface apoiado por um ou mais arquivos de implementação. (A partir da versão 16.2 do Visual Studio 2019, as partições ainda não estão totalmente implementadas.)

## <a name="modules-namespaces-and-argument-dependent-lookup"></a>Módulos, namespaces e visualização dependente de argumentos

As regras para namespaces em módulos são as mesmas de qualquer outro código. Se uma declaração dentro de um namespace for exportada, o namespace de fechamento (excluindo membros não exportados) também será exportado implicitamente. Se um namespace for explicitamente exportado, todas as declarações dentro dessa definição de namespace serão exportadas.

Ao realizar uma pesquisa dependente de argumentos para resoluções de sobrecarga na unidade de tradução de importação, o compilador considera funções que são declaradas na mesma unidade de tradução (incluindo interfaces de módulo) como onde o tipo de argumentos da função são definidos.

### <a name="module-partitions"></a>Partições de módulo

> [!NOTE]
> Esta seção está prevista para a completude. As partições ainda não foram implementadas no compilador Microsoft C++.

Um módulo pode ser componenteem *partições,* cada uma consistindo de um arquivo de interface e arquivos de implementação zero ou mais. Uma partição de módulo é semelhante a um módulo, exceto que compartilha a propriedade de todas as declarações em todo o módulo. Todos os nomes exportados por arquivos de interface de partição são importados e reexportados pelo arquivo de interface principal. O nome de uma partição deve começar com o nome do módulo seguido de um cólon. As declarações em qualquer uma das partições são visíveis dentro de todo o módulo. Não são necessárias precauções especiais para evitar erros de regra de uma definição (ODR). Você pode declarar um nome (função, classe, etc.) em uma partição e defini-lo em outra. Um arquivo de implementação de partição começa assim:

```cpp
module Foo:part1
```

e o arquivo de interface de partição começa assim:

```cpp
export module Foo:part1
```

Para acessar declarações em outra partição, uma partição deve importá-la, mas ela só pode usar o nome da partição, não o nome do módulo:

```cpp
module Foo:part2;
import :part1;
```

A unidade de interface primária deve importar e reexportar todos os arquivos de partição de interface do módulo como este:

```cpp
export import :part1
export import :part2
...
```

A unidade de interface primária pode importar arquivos de implementação de partição, mas não pode exportá-los porque esses arquivos não podem exportar nenhum nome. Isso permite que um módulo mantenha os detalhes da implementação internos ao módulo.

## <a name="modules-and-header-files"></a>Módulos e arquivos de cabeçalho

Você pode incluir arquivos de cabeçalho `#include` em um arquivo de origem do módulo colocando a diretiva antes da declaração do módulo. Esses arquivos são considerados no *fragmento do módulo global*. Um módulo só pode ver os nomes no *fragmento de módulo global* que estão em cabeçalhos que ele explicitamente inclui. O fragmento do módulo global contém apenas símbolos que são realmente usados.

```cpp
// MyModuleA.cpp

#include "customlib.h"
#include "anotherlib.h"

import std.core;
import MyModuleB;

//... rest of file
```

Você pode usar um arquivo de cabeçalho tradicional para controlar quais módulos são importados:

```cpp
// MyProgram.h
import std.core;
#ifdef DEBUG_LOGGING
import std.filesystem;
#endif
```

### <a name="imported-header-files"></a>Arquivos de cabeçalho importados

> [!NOTE]
> Esta seção é apenas informacional. As importações herdadas ainda não foram implementadas no compilador Microsoft C++.

Alguns cabeçalhos são suficientemente auto-suficientes que podem ser trazidos usando a palavra-chave **de importação.** A principal diferença entre um cabeçalho importado e um módulo importado é que quaisquer definições de pré-processador no cabeçalho são visíveis no programa de importação imediatamente após a declaração de importação. (As definições de pré-processador em todos os arquivos incluídos por esse cabeçalho *não* são visíveis.)

```cpp
import <vector>
import "myheader.h"
```

## <a name="see-also"></a>Confira também

[module, import e export](import-export-module.md)
