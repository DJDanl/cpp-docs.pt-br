---
title: Compilador aviso (nível 1) C4041
ms.date: 11/04/2016
f1_keywords:
- C4041
helpviewer_keywords:
- C4041
ms.assetid: 107ee9fd-4b88-4f22-a18f-a20726831095
ms.openlocfilehash: 6e1f2a2396447038f6a117f66d4002bea7fd7486
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50513666"
---
# <a name="compiler-warning-level-1-c4041"></a>Compilador aviso (nível 1) C4041

limite do compilador: saída do navegador de terminação

Informações sobre o navegador excedeu o limite do compilador.

Esse aviso pode ser causado por compilar com [/FR](../../build/reference/fr-fr-create-dot-sbr-file.md) (informações de navegador inclusive variáveis locais).

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Compile com /Fr (informações do navegador sem variáveis locais).

1. Desabilite a saída do navegador (compilar sem /FR ou /Fr).