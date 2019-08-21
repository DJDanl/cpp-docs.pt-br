---
title: Aviso do compilador (nível 1) C4727
ms.date: 08/19/2019
f1_keywords:
- C4727
helpviewer_keywords:
- C4727
ms.assetid: 991b0087-3a50-40f5-9cdb-cdc367cd472c
ms.openlocfilehash: 1bcc029536d2602d50178d7148332b8371db3c7f
ms.sourcegitcommit: 9d4ffb8e6e0d70520a1e1a77805785878d445b8a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/20/2019
ms.locfileid: "69630826"
---
# <a name="compiler-warning-level-1-c4727"></a>Aviso do compilador (nível 1) C4727

"PCH nomeado pch_file com o mesmo carimbo de data/hora encontrado em obj_file_1 e obj_file_2.  Usando o primeiro PCH.

> [!NOTE]
> No Visual Studio 2017 e anterior, o cabeçalho pré-compilado é chamado de *stdafx. h* por padrão e, no Visual Studio 2019 e posterior, ele é chamado de *PCH. h* por padrão.

C4727 ocorre ao compilar vários compilandos com **/YC**e onde o compilador conseguiu marcar todos os arquivos. obj com o mesmo carimbo de data/hora. pch.

Para resolver, compile um arquivo de origem com **/Yc/c** (cria pch) e os outros compilam separadamente com **/Yu/c** (usa pch) e vincule-os juntos.

Portanto, se você fez o seguinte e gera C4727:

::: moniker range="<=vs-2017"

**cl /clr /GL a.cpp b.cpp c.cpp /Ycstdafx.h**

Em vez disso, você faria o seguinte:

**cl /clr /GL a.cpp /Ycstdafx.h /c**

**CL/CLR/GL b. cpp c. cpp/Yustdafx.h/link a. obj**

::: moniker-end

::: moniker range=">=vs-2019"

**CL/CLR/GL a. cpp b. cpp c. cpp/Ycpch.h**

Em vez disso, você faria o seguinte:

**CL/CLR/GL a. cpp/Ycpch.h/c**

**CL/CLR/GL b. cpp c. cpp/Yupch.h/link a. obj**

::: moniker-end


Para saber mais, veja

- [/Yc (criar arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md)

- [/Yu (usar arquivo de cabeçalho pré-compilado)](../../build/reference/yu-use-precompiled-header-file.md)