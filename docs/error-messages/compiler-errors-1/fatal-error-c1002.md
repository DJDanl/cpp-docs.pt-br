---
title: Erro fatal C1002 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C1002
dev_langs: C++
helpviewer_keywords: C1002
ms.assetid: bd6d274a-c7b4-43af-8bf2-23c5e442aa22
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d299c6793e106ce516a81a9a81312ef0a09c25bf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fatal-error-c1002"></a>Erro fatal C1002
compilador está fora do espaço de heap no passo 2  
  
 O compilador ficou sem espaço de memória dinâmica durante a segunda fase, provavelmente devido a um programa com muitos símbolos ou expressões complexas.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  Divida o arquivo de origem em vários arquivos menores.  
  
2.  Quebre expressões em subexpressões menores.  
  
3.  Remova outros programas ou drivers que consomem memória.