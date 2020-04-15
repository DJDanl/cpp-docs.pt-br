---
title: Blocos de descrição
description: O NMAKE usa blocos de descrição para associar alvos, dependências e comandos em um makefile.
ms.date: 10/29/2019
helpviewer_keywords:
- description blocks
- NMAKE program, description blocks
- blocks, description
ms.assetid: 1321f228-d389-40ac-b0cd-4f6e9293602b
ms.openlocfilehash: e4e80b59d3d30b3b34c55b40d337ef5c078e6404
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81322260"
---
# <a name="description-blocks"></a>Blocos de descrição

Blocos de descrição formam o núcleo de um arquivo de make. Eles descrevem os *alvos*, ou arquivos para criar, e suas *dependências*, os arquivos necessários para criar os alvos. Um bloco de descrição pode incluir *comandos,* que descrevem como criar os alvos a partir das dependências. Um bloco de descrição é uma linha de dependência, opcionalmente seguida por um bloco de comandos:

```makefile
targets... : dependents...
    commands...
```

## <a name="dependency-lines"></a>Linhas de dependência

Uma *linha de dependência* especifica um ou mais alvos e zero ou mais dependentes. Se um alvo não existir ou tiver um carimbo de data e hora anterior que um dependente, o NMAKE executará os comandos no bloco de comando. O NMAKE também executa o bloco de comando se o alvo for um [pseudotarget](pseudotargets.md). Aqui está uma linha de dependência de exemplo:

```makefile
hi_bye.exe : hello.obj goodbye.obj helper.lib
```

Nesta linha de `hi_bye.exe` dependência, está o alvo. Suas dependências `hello.obj` `goodbye.obj`são, `helper.lib`e . A linha de dependência diz à `hello.obj`NMAKE para construir o alvo sempre que , `goodbye.obj`ou `helper.lib` tiver mudado mais recentemente do que `hi_bye.exe`.

Um alvo deve estar no início da linha. Não pode ser recuado com espaços ou guias. Use um`:`cólon ( ) para separar alvos de dependentes. Espaços ou abas são permitidos entre alvos, o separador de cólon (`:`) e dependentes. Para dividir a linha de dependência,`\`use uma barra invertida () após um alvo ou dependente.

Antes de executar blocos de comando, o NMAKE escaneia todas as dependências e quaisquer regras de inferência aplicáveis para construir uma *árvore de dependência*. Uma árvore de dependência especifica as etapas necessárias para atualizar totalmente o destino. O NMAKE verifica recursivamente se um dependente é um alvo em outra lista de dependência. Depois de construir a árvore de dependência, o NMAKE verifica os carimbos de tempo. Se os dependentes na árvore forem mais novos que o alvo, o NMAKE construirá o alvo.

## <a name="targets"></a><a name="targets"></a>Alvos

A seção de alvos de uma linha de dependência especifica um ou mais alvos. Um alvo pode ser qualquer nome de arquivo válido, nome do diretório ou [pseudotarget](pseudotargets.md). Separe vários alvos usando um ou mais espaços ou guias. Os alvos não são sensíveis a casos. Caminhos são permitidos com nomes de arquivos. Um alvo e seu caminho não podem exceder 256 caracteres. Se o alvo que precede o cólon for um único caractere, use um espaço de separação. Caso contrário, o NMAKE interpreta a combinação de letras-cólon como um especificador de unidade.

### <a name="multiple-targets"></a><a name="multiple-targets"></a>Múltiplos alvos

O NMAKE avalia vários alvos em uma única dependência como se cada um fosse especificado em um bloco de descrição separado.

Por exemplo, esta regra:

```makefile
bounce.exe leap.exe : jump.obj
   echo Building...
```

é avaliado como:

```makefile
bounce.exe : jump.obj
   echo Building...

leap.exe : jump.obj
   echo Building...
