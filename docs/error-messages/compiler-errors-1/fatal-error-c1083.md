---
title: Erro fatal C1083
ms.date: 09/01/2017
f1_keywords:
- C1083
helpviewer_keywords:
- C1083
ms.assetid: 97e52df3-e79c-4f85-8f1e-bbd1057d55e7
ms.openlocfilehash: ae4c6a9f6c41d94aa1e36ba4a79226b49df08b49
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50628001"
---
# <a name="fatal-error-c1083"></a>Erro fatal C1083

> Não é possível abrir *filetype* arquivo: '*arquivo*': *mensagem*

O compilador gera um erro C1083 quando não conseguir encontrar um arquivo necessário. Há muitas causas possíveis para esse erro. Uma pesquisa de inclusão incorreto caminho ou arquivos de cabeçalho ausente ou equivocado são as causas mais comuns, mas outros tipos de arquivo e os problemas também podem causar C1083. Aqui estão algumas das razões comuns por que o compilador gera esse erro.

## <a name="the-specified-file-name-is-wrong"></a>O nome de arquivo especificado está errado

O nome de um arquivo pode ter sido digitado incorretamente. Por exemplo,

`#include <algorithm.h>`

pode não encontrar o arquivo desejado. A maioria dos arquivos de cabeçalho da biblioteca padrão C++ não tem uma extensão de nome de arquivo. h. O \<algoritmo > cabeçalho não seria encontrado por este `#include` diretiva. Para corrigir esse problema, verifique se o nome de arquivo correto for inserido, como neste exemplo:

`#include <algorithm>`

Certos cabeçalhos da biblioteca CRT estão localizados em um subdiretório do diretório de inclusão padrão. Por exemplo, para incluir h, você deve incluir o nome do subdiretório sys na `#include` diretiva:

`#include <sys/types.h>`

## <a name="the-file-is-not-included-in-the-include-search-path"></a>O arquivo não está incluído no caminho de pesquisa de inclusão

O compilador não pode encontrar o arquivo usando as regras de pesquisa que são indicadas por uma diretiva `#include` ou `#import`. Por exemplo, quando um nome de arquivo de cabeçalho é colocado entre aspas,

`#include "myincludefile.h"`

Isso informa ao compilador para procurar o arquivo no mesmo diretório que contém o arquivo de origem primeiro e depois procurar outros locais especificados pelo ambiente de compilação. Se as aspas contiverem um caminho absoluto, o compilador procurará somente o arquivo nesse local. Se as aspas contiverem um caminho relativo, o compilador procurará o arquivo no diretório relativo ao diretório de origem.

Se o nome está entre colchetes angulares,

`#include <stdio.h>`

