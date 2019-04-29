---
title: Variáveis de ambiente para otimizações orientadas a perfil
ms.date: 03/14/2018
helpviewer_keywords:
- profile-guided optimizations, environment variables
ms.assetid: f95a6d1e-49a4-4802-a144-092026b600a3
ms.openlocfilehash: 099e57f1ac69223adafe7bec1af4cc3452915e86
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62195256"
---
# <a name="environment-variables-for-profile-guided-optimizations"></a>Variáveis de ambiente para otimizações orientadas a perfil

Há três variáveis de ambiente que afetam os cenários de teste em uma imagem criada com **/ltcg: pgi** para otimizações guiadas por perfil:

- **PogoSafeMode** Especifica se deve usar o modo rápido ou modo de segurança para a criação de perfil de aplicativo.

- **VCPROFILE_ALLOC_SCALE** adiciona memória adicional para uso pelo criador de perfil.

- **VCPROFILE_PATH** permite que você especifique a pasta usada para arquivos. PGC.

**As variáveis de ambiente PogoSafeMode e VCPROFILE_ALLOC_SCALE foram preteridas no Visual Studio 2015.** As opções do vinculador [/GENPROFILE ou /FASTGENPROFILE](reference/genprofile-fastgenprofile-generate-profiling-instrumented-build.md) e [/USEPROFILE](reference/useprofile.md) especificam o mesmo comportamento do vinculador como essas variáveis de ambiente.

## <a name="pogosafemode"></a>PogoSafeMode

Essa variável de ambiente é preterida. Use o **EXACT** ou **NOEXACT** argumentos a serem **/GENPROFILE** ou **/FASTGENPROFILE** para controlar esse comportamento.

Limpar ou defina as **PogoSafeMode** variável de ambiente para especificar se deseja usar o modo de segurança ou de modo rápido para criação de perfil de aplicativo em x86 sistemas.

Otimização Guiada por perfil (PGO) tem dois modos possíveis durante a fase de criação de perfil: *modo rápido* e *modo de segurança*. Quando a analise está no modo rápido, ele usa o **INC** instrução para aumentar contadores de dados. O **INC** instrução é mais rápida, mas não é thread-safe. Quando a analise está no modo de segurança, ele usa o **LOCK INC** instrução para aumentar contadores de dados. O **LOCK INC** instrução tem a mesma funcionalidade que o **INC** instrução tem e é thread-safe, mas é mais lento do que o **INC** instrução.

Por padrão, a criação de perfil de PGO opera no modo rápido. **PogoSafeMode** é necessário apenas se você deseja usar o modo de segurança.

Para executar a criação de perfil de PGO no modo de segurança, você deve usar a variável de ambiente **PogoSafeMode** ou a opção de vinculador **/PogoSafeMode**, dependendo do sistema. Se você estiver executando a criação de perfil em um x64 computador, você deve usar a opção de vinculador. Se você estiver executando a criação de perfil em um x86 computador, você pode usar o vinculador alternar ou defina as **PogoSafeMode** variável de ambiente para qualquer valor antes de iniciar o processo de otimização.

### <a name="pogosafemode-syntax"></a>Sintaxe de PogoSafeMode

> **set PogoSafeMode**[**=**_value_]

Definir **PogoSafeMode** qualquer valor para habilitar o modo de segurança. Defina sem um valor para limpar um valor anterior e habilitar novamente de modo rápido.

## <a name="vcprofileallocscale"></a>VCPROFILE_ALLOC_SCALE

Essa variável de ambiente é preterida. Use o **MEMMIN** e **MEMMAX** argumentos a serem **/GENPROFILE** ou **/FASTGENPROFILE** para controlar esse comportamento.

Modificar a **VCPROFILE_ALLOC_SCALE** variável de ambiente para alterar a quantidade de memória alocada para armazenar os dados de perfil. Em casos raros, não haverá memória suficiente disponível para dar suporte à coleta de dados de perfil durante a execução de cenários de teste. Nesses casos, você pode aumentar a quantidade de memória, definindo **VCPROFILE_ALLOC_SCALE**. Se você receber uma mensagem de erro durante uma execução de teste que indica que você tenha memória suficiente, atribua um valor maior para **VCPROFILE_ALLOC_SCALE**, até que as execuções de teste concluída sem erros de falta de memória.

### <a name="vcprofileallocscale-syntax"></a>Sintaxe VCPROFILE_ALLOC_SCALE

> **set VCPROFILE_ALLOC_SCALE**[__=__*scale_value*]

O *scale_value* parâmetro é um fator de escala para a quantidade de memória que você deseja para a execução de cenários de teste.  O padrão é 1. Por exemplo, esta linha de comando define o fator de escala como 2:

`set VCPROFILE_ALLOC_SCALE=2`

## <a name="vcprofilepath"></a>VCPROFILE_PATH

Use o **VCPROFILE_PATH** variável de ambiente para especificar o diretório para criar arquivos. PGC. Por padrão, os arquivos. PGC são criados no mesmo diretório que o binário com perfil sendo criado. No entanto, se o caminho absoluto do binário não existir, conforme pode ser o caso quando você executar cenários de perfil em um computador diferente de onde o binário foi criado, você pode definir **VCPROFILE_PATH** para um caminho que existe no computador de destino.

### <a name="vcprofilepath-syntax"></a>Sintaxe VCPROFILE_PATH

> **set VCPROFILE_PATH**[**=**_path_]

Defina as *caminho* parâmetro para o caminho do diretório no qual adicionar o arquivo. PGC. Por exemplo, esta linha de comando define a pasta para C:\profile:

`set VCPROFILE_PATH=c:\profile`

## <a name="see-also"></a>Consulte também

[Otimizações guiadas por perfil](profile-guided-optimizations.md)<br/>
[/GENPROFILE e /FASTGENPROFILE](reference/genprofile-fastgenprofile-generate-profiling-instrumented-build.md)<br/>
[/USEPROFILE](reference/useprofile.md)<br/>