```

### <a name="cumulative-dependencies"></a><a name="cumulative-dependencies"></a>Dependências cumulativas

As dependências são cumulativas em um bloco de descrição, se um alvo for repetido.

Por exemplo, esse conjunto de regras,

```makefile
bounce.exe : jump.obj
bounce.exe : up.obj
   echo Building bounce.exe...
```

é avaliado como:

```makefile
bounce.exe : jump.obj up.obj
   echo Building bounce.exe...
```

Quando você tem vários alvos em várias linhas de dependência em um único bloco de descrição, o NMAKE os avalia como se cada um fosse especificado em um bloco de descrição separado. No entanto, apenas os alvos na última linha de dependência usam o bloco de comandos. O NMAKE tenta usar uma regra de inferência para os outros alvos.

Por exemplo, esse conjunto de regras,

```makefile
leap.exe bounce.exe : jump.obj
bounce.exe climb.exe : up.obj
   echo Building bounce.exe...
```

é avaliado como:

```makefile
leap.exe : jump.obj
# invokes an inference rule

bounce.exe : jump.obj up.obj
   echo Building bounce.exe...

climb.exe : up.obj
   echo Building bounce.exe...
```

### <a name="targets-in-multiple-description-blocks"></a><a name="targets-in-multiple-description-blocks"></a>Alvos em vários blocos de descrição

Para atualizar um alvo em mais de um bloco de descrição usando diferentes comandos, especifique dois pontos consecutivos (::) entre alvos e dependentes.

```makefile
target.lib :: one.asm two.asm three.asm
    ml one.asm two.asm three.asm
    lib target one.obj two.obj three.obj
target.lib :: four.c five.c
    cl /c four.c five.c
    lib target four.obj five.obj
```

### <a name="dependency-side-effects"></a><a name="dependency-side-effects"></a>Efeitos colaterais de dependência

Você pode especificar um alvo com um cólon (:) em duas linhas de dependência em locais diferentes. Se os comandos aparecerem após apenas uma das linhas, o NMAKE interpretará as dependências como se as linhas fossem adjacentes ou combinadas. Não invoca uma regra de inferência para a dependência que não tem comandos. Em vez disso, o NMAKE assume que as dependências pertencem a um bloco de descrição e executa os comandos especificados com a outra dependência. Considere este conjunto de regras:

```makefile
bounce.exe : jump.obj
   echo Building bounce.exe...

bounce.exe : up.obj
```

é avaliado como:

```makefile
bounce.exe : jump.obj up.obj
   echo Building bounce.exe...
```

Este efeito não ocorre se um`::`duplo cólon () for usado. Por exemplo, este conjunto de regras:

```makefile
bounce.exe :: jump.obj
   echo Building bounce.exe...

bounce.exe :: up.obj
```

é avaliado como:

```makefile
bounce.exe : jump.obj
   echo Building bounce.exe...

