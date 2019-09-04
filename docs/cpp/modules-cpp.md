---
title: Visão geral dos módulos no C++
ms.date: 07/23/2019
helpviewer_keywords:
- modules [C++]
- modules [C++], overview
description: Os módulos no C++ 20 fornecem uma alternativa moderna para arquivos de cabeçalho.
ms.openlocfilehash: 17495aa3e295b26fcfa5c489ff6793bb75d13d68
ms.sourcegitcommit: fd0f8839da5c6a3663798a47c6b0bb6e63b518bd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2019
ms.locfileid: "70273678"
---
# <a name="overview-of-modules-in-c"></a>Visão geral dos módulos no C++

O c++ 20 introduz *módulos*, uma solução moderna para a componentização de C++ bibliotecas e programas. Um módulo é um conjunto de arquivos de código-fonte que são compilados independentemente das [unidades de tradução](https://wikipedia.org/wiki/Translation_unit_(programming)) que os importam. Os módulos eliminam ou reduzem muito muitos dos problemas associados ao uso de arquivos de cabeçalho e também reduzem os tempos de compilação. Macros, diretivas de pré-processador e nomes não exportados declarados em um módulo não são visíveis e, portanto, não têm efeito sobre a compilação da unidade de tradução que importa o módulo. Você pode importar módulos em qualquer ordem sem preocupação com redefinições de macro. As declarações na unidade de conversão de importação não participam da resolução de sobrecarga ou da pesquisa de nome no módulo importado. Depois que um módulo é compilado uma vez, os resultados são armazenados em um arquivo binário que descreve todos os tipos, funções e modelos exportados. Esse arquivo pode ser processado muito mais rápido que um arquivo de cabeçalho e pode ser reutilizado pelo compilador em todos os locais em que o módulo é importado em um projeto.

Os módulos podem ser usados lado a lado com arquivos de cabeçalho. Um C++ arquivo de origem pode importar módulos e também #include arquivos de cabeçalho. Em alguns casos, um arquivo de cabeçalho pode ser importado como um módulo, em vez de #included textualmente pelo pré-processador. Recomendamos que novos projetos usem módulos em vez de arquivos de cabeçalho o máximo possível. Para projetos maiores existentes em desenvolvimento ativo, sugerimos que você teste a conversão de cabeçalhos herdados em módulos para ver se você obtém uma redução significativa nos tempos de compilação.

## <a name="enable-modules-in-the-microsoft-c-compiler"></a>Habilitar módulos no compilador da C++ Microsoft

A partir do Visual Studio 2019 versão 16,2, os módulos não são totalmente implementados C++ no compilador da Microsoft. Você pode usar o recurso de módulos para criar módulos de partição única e para importar os módulos de biblioteca padrão fornecidos pela Microsoft. Para habilitar o suporte para módulos, compile com [/experimental: module](../build/reference/experimental-module.md) e [/std: c + + Latest](../build/reference/std-specify-language-standard-version.md). Em um projeto do Visual Studio, clique com o botão direito do mouse no nó do projeto em **Gerenciador de soluções** e escolha **Propriedades**. Defina a lista suspensa **configuração** para **todas as configurações**e, em seguida, escolha **Propriedades** > de configuração > **C/C++** **idioma** >  **C++ habilitar módulos ( experimental)** .

Um módulo e o código que o consome devem ser compilados com as mesmas opções de compilador.

## <a name="consume-the-c-standard-library-as-modules"></a>Consumir a C++ biblioteca padrão como módulos

Embora não seja especificado pelo padrão C++ 20, a Microsoft permite que sua implementação C++ da biblioteca padrão seja importada como módulos. Ao importar a C++ biblioteca padrão como módulos em vez de #including-la por meio de arquivos de cabeçalho, é possível acelerar os tempos de compilação dependendo do tamanho do seu projeto. A biblioteca é componented nos seguintes módulos:

- o STD. Regex fornece o conteúdo do \<Regex de cabeçalho >
- o STD. FileSystem fornece o conteúdo do \<> do sistema de arquivos do cabeçalho
- o STD. Memory fornece o conteúdo da \<memória de cabeçalho >
- o padrão de Threading fornece o conteúdo dos cabeçalhos \<> Atomic, \<CONDITION_VARIABLE >, \<futuro >, \<> mutex, \<shared_mutex > e \<thread >
- o STD. Core fornece tudo o C++ mais na biblioteca padrão

Para consumir esses módulos, basta adicionar uma instrução de importação à parte superior do arquivo de código-fonte. Por exemplo:

```cpp
import std.core;
import std.regex;
```

Para consumir o módulo Microsoft standard library, você deve compilar seu programa com as opções [/EHsc](../build/reference/eh-exception-handling-model.md) e [/MD](../build/reference/md-mt-ld-use-run-time-library.md) .

## <a name="basic-example"></a>Exemplo básico

O exemplo a seguir mostra uma definição de módulo simples em um arquivo de origem chamado **foo. IXX**. A extensão **. IXX** é necessária para arquivos de interface de módulo no Visual Studio. Neste exemplo, o arquivo de interface contém a definição de função, bem como a declaração. No entanto, as definições também podem ser colocadas em um ou mais arquivos separados (conforme mostrado em um exemplo posterior). A instrução **Export Module foo** indica que esse arquivo é a interface primária para um módulo chamado `Foo`. O modificador de `f()` exportação no indica que essa função estará visível `Foo` quando for importada por outro programa ou módulo. Observe que o módulo faz referência a `Bar`um namespace.

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

O arquivo **myprogram. cpp** usa a instrução **Import** para acessar o nome que é exportado pelo `Foo`. Observe que o nome `Bar` está visível aqui, mas não todos os seus membros. Observe também que a macro `ANSWER` não está visível.

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

A declaração de importação pode aparecer somente no escopo global.

## <a name="implementing-modules"></a>Implementando módulos

Você pode criar um módulo com um único arquivo de interface (. IXX) que exporta nomes e inclui implementações de todas as funções e tipos. Você também pode colocar as implementações em um ou mais arquivos de implementação separados, de forma semelhante a como os arquivos. h e. cpp são usados. A palavra-chave **Export** é usada somente no arquivo de interface. Um arquivo de implementação pode **importar** outro módulo, mas não pode **Exportar** nenhum nome. Os arquivos de implementação podem ser nomeados com qualquer extensão. Um arquivo de interface e o conjunto de arquivos de implementação que o fazem de volta são tratados como um tipo especial de unidade de tradução chamado *unidade de módulo*. Um nome declarado em qualquer arquivo de implementação é automaticamente visível em todos os outros arquivos dentro da mesma unidade de módulo.

Para módulos maiores, você pode dividir o módulo em várias unidades de módulo chamadas *partições*. Cada partição consiste em um arquivo de interface apoiado por um ou mais arquivos de implementação. (A partir do Visual Studio 2019 versão 16,2, as partições ainda não estão totalmente implementadas.)

## <a name="modules-namespaces-and-argument-dependent-lookup"></a>Módulos, namespaces e pesquisa dependente de argumento

As regras para namespaces em módulos são as mesmas de qualquer outro código. Se uma declaração dentro de um namespace for exportada, o namespace delimitador (excluindo Membros não exportados) também será exportado implicitamente. Se um namespace for explicitamente exportado, todas as declarações nessa definição de namespace serão exportadas.

Ao executar a pesquisa dependente de argumento para resoluções de sobrecarga na unidade de conversão de importação, o compilador considera as funções declaradas na mesma unidade de tradução (incluindo as interfaces de módulo) como onde o tipo dos argumentos da função são definidos.

### <a name="module-partitions"></a>Partições de módulo

> [!NOTE]
> Esta seção é fornecida para fins de integridade. As partições ainda não foram implementadas no C++ compilador da Microsoft.

Um módulo pode ser componented em *partições*, cada uma consistindo em um arquivo de interface e zero ou mais arquivos de implementação. Uma partição de módulo é semelhante a um módulo, exceto pelo fato de que ela compartilha a propriedade de todas as declarações em todo o módulo. Todos os nomes exportados por arquivos de interface de partição são importados e exportados novamente pelo arquivo de interface primário. O nome de uma partição deve começar com o nome do módulo seguido por dois-pontos. As declarações em qualquer uma das partições são visíveis no módulo inteiro. Nenhuma precauções especial é necessária para evitar erros de ODR (um-Definition-Rule). Você pode declarar um nome (função, classe, etc.) em uma partição e defini-la em outra. Um arquivo de implementação de partição começa da seguinte maneira:

```cpp
module Foo:part1
```

e o arquivo da interface de partição começa desta forma:

```cpp
export module Foo:part1
```

Para acessar declarações em outra partição, uma partição deve importá-la, mas ela só pode usar o nome da partição, não o nome do módulo:

```cpp
module Foo:part2;
import :part1;
```

A unidade de interface primária deve importar e reexportar todos os arquivos de partição da interface do módulo da seguinte maneira:

```cpp
export import :part1
export import :part2
...
```

A unidade de interface primária pode importar arquivos de implementação de partição, mas não pode exportá-los porque esses arquivos não têm permissão para exportar nomes. Isso permite que um módulo mantenha detalhes de implementação internos ao módulo.

## <a name="modules-and-header-files"></a>Módulos e arquivos de cabeçalho

Você pode incluir arquivos de cabeçalho em um arquivo de origem de módulo `#include` colocando a diretiva antes da declaração do módulo. Esses arquivos são considerados no *fragmento do módulo global*. Um módulo só pode ver os nomes no *fragmento do módulo global* que estão nos cabeçalhos que ele inclui explicitamente. O fragmento do módulo global contém apenas símbolos que são realmente usados.

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
> Esta seção é apenas informativa. As importações herdadas ainda não foram implementadas C++ no compilador da Microsoft.

Alguns cabeçalhos são suficientemente independentes que podem ser trazidos usando a palavra-chave **Import** . A principal diferença entre um cabeçalho importado e um módulo importado é que qualquer definição de pré-processador no cabeçalho é visível no programa de importação imediatamente após a instrução de importação. (As definições de pré-processador em quaisquer arquivos incluídos por esse cabeçalho *não* são visíveis.)

```cpp
import <vector>
import "myheader.h"
```

## <a name="see-also"></a>Consulte também

[módulo, importar, exportar](import-export-module.md)
