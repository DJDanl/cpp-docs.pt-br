---
title: Sintaxe de linha de comando do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- syntax, CL compiler command line
- cl.exe compiler, command-line syntax
ms.assetid: acba2c1c-0803-4a3a-af25-63e849b930a2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 18fb22ba370a447be8cb4cb2fb96633d702a1089
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45710294"
---
# <a name="compiler-command-line-syntax"></a>Sintaxe da linha de comando do compilador

A linha de comando CL usa a seguinte sintaxe:

```
CL [option...] file... [option | file]... [lib...] [@command-file] [/link link-opt...]
```

A tabela a seguir descreve a entrada para o comando CL.

|Entrada|Significado|
|-----------|-------------|
|*Opção*|Um ou mais [opções CL](../../build/reference/compiler-options.md). Observe que todas as opções se aplicam a todos os arquivos de origem especificado. As opções são especificadas por uma barra (/) ou um traço (-). Se uma opção usa um argumento, documentos de descrição da opção, se um espaço é permitido entre a opção e os argumentos. Nomes de opção (exceto para a opção /HELP) diferenciam maiusculas de minúsculas. Ver [ordem de opções CL](../../build/reference/order-of-cl-options.md) para obter mais informações.|
|`file`|O nome de um ou mais arquivos de origem, arquivos. obj ou bibliotecas. CL compila arquivos de origem e passa os nomes dos arquivos. obj e bibliotecas para o vinculador. Ver [sintaxe de nome de arquivo CL](../../build/reference/cl-filename-syntax.md) para obter mais informações.|
|*lib*|Um ou mais nomes de biblioteca. CL passa esses nomes para o vinculador.|
|*arquivo de comando*|Um arquivo que contém várias opções e nomes de arquivo. Ver [arquivos de comando CL](../../build/reference/cl-command-files.md) para obter mais informações.|
|*link-opt*|Um ou mais [opções de vinculador](../../build/reference/linker-options.md). CL passa essas opções para o vinculador.|

Você pode especificar qualquer número de opções, nomes de arquivo e nomes de biblioteca, desde que o número de caracteres na linha de comando não excede 1024, o limite determinado pelo sistema operacional.

Para obter informações sobre o valor de retorno cl.exe, consulte [retornam o valor de cl.exe](../../build/reference/return-value-of-cl-exe.md) .

> [!NOTE]
>  Não é garantido que o limite de entrada de linha de comando de 1024 caracteres permanecem os mesmos nas versões futuras do Windows.

## <a name="see-also"></a>Consulte também

[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[Opções do Compilador](../../build/reference/compiler-options.md)