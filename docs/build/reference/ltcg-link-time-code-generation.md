---
title: /LTCG (geração de código do tempo de vinculação)
ms.date: 05/16/2019
f1_keywords:
- VC.Project.VCLinkerTool.LinkTimeCodeGeneration
- VC.Project.VCConfiguration.WholeProgramOptimization
- VC.Project.VCCLWCECompilerTool.WholeProgramOptimization
- /ltcg
- VC.Project.VCCLCompilerTool.WholeProgramOptimization
helpviewer_keywords:
- link-time code generation in C++ linker
- /LTCG linker option
- -LTCG linker option
- LTCG linker option
ms.assetid: 788c6f52-fdb8-40c2-90af-4026ea2cf2e2
ms.openlocfilehash: a8f13c32593d1cfef690d63d506faf14490de02d
ms.sourcegitcommit: a10c9390413978d36b8096b684d5ed4cf1553bc8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2019
ms.locfileid: "65837264"
---
# <a name="ltcg-link-time-code-generation"></a>/LTCG (geração de código do tempo de vinculação)

Use **/LTCG** para executar a otimização do programa inteiro ou, para criar a instrumentação do PGO (otimização guiada por perfil), execute o treinamento e crie builds com otimização guiada por perfil.

## <a name="syntax"></a>Sintaxe

> **/LTCG**[**:**{**INCREMENTAL**|**NOSTATUS**|**STATUS**|**OFF**}]<br/>

Estas opções foram preteridas no Visual Studio 2015 em diante:

> **/LTCG:**{**PGINSTRUMENT**|**PGOPTIMIZE**|**PGUPDATE**}<br/>

### <a name="arguments"></a>Arguments

**INCREMENTAL**<br/>
(Opcional) Especifica que o vinculador só aplica a otimização do programa inteiro ou a LTCG (Geração de Código Durante o Tempo de Vinculação) ao conjunto de arquivos afetado por uma edição, em vez de todo o projeto. Por padrão, esse sinalizador não é definido quando **/LTCG** é especificado e todo o projeto é vinculado usando a otimização do programa inteiro.

**NOSTATUS** &#124; **STATUS**<br/>
(Opcional) Especifica se o vinculador exibe um indicador de progresso que mostra o percentual concluído da vinculação. Por padrão, essas informações de status não são exibidas.

**OFF**<br/>
(Opcional) Desabilita a Geração de Código Durante o Tempo de Vinculação. Esse comportamento é o mesmo que quando **/LTCG** não é especificado na linha de comando.

**PGINSTRUMENT**<br/>
(Opcional) Essa opção foi preterida no Visual Studio 2015 em diante. Em vez disso, use **/LTCG** e [/GENPROFILE ou /FASTGENPROFILE](genprofile-fastgenprofile-generate-profiling-instrumented-build.md) para gerar um build instrumentado para a otimização guiada por perfil. Os dados coletados de execuções instrumentadas são usados para criar uma imagem otimizada. Para obter mais informações, confira [Otimizações guiadas por perfil](../profile-guided-optimizations.md). A forma abreviada dessa opção é **/LTCG:PGI**.

**PGOPTIMIZE**<br/>
(Opcional) Essa opção foi preterida no Visual Studio 2015 em diante. Em vez disso, use **/LTCG** e [/USEPROFILE](useprofile.md) para compilar uma imagem otimizada. Para obter mais informações, confira [Otimizações guiadas por perfil](../profile-guided-optimizations.md). A forma abreviada dessa opção é **/LTCG:PGO**.

**PGUPDATE**<br/>
(Opcional) Essa opção foi preterida no Visual Studio 2015 em diante. Em vez disso, use **/LTCG** e **/USEPROFILE** para recompilar uma imagem otimizada. Para obter mais informações, confira [Otimizações guiadas por perfil](../profile-guided-optimizations.md). A forma abreviada dessa opção é **/LTCG:PGU**.

## <a name="remarks"></a>Comentários

A opção **/LTCG** instrui o vinculador a chamar o compilador e executar a otimização do programa inteiro. Faça também uma otimização guiada por perfil. Para obter mais informações, confira [Otimizações guiadas por perfil](../profile-guided-optimizations.md).

Com as seguintes exceções, não é possível adicionar opções do vinculador à combinação do PGO **/LTCG** e **/USEPROFILE** que não foram especificadas na combinação anterior de inicialização do PGO das opções **/LTCG** e **/GENPROFILE**:

- [/BASE](base-base-address.md)

- [/FIXED](fixed-fixed-base-address.md)

- **/LTCG**

- [/MAP](map-generate-mapfile.md)

- [/MAPINFO](mapinfo-include-information-in-mapfile.md)

- [/NOLOGO](nologo-suppress-startup-banner-linker.md)

- [/OUT](out-output-file-name.md)

- [/PGD](pgd-specify-database-for-profile-guided-optimizations.md)

- [/PDB](pdb-use-program-database.md)

- [/PDBSTRIPPED](pdbstripped-strip-private-symbols.md)

- [/STUB](stub-ms-dos-stub-file-name.md)

- [/VERBOSE](verbose-print-progress-messages.md)

