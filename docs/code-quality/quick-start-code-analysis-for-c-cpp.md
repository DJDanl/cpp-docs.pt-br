---
title: 'Início Rápido: análise de código para C/C++'
description: Execute a análise estática no código C++ no Visual Studio para detectar problemas e defeitos comuns de codificação.
ms.date: 04/08/2020
ms.topic: conceptual
helpviewer_keywords:
- C/C++ code analysis
- code analysis, C/C++
ms.openlocfilehash: 43866564915ac84d227ccbf347280efe59e33351
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370580"
---
# <a name="quickstart-code-analysis-for-cc"></a>Início Rápido: análise de código para C/C++

Você pode melhorar a qualidade do seu aplicativo executando a análise de código regularmente no código C ou C++. A análise de código pode ajudá-lo a encontrar problemas comuns e violações de boas práticas de programação. E, encontra defeitos que são difíceis de descobrir através de testes. Seus avisos diferem de erros e avisos do compilador: Ele procura por padrões de código específicos que são conhecidos por causar problemas. Ou seja, código válido, mas que ainda pode criar problemas, seja para você ou para outras pessoas que usam seu código.

## <a name="configure-rule-sets-for-a-project"></a>Configure conjuntos de regras para um projeto

1. No **Solution Explorer,** abra o menu de atalho para o nome do projeto e, em seguida, escolha **Propriedades**.

1. Opcionalmente, nas listas **Configuração** e **Plataforma,** escolha a configuração de compilação e a plataforma de destino.

1. Para executar a análise de código toda vez que o projeto for construído usando a configuração selecionada, selecione a **caixa Despermitir análise de código na** caixa de seleção Build. Você também pode executar a análise de código manualmente abrindo o menu **Analisar** e, em seguida, escolhendo **Run Code Analysis no** *ProjectName* ou **Run Code Analysis on File**.

