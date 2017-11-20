---
title: Erro de linha de comando D8027 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: D8027
dev_langs: C++
helpviewer_keywords: D8027
ms.assetid: f228220f-0c7f-49a6-a6e0-1f7bd4745aa6
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 8e52c3c3029a8828aef11637a21f862cbe33cf9f
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="command-line-error-d8027"></a>Erro D8027 (linha de comando)
não é possível executar 'componente'  
  
 O compilador não pôde executar o componente de determinado compilador ou vinculador.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Não há memória suficiente para carregar o componente. Se NMAKE chamado o compilador, execute o compilador fora makefile.  
  
2.  O sistema operacional atual não foi possível executar o componente. Verifique se o caminho aponta para os arquivos executáveis apropriado para seu sistema operacional.  
  
3.  O componente foi corrompido. Copie o componente a partir dos discos de distribuição, usando o programa de instalação.  
  
4.  Uma opção foi especificada incorretamente. Por exemplo:  
  
    ```  
    cl /B1 file1.c  
    ```