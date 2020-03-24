---
title: Aviso do compilador (nível 3) C4278
ms.date: 08/27/2018
f1_keywords:
- C4278
helpviewer_keywords:
- C4278
ms.assetid: 4b6053fb-df62-4c04-b6c8-c011759557b8
ms.openlocfilehash: 7994ae05d6cb16b5ddc9775b1044de7f3a22d542
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80174226"
---
# <a name="compiler-warning-level-3-c4278"></a>Aviso do compilador (nível 3) C4278

> '*Identifier*': o identificador na biblioteca de tipos '*tlb*' já é uma macro; usar o qualificador ' Renomear '

Ao usar [#import](../../preprocessor/hash-import-directive-cpp.md), um identificador no typelib que você está importando está tentando declarar um *identificador*de identificador. No entanto, este já é um símbolo válido.

Use o atributo `#import` **renomeação** para atribuir um alias ao símbolo na biblioteca de tipos.
