---
title: 'Páginas de propriedade HLSL: Geral'
ms.date: 11/04/2016
f1_keywords:
- VC.Project.FXCompilerTool.ShaderModel
- VC.Project.FXCompilerTool.PreprocessorDefinitions
- VC.Project.FXCompilerTool.ShaderType
- VC.Project.FXCompilerTool.EnableDebuggingInformation
- VC.Project.FXCompilerTool.AdditionalIncludeDirectories
- VC.Project.FXCompilerTool.DisableOptimizations
- VC.Project.FXCompilerTool.EntryPointName
ms.assetid: 0e02f2a6-f123-43da-b04b-a0719a7c2b03
ms.openlocfilehash: 0fce8a3b2a43cf05024a028a9e3325a929922abb
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824248"
---
# <a name="hlsl-property-pages-general"></a>Páginas de propriedade HLSL: Geral

Para configurar as propriedades a seguir do compilador HLSL (fxc.exe), use a página de propriedades **Geral**. Para obter informações sobre como acessar o **gerais** página de propriedades na pasta HLSL, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

## <a name="uielement-list"></a>Lista UIElement

- **Diretórios de Inclusão Adicionais**

   Adiciona um ou mais diretórios ao caminho de inclusão. Use ponto-e-vírgula para separar os diretórios.

Essa propriedade corresponde ao argumento de linha de comando **/I[path]**.

- **Nome do Ponto de Entrada**

   Especifica o ponto de entrada para o sombreador. Por padrão, o valor é **main**.

Essa propriedade corresponde ao argumento de linha de comando **/E[name]**.

- **Desabilitar Otimizações**

   **Sim (/Od)** para desabilitar as otimizações; caso contrário, **Não**. Por padrão, o valor é **Sim (/Od)** para configurações de **Depuração** e **Não** para configurações de **Versão**.

O argumento de linha de comando **/Od** para o compilador HLSL aplica implicitamente o argumento de linha de comando **/Gfp**, mas a saída pode não ser idêntica à saída produzida ao passar os argumentos de linha de comando **/Od** e **/Gfp** explicitamente.

- **Habilitar Informações de Depuração**

   **Sim (/Zi)** para habilitar as informações de depuração; caso contrário, **Não**. Por padrão, o valor é **Sim (/Zi)** para configurações de **Depuração** e **Não** para configurações de **Versão**.

- **Tipo de Sombreador**

   Especifica o tipo de sombreador. Diferentes tipos de sombreadores implementam diferentes partes do pipeline gráfico. Alguns tipos de sombreadores estão disponíveis apenas em modelos de sombreador mais recentes (que são especificados pela propriedade **Modelo de Sombreador**) – por exemplo, sombreadores de computação foram introduzidos no modelo de sombreador 5.

   Essa propriedade corresponde à parte **\[type]** do argumento de linha de comando **/T \[type]_\[model]** para o compilador HLSL. A propriedade **Modelos de Sombreador** especifica a parte **[model]** do argumento.

- **Modelo de Sombreador**

   Especifica o modelo de sombreador. Diferentes modelos de sombreador têm diferentes funcionalidades. Em geral, modelos de sombreador mais recentes oferecem funcionalidades expandidas, mas exigem um hardware de elementos gráficos mais moderno para executar o código do sombreador. Alguns tipos de sombreadores (que são especificados pela propriedade **Tipo de Sombreador**) estão disponíveis apenas em modelos de sombreador mais recentes – por exemplo, sombreadores de computação foram introduzidos no modelo de sombreador 5.

   Essa propriedade corresponde à parte **\[model]** do argumento de linha de comando **/T \[type]_\[model]** para o compilador HLSL. A propriedade **Tipo de Sombreador** especifica a parte **[type]** do argumento.

- **Definições de Pré-processador**

   Adiciona uma ou mais definições de símbolo do pré-processador a serem aplicadas ao arquivo de código-fonte HLSL. Use ponto-e-vírgula para separar as definições de símbolo.

   Essa propriedade corresponde ao argumento de linha de comando **/D \[definitions]** para o compilador HLSL.

## <a name="see-also"></a>Consulte também

[Páginas de propriedade HLSL](hlsl-property-pages.md)<br>
[Páginas de propriedades de HLSL: avançado](hlsl-property-pages-advanced.md)<br>
[Páginas de propriedades de HLSL: arquivos de saída](hlsl-property-pages-output-files.md)
