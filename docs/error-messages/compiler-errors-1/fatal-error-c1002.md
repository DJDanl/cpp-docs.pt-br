---
title: Erro fatal C1002 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1002
dev_langs:
- C++
helpviewer_keywords:
- C1002
ms.assetid: bd6d274a-c7b4-43af-8bf2-23c5e442aa22
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c63a8d399b3e8c781694d89825e7898fd1db4639
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1002"></a>Erro fatal C1002
compilador está fora do espaço de heap no passo 2  
  
 O compilador ficou sem espaço de memória dinâmica durante a segunda fase, provavelmente devido a um programa com muitos símbolos ou expressões complexas.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  Divida o arquivo de origem em vários arquivos menores.  
  
2.  Quebre expressões em subexpressões menores.  
  
3.  Remova outros programas ou drivers que consomem memória.