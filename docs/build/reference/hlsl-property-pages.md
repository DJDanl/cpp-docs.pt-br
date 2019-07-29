---
title: Páginas de propriedade HLSL
ms.date: 07/24/2019
ms.assetid: 0c65f5ec-a2a5-4f5b-8d4c-fa57113a5a1d
f1_keywords:
- VC.Project.FXCompilerTool.AdditionalIncludeDirectories
- VC.Project.FXCompilerTool.SuppressStartupBanner
- VC.Project.FXCompilerTool.EntryPointName
- VC.Project.FXCompilerTool.TreatWarningAsError
- VC.Project.FXCompilerTool.DisableOptimizations
- VC.Project.FXCompilerTool.EnableDebuggingInformation
- VC.Project.FXCompilerTool.ShaderType
- VC.Project.FXCompilerTool.ShaderModel
- VC.Project.FXCompilerTool.AllResourcesBound
- VC.Project.FXCompilerTool.EnableUnboundedDescriptorTables
- VC.Project.FXCompilerTool.SetRootSignature
- VC.Project.FXCompilerTool.PreprocessorDefinitions
- VC.Project.FXCompilerTool.AdditionalOptionsPage
- VC.Project.FXCompilerTool.VariableName
- VC.Project.FXCompilerTool.HeaderFileOutput
- VC.Project.FXCompilerTool.ObjectFileOutput
- VC.Project.FXCompilerTool.AssemblerOutput
- VC.Project.FXCompilerTool.AssemblerOutputFile
- VC.Project.FXCompilerTool.CompileD2DCustomEffect
- VC.Project.FXCompilerTool.MultiProcFXC
ms.openlocfilehash: a45ae433e5adaa8aeaf32215d4af7ad0a247af04
ms.sourcegitcommit: 720b74dddb1cdf4e570d55103158304ee1df81f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/29/2019
ms.locfileid: "68606403"
---
# <a name="hlsl-compiler-property-pages"></a>Páginas de propriedades do compilador HLSL

