---
title: UNIX | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3f5155791f4bf12f15fa0c2c53d27fbe515e5af3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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