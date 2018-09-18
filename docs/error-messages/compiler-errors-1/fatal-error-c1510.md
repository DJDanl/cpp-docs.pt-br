---
title: Erro fatal C1510 | Microsoft Docs
ms.custom: ''
ms.date: 04/11/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1510
dev_langs:
- C++
helpviewer_keywords:
- C1510
ms.assetid: 150c827f-9514-41a9-8d7e-82f820749bcb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4d1da6a21e5156ef0b78c42215de5c4ae7e807db
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46049690"
---
# <a name="fatal-error-c1510"></a>Erro fatal C1510

Não é possível abrir o recurso de linguagem clui. dll

O compilador não é possível carregar a DLL de recurso de idioma.

Há duas causas comuns para esse problema. Ao usar as ferramentas e o compilador de 32 bits, você poderá ver esse erro para grandes projetos que usam mais de 2GB de memória durante um link. Uma solução possível nos sistemas do Windows de 64 bits é usar o nativo de 64 bits ou cruzada de compilador e ferramentas para gerar seu código. Isso aproveita o maior espaço de memória disponível para aplicativos de 64 bits. Se você precisar usar um compilador de 32 bits porque você está executando em um sistema de 32 bits, em alguns casos, você pode aumentar a quantidade de memória disponível para o vinculador para 3GB. Para obter mais informações, consulte [ajuste de 4 gigabytes: BCDEdit e Boot. ini](https://msdn.microsoft.com/library/vs/alm/bb613473\(v=vs.85\).aspx) e o [BCDEdit /Set increaseuserva](https://msdn.microsoft.com/library/ff542202.aspx) comando.

A outra causa comum é uma instalação do Visual Studio quebrada ou incompleta. Nesse caso, execute o instalador novamente para reparar ou reinstalar o Visual Studio.
