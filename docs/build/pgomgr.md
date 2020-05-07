---
title: pgomgr
ms.date: 03/14/2018
helpviewer_keywords:
- pgomgr program
- profile-guided optimizations, pgomgr
ms.assetid: 74589126-df18-42c9-8739-26d60e148d6a
ms.openlocfilehash: 4e3eb08c88db9d0ed4e47649014a600c3e0ccb78
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62295218"
---
# <a name="pgomgr"></a>pgomgr

Adiciona dados de perfil de um ou mais arquivos. pgc ao arquivo. pgd.

## <a name="syntax"></a>Sintaxe

> **pgomgr** [*Opções*] *pgcfiles* *pgdFile*

### <a name="parameters"></a>Parâmetros

*options*<br/>
As opções a seguir podem ser especificadas para **pgomgr**:

- **/help** ou **/?** Exibe as opções de **pgomgr** disponíveis.

- **/Clear** Faz com que o arquivo. pgd seja limpo de todas as informações de perfil. Você não pode especificar um arquivo. pgc quando **/Clear** é especificado.

- **/Detail** Exibe estatísticas detalhadas, incluindo informações de cobertura do grafo de fluxo.

- **/Summary** Exibe estatísticas por função.

- **/Unique** Quando usado com **/Summary**, faz com que nomes de função decorados sejam exibidos. O padrão, quando **/Unique** não é usado, é para que nomes de função não decorados sejam exibidos.

- **/Merge**\[**:**<em>n</em>] faz com que os dados nos arquivos. pgc sejam adicionados ao arquivo. pgd. O parâmetro opcional, *n*, permite que você especifique que os dados devem ser adicionados *n* vezes. Por exemplo, se um cenário normalmente fosse feito seis vezes para refletir a frequência de conclusão pelos clientes, você pode fazer isso uma vez em uma execução de teste e adicioná-lo ao arquivo. pgd seis vezes com **pgomgr/Merge: 6**.

*pgcfiles*<br/>
Um ou mais arquivos. pgc cujos dados de perfil você deseja mesclar no arquivo. pgd. Você pode especificar um único arquivo. pgc ou vários arquivos. pgc. Se você não especificar nenhum arquivo. pgc, o **pgomgr** mesclará todos os arquivos. pgc cujos nomes de arquivo são iguais aos arquivos. pgd.

*pgdfile*<br/>
O arquivo. pgd no qual você está Mesclando dados do arquivo. pgc ou arquivos.

## <a name="remarks"></a>Comentários

> [!NOTE]
> Você pode iniciar essa ferramenta somente em um prompt de comando do desenvolvedor do Visual Studio. Você não pode iniciá-lo em um prompt de comando do sistema ou no explorador de arquivos.

## <a name="example"></a>Exemplo

Este comando de exemplo limpa o arquivo MyApp. pgd dos dados de perfil:

`pgomgr /clear myapp.pgd`

Esse comando de exemplo adiciona dados de perfil em myapp1. pgc ao arquivo. pgd três vezes:

`pgomgr /merge:3 myapp1.pgc myapp.pgd`

Neste exemplo, os dados de perfil de todos os arquivos MyApp #. pgc são adicionados ao arquivo MyApp. pgd.

`pgomgr -merge myapp1.pgd`

## <a name="see-also"></a>Confira também

[Otimizações orientadas a perfil](profile-guided-optimizations.md)<br/>
[PgoAutoSweep](pgoautosweep.md)<br/>
[pgosweep](pgosweep.md)<br/>
