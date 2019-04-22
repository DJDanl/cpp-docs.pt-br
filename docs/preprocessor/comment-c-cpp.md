---
title: comment (C/C++)
ms.date: 11/04/2016
f1_keywords:
- vc-pragma.comment
- comment_CPP
helpviewer_keywords:
- annotations [C++]
- comments [C++], compiled files
- pragmas, comment
- comment pragma
ms.assetid: 20f099ff-6303-49b3-9c03-a94b6aa69b85
ms.openlocfilehash: fb9bfef2ae751529b8424143cde020e78f17ec72
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59025264"
---
# <a name="comment-cc"></a>comment (C/C++)

Coloca um registro de comentário em um arquivo de objeto ou executável.

## <a name="syntax"></a>Sintaxe

```
#pragma comment( comment-type [,"commentstring"] )
```

## <a name="remarks"></a>Comentários

O *tipo de comentário* é um dos identificadores predefinidos, descritos abaixo, que especifica o tipo de registro de comentário. Opcional *commentstring* é uma cadeia de caracteres literal que fornece informações adicionais para alguns tipos de comentário. Porque *commentstring* é uma cadeia de caracteres literal, ele obedece às todas as regras para literais de cadeia de caracteres em relação a caracteres de escape, marcas de aspas inseridas (`"`) e a concatenação.

### <a name="compiler"></a>compilador

Coloque o nome e o número da versão do compilador no arquivo de objeto. Esse registro de comentário é ignorado pelo vinculador. Se você fornecer um *commentstring* parâmetro para esse tipo de registro, o compilador gera um aviso.

### <a name="exestr"></a>{1&gt;exestr&lt;1}

Casas *commentstring* no arquivo de objeto. No tempo de vinculação, essa cadeia de caracteres é colocada no arquivo executável. A cadeia de caracteres não será carregada na memória quando o arquivo executável for carregado; no entanto, pode ser encontrada com um programa que localiza cadeias de caracteres imprimíveis em arquivos. Um uso para esse tipo de registro de comentário é inserir um número de versão ou informações semelhantes em um arquivo executável.

`exestr` é preterido e será removido em uma versão futura; o vinculador não processa o registro de comentário.

### <a name="lib"></a>lib

Coloca um registro de pesquisa de biblioteca no arquivo de objeto. Esse tipo de comentário deve ser acompanhado por uma *commentstring* parâmetro que contém o nome (e possivelmente o caminho) da biblioteca que você deseja que o vinculador para pesquisar. O nome da biblioteca segue os registros de pesquisa de biblioteca padrão no arquivo de objeto; o vinculador procura por essa biblioteca como se você tivesse a nomeado na linha de comando desde que a biblioteca não for especificada com [/nodefaultlib](../build/reference/nodefaultlib-ignore-libraries.md). Você pode colocar vários registros de pesquisa de biblioteca no mesmo arquivo de origem; cada registro aparece no arquivo de objeto na mesma ordem em que é encontrado no arquivo de origem.

Se a ordem de biblioteca padrão e uma biblioteca adicionada for importante, compilando com o [/Zl](../build/reference/zl-omit-default-library-name.md) switch impedirá que o nome da biblioteca padrão que está sendo colocado no módulo de objeto. Um segundo pragma de comentário em pode ser usado para inserir o nome da biblioteca padrão após a biblioteca adicionada. As bibliotecas listadas com esses pragmas aparecerão no módulo de objeto na mesma ordem que são localizadas no código-fonte.

### <a name="linker"></a>vinculador

Locais de um [opção de vinculador](../build/reference/linker-options.md) no arquivo de objeto. Você pode usar esse tipo de comentário para especificar uma opção de vinculador em vez de passá-la para a linha de comando ou de especificá-la na ambiente de desenvolvimento. Por exemplo, você pode especificar a opção /include para forçar a inclusão de um símbolo:

```
#pragma comment(linker, "/include:__mySymbol")
```

Apenas o seguinte (*tipo de comentário*) opções de vinculador estão disponíveis a serem passados para o identificador do vinculador:

- [/DEFAULTLIB](../build/reference/defaultlib-specify-default-library.md)

- [/EXPORT](../build/reference/export-exports-a-function.md)

- [/INCLUDE](../build/reference/include-force-symbol-references.md)

- [/MANIFESTDEPENDENCY](../build/reference/manifestdependency-specify-manifest-dependencies.md)

- [/MERGE](../build/reference/merge-combine-sections.md)

- [/ SEÇÃO](../build/reference/section-specify-section-attributes.md)

### <a name="user"></a>usuário

Coloca um comentário geral no arquivo de objeto. O *commentstring* parâmetro contém o texto do comentário. Esse registro de comentário é ignorado pelo vinculador.

O seguinte pragma faz com que o vinculador procure pela biblioteca EMAPI.LIB na vinculação. O vinculador procura primeiro no diretório de trabalho atual e depois no caminho especificado na variável de ambiente LIB.

```
#pragma comment( lib, "emapi" )
```

O seguinte pragma faz com que o compilador coloque o nome e o número da versão do compilador no arquivo de objeto:

```
#pragma comment( compiler )
```

> [!NOTE]
> Para os comentários que possuem uma *commentstring* parâmetro, você pode usar uma macro em qualquer lugar onde você usaria uma cadeia de caracteres literal, desde que a macro se expande para um literal de cadeia de caracteres. Você também pode concatenar qualquer combinação de literais de cadeia de caracteres e macros que se expandem para literais de cadeias de caracteres. Por exemplo, a seguinte instrução é aceitável:

```
#pragma comment( user, "Compiled on " __DATE__ " at " __TIME__ )
```

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)