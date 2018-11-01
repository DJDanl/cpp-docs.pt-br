---
title: /LTCG (geração de código do tempo de vinculação)
ms.date: 03/14/2018
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
ms.openlocfilehash: 68c12cc7666da489870da1cacacc5053aeca5b51
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50523208"
---
# <a name="ltcg-link-time-code-generation"></a>/LTCG (geração de código do tempo de vinculação)

Use **/LTCG** para executar a otimização de todo o programa, ou crie a instrumentação de Otimização Guiada por perfil (PGO), execute o treinamento e criar guiada por perfil otimizado compilações.

## <a name="syntax"></a>Sintaxe

> **/LTCG**[**:**{**INCREMENTAL**|**NOSTATUS**|**STATUS**|**OFF**}]<br/>

Essas opções são preteridas a partir do Visual Studio 2015:

> **/LTCG:**{**PGINSTRUMENT**|**PGOPTIMIZE**|**PGUPDATE**}<br/>

### <a name="arguments"></a>Arguments

**INCREMENTAL**<br/>
(Opcional) Especifica que o vinculador só se aplica todo o programa otimização ou tempo de vinculação a geração de código (LTCG) ao conjunto de arquivos afetados por uma edição, em vez de todo o projeto. Por padrão, esse sinalizador não é definido quando **/LTCG** for especificado, e todo o projeto está vinculado usando a otimização de programa inteiro.

**NOSTATUS** &AMP;#124; **STATUS**<br/>
(Opcional) Especifica se o vinculador exibe um indicador de progresso que mostra qual é a porcentagem do link for concluída. Por padrão, essas informações de status não são exibidas.

**OFF**<br/>
(Opcional) Desabilita a geração de código para link-time. Esse comportamento é o mesmo que quando **/LTCG** não for especificado na linha de comando.

**PGINSTRUMENT**<br/>
(Opcional) Essa opção é preterida a partir do Visual Studio 2015. Em vez disso, use **/LTCG** e [/GENPROFILE ou /FASTGENPROFILE](genprofile-fastgenprofile-generate-profiling-instrumented-build.md) para gerar um build instrumentado para Otimização Guiada por perfil. Os dados que são coletados de execuções instrumentadas são usados para criar uma imagem otimizada. Para obter mais informações, consulte [Otimização Guiada por perfil](profile-guided-optimizations.md). A forma abreviada dessa opção é **/ltcg: pgi**.

**PGOPTIMIZE**<br/>
(Opcional) Essa opção é preterida a partir do Visual Studio 2015. Em vez disso, use **/LTCG** e [/USEPROFILE](useprofile.md) para criar uma imagem otimizada. Para obter mais informações, consulte [Otimização Guiada por perfil](../../build/reference/profile-guided-optimizations.md). A forma abreviada dessa opção é **/ltcg: PGO**.

**PGUPDATE**<br/>
(Opcional) Essa opção é preterida a partir do Visual Studio 2015. Em vez disso, use **/LTCG** e **/USEPROFILE** para recriar uma imagem otimizada. Para obter mais informações, consulte [Otimização Guiada por perfil](../../build/reference/profile-guided-optimizations.md). A forma abreviada dessa opção é **/ltcg: pgu**.

## <a name="remarks"></a>Comentários

O **/LTCG** opção instrui o vinculador para chamar o compilador e executará a otimização de programa inteiro. Você também pode fazer Otimização Guiada por perfil. Para obter mais informações, consulte [Otimização Guiada por perfil](../../build/reference/profile-guided-optimizations.md).

Com as seguintes exceções, você não pode adicionar opções de vinculador à combinação de PGO **/LTCG** e **/USEPROFILE** que não foram especificadas na combinação de inicialização de PGO anterior dos  **/LTCG** e **/GENPROFILE** opções:

- [/BASE](../../build/reference/base-base-address.md)

- [/FIXED](../../build/reference/fixed-fixed-base-address.md)

- **/LTCG**

- [/MAP](../../build/reference/map-generate-mapfile.md)

- [/MAPINFO](../../build/reference/mapinfo-include-information-in-mapfile.md)

- [/NOLOGO](../../build/reference/nologo-suppress-startup-banner-linker.md)

- [/ ENTRADA SAÍDA](../../build/reference/out-output-file-name.md)

- [/PGD](../../build/reference/pgd-specify-database-for-profile-guided-optimizations.md)

- [/PDB](../../build/reference/pdb-use-program-database.md)

- [/PDBSTRIPPED](../../build/reference/pdbstripped-strip-private-symbols.md)

- [/STUB](../../build/reference/stub-ms-dos-stub-file-name.md)

- [/VERBOSE](../../build/reference/verbose-print-progress-messages.md)

Qualquer opção de vinculador que é especificadas junto com o **/LTCG** e **/GENPROFILE** opções para inicializar a PGO não precisa ser especificado quando você compila usando **/LTCG** e **/USEPROFILE**; eles são deduzidos.