As opções do vinculador especificadas junto com as opções **/LTCG** e **/GENPROFILE** para inicializar o PGO não precisam ser especificadas durante o build com **/LTCG** e **/USEPROFILE**; elas ficam implícitas.

O restante deste artigo aborda a opção **/LTCG** em termos da Geração de Código Durante o Tempo de Vinculação.

A opção **/LTCG** fica implícita com [/GL](gl-whole-program-optimization.md).

O vinculador invoca a Geração de Código Durante o Tempo de Vinculação se ele recebe um módulo que foi compilado usando **/GL** ou um módulo da MSIL (confira [Arquivos .netmodule como entrada do vinculador](netmodule-files-as-linker-input.md)). Se você não especificar explicitamente **/LTCG** quando passar **/GL** ou módulos da MSIL para o vinculador, o vinculador acabará detectando isso e reiniciará a vinculação usando **/LTCG**. Especifique explicitamente **/LTCG** quando você passar **/GL** e os módulos da MSIL para o vinculador a fim de obter o desempenho de build mais rápido possível.

Para obter um desempenho ainda mais rápido, use **/LTCG:INCREMENTAL**. Essa opção instrui o vinculador a só otimizar novamente o conjunto de arquivos afetado por uma alteração no arquivo de origem, em vez do projeto inteiro. Isso pode reduzir consideravelmente o tempo de vinculação necessário. Essa não é a mesma opção que a vinculação incremental.

A opção **/LTCG** não é válida para uso com [/INCREMENTAL](incremental-link-incrementally.md).

Quando a opção **/LTCG** é usada para vincular os módulos compilados usando [/Og](og-global-optimizations.md), [/O1](o1-o2-minimize-size-maximize-speed.md), [/O2](o1-o2-minimize-size-maximize-speed.md) ou [/Ox](ox-full-optimization.md), as seguintes otimizações são executadas:

- Inlining entre módulos

- Alocação de registro entre procedimentos (somente sistemas operacionais de 64 bits)

- Convenção de chamada personalizada (somente x86)

- Pequeno deslocamento do TLS (somente x86)

- Alinhamento duplo de pilha (somente x86)

- Desambiguidade de memória aprimorada (melhores informações de interferência para variáveis globais e parâmetros de entrada)

> [!NOTE]
> O vinculador determina quais otimizações foram usadas para compilar cada função e aplica as mesmas otimizações durante o tempo de vinculação.

O uso de **/LTCG** e **/Ogt** gera a otimização de alinhamento duplo.

Se **/LTCG** e **/Ogs** forem especificados, o alinhamento duplo não será executado. Se a maioria das funções de um aplicativo for compilada para velocidade, com algumas funções compiladas para tamanho (por exemplo, usando o pragma [otimize](../../preprocessor/optimize.md)), o compilador fará o alinhamento duplo das funções que são otimizadas para tamanho, caso elas chamem funções que exijam o alinhamento duplo.

Se o compilador puder identificar todos os sites de chamada de uma função, o compilador ignorará os modificadores de convenção de chamada explícitos em uma função e tentará otimizar a convenção de chamada da função:

- passar parâmetros em registros

- reordenar parâmetros quanto ao alinhamento

- remover parâmetros não usados

Se uma função for chamada por meio de um ponteiro de função ou se uma função for chamada fora de um módulo que é compilado usando **/GL**, o compilador não tentará otimizar a convenção de chamada da função.

> [!NOTE]
> Se você usar **/LTCG** e redefinir `mainCRTStartup`, o aplicativo poderá ter um comportamento imprevisível relacionado ao código do usuário que é executado antes da inicialização dos objetos globais. Há três maneiras de resolver esse problema: não redefinir `mainCRTStartup`, não compilar o arquivo que contém `mainCRTStartup` usando **/LTCG** ou inicializar objetos e variáveis globais estaticamente.

### <a name="ltcg-and-msil-modules"></a>/LTCG e módulos da MSIL

Os módulos que são compilados usando [/GL](gl-whole-program-optimization.md) e [/clr](clr-common-language-runtime-compilation.md) poderão ser usados como entrada para o vinculador quando **/LTCG** for especificado.

- **/LTCG** pode aceitar arquivos-objeto nativos e arquivos-objeto nativos/gerenciados mistos (compilados usando **/clr**). As opções do compilador **/clr:pure** e **/clr:safe** foram preteridas no Visual Studio 2015 e estão sem suporte no Visual Studio 2017 e posterior.

- **/LTCG:PGI** não aceita módulos nativos compilados usando **/GL** e **/clr**

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **Propriedades da Configuração** > **Geral**.

1. Modifique a propriedade **Otimização do Programa Inteiro**.

Aplique também **/LTCG** a builds específicos escolhendo **Build** > **Otimização Guiada por Perfil** na barra de menus ou escolhendo uma das opções de otimização guiada por perfil no menu de atalho do projeto.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.LinkTimeCodeGeneration%2A>.

## <a name="see-also"></a>Consulte também

- [Referência de vinculador MSVC](linking.md)
- [Opções de vinculador MSVC](linker-options.md)
