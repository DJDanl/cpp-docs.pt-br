---
title: Erro fatal C1383
ms.date: 11/04/2016
f1_keywords:
- C1383
helpviewer_keywords:
- C1383
ms.assetid: ca224d14-d687-4fd6-80c2-8b82f28924ea
ms.openlocfilehash: 6c0be830cb56b760f1397ea2b2f81b42a87e9ba6
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80203080"
---
# <a name="fatal-error-c1383"></a>Erro fatal C1383

a opção de compilador/GL é incompatível com a versão instalada do Common Language Runtime

C1383 ocorre quando você está usando uma versão anterior do Common Language Runtime com um compilador mais recente e quando você compila com **/CLR** e **/GL.**

Para resolver, não use **/GL** com **/CLR** ou instale a versão do Common Language Runtime fornecido com o compilador.

Para obter mais informações, consulte [/CLR (compilação em tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md) e [/GL (otimização de programa completo)](../../build/reference/gl-whole-program-optimization.md).
