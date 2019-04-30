---
title: Erro do compilador C2097
ms.date: 11/04/2016
f1_keywords:
- C2097
helpviewer_keywords:
- C2097
ms.assetid: 7e5b2fd4-f61c-4b8a-b265-93e987a04bd3
ms.openlocfilehash: 8b50221997dcf2fb60ee2b82ed630dd325a38145
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62377001"
---
# <a name="compiler-error-c2097"></a>Erro do compilador C2097

inicialização inválida

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Inicialização de uma variável usando um valor não constante.

1. Inicialização de um endereço curto com um endereço longo.

1. Inicialização de um local estrutura, união ou matriz com uma expressão não constante ao compilar com **/Za**.

1. Inicialização com uma expressão que contém um operador de vírgula.

1. Inicialização com uma expressão que é não constante nem simbólico.