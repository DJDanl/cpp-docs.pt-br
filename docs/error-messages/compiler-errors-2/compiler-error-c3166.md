---
title: Erro do compilador C3166
ms.date: 11/04/2016
f1_keywords:
- C3166
helpviewer_keywords:
- C3166
ms.assetid: ec3e330d-c15d-4158-8268-09101486c566
ms.openlocfilehash: 17efd401314e93ff710be2c1e6f187a938e388b9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62174297"
---
# <a name="compiler-error-c3166"></a>Erro do compilador C3166

'ponteiro': não é possível declarar um ponteiro para um ponteiro interior GC como um membro de 'type'

O compilador encontrou uma declaração de ponteiro inválido (um `__nogc` ponteiro para um `__gc` ponteiro.).

C3166 só está acessível usando a opção de compilador obsoletos **/CLR: oldSyntax**.
