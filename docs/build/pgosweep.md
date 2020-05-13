---
title: pgosweep
ms.date: 03/14/2018
helpviewer_keywords:
- pgosweep program
- profile-guided optimizations, pgosweep
ms.assetid: f39dd3b7-1cd9-4c3b-8e8b-fb794744b757
ms.openlocfilehash: 3ba31671fc3794e1cc959d86d914ba1eef2e01e4
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64341191"
---
# <a name="pgosweep"></a>pgosweep

Usado na otimização guiada por perfil para gravar todos os dados de perfil de um programa em execução no arquivo. pgc.

## <a name="syntax"></a>Sintaxe

> **PGOSWEEP** [*Opções*] *imagem* *pgcfile*

### <a name="parameters"></a>Parâmetros

*options*<br/>
Adicional Os valores válidos para *as opções* são:

- **/?** ou **/Help** exibe a mensagem de ajuda.

- **/noreset** preserva a contagem nas estruturas de dados de tempo de execução.

*imagem*<br/>
O caminho completo de um arquivo. exe ou. dll que foi criado usando a opção [/GENPROFILE](reference/genprofile-fastgenprofile-generate-profiling-instrumented-build.md), [/FASTGENPROFILE](reference/genprofile-fastgenprofile-generate-profiling-instrumented-build.md)ou [/LTCG: PGINSTRUMENT](reference/ltcg-link-time-code-generation.md) .

*pgcfile*<br/>
O arquivo. pgc em que esse comando grava as contagens de dados.

## <a name="remarks"></a>Comentários

O comando **PGOSWEEP** funciona em programas que foram criados usando a opção [/GENPROFILE ou/FASTGENPROFILE](reference/genprofile-fastgenprofile-generate-profiling-instrumented-build.md) ou a opção [/LTCG: PGINSTRUMENT](reference/ltcg-link-time-code-generation.md) preterida. Ele interrompe um programa em execução e grava os dados do perfil em um novo arquivo. pgc. Por padrão, o comando redefine as contagens após cada operação de gravação. Se você especificar a opção **/noreset** , o comando irá registrar os valores, mas não redefini-los no programa em execução. Essa opção lhe dará dados duplicados se você recuperar os dados do perfil mais tarde.

Um uso alternativo para **PGOSWEEP** é recuperar informações de perfil apenas para a operação normal do aplicativo. Por exemplo, você pode executar **PGOSWEEP** logo depois de iniciar o aplicativo e descartar esse arquivo. Isso removeria os dados de perfil associados aos custos de inicialização. Em seguida, você pode executar **PGOSWEEP** antes de encerrar o aplicativo. Agora os dados coletados têm informações de perfil somente a partir do momento em que o usuário pode interagir com o programa.

Ao nomear um arquivo. pgc (usando o parâmetro *pgcfile* ), você pode usar o formato padrão, que é *AppName! n*. pgc. Se você usar esse formato, o compilador localizará automaticamente esses dados na fase **/LTCG/USEPROFILE** ou **/LTCG: PGO** . Se você não usar o formato padrão, deverá usar [pgomgr](pgomgr.md) para mesclar os arquivos. pgc.

> [!NOTE]
> Você pode iniciar essa ferramenta somente em um prompt de comando do desenvolvedor do Visual Studio. Você não pode iniciá-lo em um prompt de comando do sistema ou no explorador de arquivos.

Para obter informações sobre como capturar os dados de perfil de dentro de seu executável, consulte [PgoAutoSweep](pgoautosweep.md).

## <a name="example"></a>Exemplo

Neste comando de exemplo, **PGOSWEEP** grava as informações de perfil atuais para MyApp. exe em MyApp! 1. pgc.

`pgosweep myapp.exe myapp!1.pgc`

## <a name="see-also"></a>Confira também

[Otimizações orientadas a perfil](profile-guided-optimizations.md)<br/>
[PgoAutoSweep](pgoautosweep.md)<br/>
