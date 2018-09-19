---
title: Erro fatal C1067 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1067
dev_langs:
- C++
helpviewer_keywords:
- C1067
ms.assetid: e2c94be6-4573-4571-aac9-73d657fe9f96
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f267e58617fbc68835fd3a387c4b635de4fd0530
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46077666"
---
# <a name="fatal-error-c1067"></a>Erro fatal C1067

limite do compilador: limite de 64 mil em tamanho de um registro de tipo foi excedido

Esse erro pode ocorrer se um símbolo tiver um nome decorado excedendo 247 caracteres.  Para resolver, encurte o nome do símbolo.

Quando o compilador gera informações de depuração, ele emite os registros do tipo para definir tipos encontrados no código-fonte.  Por exemplo, registros de tipo incluem estruturas simples e listas de argumentos de funções.  Alguns desses registros do tipo podem ser listas grandes.

Há um limite de 64K no tamanho de qualquer tipo de registro.  Se esse limite de 64K for excedido, em seguida, esse erro ocorrerá.

C1067 também pode ocorrer se houver vários símbolos com nomes longos ou se uma classe, struct ou união tem muitos membros.