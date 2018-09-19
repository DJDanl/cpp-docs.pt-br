---
title: Subtração do ponteiro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- pointer subtraction
ms.assetid: 4d515690-088a-43f6-bb8c-57b849f7ccf7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9756861fd1204a05179ac77dfa648822ed83e5a3
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46079525"
---
# <a name="pointer-subtraction"></a>Subtração do ponteiro

**ANSI 3.3.6, 4.1.1** O tipo de inteiro necessário para manter a diferença entre dois ponteiros em relação aos elementos da mesma matriz, **ptrdiff_t**

O typedef `ptrdiff_t` é `int` na plataforma x86 de 32 bits. Em plataformas de 64 bits, o typedef `ptrdiff_t` é um `__int64`.

## <a name="see-also"></a>Consulte também

[Matrizes e ponteiros](../c-language/arrays-and-pointers.md)
