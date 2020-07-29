---
title: Erro do compilador C2696
ms.date: 11/04/2016
f1_keywords:
- C2696
helpviewer_keywords:
- C2696
ms.assetid: 6c6eb7df-1230-4346-9a73-abf14c20785d
ms.openlocfilehash: f6af217dbcd871ac4edd1852042144802388545b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216083"
---
# <a name="compiler-error-c2696"></a>Erro do compilador C2696

Não é possível criar um objeto temporário de um tipo gerenciado ' type '

Referências a **`const`** em um programa não gerenciado fazem com que o compilador chame o construtor e crie um objeto temporário na pilha. No entanto, uma classe gerenciada nunca pode ser criada na pilha.

C2696 só é acessível usando a opção de compilador obsoleto **/CLR: oldSyntax**.
