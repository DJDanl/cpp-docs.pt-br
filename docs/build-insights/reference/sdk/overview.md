---
title: SDK do C++ Build Insights
description: Uma visão geral do SDK do Visual Studio C++ Build insights.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Analyzing
- Relogging
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: a6ecff81a9f3d2b22107a8fa7fc26fad85d4f579
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92919508"
---
# <a name="c-build-insights-sdk"></a>SDK do C++ Build Insights

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

O SDK do insights de compilação do C++ é uma coleção de APIs que permitem que você crie ferramentas personalizadas sobre a plataforma de compilação do C++. Esta página fornece uma visão geral de alto nível para ajudá-lo a começar.

## <a name="obtaining-the-sdk"></a>Obtendo o SDK

Você pode baixar o SDK de informações de compilação C++ como um pacote NuGet seguindo estas etapas:

1. No Visual Studio 2017 e superior, crie um novo projeto C++.
1. No painel de **Gerenciador de soluções** , clique com o botão direito do mouse em seu projeto.
1. Selecione **gerenciar pacotes NuGet** no menu de contexto.
1. No canto superior direito, selecione a origem do pacote **NuGet.org** .
1. Pesquise a versão mais recente do pacote Microsoft. cpp. BuildInsights.
1. Escolha **instalar** .
1. Aceite a licença.

