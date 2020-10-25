---
title: pgosweep
description: Use o comando PGOSWEEP para gravar dados de perfil em um arquivo PGC para uso na otimização guiada por perfil.
ms.date: 10/23/2020
helpviewer_keywords:
- pgosweep program
- profile-guided optimizations, pgosweep
ms.openlocfilehash: be96d0f092ff65867c304ddf5eb41c0754f6e4be
ms.sourcegitcommit: bf54b407169900bb668c85a67b31dbc0f069fe65
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2020
ms.locfileid: "92497176"
---
# <a name="pgosweep"></a>pgosweep

Usado na otimização guiada por perfil para gravar todos os dados de perfil de um programa em execução no arquivo PGC.

## <a name="syntax"></a>Sintaxe

> **`pgosweep`**[*Opções*] *image* *pgcfile* de imagem

### <a name="parameters"></a>Parâmetros

*Opções*\
Adicional Os valores válidos para *as opções* são:

- **`/?`** ou **`/help`** exibe a mensagem de ajuda.

- **`/reset`** Redefine contagens para zero após varredura. Esse é o comportamento padrão.

- **`/pid:n`** apenas varre o PID especificado, em que *n* é o número da PID.

- **`/wait`** aguarda até que o PID especificado seja encerrado antes de coletar contagens.

- **`/onlyzero`** não salva um arquivo PGC, somente contagens zero.

- **`/pause`** pausa a coleta de contagem no sistema.

- **`/resume`** retoma a coleta de contagem no sistema.

- **`/noreset`** preserva a contagem nas estruturas de dados de tempo de execução.

*image*\
O caminho completo de um arquivo EXE ou DLL que foi criado usando a [`/GENPROFILE`](reference/genprofile-fastgenprofile-generate-profiling-instrumented-build.md) opção, [`/FASTGENPROFILE`](reference/genprofile-fastgenprofile-generate-profiling-instrumented-build.md) ou [`/LTCG:PGINSTRUMENT`](reference/ltcg-link-time-code-generation.md) .

*pgcfile*\
O arquivo PGC em que esse comando grava as contagens de dados.

## <a name="remarks"></a>Comentários

O **`pgosweep`** comando funciona em programas que foram criados usando a opção [ `/GENPROFILE` ou `/FASTGENPROFILE` ](reference/genprofile-fastgenprofile-generate-profiling-instrumented-build.md) , ou a opção preterida [`/LTCG:PGINSTRUMENT`](reference/ltcg-link-time-code-generation.md) . Ele interrompe um programa em execução e grava os dados do perfil em um novo arquivo PGC. Por padrão, o comando redefine as contagens após cada operação de gravação. Se você especificar a **`/noreset`** opção, o comando irá registrar os valores, mas não redefini-los no programa em execução. Essa opção lhe dará dados duplicados se você recuperar os dados do perfil mais tarde.

Um uso alternativo para **`pgosweep`** o é recuperar informações de perfil apenas para a operação normal do aplicativo. Por exemplo, você pode executar **`pgosweep`** logo depois de iniciar o aplicativo e descartar esse arquivo. Esse comando removeria os dados de perfil associados aos custos de inicialização. Em seguida, você pode executar **`pgosweep`** antes de encerrar o aplicativo. Agora os dados coletados têm informações de perfil somente a partir do momento em que o usuário pode interagir com o programa.

Ao nomear um arquivo PGC (usando o parâmetro *pgcfile* ), você pode usar o formato padrão, que é *`appname!n.pgc`* . O *n* representa um valor numérico cada vez maior para cada arquivo. Se você usar esse formato, o compilador localizará automaticamente esses dados na **`/LTCG /USEPROFILE`** **`/LTCG:PGO`** fase ou. Se você não usar o formato padrão, deverá usar [`pgomgr`](pgomgr.md) para mesclar os arquivos de PGC.

> [!NOTE]
> Você pode iniciar essa ferramenta somente em um prompt de comando do desenvolvedor do Visual Studio. Você não pode iniciá-lo em um prompt de comando do sistema ou no explorador de arquivos.

Para obter informações sobre como capturar os dados de perfil de dentro de seu executável, consulte [`PgoAutoSweep`](pgoautosweep.md) .

## <a name="example"></a>Exemplo

Neste exemplo de comando, **`pgosweep`** grava as informações do perfil atual para o *`myapp.exe`* *`myapp!1.pgc`* .

`pgosweep myapp.exe myapp!1.pgc`

## <a name="see-also"></a>Confira também

[Otimizações guiadas por perfil](profile-guided-optimizations.md)\
[PgoAutoSweep](pgoautosweep.md)
