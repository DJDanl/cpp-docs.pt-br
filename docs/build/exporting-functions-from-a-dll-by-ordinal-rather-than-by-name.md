---
title: Exportando funções de uma DLL por Ordinal em vez de por nome | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
f1_keywords:
- NONAME
dev_langs:
- C++
helpviewer_keywords:
- exporting functions [C++], ordinal values
- ordinal exports [C++]
- exporting DLLs [C++], ordinal values
- NONAME attribute
ms.assetid: 679719fd-d965-4df3-9f7a-7d86ad831702
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2d894df971dd0c50556a420eafa2909474ee6912
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45714253"
---
# <a name="exporting-functions-from-a-dll-by-ordinal-rather-than-by-name"></a>Exportando funções a partir de uma DLL por ordinal e não por nome

É a maneira mais simples para exportar funções de DLL para exportá-los por nome. Isso é o que acontece quando você usa **dllexport**, por exemplo. Mas, em vez disso, você pode exportar funções por ordinal. Com essa técnica, você deve usar um arquivo. def, em vez de **dllexport**. Para especificar o valor ordinal de uma função, anexe seu ordinal para o nome da função no arquivo. def. Para obter informações sobre como especificar ordinais, consulte [exportando de uma DLL usando arquivos. def](../build/exporting-from-a-dll-using-def-files.md).

> [!TIP]
>  Se você deseja otimizar o tamanho do arquivo da sua DLL, use o **NONAME** atributo em cada função exportada. Com o **NONAME** atributo, os ordinais são armazenados em DLL exporta tabela, em vez dos nomes de função. Se você estiver exportando muitas funções, isso pode ser uma economia considerável.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Usar um arquivo. def, portanto, posso exportar por ordinal](../build/exporting-from-a-dll-using-def-files.md)

- [Usar dllexport](../build/exporting-from-a-dll-using-declspec-dllexport.md)

## <a name="see-also"></a>Consulte também

[Exportando de uma DLL](../build/exporting-from-a-dll.md)