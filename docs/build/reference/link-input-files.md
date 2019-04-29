---
title: Arquivos de entrada LINK
ms.date: 11/04/2016
f1_keywords:
- link
helpviewer_keywords:
- files [C++], LINK
- module definition files
- resources [C++], linker files
- LINK tool [C++], input files
- module definition files, linker files
- input files [C++], LINK
- linker [C++], input files
- import libraries [C++], linker files
- command input to linker files [C++]
ms.assetid: bb26fcc5-509a-4620-bc3e-b6c6e603a412
ms.openlocfilehash: 48ad9423ae35c22a97a873fe6a2a0479c12ab33b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62291503"
---
# <a name="link-input-files"></a>Arquivos de entrada LINK

Você pode fornecer o vinculador com arquivos que contêm objetos, importação e bibliotecas padrão, recursos, definições de módulo e comando de entrada. LINK não usa extensões de arquivo, fazer suposições sobre o conteúdo de um arquivo. Em vez disso, o LINK examina cada arquivo de entrada para determinar o tipo de arquivo é.

Arquivos de objeto na linha de comando são processados na ordem em que aparecem na linha de comando. Bibliotecas são pesquisadas na ordem de linha de comando, com a seguinte limitação: Símbolos não resolvidos quando colocar em um arquivo de objeto de uma biblioteca são pesquisada para nessa biblioteca pela primeira vez e, em seguida, as bibliotecas a seguir na linha de comando e [/DEFAULTLIB (especificar biblioteca padrão)](defaultlib-specify-default-library.md) diretivas e, em seguida, a quaisquer bibliotecas no início da linha de comando.

> [!NOTE]
>  LINK não aceita mais um ponto e vírgula (ou qualquer outro caractere) como o início de um comentário em arquivos de resposta e arquivos de ordem. Ponto e vírgula é reconhecida apenas como o início de comentários em arquivos de definição de módulo (. def).

LINK usa os seguintes tipos de arquivos de entrada:

- [arquivos. obj](dot-obj-files-as-linker-input.md)

- [arquivos. netmodule](netmodule-files-as-linker-input.md)

- [.lib files](dot-lib-files-as-linker-input.md)

- [arquivos. EXP](dot-exp-files-as-linker-input.md)

- [arquivos. def](dot-def-files-as-linker-input.md)

- [arquivos. PDB](dot-pdb-files-as-linker-input.md)

- [arquivos. res](dot-res-files-as-linker-input.md)

- [arquivos .exe](dot-exe-files-as-linker-input.md)

- [arquivos. txt](dot-txt-files-as-linker-input.md)

- [arquivos. ilk](dot-ilk-files-as-linker-input.md)

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
