---
title: Erro fatal C1510 | Microsoft Docs
ms.custom: 
ms.date: 04/11/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1510
dev_langs:
- C++
helpviewer_keywords:
- C1510
ms.assetid: 150c827f-9514-41a9-8d7e-82f820749bcb
caps.latest.revision: 1
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 373cd74b1649fb9c1bd87cad1903df183f153c0f
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="fatal-error-c1510"></a>Erro fatal C1510
Não é possível abrir o recurso de linguagem clui.dll  
  
 O compilador não pode carregar a DLL do recurso de idioma.  
  
Há duas causas comuns desse problema. Ao usar as ferramentas e o compilador de 32 bits, você poderá ver esse erro para grandes projetos que usam mais de 2GB de memória durante um link. Uma possível solução em sistemas Windows de 64 bits é usar o nativo de 64 bits ou cruzada compilador e ferramentas para gerar o código. Isso aproveita o maior espaço de memória disponível para aplicativos de 64 bits. Se você precisar usar um compilador de 32 bits porque você está executando em um sistema de 32 bits, em alguns casos, você pode aumentar a quantidade de memória disponível para o vinculador para 3GB. Para obter mais informações, consulte [ajuste de 4 gigabytes: BCDEdit e Boot.ini](https://msdn.microsoft.com/library/vs/alm/bb613473(v=vs.85).aspx) e [BCDEdit /Set increaseuserva](https://msdn.microsoft.com/library/ff542202.aspx) comando.  

A outra causa comum é uma instalação do Visual Studio quebrada ou incompleta. Nesse caso, execute o instalador novamente para reparar ou reinstalar o Visual Studio.  
  
