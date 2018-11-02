---
title: Erro fatal C1067
ms.date: 11/04/2016
f1_keywords:
- C1067
helpviewer_keywords:
- C1067
ms.assetid: e2c94be6-4573-4571-aac9-73d657fe9f96
ms.openlocfilehash: f8fe301e25d9ecb5cc67397f9537e0bbd86c0627
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50595618"
---
# <a name="fatal-error-c1067"></a>Erro fatal C1067

limite do compilador: limite de 64 mil em tamanho de um registro de tipo foi excedido

Esse erro pode ocorrer se um símbolo tiver um nome decorado excedendo 247 caracteres.  Para resolver, encurte o nome do símbolo.

Quando o compilador gera informações de depuração, ele emite os registros do tipo para definir tipos encontrados no código-fonte.  Por exemplo, registros de tipo incluem estruturas simples e listas de argumentos de funções.  Alguns desses registros do tipo podem ser listas grandes.

Há um limite de 64K no tamanho de qualquer tipo de registro.  Se esse limite de 64K for excedido, em seguida, esse erro ocorrerá.

C1067 também pode ocorrer se houver vários símbolos com nomes longos ou se uma classe, struct ou união tem muitos membros.