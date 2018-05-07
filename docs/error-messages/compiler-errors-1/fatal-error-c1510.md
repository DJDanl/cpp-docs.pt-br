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
ms.openlocfilehash: f39a609e1621dab404ff79e49ade56a88277aa80
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1510"></a>Erro fatal C1510
Não é possível abrir o recurso de linguagem clui.dll  
  
 O compilador não pode carregar a DLL do recurso de idioma.  
  
Há duas causas comuns desse problema. Ao usar as ferramentas e o compilador de 32 bits, você poderá ver esse erro para grandes projetos que usam mais de 2GB de memória durante um link. Uma possível solução em sistemas Windows de 64 bits é usar o nativo de 64 bits ou cruzada compilador e ferramentas para gerar o código. Isso aproveita o maior espaço de memória disponível para aplicativos de 64 bits. Se você precisar usar um compilador de 32 bits porque você está executando em um sistema de 32 bits, em alguns casos, você pode aumentar a quantidade de memória disponível para o vinculador para 3GB. Para obter mais informações, consulte [ajuste de 4 gigabytes: BCDEdit e Boot.ini](https://msdn.microsoft.com/library/vs/alm/bb613473(v=vs.85).aspx) e [BCDEdit /Set increaseuserva](https://msdn.microsoft.com/library/ff542202.aspx) comando.  

A outra causa comum é uma instalação do Visual Studio quebrada ou incompleta. Nesse caso, execute o instalador novamente para reparar ou reinstalar o Visual Studio.  
  