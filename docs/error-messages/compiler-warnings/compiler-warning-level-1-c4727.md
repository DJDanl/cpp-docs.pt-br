---
title: Aviso do compilador (nível 1) C4727
ms.date: 08/19/2019
f1_keywords:
- C4727
helpviewer_keywords:
- C4727
ms.assetid: 991b0087-3a50-40f5-9cdb-cdc367cd472c
ms.openlocfilehash: e1eeb7e466e325772d6a1522e77983fd3de04293
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92923964"
---
# <a name="compiler-warning-level-1-c4727"></a>Aviso do compilador (nível 1) C4727

"PCH nomeado pch_file com o mesmo carimbo de data/hora encontrado em obj_file_1 e obj_file_2.  Usando o primeiro PCH.

> [!NOTE]
> No Visual Studio 2017 e anterior, o cabeçalho pré-compilado é chamado de *stdafx. h* por padrão e, no Visual Studio 2019 e posterior, ele é chamado de *PCH. h* por padrão.

C4727 ocorre ao compilar vários compilandos com **/YC** e onde o compilador conseguiu marcar todos os arquivos. obj com o mesmo carimbo de data/hora. pch.

Para resolver, compile um arquivo de origem com **/Yc/c** (cria pch) e os outros compilam separadamente com **/Yu/c** (usa pch) e vincule-os juntos.

Portanto, se você fez o seguinte e gera C4727:

::: moniker range="<=msvc-150"

**CL/CLR/GL a. cpp b. cpp c. cpp/Ycstdafx.h**

Em vez disso, você faria o seguinte:

**CL/CLR/GL a. cpp/Ycstdafx.h/c**

**CL/CLR/GL b. cpp c. cpp/Yustdafx.h/link a. obj**

::: moniker-end

::: moniker range=">=msvc-160"

**CL/CLR/GL a. cpp b. cpp c. cpp/Ycpch.h**

Em vez disso, você faria o seguinte:

**CL/CLR/GL a. cpp/Ycpch.h/c**

**CL/CLR/GL b. cpp c. cpp/Yupch.h/link a. obj**

::: moniker-end

Para obter mais informações, consulte

- [/Yc (criar arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md)

- [/Yu (usar arquivo de cabeçalho pré-compilado)](../../build/reference/yu-use-precompiled-header-file.md)
