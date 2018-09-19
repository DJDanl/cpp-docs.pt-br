---
title: Desempenho de bibliotecas multithread | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- threading [C++], performance
- libraries, multithreaded
- performance, multithreading
- multithreaded libraries
ms.assetid: faa5d808-087c-463d-8f0d-8c478d137296
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9f66aebc7b6d77e3697fabf783332a83bdd6f3fb
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46052095"
---
# <a name="multithreaded-libraries-performance"></a>Desempenho de bibliotecas multithread

A CRT single-thread não está mais disponível. Este tópico trata de como obter o máximo desempenho de bibliotecas multithread.

## <a name="maximizing-performance"></a>Maximizar o desempenho

O desempenho das bibliotecas multithread foi aprimorado e está próximo do desempenho das bibliotecas single-thread que foram eliminadas. Existem vários recursos novos para essas situações, mesmo quando é necessário um desempenho superior.

- O bloqueio de fluxo independente permite bloquear um fluxo e, em seguida, usar as [funções _nolock](../c-runtime-library/nolock-functions.md), que acessam o fluxo diretamente. Assim, o uso de bloqueio pode ser suspenso fora de loops críticos.

- A opção de acordo com a localidade do thread reduz o custo de acesso de localidade para cenários multithread (consulte [_configthreadlocale](../c-runtime-library/reference/configthreadlocale.md)).

- As funções dependentes da localidade (com nomes que terminam em _l) usam a localidade como parâmetro, removendo um custo substancial (por exemplo, [printf, _printf_l, wprintf, _wprintf_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)).

- Otimizações para páginas de código comuns reduzem o custo de muitas operações curtas.

- A definição de [_CRT_DISABLE_PERFCRIT_LOCKS](../c-runtime-library/crt-disable-perfcrit-locks.md) força todas as operações de E/S a assumir um modelo de E/S single-thread e a usar as formas _nolock das funções. Isso permite que aplicativos single-thread altamente baseados em E/S tenham um melhor desempenho.

- Com a exposição do identificador de heap CRT, é possível habilitar o Heap de Baixa Fragmentação do (LFH) do Windows para o heap de CRT, o que pode melhorar substancialmente o desempenho em cenários altamente dimensionados.

## <a name="see-also"></a>Consulte também

[Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)