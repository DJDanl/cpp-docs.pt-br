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
ms.openlocfilehash: 9fb2e6b8ee0f8ddc1512c605373671ae1c93c0b8
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57413245"
---
# <a name="link-input-files"></a>Arquivos de entrada LINK

Você pode fornecer o vinculador com arquivos que contêm objetos, importação e bibliotecas padrão, recursos, definições de módulo e comando de entrada. LINK não usa extensões de arquivo, fazer suposições sobre o conteúdo de um arquivo. Em vez disso, o LINK examina cada arquivo de entrada para determinar o tipo de arquivo é.

Arquivos de objeto na linha de comando são processados na ordem em que aparecem na linha de comando. Bibliotecas são pesquisadas na ordem de linha de comando, com a seguinte limitação: Símbolos não resolvidos quando colocar em um arquivo de objeto de uma biblioteca são pesquisada para nessa biblioteca pela primeira vez e, em seguida, as bibliotecas a seguir na linha de comando e [/DEFAULTLIB (especificar biblioteca padrão)](../../build/reference/defaultlib-specify-default-library.md) diretivas e, em seguida, a quaisquer bibliotecas no início da linha de comando.

> [!NOTE]
>  LINK não aceita mais um ponto e vírgula (ou qualquer outro caractere) como o início de um comentário em arquivos de resposta e arquivos de ordem. Ponto e vírgula é reconhecida apenas como o início de comentários em arquivos de definição de módulo (. def).

LINK usa os seguintes tipos de arquivos de entrada:

- [arquivos. obj](../../build/reference/dot-obj-files-as-linker-input.md)

- [arquivos. netmodule](../../build/reference/netmodule-files-as-linker-input.md)

- [.lib files](../../build/reference/dot-lib-files-as-linker-input.md)

- [arquivos. EXP](../../build/reference/dot-exp-files-as-linker-input.md)

- [arquivos. def](../../build/reference/dot-def-files-as-linker-input.md)

- [arquivos. PDB](../../build/reference/dot-pdb-files-as-linker-input.md)

- [arquivos. res](../../build/reference/dot-res-files-as-linker-input.md)

- [arquivos .exe](../../build/reference/dot-exe-files-as-linker-input.md)

- [arquivos. txt](../../build/reference/dot-txt-files-as-linker-input.md)

- [arquivos. ilk](../../build/reference/dot-ilk-files-as-linker-input.md)

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)
