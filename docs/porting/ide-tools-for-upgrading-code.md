---
title: Ferramentas IDE do Visual Studio para C++ atualizar o código
description: O C++ editor de código e as ferramentas de análise de código no Visual Studio ajudam você C++ a modernizar sua base de código.
ms.date: 11/13/2019
ms.topic: conceptual
ms.openlocfilehash: 409fc0a2fa6cd39c7751dc34b20b231ffbea3956
ms.sourcegitcommit: 7bea0420d0e476287641edeb33a9d5689a98cb98
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/17/2020
ms.locfileid: "77416146"
---
# <a name="visual-studio-ide-tools-for-upgrading-c-code"></a>Ferramentas IDE do Visual Studio para C++ atualizar o código

O Visual Studio ajuda você a C++ atualizar o código herdado com opções de compilador, avisos de análise de código e recursos de editor, como correções rápidas, informações rápidas e barra de rolagem avançada. O termo "código herdado" refere-se a qualquer uma dessas categorias:

- O código que era anteriormente permitido pelo compilador C++ da Microsoft (MSVC), mas nunca está em conformidade C++ com o padrão.

   Para atualizar o código de MSVC não compatível mais antigo, ative a opção de compilador [/permissive-](../build/reference/permissive-standards-conformance.md) . Todas as instâncias de usos não conformados são sublinhadas com ondulado vermelho no editor de códigos. As mensagens de erro na janela de **lista de erros** incluem uma recomendação de como corrigir o erro. Clique no código de erro para ir para a página de ajuda na documentação. Se a correção de todos os erros ao mesmo tempo não for prática, você poderá atualizar o código não compatível em estágios ativando a opção **permissiva** , corrigindo alguns erros e, em seguida, desligando a opção novamente. O código será compilado com as novas melhorias e você poderá voltar e corrigir os problemas restantes mais tarde. Consulte a página [/permissive-](../build/reference/permissive-standards-conformance.md) para obter exemplos de código de MSVC não compatível.

- Código que foi permitido em uma versão anterior do C++ padrão, mas foi preterido ou removido em uma versão posterior.

   Para atualizar para um padrão de idioma mais recente, [ C++ ](../build/reference/std-specify-language-standard-version.md) defina a opção padrão de idioma para o padrão desejado e corrija os erros de compilação que forem gerados. Em geral, é recomendável definir o idioma padrão para [/std: c++ 17](../build/reference/std-specify-language-standard-version.md). Os erros gerados ao atualizar para um padrão mais recente não estão relacionados aos erros gerados ao usar a opção **permissiva** .

- Código que está em conformidade com todas as versões do padrão, mas que não é mais considerada prática recomendada C++no moderno.

   Para identificar o código em que as alterações são recomendadas, execute a [análise de código](/cpp/code-quality/code-analysis-for-c-cpp-overview).

## <a name="open-and-convert-a-legacy-project"></a>Abrir e converter um projeto herdado

Se seu projeto herdado for baseado em uma versão mais antiga do Visual Studio, você poderá abri-lo no Visual Studio 2017 ou no Visual Studio 2019. O Visual Studio o converte automaticamente no esquema de projeto atual com suporte para todos os recursos de compilador e IDE mais recentes.

![Atualizar um projeto](media/upgrade-dialog-v142.png "Atualizar um projeto")

Para obter mais informações, [consulte C++ atualizar projetos de versões anteriores do Visual Studio](upgrading-projects-from-earlier-versions-of-visual-cpp.md).

## <a name="search-the-code-base"></a>Pesquisar a base de código

A atualização de uma base de código geralmente envolve a pesquisa em vários arquivos. Para pesquisar qualquer coisa em sua base de código, pressione **Ctrl + T** para exibir a caixa de pesquisa **ir para todos** .

![Ir para todos](media/go-to-all.png "Ir para todos")

Para restringir o escopo da pesquisa, digite um dos filtros de 1 letra, seguido por um espaço e a coisa que você está procurando.

## <a name="error-list"></a>Lista de Erros

Depois de definir o padrão C++ de idioma desejado e quaisquer outras opções de compilador (**projeto** > **Propriedades** > **geral**), pressione **Ctrl + Shift + B** para compilar seu projeto. Você pode esperar ver alguns erros e avisos na forma de rabiscos vermelhos em vários locais no código. Os erros também aparecem na **lista de erros**. Para obter mais informações sobre um erro específico, clique no código de erro para ir para a página de ajuda na documentação do. Os códigos de erro que começam com um "C" são erros do compilador. Os códigos que começam com "MSB" são erros do MSBuild que indicam um problema com a configuração do projeto.

![Erros do compilador e do MSBuild no Lista de Erros](media/compiler-error-list.png "Erros do compilador e do MSBuild no Lista de Erros")

## <a name="document-health-indicator"></a>Indicador de integridade do documento