Use as páginas de propriedades do compilador HLSL (fxc.exe) para configurar como os arquivos individuais do sombreador HLSL são criados. Você também pode especificar argumentos de linha de comando para o compilador HLSL usando a propriedade **Opções adicionais** da página de propriedades de **linha de comando** ; Isso inclui argumentos que não podem ser configurados usando outras propriedades das páginas de propriedades HLSL. Para obter informações sobre o compilador HLSL, confira [Ferramenta Compilador de Efeitos](https://go.microsoft.com/fwlink/p/?LinkID=258285&clcid=0x409)

## <a name="hlsl-general-property-page"></a>Página de propriedades geral do HLSL

### <a name="additional-include-directories"></a>Diretórios de Inclusão Adicionais

Especifica um ou mais diretórios a serem adicionados ao caminho de inclusão, separados por ponto e vírgula no caso de mais de um. (/I [caminho])

### <a name="entrypoint-name"></a>Nome do ponto de entrada

Especifica o nome do ponto de entrada para o sombreador (/E [name])

### <a name="disable-optimizations"></a>Desabilitar otimizações

**Sim (/Od)** para desabilitar as otimizações; caso contrário, **Não**. Por padrão, o valor é **Sim (/Od)** para configurações de **Depuração** e **Não** para configurações de **Versão**.

O argumento de linha de comando **/Od** para o compilador HLSL aplica implicitamente o argumento de linha de comando **/Gfp**, mas a saída pode não ser idêntica à saída produzida ao passar os argumentos de linha de comando **/Od** e **/Gfp** explicitamente.

### <a name="enable-debugging-information"></a>Habilitar informações de depuração

**Sim (/Zi)** para habilitar as informações de depuração; caso contrário, **Não**. Por padrão, o valor é **Sim (/Zi)** para configurações de **Depuração** e **Não** para configurações de **Versão**.

### <a name="shader-type"></a>Tipo de sombreador

Especifica o tipo de sombreador. Diferentes tipos de sombreadores implementam diferentes partes do pipeline gráfico. Alguns tipos de sombreadores estão disponíveis apenas em modelos de sombreador mais recentes (que são especificados pela propriedade **Modelo de Sombreador**) – por exemplo, sombreadores de computação foram introduzidos no modelo de sombreador 5.

Essa propriedade corresponde à parte **\[type]** do argumento de linha de comando **/T \[type]_\[model]** para o compilador HLSL. A propriedade **Modelos de Sombreador** especifica a parte **[model]** do argumento.

**Durante**

- **Effect**
- **Sombreador de vértice**
- **Sombreador de pixel**
- **Sombreador de geometria**
- **Sombreador envoltória**
- **Sombreador de domínio**
- **Sombreador de computação**
- **Library**
- **Gerar objeto de assinatura de raiz**

### <a name="shader-model"></a>Modelo de sombreador

Especifica o modelo de sombreador. Diferentes modelos de sombreador têm diferentes funcionalidades. Em geral, modelos de sombreador mais recentes oferecem funcionalidades expandidas, mas exigem um hardware de elementos gráficos mais moderno para executar o código do sombreador. Alguns tipos de sombreadores (que são especificados pela propriedade **Tipo de Sombreador**) estão disponíveis apenas em modelos de sombreador mais recentes – por exemplo, sombreadores de computação foram introduzidos no modelo de sombreador 5.

Essa propriedade corresponde à parte **\[model]** do argumento de linha de comando **/T \[type]_\[model]** para o compilador HLSL. A propriedade **Tipo de Sombreador** especifica a parte **[type]** do argumento.

### <a name="all-resources-bound"></a>Todos os recursos associados

O compilador assumirá que todos os recursos que um sombreador pode referenciar estão associados e que estão em bom estado para a duração da execução do sombreador (/all_resources_bound). Disponível para Shader Model 5.1 e posterior.

### <a name="enable-unbounded-descriptor-tables"></a>Habilitar tabelas de descritor não associado

Informe ao compilador que um sombreador pode conter uma declaração de uma matriz de recursos com intervalo não associado (/enable_unbounded_descriptor_tables). Disponível para Shader Model 5.1 e posterior.

### <a name="set-root-signature"></a>Definir assinatura de raiz

Anexar assinatura de raiz ao código de bytes do sombreador (/setrootsignature). Disponível para Shader Model 5.0 e posterior.

### <a name="preprocessor-definitions"></a>Definições do Pré-processador

Adiciona uma ou mais definições de símbolo do pré-processador a serem aplicadas ao arquivo de código-fonte HLSL. Use ponto-e-vírgula para separar as definições de símbolo.

Essa propriedade corresponde ao argumento de linha de comando **/D \[definitions]** para o compilador HLSL.

### <a name="compile-a-direct2d-custom-pixel-shader-effect"></a>Compilar um efeito de sombreador de pixel personalizado Direct2D

Compile um efeito personalizado Direct2D que contém sombreadores de pixel. Não use um vértice ou efeito personalizado de computação.

### <a name="multi-processor-compilation"></a>Compilação de vários processadores

Execute várias instâncias ao mesmo tempo.

## <a name="advanced-property-page"></a>Página de propriedades avançada

### <a name="suppress-startup-banner"></a>Suprimir Faixa de Inicialização

Suprime a exibição da faixa de inicialização e das mensagens informativas. /nologo

### <a name="treat-warnings-as-errors"></a>Tratar avisos como erros

Trata todos os avisos do compilador como erros. Para um novo projeto, talvez seja melhor usar /WX em todas as compilações. Resolver todos os avisos assegurará o menor número possível de defeitos de código difíceis de localizar.

## <a name="output-files-property-page"></a>Página de propriedades de arquivos de saída

### <a name="header-variable-name"></a>Nome da variável de cabeçalho

Especifica um nome para o nome da variável no arquivo de cabeçalho (/vn [name])

### <a name="header-file-name"></a>Nome do arquivo de cabeçalho

Especifica um nome para um arquivo de cabeçalho que contém código objeto. (/FH [name])

### <a name="object-file-name"></a>Nome do arquivo-objeto

Especifica um nome para o arquivo-objeto. (/Fo [nome])

### <a name="assembler-output"></a>Saída do Assembler

Especifica o conteúdo do arquivo de saída de linguagem assembly. (/FC,/FX)

**Durante**

- **Sem listagem** -sem listagem.
- **Listagem somente de assembly** -arquivo de código de assembly
- **Código do assembly e código hex** -assembly e arquivo de listagem hex

### <a name="assembler-output-file"></a>Arquivo de saída do Assembler

Especifica o nome do arquivo para o arquivo de listagem de código do assembly

## <a name="see-also"></a>Consulte também

[C++referência de página de propriedades do projeto](property-pages-visual-cpp.md)<br>
[Página de propriedades de linha de comando](command-line-property-pages.md)<br>
[Compilando sombreadores](https://go.microsoft.com/fwlink/p/?LinkID=258284&clcid=0x409)
