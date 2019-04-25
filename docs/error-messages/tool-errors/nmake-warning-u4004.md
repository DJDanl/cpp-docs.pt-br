---
title: Aviso U4004 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U4004
helpviewer_keywords:
- U4004
ms.assetid: 5086bbcb-42d7-4677-a877-1a02202a86a2
ms.openlocfilehash: 882f6c98b31d23d283f5e8b32b46a46c543b1a76
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62298146"
---
# <a name="nmake-warning-u4004"></a>Aviso U4004 (NMAKE)

muitas regras para targetname' destino'

Mais de um bloco de descrição foi especificado para o destino especificado usando um únicos dois-pontos (**:**) como separadores. NMAKE executado os comandos no primeiro bloco de descrição e ignorado posterior bloqueia.

Para especificar o mesmo destino em várias dependências, use dois-pontos duplo (`::`) como o separador em cada linha de dependência.