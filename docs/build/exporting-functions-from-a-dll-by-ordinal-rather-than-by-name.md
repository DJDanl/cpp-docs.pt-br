---
title: Exportando funções a partir de uma DLL por ordinal e não por nome
ms.date: 11/04/2016
helpviewer_keywords:
- exporting functions [C++], ordinal values
- ordinal exports [C++]
- exporting DLLs [C++], ordinal values
- NONAME attribute
ms.assetid: 679719fd-d965-4df3-9f7a-7d86ad831702
ms.openlocfilehash: 66e99b18d181e9067e90398c35a61db2da66c301
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328581"
---
# <a name="exporting-functions-from-a-dll-by-ordinal-rather-than-by-name"></a>Exportando funções a partir de uma DLL por ordinal e não por nome

A maneira mais simples de exportar funções do seu DLL é exportá-las pelo nome. Isso é o que acontece quando você usa **__declspec(dllexport)**, por exemplo. Mas você pode, em vez disso, exportar funções por ordinal. Com esta técnica, você deve usar um arquivo .def em vez de **__declspec(dllexport)**. Para especificar o valor ordinal de uma função, aprová-lo ordinal ao nome da função no arquivo .def. Para obter informações sobre como especificar ordinals, consulte [Exportando a partir de um DLL Usando .def Files](exporting-from-a-dll-using-def-files.md).

> [!TIP]
> Se você quiser otimizar o tamanho do arquivo do seu DLL, use o atributo **NONAME** em cada função exportada. Com o atributo **NONAME,** as ordinais são armazenadas na tabela de exportação da DLL em vez dos nomes da função. Isso pode ser uma economia considerável se você estiver exportando muitas funções.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Use um arquivo .def para que eu possa exportar por ordinal](exporting-from-a-dll-using-def-files.md)

- [Use __declspec(dllexport)](exporting-from-a-dll-using-declspec-dllexport.md)

## <a name="see-also"></a>Confira também

[Exportando a partir de uma DLL](exporting-from-a-dll.md)
