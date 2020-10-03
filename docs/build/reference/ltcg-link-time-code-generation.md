---
title: /LTCG (geração de código do tempo de vinculação)
description: A opção de vinculador MSVC/LTCG permite a geração de código em tempo de vinculação para otimização de todo o programa.
ms.date: 07/08/2020
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
ms.openlocfilehash: 6c0009e5236f33119ed411dc81ce6a4385f21a2a
ms.sourcegitcommit: f7fbdc39d73e1fb3793c396fccf7a1602af7248b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/02/2020
ms.locfileid: "91662260"
---
# <a name="ltcg-link-time-code-generation"></a>`/LTCG` (Geração de código em tempo de vinculação)

Use **`/LTCG`** para executar a otimização de todo o programa ou para criar a instrumentação de PGO (otimização guiada por perfil), executar treinamento e criar compilações otimizadas guiadas por perfil.

## <a name="syntax"></a>Syntax

> **`/LTCG`**[**`:`**{**`INCREMENTAL`**|**`NOSTATUS`**|**`STATUS`**|**`OFF`**}]

Estas opções foram preteridas no Visual Studio 2015 em diante:

> **`/LTCG:`**{**`PGINSTRUMENT`**|**`PGOPTIMIZE`**|**`PGUPDATE`**}

### <a name="arguments"></a>Argumentos

**`INCREMENTAL`**<br/>
Adicional Especifica que o vinculador só aplica otimização de programa completa ou geração de código de tempo de vinculação (LTCG) a arquivos afetados por uma edição, em vez de todo o projeto. Por padrão, esse sinalizador não é definido quando **`/LTCG`** é especificado, e todo o projeto é vinculado usando a otimização de programa inteira.

**`NOSTATUS`** &#124; **`STATUS`**<br/>
(Opcional) Especifica se o vinculador exibe um indicador de progresso que mostra o percentual concluído da vinculação. Por padrão, essas informações de status não são exibidas.

**`OFF`**<br/>
(Opcional) Desabilita a Geração de Código Durante o Tempo de Vinculação. Esse comportamento é o mesmo que quando **`/LTCG`** não está especificado na linha de comando.

**`PGINSTRUMENT`**<br/>
(Opcional) Essa opção foi preterida no Visual Studio 2015 em diante. Em vez disso, use **`/LTCG`** and [ `/GENPROFILE` `/FASTGENPROFILE` ou](genprofile-fastgenprofile-generate-profiling-instrumented-build.md) para gerar uma compilação instrumentada para otimização guiada por perfil. Os dados coletados de execuções instrumentadas são usados para criar uma imagem otimizada. Para obter mais informações, confira [Otimizações guiadas por perfil](../profile-guided-optimizations.md). A forma abreviada dessa opção é **`/LTCG:PGI`** .

**`PGOPTIMIZE`**<br/>
(Opcional) Essa opção foi preterida no Visual Studio 2015 em diante. Em vez disso, use **`/LTCG`** e  [`/USEPROFILE`](useprofile.md) para criar uma imagem otimizada. Para obter mais informações, confira [Otimizações guiadas por perfil](../profile-guided-optimizations.md). A forma abreviada dessa opção é **`/LTCG:PGO`** .

**`PGUPDATE`**<br/>
(Opcional) Essa opção foi preterida no Visual Studio 2015 em diante. Em vez disso, use **`/LTCG`** e  **`/USEPROFILE`** para recriar uma imagem otimizada. Para obter mais informações, confira [Otimizações guiadas por perfil](../profile-guided-optimizations.md). A forma abreviada dessa opção é **`/LTCG:PGU`** .

## <a name="remarks"></a>Comentários

A **`/LTCG`** opção informa o vinculador para chamar o compilador e executar a otimização de todo o programa. Faça também uma otimização guiada por perfil. Para obter mais informações, confira [Otimizações guiadas por perfil](../profile-guided-optimizations.md).

Com as exceções a seguir, você não pode adicionar opções de vinculador à combinação de PGO de **`/LTCG`** e **`/USEPROFILE`** que não foram especificadas na combinação de opções e de inicialização de PGO anteriores **`/LTCG`** **`/GENPROFILE`** :

- [`/BASE`](base-base-address.md)

- [`/FIXED`](fixed-fixed-base-address.md)

- **`/LTCG`**

- [`/MAP`](map-generate-mapfile.md)

- [`/MAPINFO`](mapinfo-include-information-in-mapfile.md)

- [`/NOLOGO`](nologo-suppress-startup-banner-linker.md)

- [`/OUT`](out-output-file-name.md)

- [`/PGD`](pgd-specify-database-for-profile-guided-optimizations.md)

- [`/PDB`](pdb-use-program-database.md)

- [`/PDBSTRIPPED`](pdbstripped-strip-private-symbols.md)

- [`/STUB`](stub-ms-dos-stub-file-name.md)

- [`/VERBOSE`](verbose-print-progress-messages.md)

Qualquer opção do vinculador que é especificada junto com **`/LTCG`** as **`/GENPROFILE`** Opções e para inicializar PGO não precisa ser especificada quando você cria usando **`/LTCG`** e **`/USEPROFILE`** ; elas estão implícitas.

