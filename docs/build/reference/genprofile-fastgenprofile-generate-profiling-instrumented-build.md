---
title: /GENPROFILE,/FASTGENPROFILE (gerar criação de perfil instrumentada de criação)
ms.date: 03/14/2018
f1_keywords:
- GENPROFILE
- FASTGENPROFILE
- /GENPROFILE
- /FASTGENPROFILE
helpviewer_keywords:
- GENPROFILE
- FASTGENPROFILE
ms.assetid: deff5ce7-46f5-448a-b9cd-a7a83a6864c6
ms.openlocfilehash: 19ddf56d92cc2d8fbbfaf635c8e1602443e35b5b
ms.sourcegitcommit: 6b749db14b4cf3a2b8d581fda6fdd8cb98bc3207
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/05/2020
ms.locfileid: "82825777"
---
# <a name="genprofile-fastgenprofile-generate-profiling-instrumented-build"></a>/GENPROFILE,/FASTGENPROFILE (gerar criação de perfil instrumentada de criação)

Especifica a geração de um arquivo. pgd pelo vinculador para dar suporte à otimização guiada por perfil (PGO). **/GENPROFILE** e **/FASTGENPROFILE** usam parâmetros padrão diferentes. Use **/GENPROFILE** para favorecer a precisão sobre a velocidade e o uso de memória durante a criação de perfil. Use **/FASTGENPROFILE** para favorecer o uso de memória menor e acelerar a precisão.

## <a name="syntax"></a>Sintaxe

> **/GENPROFILE**[**:**{[**COUNTER32**|**COUNTER64**] | [ |**NOEXACT**exexactly Exact] | **EXACT** **MEMMAX =**_#_|**MEMMIN =**_#_| [**caminho**|**nopath** ] | [**TRACKEH** |**NOTRACKEH** ] | **PGD =**_filename_}] \
> **/FASTGENPROFILE**[**:**{[**COUNTER32**|**COUNTER64**] | [ |**NOEXACT**exexactly Exact] | **EXACT** **MEMMAX =**_#_|**MEMMIN =**_#_| [**caminho**|**nopath** ] | [**TRACKEH** |**NOTRACKEH** ] | **PGD =**_filename_}]

### <a name="arguments"></a>Argumentos

Qualquer um dos argumentos a seguir pode ser especificado para **/GENPROFILE** ou **/FASTGENPROFILE**. Os argumentos listados aqui separados por um caractere**|** de pipe () são mutuamente exclusivos. Use um caractere de vírgula (**,**) para separar as opções.

**COUNTER32** &#124; **COUNTER64**<br/>
Use **COUNTER32** para especificar o uso de contadores de investigação de 32 bits e **COUNTER64** para especificar contadores de investigação de 64 bits. Quando você especifica **/GENPROFILE**, o padrão é **COUNTER64**. Quando você especifica **/FASTGENPROFILE**, o padrão é **COUNTER32**.

**Exato** &#124; **noexact**<br/>
Use **Exact** para especificar incrementos intercadeados com segurança de thread para investigações. **Noexact** especifica operações de incremento desprotegidas para investigações. O padrão é **noexact**.

**MEMMAX**=*Valor*de MEMMAX,*valor* de **MEMMIN**=<br/>
Use **MEMMAX** e **MEMMIN** para especificar os tamanhos máximo e mínimo de reserva para dados de treinamento na memória. O valor é a quantidade de memória a ser reservada em bytes. Por padrão, esses valores são determinados por um heurístico interno.

**Caminho** &#124; **nopath** <br/>
Use **path** para especificar um conjunto separado de contadores PGO para cada caminho exclusivo para uma função. Use **nopath** para especificar apenas um conjunto de contadores para cada função. Quando você especifica **/GENPROFILE**, o padrão é **caminho** . Quando você especifica **/FASTGENPROFILE**, o padrão é **nopath** .

**TRACKEH** &#124; **NOTRACKEH** <br/>
Especifica se os contadores extras devem ser usados para manter uma contagem precisa quando as exceções são lançadas durante o treinamento. Use **TRACKEH** para especificar contadores extras para uma contagem exata. Use **NOTRACKEH** para especificar contadores únicos para código que não usa manipulação de exceção ou que não encontre exceções em seus cenários de treinamento.  Quando você especifica **/GENPROFILE**, o padrão é **TRACKEH** . Quando você especifica **/FASTGENPROFILE**, o padrão é **NOTRACKEH** .

**PGD**=*Nome de arquivo* de PGD<br/>
Especifica um nome de arquivo base para o arquivo. pgd. Por padrão, o vinculador usa o nome do arquivo de imagem executável de base com uma extensão. pgd.

## <a name="remarks"></a>Comentários

As opções **/GENPROFILE** e **/FASTGENPROFILE** dizem ao vinculador para gerar o arquivo de instrumentação de criação de perfil necessário para dar suporte ao treinamento de aplicativos para a PGO (otimização guiada por perfil). Essas opções são novas no Visual Studio 2015. Prefira essas opções às opções preteridas **/LTCG: PGINSTRUMENT**, **/PGD** e **/POGOSAFEMODE** e **POGOSAFEMODE**, **VCPROFILE_ALLOC_SCALE** e **VCPROFILE_PATH** variáveis de ambiente. As informações de criação de perfil geradas pelo treinamento de aplicativo são usadas como entrada para executar otimizações de programa inteiro direcionadas durante compilações. Você pode definir opções adicionais para controlar vários recursos de criação de perfil para desempenho durante o treinamento e as compilações do aplicativo. As opções padrão especificadas pelo **/GENPROFILE** fornecem resultados mais precisos, especialmente para aplicativos multithread complexos e grandes. A opção **/FASTGENPROFILE** usa padrões diferentes para uma superfície de memória inferior e um desempenho mais rápido durante o treinamento, às custas da precisão.

As informações de criação de perfil são capturadas quando você executa o aplicativo instrumentado depois de criar usando **/GENPROFILE** de **/FASTGENPROFILE**. Essas informações são capturadas quando você especifica a opção de vinculador [/USEPROFILE](useprofile.md) para executar a etapa de criação de perfil e, em seguida, é usada para guiar a etapa de compilação otimizada. Para obter mais informações sobre como treinar seu aplicativo e detalhes sobre os dados coletados, consulte [otimizações guiadas por perfil](../profile-guided-optimizations.md).

Você também deve especificar **/LTCG** ao especificar **/GENPROFILE** ou **/FASTGENPROFILE**.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedade da**linha de comando** do**vinculador** > de **Propriedades** > de configuração.

1. Insira as opções e os argumentos **/GENPROFILE** ou **/FASTGENPROFILE** na caixa **Opções adicionais** . Escolha **OK** para salvar suas alterações.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Confira também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)<br/>
[/LTCG (geração de código do tempo de vinculação)](ltcg-link-time-code-generation.md)<br/>
