---
title: Arquivos de definição do módulo (.Def)
ms.date: 11/04/2016
helpviewer_keywords:
- def files
- module definition files
- .def files
ms.assetid: 08c0bc28-c5d2-47aa-9624-7fc68bcaa4d8
ms.openlocfilehash: 041894fa88527061d90399540bc29762bff66f81
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57424529"
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

- [VERSION](../../build/reference/version-c-cpp.md)

- [Palavras reservadas](../../build/reference/reserved-words.md)

## <a name="see-also"></a>Consulte também

[Referência de build C/C++](../../build/reference/c-cpp-building-reference.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)
