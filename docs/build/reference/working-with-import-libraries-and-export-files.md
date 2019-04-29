---
title: Trabalhando com bibliotecas de importação e arquivos de exportação
ms.date: 11/04/2016
helpviewer_keywords:
- LIB [C++], /DEF option
- import libraries
- LIB [C++], import libraries and export files
- export files
- import libraries, creating
ms.assetid: d8175596-9773-4c2f-959d-b05b065a5161
ms.openlocfilehash: 6f6f2d5c48c63ba6d8a8a7f67a98b949b32a8afa
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62316503"
---
# <a name="working-with-import-libraries-and-export-files"></a>Trabalhando com bibliotecas de importação e arquivos de exportação

Você pode usar LIB com a opção /DEF para criar uma biblioteca de importação e um arquivo de exportação. Usos LINK de arquivo para criar um programa que contém a exportação exporta (normalmente, uma biblioteca de vínculo dinâmico (DLL)), e ele usa a biblioteca de importação para resolver referências a essas exportações em outros programas.

Observe que se você criar sua biblioteca de importação em uma etapa preliminar, antes de criar seu. dll, você deve passar o mesmo conjunto de arquivos de objeto ao criar o arquivo. dll, conforme passado ao compilar a biblioteca de importação.

Na maioria das situações, você não precisa usar LIB para criar sua biblioteca de importação. Quando você vincula um programa (um arquivo executável ou uma DLL) que contém exportações, o LINK cria automaticamente uma biblioteca de importação que descreve as exportações. Posteriormente, quando você vincula um programa que faz referência a essas exportações, especifique a biblioteca de importação.

No entanto, quando uma DLL exporta para um programa que ele também importa de, se direta ou indiretamente, você deve usar LIB para criar uma das bibliotecas de importação. Quando o LIB cria uma biblioteca de importação, ele também cria um arquivo de exportação. Ao vincular uma das DLLs, você deve usar o arquivo de exportação.

## <a name="see-also"></a>Consulte também

[Referência de LIB](lib-reference.md)
