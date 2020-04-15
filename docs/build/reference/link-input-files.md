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
ms.openlocfilehash: aec71d4622821618f377953d36a9676e2233eefc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328198"
---
# <a name="link-input-files"></a>Arquivos de entrada LINK

Você fornece ao linker arquivos que contêm objetos, bibliotecas de importação e padrão, recursos, definições de módulos e entrada de comando. O LINK não usa extensões de arquivo para fazer suposições sobre o conteúdo de um arquivo. Em vez disso, o LINK examina cada arquivo de entrada para determinar que tipo de arquivo ele é.

Os arquivos de objeto na linha de comando são processados na ordem em que aparecem na linha de comando. Bibliotecas também são pesquisadas na ordem de linha de comando, com a seguinte ressalva: Símbolos que não são resolvidos ao trazer um arquivo de objeto de uma biblioteca são pesquisados nessa biblioteca primeiro e, em seguida, as bibliotecas a seguir da linha de comando e [/DEFAULTLIB (Especificar Biblioteca padrão)](defaultlib-specify-default-library.md) e, em seguida, para quaisquer bibliotecas no início da linha de comando.

> [!NOTE]
> Link não aceita mais um ponto e vírgula (ou qualquer outro caractere) como o início de um comentário em arquivos de resposta e arquivos de ordem. Os ponto e vírgula são reconhecidos apenas como o início dos comentários em arquivos de definição de módulo (.def).

O LINK usa os seguintes tipos de arquivos de entrada:

- [Arquivos .obj](dot-obj-files-as-linker-input.md)

- [Arquivos .netmodule](netmodule-files-as-linker-input.md)

- [Arquivos .lib](dot-lib-files-as-linker-input.md)

- [arquivos .exp](dot-exp-files-as-linker-input.md)

- [.def arquivos](dot-def-files-as-linker-input.md)

- [arquivos .pdb](dot-pdb-files-as-linker-input.md)

- [arquivos .res](dot-res-files-as-linker-input.md)

- [.exe arquivos](dot-exe-files-as-linker-input.md)

- [Arquivos .txt](dot-txt-files-as-linker-input.md)

- [Arquivos .ilk](dot-ilk-files-as-linker-input.md)

## <a name="see-also"></a>Confira também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
