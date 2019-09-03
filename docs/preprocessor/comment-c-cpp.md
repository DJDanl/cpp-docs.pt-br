---
title: pragma de comentário
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.comment
- comment_CPP
helpviewer_keywords:
- annotations [C++]
- comments [C++], compiled files
- pragmas, comment
- comment pragma
ms.assetid: 20f099ff-6303-49b3-9c03-a94b6aa69b85
ms.openlocfilehash: 3175ad5318bcc6fd9aa6233258ccec9033c89be8
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219101"
---
# <a name="comment-pragma"></a>pragma de comentário

Coloca um registro de comentário em um arquivo de objeto ou executável.

## <a name="syntax"></a>Sintaxe

> **#pragma comentário (** *comentário-tipo* [ **,** "*Comentário-cadeia de caracteres*"] **)**

## <a name="remarks"></a>Comentários

O *tipo de comentário* é um dos identificadores predefinidos, descritos abaixo, que especifica o tipo de registro de comentário. A *cadeia de caracteres de comentário* opcional é um literal de cadeia de caracteres que fornece informações adicionais para alguns tipos de comentários. Como *comment-String* é um literal de cadeia de caracteres, ele obedece a todas as regras para literais de cadeia de caracteres em relação a caracteres`"`de escape, aspas incorporadas () e concatenação.

### <a name="compiler"></a>compilador

Coloque o nome e o número da versão do compilador no arquivo de objeto. Esse registro de comentário é ignorado pelo vinculador. Se você fornecer um parâmetro *comment-String* para esse tipo de registro, o compilador gerará um aviso.

### <a name="lib"></a>lib

Coloca um registro de pesquisa de biblioteca no arquivo de objeto. Esse tipo de comentário deve ser acompanhado por um parâmetro de *cadeia de caracteres de comentário* que contém o nome (e possivelmente o caminho) da biblioteca que você deseja que o vinculador pesquise. O nome da biblioteca segue os registros de pesquisa de biblioteca padrão no arquivo de objeto; o vinculador pesquisa essa biblioteca como se você a tivesse nomeado na linha de comando, desde que a biblioteca não seja especificada com [/NODEFAULTLIB](../build/reference/nodefaultlib-ignore-libraries.md). Você pode colocar vários registros de pesquisa de biblioteca no mesmo arquivo de origem; cada registro aparece no arquivo de objeto na mesma ordem em que é encontrado no arquivo de origem.

Se a ordem da biblioteca padrão e de uma biblioteca adicionada for importante, a compilação com a opção [/zl](../build/reference/zl-omit-default-library-name.md) impedirá que o nome da biblioteca padrão seja colocado no módulo Object. Um segundo pragma de comentário em pode ser usado para inserir o nome da biblioteca padrão após a biblioteca adicionada. As bibliotecas listadas com esses pragmas aparecerão no módulo de objeto na mesma ordem que são localizadas no código-fonte.

### <a name="linker"></a>vinculador

Coloca uma [opção](../build/reference/linker-options.md) de vinculador no arquivo de objeto. Você pode usar esse tipo de comentário para especificar uma opção de vinculador em vez de passá-la para a linha de comando ou de especificá-la na ambiente de desenvolvimento. Por exemplo, você pode especificar a opção /include para forçar a inclusão de um símbolo:

```C
#pragma comment(linker, "/include:__mySymbol")
```

Somente as seguintes opções de vinculador (*tipo de comentário*) estão disponíveis para serem passadas para o identificador do vinculador:

- [/DEFAULTLIB](../build/reference/defaultlib-specify-default-library.md)

- [/EXPORT](../build/reference/export-exports-a-function.md)

- [/INCLUDE](../build/reference/include-force-symbol-references.md)

- [/MANIFESTDEPENDENCY](../build/reference/manifestdependency-specify-manifest-dependencies.md)

- [/MERGE](../build/reference/merge-combine-sections.md)

- [/SECTION](../build/reference/section-specify-section-attributes.md)

### <a name="user"></a>usuário

Coloca um comentário geral no arquivo de objeto. O parâmetro *comment-String* contém o texto do comentário. Esse registro de comentário é ignorado pelo vinculador.

## <a name="examples"></a>Exemplos

O seguinte pragma faz com que o vinculador procure pela biblioteca EMAPI.LIB na vinculação. O vinculador procura primeiro no diretório de trabalho atual e depois no caminho especificado na variável de ambiente LIB.

```C
#pragma comment( lib, "emapi" )
```

O seguinte pragma faz com que o compilador coloque o nome e o número da versão do compilador no arquivo de objeto:

```C
#pragma comment( compiler )
```

Para comentários que usam um parâmetro *de cadeia de caracteres de comentário* , você pode usar uma macro em qualquer lugar em que você usaria um literal de cadeia de caracteres, desde que a macro expanda para um literal de cadeia de caracteres. Você também pode concatenar qualquer combinação de literais de cadeia de caracteres e macros que se expandem para literais de cadeias de caracteres. Por exemplo, a seguinte instrução é aceitável:

```C
#pragma comment( user, "Compiled on " __DATE__ " at " __TIME__ )
```

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
