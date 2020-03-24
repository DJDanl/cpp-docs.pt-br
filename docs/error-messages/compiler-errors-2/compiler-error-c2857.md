---
title: Erro do compilador C2857
ms.date: 09/13/2018
f1_keywords:
- C2857
helpviewer_keywords:
- C2857
ms.assetid: b57302bd-58ec-45ae-992a-1e282d5eeccc
ms.openlocfilehash: 11b620f9748ac85e731d79b0652c0392375b2ea4
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80201845"
---
# <a name="compiler-error-c2857"></a>Erro do compilador C2857

> a instrução ' #include ' especificada com a opção de linha de comando/YC*filename* não foi encontrada no arquivo de origem

A opção [/YC](../../build/reference/yc-create-precompiled-header-file.md) especifica o nome de um arquivo de inclusão que não está incluído no arquivo de origem que está sendo compilado.

## <a name="remarks"></a>Comentários

Quando você usa a opção **/YC**<em>filename</em> em um arquivo de origem para criar um arquivo de cabeçalho pré-compilado (PCH), esse arquivo de origem deve incluir o arquivo de cabeçalho *filename* . Cada arquivo incluído no arquivo de origem, até e incluindo o *nome*de arquivo especificado, é incluído no arquivo PCH. Em outros arquivos de origem compilados usando a opção **/Yu**<em>filename</em> para usar o arquivo PCH, uma inclusão de *filename* deve ser a primeira linha que não seja de comentário no arquivo. O compilador ignora qualquer coisa no arquivo de origem antes que isso seja incluído.

Esse erro pode ser causado por uma instrução `#include "filename"` em um bloco de compilação condicional que não é compilado em seu arquivo de origem PCH.

## <a name="example"></a>Exemplo

No uso típico, um arquivo de origem em seu projeto é designado como o arquivo de origem PCH e um arquivo de cabeçalho é usado como o arquivo de cabeçalho PCH. Um arquivo de cabeçalho PCH típico tem todos os cabeçalhos de biblioteca usados em seu projeto, mas não os cabeçalhos locais que ainda estão em desenvolvimento. Neste exemplo, o arquivo de cabeçalho PCH é chamado de *my_pch. h*.

```cpp
// my_pch.h
#pragma once
#include <stdio.h>
```

O arquivo de origem PCH é compilado usando a opção **/Yc**<em>my_pch. h</em> . Se o compilador não encontrar uma inclusão desse arquivo de cabeçalho PCH, ele gerará C2857:

```cpp
// my_pch.cpp
// Compile by using: cl /EHsc /W4 /Yumy_pch.h /c my_pch.cpp

#if 0
#include "my_pch.h"  // C2857; remove conditional directives to fix
#endif
```

Para usar esse arquivo PCH, os arquivos de origem devem ser compilados usando a opção **/Yu**<em>my_pch. h</em> . O arquivo de cabeçalho PCH deve ser incluído primeiro em arquivos de origem que usam o PCH:

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
