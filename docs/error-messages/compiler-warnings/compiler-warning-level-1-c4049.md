---
title: Compilador aviso (nível 1) C4049
ms.date: 11/04/2016
f1_keywords:
- C4049
helpviewer_keywords:
- C4049
ms.assetid: d11c1870-bcfc-4d71-8945-b87ec6ec3514
ms.openlocfilehash: a4958bb446b5f7e80ef2eef92b52a0f86cf6a134
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50479398"
---
# <a name="compiler-warning-level-1-c4049"></a>Compilador aviso (nível 1) C4049

limite do compilador: encerrando emissão de número de linha

O arquivo contém mais de 16.777.215 (2<sup>24</sup>-1) linhas de origem. O compilador interrompe a numeração em 16.777.215.

Para o código após a linha 16.777.215:

- A imagem não conterá nenhuma informação de depuração para números de linha.

- Alguns diagnósticos podem ser relatados com números de linha incorreto.

- listagens. ASM (/ FAs) podem ter números de linha incorreto.