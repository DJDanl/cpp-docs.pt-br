---
title: Arquivos de definição do módulo (.Def)
ms.date: 11/04/2016
helpviewer_keywords:
- def files
- module definition files
- .def files
ms.assetid: 08c0bc28-c5d2-47aa-9624-7fc68bcaa4d8
ms.openlocfilehash: 0047f24722644cd9a68bbbf827ced26ad085d4c1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62321215"
---
# <a name="module-definition-def-files"></a>Arquivos de definição do módulo (.Def)

Os arquivos de definição de módulo (. def) fornecem o vinculador com informações sobre exportações, atributos e outras informações sobre o programa a ser vinculado. Um arquivo. def é mais útil ao criar uma DLL. Porque há [opções do vinculador MSVC](linker-options.md) que pode ser usado em vez de instruções de definição de módulo, arquivos. def geralmente não são necessários. Você também pode usar [dllexport](../exporting-from-a-dll-using-declspec-dllexport.md) como uma maneira de especificar as funções exportadas.

Você pode invocar um arquivo. def durante a fase de vinculador com o [/DEF (especificar arquivo de definição de módulo)](def-specify-module-definition-file.md) a opção de vinculador.

Se você estiver criando um arquivo .exe com nenhuma exportação, o uso de um arquivo. def tornará seu carregamento maior e mais lento do arquivo de saída.

Por exemplo, consulte [exportando a partir de uma DLL usando arquivos de DEF](../exporting-from-a-dll-using-def-files.md).

Consulte as seções a seguir para obter mais informações:

- [Regras para instruções de definição do módulo](rules-for-module-definition-statements.md)

- [EXPORTS](exports.md)

- [HEAPSIZE](heapsize.md)

- [LIBRARY](library.md)

- [NOME](name-c-cpp.md)

- [SEÇÕES](sections-c-cpp.md)

- [STACKSIZE](stacksize.md)

- [STUB](stub.md)

- [VERSION](version-c-cpp.md)

- [Palavras reservadas](reserved-words.md)

## <a name="see-also"></a>Consulte também

[Referência de build C/C++](c-cpp-building-reference.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
