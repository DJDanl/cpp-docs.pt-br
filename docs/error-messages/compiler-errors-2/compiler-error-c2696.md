---
title: Erro do compilador C2696
ms.date: 11/04/2016
f1_keywords:
- C2696
helpviewer_keywords:
- C2696
ms.assetid: 6c6eb7df-1230-4346-9a73-abf14c20785d
ms.openlocfilehash: 340a5d0596160b6c9c7bcfc78aed812f8c5f3fa3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50562858"
---
# <a name="compiler-error-c2696"></a>Erro do compilador C2696

Não é possível criar um objeto temporário de um tipo gerenciado 'type'

As referências a `const` em um programa não gerenciado, com que o compilador chama o construtor e criar um objeto temporário na pilha. No entanto, uma classe gerenciada nunca pode ser criada na pilha.

C2696 só está acessível usando a opção de compilador obsoletos **/CLR: oldSyntax**.
