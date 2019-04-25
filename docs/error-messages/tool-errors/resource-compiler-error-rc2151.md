---
title: Erro RC2151 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RC2151
helpviewer_keywords:
- RC2151
ms.assetid: 3c47e535-c78d-4338-aab9-9b47e2c34728
ms.openlocfilehash: 8eaa50bc6080e37a4a74585eb03cbe4e40893bce
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62173438"
---
# <a name="resource-compiler-error-rc2151"></a>Erro RC2151 (compilador de recurso)

não é possível usar novamente as constantes de cadeia de caracteres

Você estiver usando o mesmo valor de duas vezes em uma **STRINGTABLE** instrução. Verifique se que você está misturando não sobrepostos valores decimais e hexadecimais.

Cada ID em um **STRINGTABLE** deve ser exclusivo. Para obter eficiência máxima use contíguos constantes com início em um múltiplo de 16.