---
title: Linha de comando BSCMAKE
ms.date: 11/04/2016
helpviewer_keywords:
- BSCMAKE, command line
ms.assetid: 8006e8cf-8bfe-4c23-868a-b0a25e6bbf0f
ms.openlocfilehash: b6268eb6d0ea39e72a1d8fd40ab563347c05f0c6
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57416833"
---
# <a name="bscmake-command-line"></a>Linha de comando BSCMAKE

Para executar BSCMAKE, use a seguinte sintaxe de linha de comando:

```
BSCMAKE [options] sbrfiles
```

As opções podem aparecer somente no `options` campo na linha de comando.

O *sbrfiles* campo especifica um ou mais arquivos. SBR criados por um compilador ou montador. Separe os nomes dos arquivos. SBR com espaços ou tabulações. Você deve especificar a extensão; Não há nenhum padrão. Você pode especificar um caminho com o nome do arquivo, e você pode usar caracteres curinga do sistema operacional (\* e?).

Durante uma compilação incremental, você pode especificar novos arquivos. SBR que não faziam parte da compilação original. Se você quiser que todas as contribuições para permanecer no arquivo de informações de procura, você deve especificar todos os arquivos. SBR (incluindo arquivos truncados) que foram originalmente usados para criar o arquivo. bsc. Se você omitir um arquivo. SBR, contribuição do arquivo para o arquivo de informações de procura é removida.

Não especifique um arquivo. SBR truncados para uma compilação completa. Uma compilação completa exige contribuições de todos os arquivos. SBR especificado. Antes de executar uma compilação completa, recompile o projeto e crie um novo arquivo. SBR para cada arquivo vazio.

O comando a seguir executa BSCMAKE para criar um arquivo chamado MAIN.bsc dos três arquivos. SBR:

```
BSCMAKE main.sbr file1.sbr file2.sbr
```

Para obter informações relacionadas, consulte [arquivo de comando BSCMAKE](../../build/reference/bscmake-command-file-response-file.md) e [opções BSCMAKE](../../build/reference/bscmake-options.md).

## <a name="see-also"></a>Consulte também

[Referência de BSCMAKE](../../build/reference/bscmake-reference.md)
