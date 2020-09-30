---
title: UNIX
description: Diretrizes para portar seu programa para UNIX.
ms.date: 11/04/2016
ms.topic: conceptual
f1_keywords:
- unix
helpviewer_keywords:
- UNIX
- POSIX compatibility
- POSIX file names
- UNIX, compatibility
ms.assetid: 40792414-7a5b-415d-bfa8-2bfb1ebb3731
ms.openlocfilehash: 07f5ffeec8696ded5880c45ed2ea1a5107bee48c
ms.sourcegitcommit: 9451db8480992017c46f9d2df23fb17b503bbe74
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2020
ms.locfileid: "91590141"
---
# <a name="unix"></a>UNIX

Se você planeja transferir seus programas para UNIX, siga estas diretrizes:

- Não remova os arquivos de cabeçalho do subdiretório SYS. Você pode posicionar os arquivos de cabeçalho SYS em outro lugar somente se não planeja transportar seus programas para o UNIX.

- Use o delimitador de caminho compatível com UNIX em rotinas que usem cadeias de caracteres que representam caminhos e nomes de arquivo como argumentos. O UNIX dá suporte apenas à barra (/) para essa finalidade, mas os sistemas operacionais Win32 dão suporte à barra invertida ( \\ ) e à barra (/). Esta documentação usa barras de avanço compatíveis com UNIX como delimitadores de caminho em `#include` instruções, por exemplo. (No entanto, o Shell de comando do sistema operacional Windows, CMD.EXE, não dá suporte à barra invertida nos comandos inseridos no prompt de comando.)

- Use caminhos e nomes de dados que funcionam corretamente no UNIX, que diferencia maiúsculas de minúsculas. O sistema de arquivos FAT (tabela de alocação de arquivos) em sistemas operacionais Win32 não diferencia maiúsculas de minúsculas. O sistema de arquivos NTFS preserva o caso de listagens de diretório, mas ignora maiúsculas e minúsculas em pesquisas de arquivos e outras operações do sistema.

> [!NOTE]
>  Nesta versão do Visual C++, informações de compatibilidade do UNIX foram removidas das descrições de função.

## <a name="see-also"></a>Confira também

[Compatibilidade](../c-runtime-library/compatibility.md)
