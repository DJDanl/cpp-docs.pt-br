---
title: Definição de módulo (. Arquivos def) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- def files
- module definition files
- .def files
ms.assetid: 08c0bc28-c5d2-47aa-9624-7fc68bcaa4d8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f04035f3c5f0acd77fc197cbef3d2ab507feb0d4
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45710184"
---
# <a name="module-definition-def-files"></a>Arquivos de definição do módulo (.Def)

Os arquivos de definição de módulo (. def) fornecem o vinculador com informações sobre exportações, atributos e outras informações sobre o programa a ser vinculado. Um arquivo. def é mais útil ao criar uma DLL. Porque há [opções de vinculador](../../build/reference/linker-options.md) que pode ser usado em vez de instruções de definição de módulo, arquivos. def geralmente não são necessários. Você também pode usar [dllexport](../../build/exporting-from-a-dll-using-declspec-dllexport.md) como uma maneira de especificar as funções exportadas.

Você pode invocar um arquivo. def durante a fase de vinculador com o [/DEF (especificar arquivo de definição de módulo)](../../build/reference/def-specify-module-definition-file.md) a opção de vinculador.

Se você estiver criando um arquivo .exe com nenhuma exportação, o uso de um arquivo. def tornará seu carregamento maior e mais lento do arquivo de saída.

Por exemplo, consulte [exportando a partir de uma DLL usando arquivos de DEF](../../build/exporting-from-a-dll-using-def-files.md).

Consulte as seções a seguir para obter mais informações:

- [Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)

- [EXPORTS](../../build/reference/exports.md)

- [HEAPSIZE](../../build/reference/heapsize.md)

- [LIBRARY](../../build/reference/library.md)

- [NOME](../../build/reference/name-c-cpp.md)

- [SEÇÕES](../../build/reference/sections-c-cpp.md)

- [STACKSIZE](../../build/reference/stacksize.md)

- [STUB](../../build/reference/stub.md)

- [VERSÃO](../../build/reference/version-c-cpp.md)

- [Palavras reservadas](../../build/reference/reserved-words.md)

## <a name="see-also"></a>Consulte também

[Referência de build C/C++](../../build/reference/c-cpp-building-reference.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)