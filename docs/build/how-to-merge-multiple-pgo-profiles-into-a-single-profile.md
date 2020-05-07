---
title: Como mesclar vários perfis PGO em um único perfil
ms.date: 03/14/2018
helpviewer_keywords:
- merging profiles
- profile-guided optimizations, merging profiles
ms.assetid: aab686b5-59dd-40d1-a04b-5064690f65a6
ms.openlocfilehash: 451c0f30a271f5dce3974e172766da4a23340b93
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62188867"
---
# <a name="how-to-merge-multiple-pgo-profiles-into-a-single-profile"></a>Como mesclar vários perfis PGO em um único perfil

A PGO (otimização guiada por perfil) é uma excelente ferramenta para criar binários otimizados com base em um cenário cujo perfil é criado. Mas e se você tiver um aplicativo que tenha vários cenários importantes, mas distintos? Como criar um único perfil que o PGO pode usar de vários cenários diferentes? No Visual Studio, o PGO Manager, [pgomgr. exe](pgomgr.md), faz esse trabalho para você.

A sintaxe para mesclar perfis é:

`pgomgr /merge[:num] [.pgc_files] .pgd_files`

em `num` que é um peso opcional a ser usado para os arquivos. pgc adicionados por essa mesclagem. Os pesos são geralmente usados se houver alguns cenários que são mais importantes do que outros ou se houver cenários que devem ser executados várias vezes.

> [!NOTE]
> O Gerenciador de PGO não funciona com dados de perfil obsoletos. Para mesclar um arquivo. pgc em um arquivo. pgd, o arquivo. pgc deve ser gerado por um executável que foi criado pela mesma invocação de link que gerou o arquivo. pgd.

## <a name="examples"></a>Exemplos

Neste exemplo, o Gerenciador de PGO adiciona pgcFile. pgc a pgdFile. pgd seis vezes:

`pgomgr /merge:6 pgcFile.pgc pgdFile.pgd`

Neste exemplo, o Gerenciador de PGO adiciona pgcFile1. pgc e pgcFile2. pgc a pgdFile. pgd, duas vezes para cada arquivo. pgc:

`pgomgr /merge:2 pgcFile1.pgc pgcFile2.pgc pgdFile.pgd`

Se o Gerenciador de PGO for executado sem argumentos de arquivo. pgc, ele pesquisará o diretório local em busca de todos os arquivos. pgc que têm o mesmo nome base do arquivo. pgd seguido por um ponto de exclamação (!) e, em seguida, um ou mais caracteres arbitrários. Por exemplo, se o diretório local tiver arquivos test. pgd, Test! 1. pgc, test2. pgc e test! hello. pgc, e o comando a seguir for executado a partir do diretório local, o **pgomgr** mesclará Test! 1. pgc e test! hello. pgc em Test. pgd.

`pgomgr /merge test.pgd`

## <a name="see-also"></a>Confira também

[Otimizações orientadas a perfil](profile-guided-optimizations.md)
