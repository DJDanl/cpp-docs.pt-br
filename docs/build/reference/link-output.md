---
title: Saída LINK | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- link
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ae68de707ece35825a32a404ce14032d4bbd3141
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32376722"
---
# <a name="link-output"></a>Saída LINK
Saída link inclui arquivos .exe, DLLs, arquivos de mapa e mensagens.  
  
##  <a name="_core_output_files"></a> Arquivos de saída  
 O arquivo de saída padrão do LINK é um arquivo de .exe. Se o [/DLL](../../build/reference/dll-build-a-dll.md) opção for especificada, o LINK cria um arquivo. dll. Você pode controlar o nome do arquivo de saída com o [nome de arquivo de saída (/out)](../../build/reference/out-output-file-name.md) opção.  
  
 No modo incremental, LINK cria um arquivo. ilk para armazenar informações de status para posteriores compilações incrementais do programa. Para obter detalhes sobre os arquivos. ilk, consulte [arquivos. ilk](../../build/reference/dot-ilk-files-as-linker-input.md). Para obter mais informações sobre a vinculação incremental, consulte o [Link incremental (/incremental)](../../build/reference/incremental-link-incrementally.md) opção.  
  
 Quando o LINK cria um programa que contenha exporta (geralmente uma DLL), ele também cria um arquivo. lib, a menos que um arquivo. EXP foi usado na compilação. Você pode controlar o nome de arquivo de biblioteca de importação com o [/IMPLIB](../../build/reference/implib-name-import-library.md) opção.  
  
 Se o [Gerar Mapfile (/Map)](../../build/reference/map-generate-mapfile.md) opção for especificada, o LINK cria um arquivo de mapa.  
  
 Se o [gerar informações de depuração (/debug)](../../build/reference/debug-generate-debug-info.md) opção for especificada, o LINK cria um PDB para conter as informações de depuração para o programa.  
  
##  <a name="_core_other_output"></a> Outra saída  
 Quando você digita `link` sem qualquer outra entrada de linha de comando, o LINK exibirá uma instrução de uso que resume as opções.  
  
 LINK exibirá uma mensagem de direitos autorais e a versão e exibe o arquivo de comando de entrada, a menos que o [Suprimir faixa de inicialização (/ /NOLOGO)](../../build/reference/nologo-suppress-startup-banner-linker.md) opção é usada.  
  
 Você pode usar o [imprimir mensagens de andamento (/verbose)](../../build/reference/verbose-print-progress-messages.md) opção para exibir detalhes adicionais sobre a compilação.  
  
 LINK emite mensagens de erro e aviso no formulário LNK*nnnn*. Esse prefixo de erro e o intervalo de números também são usados por LIB, DUMPBIN e EDITBIN.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)