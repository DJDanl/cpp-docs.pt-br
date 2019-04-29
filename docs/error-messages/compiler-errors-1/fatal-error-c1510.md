---
title: Erro fatal C1510
ms.date: 04/11/2017
f1_keywords:
- C1510
helpviewer_keywords:
- C1510
ms.assetid: 150c827f-9514-41a9-8d7e-82f820749bcb
ms.openlocfilehash: f05f79ea78958a7d7a64f24bdce2d1151b93cdfb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62208499"
---
# <a name="fatal-error-c1510"></a>Erro fatal C1510

Não é possível abrir o recurso de linguagem clui. dll

O compilador não é possível carregar a DLL de recurso de idioma.

Há duas causas comuns para esse problema. Ao usar as ferramentas e o compilador de 32 bits, você poderá ver esse erro para grandes projetos que usam mais de 2GB de memória durante um link. Uma solução possível nos sistemas do Windows de 64 bits é usar o nativo de 64 bits ou cruzada de compilador e ferramentas para gerar seu código. Isso aproveita o maior espaço de memória disponível para aplicativos de 64 bits. Se você precisar usar um compilador de 32 bits porque você está executando em um sistema de 32 bits, em alguns casos, você pode aumentar a quantidade de memória disponível para o vinculador para 3GB. Para obter mais informações, consulte [ajuste de 4 GB: BCDEdit e Boot. ini](https://msdn.microsoft.com/library/vs/alm/bb613473) e o [BCDEdit /Set increaseuserva](https://msdn.microsoft.com/library/ff542202.aspx) comando.

A outra causa comum é uma instalação do Visual Studio quebrada ou incompleta. Nesse caso, execute o instalador novamente para reparar ou reinstalar o Visual Studio.
