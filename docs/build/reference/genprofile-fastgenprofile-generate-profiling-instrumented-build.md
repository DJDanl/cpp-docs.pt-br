---
title: /GENPROFILE, /FASTGENPROFILE (gerar a criação de perfil instrumentada compilação) | Microsoft Docs
ms.custom: ''
ms.date: 03/14/2018
ms.technology:
- cpp-tools
ms.topic: article
f1_keywords:
- GENPROFILE
- FASTGENPROFILE
- /GENPROFILE
- /FASTGENPROFILE
helpviewer_keywords:
- GENPROFILE
- FASTGENPROFILE
ms.assetid: deff5ce7-46f5-448a-b9cd-a7a83a6864c6
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b6174c1fdd53ec14f0cb63292a9036caabc98a7d
ms.sourcegitcommit: ee7d74683af7631441c8c7f65ef5ceceaee4a5ee
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2018
---
# <a name="genprofile-fastgenprofile-generate-profiling-instrumented-build"></a>/GENPROFILE, /FASTGENPROFILE (gerar compilação instrumentada de criação de perfil)

Especifica a geração de um arquivo. PGD pelo vinculador para dar suporte a Otimização Guiada por perfil (PGO). **/GENPROFILE** e **/FASTGENPROFILE** usar parâmetros diferentes do padrão. Use **/GENPROFILE** a favorecer precisão sobre velocidade e uso de memória durante a criação de perfil. Use **/FASTGENPROFILE** favorecer velocidade e menor uso de memória em precisão.

## <a name="syntax"></a>Sintaxe

> **/GENPROFILE**[**:**{[**COUNTER32**|**COUNTER64**]|[**EXACT**|**NOEXACT**]|**MEMMAX=**_#_|**MEMMIN=**_#_|[**PATH**|**NOPATH** ]|[**TRACKEH** |**NOTRACKEH** ]|**PGD=**_filename_}]<br/>
> **/FASTGENPROFILE**[**:**{[**COUNTER32**|**COUNTER64**]|[**EXACT**|**NOEXACT**]|**MEMMAX=**_#_|**MEMMIN=**_#_|[**PATH**|**NOPATH** ]|[**TRACKEH** |**NOTRACKEH** ]|**PGD=**_filename_}]

### <a name="arguments"></a>Arguments

Qualquer um dos seguintes argumentos pode ser especificado para **/GENPROFILE** ou **/FASTGENPROFILE**. Argumentos listados aqui são separados por uma barra vertical (**|**) caracteres são mutuamente exclusivos. Use uma vírgula (**,**) caractere para separar opções.

**COUNTER32** &#124; **COUNTER64**<br/>
Use **COUNTER32** para especificar o uso de contadores de teste de 32 bits, e **COUNTER64** para especificar os contadores de teste de 64 bits. Quando você especifica **/GENPROFILE**, o padrão é **COUNTER64**. Quando você especifica **/FASTGENPROFILE**, o padrão é **COUNTER32**.

**EXACT** &#124; **NOEXACT**<br/>
Use **exato** para especificar incrementos interlocked para testes de thread-safe. **NOEXACT** Especifica as operações de incremento desprotegido para testes. O padrão é **NOEXACT**.

**MEMMAX**=*value*, **MEMMIN**=*value*<br/>
Use **MEMMAX** e **MEMMIN** para especificar os tamanhos de reserva máximo e mínimo para dados de treinamento na memória. O valor é a quantidade de memória para reservar em bytes. Por padrão, esses valores são determinados por uma heurística interna.

**PATH**  &#124; **NOPATH** <br/>
Use **caminho** para especificar um conjunto separado de contadores PGO para cada caminho exclusivo para uma função. Use **NOPATH** para especificar apenas um conjunto de contadores para cada função. Quando você especifica **/GENPROFILE**, o padrão é **caminho** . Quando você especifica **/FASTGENPROFILE**, o padrão é **NOPATH** .

**TRACKEH**  &#124; **NOTRACKEH** <br/>
Especifica se deve usar os contadores extras para manter uma contagem precisa quando as exceções são geradas durante o treinamento. Use **TRACKEH** para especificar contadores extras para uma contagem exata. Use **NOTRACKEH** para especificar contadores único para o código que não usam a exceção manipulação ou que não encontrar exceções em seus cenários de treinamento.  Quando você especifica **/GENPROFILE**, o padrão é **TRACKEH** . Quando você especifica **/FASTGENPROFILE**, o padrão é **NOTRACKEH** .

**PGD**=*filename*<br/>
Especifica um nome de arquivo de base para o arquivo. PGD. Por padrão, o vinculador usa o nome do arquivo de imagem executável base com uma extensão. PGD.

## <a name="remarks"></a>Comentários

O **/GENPROFILE** e **/FASTGENPROFILE** opções informam o vinculador para gerar o arquivo de instrumentação de criação de perfil necessário para dar suporte a treinamento de aplicativo para Otimização Guiada por perfil (PGO). Essas opções são novas no Visual Studio 2015. Preferir essas opções para preterido **/LTCG:PGINSTRUMENT**, **/PGD** e **/POGOSAFEMODE** opções e o **PogoSafeMode**,  **VCPROFILE_ALLOC_SCALE** e **VCPROFILE_PATH** variáveis de ambiente. As informações de perfil geradas pelo treinamento de aplicativo são usadas como entrada para executar destinados otimizações de programa inteiro durante compilações. Você pode definir opções adicionais para controlar vários recursos de criação de perfil de desempenho durante o treinamento do aplicativo e cria. Opções padrão especificadas pelo **/GENPROFILE** dar resultados mais precisos, especialmente para aplicativos multithread grandes e complexos. O **/FASTGENPROFILE** opção usa padrões diferentes para uma base de memória menor e um desempenho mais rápido durante o treinamento, às custas de precisão.

Informações de criação de perfil é capturada quando você executa o aplicativo instrumentado depois que você cria usando **/GENPROFILE** de **/FASTGENPROFILE**. Essas informações são capturadas quando você especificar o [/USEPROFILE](useprofile.md) opção de vinculador para executar a criação de perfil etapa e, em seguida, usado para guiar a etapa de compilação otimizada. Para obter mais informações sobre como treinar seu aplicativo e os detalhes sobre os dados coletados, consulte [Otimização Guiada por perfil](profile-guided-optimizations.md).

Você também deve especificar **/LTCG** quando você especifica **/GENPROFILE** ou **/FASTGENPROFILE**.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. Insira o **/GENPROFILE** ou **/FASTGENPROFILE** opções e argumentos para o **opções adicionais** caixa. Escolha **Okey** para salvar suas alterações.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)<br/>
[/LTCG (geração de código do tempo de vinculação)](../../build/reference/ltcg-link-time-code-generation.md)<br/>
