---
title: Erro fatal C1510
ms.date: 04/11/2017
f1_keywords:
- C1510
helpviewer_keywords:
- C1510
ms.assetid: 150c827f-9514-41a9-8d7e-82f820749bcb
ms.openlocfilehash: 33c17a3099f4aed99cc26579d0e65c4a350b4268
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69501087"
---
# <a name="fatal-error-c1510"></a>Erro fatal C1510

Não é possível abrir o recurso de linguagem clui. dll

O compilador não pode carregar a DLL de recursos de idioma.

Há duas causas comuns para esse problema. Ao usar o compilador de 32 bits e as ferramentas, você poderá ver esse erro para projetos grandes que usam mais de 2GB de memória durante um link. Uma solução possível em sistemas Windows de 64 bits é usar o compilador e as ferramentas de 64 bits nativos e cruzados para gerar seu código. Isso aproveita o maior espaço de memória disponível para aplicativos de 64 bits. Se você precisar usar um compilador de 32 bits porque está executando em um sistema de 32 bits, em alguns casos, você pode aumentar a quantidade de memória disponível para o vinculador para 3GB. Para obter mais informações, [consulte ajuste de 4 gigabytes: Bcdedit e boot. ini](/windows/win32/memory/4-gigabyte-tuning) e o comando [bcdedit/set IncreaseUserVa](/windows-hardware/drivers/devtest/bcdedit--set)

A outra causa comum é uma instalação quebrada ou incompleta do Visual Studio. Nesse caso, execute o instalador novamente para reparar ou reinstalar o Visual Studio.