1. Escolha o [conjunto de regras](using-rule-sets-to-specify-the-cpp-rules-to-run.md) que deseja usar ou crie um conjunto de regras [personalizado](using-rule-sets-to-specify-the-cpp-rules-to-run.md#to-create-a-rule-set-in-a-text-editor). Se estiver usando LLVM/clang-cl, consulte [Usando Clang-Tidy no Visual Studio](../code-quality/clang-tidy.md) para configurar opções de análise Clang-Tidy.

### <a name="standard-cc-rule-sets"></a>Conjuntos de regras Padrão C/C++

O Visual Studio inclui estes conjuntos padrão de regras para código nativo:

| Conjunto de regras | Descrição |
|--|--|
| **C++ Core Verificar Regras Aritméticas** | Essas regras impõem verificações relacionadas às [operações aritméticas das Diretrizes Principais C++.](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#es-expressions-and-statements) |
| **C++ Regras de limites de verificação de núcleo** | Essas regras aplicam o [perfil Bounds das Diretrizes Principais C++.](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#probounds-bounds-safety-profile) |
| **C++ Regras da classe de verificação do núcleo** | Essas regras impõem verificações relacionadas às [classes das Diretrizes Principais C++.](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c-classes-and-class-hierarchies) |
| **C++ Regras de concorrência de verificação de núcleo** | Essas regras impõem verificações relacionadas à [concorrência das Diretrizes Principais C++.](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#cpcon-concurrency) |
| **C++ Regras de const de verificação de núcleo** | Essas regras impõem [verificações relacionadas ao const a partir das Diretrizes Principais C++.](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#con-constants-and-immutability) |
| **C++ Regras de Declaração de Verificação Do Núcleo** | Essas regras impõem verificações relacionadas às [declarações das Diretrizes Principais C++.](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#i-interfaces) |
| **C++ Regras do enum de verificação do núcleo** | Essas regras aplicam [verificações relacionadas ao enum das Diretrizes Principais C++.](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#S-enum) |
| **C++ Core Check Regras Experimentais** | Essas regras coletam alguns cheques experimentais. Eventualmente, esperamos que esses cheques sejam movidos para outros conjuntos de regras ou removidos completamente. |
| **C++ Regras de função de verificação do núcleo** | Essas regras impõem verificações relacionadas às [funções das Diretrizes Principais C++.](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#f-functions) |
| **C++ Core Verificar regras gsl** | Essas regras impõem verificações relacionadas à [Biblioteca de Suporte de Diretrizes das Diretrizes Principais C++.](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#S-gsl) |
| **C++ Core Verificar regras de vida** | Essas regras aplicam o [perfil Lifetime das Diretrizes Principais C++.](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#prolifetime-lifetime-safety-profile) |
| **C++ Regras do ponteiro do proprietário do ponto de verificação do núcleo** | Essas regras aplicam verificações de gerenciamento de recursos relacionadas ao [proprietário&lt;T&gt; a partir das Diretrizes Principais C++.](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#r-resource-management) |
| **C++ Core Verificar regras de ponteiro bruto** | Essas regras aplicam verificações de gerenciamento de recursos relacionadas a [ponteiros brutos das Diretrizes Principais C++.](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#r-resource-management) |
| **C++ Regras de verificação do núcleo** | Essas regras impõem um subconjunto das verificações das [Diretrizes Principais C++.](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c-core-guidelines) Use este conjunto de regras para incluir todas as regras de Verificação do Núcleo C++, exceto os conjuntos de regras Enum e Experimental. |
| **C++ Core Verifique regras de ponteiro compartilhada** | Essas regras aplicam verificações de gerenciamento de recursos relacionadas a [tipos com semântica de ponteiro compartilhado das Diretrizes Principais C++.](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#r-resource-management) |
| **C++ Core Verificar regras de STL** | Essas regras impõem verificações relacionadas à [C++ Standard Template Library (STL) das Diretrizes Principais C++.](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#S-stdlib) |
| **C++ Regras de estilo de verificação do núcleo** | Essas regras impõem verificações relacionadas ao uso de [expressões e declarações das Diretrizes Principais C++.](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#es-expressions-and-statements) |
| **C++ Regras do tipo de verificação do núcleo** | Essas regras aplicam o [perfil Tipo das Diretrizes Principais C++.](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#prosafety-type-safety-profile) |
| **C++ Core Check Regras únicas de ponteiro** | Essas regras aplicam verificações de gerenciamento de recursos relacionadas a tipos com [semântica de ponteiro exclusiva das Diretrizes Principais C++.](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#r-resource-management) |
| **Regras de verificação de concorrência** | Essas regras aplicam um conjunto de verificações de padrão de simultuo Win32 em C++. |
| **Regras de concorrência** | Adiciona regras de simultuo de Diretrizes Principais C++ às **Regras de Verificação de Concorrência**. |
| **Regras mínimas nativas da Microsoft** | Essas regras se concentram nos problemas mais críticos do seu código nativo, incluindo possíveis falhas de segurança e falhas de aplicativos. Recomendamos que você inclua esta regra definida em qualquer conjunto de regras personalizadas que você crie para seus projetos nativos. |
| **Regras recomendadas nativas da Microsoft** | Essas regras se concentram nos problemas mais críticos e comuns em seu código nativo. Esses problemas incluem possíveis falhas de segurança e falhas de aplicativos. Recomendamos que você inclua esta regra definida em qualquer conjunto de regras personalizadas que você crie para seus projetos nativos. Este conjunto de regras foi projetado para funcionar com a edição Visual Studio Professional e superior. Ele inclui todas as regras em **Regras Mínimas Nativas da Microsoft**. |

O Visual Studio inclui estes conjuntos padrão de regras para código gerenciado:

| Conjunto de regras | Descrição |
|--|--|
| **Regras básicas de correção da Microsoft** | Essas regras se concentram em erros lógicos e erros comuns cometidos no uso de APIs-framework. Inclua esta regra definida para expandir na lista de avisos relatados pelas regras mínimas recomendadas. |
| **Regras de diretrizes básicas de design da Microsoft** | Essas regras se concentram em aplicar as melhores práticas para tornar seu código fácil de entender e usar. Inclua este conjunto de regras se o seu projeto incluir o código da biblioteca ou se você quiser impor práticas recomendadas para um código facilmente sustentável. |
| **Regras de correção estendidas da Microsoft** | Essas regras se expandem sobre as regras básicas de correção para maximizar a lógica relatada e os erros de uso da estrutura. Ênfase extra é dada em cenários específicos, como interop COM e aplicativos móveis. Considere incluir esta regra definida se um desses cenários se aplica ao seu projeto ou para encontrar problemas adicionais em seu projeto. |
| **Regras de diretrizes de design estendidas da Microsoft** | Essas regras se expandem sobre as regras básicas de diretriz de design para maximizar os problemas de usabilidade e manutenção relatados. Uma ênfase extra é dada às diretrizes de nomeação. Considere incluir este conjunto de regras se o seu projeto incluir código de biblioteca ou se você quiser impor os mais altos padrões para escrever código sustentável. |
| **Regras de globalização da Microsoft** | Essas regras se concentram em problemas que impedem que os dados em seu aplicativo sejam exibidos corretamente quando usados em diferentes idiomas, locais e culturas. Inclua esta regra definida se seu aplicativo estiver localizado e/ou globalizado. |
| **Regras mínimas gerenciadas pela Microsoft** | Essas regras se concentram nos problemas mais críticos do seu código para os quais a Análise de Código é a mais precisa.  Essas regras são pequenas em número e destinam-se apenas a ser executadas em edições limitadas do Visual Studio.  Use MinimumRecommendedRules.ruleset com outras edições do Visual Studio. |
| **Regras recomendadas gerenciadas pela Microsoft** | Essas regras se concentram nos problemas mais críticos do seu código. Esses problemas incluem possíveis falhas de segurança, falhas de aplicativos e outros erros importantes de lógica e design. Recomendamos que você inclua esta regra definida em qualquer conjunto de regras personalizadas que você crie para seus projetos. |
| **Regras mínimas da Microsoft Mixed (C++ /CLR)** | Essas regras se concentram nos problemas mais críticos em seus projetos C++ que suportam o Tempo de Execução de Idiomas Comuns. Esses problemas incluem possíveis falhas de segurança, falhas de aplicativos e outros erros importantes de lógica e design. Recomendamos que você inclua esta regra definida em qualquer conjunto de regras personalizadas que você crie para seus projetos C++ que suportam o Tempo de Execução do Idioma Comum. |
| **Regras recomendadas da Microsoft Mixed (C++ /CLR)** | Essas regras se concentram nos problemas mais comuns e críticos em seus projetos C++ que suportam o Tempo de Execução do Idioma Comum. Esses problemas incluem possíveis falhas de segurança, falhas de aplicativos e outros erros importantes de lógica e design. Este conjunto de regras foi projetado para ser usado na edição visual studio profissional e superior. |
| **Regras de segurança da Microsoft** | Este conjunto de regras contém todas as regras de segurança da Microsoft. Inclua esta regra definida para maximizar o número de potenciais problemas de segurança relatados. |

Para incluir todas as regras:

| Conjunto de regras | Descrição |
|--|--|
| **Todas as regras da Microsoft** | Este conjunto de regras contém todas as regras. A execução deste conjunto de regras pode resultar em um grande número de avisos sendo relatados. Use esta regra definida para obter uma imagem abrangente de todos os problemas em seu código. Ele pode ajudá-lo a decidir qual dos conjuntos de regras mais focados são mais apropriados para executar para seus projetos. |

## <a name="run-code-analysis"></a>Executar análise de código

Na página **de análise** de código da caixa de diálogo Propriedades do projeto, você pode configurar a análise de código para executar cada vez que você construir seu projeto. Você também pode executar a análise de código manualmente.

Para executar a análise de código em uma solução:

- No **menu Build,** escolha **Executar análise de código na solução**.

Para executar a análise de código em um projeto:

1. No Solution Explorer, selecione o nome do projeto.

1. No **menu Build,** escolha **Executar análise de código em** nome do *projeto*.

Para executar a análise de código em um arquivo:

1. No Solution Explorer, selecione o nome do arquivo.

1. No menu **Build,** escolha **Executar análise de código no arquivo** ou **pressione Ctrl+Shift+Alt+F7**.

   O projeto ou solução é compilado e a análise de código é executada. Os resultados aparecem na janela Lista de erros.

## <a name="analyze-and-resolve-code-analysis-warnings"></a>Analisar e resolver avisos de análise de código

A janela Lista de erros lista os avisos de análise de código encontrados. Os resultados são exibidos em uma tabela. Se houver mais informações sobre um aviso específico, a primeira coluna contém um controle de expansão. Escolha-o para expandir o display para obter informações adicionais sobre o problema. Quando possível, a análise de código exibe os números de linha e a lógica de análise que levaram ao aviso.

Para obter informações detalhadas sobre o aviso, incluindo possíveis soluções para o problema, escolha o ID de aviso na coluna Código para exibir seu artigo de ajuda on-line correspondente.

Clique duas vezes em um aviso para mover o cursor para a linha de código que causou o aviso no editor de código satelital Visual Studio. Ou pressione Enter no aviso selecionado.

Depois de entender o problema, você pode resolvê-lo no seu código. Em seguida, execute novamente a análise de código para garantir que o aviso não seja mais exibido na Lista de erros.

## <a name="create-work-items-for-code-analysis-warnings"></a>Crie itens de trabalho para avisos de análise de código

Você pode usar o recurso de rastreamento de itens de trabalho para registrar bugs de dentro do Visual Studio. Para usar esse recurso, você deve se conectar a uma instância do Azure DevOps Server (anteriormente, Team Foundation Server).

### <a name="to-create-a-work-item-for-one-or-more-cc-code-warnings"></a>Para criar um item de trabalho para um ou mais avisos de código C/C++

1. Na lista de erros, expanda e selecione os avisos

1. No menu de atalho para os avisos, escolha **Criar item de trabalho**e, em seguida, escolha o tipo de item de trabalho.

1. O Visual Studio cria um único item de trabalho para os avisos selecionados e exibe o item de trabalho em uma janela de documento do IDE.

1. Adicione qualquer informação adicional e, em seguida, escolha **Salvar o item de trabalho**.

## <a name="search-and-filter-code-analysis-results"></a>Resultados de análise de código de pesquisa e filtro

Você pode pesquisar listas longas de mensagens de aviso e pode filtrar avisos em soluções multiprojeto.

- **Para filtrar avisos por título ou ID de aviso**: Digite a palavra-chave na caixa Lista de erros de pesquisa.

- **Para filtrar avisos por gravidade**: Por padrão, as mensagens de análise de código são atribuídas a uma gravidade de **Aviso**. Você pode atribuir a gravidade de uma ou mais mensagens como **erro** em um conjunto de regras personalizado. Na coluna **Gravidade** da Lista de **erros,** escolha a seta baixa e, em seguida, o ícone do filtro. Escolha **Aviso** ou **Erro** para exibir apenas as mensagens atribuídas à respectiva gravidade. Escolha **Selecionar Tudo** para exibir todas as mensagens.

## <a name="see-also"></a>Confira também

- [Análise de código para C/C++](../code-quality/code-analysis-for-c-cpp-overview.md)
