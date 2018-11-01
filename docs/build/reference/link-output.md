---
title: Saída LINK
ms.date: 11/04/2016
f1_keywords:
- link
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
ms.openlocfilehash: 819ac130d2f8ae45ff48a2f2c1941f717d5afd99
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50464132"
---
# <a name="link-output"></a>Saída LINK

Saída link inclui arquivos .exe, DLLs, arquivos de mapa e mensagens.

##  <a name="_core_output_files"></a> Arquivos de saída

O arquivo de saída padrão do LINK é um arquivo de .exe. Se o [/DLL](../../build/reference/dll-build-a-dll.md) opção for especificada, o LINK compila um arquivo. dll. Você pode controlar o nome do arquivo de saída com o [nome do arquivo de saída (/out)](../../build/reference/out-output-file-name.md) opção.

No modo incremental, o LINK cria um arquivo. ilk para manter informações de status para mais tarde as compilações incrementais do programa. Para obter detalhes sobre os arquivos. ilk, consulte [arquivos. ilk](../../build/reference/dot-ilk-files-as-linker-input.md). Para obter mais informações sobre a vinculação incremental, consulte o [vincular de maneira incremental (/incremental)](../../build/reference/incremental-link-incrementally.md) opção.

Quando o LINK cria um programa que contém exporta (geralmente uma DLL), mas também cria um arquivo. lib, a menos que um arquivo. EXP foi usado na compilação. Você pode controlar o nome de arquivo de biblioteca de importação com o [/IMPLIB](../../build/reference/implib-name-import-library.md) opção.

Se o [Gerar Mapfile (/Map)](../../build/reference/map-generate-mapfile.md) opção for especificada, o LINK cria um arquivo de mapa.

Se o [gerar informações de depuração (/debug)](../../build/reference/debug-generate-debug-info.md) opção for especificada, o LINK cria um PDB para conter informações de depuração para o programa.

##  <a name="_core_other_output"></a> Outra saída

Quando você digita `link` sem qualquer outra entrada de linha de comando, o LINK exibirá uma instrução de uso que resume as suas opções.

LINK exibe uma mensagem de copyright e de versão e ecoa a entrada, do arquivo de comando, a menos que o [Suprimir faixa de inicialização (/ /NOLOGO)](../../build/reference/nologo-suppress-startup-banner-linker.md) opção é usada.

Você pode usar o [imprimir mensagens de andamento (/verbose)](../../build/reference/verbose-print-progress-messages.md) opção para exibir detalhes adicionais sobre a compilação.

LINK emite mensagens de erro e aviso no formulário LNK*nnnn*. Esse prefixo de erro e o intervalo de números também são usadas pelo LIB (DUMPBIN) e (editbin).

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)