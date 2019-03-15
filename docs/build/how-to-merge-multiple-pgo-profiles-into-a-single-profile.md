---
title: 'Como: Mesclar vários perfis PGO em um único perfil'
ms.date: 03/14/2018
helpviewer_keywords:
- merging profiles
- profile-guided optimizations, merging profiles
ms.assetid: aab686b5-59dd-40d1-a04b-5064690f65a6
ms.openlocfilehash: 451c0f30a271f5dce3974e172766da4a23340b93
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824329"
---
# <a name="how-to-merge-multiple-pgo-profiles-into-a-single-profile"></a>Como: Mesclar vários perfis PGO em um único perfil

Otimização Guiada por perfil (PGO) é uma excelente ferramenta para criar binários otimizados com base em um cenário cujo perfil foi criado. Mas e se você tiver um aplicativo que tenha vários cenários importantes, ainda distintos? Como criar um único perfil pode usar a PGO de vários cenários diferentes? No Visual Studio, o Gerenciador de PGO [pgomgr.exe](pgomgr.md), faz esse trabalho para você.

A sintaxe para a mesclagem de perfis é:

`pgomgr /merge[:num] [.pgc_files] .pgd_files`

onde `num` é um peso opcional a ser usado para os arquivos. PGC adicionados por essa mesclagem. Os pesos são usados se há alguns cenários que são mais importantes que outras pessoas ou se houver cenários que estão para ser executado várias vezes.

> [!NOTE]
> O Gerenciador de PGO não funciona com os dados de perfil obsoletos. Para mesclar um arquivo. PGC em um arquivo. PGD, o arquivo. PGC deve ser gerado por um executável que foi criado por invocação mesmo link que gerou o arquivo. PGD.

## <a name="examples"></a>Exemplos

Neste exemplo, o Gerenciador de PGO adiciona pgcFile.pgc ao pgdFile.pgd seis vezes:

`pgomgr /merge:6 pgcFile.pgc pgdFile.pgd`

Neste exemplo, o Gerenciador de PGO adiciona pgcFile1.pgc e pgcFile2.pgc para pgdFile.pgd, duas vezes para cada arquivo. PGC:

`pgomgr /merge:2 pgcFile1.pgc pgcFile2.pgc pgdFile.pgd`

Se o Gerenciador de PGO é executado sem nenhum argumento de arquivo. PGC, ele pesquisará o diretório local para todos os arquivos. PGC que têm o mesmo nome base do arquivo. PGD seguido por um ponto de exclamação (!) e caracteres arbitrários, em seguida, um ou mais. Por exemplo, se o diretório local tiver arquivos test.pgd, test!1.pgc, test2.pgc e test!hello.pgc, e o comando a seguir é executado no diretório local, em seguida, **pgomgr** mescla test!1.pgc e test!hello.pgc test.pgd.

`pgomgr /merge test.pgd`

## <a name="see-also"></a>Consulte também

[Otimizações guiadas por perfil](profile-guided-optimizations.md)