Continue lendo para obter informações sobre os conceitos gerais em torno do SDK. Você também pode acessar o [repositório do GitHub de amostras de Build do c++](https://github.com/microsoft/cpp-build-insights-samples) oficial para ver exemplos de aplicativos reais do c++ que usam o SDK.

## <a name="collecting-a-trace"></a>Coletando um rastreamento

Usando o SDK do insights do C++ Build para analisar eventos provenientes do MSVC ferramentas, é necessário primeiro coletar um rastreamento. O SDK usa o ETW (rastreamento de eventos para Windows) como a tecnologia de rastreamento subjacente. A coleta de um rastreamento pode ser feita de duas maneiras:

### <a name="method-1-using-vcperf-in-visual-studio-2019-and-above"></a>Método 1: usando vcperf no Visual Studio 2019 e superior

1. Abra um Prompt de Comando de Ferramentas Nativas do x64 elevado para VS 2019.
1. Execute o seguinte comando: `vcperf /start MySessionName`
1. Compile o projeto.
1. Execute o seguinte comando: `vcperf /stopnoanalyze MySessionName outputTraceFile.etl`

   > [!IMPORTANT]
   > Use o `/stopnoanalyze` comando ao parar o rastreamento com vcperf. Você não pode usar o SDK do insights do C++ Build para analisar rastreamentos interrompidos pelo `/stop` comando regular.

### <a name="method-2-programmatically"></a>Método 2: programaticamente

Use qualquer uma dessas funções de coleta de rastreamento do SDK do Application insights do C++ para iniciar e parar rastreamentos programaticamente. **O programa que executa essas chamadas de função deve ter privilégios administrativos.** Somente as funções de rastreamento iniciar e parar exigem privilégios administrativos. Todas as outras funções no SDK do insights de compilação do C++ podem ser executadas sem elas.

### <a name="sdk-functions-related-to-trace-collection"></a>Funções do SDK relacionadas à coleta de rastreamento

| Funcionalidade | API de C++ | API do C |
|--|--|--|
| Iniciando um rastreamento | [StartTracingSession](functions/start-tracing-session.md) | [StartTracingSessionA](functions/start-tracing-session-a.md)<br />[StartTracingSessionW](functions/start-tracing-session-w.md) |
| Interrompendo um rastreamento | [StopTracingSession](functions/stop-tracing-session.md) | [StopTracingSessionA](functions/stop-tracing-session-a.md)<br />[StopTracingSessionW](functions/stop-tracing-session-w.md) |
| Parando um rastreamento e<br />analisando imediatamente o resultado | [StopAndAnalyzeTracingSession](functions/stop-and-analyze-tracing-session.md) | [StopAndAnalyzeTracingSessionA](functions/stop-and-analyze-tracing-session-a.md)<br />[StopAndAnalyzeTracingSession](functions/stop-and-analyze-tracing-session-w.md) |
| Parando um rastreamento e<br />refazendo o log imediatamente do resultado | [StopAndRelogTracingSession](functions/stop-and-relog-tracing-session.md) | [StopAndRelogTracingSessionA](functions/stop-and-relog-tracing-session-a.md)<br />[StopAndRelogTracingSessionW](functions/stop-and-relog-tracing-session-w.md) |

As seções a seguir mostram como configurar uma sessão de análise ou de reregistro em log. Ele é necessário para as funções de funcionalidade combinadas, como [StopAndAnalyzeTracingSession](functions/stop-and-analyze-tracing-session.md).

## <a name="consuming-a-trace"></a>Consumindo um rastreamento

Depois que você tiver um rastreamento ETW, use o SDK de Build do C++ para descompactá-lo. O SDK fornece os eventos em um formato que permite desenvolver suas ferramentas rapidamente. Não recomendamos que você consuma o rastreamento ETW bruto sem usar o SDK. O formato de evento usado pelo MSVC não é documentado, otimizado para ser dimensionado para compilações enormes e difícil de fazer sentido. Além disso, a API do SDK do insights de compilação do C++ é estável, enquanto o formato de rastreamento ETW bruto está sujeito a alterações sem aviso prévio.

### <a name="sdk-types-and-functions-related-to-trace-consumption"></a>Tipos e funções de SDK relacionados ao consumo de rastreamento

| Funcionalidade | API de C++ | API do C | Observações |
|--|--|--|--|
| Configurando retornos de chamada de evento | [IAnalyzer](other-types/ianalyzer-class.md)<br />[IRelogger](other-types/irelogger-class.md) | [ANALYSIS_CALLBACKS](other-types/analysis-callbacks-struct.md)<br />[RELOG_CALLBACKS](other-types/relog-callbacks-struct.md) | O SDK do insights de compilação do C++ fornece eventos por meio de funções de retorno de chamada. Em C++, implemente as funções de retorno de chamada criando um analisador ou uma classe de relogger que herda a interface IAnalyzer ou IRelogger. Em C, implemente os retornos de chamada em funções globais e forneça ponteiros para eles na estrutura ANALYSIS_CALLBACKS ou RELOG_CALLBACKS. |
| Criando grupos | [MakeStaticAnalyzerGroup](functions/make-static-analyzer-group.md)<br />[MakeStaticReloggerGroup](functions/make-static-relogger-group.md)<br />[MakeDynamicAnalyzerGroup](functions/make-dynamic-analyzer-group.md)<br />[MakeDynamicReloggerGroup](functions/make-dynamic-relogger-group.md) |  | A API do C++ fornece tipos e funções auxiliares para agrupar vários objetos do analisador e relogger juntos. Os grupos são uma maneira organizada de dividir uma análise complexa em etapas mais simples. o [vcperf](https://github.com/microsoft/vcperf) é organizado dessa maneira. |
| Analisando ou refazendo o log | [Analisar](functions/analyze.md)<br />[Relog](functions/relog.md) | [AnalyzeA](functions/analyze-a.md)<br />[AnalyzeW](functions/analyze-w.md)<br />[RelogA](functions/relog-a.md)<br />[RelogW](functions/relog-w.md) |  |

### <a name="analyzing-and-relogging"></a>Analisando e refazendo o log

O consumo de um rastreamento é feito por meio de uma sessão de análise ou de uma sessão de reregistro.

O uso de uma análise regular é apropriado para a maioria dos cenários. Esse método oferece a flexibilidade para escolher o formato de saída: `printf` texto, XML, JSON, banco de dados, chamadas REST e assim por diante.

O reregistro em log é para análises de finalidade especial que precisam produzir um arquivo de saída ETW. Usando o relogin, você pode converter os eventos de informações de compilação do C++ em seu próprio formato de evento ETW. Um uso apropriado do registro em log seria vincular dados de informações de compilação do C++ a suas ferramentas e infraestruturas de ETW existentes. Por exemplo, [vcperf](https://github.com/microsoft/vcperf) usa as interfaces de reregistro em log. Isso ocorre porque ele deve produzir dados que o analisador de desempenho do Windows, uma ferramenta ETW, pode entender. Um conhecimento prévio de como o ETW funciona é necessário se você planeja usar as interfaces de registro em log.

### <a name="creating-analyzer-groups"></a>Criando grupos do analisador

É importante saber como criar grupos. Aqui está um exemplo que mostra como criar um grupo do Analyzer que imprime *Olá, mundo!* para cada evento de início de atividade, ele recebe.

```cpp
using namespace Microsoft::Cpp::BuildInsights;

class Hello : public IAnalyzer
{
public:
    AnalysisControl OnStartActivity(
        const EventStack& eventStack) override
    {
        std::cout << "Hello, " << std::endl;
        return AnalysisControl::CONTINUE;
    }
};

class World : public IAnalyzer
{
public:
    AnalysisControl OnStartActivity(
        const EventStack& eventStack) override
    {
        std::cout << "world!" << std::endl;
        return AnalysisControl::CONTINUE;
    }
};

int main()
{
    Hello hello;
    World world;

    // Let's make Hello the first analyzer in the group
    // so that it receives events and prints "Hello, "
    // first.
    auto group = MakeStaticAnalyzerGroup(&hello, &world);

    unsigned numberOfAnalysisPasses = 1;

    // Calling this function initiates the analysis and
    // forwards all events from "inputTrace.etl" to my analyzer
    // group.
    Analyze("inputTrace.etl", numberOfAnalysisPasses, group);

    return 0;
}
```

## <a name="using-events"></a>Usando eventos

### <a name="sdk-types-and-functions-related-to-events"></a>Tipos e funções de SDK relacionados a eventos

| Funcionalidade | API de C++ | API do C | Observações |
|--|--|--|--|
| Correspondência e filtragem de eventos | [MatchEventStackInMemberFunction](functions/match-event-stack-in-member-function.md)<br />[MatchEventStack](functions/match-event-stack.md)<br />[MatchEventInMemberFunction](functions/match-event-in-member-function.md)<br />[MatchEvent](functions/match-event.md) |  | A API do C++ oferece funções que facilitam a extração dos eventos que você se preocupa com seus rastreamentos. Com a C API, essa filtragem deve ser feita manualmente. |
| Tipos de dados de evento | [Atividade](cpp-event-data-types/activity.md)<br />[BackEndPass](cpp-event-data-types/back-end-pass.md)<br />[BottomUp](cpp-event-data-types/bottom-up.md)<br />[C1DLL](cpp-event-data-types/c1-dll.md)<br />[C2DLL](cpp-event-data-types/c2-dll.md)<br />[CodeGeneration](cpp-event-data-types/code-generation.md)<br />[CommandLine](cpp-event-data-types/command-line.md)<br />[Compiler](cpp-event-data-types/compiler.md)<br />[CompilerPass](cpp-event-data-types/compiler-pass.md)<br />[EnvironmentVariable](cpp-event-data-types/environment-variable.md)<br />[Evento](cpp-event-data-types/event.md)<br />[ID](cpp-event-data-types/event-group.md)<br />[EventStack](cpp-event-data-types/event-stack.md)<br />[ExecutableImageOutput](cpp-event-data-types/executable-image-output.md)<br />[ExpOutput](cpp-event-data-types/exp-output.md)<br />[FileInput](cpp-event-data-types/file-input.md)<br />[FileOutput](cpp-event-data-types/file-output.md)<br />[ForceInlinee](cpp-event-data-types/force-inlinee.md)<br />[FrontEndFile](cpp-event-data-types/front-end-file.md)<br />[FrontEndFileGroup](cpp-event-data-types/front-end-file-group.md)<br />[FrontEndPass](cpp-event-data-types/front-end-pass.md)<br />[Função](cpp-event-data-types/function.md)<br />[ImpLibOutput](cpp-event-data-types/imp-lib-output.md)<br />[Invocação](cpp-event-data-types/invocation.md)<br />[InvocationGroup](cpp-event-data-types/invocation-group.md)<br />[LibOutput](cpp-event-data-types/lib-output.md)<br />[Vinculador](cpp-event-data-types/linker.md)<br />[LinkerGroup](cpp-event-data-types/linker-group.md)<br />[LinkerPass](cpp-event-data-types/linker-pass.md)<br />[LTCG](cpp-event-data-types/ltcg.md)<br />[ObjOutput](cpp-event-data-types/obj-output.md)<br />[OptICF](cpp-event-data-types/opt-icf.md)<br />[OptLBR](cpp-event-data-types/opt-lbr.md)<br />[OptRef](cpp-event-data-types/opt-ref.md)<br />[Pass1](cpp-event-data-types/pass1.md)<br />[Pass2](cpp-event-data-types/pass2.md)<br />[PreLTCGOptRef](cpp-event-data-types/pre-ltcg-opt-ref.md)<br />[SimpleEvent](cpp-event-data-types/simple-event.md)<br />[SymbolName](cpp-event-data-types/symbol-name.md)<br />[TemplateInstantiation](cpp-event-data-types/template-instantiation.md)<br />[TemplateInstantiationGroup](cpp-event-data-types/template-instantiation-group.md)<br />[Processo](cpp-event-data-types/thread.md)<br />[TopDown](cpp-event-data-types/top-down.md)<br />[TraceInfo](cpp-event-data-types/trace-info.md)<br />[WholeProgramAnalysis](cpp-event-data-types/whole-program-analysis.md) | [CL_PASS_DATA](c-event-data-types/cl-pass-data-struct.md)<br />[EVENT_COLLECTION_DATA](c-event-data-types/event-collection-data-struct.md)<br />[EVENT_DATA](c-event-data-types/event-data-struct.md)<br />[EVENT_ID](c-event-data-types/event-id-enum.md)<br />[FILE_DATA](c-event-data-types/file-data-struct.md)<br />[FILE_TYPE_CODE](c-event-data-types/file-type-code-enum.md)<br />[FRONT_END_FILE_DATA](c-event-data-types/front-end-file-data-struct.md)<br />[FUNCTION_DATA](c-event-data-types/function-data-struct.md)<br />[FUNCTION_FORCE_INLINEE_DATA](c-event-data-types/function-force-inlinee-data-struct.md)<br />[INVOCATION_DATA](c-event-data-types/invocation-data-struct.md)<br />[INVOCATION_VERSION_DATA](c-event-data-types/invocation-version-data-struct.md)<br />[MSVC_TOOL_CODE](c-event-data-types/msvc-tool-code-enum.md)<br />[NAME_VALUE_PAIR_DATA](c-event-data-types/name-value-pair-data-struct.md)<br />[SYMBOL_NAME_DATA](c-event-data-types/symbol-name-data-struct.md)<br />[TEMPLATE_INSTANTIATION_DATA](c-event-data-types/template-instantiation-data-struct.md)<br />[TEMPLATE_INSTANTIATION_KIND_CODE](c-event-data-types/template-instantiation-kind-code-enum.md)<br />[TRACE_INFO_DATA](c-event-data-types/trace-info-data-struct.md)<br />[TRANSLATION_UNIT_PASS_CODE](c-event-data-types/translation-unit-pass-code-enum.md) |  |

### <a name="activities-and-simple-events"></a>Atividades e eventos simples

Os eventos são fornecidos em duas categorias: *atividades* e *eventos simples* . As atividades são processos contínuos no tempo que têm um início e um fim. Eventos simples são ocorrências de punctual e não têm duração. Ao analisar os rastreamentos de MSVC com o SDK do insights de compilação do C++, você receberá eventos separados quando uma atividade for iniciada e interrompida. Você receberá apenas um evento quando ocorrer um evento simples.

### <a name="parent-child-relationships"></a>Relações pai-filho

Atividades e eventos simples estão relacionados entre si por meio de relações pai-filho. O pai de uma atividade ou evento simples é a atividade de abrangeção na qual elas ocorrem. Por exemplo, ao compilar um arquivo de origem, o compilador precisa analisar o arquivo e, em seguida, gerar o código. As atividades de análise e geração de código são ambos filhos da atividade do compilador.

Eventos simples não têm duração, portanto, nada mais pode acontecer dentro deles. Como tal, eles nunca têm filhos.

As relações pai-filho de cada atividade e evento simples são indicadas na [tabela de eventos](event-table.md). Conhecer essas relações é importante ao consumir eventos de análise do C++. Com freqüência, você precisará confiar neles para entender o contexto completo de um evento.

### <a name="properties"></a>Propriedades

Todos os eventos têm as seguintes propriedades:

| Propriedade | Descrição |
|--|--|
| Identificador de tipo | Um número que identifica exclusivamente o tipo de evento. |
| Identificador de instância | Um número que identifica exclusivamente o evento dentro do rastreamento. Se dois eventos do mesmo tipo ocorrerem em um rastreamento, ambos obterão um identificador de instância exclusivo. |
| Hora de início | A hora em que uma atividade foi iniciada ou a hora em que um evento simples ocorreu. |
| Identificador de processo | Um número que identifica o processo no qual o evento ocorreu. |
| Identificador de thread | Um número que identifica o thread no qual o evento ocorreu. |
| Índice do processador | Um índice de base zero que indica a qual processador lógico o evento foi emitido. |
| Nome do evento | Uma cadeia de caracteres que descreve o tipo de evento. |

Todas as atividades que não sejam eventos simples também têm essas propriedades:

| Propriedade | Descrição |
|--|--|
| Hora de parada | A hora em que a atividade foi interrompida. |
| Duração exclusiva | O tempo gasto em uma atividade, excluindo o tempo gasto em suas atividades filhas. |
| Tempo de CPU | O tempo que a CPU gastou executando código no thread anexado à atividade. Ela não inclui a hora em que o thread anexado à atividade estava em suspensão. |
| Tempo de CPU exclusivo | O mesmo que o tempo de CPU, mas excluindo o tempo de CPU gasto por atividades filhas. |
| Responsabilidade do tempo do relógio do mural | A contribuição da atividade para o tempo geral do relógio de parede. A responsabilidade pelo tempo do relógio leva em conta o paralelismo entre as atividades. Por exemplo, vamos supor que duas atividades não relacionadas sejam executadas em paralelo. Ambos têm uma duração de 10 segundos e exatamente a mesma hora de início e de parada. Nesse caso, a compilação insights atribui uma responsabilidade de tempo de relógio de parede de 5 segundos. Por outro lado, se essas atividades forem executadas uma após a outra sem sobreposição, elas serão atribuídas à responsabilidade de tempo do relógio de parede de 10 segundos. |
| Responsabilidade de tempo do relógio de parede exclusivo | O mesmo que a responsabilidade do tempo do relógio de parede, mas exclui a responsabilidade do tempo do relógio das atividades filhas. |

Alguns eventos têm suas próprias propriedades além das mencionadas. Nesse caso, essas propriedades adicionais são listadas na [tabela de eventos](event-table.md).

### <a name="consuming-events-provided-by-the-c-build-insights-sdk"></a>Consumindo eventos fornecidos pelo SDK do insights de compilação do C++

#### <a name="the-event-stack"></a>A pilha de eventos

Sempre que o SDK do insights de compilação do C++ fornece um evento, ele é fornecido na forma de uma pilha. A última entrada na pilha é o evento atual e as entradas antes que ela seja sua hierarquia pai. Por exemplo, [LTCG](event-table.md#ltcg) iniciar e parar eventos ocorrem durante a passagem 1 do vinculador. Nesse caso, a pilha que você receberia contém: \[ [linker](event-table.md#linker), [PASS1](event-table.md#pass1), LTCG \] . A hierarquia pai é conveniente porque você pode rastrear de volta um evento para sua raiz. Se a atividade LTCG mencionada acima for lenta, você poderá aprender imediatamente qual invocação do vinculador estava envolvida.

#### <a name="matching-events-and-event-stacks"></a>Eventos correspondentes e pilhas de eventos

O SDK da compilação do C++ insights oferece todos os eventos em um rastreamento, mas, na maioria das vezes, você só se preocupa com um subconjunto deles. Em alguns casos, você pode se preocupar apenas com um subconjunto de *pilhas de eventos* . O SDK fornece recursos para ajudá-lo a extrair rapidamente os eventos ou a pilha de eventos de que você precisa e rejeitar aqueles que não tem. Isso é feito por meio dessas funções correspondentes:

| Função | Descrição |
|--|--|
| [MatchEvent](functions/match-event.md) | Mantenha um evento se ele corresponder a um dos tipos especificados. Encaminhe eventos correspondentes para um lambda ou outro tipo que possa ser chamado. A hierarquia pai do evento não é considerada por essa função. |
| [MatchEventInMemberFunction](functions/match-event-in-member-function.md) | Mantenha um evento se ele corresponder ao tipo especificado em um parâmetro de função de membro. Encaminhe eventos correspondentes para a função de membro. A hierarquia pai do evento não é considerada por essa função. |
| [MatchEventStack](functions/match-event-stack.md) | Mantenha um evento se o evento e sua hierarquia pai corresponderem aos tipos especificados. Encaminhe o evento e os eventos de hierarquia pai correspondentes para um lambda ou outro tipo que possa ser chamado. |
| [MatchEventStackInMemberFunction](functions/match-event-stack-in-member-function.md) | Mantenha um evento se o evento e sua hierarquia pai corresponderem aos tipos especificados na lista de parâmetros de uma função de membro. Encaminhe o evento e os eventos de hierarquia pai correspondentes para a função membro. |

A pilha de eventos que corresponde às funções como `MatchEventStack` permitir lacunas ao descrever a hierarquia pai para corresponder. Por exemplo, você pode dizer que está interessado no \[ [vinculador](event-table.md#linker), [LTCG](event-table.md#ltcg) \] Stack. Ele também corresponderia ao \[ vinculador, [PASS1](event-table.md#pass1), LTCG \] Stack. O último tipo especificado deve ser o tipo de evento a ser correspondido e não faz parte da hierarquia pai.

#### <a name="capture-classes"></a>Capturar classes

O uso das `Match*` funções requer que você especifique os tipos que deseja corresponder. Esses tipos são selecionados em uma lista de *classes de captura* . As classes de captura vêm em várias categorias, descritas abaixo.

| Categoria | Descrição |
|--|--|
| Exato | Essas classes de captura são usadas para corresponder a um tipo de evento específico e nenhuma outra. Um exemplo é a classe do [compilador](cpp-event-data-types/compiler.md) , que corresponde ao evento do [compilador](event-table.md#compiler) . |
| Curinga | Essas classes de captura podem ser usadas para corresponder a qualquer evento da lista de eventos aos quais dão suporte. Por exemplo, o curinga de [atividade](cpp-event-data-types/activity.md) corresponde a qualquer evento de atividade. Outro exemplo é o curinga [CompilerPass](cpp-event-data-types/compiler-pass.md) , que pode corresponder à [FRONT_END_PASS](event-table.md#front-end-pass) ou ao evento [BACK_END_PASS](event-table.md#back-end-pass) . |
| Grupo | Os nomes das classes de captura de grupo terminam em *grupo* . Eles são usados para corresponder vários eventos do mesmo tipo em uma linha, ignorando lacunas. Eles fazem sentido apenas ao corresponder eventos recursivos, porque você não sabe quantas existem na pilha de eventos. Por exemplo, a atividade de [FRONT_END_FILE](event-table.md#front-end-file) ocorre toda vez que o compilador analisa um arquivo. Essa atividade é recursiva porque o compilador pode encontrar uma diretiva include enquanto analisa o arquivo. A classe [frontendfile](cpp-event-data-types/front-end-file.md) corresponde a apenas um evento FRONT_END_FILE na pilha. Use a classe [FrontEndFileGroup](cpp-event-data-types/front-end-file-group.md) para corresponder à hierarquia de inclusão inteira. |
| Grupo de curingas | Um grupo de curingas combina as propriedades de curingas e grupos. A única classe dessa categoria é a [chamada](cpp-event-data-types/invocation-group.md)a, que corresponde e captura todos os eventos do [vinculador](event-table.md#linker) e do [compilador](event-table.md#compiler) em uma única pilha de eventos. |

Consulte a [tabela de eventos](event-table.md) para saber quais classes de captura podem ser usadas para corresponder a cada evento.

#### <a name="after-matching-using-captured-events"></a>Após a correspondência: usando eventos capturados

Quando uma correspondência for concluída com êxito, as `Match*` funções construirão os objetos da classe de captura e as encaminharão para a função especificada. Use esses objetos de classe de captura para acessar as propriedades dos eventos.

#### <a name="example"></a>Exemplo

```cpp
AnalysisControl MyAnalyzer::OnStartActivity(const EventStack& eventStack)
{
    // The event types to match are specified in the PrintIncludes function
    // signature.  
    MatchEventStackInMemberFunction(eventStack, this, &MyAnalyzer::PrintIncludes);
}

// We want to capture event stacks where:
// 1. The current event is a FrontEndFile activity.
// 2. The current FrontEndFile activity has at least one parent FrontEndFile activity
//    and possibly many.
void PrintIncludes(FrontEndFileGroup parentIncludes, FrontEndFile currentFile)
{
    // Once we reach this point, the event stack we are interested in has been matched.
    // The current FrontEndFile activity has been captured into 'currentFile', and
    // its entire inclusion hierarchy has been captured in 'parentIncludes'.

    cout << "The current file being parsed is: " << currentFile.Path() << endl;
    cout << "This file was reached through the following inclusions:" << endl;

    for (auto& f : parentIncludes)
    {
        cout << f.Path() << endl;
    }
}
```

::: moniker-end
