---
title: C++Avisos de diretrizes principais
ms.date: 10/16/2019
ms.topic: conceptual
ms.assetid: 7c83814a-f21d-4323-ad5f-13bac40d3e38
ms.openlocfilehash: f499374c84973be09e2f02e6d2f2e6d9a6548363
ms.sourcegitcommit: 7bea0420d0e476287641edeb33a9d5689a98cb98
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/17/2020
ms.locfileid: "77418826"
---
# <a name="using-the-c-core-guidelines-checkers"></a>Usando os verificadores de Diretrizes Principais do C++

As C++ diretrizes básicas são um conjunto portátil de diretrizes, regras e práticas recomendadas sobre a codificação C++ criada por C++ especialistas e designers. O Visual Studio atualmente dá suporte a um subconjunto dessas regras como parte de suas ferramentas C++de análise de código para o. Os verificadores de diretriz principais são instalados por padrão no Visual Studio 2017 e no Visual Studio 2019 e estão [disponíveis como um pacote NuGet para o visual studio 2015](#vs2015_corecheck).

## <a name="the-c-core-guidelines-project"></a>O C++ projeto de diretrizes principais

Criado por Bjarne Stroustrup e outros, as C++ principais diretrizes são um guia para usar o C++ moderno de forma segura e eficaz. As diretrizes enfatizam a segurança de tipo estático e a segurança de recursos. Eles identificam maneiras de eliminar ou minimizar as partes mais propensas a erros da linguagem e sugerem como tornar seu código mais simples e mais funcional de maneira confiável. Essas diretrizes são mantidas pela Standard C++ Foundation. Para saber mais, confira a documentação, C++ [ C++ as diretrizes básicas](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)e acesse os arquivos de projeto de documentação das diretrizes principais no [GitHub](https://github.com/isocpp/CppCoreGuidelines).

## <a name="enable-the-c-core-check-guidelines-in-code-analysis"></a>Habilitar as C++ diretrizes de verificação principal na análise de código

Você pode habilitar a análise de código em seu projeto marcando a caixa de seleção **Habilitar análise de código no Build** na seção **análise de código** da caixa de diálogo **páginas de propriedades** do seu projeto.

![Página de propriedades para configurações gerais de análise de código](../code-quality/media/cppcorecheck_codeanalysis_general.png)

As C++ regras de verificação principais são extensões para os conjuntos de regras padrão que são executados quando a análise de código está habilitada. Como as C++ regras de verificação principais estão em desenvolvimento, algumas regras são bem estabelecidas e algumas podem não estar prontas para uso em todo o código, mas ainda podem ser informativas. As regras são divididas em dois grupos: lançado e experimental. Você pode escolher se deseja executar as regras de lançamento ou experimental nas propriedades do seu projeto.

![Página de propriedades para configurações de extensões de análise de código](../code-quality/media/cppcorecheck_codeanalysis_extensions.png)

Para habilitar ou desabilitar os C++ conjuntos de regras de verificação principal, abra a caixa de diálogo **páginas de propriedades** do seu projeto. Em **Propriedades de configuração**, expanda **análise de código**, **extensões**. No controle suspenso ao lado de **habilitar C++ verificação de núcleo (liberado)** ou **habilitar C++ verificação de núcleo (experimental)** , escolha **Sim** ou **não**. Escolha **OK** ou **aplicar** para salvar suas alterações.

## <a name="examples"></a>Exemplos

Veja um exemplo de alguns dos problemas que as regras de C++ verificação principais podem encontrar:

```cpp
// CoreCheckExample.cpp
// Add CppCoreCheck package and enable code analysis in build for warnings.

int main()
{
    int arr[10];           // warning C26494
    int* p = arr;          // warning C26485

    [[gsl::suppress(bounds.1)]] // This attribute suppresses Bounds rule #1
    {
        int* q = p + 1;    // warning C26481 (suppressed)
        p = q++;           // warning C26481 (suppressed)
    }

    return 0;
}
```

Este exemplo demonstra alguns dos avisos que as regras de C++ verificação principais podem encontrar:

- C26494 é o tipo de regra. 5: sempre inicializar um objeto.

- C26485 é associado à regra. 3: nenhum decaimento de matriz para ponteiro.

- C26481 são limites de regra. 1: não use aritmética de ponteiro. Use `span` em vez disso.

Se os C++ conjuntos de regras de análise de código de verificação principal estiverem instalados e habilitados quando você compilar esse código, os dois primeiros avisos serão gerados, mas o terceiro será suprimido. Aqui está a saída da compilação do código de exemplo:

```Output
1>------ Build started: Project: CoreCheckExample, Configuration: Debug Win32 ------
1>  CoreCheckExample.cpp
1>  CoreCheckExample.vcxproj -> C:\Users\username\documents\visual studio 2015\Projects\CoreCheckExample\Debug\CoreCheckExample.exe
1>  CoreCheckExample.vcxproj -> C:\Users\username\documents\visual studio 2015\Projects\CoreCheckExample\Debug\CoreCheckExample.pdb (Full PDB)
c:\users\username\documents\visual studio 2015\projects\corecheckexample\corecheckexample\corecheckexample.cpp(6): warning C26494: Variable 'arr' is uninitialized. Always initialize an object. (type.5: http://go.microsoft.com/fwlink/p/?LinkID=620421)
c:\users\username\documents\visual studio 2015\projects\corecheckexample\corecheckexample\corecheckexample.cpp(7): warning C26485: Expression 'arr': No array to pointer decay. (bounds.3: http://go.microsoft.com/fwlink/p/?LinkID=620415)
========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========
```

As C++ diretrizes básicas estão lá para ajudá-lo a escrever um código melhor e mais seguro. No entanto, se você tiver uma instância em que uma regra ou um perfil não deve ser aplicado, será fácil suprimir diretamente no código. Você pode usar o atributo `gsl::suppress` para impedir C++ que a verificação principal detecte e relate qualquer violação de uma regra no bloco de código a seguir. Você pode marcar instruções individuais para suprimir regras específicas. Você pode até mesmo suprimir todo o perfil de limites escrevendo `[[gsl::suppress(bounds)]]` sem incluir um número de regra específico.

## <a name="supported-rule-sets"></a>Conjuntos de regras com suporte

À medida que novas regras são adicionadas ao verificador de diretrizes C++ principais, o número de avisos produzidos para código pré-existente pode aumentar. Você pode usar conjuntos de regras predefinidos para filtrar quais tipos de regras habilitar. A partir do Visual Studio 2017 versão 15,3, os conjuntos de regras com suporte são:

- **As regras de ponteiro do proprietário** impõem [verificações de gerenciamento de recursos relacionadas ao proprietário C++\<t > das principais diretrizes](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#r-resource-management).

- **As regras const** impõem [verificações relacionadas a C++ const das principais diretrizes](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#con-constants-and-immutability).

- **Regras de ponteiro brutos** impõem [verificações de gerenciamento de recursos relacionadas a C++ ponteiros brutos das diretrizes básicas](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#r-resource-management).

- **Regras de ponteiro exclusivo** impõem [verificações de gerenciamento de recursos relacionadas a tipos com semântica de ponteiro C++ exclusiva das diretrizes básicas](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#r-resource-management).

- **As regras de limites** impõem o [perfil de limites C++ das principais diretrizes](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#probounds-bounds-safety-profile).

- **As regras de tipo** impõem o [perfil C++ de tipo das principais diretrizes](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#prosafety-type-safety-profile).

Você pode optar por limitar os avisos a apenas um ou alguns dos grupos. Os conjuntos de regras **recomendadas** nativas e C++ **mínimas** nativas incluem regras de verificação de núcleo, além de outras verificações PREfast. Para ver os conjuntos de regras disponíveis, abra o diálogo Propriedades do projeto, selecione **código Analysis\General**, abra a lista suspensa na caixa de combinação **conjuntos de regras** e **escolha escolher vários conjuntos de regras**. Para obter mais informações sobre como usar conjuntos de regras no Visual Studio, consulte [usar conjuntos de C++ regras para especificar as regras a serem executadas](using-rule-sets-to-specify-the-cpp-rules-to-run.md) e [usar conjuntos de regras para regras de análise de código de grupo](/visualstudio/code-quality/using-rule-sets-to-group-code-analysis-rules).

## <a name="macros"></a>Macros

O C++ principal verificador de diretrizes vem com um arquivo de cabeçalho que define macros que facilitam a supressão de categorias inteiras de avisos no código:

```cpp
ALL_CPPCORECHECK_WARNINGS
CPPCORECHECK_TYPE_WARNINGS
CPPCORECHECK_RAW_POINTER_WARNINGS
CPPCORECHECK_CONST_WARNINGS
CPPCORECHECK_OWNER_POINTER_WARNINGS
CPPCORECHECK_UNIQUE_POINTER_WARNINGS
CPPCORECHECK_BOUNDS_WARNINGS
```

Essas macros correspondem aos conjuntos de regras e se expandem para uma lista separada por espaços de números de aviso. Usando as construções de pragma apropriadas, você pode configurar o conjunto eficaz de regras que é interessante para um projeto ou uma seção de código. No exemplo a seguir, a análise de código avisará apenas sobre modificadores de constante ausentes:

```cpp
#include <CppCoreCheck\Warnings.h>
#pragma warning(disable: ALL_CPPCORECHECK_WARNINGS)
#pragma warning(default: CPPCORECHECK_CONST_WARNINGS)
```

## <a name="attributes"></a>Atributos

O compilador C++ da Microsoft tem um suporte limitado para o atributo de supressão GSL. Ele pode ser usado para suprimir avisos em instruções de expressão e de bloco dentro de uma função.

```cpp
// Suppress only warnings from the 'r.11' rule in expression.
[[gsl::suppress(r.11)]] new int;

// Suppress all warnings from the 'r' rule group (resource management) in block.
[[gsl::suppress(r)]]
{
    new int;
}

// Suppress only one specific warning number.
// For declarations, you may need to use the surrounding block.
// Macros are not expanded inside of attributes.
// Use plain numbers instead of macros from the warnings.h.
[[gsl::suppress(26400)]]
{
    int *p = new int;
}
```

## <a name="suppressing-analysis-by-using-command-line-options"></a>Suprimindo a análise usando opções de linha de comando

Em vez de #pragmas, você pode usar opções de linha de comando na página de propriedades do arquivo para suprimir os avisos de um projeto ou de um único arquivo. Por exemplo, para desabilitar o aviso C26400 para um arquivo:

1. Clique com o botão direito do mouse no arquivo em **Gerenciador de soluções**

1. Escolher **Propriedades | C/C++| Linha de comando**

1. Na janela **Opções adicionais** , adicione `/wd26400`.

Você pode usar a opção de linha de comando para desabilitar temporariamente toda a análise de código de um arquivo, especificando `/analyze-`. Isso produzirá o aviso *D9025 substituindo '/ANALYZE ' por '/ANALYZE-'* , que o lembrará de reabilitar a análise de código mais tarde.

## <a name="corecheck_per_file"></a>Habilitando C++ o verificador de diretrizes principais em arquivos de projeto específicos

Às vezes, pode ser útil fazer uma análise de código focada e ainda aproveitar o IDE do Visual Studio. Abaixo está um cenário de exemplo que pode ser usado para projetos grandes para economizar tempo de compilação e para facilitar o filtro de resultados.

1. No Shell de comando, defina as variáveis de ambiente `esp.extension` e `esp.annotationbuildlevel`.
1. Abra o Visual Studio do Shell de comando para herdar essas variáveis.
1. Carregue seu projeto e abra suas propriedades.
1. Habilite a análise de código, escolha os conjuntos de regras apropriados, mas não habilite as extensões de análise de código.
1. Vá para o arquivo que você deseja analisar com o C++ verificador de diretrizes principais e abra suas propriedades.
1. Escolha **as opçõesC++de linha C/\Command** e adicione `/analyze:plugin EspXEngine.dll`
1. Desabilite o uso do cabeçalho pré-compilado (**cabeçalhos C/C++\Precompiled**). Isso é necessário porque o mecanismo de extensões pode tentar ler suas informações internas do cabeçalho pré-compilado e, se o último tiver sido compilado com opções de projeto padrão, ele não será compatível.
1. Recompile o projeto. As verificações PREfast comuns devem ser executadas em todos os arquivos. Como o C++ verificador de diretrizes principais não está habilitado por padrão, ele só deve ser executado no arquivo que está configurado para usá-lo.

## <a name="how-to-use-the-c-core-guidelines-checker-outside-of-visual-studio"></a>Como usar o verificador de C++ diretrizes principais fora do Visual Studio

Você pode usar as C++ principais verificações de diretrizes em compilações automatizadas.

### <a name="msbuild"></a>MSBuild

O PREfast (verificador de análise de código) nativo é integrado ao ambiente do MSBuild por arquivos de destino personalizados. Você pode usar as propriedades do projeto para habilitá-lo C++ e adicionar o verificador de diretrizes principais (que se baseia em PREfast):

```xml
<PropertyGroup>
  <EnableCppCoreCheck>true</EnableCppCoreCheck>
  <CodeAnalysisRuleSet>CppCoreCheckRules.ruleset</CodeAnalysisRuleSet>
  <RunCodeAnalysis>true</RunCodeAnalysis>
</PropertyGroup>
```

Certifique-se de adicionar essas propriedades antes da importação do arquivo Microsoft. cpp. targets. Você pode escolher conjuntos de regras específicos ou criar um conjunto de regras personalizado ou usar o conjunto de regras padrão que inclui outras verificações PREfast.

Você pode executar o C++ verificador principal somente em arquivos especificados usando a mesma abordagem [descrita anteriormente](#corecheck_per_file), mas usando arquivos MSBuild. As variáveis de ambiente podem ser definidas usando o `BuildMacro` item:

```xml
<ItemGroup>
    <BuildMacro Include="Esp_AnnotationBuildLevel">
      <EnvironmentVariable>true</EnvironmentVariable>
      <Value>Ignore</Value>
    </BuildMacro>
    <BuildMacro Include="Esp_Extensions">
      <EnvironmentVariable>true</EnvironmentVariable>
      <ValueCppCoreCheck.dll</Value>
    </BuildMacro>
</ItemGroup>
```

Se você não quiser modificar o arquivo de projeto, poderá passar Propriedades na linha de comando:

```cmd
msbuild /p:EnableCppCoreCheck=true /p:RunCodeAnalysis=true /p:CodeAnalysisRuleSet=CppCoreCheckRules.ruleset ...
```

### <a name="non-msbuild-projects"></a>Projetos não MSBuild

Se você usar um sistema de compilação que não dependa do MSBuild, ainda poderá executar o verificador, mas precisará se familiarizar com alguns elementos internos da configuração do mecanismo de análise de código (o que não tem a garantia de ter suporte no futuro).

Você precisará definir algumas variáveis de ambiente e usar as opções de linha de comando adequadas para o compilador. É melhor trabalhar no ambiente "prompt de comando de ferramentas nativas" para que você não precise procurar caminhos específicos para o compilador, incluir diretórios, etc.

1. **Variáveis de ambiente**
   - `set esp.extensions=cppcorecheck.dll` isso diz ao mecanismo para carregar o C++ módulo de diretrizes básicas.
   - `set esp.annotationbuildlevel=ignore` isso desabilita a lógica que processa as anotações SAL. As anotações não afetam a análise de código C++ no verificador de diretrizes principais, mas seu processamento leva tempo (às vezes, muito tempo). Essa configuração é opcional, mas altamente recomendável.
   - `set caexcludepath=%include%` é altamente recomendável que você desabilite os avisos que são acionados em cabeçalhos padrão. Você pode adicionar mais caminhos aqui, por exemplo, o caminho para os cabeçalhos comuns em seu projeto.
1. **Opções de linha de comando**
   - `/analyze` habilita a análise de código (Considere também usar/analyze: Only e/analyze: Quiet).
   - `/analyze:plugin EspXEngine.dll` essa opção carrega o mecanismo de extensões de análise de código no PREfast. Esse mecanismo, por sua vez, carrega C++ o principal verificador de diretrizes.

## <a name="use-the-guideline-support-library"></a>Usar a biblioteca de suporte de diretrizes

A biblioteca de suporte a diretrizes foi projetada para ajudá-lo a seguir as principais diretrizes. O GSL inclui definições que permitem que você substitua construções propensas a erros com alternativas mais seguras. Por exemplo, você pode substituir um `T*, length` par de parâmetros pelo tipo de `span<T>`. O GSL está disponível em [http://www.nuget.org/packages/Microsoft.Gsl](https://www.nuget.org/packages/Microsoft.Gsl). A biblioteca é de software livre, para que você possa exibir as fontes, fazer comentários ou contribuir. O projeto pode ser encontrado em [https://github.com/Microsoft/GSL](https://github.com/Microsoft/GSL).

## <a name="vs2015_corecheck"></a>Use as C++ diretrizes de verificação principal nos projetos do Visual Studio 2015

Se você usar o Visual Studio 2015, C++ os conjuntos de regras de análise de código de verificação de núcleo não serão instalados por padrão. Você deve executar algumas etapas adicionais para poder habilitar as ferramentas C++ de análise de código de verificação de núcleo no Visual Studio 2015. A Microsoft fornece suporte para projetos do Visual Studio 2015 usando um pacote NuGet. O pacote é denominado Microsoft. CppCoreCheck e está disponível em [http://www.nuget.org/packages/Microsoft.CppCoreCheck](https://www.nuget.org/packages/Microsoft.CppCoreCheck). Este pacote requer que você tenha pelo menos o Visual Studio 2015 com atualização 1 instalado.

O pacote também instala outro pacote como uma dependência, uma biblioteca de suporte de diretrizes somente de cabeçalho (GSL). O GSL também está disponível no GitHub em [https://github.com/Microsoft/GSL](https://github.com/Microsoft/GSL).

Devido à maneira como as regras de análise de código são carregadas, você deve instalar o pacote NuGet Microsoft. C++ CppCoreCheck em cada projeto que você deseja verificar no Visual Studio 2015.

### <a name="to-add-the-microsoftcppcorecheck-package-to-your-project-in-visual-studio-2015"></a>Para adicionar o pacote Microsoft. CppCoreCheck ao seu projeto no Visual Studio 2015

1. No **Gerenciador de soluções**, clique com o botão direito do mouse para abrir o menu de contexto do seu projeto na solução à qual você deseja adicionar o pacote. Escolha **gerenciar pacotes NuGet** para abrir o **Gerenciador de pacotes NuGet**.

1. Na janela **Gerenciador de pacotes NuGet** , procure Microsoft. CppCoreCheck.

    ![Janela do Gerenciador de pacotes NuGet mostra o pacote CppCoreCheck](../code-quality/media/cppcorecheck_nuget_window.png)

1. Selecione o pacote Microsoft. CppCoreCheck e, em seguida, escolha o botão **instalar** para adicionar as regras ao seu projeto.

   O pacote NuGet adiciona um arquivo MSBuild. targets adicional ao seu projeto que é invocado quando você habilita a análise de código em seu projeto. Esse arquivo. targets adiciona C++ as regras de verificação principal como uma extensão adicional à ferramenta de análise de código do Visual Studio. Quando o pacote é instalado, você pode usar a caixa de diálogo páginas de propriedades para habilitar ou desabilitar as regras liberadas e experimentais.
