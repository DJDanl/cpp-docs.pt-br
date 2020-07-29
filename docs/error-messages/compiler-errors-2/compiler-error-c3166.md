---
title: Erro do compilador C3166
ms.date: 11/04/2016
f1_keywords:
- C3166
helpviewer_keywords:
- C3166
ms.assetid: ec3e330d-c15d-4158-8268-09101486c566
ms.openlocfilehash: 1915d58f73ce8d16135951b359c3f0fd48aea3ac
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230864"
---
# <a name="compiler-error-c3166"></a>Erro do compilador C3166

> ' pointer ': não é possível declarar um ponteiro para um ponteiro de __gc interior como membro de ' type '

O compilador encontrou uma declaração de ponteiro inválida (um **`__nogc`** ponteiro para um **`__gc`** ponteiro.).

C3166 só pode ser acessado usando a opção de compilador obsoleto **`/clr:oldSyntax`** .
