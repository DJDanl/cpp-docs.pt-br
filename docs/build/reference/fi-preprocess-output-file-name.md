---
title: /Fi (pré-processar nome do arquivo de saída)
ms.date: 11/04/2016
f1_keywords:
- /Fi
helpviewer_keywords:
- Fi compiler option (C++)
- -Fi compiler option (C++)
- /Fi compiler option (C++)
- preprocessing output files, file name
ms.assetid: 6d0ba983-a8b7-41ec-84f5-b4688ef8efee
ms.openlocfilehash: 02d2a27f0a3d6b6aee6c2cd6f7161c9de718446d
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57414013"
---
# <a name="fi-preprocess-output-file-name"></a>/Fi (pré-processar nome do arquivo de saída)

Especifica o nome do arquivo de saída para o qual o [/P (pré-processar em um arquivo)](../../build/reference/p-preprocess-to-a-file.md) opção de compilador grava a saída pré-processada.

## <a name="syntax"></a>Sintaxe

```
/Fipathname
```

#### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|`pathname`|O nome e caminho do arquivo de saída produzidos pela **/p** opção de compilador.|

## <a name="remarks"></a>Comentários

Use o **/Fi** opção de compilador em combinação com o **/p** opção de compilador.

Se você especificar apenas um caminho para o `pathname` parâmetro, o nome base do arquivo de origem é usado como o nome base do arquivo de saída pré-processado. O `pathname` parâmetro não requer uma extensão de nome de arquivo específico. No entanto, uma extensão de. "i" é usada se você não especificar uma extensão de nome de arquivo.

## <a name="example"></a>Exemplo

A seguinte linha de comando pré-processa PROGRAM.cpp, preservará comentários, adiciona [#line](../../preprocessor/hash-line-directive-c-cpp.md) diretivas e grava o resultado para o arquivo MYPROCESS.i.

```
CL /P /FiMYPROCESS.I PROGRAM.CPP
```

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[/P (pré-processar em um arquivo)](../../build/reference/p-preprocess-to-a-file.md)<br/>
[Especificando o nome de caminho](../../build/reference/specifying-the-pathname.md)
