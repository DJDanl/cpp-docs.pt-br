---
title: '&lt;filesystem&gt;'
ms.date: 11/04/2016
f1_keywords:
- filesystem/std::experimental::filesystem::directory_entry
- filesystem/std::experimental::filesystem::recursive_directory_iterator
- filesystem/std::experimental::filesystem::path
- filesystem/std::experimental::filesystem::filesystem_error
- filesystem/std::experimental::filesystem::directory_iterator
- <filesystem>
ms.assetid: 5005753b-46fa-43e1-8d4e-1b38617d3cfd
ms.openlocfilehash: 54817eeeba0b885cbf3de558c04fe2eb5d6e14fa
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62159841"
---
# <a name="ltfilesystemgt"></a>&lt;filesystem&gt;

Inclua o cabeçalho &lt;filesystem> para acessar classes e funções que manipulam e recuperam informações sobre caminhos, arquivos e diretórios.

## <a name="syntax"></a>Sintaxe

```cpp
#include <experimental/filesystem> // C++-standard header file name
#include <filesystem> // Microsoft-specific implementation header file name
using namespace std::experimental::filesystem::v1;
```

> [!IMPORTANT]
> A partir da versão do Visual Studio 2017, o \<filesystem > cabeçalho ainda não era um padrão de C++. O Visual C++ 2017 implementa o padrão final de rascunho, encontrado em [ISO/IEC JTC 1/SC 22/WG 21 N4100](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4100.pdf).

Esse cabeçalho dá suporte a sistemas de arquivos para uma das duas classes amplas de sistemas operacionais host: Microsoft Windows e Posix.

Enquanto a maioria das funcionalidades são comuns para ambos os sistemas operacionais, este documento identifica onde ocorrem as diferenças. Por exemplo:

- O Windows dá suporte a vários nomes de raiz, como c: ou \\\nome_rede. Um sistema de arquivos consiste em uma floresta de árvores, cada uma com seu próprio diretório raiz, como c:\ ou \\\network_name\\e cada uma com seu próprio diretório atual, para completar um nome de caminho relativo (que não é um nome de caminho absoluto).

- O Posix dá suporte a uma única árvore, sem nome de raiz, o único diretório raiz / e um único diretório atual.

Outra diferença significativa é a representação nativa dos nomes de caminho:

- O Windows usa uma sequência de terminação nula de wchar_t, codificada como UTF-16 (um ou dois elementos para cada caractere).

- O Posix usa uma sequência de terminação nula de caracteres, codificada como UTF-8 (um ou mais elementos para cada caractere).

- Um objeto do caminho de classe armazena o nome do caminho no formato nativo, mas dá suporte à conversão fácil entre esse formato armazenado e vários formatos externos:

- Uma sequência de terminação nula de caracteres, codificada como preferencial para o sistema operacional.

- Uma sequência de terminação nula de caracteres, codificada como UTF-8.

- Uma sequência de terminação nula de wchar_t, codificada como preferencial para o sistema operacional.

- Uma sequência de terminação nula de char16_t, codificada como UTF-16.

- Uma sequência de terminação nula de char32_t, codificada como UTF-32.

Interconversões entre essas representações são mediadas, conforme necessário, pelo uso de uma ou mais facetas de `codecvt`. Se um objeto de localidade específico não for designado, essas facetas serão obtidas da localidade global.

Outra diferença é o detalhamento com que cada sistema operacional permite especificar permissões de acesso de arquivo ou diretório:

1. O Windows registra se um arquivo é somente leitura ou gravável, um atributo que não tem nenhum significado para diretórios.

1. O Posix registra se um arquivo pode ser lido, gravado ou executado (verificado se for um diretório) pelo proprietário, pelo grupo do proprietário ou por todo mundo, bem como algumas outras permissões.

É comum aos dois sistemas a estrutura imposta a um nome de caminho quando você passar do nome da raiz. Para o nome de caminho c:/abc/xyz/def.ext:

- O nome da raiz é c:.

- O diretório raiz é /.

- O caminho raiz é c:/.

- O caminho relativo é abc/xyz/def.ext.

- O caminho pai é c:/abc/xyz.

- O nome de arquivo é def.ext.

- O tronco é def.

- A extensão é .ext.

Uma pequena diferença é o **separador preferencial** entre a sequência de diretórios em um nome de caminho. Os dois sistemas operacionais permitem escrever uma barra /, mas em alguns contextos o Windows prefere uma barra invertida \\.

Por fim, um recurso importante dos objetos de caminho é que você pode usá-los sempre que um argumento de nome de arquivo for necessário nas classes definidas no cabeçalho \<fstream>.

Para obter mais informações e exemplos de código, consulte [Navegação do Sistema de Arquivos (C++)](../standard-library/file-system-navigation.md).

## <a name="classes"></a>Classes

|Nome|Descrição|
|----------|-----------------|
|[Classe directory_entry](../standard-library/directory-entry-class.md)|Descreve um objeto retornado por um `directory_iterator` ou um `recursive_directory_iterator` e contém um caminho.|
|[Classe directory_iterator](../standard-library/directory-iterator-class.md)|Descreve um iterador de entrada que percorre em sequência os nomes de arquivo no diretório de um sistema de arquivos.|
|[Classe filesystem_error](../standard-library/filesystem-error-class.md)|Uma classe base para exceções que são geradas para relatar um estouro de baixo nível no sistema.|
|[Classe path](../standard-library/path-class.md)|Define uma classe que armazena um objeto do tipo de modelo `String` que é adequado para uso como um nome de arquivo.|
|[Classe recursive_directory_iterator](../standard-library/recursive-directory-iterator-class.md)|Descreve um iterador de entrada que percorre em sequência os nomes de arquivo no diretório de um sistema de arquivos. O iterador também pode descer para subdiretórios.|
|[Classe file_status](../standard-library/file-status-class.md)|Encapsula um `file_type`.|

## <a name="structs"></a>Structs

|Nome|Descrição|
|----------|-----------------|
|[Estrutura space_info](../standard-library/space-info-structure.md)|Mantém informações sobre um volume.|

## <a name="functions"></a>Funções

[\<funções filesystem>](../standard-library/filesystem-functions.md)

## <a name="operators"></a>Operadores

[\<operadores filesystem>](../standard-library/filesystem-operators.md)

## <a name="enumerations"></a>Enumerações

|Nome|Descrição|
|----------|-----------------|
|[copy_options](../standard-library/filesystem-enumerations.md#copy_options)|Uma enumeração que é usada com [copy_file](../standard-library/filesystem-functions.md#copy_file) e determina o comportamento se um arquivo de destino já existir.|
|[copy_options](../standard-library/filesystem-enumerations.md#copy_options)|Uma enumeração que é usada com [copy_file](../standard-library/filesystem-functions.md#copy_file) e determina o comportamento se um arquivo de destino já existir.|
|[directory_options](../standard-library/filesystem-enumerations.md#directory_options)|Uma enumeração que especifica opções para iteradores de diretório.|
|[file_type](../standard-library/filesystem-enumerations.md#file_type)|Uma enumeração de tipos de arquivo.|
|[perms](../standard-library/filesystem-enumerations.md#perms)|Um tipo de bitmask usado para transmitir permissões e opções de permissões|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
