---
title: Aviso de NMAKE U4004 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U4004
dev_langs:
- C++
helpviewer_keywords:
- U4004
ms.assetid: 5086bbcb-42d7-4677-a877-1a02202a86a2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2a89bb8abf212c8a0ffa9fb40fe5d3ea43307a08
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46016644"
---
# <a name="nmake-warning-u4004"></a>Aviso U4004 (NMAKE)

muitas regras para targetname' destino'

Mais de um bloco de descrição foi especificado para o destino especificado usando um únicos dois-pontos (**:**) como separadores. NMAKE executado os comandos no primeiro bloco de descrição e ignorado posterior bloqueia.

Para especificar o mesmo destino em várias dependências, use dois-pontos duplo (`::`) como o separador em cada linha de dependência.