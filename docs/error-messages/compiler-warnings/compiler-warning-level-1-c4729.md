---
title: Aviso do compilador (nível 1) C4729
ms.date: 11/04/2016
f1_keywords:
- C4729
helpviewer_keywords:
- C4729
ms.assetid: 36a0151f-f258-48d9-9444-ae6d41ff70a4
ms.openlocfilehash: e78606f117251fa8ab1f08f2cef280a266309c32
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80185822"
---
# <a name="compiler-warning-level-1-c4729"></a>Aviso do compilador (nível 1) C4729

função muito grande para avisos baseados em grafo de fluxo

Esse aviso é gerado quando uma função é muito grande para ser compilada com verificação confiável para situações que gerem um aviso. Esse aviso só é gerado quando a opção de compilador [/OD](../../build/reference/od-disable-debug.md) é usada.

Para resolver esse aviso, quebre a função em funções menores.
