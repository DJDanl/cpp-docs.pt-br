---
title: Arquivos de entrada LINK
ms.date: 11/04/2016
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
ms.openlocfilehash: 25d8e20903a97186e2c32a079fd74ece3626b7fa
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79439349"
---
# <a name="link-input-files"></a>Arquivos de entrada LINK

Você fornece o vinculador com arquivos que contêm objetos, bibliotecas padrão e de importação, recursos, definições de módulo e entrada de comando. O LINK não usa extensões de arquivo para fazer suposições sobre o conteúdo de um arquivo. Em vez disso, o LINK examina cada arquivo de entrada para determinar que tipo de arquivo é.

Os arquivos de objeto na linha de comando são processados na ordem em que aparecem na linha de comando. As bibliotecas também são pesquisadas na ordem de linha de comando, com a seguinte limitação: símbolos que não são resolvidos ao trazer um arquivo de objeto de uma biblioteca são pesquisados nessa biblioteca primeiro e, em seguida, as bibliotecas a seguir da linha de comando e das diretivas [/DEFAULTLIB (especificar biblioteca padrão)](defaultlib-specify-default-library.md) e, em seguida, para todas as bibliotecas no início da linha de comando.

> [!NOTE]
>  O LINK não aceita mais um ponto e vírgula (ou qualquer outro caractere) como o início de um comentário em arquivos de resposta e arquivos de ordem. Pontos e vírgulas são reconhecidos apenas como o início de comentários em arquivos de definição de módulo (. def).

O LINK usa os seguintes tipos de arquivos de entrada:

- [arquivos. obj](dot-obj-files-as-linker-input.md)

- [arquivos. netmodule](netmodule-files-as-linker-input.md)

- [arquivos. lib](dot-lib-files-as-linker-input.md)

- [arquivos. exp](dot-exp-files-as-linker-input.md)

- [arquivos. def](dot-def-files-as-linker-input.md)

- [arquivos. pdb](dot-pdb-files-as-linker-input.md)

- [arquivos. res](dot-res-files-as-linker-input.md)

- [arquivos. exe](dot-exe-files-as-linker-input.md)

- [arquivos. txt](dot-txt-files-as-linker-input.md)

- [arquivos. ilk](dot-ilk-files-as-linker-input.md)

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
