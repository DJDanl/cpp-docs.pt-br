---
title: 'Como: mesclar vários perfis PGO em um único perfil | Microsoft Docs'
ms.custom: ''
ms.date: 03/14/2018
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- merging profiles
- profile-guided optimizations, merging profiles
ms.assetid: aab686b5-59dd-40d1-a04b-5064690f65a6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6ca8fd6ef94af290d568f3186747c659b918c0fd
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32372276"
---
# <a name="how-to-merge-multiple-pgo-profiles-into-a-single-profile"></a>Como mesclar vários perfis PGO em um único perfil

Otimização Guiada por perfil (PGO) é uma excelente ferramenta para criar binários otimizados com base em um cenário que é atribuído. Mas e se você tiver um aplicativo que tenha vários cenários importantes, ainda distintos? Como você cria um único perfil PGO pode usar de vários cenários diferentes? No Visual Studio, o Gerenciador de PGO [pgomgr.exe](pgomgr.md), faz esse trabalho para você.

A sintaxe para a mesclagem de perfis é:

`pgomgr /merge[:num] [.pgc_files] .pgd_files`

onde `num` é um peso opcional a ser usado para os arquivos. PGC adicionados por essa mesclagem. Os pesos são usados se existem alguns cenários que são mais importantes que outras pessoas ou se há cenários que estão para ser executado várias vezes.

> [!NOTE]
> O Gerenciador de PGO não funciona com dados de perfil obsoletos. Para mesclar um arquivo. PGC em um arquivo. PGD, o arquivo. PGC deve ser gerado por um executável que foi criado pelo mesmo invocação de link que gerou o arquivo. PGD.

## <a name="examples"></a>Exemplos

Neste exemplo, o Gerenciador de PGO adiciona pgcFile.pgc ao pgdFile.pgd seis vezes:

`pgomgr /merge:6 pgcFile.pgc pgdFile.pgd`

Neste exemplo, o Gerenciador de PGO adiciona pgcFile1.pgc e pgcFile2.pgc para pgdFile.pgd, duas vezes para cada arquivo. PGC:

`pgomgr /merge:2 pgcFile1.pgc pgcFile2.pgc pgdFile.pgd`

Se o Gerenciador de PGO for executado sem nenhum argumento de arquivo. PGC, ele pesquisa o diretório local para todos os arquivos. PGC que têm o mesmo nome base do arquivo. PGD seguido de um ponto de exclamação (!) e, em seguida, um ou mais arbitrários caracteres. Por exemplo, se o diretório local tiver arquivos test.pgd, test!1.pgc, test2.pgc e test!hello.pgc, e o comando a seguir é executado no diretório local, em seguida, **pgomgr** mescla test!1.pgc e test!hello.pgc test.pgd.

`pgomgr /merge test.pgd`

## <a name="see-also"></a>Consulte também

[Otimizações guiadas por perfil](../../build/reference/profile-guided-optimizations.md)
