---
title: Sintaxe da linha de comando do compilador MSVC
ms.date: 11/04/2016
helpviewer_keywords:
- syntax, CL compiler command line
- cl.exe compiler, command-line syntax
ms.assetid: acba2c1c-0803-4a3a-af25-63e849b930a2
ms.openlocfilehash: 6a56474b537d78a3d0bea8a74d9082007cd2e295
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320540"
---
# <a name="compiler-command-line-syntax"></a>Sintaxe da linha de comando do compilador

A linha de comando CL usa a seguinte sintaxe:

```
CL [option...] file... [option | file]... [lib...] [@command-file] [/link link-opt...]
```

A tabela a seguir descreve a entrada no comando CL.

|Entrada|Significado|
|-----------|-------------|
|*opção*|Uma ou mais [opções de CL.](compiler-options.md) Observe que todas as opções se aplicam a todos os arquivos de origem especificados. As opções são especificadas por uma barra para frente (/) ou um traço (-). Se uma opção tiver um argumento, a descrição da opção documenta se um espaço é permitido entre a opção e os argumentos. Os nomes das opções (exceto a opção /HELP) são sensíveis a maiúsculas e minúsculas. Consulte [Order of CL Options](order-of-cl-options.md) para obter mais informações.|
|`file`|O nome de um ou mais arquivos de origem, arquivos .obj ou bibliotecas. Cl compila arquivos de origem e passa os nomes dos arquivos .obj e bibliotecas para o linker. Consulte [cl filename sintax e](cl-filename-syntax.md) obter mais informações.|
|*Lib*|Um ou mais nomes de biblioteca. Cl passa esses nomes para o linker.|
|*arquivo de comando*|Um arquivo que contém várias opções e nomes de arquivos. Consulte [cl command files](cl-command-files.md) para obter mais informações.|
|*opção de link*|Uma ou mais [opções de Linker MSVC](linker-options.md). Cl passa essas opções para o linker.|

Você pode especificar qualquer número de opções, nomes de arquivos e nomes de biblioteca, desde que o número de caracteres na linha de comando não exceda 1024, o limite ditado pelo sistema operacional.

Para obter informações sobre o valor de retorno de cl.exe, consulte [Valor de Retorno de cl.exe](return-value-of-cl-exe.md) .

> [!NOTE]
> O limite de entrada da linha de comando de 1024 caracteres não é garantido para permanecer o mesmo em versões futuras do Windows.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)
