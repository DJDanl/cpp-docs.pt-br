---
title: pgosweep | Microsoft Docs
ms.custom: ''
ms.date: 03/14/2018
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- pgosweep program
- profile-guided optimizations, pgosweep
ms.assetid: f39dd3b7-1cd9-4c3b-8e8b-fb794744b757
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ed12828d9170aac576a97c63b9988bb4b303ef58
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45711897"
---
# <a name="pgosweep"></a>pgosweep

Usado em Otimização Guiada por perfil para gravar todos os dados de perfil de um programa em execução para o arquivo. PGC.

## <a name="syntax"></a>Sintaxe

> **pgosweep** [*options*] *image* *pgcfile*

### <a name="parameters"></a>Parâmetros

*options*<br/>
(Opcional) Os valores válidos para *opções* são:

- **/?** ou **/Help** exibe a mensagem de Ajuda.

- **/NoReset** preserva a contagem em estruturas de dados de tempo de execução.

*image*<br/>
O caminho completo de um arquivo. dll ou. .exe que foi criado usando o [/GENPROFILE](genprofile-fastgenprofile-generate-profiling-instrumented-build.md), [/FASTGENPROFILE](genprofile-fastgenprofile-generate-profiling-instrumented-build.md), ou [/LTCG:PGINSTRUMENT](ltcg-link-time-code-generation.md) opção.

*pgcfile*<br/>
O arquivo. PGC onde este comando grava os dados de contagens.

## <a name="remarks"></a>Comentários

O **pgosweep** comando funciona em programas que foram compilados usando o [/GENPROFILE ou /FASTGENPROFILE](genprofile-fastgenprofile-generate-profiling-instrumented-build.md) opção ou preteridas [/LTCG:PGINSTRUMENT](ltcg-link-time-code-generation.md) opção. Ele interrompe um programa em execução e grava os dados de perfil para um novo arquivo. PGC. Por padrão, o comando redefine contagens após cada operação de gravação. Se você especificar o **/noreset** opção, o comando registre os valores, mas não redefini-los no programa em execução. Essa opção oferece dados duplicados se você recuperar os dados de perfil mais tarde.

A alternativa de usar para **pgosweep** é recuperar informações de perfil apenas para a operação normal do aplicativo. Por exemplo, você pode executar **pgosweep** logo após iniciar o aplicativo e descartar esse arquivo. Isso removerá os dados de perfil associados com os custos de inicialização. Em seguida, você pode executar **pgosweep** antes de encerrar o aplicativo. Agora os dados coletados tem informações de perfil somente a partir da hora que o usuário pode interagir com o programa.

Quando você nomear um arquivo. PGC (usando o *pgcfile* parâmetro) você pode usar o formato padrão, o que está *appname! n*. PGC. Se você usar esse formato, o compilador encontra automaticamente esses dados na **/LTCG /USEPROFILE** ou **/ltcg: PGO** fase. Se você não usar o formato padrão, você deve usar [pgomgr](pgomgr.md) para mesclar os arquivos. PGC.

> [!NOTE]
> Você pode iniciar essa ferramenta apenas de um prompt de comando do desenvolvedor de Visual Studio. Você não pode iniciá-lo em um prompt de comando do sistema ou no Explorador de arquivos.

Para obter informações sobre como capturar os dados de perfil de dentro de seu executável, consulte [PgoAutoSweep](pgoautosweep.md).

## <a name="example"></a>Exemplo

Neste comando de exemplo, **pgosweep** grava as informações de perfil atual para myapp.exe myapp!1.pgc.

`pgosweep myapp.exe myapp!1.pgc`

## <a name="see-also"></a>Consulte também

[Otimizações guiadas por perfil](profile-guided-optimizations.md)<br/>
[PgoAutoSweep](pgoautosweep.md)<br/>
