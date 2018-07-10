---
title: pgomgr | Microsoft Docs
ms.custom: ''
ms.date: 03/14/2018
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- pgomgr program
- profile-guided optimizations, pgomgr
ms.assetid: 74589126-df18-42c9-8739-26d60e148d6a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7bf7567cfe9f21effda913606ca3af9a19464f9d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32377200"
---
# <a name="pgomgr"></a>pgomgr

Adiciona dados de perfil de um ou mais arquivos. PGC para o arquivo. PGD.

## <a name="syntax"></a>Sintaxe

> **pgomgr** [*opções*] *pgcfiles* *pgdfile*

### <a name="parameters"></a>Parâmetros

*Opções*<br/>
As opções a seguir podem ser especificadas para **pgomgr**:

- **/Help** ou **/?** Exibe disponível **pgomgr** opções.

- **/clear** faz com que o arquivo. PGD limpo de todas as informações de perfil. Não é possível especificar um. PGC arquivo quando **/limpar** for especificado.

- **detalhes** exibe as estatísticas detalhadas, incluindo informações de cobertura de gráfico de fluxo.

- **Resumo** exibe de estatísticas por função.

- **/Unique** quando usado com **resumo**, causas decorado nomes de função para exibir. O padrão, quando **/Unique** não for usado, para exibir os nomes de função não decorados.

- **/merge**[**:***n*] faz com que os dados no arquivo. PGC ou arquivos a ser adicionado ao arquivo. PGD. O parâmetro opcional, *n*, permite que você especifique que os dados devem ser adicionados *n* vezes. Por exemplo, se um cenário normalmente seria feitas seis vezes refletir a frequência na qual é feito pelos clientes, você pode fazer isso vez em uma execução de teste e adicioná-lo para o arquivo. PGD seis vezes com **pgomgr /merge:6**.

*pgcfiles*<br/>
. PGC um ou mais arquivos cujos dados de perfil que você deseja mesclar o arquivo. PGD. Você pode especificar um arquivo. PGC único ou vários arquivos. PGC. Se você não especificar os arquivos. PGC, **pgomgr** mescla todos os arquivos. PGC cujos nomes de arquivo são o mesmo que o arquivo. PGD.

*pgdfile* o arquivo. PGD na qual você estiver mesclando dados do arquivo. PGC ou arquivos.

## <a name="remarks"></a>Comentários

> [!NOTE]
> Você pode iniciar essa ferramenta somente de um prompt de comando do Visual Studio developer. Você não pode iniciá-lo em um prompt de comando do sistema ou no Explorador de arquivos.

## <a name="example"></a>Exemplo

Este exemplo de comando limpa o arquivo de myapp.pgd de dados de perfil:

`pgomgr /clear myapp.pgd`

Este exemplo de comando adiciona dados de perfil no myapp1.pgc para o arquivo. PGD três vezes:

`pgomgr /merge:3 myapp1.pgc myapp.pgd`

Neste exemplo, dados de perfil de todos os arquivos. PGC de # myapp são adicionados ao arquivo myapp.pgd.

`pgomgr -merge myapp1.pgd`

## <a name="see-also"></a>Consulte também

[Otimizações guiadas por perfil](profile-guided-optimizations.md)<br/>
[PgoAutoSweep](pgoautosweep.md)<br/>
[pgosweep](pgosweep.md)<br/>
