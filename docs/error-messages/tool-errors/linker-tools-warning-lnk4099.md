---
title: Aviso LNK4099 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4099
helpviewer_keywords:
- LNK4099
ms.assetid: 358170a4-07cd-43fe-918f-82c32757ffc5
ms.openlocfilehash: b1f330924b8e47e0649268142106a050c83cb20a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80183313"
---
# <a name="linker-tools-warning-lnk4099"></a>Aviso LNK4099 (Ferramentas de Vinculador)

PDB ' FileName ' não foi encontrado com ' Object/library ' ou em ' path '; Vinculando objeto quando sem informação de depuração

O vinculador não pôde localizar o arquivo. pdb. Copie-o para o diretório que contém `object/library`.

Para localizar o nome do arquivo. PDB associado ao arquivo de objeto:

1. Extraia um arquivo de objeto da biblioteca com a [lib](../../build/reference/lib-reference.md) **/extract:** `objectname` **. obj** `xyz` **. lib**.

1. Verifique o caminho para o arquivo. pdb com **dumpbin/section:. debug $ T/rawdata** `objectname` **. obj**.

Você também pode compilar com [/Z7](../../build/reference/z7-zi-zi-debug-information-format.md), portanto, o PDB não precisa ser usado ou remover a opção de vinculador [/debug](../../build/reference/debug-generate-debug-info.md) se você não tiver arquivos. pdb para os objetos que está vinculando.
