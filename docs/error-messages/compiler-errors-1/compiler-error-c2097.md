---
title: Erro do compilador C2097
ms.date: 11/04/2016
f1_keywords:
- C2097
helpviewer_keywords:
- C2097
ms.assetid: 7e5b2fd4-f61c-4b8a-b265-93e987a04bd3
ms.openlocfilehash: cdb14aeef61d136a6992a05a72f382e589e88770
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80207487"
---
# <a name="compiler-error-c2097"></a>Erro do compilador C2097

inicialização ilegal

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Inicialização de uma variável usando um valor não constante.

1. Inicialização de um endereço curto com um endereço longo.

1. Inicialização de uma estrutura, União ou matriz local com uma expressão não constante ao compilar com **/za**.

1. Inicialização com uma expressão que contém um operador de vírgula.

1. Inicialização com uma expressão que não é constante nem simbólica.
