---
title: '&lt;:::no-loc(filesystem):::&gt;'
description: 'Descreve as classes, funções e tipos no :::no-loc(filesystem)::: cabeçalho da biblioteca C++ padrão.'
ms.date: 01/22/2020
f1_keywords:
- <:::no-loc(filesystem):::>
ms.assetid: 5005753b-46fa-43e1-8d4e-1b38617d3cfd
no-loc:
- ':::no-loc(filesystem):::'
- ':::no-loc(experimental):::'
- ':::no-loc(char):::'
- ':::no-loc(wchar_t):::'
- ':::no-loc(char16_t):::'
- ':::no-loc(char32_t):::'
ms.openlocfilehash: 1b3f541619bde85131915a4d1586a44675c2906a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219138"
---
# &lt;:::no-loc(filesystem):::&gt;

Inclua o &lt; :::no-loc(filesystem):::> de cabeçalho para acesso a classes e funções que manipulam e recuperam informações sobre caminhos, arquivos e diretórios.

## <a name="syntax"></a>Sintaxe

```cpp
#include <:::no-loc(filesystem):::> // C++17 standard header file name
#include <:::no-loc(experimental):::/:::no-loc(filesystem):::> // Header file for pre-standard implementation
using namespace std:::::no-loc(experimental)::::::::no-loc(filesystem):::::v1;
```

