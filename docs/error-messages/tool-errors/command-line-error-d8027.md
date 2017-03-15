---
title: Erro de linha de comando D8027 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- D8027
dev_langs:
- C++
helpviewer_keywords:
- D8027
ms.assetid: f228220f-0c7f-49a6-a6e0-1f7bd4745aa6
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 804b12aec30f598321a3c1f7823f08240797728a
ms.lasthandoff: 02/25/2017

---
# <a name="command-line-error-d8027"></a>Erro D8027 (linha de comando)
não é possível executar 'componente'  
  
 O compilador não pôde executar o compilador determinado componente ou o vinculador.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Não há memória suficiente para carregar o componente. Se NMAKE invocar o compilador, execute o compilador fora o makefile.  
  
2.  O sistema operacional atual não pôde executar o componente. Verifique se o caminho aponta para os arquivos executáveis apropriado para seu sistema operacional.  
  
3.  O componente está corrompido. Copie o componente a partir dos discos de distribuição, usando o programa de instalação.  
  
4.  Uma opção foi especificada incorretamente. Por exemplo:  
  
    ```  
    cl /B1 file1.c  
    ```
