---
title: Variáveis de ambiente para otimizações guiadas por perfil | Microsoft Docs
ms.custom: ''
ms.date: 03/14/2018
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- profile-guided optimizations, environment variables
ms.assetid: f95a6d1e-49a4-4802-a144-092026b600a3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 19edc9c8a2702e5b7ac9ae4a49364718f19d3900
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32379439"
---
# <a name="environment-variables-for-profile-guided-optimizations"></a>Variáveis de ambiente para otimizações orientadas a perfil

Há três variáveis de ambiente que afetam os cenários de teste em uma imagem criada com **/LTCG:PGI** para otimizações guiadas por perfil:

- **PogoSafeMode** Especifica se deve usar o modo de segurança ou de modo rápido para a criação de perfil de aplicativo.

- **VCPROFILE_ALLOC_SCALE** adiciona memória adicional para uso pelo criador de perfil.

- **VCPROFILE_PATH** permite que você especifique a pasta usada para arquivos. PGC.

**As variáveis de ambiente PogoSafeMode e VCPROFILE_ALLOC_SCALE foram substituídas no Visual Studio 2015.** As opções do vinculador [/GENPROFILE ou /FASTGENPROFILE](genprofile-fastgenprofile-generate-profiling-instrumented-build.md) e [/USEPROFILE](useprofile.md) especificar o mesmo comportamento de vinculador como essas variáveis de ambiente.

## <a name="pogosafemode"></a>PogoSafeMode

Essa variável de ambiente é preterida. Use o **exato** ou **NOEXACT** argumentos para **/GENPROFILE** ou **/FASTGENPROFILE** para controlar esse comportamento.

Limpar ou defina o **PogoSafeMode** variável de ambiente para especificar se deseja usar o modo rápido ou modo de segurança para criação de perfil de aplicativo em x86 sistemas.

Otimização Guiada por perfil (PGO) tem dois modos possíveis durante a fase de criação de perfil: *modo rápido* e *modo de segurança*. Quando a criação de perfil está no modo rápido, ele usa o **INC** instrução para aumentar os contadores de dados. O **INC** instrução é mais rápida, mas não é thread-safe. Quando a criação de perfil está no modo de segurança, ele usa o **LOCK INC** instrução para aumentar os contadores de dados. O **LOCK INC** instrução tem a mesma funcionalidade que o **INC** instrução tem e é thread-safe, mas é mais lenta que a **INC** instrução.

Por padrão, a criação de perfil de PGO opera em modo rápido. **PogoSafeMode** é necessário apenas se você deseja usar o modo de segurança.

Para executar a criação de perfil PGO no modo de segurança, você deve usar a variável de ambiente **PogoSafeMode** ou a opção de vinculador **/PogoSafeMode**, dependendo do sistema. Se você estiver executando a criação de perfil em um x64 computador, você deve usar a opção de vinculador. Se você estiver executando a criação de perfil em um x86 computador, você pode usar o vinculador alternar ou defina o **PogoSafeMode** variável de ambiente para qualquer valor antes de iniciar o processo de otimização.

### <a name="pogosafemode-syntax"></a>Sintaxe de PogoSafeMode

> **set PogoSafeMode**[**=**_value_]

Definir **PogoSafeMode** qualquer valor para habilitar o modo de segurança. Definir um valor de limpar um valor anterior e habilitar novamente de modo rápido.

## <a name="vcprofileallocscale"></a>VCPROFILE_ALLOC_SCALE

Essa variável de ambiente é preterida. Use o **MEMMIN** e **MEMMAX** argumentos para **/GENPROFILE** ou **/FASTGENPROFILE** para controlar esse comportamento.

Modificar o **VCPROFILE_ALLOC_SCALE** variável de ambiente para alterar a quantidade de memória alocada para armazenar os dados do perfil. Em casos raros, não haja memória suficiente dar suporte a coleta de dados de perfil durante a execução de cenários de teste. Nesses casos, você pode aumentar a quantidade de memória, definindo **VCPROFILE_ALLOC_SCALE**. Se você receber uma mensagem de erro durante uma execução de teste que indica que você tenha memória suficiente, atribua um valor maior para **VCPROFILE_ALLOC_SCALE**, até que a execução do teste concluída sem erros de falta de memória.

### <a name="vcprofileallocscale-syntax"></a>Sintaxe VCPROFILE_ALLOC_SCALE

> **set VCPROFILE_ALLOC_SCALE**[__=__*scale_value*]

O *scale_value* parâmetro é um fator de escala para a quantidade de memória que você deseja para a execução de cenários de teste.  O padrão é 1. Por exemplo, a linha de comando define o fator de escala para 2:

`set VCPROFILE_ALLOC_SCALE=2`

## <a name="vcprofilepath"></a>VCPROFILE_PATH

Use o **VCPROFILE_PATH** variável de ambiente para especificar o diretório para criar arquivos. PGC. Por padrão, os arquivos. PGC são criados no mesmo diretório que o binário que está sendo analisado. No entanto, se o caminho absoluto do binário não existir, que pode ser o caso quando você executa os cenários de perfil em um computador diferente de onde o binário foi criado, você pode definir **VCPROFILE_PATH** para um caminho que existe no computador de destino.

### <a name="vcprofilepath-syntax"></a>Sintaxe VCPROFILE_PATH

> **set VCPROFILE_PATH**[**=**_path_]

Definir o *caminho* parâmetro para o caminho do diretório no qual adicionar o arquivo. PGC. Por exemplo, a linha de comando define a pasta para C:\profile:

`set VCPROFILE_PATH=c:\profile`

## <a name="see-also"></a>Consulte também

[Otimizações guiadas por perfil](../../build/reference/profile-guided-optimizations.md)<br/>
[/GENPROFILE e /FASTGENPROFILE](genprofile-fastgenprofile-generate-profiling-instrumented-build.md)<br/>
[/USEPROFILE](useprofile.md)<br/>
