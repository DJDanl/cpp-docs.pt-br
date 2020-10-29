---
title: Usando os verificadores de Diretrizes Principais do C++
description: Como configurar e usar as regras de análise de código do Microsoft C++ para Diretrizes Principais do C++.
ms.date: 07/27/2020
ms.topic: conceptual
dev_langs:
- CPP
ms.openlocfilehash: a041ecd4053360ebfc0da198efe9a3decb73ffd2
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924796"
---
# <a name="use-the-c-core-guidelines-checkers"></a>Usar os verificadores de Diretrizes Principais do C++

A Diretrizes Principais do C++ é um conjunto portátil de diretrizes, regras e práticas recomendadas sobre codificação em C++ criado por especialistas e designers do C++. Atualmente, o Visual Studio dá suporte a um subconjunto dessas regras como parte de suas ferramentas de análise de código para C++. Os verificadores de diretriz principais são instalados por padrão no Visual Studio 2017 e no Visual Studio 2019. Eles estão [disponíveis como um pacote NuGet para o Visual Studio 2015](#vs2015_corecheck).

## <a name="the-c-core-guidelines-project"></a>O projeto Diretrizes Principais do C++

Criado por Bjarne Stroustrup e outros, o Diretrizes Principais do C++ é um guia para usar C++ moderno com segurança e eficiência. As diretrizes enfatizam a segurança de tipo estático e a segurança de recursos. Eles identificam maneiras de eliminar ou minimizar as partes mais propensas a erros da linguagem. Eles também sugerem como tornar seu código mais simples, mais confiável e ter um desempenho melhor. Essas diretrizes são mantidas pelo Standard C++ Foundation. Para saber mais, consulte a documentação, [diretrizes principais do C++](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)e acessar os arquivos de projeto de documentação diretrizes principais do C++ no [GitHub](https://github.com/isocpp/CppCoreGuidelines).

## <a name="enable-the-c-core-check-guidelines-in-code-analysis"></a>Habilitar as diretrizes de Verificação Principal do C++ na análise de código

::: moniker range="<=msvc-150"

Um subconjunto de regras de Verificação Principal do C++ está incluído no conjunto de regras Microsoft Native recomendado. É o conjunto de regras que é executado por padrão quando a análise de código está habilitada.

### <a name="to-enable-code-analysis-on-your-project"></a>Para habilitar a análise de código em seu projeto

1. Abra a caixa de diálogo  **páginas de propriedades** do seu projeto.

1. Selecione a página de propriedade análise de código **das propriedades de configuração** > **Code Analysis** .

1. Marque a caixa de seleção **Habilitar análise de código no Build** .

![Página de propriedades para configurações gerais de análise de código](media/cppcorecheck_codeanalysis_general.png)

Para habilitar outras regras de verificação principais, abra a lista suspensa e escolha quais conjuntos de regras você deseja incluir:

![Lista suspensa para conjuntos de regras de Verificação Principal do C++ adicionais](media/cppcorecheck_codeanalysis_extensions.png)

::: moniker-end
::: moniker range=">=msvc-160"

Um subconjunto de regras de Verificação Principal do C++ está incluído no conjunto de regras Microsoft Native recomendado. É o conjunto de regras que é executado por padrão quando a análise de código da Microsoft é habilitada.

### <a name="to-enable-code-analysis-on-your-project"></a>Para habilitar a análise de código em seu projeto:

1. Abra a caixa de diálogo  **páginas de propriedades** do seu projeto.

1. Selecione a página de propriedade análise de código **das propriedades de configuração** > **Code Analysis** .

1. Defina a configuração **Habilitar análise de código na compilação** e habilitar as propriedades de **análise de código da Microsoft** .

Você também pode optar por executar todas as regras de Verificação Principal do C++ com suporte ou selecionar seu próprio subconjunto para executar:

### <a name="to-enable-additional-core-check-rules"></a>Para habilitar outras regras de verificação principais

1. Abra a caixa de diálogo  **páginas de propriedades** do seu projeto.

1. Selecione a página de propriedade da análise de código **das propriedades de configuração** > **Code Analysis** > da **Microsoft** .

1. Abra a lista suspensa **regras ativas** e selecione **escolher vários conjuntos de regras** .

1. Na caixa de diálogo **Adicionar ou remover conjuntos de regras** , escolha quais conjuntos de regras você deseja incluir.

::: moniker-end

## <a name="examples"></a>Exemplos

Veja um exemplo de alguns dos problemas que as regras de Verificação Principal do C++ podem encontrar:

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

Este exemplo demonstra alguns dos avisos que as regras de Verificação Principal do C++ podem encontrar:

- C26494 é o tipo de regra. 5: sempre inicializar um objeto.

- C26485 é associado à regra. 3: nenhum decaimento de matriz para ponteiro.

- C26481 são limites de regra. 1: não use aritmética de ponteiro. Use `span` em seu lugar.

Instale e habilite os conjuntos de regras de análise de código Verificação Principal do C++ e compile este código. A análise de código gera os dois primeiros avisos e suprime o terceiro. Aqui está a saída da compilação do código de exemplo no Visual Studio 2015:

```Output
1>------ Build started: Project: CoreCheckExample, Configuration: Debug Win32 ------
1>  CoreCheckExample.cpp
1>  CoreCheckExample.vcxproj -> C:\Users\username\documents\visual studio 2015\Projects\CoreCheckExample\Debug\CoreCheckExample.exe
1>  CoreCheckExample.vcxproj -> C:\Users\username\documents\visual studio 2015\Projects\CoreCheckExample\Debug\CoreCheckExample.pdb (Full PDB)
c:\users\username\documents\visual studio 2015\projects\corecheckexample\corecheckexample\corecheckexample.cpp(6): warning C26494: Variable 'arr' is uninitialized. Always initialize an object. (type.5: http://go.microsoft.com/fwlink/p/?LinkID=620421)
c:\users\username\documents\visual studio 2015\projects\corecheckexample\corecheckexample\corecheckexample.cpp(7): warning C26485: Expression 'arr': No array to pointer decay. (bounds.3: http://go.microsoft.com/fwlink/p/?LinkID=620415)
========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========
```

As Diretrizes Principais do C++ existem para ajudá-lo a escrever um código melhor e mais seguro. No entanto, você pode encontrar uma instância em que uma regra ou um perfil não deve ser aplicado. É fácil suprimir isso diretamente no código. Você pode usar o `[[gsl::suppress]]` atributo para manter verificação principal do C++ de detectar e relatar qualquer violação de uma regra no bloco de código a seguir. Você pode marcar instruções individuais para suprimir regras específicas. Você pode até mesmo suprimir todo o perfil de limites escrevendo `[[gsl::suppress(bounds)]]` sem incluir um número de regra específico.

## <a name="supported-rule-sets"></a>Conjuntos de regras com suporte

À medida que novas regras são adicionadas ao verificador de Diretrizes Principais do C++, o número de avisos produzidos para código pré-existente pode aumentar. Você pode usar conjuntos de regras predefinidos para filtrar quais tipos de regras habilitar. Você encontrará artigos de referência para a maioria das regras no [Visual Studio verificação principal do C++ referência](code-analysis-for-cpp-corecheck.md).

- **Regras aritméticas** : regras para detectar [estouro](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Res-overflow)aritmético, [operações não assinadas](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Res-unsigned)e manipulação de [bits](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Res-nonnegative). <sup>15,6</sup>

- **Regras de limites** : impor o [perfil de limites do diretrizes principais do C++](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#probounds-bounds-safety-profile). <sup>15,3</sup>

- **Regras de classe** : algumas regras que se concentram no uso adequado de funções de membro especiais e especificações virtuais. Eles são um subconjunto das verificações recomendadas para [classes e hierarquias de classe](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#S-class). <sup>15,5</sup>

- **Regras de simultaneidade** : uma única regra, que captura declarações de objeto de proteção inadequadas. Para obter mais informações, consulte [diretrizes relacionadas à simultaneidade](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#S-concurrency). <sup>15,5</sup>

- **Regras const** : impor [verificações relacionadas a const do diretrizes principais do C++](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#con-constants-and-immutability). <sup>15,3</sup>

- **Regras de declaração** : algumas regras das diretrizes de [interfaces](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#S-interfaces) que se concentram em como as variáveis globais são declaradas. <sup>15,5</sup>

- **Regras de enumeração** : essas regras impõem [verificações relacionadas a enum do diretrizes principais do C++](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#S-enum). <sup>16,3</sup>

- **Regras experimentais** Essas são regras de Verificação Principal do C++ experimentais que são úteis, mas não estão prontas para uso diário. Experimente e [forneça comentários](https://developercommunity.visualstudio.com/content/idea/post.html?space=62). <sup>16,0</sup>

- **Regras de função** : duas verificações que ajudam na adoção do **`noexcept`** especificador. Eles fazem parte das diretrizes para o [design e a implementação da função Clear](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#S-functions). <sup>15,5</sup>

- **Regras de GSL** : essas regras impõem verificações relacionadas à [biblioteca de suporte de diretrizes do diretrizes principais do C++](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#S-gsl). <sup>15,7</sup>

- **Regras de tempo de vida** : essas regras impõem o [perfil de tempo de vida do diretrizes principais do C++](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#prolifetime-lifetime-safety-profile). <sup>15,7</sup>

- **Regras de ponteiro do proprietário** : impor [verificações de gerenciamento de recursos relacionadas ao proprietário \<T> da diretrizes principais do C++](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#r-resource-management). <sup> 15,3</sup>

- **Regras de ponteiro bruto** : impor [verificações de gerenciamento de recursos relacionadas a ponteiros brutos do diretrizes principais do C++](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#r-resource-management). <sup>15,3</sup>

- **Regras de ponteiro compartilhado** : faz parte da imposição de diretrizes de [Gerenciamento de recursos](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#S-resource) . <sup>15,5</sup> adicionamos algumas regras específicas para como ponteiros compartilhados são passados para funções ou usados localmente.

- **Regras STL** : essas regras impõem verificações relacionadas à [STL (biblioteca padrão C++) do diretrizes principais do C++](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#S-stdlib). <sup>15,7</sup>

- **Regras de estilo** : uma verificação simples, mas importante, que banimentos o uso de [goto](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Res-goto). <sup>15,5</sup> é a primeira etapa para melhorar o estilo de codificação e o uso de expressões e instruções em C++.

- **Regras de tipo** : impor o [perfil de tipo do diretrizes principais do C++](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#prosafety-type-safety-profile). <sup>15,3</sup>

- **Regras de ponteiro exclusivas** : impor [verificações de gerenciamento de recursos relacionadas a tipos com semântica de ponteiro exclusiva do diretrizes principais do C++](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#r-resource-management). <sup>15,3</sup>

- **Regras de verificação principal do C++** : esse conjunto de regras contém todas as verificações atualmente implementadas do [diretrizes principais do C++](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c-core-guidelines), exceto as regras experimentais.

<sup>15,3</sup> essas regras apareciam primeiro no Visual Studio 2017 versão 15,3 \
<sup>15,5</sup> essas regras apareciam primeiro no Visual Studio 2017 versão 15,5 \
<sup>15,6</sup> essas regras apareciam primeiro no Visual Studio 2017 versão 15,6 \
<sup>15,7</sup> essas regras apareciam primeiro no Visual Studio 2017 versão 15,7 \
<sup>16,0</sup> essas regras apareciam primeiro no Visual Studio 2019 versão 16,0 \
<sup>16,3</sup> essas regras apareciam primeiro no Visual Studio 2019 versão 16,3

Você pode optar por limitar os avisos a apenas um ou alguns dos grupos. Os conjuntos de regras **recomendadas** nativas e **mínimas** nativas incluem regras de verificação principal do C++ e outras verificações PREfast.

::: moniker range="<=msvc-150"

Para ver os conjuntos de regras disponíveis, abra a caixa de diálogo **Propriedades do projeto** . Na caixa de diálogo **páginas de propriedades** , selecione a página de propriedades **configuração**  >  **análise de código**  >  **geral** . Em seguida, abra o menu suspenso na caixa de combinação **conjuntos de regras** para ver os conjuntos de regras disponíveis. Para criar uma combinação personalizada de conjuntos de regras, selecione **escolher vários conjuntos de regras** . A caixa de diálogo **Adicionar ou remover conjuntos de regras** lista as regras que podem ser escolhidas. Para obter mais informações sobre como usar conjuntos de regras no Visual Studio, consulte [usar conjuntos de regras para especificar as regras do C++ a serem executadas](using-rule-sets-to-specify-the-cpp-rules-to-run.md).

::: moniker-end
::: moniker range=">=msvc-160"

Para ver os conjuntos de regras disponíveis, abra a caixa de diálogo **Propriedades do projeto** . Na caixa de diálogo **páginas de propriedades** , selecione a página de propriedades **configuração**  >  **análise de código** da  >  **Microsoft** . Em seguida, abra o menu suspenso na caixa de combinação **regras ativas** para ver os conjuntos de regras disponíveis. Para criar uma combinação personalizada de conjuntos de regras, selecione **escolher vários conjuntos de regras** . A caixa de diálogo **Adicionar ou remover conjuntos de regras** lista as regras que podem ser escolhidas. Para obter mais informações sobre como usar conjuntos de regras no Visual Studio, consulte [usar conjuntos de regras para especificar as regras do C++ a serem executadas](using-rule-sets-to-specify-the-cpp-rules-to-run.md).

::: moniker-end

## <a name="macros"></a>Macros

O verificador de Diretrizes Principais do C++ vem com um arquivo de cabeçalho, que define macros que facilitam a supressão de categorias inteiras de avisos no código:

```cpp
ALL_CPPCORECHECK_WARNINGS
CPPCORECHECK_TYPE_WARNINGS
CPPCORECHECK_RAW_POINTER_WARNINGS
CPPCORECHECK_CONST_WARNINGS
CPPCORECHECK_OWNER_POINTER_WARNINGS
CPPCORECHECK_UNIQUE_POINTER_WARNINGS
CPPCORECHECK_BOUNDS_WARNINGS
```

Essas macros correspondem aos conjuntos de regras e se expandem para uma lista separada por espaços de números de aviso. Usando as construções de pragma apropriadas, você pode configurar o conjunto eficaz de regras que é interessante para um projeto ou uma seção de código. No exemplo a seguir, a análise de código avisa apenas sobre os modificadores de constante ausentes:

```cpp
#include <CppCoreCheck\Warnings.h>
#pragma warning(disable: ALL_CPPCORECHECK_WARNINGS)
#pragma warning(default: CPPCORECHECK_CONST_WARNINGS)
```

## <a name="attributes"></a>Atributos

O compilador do Microsoft C++ tem suporte limitado para o `[[gsl::suppress]]` atributo. Ele pode ser usado para suprimir avisos em instruções de expressão e de bloco dentro de funções.

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

## <a name="suppress-analysis-by-using-command-line-options"></a>Suprimir análise usando opções de linha de comando

Em vez de #pragmas, você pode usar opções de linha de comando na página de propriedades do arquivo para suprimir os avisos de um projeto ou de um único arquivo. Por exemplo, para desabilitar o aviso C26400 para um arquivo:

1. Clique com o botão direito do mouse no arquivo em **Gerenciador de soluções** e escolha **Propriedades** .

1. Na caixa de diálogo **páginas de propriedades** , selecione a página de propriedades **configuração** de  >  linha de comando **C/C++**  >  **Command Line** .

1. Na caixa de edição **Opções adicionais** , adicione *`/wd26400`* .

Você pode usar a opção de linha de comando para desabilitar temporariamente toda a análise de código de um arquivo, especificando **`/analyze-`** . Você verá o aviso *D9025 substituindo '/ANALYZE ' por '/ANALYZE-'* , que o lembrará de reabilitar a análise de código mais tarde.

## <a name="enable-the-c-core-guidelines-checker-on-specific-project-files"></a><a name="corecheck_per_file"></a> Habilitar o verificador de Diretrizes Principais do C++ em arquivos de projeto específicos

Às vezes, é útil fazer uma análise de código focada e ainda usar o IDE do Visual Studio. Experimente o cenário de exemplo a seguir para projetos grandes. Ele pode economizar tempo de compilação e facilitar o filtro de resultados:

1. No Shell de comando, defina as `esp.extension` `esp.annotationbuildlevel` variáveis de ambiente e.

1. Para herdar essas variáveis, abra o Visual Studio no Shell de comando.

1. Carregue seu projeto e abra suas propriedades.

1. Habilite a análise de código, escolha os conjuntos de regras apropriados, mas não habilite as extensões de análise de código.

1. Vá para o arquivo que você deseja analisar com o verificador de Diretrizes Principais do C++ e abra suas propriedades.

1. Escolha **Propriedades de configuração**  >  linha de comando **C/C++**  >  **Command Line**  >  **Opções adicionais** e adicionar *`/analyze:plugin EspXEngine.dll`*

1. Desabilite o uso de cabeçalho pré-compilado ( **Propriedades de configuração**  >  cabeçalhos pré-compilados **C/C++**  >  **Precompiled Headers** ). É necessário porque o mecanismo de extensões pode tentar ler suas informações internas do cabeçalho pré-compilado (PCH). Se o PCH tiver sido compilado com opções de projeto padrão, ele não será compatível.

1. Recompile o projeto. As verificações PREfast comuns devem ser executadas em todos os arquivos. Como o verificador de Diretrizes Principais do C++ não está habilitado por padrão, ele só deve ser executado no arquivo que está configurado para usá-lo.

## <a name="how-to-use-the-c-core-guidelines-checker-outside-of-visual-studio"></a>Como usar o verificador de Diretrizes Principais do C++ fora do Visual Studio

Você pode usar as verificações de Diretrizes Principais do C++ em compilações automatizadas.

### <a name="msbuild"></a>MSBuild

O PREfast (verificador de análise de código) nativo é integrado ao ambiente do MSBuild por arquivos de destino personalizados. Você pode usar as propriedades do projeto para habilitá-lo e adicionar o verificador de Diretrizes Principais do C++ (que se baseia em PREfast):

```xml
  <PropertyGroup>
    <EnableCppCoreCheck>true</EnableCppCoreCheck>
    <CodeAnalysisRuleSet>CppCoreCheckRules.ruleset</CodeAnalysisRuleSet>
    <RunCodeAnalysis>true</RunCodeAnalysis>
  </PropertyGroup>
```

Certifique-se de adicionar essas propriedades antes da importação do *`Microsoft.Cpp.targets`* arquivo. Você pode escolher conjuntos de regras específicos ou criar um conjunto de regras personalizado. Ou use o conjunto de regras padrão que inclui outras verificações PREfast.

Você pode executar o verificador principal do C++ somente em arquivos especificados. Use a mesma abordagem [descrita anteriormente](#corecheck_per_file), mas use arquivos MSBuild. As variáveis de ambiente podem ser definidas usando o `BuildMacro` Item:

```xml
<ItemGroup>
    <BuildMacro Include="Esp_AnnotationBuildLevel">
      <EnvironmentVariable>true</EnvironmentVariable>
      <Value>Ignore</Value>
    </BuildMacro>
    <BuildMacro Include="Esp_Extensions">
      <EnvironmentVariable>true</EnvironmentVariable>
      <Value>CppCoreCheck.dll</Value>
    </BuildMacro>
</ItemGroup>
```

Se você não quiser modificar o arquivo de projeto, poderá passar Propriedades na linha de comando:

```cmd
msbuild /p:EnableCppCoreCheck=true /p:RunCodeAnalysis=true /p:CodeAnalysisRuleSet=CppCoreCheckRules.ruleset ...
```

### <a name="non-msbuild-projects"></a>Projetos não MSBuild

Se você usar um sistema de compilação que não dependa do MSBuild, ainda poderá executar o verificador. Para usá-lo, você precisa estar familiarizado com alguns elementos internos da configuração do mecanismo de análise de código. Não garantimos suporte para esses elementos internos em versões futuras do Visual Studio.

A análise de código requer algumas variáveis de ambiente e opções de linha de comando do compilador. É recomendável usar o ambiente de **prompt de comando das ferramentas nativas** para que você não precise procurar caminhos específicos para o compilador, incluir diretórios e assim por diante.

- **Variáveis de ambiente**
  - `set esp.extensions=cppcorecheck.dll` Isso informa o mecanismo para carregar o módulo Diretrizes Principais do C++.
  - `set esp.annotationbuildlevel=ignore` Isso desabilita a lógica que processa anotações SAL. As anotações não afetam a análise de código no verificador de Diretrizes Principais do C++, mas seu processamento leva tempo (às vezes, muito tempo). Essa configuração é opcional, mas altamente recomendável.
  - `set caexcludepath=%include%` É altamente recomendável que você desabilite os avisos que são acionados em cabeçalhos padrão. Você pode adicionar mais caminhos aqui, por exemplo, o caminho para os cabeçalhos comuns em seu projeto.

- **Opções de linha de comando**
  - **`/analyze`**  Habilita a análise de código (Considere também usar **`/analyze:only`** e **`/analyze:quiet`** ).
  - **`/analyze:plugin EspXEngine.dll`** Essa opção carrega o mecanismo de extensões de análise de código no PREfast. Esse mecanismo, por sua vez, carrega o verificador de Diretrizes Principais do C++.

## <a name="use-the-guideline-support-library"></a>Usar a biblioteca de suporte de diretrizes

A GSL (biblioteca de suporte de diretrizes) foi projetada para ajudá-lo a seguir as diretrizes básicas. O GSL inclui definições que permitem que você substitua construções propensas a erros com alternativas mais seguras. Por exemplo, você pode substituir um `T*, length` par de parâmetros pelo `span<T>` tipo. O GSL está disponível em [http://www.nuget.org/packages/Microsoft.Gsl](https://www.nuget.org/packages/Microsoft.Gsl) . A biblioteca é de código-fonte aberto, para que você possa exibir as fontes, fazer comentários ou contribuir. O projeto pode ser encontrado em [https://github.com/Microsoft/GSL](https://github.com/Microsoft/GSL) .

::: moniker range="msvc-140"

## <a name="use-the-c-core-check-guidelines-in-visual-studio-2015-projects"></a><a name="vs2015_corecheck"></a> Usar as diretrizes de Verificação Principal do C++ nos projetos do Visual Studio 2015

Se você usar o Visual Studio 2015, os conjuntos de regras de análise de código Verificação Principal do C++ não serão instalados por padrão. Etapas adicionais são necessárias para que você possa habilitar as ferramentas de análise de código Verificação Principal do C++ no Visual Studio 2015. A Microsoft fornece suporte para projetos do Visual Studio 2015 usando um pacote NuGet. O pacote é denominado Microsoft. CppCoreCheck e está disponível em [http://www.nuget.org/packages/Microsoft.CppCoreCheck](https://www.nuget.org/packages/Microsoft.CppCoreCheck) . Este pacote requer que você tenha pelo menos o Visual Studio 2015 com atualização 1 instalado.

O pacote também instala outro pacote como uma dependência, a GSL (biblioteca de suporte de diretrizes somente de cabeçalho). O GSL também está disponível no GitHub em [https://github.com/Microsoft/GSL](https://github.com/Microsoft/GSL) .

Devido à maneira como as regras de análise de código são carregadas no Visual Studio 2015, você deve instalar o `Microsoft.CppCoreCheck` pacote NuGet em cada projeto C++ que você deseja verificar.

### <a name="to-add-the-microsoftcppcorecheck-package-to-your-project-in-visual-studio-2015"></a>Para adicionar o pacote Microsoft. CppCoreCheck ao seu projeto no Visual Studio 2015

1. No **Gerenciador de soluções** , clique com o botão direito do mouse para abrir o menu de contexto do seu projeto na solução à qual você deseja adicionar o pacote. Escolha **gerenciar pacotes NuGet** para abrir o **Gerenciador de pacotes NuGet** .

1. Na janela **Gerenciador de pacotes NuGet** , procure Microsoft. CppCoreCheck.

    ![Janela do Gerenciador de pacotes NuGet mostra o pacote CppCoreCheck](../code-quality/media/cppcorecheck_nuget_window.png)

1. Selecione o pacote Microsoft. CppCoreCheck e, em seguida, escolha o botão **instalar** para adicionar as regras ao seu projeto.

   O pacote NuGet adiciona um arquivo MSBuild adicional *`.targets`* ao seu projeto que é invocado quando você habilita a análise de código em seu projeto. O *`.targets`* arquivo adiciona as regras de verificação principal do C++ como uma extensão adicional à ferramenta de análise de código do Visual Studio. Quando o pacote é instalado, você pode usar a caixa de diálogo páginas de propriedades para habilitar ou desabilitar as regras liberadas e experimentais.

::: moniker-end

## <a name="see-also"></a>Veja também

- [Referência do Visual Studio Verificação Principal do C++](code-analysis-for-cpp-corecheck.md)
