---
title: /GENPROFILE, /FASTGENPROFILE (gerar Build instrumentado de criação de perfil)
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
ms.openlocfilehash: cf6327b175344f1e2914792eb47a4838e544ea24
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57813871"
---
# <a name="genprofile-fastgenprofile-generate-profiling-instrumented-build"></a>/GENPROFILE, /FASTGENPROFILE (gerar Build instrumentado de criação de perfil)

Especifica a geração de um arquivo. PGD pelo vinculador para dar suporte à otimização guiada por perfil (PGO). **/GENPROFILE** e **/FASTGENPROFILE** usam parâmetros padrão diferentes. Use **/GENPROFILE** a favorecer precisão sobre o uso de memória e velocidade durante a criação de perfil. Use **/FASTGENPROFILE** favorecer velocidade e menor uso de memória sobre a precisão.

## <a name="syntax"></a>Sintaxe

> **/GENPROFILE**[**:**{[**COUNTER32**|**COUNTER64**]|[**EXACT**|**NOEXACT**]|**MEMMAX=**_#_|**MEMMIN=**_#_|[**PATH**|**NOPATH** ]|[**TRACKEH** |**NOTRACKEH** ]|**PGD=**_filename_}]<br/>
> **/FASTGENPROFILE**[**:**{[**COUNTER32**|**COUNTER64**]|[**EXACT**|**NOEXACT**]|**MEMMAX=**_#_|**MEMMIN=**_#_|[**PATH**|**NOPATH** ]|[**TRACKEH** |**NOTRACKEH** ]|**PGD=**_filename_}]

### <a name="arguments"></a>Arguments

Qualquer um dos argumentos a seguir pode ser especificado para **/GENPROFILE** ou **/FASTGENPROFILE**. Argumentos listados aqui são separados por uma barra vertical (**|**) caractere são mutuamente exclusivos. Use uma vírgula (**,**) caractere para separar opções.

**COUNTER32** &#124; **COUNTER64**<br/>
Use **COUNTER32** para especificar o uso de contadores de teste de 32 bits, e **COUNTER64** para especificar os contadores de teste de 64 bits. Quando você especifica **/GENPROFILE**, o padrão é **COUNTER64**. Quando você especifica **/FASTGENPROFILE**, o padrão é **COUNTER32**.

**EXACT** &#124; **NOEXACT**<br/>
Use **EXACT** para especificar a incrementos interconectados thread-safe para investigações. **NOEXACT** Especifica as operações de incremento desprotegido para testes. O padrão é **NOEXACT**.

**MEMMAX**=*valor*, **MEMMIN**=*valor*<br/>
Use **MEMMAX** e **MEMMIN** para especificar os tamanhos de reserva de mínimo e máximo para dados de treinamento na memória. O valor é a quantidade de memória reservado em bytes. Por padrão, esses valores são determinados por uma heurística interna.

**PATH**  &#124; **NOPATH** <br/>
Use **caminho** para especificar um conjunto separado de contadores PGO para cada caminho exclusivo para uma função. Use **NOPATH** para especificar apenas um conjunto de contadores para cada função. Quando você especifica **/GENPROFILE**, o padrão é **caminho** . Quando você especifica **/FASTGENPROFILE**, o padrão é **NOPATH** .

**TRACKEH**  &#124; **NOTRACKEH** <br/>
Especifica se deve usar os contadores extras para manter uma contagem precisa quando exceções forem geradas durante o treinamento. Use **TRACKEH** para especificar os contadores extras para uma contagem exata. Use **NOTRACKEH** para especificar contadores únicos para o código que não usa exceção manipulação ou que não encontrar exceções em seus cenários de treinamento.  Quando você especifica **/GENPROFILE**, o padrão é **TRACKEH** . Quando você especifica **/FASTGENPROFILE**, o padrão é **NOTRACKEH** .

**PGD**=*filename*<br/>
Especifica um nome de arquivo de base para o arquivo. PGD. Por padrão, o vinculador usa o nome do arquivo de imagem executável base com uma extensão. PGD.

## <a name="remarks"></a>Comentários

O **/GENPROFILE** e **/FASTGENPROFILE** opções dizer ao vinculador para gerar o arquivo de criação de perfil de instrumentação necessário para dar suporte a treinamento de aplicativo para a Otimização Guiada por perfil (PGO). Essas opções são novas no Visual Studio 2015. Prefira essas opções para preteridas **/LTCG:PGINSTRUMENT**, **/PGD.** e **/POGOSAFEMODE** opções e o **PogoSafeMode**,  **VCPROFILE_ALLOC_SCALE** e **VCPROFILE_PATH** variáveis de ambiente. As informações de perfil geradas pelo treinamento de aplicativo são usadas como entrada para executar direcionado a otimizações de programa inteiro durante builds. Você pode definir opções adicionais para controlar vários recursos de criação de perfil de desempenho durante o treinamento do aplicativo e se baseia. As opções padrão especificadas pelo **/GENPROFILE** dar resultados mais precisos, especialmente para grandes e complexos aplicativos multi-threaded. O **/FASTGENPROFILE** opção usa os padrões diferentes para um volume de memória menor e um desempenho mais rápido durante o treinamento, às custas da precisão.

Informações de criação de perfil é capturada quando você executar o aplicativo instrumentado depois que você compila usando **/GENPROFILE** dos **/FASTGENPROFILE**. Essas informações são capturadas quando você especifica o [/USEPROFILE](useprofile.md) etapa de opção de vinculador para executar a criação de perfil e, em seguida, usado para orientar a etapa de compilação otimizada. Para obter mais informações sobre como treinar seu aplicativo e obter detalhes sobre os dados coletados, consulte [otimizações guiadas pelo perfil](../profile-guided-optimizations.md).

Você também deve especificar **/LTCG** quando você especifica **/GENPROFILE** ou **/FASTGENPROFILE**.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. Insira o **/GENPROFILE** ou **/FASTGENPROFILE** opções e argumentos para o **opções adicionais** caixa. Escolha **OK** para salvar suas alterações.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)<br/>
[/LTCG (geração de código do tempo de vinculação)](ltcg-link-time-code-generation.md)<br/>
