---
title: Compilador aviso (nível 1) C4041 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4041
dev_langs:
- C++
helpviewer_keywords:
- C4041
ms.assetid: 107ee9fd-4b88-4f22-a18f-a20726831095
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9ff2c8066557e420ecd7de561d7731b7be733315
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46085778"
---
# <a name="compiler-warning-level-1-c4041"></a>Compilador aviso (nível 1) C4041

limite do compilador: saída do navegador de terminação

Informações sobre o navegador excedeu o limite do compilador.

Esse aviso pode ser causado por compilar com [/FR](../../build/reference/fr-fr-create-dot-sbr-file.md) (informações de navegador inclusive variáveis locais).

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Compile com /Fr (informações do navegador sem variáveis locais).

1. Desabilite a saída do navegador (compilar sem /FR ou /Fr).