> [!IMPORTANT]
> No lançamento do Visual Studio 2017, o \<:::no-loc(filesystem):::> cabeçalho ainda não era um padrão C++. O C++ no Visual Studio 2017 RTW implementa o padrão final de rascunho, encontrado em [ISO/IEC JTC 1/SC 22/WG 21 N4100](https://wg21.link/n4100). O Visual Studio 2017 versão 15,7 e posterior dá suporte ao novo \<:::no-loc(filesystem):::> padrão c++ 17.
> Essa é uma implementação completamente nova, incompatível com a `std:::::no-loc(experimental):::` versão anterior. Ele tornou-se necessário pelo suporte do symlink, correções de bugs e alterações no comportamento padrão necessário. Atualmente, incluindo \<:::no-loc(filesystem):::> o fornece o novo `std:::::no-loc(filesystem):::` e o anterior `std:::::no-loc(experimental)::::::::no-loc(filesystem):::` . Incluindo \<:::no-loc(experimental):::/:::no-loc(filesystem):::> o fornece apenas a :::no-loc(experimental)::: implementação antiga. A :::no-loc(experimental)::: implementação será removida na próxima versão de interrupção da Abi das bibliotecas.

Esse cabeçalho dá suporte a sistemas de arquivos para uma das duas classes amplas de sistemas operacionais de host: Microsoft Windows e POSIX.

Enquanto a maioria das funcionalidades são comuns para ambos os sistemas operacionais, este documento identifica onde ocorrem as diferenças. Por exemplo:

- O Windows dá suporte a vários nomes de raiz, como `c:` ou `\\network_name` . Um sistema de arquivos consiste em uma floresta de árvores, cada uma com seu próprio diretório raiz, como `c:\` ou `\\network_name\` , e cada uma com seu próprio diretório atual, para concluir um nome de caminho relativo (um que não seja um nome de caminho absoluto).

- O POSIX dá suporte a uma única árvore, sem nome raiz, diretório raiz único `/` e um único diretório atual.

Outra diferença significativa é a representação nativa dos nomes de caminho:

- O Windows usa uma sequência com terminação nula de **`:::no-loc(wchar_t):::`** , codificada como UTF-16 (um ou mais elementos para cada :::no-loc(char)::: acter).

- O POSIX usa uma sequência com terminação nula de **`:::no-loc(char):::`** , codificada como UTF-8 (um ou mais elementos para cada :::no-loc(char)::: acter).

- Um objeto da classe `path` armazena o nome do caminho na forma nativa, mas dá suporte à conversão fácil entre esse formulário armazenado e vários formulários externos:

  - Uma sequência terminada em nulo de **`:::no-loc(char):::`** , codificada como favoreceda pelo sistema operacional.

  - Uma sequência terminada em nulo de **`:::no-loc(char):::`** , codificada como UTF-8.

  - Uma sequência terminada em nulo de **`:::no-loc(wchar_t):::`** , codificada como favoreceda pelo sistema operacional.

  - Uma sequência terminada em nulo **`:::no-loc(char16_t):::`** , codificada como UTF-16.

  - Uma sequência terminada em nulo **`:::no-loc(char32_t):::`** , codificada como UTF-32.

  Interconversões entre essas representações são mediadas, conforme necessário, pelo uso de uma ou mais facetas de `codecvt`. Se nenhum objeto de localidade específico for especificado, essas facetas serão obtidas da localidade global.

Outra diferença é o detalhamento com que cada sistema operacional permite especificar permissões de acesso de arquivo ou diretório:

- O Windows registra se um arquivo é somente leitura ou gravável, um atributo que não tem significado para os diretórios.

- O POSIX registra se um arquivo pode ser lido, gravado ou executado (verificado, se for um diretório). E se cada operação é permitida para o proprietário, o grupo do proprietário ou para todos, além de algumas outras permissões.

É comum aos dois sistemas a estrutura imposta a um nome de caminho quando você passar do nome da raiz. Para o nome do caminho `c:/abc/xyz/def.ext` :

- O nome raiz é `c:` .

- O diretório raiz é `/` .

- O caminho raiz é `c:/` .

- O caminho relativo é `abc/xyz/def.ext` .

- O caminho pai é `c:/abc/xyz` .

- O nome do arquivo é `def.ext`.

- O tronco é `def` .

- A extensão é `.ext` .

Uma diferença secundária é o separador preferido entre a sequência de diretórios em um nome de caminho. Ambos os sistemas operacionais permitem que você escreva uma barra `/` , mas em alguns contextos o Windows prefere uma barra invertida `\` . A implementação armazena seu separador preferido no membro de dados `preferred_separator` no `path` .

Por fim, `path` os objetos têm um recurso importante: você pode usá-los sempre que um argumento de nome de arquivo for necessário nas classes definidas no cabeçalho [\<fstream>](fstream.md) .

Para obter mais informações e exemplos de código, consulte [navegação do sistema de arquivos (C++)](../standard-library/file-system-navigation.md).

## <a name="members"></a>Membros

### <a name="classes"></a>Classes

|||
|-|-|
|[Classe directory_entry](../standard-library/directory-entry-class.md)|Descreve um objeto que é retornado por um `directory_iterator` ou um `recursive_directory_iterator` e contém um `path` .|
|[Classe directory_iterator](../standard-library/directory-iterator-class.md)|Descreve um iterador de entrada que percorre em sequência os nomes de arquivo no diretório de um sistema de arquivos.|
|[:::no-loc(filesystem):::classe _error](../standard-library/:::no-loc(filesystem):::-error-class.md)|Uma classe base para exceções que são geradas para relatar um estouro de baixo nível no sistema.|
|[Classe path](../standard-library/path-class.md)|Define uma classe que armazena um objeto do tipo de modelo `String` que é adequado para uso como um nome de arquivo.|
|[Classe recursive_directory_iterator](../standard-library/recursive-directory-iterator-class.md)|Descreve um iterador de entrada que percorre em sequência os nomes de arquivo no diretório de um sistema de arquivos. O iterador também pode descer para subdiretórios.|
|[Classe file_status](../standard-library/file-status-class.md)|Encapsula um `file_type`.|

### <a name="structs"></a>Estruturas

|||
|-|-|
|[estrutura de space_info](../standard-library/space-info-structure.md)|Mantém informações sobre um volume.|

## <a name="functions"></a>Funções

[\<:::no-loc(filesystem):::>funções](../standard-library/:::no-loc(filesystem):::-functions.md)

## <a name="operators"></a>Operadores

[\<:::no-loc(filesystem):::>operações](../standard-library/:::no-loc(filesystem):::-operators.md)

## <a name="enumerations"></a>Enumerações

|||
|-|-|
|[copy_options](../standard-library/:::no-loc(filesystem):::-enumerations.md#copy_options)|Uma enumeração que é usada com [copy_file](../standard-library/:::no-loc(filesystem):::-functions.md#copy_file) e determina o comportamento se um arquivo de destino já existir.|
|[directory_options](../standard-library/:::no-loc(filesystem):::-enumerations.md#directory_options)|Uma enumeração que especifica opções para iteradores de diretório.|
|[file_type](../standard-library/:::no-loc(filesystem):::-enumerations.md#file_type)|Uma enumeração de tipos de arquivo.|
|[perm_options](../standard-library/:::no-loc(filesystem):::-enumerations.md#perm_options)| Enumera as opções para a `permissions` função. |
|[perms](../standard-library/:::no-loc(filesystem):::-enumerations.md#perms)|Um tipo de bitmask usado para transmitir permissões e opções de permissões|

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)
