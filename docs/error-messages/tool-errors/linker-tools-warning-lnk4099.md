---
title: Aviso LNK4099 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4099
helpviewer_keywords:
- LNK4099
ms.assetid: 358170a4-07cd-43fe-918f-82c32757ffc5
ms.openlocfilehash: dcf4d44c3a0b5b10035af763040c2912afc8c6f7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62310884"
---
# <a name="linker-tools-warning-lnk4099"></a>Aviso LNK4099 (Ferramentas de Vinculador)

PDB 'filename' não foi encontrado com '/ Biblioteca de objetos' ou 'caminho'; Vinculando objeto quando sem informação de depuração

O vinculador não pôde localizar o arquivo. PDB. Copiá-lo para o diretório que contém `object/library`.

Para localizar o nome do arquivo. PDB associado com o arquivo de objeto:

1. Extrair um arquivo de objeto da biblioteca com o [lib](../../build/reference/lib-reference.md) **/extract:**`objectname`**obj** `xyz` **. lib**.

1. Verifique o caminho para o arquivo. PDB com **dumpbin /section:.debug$ T /rawdata** `objectname` **obj**.

Você também pode compilar com [/Z7](../../build/reference/z7-zi-zi-debug-information-format.md), de modo que o pdb não precisa ser usado, ou remova a [/Debug](../../build/reference/debug-generate-debug-info.md) se você não tem arquivos. PDB para os objetos que você está vinculando a opção de vinculador.