---
title: Arquivo de comando BSCMAKE (arquivo de resposta)
ms.date: 11/04/2016
helpviewer_keywords:
- BSCMAKE, response file
- BSCMAKE, command file
- response files, BSCMAKE
- command files, BSCMAKE
- response files
- command files
ms.assetid: abdffeea-35c7-4f2d-8c17-7d0d80bac314
ms.openlocfilehash: 6a55fd616a00aeb3ade229bf7cff8220f86085b7
ms.sourcegitcommit: 06fc71a46e3c4f6202a1c0bc604aa40611f50d36
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/27/2019
ms.locfileid: "58508813"
---
# <a name="bscmake-command-file-response-file"></a>Arquivo de comando BSCMAKE (arquivo de resposta)

> [!WARNING]
> Embora BSCMAKE ainda está instalado com o Visual Studio, ele não é mais usado pelo IDE. Desde o Visual Studio 2008, as informações de símbolo e procura são armazenadas automaticamente em um arquivo. sdf de SQL Server na pasta da solução.

Você pode fornecer parte ou toda a entrada de linha de comando em um arquivo de comando. Especifique o arquivo de comando usando a seguinte sintaxe:

```
BSCMAKE @filename
```

Arquivo de comando somente uma é permitido. Você pode especificar um caminho com *filename*. Preceder *filename* com um sinal de arroba (**\@**). BSCMAKE não assume uma extensão. Você pode especificar adicionais *sbrfiles* na linha de comando após *filename*. O arquivo de comando é um arquivo de texto que contém a entrada para BSCMAKE na mesma ordem conforme você especificaria na linha de comando. Separe os argumentos de linha de comando com um ou mais espaços, tabulações ou caracteres de nova linha.

O comando a seguir chama BSCMAKE usando um arquivo de comando:

```
BSCMAKE @prog1.txt
```

Este é um arquivo de comando de exemplo:

```
/n /v /o main.bsc /El
/S (
toolbox.h
verdate.h c:\src\inc\screen.h
)
file1.sbr file2.sbr file3.sbr file4.sbr
```

## <a name="see-also"></a>Consulte também

[Referência de BSCMAKE](bscmake-reference.md)
