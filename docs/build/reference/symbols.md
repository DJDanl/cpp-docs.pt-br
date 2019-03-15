---
title: /SYMBOLS
ms.date: 09/05/2018
f1_keywords:
- /symbols
helpviewer_keywords:
- symbols, dumping
- public symbols
- symbols, displaying COFF symbol table
- symbol tables
- SYMBOLS dumpbin option
- /SYMBOLS dumpbin option
- -SYMBOLS dumpbin option
ms.assetid: 34bcae90-4561-4c77-a80c-065508dec39a
ms.openlocfilehash: a47b7da9f0b01353ef15e8b5c070c19e7c521c37
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57822542"
---
# <a name="symbols"></a>/SYMBOLS

```
/SYMBOLS
```

Esta opção exibe a tabela de símbolos COFF. Tabelas de símbolos existem em todos os arquivos de objeto. Uma tabela de símbolos COFF aparece em um arquivo de imagem apenas se ele está vinculado com a opção /DEBUG.

A seguir está uma descrição da saída de /SYMBOLS. Encontre informações adicionais sobre o significado da saída /SYMBOLS examinando Winnt. h (IMAGE_SYMBOL e IMAGE_AUX_SYMBOL) ou na documentação de COFF.

Dado o despejo de exemplo a seguir:

```
Dump of file main.obj
File Type: COFF OBJECT

COFF SYMBOL TABLE
000 00000000 DEBUG    notype       Filename     | .file
    main.cpp
002 000B1FDB ABS      notype       Static       | @comp.id
003 00000000 SECT1    notype       Static       | .drectve
    Section length     26, #relocs    0, #linenums    0, checksum 722C964F
005 00000000 SECT2    notype       Static       | .text
    Section length     23, #relocs    1, #linenums    0, checksum 459FF65F, selection    1 (pick no duplicates)
007 00000000 SECT2    notype ()    External     | _main
008 00000000 UNDEF    notype ()    External     | ?MyDump@@YAXXZ (void __cdecl MyDump(void))

String Table Size = 0x10 bytes

  Summary

         26 .drectve
         23 .text
```

## <a name="remarks"></a>Comentários

A seguinte descrição para as linhas que começam com um número de símbolo, descreve as colunas que têm informações relevantes para os usuários:

- O primeiro número de três dígitos é o símbolo/número de índice.

- Se a terceira coluna contém SECIONE*x*, o símbolo é definido na seção do arquivo de objeto. Mas se UNDEF for exibida, ela não está definida no objeto e deve ser resolvida em outro lugar.

- A quinta coluna (estático, externo) informa se o símbolo é visível somente dentro desse objeto, ou se ele é público (visível externamente). Um símbolo estático, _sym, não seria ser vinculado a um _sym símbolos públicos; Esses seriam duas instâncias diferentes de funções denominadas _sym.

A última coluna em uma linha numerada é o nome do símbolo, decoradas e não decorados.

Somente o [/HEADERS](headers.md) opção DUMPBIN está disponível para uso em arquivos produzidos com o [/GL](gl-whole-program-optimization.md) opção de compilador.

## <a name="see-also"></a>Consulte também

[Opções de DUMPBIN](dumpbin-options.md)
