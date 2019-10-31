---
title: Opções de DUMPBIN
ms.date: 10/24/2019
f1_keywords:
- dumpbin
helpviewer_keywords:
- DUMPBIN program, options
ms.assetid: 563b696e-7599-4480-94b9-014776289ec8
ms.openlocfilehash: 81c66f1971294531a2904a0b681819476bcc1eb2
ms.sourcegitcommit: 6ed1bc5b26dc60a780c1fc5f2f19d57ba1dc47d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/30/2019
ms.locfileid: "73144549"
---
# <a name="dumpbin-options"></a>Opções de DUMPBIN

Uma opção consiste em um *especificador de opção*, que é um traço (`-`) ou uma barra (`/`), seguido pelo nome da opção. Nomes de opção não podem ser abreviados. Algumas opções usam argumentos, especificados após um sinal de dois-pontos (`:`). Não são permitidos espaços ou guias dentro de uma especificação de opção. Use um ou mais espaços ou guias para separar as especificações de opção na linha de comando. Nomes de opção e seus argumentos de nome de arquivo ou palavra-chave não diferenciam maiúsculas de minúsculas. A maioria das opções se aplica a todos os arquivos binários, mas alguns aplicam-se apenas a determinados tipos de arquivos. Por padrão, o DUMPBIN envia informações para a saída padrão. Use a opção [/out](out-dumpbin.md) para enviar a saída para um arquivo.

## <a name="options-list"></a>Lista de opções

DUMPBIN tem as seguintes opções:

- [/ALL](all.md)

- [/ARCHIVEMEMBERS](archivemembers.md)

- [/CLRHEADER](clrheader.md)

- [/DEPENDENTS](dependents.md)

- [/DIRECTIVES](directives.md)

- [\[/DISASM: {BYTES\|nobytes}\]](disasm.md)

- [/ERRORREPORT: {NONE | PROMPT | FILA | NOVAMENTE](errorreport-dumpbin-exe.md)

- [/EXPORTS](dash-exports.md)

- [/FPO](fpo.md)

- [/HEADERS](headers.md)

- [/IMPORTS\[: nome de arquivo\]](imports-dumpbin.md)

- [/LINENUMBERS](linenumbers.md)

- [\[/LINKERMEMBER: {1 | 2}\]](linkermember.md)

- [/LOADCONFIG](loadconfig.md)

- [/NOPDB](nopdb.md)

- [/OUT: nome de arquivo](out-dumpbin.md)

- [/PDATA](pdata.md)

- [\[/PDBPATH:\] detalhado](pdbpath.md)

- [/RANGEE: vaMin\[, vaMax\]](range.md)

- [/RAWDATA\[: {NONE\|1\|2\|4\|8}\[, #\]\]](rawdata.md)

- [/RELOCATIONS](relocations.md)

- [/SECTION: nome](section-dumpbin.md)

- [/SUMMARY](summary.md)

- [/SYMBOLS](symbols.md)

- [/TLS](tls.md)

Para listar as opções com suporte do DUMPBIN na linha de comando, use a opção **/?** Option.

## <a name="see-also"></a>Consulte também

[Ferramentas de compilação MSVC adicionais](c-cpp-build-tools.md)\
\ de [linha de comando DUMPBIN](dumpbin-command-line.md)
[Referência de DUMPBIN](dumpbin-reference.md)
