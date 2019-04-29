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
ms.openlocfilehash: 183f83501d930188032ec4209623ef7cf1a30efa
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62269170"
---
# <a name="link-output"></a>Saída LINK

Saída link inclui arquivos .exe, DLLs, arquivos de mapa e mensagens.

##  <a name="_core_output_files"></a> Arquivos de saída

O arquivo de saída padrão do LINK é um arquivo de .exe. Se o [/DLL](dll-build-a-dll.md) opção for especificada, o LINK compila um arquivo. dll. Você pode controlar o nome do arquivo de saída com o [nome do arquivo de saída (/out)](out-output-file-name.md) opção.

No modo incremental, o LINK cria um arquivo. ilk para manter informações de status para mais tarde as compilações incrementais do programa. Para obter detalhes sobre os arquivos. ilk, consulte [arquivos. ilk](dot-ilk-files-as-linker-input.md). Para obter mais informações sobre a vinculação incremental, consulte o [vincular de maneira incremental (/incremental)](incremental-link-incrementally.md) opção.

Quando o LINK cria um programa que contém exporta (geralmente uma DLL), mas também cria um arquivo. lib, a menos que um arquivo. EXP foi usado na compilação. Você pode controlar o nome de arquivo de biblioteca de importação com o [/IMPLIB](implib-name-import-library.md) opção.

Se o [Gerar Mapfile (/Map)](map-generate-mapfile.md) opção for especificada, o LINK cria um arquivo de mapa.

Se o [gerar informações de depuração (/debug)](debug-generate-debug-info.md) opção for especificada, o LINK cria um PDB para conter informações de depuração para o programa.

##  <a name="_core_other_output"></a> Outra saída

Quando você digita `link` sem qualquer outra entrada de linha de comando, o LINK exibirá uma instrução de uso que resume as suas opções.

LINK exibe uma mensagem de copyright e de versão e ecoa a entrada, do arquivo de comando, a menos que o [Suprimir faixa de inicialização (/ /NOLOGO)](nologo-suppress-startup-banner-linker.md) opção é usada.

Você pode usar o [imprimir mensagens de andamento (/verbose)](verbose-print-progress-messages.md) opção para exibir detalhes adicionais sobre a compilação.

LINK emite mensagens de erro e aviso no formulário LNK*nnnn*. Esse prefixo de erro e o intervalo de números também são usadas pelo LIB (DUMPBIN) e (editbin).

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
