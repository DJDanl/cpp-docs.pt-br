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

Há três variáveis de ambiente que afetam os cenários de teste em uma imagem criada com **/LTCG: PGI** para otimizações guiadas por perfil:

- **PogoSafeMode** especifica se o modo rápido ou o modo de segurança deve ser usado para criação de perfil de aplicativo.

- **VCPROFILE_ALLOC_SCALE** adiciona memória adicional para uso pelo criador de perfil.

- **VCPROFILE_PATH** permite especificar a pasta usada para arquivos. pgc.

**As variáveis de ambiente PogoSafeMode e VCPROFILE_ALLOC_SCALE foram preteridas a partir do Visual Studio 2015.** As opções de vinculador [/GENPROFILE ou/FASTGENPROFILE](reference/genprofile-fastgenprofile-generate-profiling-instrumented-build.md) e [/USEPROFILE](reference/useprofile.md) especificam o mesmo comportamento de vinculador que essas variáveis de ambiente.

## <a name="pogosafemode"></a>PogoSafeMode

Essa variável de ambiente foi preterida. Use os argumentos **EXexactly** ou **Exact** para **/GENPROFILE** ou **/FASTGENPROFILE** para controlar esse comportamento.

Desmarque ou defina a variável de ambiente **PogoSafeMode** para especificar se deseja usar modo rápido ou modo de segurança para criação de perfil de aplicativo em sistemas x86.

A PGO (otimização guiada por perfil) tem dois modos possíveis durante a fase de criação de perfis: *modo rápido* e *modo de segurança*. Quando a criação de perfil está no modo rápido, ela usa a instrução **Inc** para aumentar os contadores de dados. A instrução **Inc** é mais rápida, mas não é thread-safe. Quando a criação de perfil está no modo de segurança, ela usa a instrução **Lock Inc** para aumentar os contadores de dados. A instrução **Lock Inc** tem a mesma funcionalidade que a instrução **Inc** tem e é thread-safe, mas é mais lento do que a instrução **Inc** .

Por padrão, a criação de perfil do PGO opera no modo rápido. **PogoSafeMode** só será necessário se você quiser usar o modo de segurança.

Para executar a criação de perfil do PGO no modo de segurança, você deve usar a variável de ambiente **PogoSafeMode** ou a opção de vinculador **/PogoSafeMode**, dependendo do sistema. Se você estiver executando a criação de perfil em um computador x64, deverá usar a opção de vinculador. Se estiver executando a criação de perfil em um computador x86, você poderá usar a opção de vinculador ou definir a variável de ambiente **PogoSafeMode** para qualquer valor antes de iniciar o processo de otimização.

### <a name="pogosafemode-syntax"></a>Sintaxe de PogoSafeMode

> **definir PogoSafeMode**[**=**_valor_]

Defina **PogoSafeMode** como qualquer valor para habilitar o modo de segurança. Defina sem um valor para limpar um valor anterior e reabilitar o modo rápido.

## <a name="vcprofile_alloc_scale"></a>VCPROFILE_ALLOC_SCALE

Essa variável de ambiente foi preterida. Use os argumentos **MEMMIN** e **MEMMAX** para **/GENPROFILE** ou **/FASTGENPROFILE** para controlar esse comportamento.

Modifique a variável de ambiente **VCPROFILE_ALLOC_SCALE** para alterar a quantidade de memória alocada para conter os dados de perfil. Em casos raros, não haverá memória suficiente disponível para oferecer suporte à coleta de dados de perfil durante a execução de cenários de teste. Nesses casos, você pode aumentar a quantidade de memória definindo **VCPROFILE_ALLOC_SCALE**. Se você receber uma mensagem de erro durante uma execução de teste que indica que você tem memória insuficiente, atribua um valor maior a **VCPROFILE_ALLOC_SCALE**, até que o teste seja executado com erros de falta de memória.

### <a name="vcprofile_alloc_scale-syntax"></a>Sintaxe de VCPROFILE_ALLOC_SCALE

> **definir VCPROFILE_ALLOC_SCALE**[__=__*scale_value*]

O parâmetro *scale_value* é um fator de dimensionamento para a quantidade de memória desejada para a execução de cenários de teste.  O padrão é 1. Por exemplo, essa linha de comando define o fator de escala como 2:

`set VCPROFILE_ALLOC_SCALE=2`

## <a name="vcprofile_path"></a>VCPROFILE_PATH

Use a variável de ambiente **VCPROFILE_PATH** para especificar o diretório para criar arquivos. pgc. Por padrão, os arquivos. pgc são criados no mesmo diretório que o binário sendo criado para criação de perfil. No entanto, se o caminho absoluto do binário não existir, como pode ser o caso ao executar cenários de perfil em um computador diferente de onde o binário foi criado, você poderá definir **VCPROFILE_PATH** como um caminho que existe no computador de destino.

### <a name="vcprofile_path-syntax"></a>Sintaxe de VCPROFILE_PATH

> **definir VCPROFILE_PATH**[**=**_caminho_]

Defina o parâmetro *path* como o caminho do diretório no qual adicionar arquivos. pgc. Por exemplo, essa linha de comando define a pasta como C:\profile:

`set VCPROFILE_PATH=c:\profile`

## <a name="see-also"></a>Confira também

[Otimizações orientadas a perfil](profile-guided-optimizations.md)<br/>
[/GENPROFILE e/FASTGENPROFILE](reference/genprofile-fastgenprofile-generate-profiling-instrumented-build.md)<br/>
[/USEPROFILE](reference/useprofile.md)<br/>
