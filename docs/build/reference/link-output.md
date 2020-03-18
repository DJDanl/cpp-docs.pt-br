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
ms.openlocfilehash: 8323723f2049d3db469e874c91b99f4cfb561c72
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79439319"
---
# <a name="link-output"></a>Saída LINK

A saída do link inclui arquivos. exe, DLLs, mapfiles e mensagens.

##  <a name="_core_output_files"></a>Arquivos de saída

O arquivo de saída padrão do LINK é um arquivo. exe. Se a opção [/dll](dll-build-a-dll.md) for especificada, o link criará um arquivo. dll. Você pode controlar o nome do arquivo de saída com a opção [nome do arquivo de saída (/out)](out-output-file-name.md) .

No modo incremental, o LINK cria um arquivo. ilk para manter informações de status para compilações incrementais posteriores do programa. Para obter detalhes sobre arquivos. ilk, consulte [arquivos. ilk](dot-ilk-files-as-linker-input.md). Para obter mais informações sobre a vinculação incremental, consulte a opção [vincular incrementalmente (/incremental)](incremental-link-incrementally.md) .

Quando o LINK cria um programa que contém exportações (geralmente uma DLL), ele também cria um arquivo. lib, a menos que um arquivo. exp tenha sido usado na compilação. Você pode controlar o nome do arquivo da biblioteca de importação com a opção [/IMPLIB](implib-name-import-library.md) .

Se a opção [Generate mapa (/MAP)](map-generate-mapfile.md) for especificada, o link criará um mapa.

Se a opção [gerar informações de depuração (/debug)](debug-generate-debug-info.md) for especificada, o link criará um PDB para conter informações de depuração para o programa.

##  <a name="_core_other_output"></a>Outra saída

Quando você digita `link` sem qualquer outra entrada de linha de comando, o LINK exibe uma instrução de uso que resume suas opções.

O LINK exibe uma mensagem de direitos autorais e de versão e ecoa a entrada do arquivo de comando, a menos que a opção [Suprimir faixa de inicialização (/nologo)](nologo-suppress-startup-banner-linker.md) seja usada.

Você pode usar a opção [/Verbose (mensagens de progresso de impressão)](verbose-print-progress-messages.md) para exibir detalhes adicionais sobre a compilação.

O LINK emite mensagens de erro e aviso no formato LNK*nnnn*. Esse prefixo de erro e o intervalo de números também são usados por LIB, DUMPBIN e EDITBIN.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
