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
ms.openlocfilehash: fa759482d6949b27f5076643d83e92cddc1d8fac
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57416560"
---
# <a name="working-with-import-libraries-and-export-files"></a>Trabalhando com bibliotecas de importação e arquivos de exportação

Você pode usar LIB com a opção /DEF para criar uma biblioteca de importação e um arquivo de exportação. Usos LINK de arquivo para criar um programa que contém a exportação exporta (normalmente, uma biblioteca de vínculo dinâmico (DLL)), e ele usa a biblioteca de importação para resolver referências a essas exportações em outros programas.

Observe que se você criar sua biblioteca de importação em uma etapa preliminar, antes de criar seu. dll, você deve passar o mesmo conjunto de arquivos de objeto ao criar o arquivo. dll, conforme passado ao compilar a biblioteca de importação.

Na maioria das situações, você não precisa usar LIB para criar sua biblioteca de importação. Quando você vincula um programa (um arquivo executável ou uma DLL) que contém exportações, o LINK cria automaticamente uma biblioteca de importação que descreve as exportações. Posteriormente, quando você vincula um programa que faz referência a essas exportações, especifique a biblioteca de importação.

No entanto, quando uma DLL exporta para um programa que ele também importa de, se direta ou indiretamente, você deve usar LIB para criar uma das bibliotecas de importação. Quando o LIB cria uma biblioteca de importação, ele também cria um arquivo de exportação. Ao vincular uma das DLLs, você deve usar o arquivo de exportação.

## <a name="see-also"></a>Consulte também

[Referência de LIB](../../build/reference/lib-reference.md)
