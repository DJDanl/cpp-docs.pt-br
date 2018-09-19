---
title: Compilador aviso (nível 1) C4049 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4049
dev_langs:
- C++
helpviewer_keywords:
- C4049
ms.assetid: d11c1870-bcfc-4d71-8945-b87ec6ec3514
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 68a89d02129e5e8fbedb0649fff0cfe3813304c5
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46053512"
---
# <a name="compiler-warning-level-1-c4049"></a>Compilador aviso (nível 1) C4049

limite do compilador: encerrando emissão de número de linha

O arquivo contém mais de 16.777.215 (2<sup>24</sup>-1) linhas de origem. O compilador interrompe a numeração em 16.777.215.

Para o código após a linha 16.777.215:

- A imagem não conterá nenhuma informação de depuração para números de linha.

- Alguns diagnósticos podem ser relatados com números de linha incorreto.

- listagens. ASM (/ FAs) podem ter números de linha incorreto.