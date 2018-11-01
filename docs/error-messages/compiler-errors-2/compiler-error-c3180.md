---
title: Erro do compilador C3180
ms.date: 11/04/2016
f1_keywords:
- C3180
helpviewer_keywords:
- C3180
ms.assetid: 5281f583-7df7-418a-8507-d4da67ed6572
ms.openlocfilehash: bfe2699ce448aa879f0c93aa431a17dbc1334274
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50662027"
---
# <a name="compiler-error-c3180"></a>Erro do compilador C3180

'type name': nome excede o limite de metadados de caracteres 'limit'

O compilador truncado o nome de um tipo gerenciado nos metadados. O truncamento será inutilizar o tipo com o `#using` diretiva (ou o equivalente em outro idioma).

O limite de nome de tipo inclui qualquer as qualificações do namespace.