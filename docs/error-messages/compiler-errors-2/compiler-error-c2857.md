---
title: Erro do compilador C2857
ms.date: 09/13/2018
f1_keywords:
- C2857
helpviewer_keywords:
- C2857
ms.assetid: b57302bd-58ec-45ae-992a-1e282d5eeccc
ms.openlocfilehash: 10c0ea3b54ded29bf80f83713cea33428dca6ca0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50432145"
---
# <a name="compiler-error-c2857"></a>Erro do compilador C2857

> ' #include ' instrução especificada com o /Yc*filename* opção de linha de comando não foi encontrada no arquivo de origem

O [/Yc](../../build/reference/yc-create-precompiled-header-file.md) opção especifica o nome de um arquivo de inclusão não está incluído no arquivo de origem que está sendo compilado.

## <a name="remarks"></a>Comentários

Quando você usa o **/Yc**<em>filename</em> opção em um arquivo de origem para criar um arquivo de cabeçalho pré-compilado (PCH), que o arquivo de origem deve incluir o *filename* arquivo de cabeçalho. Todos os arquivos incluídos pelo arquivo de origem, até e incluindo especificado *filename*, está incluído no arquivo PCH. Em outros arquivos de origem compilados usando o **/Yu**<em>filename</em> opção para usar o PCH de arquivo, uma inclusão de *filename* deve ser a primeira linha não seja de comentários no arquivo. O compilador ignora qualquer coisa no arquivo de origem antes dessa inclusão.

Esse erro pode ser causado por um `#include "filename"` instrução em um bloco de compilação condicional não é compilado em seu arquivo de origem PCH.

## <a name="example"></a>Exemplo

No uso normal, um arquivo de origem em seu projeto é designado como o arquivo de origem PCH, e um arquivo de cabeçalho é usado como o arquivo de cabeçalho PCH. Um arquivo de cabeçalho PCH típico tem todos os cabeçalhos da biblioteca usados em seu projeto, mas cabeçalhos não locais que ainda estão em desenvolvimento. Neste exemplo, o arquivo de cabeçalho PCH é denominado *my_pch.h*.

```cpp
// my_pch.h
#pragma once
#include <stdio.h>
```

O arquivo de origem PCH é compilado usando o **/Yc**<em>my_pch.h</em> opção. Se o compilador não encontra uma inclusão desse arquivo de cabeçalho PCH, ele gera C2857:

```cpp
// my_pch.cpp
// Compile by using: cl /EHsc /W4 /Yumy_pch.h /c my_pch.cpp

#if 0
#include "my_pch.h"  // C2857; remove conditional directives to fix
#endif
```

Para usar esse arquivo PCH, os arquivos de origem devem ser compilados usando o **/Yu**<em>my_pch.h</em> opção. O arquivo de cabeçalho PCH deve ser incluído pela primeira vez em arquivos de origem que usam o PCH:

```cpp
// C2857.cpp
// Compile my_pch.cpp first, then
// compile by using: cl /EHsc /W4 /Yumy_pch.h my_project.cpp my_pch.obj
// Include the pch header before any other non-comment line
#include "my_pch.h"

int main()
{
    puts("Using a precompiled header file.\n");
}
```