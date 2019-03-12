---
title: UNIX
ms.date: 11/04/2016
f1_keywords:
- unix
helpviewer_keywords:
- UNIX
- POSIX compatibility
- POSIX file names
- UNIX, compatibility
ms.assetid: 40792414-7a5b-415d-bfa8-2bfb1ebb3731
ms.openlocfilehash: edabb639d8f45680415473ad7b017d426b931ab5
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57745239"
---
# <a name="unix"></a>UNIX

Se você planeja transferir seus programas para UNIX, siga estas diretrizes:

- Não remova os arquivos de cabeçalho do subdiretório SYS. Você pode colocar os arquivos de cabeçalho SYS em outro lugar somente se você não planeja transportar seus programas para UNIX.

- Use o delimitador de caminho compatível com UNIX em rotinas que usem cadeias de caracteres que representam caminhos e nomes de arquivo como argumentos. UNIX dá suporte somente a barra (/) para essa finalidade, enquanto os sistemas operacionais Win32 fornecem suporte a barra invertida (\\) e a barra (/). Portanto, esta documentação usa barras compatíveis com UNIX como delimitadores de caminho nas `#include` instruções, por exemplo. (No entanto, o shell de comando do sistema operacional Windows, CMD. EXE, não oferece suporte a barra de comandos digitados no prompt de comando.)

- Use caminhos e nomes de arquivos que funcionem corretamente no UNIX, que diferenciam maiusculas de minúsculas. A tabela de alocação de arquivos do sistema de arquivos (FAT) em sistemas operacionais Win32 não diferencia maiúsculas de minúsculas; o sistema de arquivos NTFS preserva o caso de listagens de diretório, mas ignora maiúsculas e minúsculas em pesquisas de arquivo e outras operações do sistema.

    > [!NOTE]
    >  Nesta versão do Visual C++, informações de compatibilidade do UNIX foram removidas das descrições de função.

## <a name="see-also"></a>Consulte também

[Compatibilidade](../c-runtime-library/compatibility.md)
