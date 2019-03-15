---
title: Sintaxe de linha de comando do compilador MSVC
ms.date: 11/04/2016
helpviewer_keywords:
- syntax, CL compiler command line
- cl.exe compiler, command-line syntax
ms.assetid: acba2c1c-0803-4a3a-af25-63e849b930a2
ms.openlocfilehash: 5cee76d5c053dbcfef33a191dc38a958338e4a82
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57821481"
---
# <a name="compiler-command-line-syntax"></a>Sintaxe da linha de comando do compilador

A linha de comando CL usa a seguinte sintaxe:

```
CL [option...] file... [option | file]... [lib...] [@command-file] [/link link-opt...]
```

A tabela a seguir descreve a entrada para o comando CL.

|Entrada|Significado|
|-----------|-------------|
|*option*|Um ou mais [opções CL](compiler-options.md). Observe que todas as opções se aplicam a todos os arquivos de origem especificado. As opções são especificadas por uma barra (/) ou um traço (-). Se uma opção usa um argumento, documentos de descrição da opção, se um espaço é permitido entre a opção e os argumentos. Nomes de opção (exceto para a opção /HELP) diferenciam maiusculas de minúsculas. Ver [ordem de opções CL](order-of-cl-options.md) para obter mais informações.|
|`file`|O nome de um ou mais arquivos de origem, arquivos. obj ou bibliotecas. CL compila arquivos de origem e passa os nomes dos arquivos. obj e bibliotecas para o vinculador. Ver [sintaxe de nome de arquivo CL](cl-filename-syntax.md) para obter mais informações.|
|*lib*|Um ou mais nomes de biblioteca. CL passa esses nomes para o vinculador.|
|*command-file*|Um arquivo que contém várias opções e nomes de arquivo. Ver [arquivos de comando CL](cl-command-files.md) para obter mais informações.|
|*link-opt*|Um ou mais [opções do vinculador MSVC](linker-options.md). CL passa essas opções para o vinculador.|

Você pode especificar qualquer número de opções, nomes de arquivo e nomes de biblioteca, desde que o número de caracteres na linha de comando não excede 1024, o limite determinado pelo sistema operacional.

Para obter informações sobre o valor de retorno cl.exe, consulte [retornam o valor de cl.exe](return-value-of-cl-exe.md) .

> [!NOTE]
>  Não é garantido que o limite de entrada de linha de comando de 1024 caracteres permanecem os mesmos nas versões futuras do Windows.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)