O restante deste artigo discute **/LTCG** em termos de geração de código para link-time.

**/LTCG** é implícita com [/GL](../../build/reference/gl-whole-program-optimization.md).

O vinculador invoca geração de código para link-time, se ele é passado um módulo que foi compilado usando **/GL** ou um módulo MSIL (consulte [arquivos. netmodule como entrada de vinculador](../../build/reference/netmodule-files-as-linker-input.md)). Se você não especificar explicitamente **/LTCG** quando você passa **/GL** ou módulos MSIL para o vinculador, eventualmente, o vinculador detecta isso e reinicia o link **/LTCG**. Especificar explicitamente **/LTCG** quando você passa **/GL** e desempenho de compilação de módulos MSIL para o vinculador para o mais rápido possível.

Para desempenho mais rápido, use **/LTCG: INCREMENTAL**. Essa opção instrui o vinculador só otimizar novamente o conjunto de arquivos que é afetado por uma alteração de arquivo de origem, em vez de todo o projeto. Isso pode reduzir significativamente o tempo de link necessário. Isso não é a mesma opção como vinculação incremental.

**/LTCG** não é válido para uso com [/incremental](../../build/reference/incremental-link-incrementally.md).

Quando **/LTCG** é usado para vincular os módulos compilados usando [/Og](../../build/reference/og-global-optimizations.md), [/O1](../../build/reference/o1-o2-minimize-size-maximize-speed.md), [/O2](../../build/reference/o1-o2-minimize-size-maximize-speed.md), ou [/Ox](../../build/reference/ox-full-optimization.md), o as seguintes otimizações são executadas:

- Inlining entre módulos

- Alocação de registro entre procedimentos (apenas sistemas de operacionais de 64 bits)

- Convenção de chamada personalizada (somente x86)

- Deslocamento de TLS pequeno (somente x86)

- Alinhamento de pilha duplo (somente x86)

- Desambiguidade de memória aprimorado (melhor informações interferência para variáveis globais e os parâmetros de entrada)

> [!NOTE]
> O vinculador determina quais otimizações foram usadas para compilar cada função e aplica as mesmas otimizações em tempo de vinculação.

Usando o **/LTCG** e **/Ogt** faz com que a otimização de alinhamento de double.

Se **/LTCG** e **/Ogs** forem especificados, alinhamento duplo não é executado. Se a maioria das funções em um aplicativo é compilada para velocidade, com algumas funções compiladas para o tamanho (por exemplo, usando o [otimizar](../../preprocessor/optimize.md) pragma), o compilador dupla alinha as funções que são otimizadas para tamanho, se eles chamam funções que exigem o alinhamento de double.

Se o compilador pode identificar todos os sites de chamada de uma função, o compilador ignora modificadores de convenção de chamada explícitas em uma função e tenta otimizar a convenção de chamada da função:

- passar parâmetros em registros

- reordenar parâmetros para o alinhamento

- remover parâmetros não utilizados

Se uma função é chamada por meio de um ponteiro de função, ou se uma função é chamada de fora de um módulo que é compilado usando **/GL**, o compilador não tenta otimizar a convenção de chamada da função.

> [!NOTE]
> Se você usar **/LTCG** e redefinir `mainCRTStartup`, seu aplicativo pode ter um comportamento imprevisível se relaciona com o código do usuário que é executado antes que os objetos globais são inicializados. Há três maneiras de resolver esse problema: não redefinem `mainCRTStartup`, não são compilados para o arquivo que contém `mainCRTStartup` usando **/LTCG**, ou inicializar variáveis globais e objetos estaticamente.

### <a name="ltcg-and-msil-modules"></a>/LTCG e módulos MSIL

Módulos que são compilados usando [/GL](../../build/reference/gl-whole-program-optimization.md) e [/clr](../../build/reference/clr-common-language-runtime-compilation.md) pode ser usado como entrada para o vinculador quando **/LTCG** for especificado.

- **/LTCG** pode aceitar arquivos de objeto nativo e arquivos de objeto nativo/gerenciado misto (compiladas usando **/clr**). O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

- **/Ltcg: pgi** não aceita módulos nativos compilados usando **/GL** e **/clr**

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra o projeto **páginas de propriedade** caixa de diálogo. Ver [trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **geral** página de propriedades.

1. Modificar a **otimização de programa inteiro** propriedade.

Você também pode aplicar **/LTCG** para compilações específicas, escolhendo **compilação** > **Otimização Guiada por perfil** na barra de menus ou escolhendo um do perfil Opções de otimização guiadas no menu de atalho para o projeto.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.LinkTimeCodeGeneration%2A>.

## <a name="see-also"></a>Consulte também

- [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)
- [Opções do vinculador](../../build/reference/linker-options.md)
