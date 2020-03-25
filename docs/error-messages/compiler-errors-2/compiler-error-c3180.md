---
title: Erro do compilador C3180
ms.date: 11/04/2016
f1_keywords:
- C3180
helpviewer_keywords:
- C3180
ms.assetid: 5281f583-7df7-418a-8507-d4da67ed6572
ms.openlocfilehash: c94019bf7a58492fcbb27c4f092a6e5f7e36ca25
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80176449"
---
# <a name="compiler-error-c3180"></a>Erro do compilador C3180

' nome do tipo ': o nome excede o limite de metadados de ' limit ' caracteres

O compilador trunca o nome de um tipo gerenciado em metadados. O truncamento tornará o tipo inutilizável com a diretiva `#using` (ou o equivalente em outra linguagem).

O limite de nome de tipo inclui quaisquer qualificações de namespace.
