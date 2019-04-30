---
title: Compilador aviso (nível 3) C4278
ms.date: 08/27/2018
f1_keywords:
- C4278
helpviewer_keywords:
- C4278
ms.assetid: 4b6053fb-df62-4c04-b6c8-c011759557b8
ms.openlocfilehash: 8c5c15105581602566116d3ed82b89a6337435c9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62402158"
---
# <a name="compiler-warning-level-3-c4278"></a>Compilador aviso (nível 3) C4278

> '*identificador*': identificador em biblioteca de tipos '*tlb*' já é uma macro; use o qualificador 'rename'

Ao usar [#import](../../preprocessor/hash-import-directive-cpp.md), um identificador em typelib que está sendo importado está tentando declarar um identificador *identificador*. No entanto, isso já é um símbolo válido.

Use o `#import` **Renomear** atributo para atribuir um alias para o símbolo na biblioteca de tipos.