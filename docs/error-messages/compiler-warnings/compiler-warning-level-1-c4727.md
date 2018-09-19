---
title: Compilador aviso (nível 1) C4727 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4727
dev_langs:
- C++
helpviewer_keywords:
- C4727
ms.assetid: 991b0087-3a50-40f5-9cdb-cdc367cd472c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b9d169ec9d08f06831370fa68c4049076dbfc582
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46053733"
---
# <a name="compiler-warning-level-1-c4727"></a>Compilador aviso (nível 1) C4727

"O PCH nomeado pch_file com mesmo carimbo de hora encontrado em obj_file_1 e obj_file_2.  Usando primeiro PCH.

C4727 ocorre ao compilar vários compilandos com **/Yc**, e em que o compilador foi capaz de marcar todos os arquivos. obj, com o mesmo carimbo de hora. pch.

Para resolver, compilar um arquivo de origem com **/Yc /c** (cria pch), e os outros separadamente compilar com **/Yu /c** (usa pch), em seguida, vinculá-los.

Portanto, se você tiver feito o seguinte e gera C4727:

**Cl /clr /GL a.cpp b.cpp c.cpp /Ycstdafx.h**

Você faria o seguinte em vez disso:

**Cl /clr /GL a.cpp /Ycstdafx.h /c**

**Cl /clr /GL b.cpp c.cpp /Yustdafx.h /link a.obj**

Para saber mais, veja

- [/Yc (criar arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md)

- [/Yu (usar arquivo de cabeçalho pré-compilado)](../../build/reference/yu-use-precompiled-header-file.md)