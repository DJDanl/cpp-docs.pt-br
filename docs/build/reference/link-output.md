---
title: Saída LINK
ms.date: 11/04/2016
helpviewer_keywords:
- mapfiles [C++]
- ILK files
- output files [C++], linker
- files [C++], LINK
- .ilk files
- LINK tool [C++], output
- import libraries [C++], creating
- executable files [C++], as linker output
- mapfiles [C++], LINK output
- linker [C++], output files
- DLLs [C++], as linker output
- LINK tool [C++], mapfile
ms.assetid: a98b557c-1947-447a-be1f-616fb45a9580
ms.openlocfilehash: 253f88ed50b9f064edf976277a4618e4f101ec7e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81331789"
---
# <a name="link-output"></a>Saída LINK

A saída de link inclui arquivos .exe, DLLs, arquivos de mapa e mensagens.

## <a name="output-files"></a><a name="_core_output_files"></a>Arquivos de saída

O arquivo de saída padrão do LINK é um arquivo .exe. Se a opção [/DLL](dll-build-a-dll.md) for especificada, o LINK criará um arquivo .dll. Você pode controlar o nome do arquivo de saída com a opção [Nome do arquivo de saída (/OUT).](out-output-file-name.md)

No modo incremental, o LINK cria um arquivo .ilk para reter informações de status para compilações incrementais posteriores do programa. Para obter detalhes sobre arquivos .ilk, consulte [Arquivos .ilk](dot-ilk-files-as-linker-input.md). Para obter mais informações sobre vinculação incremental, consulte a opção [Link Incrementally (/INCREMENTAL).](incremental-link-incrementally.md)

Quando o LINK cria um programa que contém exportações (geralmente uma DLL), ele também cria um arquivo .lib, a menos que um arquivo .exp tenha sido usado na compilação. Você pode controlar o nome do arquivo da biblioteca de importação com a opção [/IMPLIB.](implib-name-import-library.md)

Se a opção [Gerar arquivo de mapa (/MAP)](map-generate-mapfile.md) for especificada, o LINK criará um arquivo de mapa.

Se a opção [Gerar depuração de informações (/DEBUG)](debug-generate-debug-info.md) for especificada, o LINK criará um PDB para conter informações de depuração para o programa.

## <a name="other-output"></a><a name="_core_other_output"></a>Outra suinotin0

Quando você `link` digita sem qualquer outra entrada de linha de comando, o LINK exibe uma declaração de uso que resume suas opções.

O LINK exibe uma entrada de arquivo de comando e de direitos autorais e ecos, a menos que a opção [Suprimir o Banner de inicialização (/NOLOGO)](nologo-suppress-startup-banner-linker.md) seja usada.

Você pode usar a opção [Imprimir mensagens de progresso (/VERBOSE)](verbose-print-progress-messages.md) para exibir detalhes adicionais sobre a compilação.

Link emite mensagens de erro e aviso no formulário LNK*nnnn*. Este prefixo de erro e a gama de números também são usados por LIB, DUMPBIN e EDITBIN.

## <a name="see-also"></a>Confira também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