O restante deste artigo aborda a geração de código de tempo de vinculação feita pelo **`/LTCG`** .

**`/LTCG`** está implícito em [`/GL`](gl-whole-program-optimization.md) .

O vinculador invoca a geração de código em tempo de vinculação se for passado um módulo que foi compilado usando o **`/GL`** ou um módulo MSIL (consulte [ `.netmodule` arquivos como entrada de vinculador](netmodule-files-as-linker-input.md)). Se você não especificar explicitamente **`/LTCG`** quando passa **`/GL`** ou os módulos MSIL para o vinculador, o vinculador eventualmente detectará essa situação e reiniciará o link usando **`/LTCG`** . Especifique explicitamente **`/LTCG`** quando passar **`/GL`** os módulos MSIL para o vinculador para o desempenho de compilação mais rápido possível.

Para um desempenho ainda mais rápido, use **`/LTCG:INCREMENTAL`** . Essa opção informa o vinculador para reotimizar apenas os arquivos afetados por uma alteração de arquivo de origem, em vez de todo o projeto. Essa opção pode reduzir significativamente o tempo de conexão necessário. Essa opção não é a mesma opção que a [vinculação incremental](incremental-link-incrementally.md).

**`/LTCG`** Não é válido para uso com [`/INCREMENTAL`](incremental-link-incrementally.md) .

Quando **`/LTCG`** é usado para vincular módulos compilados usando [`/Og`](og-global-optimizations.md) , [`/O1`](o1-o2-minimize-size-maximize-speed.md) , [`/O2`](o1-o2-minimize-size-maximize-speed.md) ou [`/Ox`](ox-full-optimization.md) , as seguintes otimizações são executadas:

- Inlining entre módulos

- Alocação de registro entre procedimentos (somente sistemas operacionais de 64 bits)

- Convenção de chamada personalizada (somente x86)

- Pequeno deslocamento do TLS (somente x86)

- Alinhamento duplo de pilha (somente x86)

- Desambiguidade de memória aprimorada (melhores informações de interferência para variáveis globais e parâmetros de entrada)

> [!NOTE]
> O vinculador determina quais otimizações foram usadas para compilar cada função e aplica as mesmas otimizações durante o tempo de vinculação.

Usar **`/LTCG`** e **`/O2`** causa otimização de alinhamento duplo.

Se **`/LTCG`** e **`/O1`** forem especificados, o alinhamento duplo não será executado. Se a maioria das funções em um aplicativo for compilada para velocidade, com algumas funções compiladas para tamanho (por exemplo, usando o [`optimize`](../../preprocessor/optimize.md) pragma), o compilador alinhará duas vezes as funções otimizadas para tamanho se elas chamarem funções que exigem alinhamento duplo.

Se o compilador puder identificar todos os sites de chamada de uma função, o compilador ignorará os modificadores de convenção de chamada explícitos em uma função e tentará otimizar a convenção de chamada da função:

- passar parâmetros em registros

- reordenar parâmetros quanto ao alinhamento

- remover parâmetros não usados

Se uma função for chamada por meio de um ponteiro de função, ou se uma função for chamada de fora de um módulo que é compilado usando **`/GL`** , o compilador não tentará otimizar a Convenção de chamada da função.

> [!NOTE]
> Se você usar **`/LTCG`** e redefinir `mainCRTStartup` , seu aplicativo poderá ter um comportamento imprevisível relacionado ao código do usuário que é executado antes que os objetos globais sejam inicializados. Há três maneiras de resolver esse problema: não redefina, não `mainCRTStartup` compile o arquivo que contém `mainCRTStartup` usando **`/LTCG`** ou inicialize variáveis e objetos globais de forma estática.

### <a name="ltcg-and-msil-modules"></a>`/LTCG` e módulos MSIL

Módulos que são compilados usando [`/GL`](gl-whole-program-optimization.md) e [`/clr`](clr-common-language-runtime-compilation.md) podem ser usados como entrada para o vinculador quando **`/LTCG`** é especificado.

- **`/LTCG`** pode aceitar arquivos de objeto nativo e arquivos de objeto nativos/gerenciados mistos (compilados usando o **`/clr`** ). As **`/clr:pure`** **`/clr:safe`** Opções de compilador e são preteridas no visual Studio 2015 e sem suporte no visual Studio 2017 e versões posteriores.

- **`/LTCG:PGI`** Não aceita Módulos nativos compilados usando o **`/GL`** e o **`/clr`**

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade**geral** de propriedades de configuração.

1. Modifique a propriedade **Otimização do Programa Inteiro**.

Você também pode aplicar **`/LTCG`** a compilações específicas escolhendo **Build**a  >  **otimização guiada do perfil** de compilação na barra de menus ou escolhendo uma das opções de Otimização Guiada por perfil no menu de atalho do projeto.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.LinkTimeCodeGeneration%2A>.

## <a name="see-also"></a>Consulte também

[Referência do vinculador MSVC](linking.md)\
[Opções de vinculador MSVC](linker-options.md)
