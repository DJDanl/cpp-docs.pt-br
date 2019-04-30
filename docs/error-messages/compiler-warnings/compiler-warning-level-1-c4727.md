---
title: Compilador aviso (nível 1) C4727
ms.date: 11/04/2016
f1_keywords:
- C4727
helpviewer_keywords:
- C4727
ms.assetid: 991b0087-3a50-40f5-9cdb-cdc367cd472c
ms.openlocfilehash: be1a248fc2709706e137b543344966735c19064e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386428"
---
# <a name="compiler-warning-level-1-c4727"></a>Compilador aviso (nível 1) C4727

"O PCH nomeado pch_file com mesmo carimbo de hora encontrado em obj_file_1 e obj_file_2.  Usando primeiro PCH.

C4727 ocorre ao compilar vários compilandos com **/Yc**, e em que o compilador foi capaz de marcar todos os arquivos. obj, com o mesmo carimbo de hora. pch.

Para resolver, compilar um arquivo de origem com **/Yc /c** (cria pch), e os outros separadamente compilar com **/Yu /c** (usa pch), em seguida, vinculá-los.

Portanto, se você tiver feito o seguinte e gera C4727:

**cl /clr /GL a.cpp b.cpp c.cpp /Ycstdafx.h**

Você faria o seguinte em vez disso:

**cl /clr /GL a.cpp /Ycstdafx.h /c**

**Cl /clr /GL b.cpp c.cpp /Yustdafx.h /link a.obj**

Para saber mais, veja

- [/Yc (criar arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md)

- [/Yu (usar arquivo de cabeçalho pré-compilado)](../../build/reference/yu-use-precompiled-header-file.md)