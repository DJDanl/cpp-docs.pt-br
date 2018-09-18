---
title: Erro do compilador C2856 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2856
dev_langs:
- C++
helpviewer_keywords:
- C2856
ms.assetid: fe616c51-124e-49e3-9dd8-883ec1660680
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: df6226bfd2fc11f05f894091f4ff02c145d09e11
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46072700"
---
# <a name="compiler-error-c2856"></a>Erro do compilador C2856

\#pragma hdrstop não pode ser dentro de um bloco #if

O `hdrstop` pragma não pode ser colocado dentro do corpo de um bloco de compilação condicional.

Mover o `#pragma hdrstop` instrução para uma área que não está contida em um `#if/#endif` bloco.