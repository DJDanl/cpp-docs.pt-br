---
title: Ferramentas de vinculador LNK4099 aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4099
dev_langs:
- C++
helpviewer_keywords:
- LNK4099
ms.assetid: 358170a4-07cd-43fe-918f-82c32757ffc5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 50bdceaba2e72312febec4819b96df334b5398c2
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46025991"
---
# <a name="linker-tools-warning-lnk4099"></a>Aviso LNK4099 (Ferramentas de Vinculador)

PDB 'filename' não foi encontrado com '/ Biblioteca de objetos' ou 'caminho'; Vinculando objeto quando sem informação de depuração

O vinculador não pôde localizar o arquivo. PDB. Copiá-lo para o diretório que contém `object/library`.

Para localizar o nome do arquivo. PDB associado com o arquivo de objeto:

1. Extrair um arquivo de objeto da biblioteca com o [lib](../../build/reference/lib-reference.md) **/extract:**`objectname`**obj** `xyz` **. lib**.

1. Verifique o caminho para o arquivo. PDB com **dumpbin /section:.debug$ T /rawdata** `objectname` **obj**.

Você também pode compilar com [/Z7](../../build/reference/z7-zi-zi-debug-information-format.md), de modo que o pdb não precisa ser usado, ou remova a [/Debug](../../build/reference/debug-generate-debug-info.md) se você não tem arquivos. PDB para os objetos que você está vinculando a opção de vinculador.