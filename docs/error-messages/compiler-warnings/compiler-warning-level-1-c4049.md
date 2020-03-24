---
title: Aviso do compilador (nível 1) C4049
ms.date: 11/04/2016
f1_keywords:
- C4049
helpviewer_keywords:
- C4049
ms.assetid: d11c1870-bcfc-4d71-8945-b87ec6ec3514
ms.openlocfilehash: 214ccae5d9835bc4a3b66bbbe1cd5ded4bc651cb
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80164138"
---
# <a name="compiler-warning-level-1-c4049"></a>Aviso do compilador (nível 1) C4049

limite do compilador: emissão de número de linha de encerramento

O arquivo contém mais de 16.777.215 (2<sup>24</sup>-1) linhas de origem. O compilador para a numeração em 16.777.215.

Para o código após a linha 16.777.215:

- A imagem não conterá nenhuma informação de depuração para números de linha.

- Alguns diagnósticos podem ser relatados com números de linha incorretos.

- . as listagens do ASM (/FAs) podem ter números de linha incorretos.
