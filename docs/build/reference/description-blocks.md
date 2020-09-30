---
title: Blocos de descrição
description: O NMAKE usa blocos de descrição para associar destinos, dependências e comandos em um makefile.
ms.date: 10/29/2019
helpviewer_keywords:
- description blocks
- NMAKE program, description blocks
- blocks, description
ms.assetid: 1321f228-d389-40ac-b0cd-4f6e9293602b
ms.openlocfilehash: 8f7bf3a26eadde91471e8b45ec26e0abea906244
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91506591"
---
# <a name="description-blocks"></a>Blocos de descrição

Os blocos de descrição formam o núcleo de um makefile. Eles descrevem os *destinos*, os arquivos a serem criados e suas *dependências*, os arquivos necessários para criar os destinos. Um bloco de descrição pode incluir *comandos*, que descrevem como criar os destinos das dependências. Um bloco de descrição é uma linha de dependência, opcionalmente seguido por um bloco de comandos:

```makefile
targets... : dependents...
    commands...
```

## <a name="dependency-lines"></a>Linhas de dependência

Uma *linha de dependência* especifica um ou mais destinos e zero ou mais dependentes. Se um destino não existir ou tiver um carimbo de data e hora anterior do que um dependente, NMAKE executará os comandos no bloco de comando. NMAKE também executará o bloco de comando se o destino for um [pseudotarget](#pseudotargets). Aqui está um exemplo de linha de dependência:

```makefile
hi_bye.exe : hello.obj goodbye.obj helper.lib
```

Nessa linha de dependência, `hi_bye.exe` é o destino. Suas dependências são `hello.obj` , `goodbye.obj` e `helper.lib` . A linha de dependência diz ao NMAKE para criar o destino sempre que `hello.obj` , `goodbye.obj` , ou `helper.lib` foi alterado mais recentemente do que `hi_bye.exe` .

Um destino deve estar no início da linha. Ele não pode ser recuado com espaços ou tabulações. Use dois-pontos ( `:` ) para separar destinos de dependentes. Espaços ou guias são permitidos entre os destinos, o separador de dois pontos ( `:` ) e os dependentes. Para dividir a linha de dependência, use uma barra invertida ( `\` ) após um destino ou dependente.

Antes de executar os blocos de comando, o NMAKE examina todas as dependências e as regras de inferência aplicáveis para criar uma *árvore de dependência*. Uma árvore de dependência especifica as etapas necessárias para atualizar totalmente o destino. NMAKE verifica recursivamente se um dependente é um destino em outra lista de dependências. Depois de criar a árvore de dependência, o NMAKE verifica carimbos de data/hora. Se qualquer dependente na árvore for mais novo do que o destino, o NMAKE criará o destino.

## <a name="targets"></a><a name="targets"></a> Aos

A seção destinos de uma linha de dependência especifica um ou mais destinos. Um destino pode ser qualquer nome de arquivo, nome de diretório ou [pseudotarget](#pseudotargets)válido. Separe vários destinos usando um ou mais espaços ou guias. Os destinos não diferenciam maiúsculas de minúsculas. Os caminhos são permitidos com nomes de File. Um destino e seu caminho não podem exceder 256 caracteres. Se o destino que precede os dois-pontos for um único caractere, use um espaço separando. Caso contrário, NMAKE interpretará a combinação de letras-e-vírgula como um especificador de unidade.

### <a name="multiple-targets"></a><a name="multiple-targets"></a> Vários destinos

NMAKE avalia vários destinos em uma única dependência como se cada um fosse especificado em um bloco de descrição separado.

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

### <a name="cumulative-dependencies"></a><a name="cumulative-dependencies"></a> Dependências cumulativas

As dependências são cumulativas em um bloco de descrição, se um destino for repetido.

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

Quando você tem vários destinos em várias linhas de dependência em um único bloco de descrição, NMAKE os avalia como se cada um fosse especificado em um bloco de descrição separado. No entanto, somente os destinos na última linha de dependência usam o bloco comandos. NMAKE tenta usar uma regra de inferência para os outros destinos.

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

### <a name="targets-in-multiple-description-blocks"></a><a name="targets-in-multiple-description-blocks"></a> Destinos em vários blocos de descrição

Para atualizar um destino em mais de um bloco de descrição usando comandos diferentes, especifique dois dois-pontos consecutivos (::) entre os destinos e os dependentes.

```makefile
target.lib :: one.asm two.asm three.asm
    ml one.asm two.asm three.asm
    lib target one.obj two.obj three.obj
target.lib :: four.c five.c
    cl /c four.c five.c
    lib target four.obj five.obj
```

### <a name="dependency-side-effects"></a><a name="dependency-side-effects"></a> Efeitos colaterais de dependência

Você pode especificar um destino com dois-pontos (:) em duas linhas de dependência em locais diferentes. Se os comandos aparecerem depois de apenas uma das linhas, NMAKE interpretará as dependências como se as linhas fossem adjacentes ou combinadas. Ele não invoca uma regra de inferência para a dependência que não tem comandos. Em vez disso, NMAKE assume que as dependências pertencem a um bloco de descrição e executa os comandos especificados com a outra dependência. Considere este conjunto de regras:

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

Esse efeito não ocorrerá se um dois pontos duplos ( `::` ) for usado. Por exemplo, esse conjunto de regras:

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

### <a name="pseudotargets"></a><a name="pseudotargets"></a> Pseudotargets

Um *pseudotarget* é um rótulo usado no lugar de um nome de arquivo em uma linha de dependência. Ele é interpretado como um arquivo que não existe e, portanto, está desatualizado. NMAKE assume que o carimbo de data/hora de um pseudotarget é o mesmo que o mais recente de todos os seus dependentes. Se não houver nenhum dependente, a hora atual será assumida. Se um pseudotarget for usado como um destino, seus comandos serão sempre executados. Um pseudotarget usado como dependente também deve aparecer como um destino em outra dependência. No entanto, essa dependência não precisa ter um bloco de comandos.

Os nomes de pseudotarget seguem as regras de sintaxe de nome de arquivo para destinos. No entanto, se o nome não tiver uma extensão, ele poderá exceder o limite de 8 caracteres para nomes de Filee pode ter até 256 caracteres.

Pseudotargets são úteis quando você deseja que o NMAKE crie mais de um destino automaticamente. NMAKE apenas cria destinos especificados na linha de comando. Ou, se nenhum destino de linha de comando for especificado, ele criará apenas o primeiro destino na primeira dependência no Makefile. Você pode dizer ao NMAKE para criar vários destinos sem listá-los individualmente na linha de comando. Escreva um bloco de descrição com uma dependência que contenha um pseudotarget e liste os destinos que você deseja compilar como seus dependentes. Em seguida, coloque esse bloco de descrição primeiro no makefile ou especifique o pseudotarget na linha de comando NMAKE.

Neste exemplo, UPDATE é um pseudotarget.

```makefile
UPDATE : *.*
!COPY $** c:\product\release
```

Quando a atualização é avaliada, o NMAKE copia todos os arquivos no diretório atual para a unidade e o diretório especificados.

No Makefile a seguir, o pseudotarget `all` cria `project1.exe` e `project2.exe` se um `all` ou nenhum destino é especificado na linha de comando. O pseudotarget `setenv` altera a variável de ambiente LIB antes de os `.exe` arquivos serem atualizados:

```makefile
all : setenv project1.exe project2.exe

project1.exe : project1.obj
    LINK project1;

project2.exe : project2.obj
    LINK project2;

setenv :
    set LIB=\project\lib
```

## <a name="dependents"></a><a name="dependents"></a> Dependentes

Em uma linha de dependência, especifique zero ou mais dependentes após os dois-pontos ( `:` ) ou dois-pontos ( `::` ), usando qualquer nome de arquivo ou [pseudotarget](#pseudotargets)válido. Separe vários dependentes usando um ou mais espaços ou guias. Os dependentes não diferenciam maiúsculas de minúsculas. Os caminhos são permitidos com nomes de File.

### <a name="inferred-dependents"></a><a name="inferred-dependents"></a> Dependentes inferidos

Junto com os dependentes que você lista explicitamente na linha de dependência, NMAKE pode assumir um *dependente inferido*. Um dependente inferido é derivado de uma regra de inferência e é avaliado antes dos dependentes explícitos. Quando um dependente inferido está desatualizado em comparação com seu destino, NMAKE invoca o bloco de comando para a dependência. Se um dependente inferido não existir ou estiver desatualizado em comparação com seus próprios dependentes, o NMAKE primeiro atualizará o dependente inferido. Para obter mais informações sobre dependentes inferidos, consulte [regras de inferência](inference-rules.md).

### <a name="search-paths-for-dependents"></a><a name="search-paths-for-dependents"></a> Caminhos de pesquisa para dependentes

Você pode especificar um caminho de pesquisa opcional para cada dependente. Aqui está a sintaxe para especificar um conjunto de diretórios a serem pesquisados:

> **{**_diretório_ \[ **;** _diretório_...] **}**_dependente_

Coloque os nomes de diretório entre chaves ( `{ }` ). Separe vários diretórios com um ponto e vírgula ( `;` ). Não são permitidos espaços ou tabulações. NMAKE procura o dependente primeiro no diretório atual e, em seguida, na lista de diretórios na ordem especificada. Você pode usar uma macro para especificar parte ou todo um caminho de pesquisa. Somente o dependente especificado usa esse caminho de pesquisa.

#### <a name="directory-search-path-example"></a>Exemplo de caminho de pesquisa de diretório

Esta linha de dependência mostra como criar uma especificação de diretório para uma pesquisa:

```makefile
reverse.exe : {\src\omega;e:\repo\backwards}retro.obj
```

O destino `reverse.exe` tem um dependente, `retro.obj` . A lista entre chaves especifica dois diretórios. NMAKE procura `retro.obj` primeiro no diretório atual. Se não estiver lá, o NMAKE pesquisará o `\src\omega` diretório e, em seguida, o `e:\repo\backwards` diretório.

## <a name="see-also"></a>Consulte também

[Referência de NMAKE](nmake-reference.md)
