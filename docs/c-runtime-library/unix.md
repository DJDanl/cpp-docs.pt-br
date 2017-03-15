---
title: UNIX | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- unix
dev_langs:
- C++
helpviewer_keywords:
- UNIX
- POSIX compatibility
- POSIX file names
- UNIX, compatibility
ms.assetid: 40792414-7a5b-415d-bfa8-2bfb1ebb3731
caps.latest.revision: 7
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
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 10c834b166ccc055ae8e43b2f2851566c6165d29
ms.lasthandoff: 02/25/2017

---
# <a name="unix"></a>UNIX
Se você planeja transferir seus programas para UNIX, siga estas diretrizes:  
  
-   Não remova os arquivos de cabeçalho do subdiretório SYS. Você pode colocar os arquivos de cabeçalho SYS em outro lugar somente se você não planeja transportar seus programas para UNIX.  
  
-   Use o delimitador de caminho compatível com UNIX em rotinas que usem cadeias de caracteres que representam caminhos e nomes de arquivo como argumentos. UNIX dá suporte somente a barra (/) para essa finalidade, enquanto os sistemas operacionais Win32 fornecem suporte a barra invertida (\\) e a barra (/). Portanto, esta documentação usa barras compatíveis com UNIX como delimitadores de caminho nas `#include` instruções, por exemplo. (No entanto, o shell de comando do sistema operacional Windows, CMD. EXE, não oferece suporte a barra de comandos digitados no prompt de comando.)  
  
-   Use caminhos e nomes de arquivos que funcionem corretamente no UNIX, que diferenciam maiusculas de minúsculas. A tabela de alocação de arquivos do sistema de arquivos (FAT) em sistemas operacionais Win32 não diferencia maiúsculas de minúsculas; o sistema de arquivos NTFS preserva o caso de listagens de diretório, mas ignora maiúsculas e minúsculas em pesquisas de arquivo e outras operações do sistema.  
  
    > [!NOTE]
    >  Nesta versão do Visual C++, informações de compatibilidade do UNIX foram removidas das descrições de função.  
  
## <a name="see-also"></a>Consulte também  
 [Compatibilidade](../c-runtime-library/compatibility.md)