O indicador de integridade do documento na parte inferior do editor mostra o número de erros e avisos no documento atual e permite que você navegue diretamente de um aviso/erro para o próximo.

![Indicador de integridade do documento](media/document-health-indicator.png "Indicador de integridade do documento")

Em muitos casos, você pode encontrar mais informações sobre um erro específico na documentação sobre o histórico de alterações e as melhorias de conformidade do Visual Studio.

- [C++melhorias de conformidade](../overview/cpp-conformance-improvements.md)
- [Histórico C++ de alterações visuais 2003-2015](visual-cpp-change-history-2003-2015.md)
- [Visão geral de possíveis problemas de atualização](overview-of-potential-upgrade-issues-visual-cpp.md)

## <a name="use-code-analysis-to-modernize-your-code"></a>Use a análise de código para modernizar seu código

Ao atualizar, recomendamos que você execute a análise de código em seu projeto para que o código esteja de acordo com o mínimo das regras recomendadas nativas da Microsoft. Essas regras são uma combinação de regras definidas pela Microsoft e um subconjunto das [ C++ principais diretrizes](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines). Ao estar em conformidade com isso, você Reduzirá ou eliminará bastante fontes comuns de bugs e, ao mesmo tempo, tornará seu código mais legível e, portanto, mais fácil de manter. A análise de código usando as regras do Microsoft Native recomendado é habilitada por padrão. Você pode habilitar regras adicionais em **Propriedades** de > de **projeto** > **análise de código**. O código que viola uma das regras é sinalizado como um aviso e é sublinhado com um rabisco verde no editor de códigos. Passe o mouse sobre o rabisco para ver uma dica de ferramenta **QuickInfo** que descreve o problema.

![Dica de ferramenta de análise de código](media/code-analysis-tooltip.png "Aviso de análise de código")

Clique no ícone de filtro na coluna **código** para escolher quais avisos serão exibidos.

![Filtros de análise de código no Lista de Erros](media/code-analysis-filter.png "Filtros de análise de código no Lista de Erros")

Erros e avisos de análise de código também aparecem na **lista de erros** assim como erros de compilador.

![Avisos de análise de código no Lista de Erros](media/code-analysis-error-list.png "Avisos de análise de código no Lista de Erros")

Você pode alterar quais regras estão ativas e criar conjuntos de regras personalizados. Para obter mais informações sobre como usar a análise de código, consulte [análiseC++ de código para C/visão geral](/cpp/code-quality/code-analysis-for-c-cpp-overview).

## <a name="use-quick-actions-to-modernize-code"></a>Usar ações rápidas para modernizar o código

O editor de código fornece ações rápidas para algumas recomendações comuns. Quando o ícone de lâmpada é exibido, você pode clicar nele para ver as ações rápidas disponíveis.

### <a name="convert-macros-to-constexpr-functions"></a>Converter macros em funções constexpr

A imagem a seguir mostra o uso da macro chamada `AVERAGE`, que tem a colorização semântica padrão. A imagem também mostra a dica de ferramenta QuickInfo que é exibida quando o cursor do mouse passa sobre ela:

![Expansão de macro QuickInfo](media/macro-expansion-quick-info.png "Expansão de macro da dica de ferramenta QuickInfo")

Como o uso de macros é desencorajado no C++moderno, o Visual Studio facilita a conversão de macros em funções **constexpr** :

1. Clique com o botão direito do mouse em `AVERAGE` e escolha **ir para definição**.
2. Clique no ícone de chave de fenda e escolha **converter macro em constexpr**

   ![Macro de ação rápida para constexpr](media/quick-action-macro-to-constexpr.png "Macro de ação rápida para constexpr")

A macro é convertida conforme mostrado abaixo:

![função constexpr](media/constexpr-function.png "função constexpr")

E a chamada para `AVERAGE` agora é colorida como uma chamada de função e a dica de ferramenta Informações Rápidas mostra o tipo deduzido da função:

![chamada de função constexpr](media/constexpr-function-call.png "chamada de função constexpr")

### <a name="initialize-variables"></a>Inicializar variáveis

Variáveis não inicializadas podem conter valores aleatórios que levam a bugs sérios. A análise de código sinaliza essas instâncias e o Editor fornece uma ação rápida:

![Inicializar variável](media/init-variable.png "Ação rápida de inicializar variável")

### <a name="convert-to-raw-string-literal"></a>Converter em literal de cadeia de caracteres bruta

Literais de cadeia de caracteres brutas são menos propensos a erros e mais convenientes de tipos do que cadeias de caracteres de escape inseridos. Clique com o botão direito do mouse em uma cadeia de caracteres e escolha **ações rápidas** para convertê-la em um literal de cadeia de caracteres bruta.

![Literal de cadeia de caracteres bruta](media/raw-string-literal.png "Literal de cadeia de caracteres bruta")

A cadeia de caracteres é convertida em: `R"(C:\Users\bjarnes\demo\output.txt)"`.
