---
title: Exportando funções a partir de uma DLL por ordinal e não por nome
ms.date: 11/04/2016
helpviewer_keywords:
- exporting functions [C++], ordinal values
- ordinal exports [C++]
- exporting DLLs [C++], ordinal values
- NONAME attribute
ms.assetid: 679719fd-d965-4df3-9f7a-7d86ad831702
ms.openlocfilehash: 3229c98a0a6bbb0ebc4fa0ef055e4019bd6c7bd8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229812"
---
# <a name="exporting-functions-from-a-dll-by-ordinal-rather-than-by-name"></a>Exportando funções a partir de uma DLL por ordinal e não por nome

A maneira mais simples de exportar funções de sua DLL é exportá-las por nome. Isso é o que acontece quando você usa **`__declspec(dllexport)`** , por exemplo. Mas, em vez disso, você pode exportar funções por ordinal. Com essa técnica, você deve usar um arquivo. def em vez de **`__declspec(dllexport)`** . Para especificar o valor ordinal de uma função, acrescente seu ordinal ao nome da função no arquivo. def. Para obter informações sobre como especificar ordinais, consulte [exportando de uma DLL usando arquivos. def](exporting-from-a-dll-using-def-files.md).

> [!TIP]
> Se você quiser otimizar o tamanho do arquivo de sua DLL, use o atributo **NoName** em cada função exportada. Com o atributo **NoName** , os ordinais são armazenados na tabela de exportação da dll em vez dos nomes de função. Isso pode ser uma economia considerável se você estiver exportando muitas funções.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Usar um arquivo. def para que eu possa exportar por ordinal](exporting-from-a-dll-using-def-files.md)

- [Usar __declspec (dllexport)](exporting-from-a-dll-using-declspec-dllexport.md)

## <a name="see-also"></a>Confira também

[Exportando a partir de uma DLL](exporting-from-a-dll.md)
