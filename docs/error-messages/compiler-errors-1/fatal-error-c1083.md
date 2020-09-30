---
title: Erro fatal C1083
ms.date: 09/01/2017
f1_keywords:
- C1083
helpviewer_keywords:
- C1083
ms.assetid: 97e52df3-e79c-4f85-8f1e-bbd1057d55e7
ms.openlocfilehash: 57ae8f2d0b7f02732032151f86617498e5201c61
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509752"
---
# <a name="fatal-error-c1083"></a>Erro fatal C1083

> Não é possível abrir o arquivo *filetype* : '*File*': *Message*

O compilador gera um erro C1083 quando não consegue encontrar um arquivo necessário. Há várias causas possíveis para esse erro. Um caminho de pesquisa de inclusão incorreto ou arquivos de cabeçalho ausentes ou com nome inválido são as causas mais comuns, mas outros tipos de arquivo e problemas também podem causar C1083. Aqui estão alguns dos motivos comuns pelos quais o compilador gera esse erro.

## <a name="the-specified-file-name-is-wrong"></a>O nome de arquivo especificado está errado

O nome de um arquivo pode ter sido digitado incorretamente. Por exemplo,

`#include <algorithm.h>`

pode não encontrar o arquivo desejado. A maioria dos arquivos de cabeçalho da biblioteca padrão do C++ não tem uma extensão de nome de arquivo. h. O \<algorithm> cabeçalho não seria encontrado por essa `#include` diretiva. Para corrigir esse problema, verifique se o nome de arquivo correto foi inserido, como neste exemplo:

`#include <algorithm>`

Certos cabeçalhos da biblioteca CRT estão localizados em um subdiretório do diretório de inclusão padrão. Por exemplo, para incluir *`sys/types.h`* , você deve incluir o *`sys`* nome do subdiretório na `#include` diretiva:

`#include <sys/types.h>`

## <a name="the-file-is-not-included-in-the-include-search-path"></a>O arquivo não está incluído no caminho de pesquisa de inclusão

O compilador não pode encontrar o arquivo usando as regras de pesquisa que são indicadas por uma diretiva `#include` ou `#import`. Por exemplo, quando um nome de arquivo de cabeçalho está entre aspas,

`#include "myincludefile.h"`

Isso informa o compilador para procurar o arquivo no mesmo diretório que contém o arquivo de origem primeiro e, em seguida, examinar outros locais especificados pelo ambiente de compilação. Se as aspas contiverem um caminho absoluto, o compilador procurará somente o arquivo nesse local. Se as aspas contiverem um caminho relativo, o compilador procurará o arquivo no diretório relativo ao diretório de origem.

Se o nome estiver entre colchetes angulares,

`#include <stdio.h>`

