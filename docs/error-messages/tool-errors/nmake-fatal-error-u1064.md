---
title: NMAKE Erro Fatal U1064 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U1064
dev_langs:
- C++
helpviewer_keywords:
- U1064
ms.assetid: 7141e66e-cde6-4173-84df-a391f3ebcdd1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4240bf2c553957e73d5ead0bdd03ea129450645b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46092986"
---
# <a name="nmake-fatal-error-u1064"></a>Erro fatal U1064 (NMAKE)

MAKEFILE não encontrado e nenhum destino especificado

A linha de comando NMAKE não especificou um makefile ou destino e o diretório atual não contém um arquivo chamado MAKEFILE.

NMAKE exige um makefile ou um destino de linha de comando (ou ambos). Para disponibilizar um makefile para NMAKE, especifique a opção /F ou colocar um arquivo chamado MAKEFILE no diretório atual. NMAKE pode criar um destino de linha de comando usando uma regra de inferência se não for fornecido um makefile.