o compilador seguirá um caminho de pesquisa que é definido pelo ambiente de compilação, o **/I** opção de compilador, o **/X** opção de compilador e o **INCLUDE** variável de ambiente. Para obter mais informações, incluindo detalhes específicos sobre a ordem de pesquisa usado para localizar um arquivo, consulte [#include (C/C++) de diretiva](../../preprocessor/hash-include-directive-c-cpp.md) e [#import diretiva](../../preprocessor/hash-import-directive-cpp.md).

Se os arquivos de inclusão estão em outro diretório relativo ao diretório de origem, e você usa um caminho relativo no seu incluir diretivas, você deve usar aspas duplas em vez de colchetes angulares. Por exemplo, se seu myheader.h do arquivo de cabeçalho estiver em um subdiretório de suas fontes de projeto chamado cabeçalhos, em seguida, este exemplo não consegue localizar o arquivo e faz com que o C1083:

`#include <headers\myheader.h>`

mas este exemplo funciona:

`#include "headers\myheader.h"`

Caminhos relativos também podem ser usados com diretórios no caminho de pesquisa de inclusão. Se você adicionar um diretório para o **INCLUDE** variável de ambiente ou sua **diretórios de inclusão** caminho no Visual Studio, não adicione também parte do caminho para as diretivas de inclusão. Por exemplo, se seu cabeçalho está localizado em \path\example\headers\myheader.h e adicionar \path\example\headers\ para seus **diretórios de inclusão** caminho no Visual Studio, mas seu `#include` diretiva refere-se para o arquivo como

`#include <headers\myheader.h>`

em seguida, o arquivo não for encontrado. Use o caminho correto em relação ao diretório especificado no caminho de pesquisa de inclusão. Neste exemplo, você pode alterar o caminho de pesquisa de inclusão para \path\example\, ou remova o segmento de caminho de headers\ a `#include` diretiva.

## <a name="third-party-library-issues-and-vcpkg"></a>Problemas de biblioteca de terceiros e Vcpkg

Se você vir esse erro quando você está tentando configurar uma biblioteca de terceiros como parte da compilação, considere o uso [Vcpkg](../../vcpkg.md), o Visual C++ Gerenciador de pacotes para instalar e criar a biblioteca. Vcpkg dá suporte a um grande e crescente [lista de bibliotecas de terceiros](https://github.com/Microsoft/vcpkg/tree/master/ports)e define todas as propriedades de configuração e dependências necessárias para compilações bem-sucedidas como parte do seu projeto. Para obter mais informações, consulte relacionado [Blog do Visual C++](https://blogs.msdn.microsoft.com/vcblog/2016/09/19/vcpkg-a-tool-to-acquire-and-build-c-open-source-libraries-on-windows/) lançar.

## <a name="the-file-is-in-your-project-but-not-the-include-search-path"></a>O arquivo está no seu projeto, mas não o caminho de pesquisa de inclusão

Até mesmo quando os arquivos de cabeçalho são listados na **Gerenciador de soluções** como parte de um projeto, os arquivos só são encontrados pelo compilador quando eles são referenciados por uma `#include` ou `#import` diretiva em uma fonte de arquivo e estão localizados em um inclua caminho de pesquisa. Tipos diferentes de compilações podem usar caminhos de pesquisa diferentes. O **/X** opção de compilador pode ser usada para excluir diretórios do caminho de pesquisa de inclusão. Isso permite que diferentes compilações usem arquivos de inclusão diferentes de mesmo nome, mas são mantidos em diretórios diferentes. Essa é uma alternativa à compilação condicional usando comandos do pré-processador. Para obter mais informações sobre o **/X** opção de compilador, consulte [/X (ignorar demarcadores de inclusão padrão)](../../build/reference/x-ignore-standard-include-paths.md).

Para corrigir esse problema, corrija o caminho que o compilador usa para procurar o arquivo incluído ou importado. Um novo padrão de usos de projeto incluem caminhos de pesquisa. Talvez você precise modificar o caminho de pesquisa de inclusão para adicionar um diretório para seu projeto. Se você estiver compilando na linha de comando, adicione o caminho para o **INCLUDE** variável de ambiente ou o **/I** opção de compilador para especificar o caminho para o arquivo.

Para definir o caminho do diretório de inclusão no Visual Studio, abra o projeto **páginas de propriedade** caixa de diálogo. Selecione **diretórios VC + +** sob **propriedades de configuração** no painel esquerdo e, em seguida, editar o **diretórios de inclusão** propriedade. Para obter mais informações sobre os diretórios por usuário e por projeto pesquisados pelo compilador no Visual Studio, consulte [página de propriedade dos diretórios VC + +](../../ide/vcpp-directories-property-page.md). Para obter mais informações sobre o **/I** opção de compilador, consulte [/I (diretórios de inclusão adicionais)](../../build/reference/i-additional-include-directories.md).

## <a name="the-command-line-include-or-lib-environment-is-not-set"></a>A inclusão de linha de comando ou o ambiente LIB não está definido

Quando o compilador é invocado na linha de comando, variáveis de ambiente são geralmente usadas para especificar caminhos de pesquisa. Se o caminho de pesquisa descrito pela **INCLUDE** ou **LIB** variável de ambiente não está definida corretamente, pode ser gerado um erro C1083. É altamente recomendável usar um atalho de prompt de comando do desenvolvedor para definir o ambiente básico para a linha de comando builds. Para obter mais informações, consulte [Build C/C++ na linha de comando](../../build/building-on-the-command-line.md). Para obter mais informações sobre como usar variáveis de ambiente, consulte [como: usar variáveis de ambiente em um Build](/visualstudio/msbuild/how-to-use-environment-variables-in-a-build).

## <a name="the-file-may-be-locked-or-in-use"></a>O arquivo pode estar bloqueado ou em uso

Se você estiver usando outro programa para editar ou acessar o arquivo, ele pode ter o arquivo bloqueado. Tente fechar o arquivo em outro programa. Às vezes, o outro programa pode ser próprio Visual Studio, se você estiver usando as opções de compilação paralela. Se desativando a opção de build paralelo faz o erro desaparecer, em seguida, esse é o problema. Outros sistemas de build paralelo também podem ter esse problema. Tenha cuidado ao definir dependências de arquivo e projeto para que a ordem de compilação está correto. Em alguns casos, considere a criação de um projeto intermediário para forçar a ordem de dependência de compilação para um arquivo comum que pode ser compilado por vários projetos. Programas antivírus, às vezes, bloquear temporariamente os arquivos alterados recentemente para verificação. Se possível, considere excluindo os diretórios de compilação do projeto usando o scanner de antivírus.

## <a name="the-wrong-version-of-a-file-name-is-included"></a>A versão incorreta de um nome de arquivo foi incluída

Um erro C1083 também pode indicar que a versão incorreta de um arquivo foi incluída. Por exemplo, uma compilação poderia incluir a versão incorreta de um arquivo que tem uma diretiva `#include` para um arquivo de cabeçalho não destinado a essa compilação. Por exemplo, alguns arquivos podem se aplicar somente como x86 é compilado, ou para compilações de depuração. Quando o arquivo de cabeçalho não é localizado, o compilador gera um erro C1083. A correção desse problema é usar o arquivo correto, não adicionar o arquivo de cabeçalho ou diretório à compilação.

## <a name="the-precompiled-headers-are-not-yet-precompiled"></a>Os cabeçalhos pré-compilados ainda não foram pré-compilados

Quando um projeto é configurado para usar cabeçalhos pré-compilados, os arquivos .pch relevantes precisam ser criados de forma que os arquivos que usam o conteúdo do cabeçalho possam ser compilados. Por exemplo, o arquivo Stdafx cpp é criado automaticamente no diretório do projeto para novos projetos. Compile esse arquivo primeiro para criar os arquivos de cabeçalho pré-compilados. No design do processo de compilação típico, isso é feito automaticamente. Para obter mais informações, consulte [criando arquivos de cabeçalho pré-compilado](../../build/reference/creating-precompiled-header-files.md).

## <a name="additional-causes"></a>Causas adicionais

- Você instalou um SDK ou uma biblioteca de terceiros, mas você não abriu uma nova janela de prompt de comando do desenvolvedor após o SDK ou biblioteca é instalada. Se o SDK ou a biblioteca adiciona arquivos para o **INCLUDE** caminho, você talvez precise abrir uma nova janela de prompt de comando do desenvolvedor para pegar essas alterações na variável de ambiente.

- O arquivo usa código gerenciado, mas a opção de compilador **/clr** não for especificado. Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).

- O arquivo é compilado usando outro **/ANALYZE** configuração da opção de compilador que é usado para pré-compilar os cabeçalhos. Quando os cabeçalhos para um projeto são pré-compilados, todos devem usar o mesmo **/ANALYZE** configurações. Para obter mais informações, consulte [/analyze (Análise de Código)](../../build/reference/analyze-code-analysis.md).

- O arquivo ou diretório foi criado pelo subsistema Windows para Linux, diferenciação de maiusculas por diretório está habilitada e caso de um arquivo ou caminho especificado não coincide com o caso do caminho ou arquivo no disco.

- O arquivo, o diretório ou o disco é somente leitura.

- Visual Studio ou as ferramentas de linha de comando não tem permissões suficientes para ler o arquivo ou diretório. Isso pode acontecer, por exemplo, quando os arquivos de projeto têm propriedades diferentes que o processo executando o Visual Studio ou as ferramentas de linha de comando. Às vezes, esse problema pode ser corrigido executando o Visual Studio ou o prompt de comando do desenvolvedor como administrador.

- Não há identificadores de arquivo suficientes. Feche alguns aplicativos e recompile-os. Essa condição é incomum em circunstâncias normais. No entanto, pode ocorrer quando projetos grandes são compilados em um computador com memória física limitada.

## <a name="example"></a>Exemplo

O exemplo a seguir gera um erro C1083 quando o arquivo de cabeçalho `"test.h"` não existe no diretório de origem ou no caminho de pesquisa de inclusão.

```cpp
// C1083.cpp
// compile with: /c
#include "test.h"   // C1083 test.h does not exist
#include "stdio.h"  // OK
```

Para obter informações sobre como compilar projetos C/C++ no IDE ou na linha de comando e informações sobre como definir variáveis de ambiente, consulte [compilando programas C/C++](../../build/building-c-cpp-programs.md).

## <a name="see-also"></a>Consulte também

- [Propriedades MSBuild](/visualstudio/msbuild/msbuild-properties)