o compilador segue um caminho de pesquisa que é definido pelo ambiente de compilação, a **`/I`** opção do compilador, a **`/X`** opção do compilador e a variável de ambiente **include** . Para obter mais informações, incluindo detalhes específicos sobre a ordem de pesquisa usada para localizar um arquivo, consulte diretiva [de #include (C/C++)](../../preprocessor/hash-include-directive-c-cpp.md) e [#import diretiva](../../preprocessor/hash-import-directive-cpp.md).

Se os arquivos de inclusão estiverem em outro diretório em relação ao seu diretório de origem, e você usar um caminho relativo nas diretivas include, deverá usar aspas duplas em vez de colchetes angulares. Por exemplo, se o arquivo de cabeçalho *`myheader.h`* estiver em um subdiretório de suas fontes de projeto nomeadas cabeçalhos, este exemplo não encontrará o arquivo e causará C1083:

`#include <headers\myheader.h>`

Mas este exemplo funciona:

`#include "headers\myheader.h"`

Os caminhos relativos também podem ser usados com diretórios no caminho de pesquisa de inclusão. Se você adicionar um diretório à variável de ambiente **include** ou ao caminho de **diretórios de inclusão** no Visual Studio, não adicione também parte do caminho para as diretivas include. Por exemplo, se o cabeçalho estiver localizado em *`\path\example\headers\myheader.h`* e você adicionar *`\path\example\headers\`* ao caminho de **diretórios de inclusão** no Visual Studio, mas sua `#include` diretiva se referir ao arquivo como

`#include <headers\myheader.h>`

em seguida, o arquivo não foi encontrado. Use o caminho correto relativo ao diretório especificado no caminho de pesquisa de inclusão. Neste exemplo, você pode alterar o caminho de pesquisa de inclusão para *`\path\example\`* ou remover o *`headers\`* segmento de caminho da `#include` diretiva.

## <a name="third-party-library-issues-and-vcpkg"></a>Problemas de biblioteca de terceiros e vcpkg

Se você vir esse erro quando estiver tentando configurar uma biblioteca de terceiros como parte de sua compilação, considere usar o [`vcpkg`](../../build/vcpkg.md) , um Gerenciador de pacotes C++, para instalar e criar a biblioteca. o vcpkg dá suporte a uma lista grande e crescente [de bibliotecas de](https://github.com/Microsoft/vcpkg/tree/master/ports)terceiros e define todas as propriedades de configuração e dependências necessárias para compilações bem-sucedidas como parte do seu projeto.

## <a name="the-file-is-in-your-project-but-not-the-include-search-path"></a>O arquivo está em seu projeto, mas não no caminho de pesquisa de inclusão

Mesmo quando os arquivos de cabeçalho são listados em **Gerenciador de soluções** como parte de um projeto, os arquivos são encontrados somente pelo compilador quando são referenciados por uma `#include` `#import` diretiva ou em um arquivo de origem e estão localizados em um caminho de pesquisa de inclusão. Tipos diferentes de compilações podem usar caminhos de pesquisa diferentes. A **`/X`** opção do compilador pode ser usada para excluir diretórios do caminho de pesquisa de inclusão. Isso permite que diferentes compilações usem arquivos de inclusão diferentes de mesmo nome, mas são mantidos em diretórios diferentes. Essa é uma alternativa à compilação condicional usando comandos do pré-processador. Para obter mais informações sobre a **`/X`** opção do compilador, consulte [ `/X` (ignorar caminhos de inclusão padrão)](../../build/reference/x-ignore-standard-include-paths.md).

Para corrigir esse problema, corrija o caminho que o compilador usa para procurar o arquivo incluído ou importado. Um novo projeto usa os caminhos de pesquisa de inclusão padrão. Talvez seja necessário modificar o caminho de pesquisa de inclusão para adicionar um diretório para o seu projeto. Se você estiver compilando na linha de comando, adicione o caminho para a variável de ambiente **include** ou a **`/I`** opção de compilador para especificar o caminho para o arquivo.

Para definir o caminho do diretório de inclusão no Visual Studio, abra a caixa de diálogo **páginas de propriedades** do projeto. Selecione os **diretórios do vc + +** em **Propriedades de configuração** no painel esquerdo e edite a propriedade **incluir diretórios** . Para obter mais informações sobre os diretórios por usuário e por projeto pesquisados pelo compilador no Visual Studio, consulte [página de propriedades de diretórios do vc + +](../../build/reference/vcpp-directories-property-page.md). Para obter mais informações sobre a **`/I`** opção do compilador, consulte [ `/I` (diretórios de inclusão adicionais)](../../build/reference/i-additional-include-directories.md).

## <a name="the-command-line-include-or-lib-environment-is-not-set"></a>O ambiente de inclusão ou de linha de comando não está definido

Quando o compilador é invocado na linha de comando, variáveis de ambiente são geralmente usadas para especificar caminhos de pesquisa. Se o caminho de pesquisa descrito pela variável de ambiente **include** ou **lib** não estiver definido corretamente, um erro C1083 poderá ser gerado. É altamente recomendável usar um atalho de prompt de comando do desenvolvedor para definir o ambiente básico para compilações de linha de comando. Para obter mais informações, consulte [criar C/C++ na linha de comando](../../build/building-on-the-command-line.md). Para obter mais informações sobre como usar variáveis de ambiente, consulte [como: usar variáveis de ambiente em uma compilação](/visualstudio/msbuild/how-to-use-environment-variables-in-a-build).

## <a name="the-file-may-be-locked-or-in-use"></a>O arquivo pode estar bloqueado ou em uso

Se você estiver usando outro programa para editar ou acessar o arquivo, ele poderá ter o arquivo bloqueado. Tente fechar o arquivo no outro programa. Às vezes, o outro programa pode ser o próprio Visual Studio, se você estiver usando opções de compilação paralela. Se a desativação da opção de compilação paralela fizer o erro desaparecer, esse será o problema. Outros sistemas de Build paralelos também podem ter esse problema. Tenha cuidado para definir dependências de arquivo e projeto para que a ordem de compilação esteja correta. Em alguns casos, considere criar um projeto intermediário para forçar a criação de ordem de dependência para um arquivo comum que pode ser criado por vários projetos. Às vezes, os programas antivírus bloqueiam temporariamente arquivos alterados recentemente para verificação. Se possível, considere excluir os diretórios de Build do projeto do verificador de antivírus.

## <a name="the-wrong-version-of-a-file-name-is-included"></a>A versão incorreta de um nome de arquivo foi incluída

Um erro C1083 também pode indicar que a versão incorreta de um arquivo foi incluída. Por exemplo, uma compilação poderia incluir a versão incorreta de um arquivo que tem uma diretiva `#include` para um arquivo de cabeçalho não destinado a essa compilação. Por exemplo, determinados arquivos só podem ser aplicados a compilações x86 ou para Depurar compilações. Quando o arquivo de cabeçalho não é localizado, o compilador gera um erro C1083. A correção desse problema é usar o arquivo correto, não adicionar o arquivo de cabeçalho ou diretório à compilação.

## <a name="the-precompiled-headers-are-not-yet-precompiled"></a>Os cabeçalhos pré-compilados ainda não foram pré-compilados

Quando um projeto é configurado para usar cabeçalhos pré-compilados, os *`.pch`* arquivos relevantes precisam ser criados para que os arquivos que usam o conteúdo do cabeçalho possam ser compilados. Por exemplo, o *`pch.cpp`* arquivo ( *`stdafx.cpp`* no Visual Studio 2017 e anterior) é criado automaticamente no diretório do projeto para novos projetos. Compile esse arquivo primeiro para criar os arquivos de cabeçalho pré-compilados. No design típico do processo de compilação, isso é feito automaticamente. Para obter mais informações, consulte [criando arquivos de cabeçalho pré-compilados](../../build/creating-precompiled-header-files.md).

## <a name="additional-causes"></a>Causas adicionais

- Você instalou um SDK ou uma biblioteca de terceiros, mas não abriu uma nova janela do prompt de comando do desenvolvedor após a instalação do SDK ou da biblioteca. Se o SDK ou a biblioteca adicionar arquivos ao caminho de **inclusão** , talvez seja necessário abrir uma nova janela de prompt de comando do desenvolvedor para selecionar essas alterações de variável de ambiente.

- O arquivo usa código gerenciado, mas a opção do compilador **`/clr`** não é especificada. Para obter mais informações, consulte [ `/clr` (compilação em tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md).

- O arquivo é compilado usando uma **`/analyze`** configuração de opção de compilador diferente da usada para pré-compilar os cabeçalhos. Quando os cabeçalhos de um projeto são pré-compilados, todos devem usar as mesmas **`/analyze`** configurações. Para obter mais informações, consulte [ `/analyze` (análise de código)](../../build/reference/analyze-code-analysis.md).

- O arquivo ou diretório foi criado pelo subsistema do Windows para Linux, a diferenciação de maiúsculas e minúsculas por diretório está habilitada e o caso especificado de um caminho ou arquivo não corresponde ao caso do caminho ou arquivo no disco.

- O arquivo, o diretório ou o disco é somente leitura.

- O Visual Studio ou as ferramentas de linha de comando não têm permissões suficientes para ler o arquivo ou o diretório. Isso pode acontecer, por exemplo, quando os arquivos de projeto têm Propriedade diferente do processo que executa o Visual Studio ou as ferramentas de linha de comando. Às vezes, esse problema pode ser corrigido executando o Visual Studio ou o prompt de comando do desenvolvedor como administrador.

- Não há identificadores de arquivo suficientes. Feche alguns aplicativos e recompile-os. Essa condição é incomum em circunstâncias normais. No entanto, pode ocorrer quando projetos grandes são compilados em um computador com memória física limitada.

## <a name="example"></a>Exemplo

O exemplo a seguir gera um erro C1083 quando o arquivo de cabeçalho `"test.h"` não existe no diretório de origem ou no caminho de pesquisa de inclusão.

```cpp
// C1083.cpp
// compile with: /c
#include "test.h"   // C1083 test.h does not exist
#include "stdio.h"  // OK
```

Para obter informações sobre como criar projetos C/C++ no IDE ou na linha de comando e informações sobre como definir variáveis de ambiente, consulte [projetos e sistemas de compilação](../../build/projects-and-build-systems-cpp.md).

## <a name="see-also"></a>Consulte também

- [Propriedades do MSBuild](/visualstudio/msbuild/msbuild-properties)
