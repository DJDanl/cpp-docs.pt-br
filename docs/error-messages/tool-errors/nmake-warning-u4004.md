---
title: Aviso U4004 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U4004
helpviewer_keywords:
- U4004
ms.assetid: 5086bbcb-42d7-4677-a877-1a02202a86a2
ms.openlocfilehash: d59b5656d76025fa56bfc76bad800659f25acf53
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80193193"
---
# <a name="nmake-warning-u4004"></a>Aviso U4004 (NMAKE)

muitas regras para ' targetname ' de destino

Mais de um bloco de descrição foi especificado para o destino fornecido usando dois-pontos únicos ( **:** ) como separadores. NMAKE executou os comandos no primeiro bloco de descrição e ignorou blocos posteriores.

Para especificar o mesmo destino em várias dependências, use dois-pontos duplos (`::`) como o separador em cada linha de dependência.
