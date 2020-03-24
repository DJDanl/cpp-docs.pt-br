---
title: Erro fatal U1064 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U1064
helpviewer_keywords:
- U1064
ms.assetid: 7141e66e-cde6-4173-84df-a391f3ebcdd1
ms.openlocfilehash: bfc42c458c1932287f17f367d09c4b23c2c201a4
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80182819"
---
# <a name="nmake-fatal-error-u1064"></a>Erro fatal U1064 (NMAKE)

MAKEFILE não encontrado e nenhum destino especificado

A linha de comando NMAKE não especificou um makefile ou um destino, e o diretório atual não continha um arquivo chamado MAKEFILE.

O NMAKE requer um makefile ou um destino de linha de comando (ou ambos). Para disponibilizar um makefile para NMAKE, especifique a opção/F ou coloque um arquivo chamado MAKEFILE no diretório atual. NMAKE pode criar um destino de linha de comando usando uma regra de inferência se um makefile não for fornecido.