bounce.exe : up.obj
# invokes an inference rule
```

### <a name="pseudotargets"></a><a name="pseudotargets"></a>Pseudoalvos

Um *pseudotarget* é um rótulo usado no lugar de um nome de arquivo em uma linha de dependência. É interpretado como um arquivo que não existe, e por isso está desatualizado. A NMAKE assume que o carimbo de tempo de um pseudotarget é o mesmo que o mais recente de todos os seus dependentes. Se não tiver dependentes, o tempo atual é assumido. Se um pseudoalvo é usado como alvo, seus comandos são sempre executados. Um pseudoalvo usado como dependente também deve aparecer como um alvo em outra dependência. No entanto, essa dependência não precisa ter um bloco de comandos.

Os nomes pseudotarget seguem as regras de sintaxe do nome do arquivo para alvos. No entanto, se o nome não tiver uma extensão, ele pode exceder o limite de 8 caracteres para nomes de arquivos, e pode ter até 256 caracteres.

Pseudoalvos são úteis quando você quer que o NMAKE construa mais de um alvo automaticamente. O NMAKE só constrói alvos especificados na linha de comando. Ou, se nenhum alvo de linha de comando for especificado, ele constrói apenas o primeiro alvo na primeira dependência no makefile. Você pode dizer ao NMAKE para construir vários alvos sem listá-los individualmente na linha de comando. Escreva um bloco de descrição com uma dependência contendo um pseudotarget e liste os alvos que você deseja construir como seus dependentes. Em seguida, coloque este bloco de descrição primeiro no makefile ou especifique o pseudotarget na linha de comando NMAKE.

Neste exemplo, UPDATE é um pseudotarget.

```makefile
UPDATE : *.*
!COPY $** c:\product\release
```

Quando UPDATE é avaliado, o NMAKE copia todos os arquivos no diretório atual para a unidade e o diretório especificados.

No arquivo de make a `all` seguir, `project1.exe` `project2.exe` o `all` pseudotarget constrói ambos e se um ou nenhum alvo é especificado na linha de comando. O pseudotarget `setenv` altera a variável `.exe` de ambiente LIB antes que os arquivos sejam atualizados:

```makefile
all : setenv project1.exe project2.exe

project1.exe : project1.obj
    LINK project1;

project2.exe : project2.obj
    LINK project2;

setenv :
    set LIB=\project\lib
```

## <a name="dependents"></a><a name="dependents"></a>Dependentes

Em uma linha de dependência, especifique`:`zero ou mais`::`dependentes após o cólon ( ) ou duplo cólon ( ), usando qualquer nome de arquivo ou [pseudotarget](pseudotargets.md)válido . Separe vários dependentes usando um ou mais espaços ou guias. Dependentes não são sensíveis a casos. Caminhos são permitidos com nomes de arquivos.

### <a name="inferred-dependents"></a><a name="inferred-dependents"></a>Dependentes inferidos

Juntamente com os dependentes que você lista explicitamente na linha de dependência, o NMAKE pode assumir um *dependente inferido*. Um dependente inferido é derivado de uma regra de inferência, e é avaliado antes de dependentes explícitos. Quando um dependente inferido está desatualizado em comparação com seu alvo, o NMAKE invoca o bloco de comando para a dependência. Se um dependente inferido não existir ou estiver desatualizado em comparação com seus próprios dependentes, o NMAKE primeiro atualiza o dependente inferido. Para obter mais informações sobre dependentes inferidos, consulte [as regras de inferência](inference-rules.md).

### <a name="search-paths-for-dependents"></a><a name="search-paths-for-dependents"></a>Trilhas de busca de dependentes

Você pode especificar um caminho de pesquisa opcional para cada dependente. Aqui está a sintaxe para especificar um conjunto de diretórios para pesquisar:

> **{**_diretório;_\[**;** _diretório_...] **}**_dependente_

Enclose nomes de diretórioem`{ }`aparelhos (). Separe vários diretórios com`;`ponto e vírgula ( ). Não são permitidos espaços ou abas. O NMAKE procura o dependente primeiro no diretório atual e, em seguida, na lista de diretórios na ordem especificada. Você pode usar uma macro para especificar parte ou todo um caminho de pesquisa. Apenas o dependente especificado usa esse caminho de pesquisa.

#### <a name="directory-search-path-example"></a>Exemplo de caminho de pesquisa de diretório

Esta linha de dependência mostra como criar uma especificação de diretório para uma pesquisa:

```makefile
reverse.exe : {\src\omega;e:\repo\backwards}retro.obj
```

O `reverse.exe` alvo tem `retro.obj`um dependente, . A lista incluída no aparelho especifica dois diretórios. NMAKE procura `retro.obj` primeiro no diretório atual. Se não estiver lá, o `\src\omega` NMAKE procura `e:\repo\backwards` o diretório, depois o diretório.

## <a name="see-also"></a>Confira também

[Referência a NMAKE](nmake-reference.md)
