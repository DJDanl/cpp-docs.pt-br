---
title: C++ Build Insights SDK
description: Uma visão geral do Visual Studio C++ Build Insights SDK.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Analyzing
- Relogging
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 126abb0d039227eb269500966d46ef0a729763ee
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323258"
---
# <a name="c-build-insights-sdk"></a>C++ Build Insights SDK

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

O C++ Build Insights SDK é uma coleção de APIs que permitem criar ferramentas personalizadas em cima da plataforma C++ Build Insights. Esta página fornece uma visão geral de alto nível para ajudá-lo a começar.

## <a name="obtaining-the-sdk"></a>Obtenção do SDK

Você pode baixar o C++ Build Insights SDK como um pacote NuGet seguindo estas etapas:

1. Do Visual Studio 2017 e acima, crie um novo projeto C++.
1. No **painel Solution Explorer,** clique com o botão direito do mouse no seu projeto.
1. Selecione **Gerenciar pacotes NuGet** no menu de contexto.
1. No canto superior direito, selecione a fonte **do pacote nuget.org.**
1. Procure a versão mais recente do pacote Microsoft.Cpp.BuildInsights.
1. Escolha **Instalar**.
1. Aceite a licença.

Continue lendo para obter informações sobre os conceitos gerais em torno do SDK. Você também pode acessar o [c++ build insights oficial amostras do repositório GitHub](https://github.com/microsoft/cpp-build-insights-samples) para ver exemplos de aplicativos C++ reais que usam o SDK.

## <a name="collecting-a-trace"></a>Coletando um traço

O uso do C++ Build Insights SDK para analisar eventos que saem da cadeia de ferramentas MSVC requer que você primeiro colete um rastreamento. O SDK faz uso do Event Tracing for Windows (ETW) como a tecnologia de rastreamento subjacente. A coleta de um rastreamento pode ser feita de duas maneiras:

### <a name="method-1-using-vcperf-in-visual-studio-2019-and-above"></a>Método 1: usar vcperf no Visual Studio 2019 e acima

1. Abra um prompt de comando de ferramentas nativas x64 elevado para VS 2019.
1. Execute o seguinte comando: `vcperf /start MySessionName`
1. Compile o projeto.
1. Execute o seguinte comando: `vcperf /stopnoanalyze MySessionName outputTraceFile.etl`

   > [!IMPORTANT]
   > Use `/stopnoanalyze` o comando ao parar seu rastreamento com vcperf. Você não pode usar o C++ Build Insights SDK `/stop` para analisar os traços parados pelo comando regular.

### <a name="method-2-programmatically"></a>Método 2: programática

Use qualquer uma dessas funções de coleta de rastreamento C++ Build Insights SDK para iniciar e interromper rastreamentos programáticamente. **O programa que executa essas chamadas de função deve ter privilégios administrativos.** Apenas as funções de início e parada de rastreamento exigem privilégios administrativos. Todas as outras funções do C++ Build Insights SDK podem ser executadas sem elas.

### <a name="sdk-functions-related-to-trace-collection"></a>Funções de SDK relacionadas à coleta de vestígios

| Funcionalidade | API de C++ | API do C |
|--|--|--|
| Começando um rastreamento | [Sessão de starttracing](functions/start-tracing-session.md) | [StartTracingSessionA](functions/start-tracing-session-a.md)<br />[StartTracingSessionW](functions/start-tracing-session-w.md) |
| Parando um rastro | [StopTracingSession](functions/stop-tracing-session.md) | [StopTracingSessionA](functions/stop-tracing-session-a.md)<br />[StopTracingSessionW](functions/stop-tracing-session-w.md) |
| Parando um rastro e<br />imediatamente analisando o resultado | [StopAndAnalyzeTracingSession](functions/stop-and-analyze-tracing-session.md) | [StopAndAnalyzeTracingSessionA](functions/stop-and-analyze-tracing-session-a.md)<br />[StopAndAnalyzeTracingSession](functions/stop-and-analyze-tracing-session-w.md) |
| Parando um rastro e<br />imediatamente readiando o resultado | [StopAndRelogTracingSession](functions/stop-and-relog-tracing-session.md) | [StopAndRelogTracingSessionA](functions/stop-and-relog-tracing-session-a.md)<br />[StopAndRelogTracingSessionW](functions/stop-and-relog-tracing-session-w.md) |

As seções a seguir mostram como configurar uma análise ou uma sessão de relogamento. É necessário para as funções de funcionalidade combinadas, como [StopAndAnalyzeTracingSession](functions/stop-and-analyze-tracing-session.md).

## <a name="consuming-a-trace"></a>Consumindo um traço

Depois de ter um rastreamento de ETW, use o C++ Build Insights SDK para desempacotá-lo. O SDK oferece os eventos em um formato que permite que você desenvolva suas ferramentas rapidamente. Não recomendamos que você consuma o traço eTW bruto sem usar o SDK. O formato de evento usado pelo MSVC é indocumentado, otimizado para escalar para grandes construções, e difícil de entender. Além disso, a API C++ Build Insights SDK é estável, enquanto o formato de rastreamento ETW bruto está sujeito a alterações sem aviso prévio.

### <a name="sdk-types-and-functions-related-to-trace-consumption"></a>Tipos e funções de SDK relacionadas ao consumo de vestígios

| Funcionalidade | API de C++ | API do C | Observações |
|--|--|--|--|
| Configuração de retornos de eventos | [IAnalyzer](other-types/ianalyzer-class.md)<br />[IRelogger](other-types/irelogger-class.md) | [ANALYSIS_CALLBACKS](other-types/analysis-callbacks-struct.md)<br />[RELOG_CALLBACKS](other-types/relog-callbacks-struct.md) | O C++ Build Insights SDK fornece eventos através de funções de retorno de chamada. Em C++, implemente as funções de retorno de chamada criando uma classe de analisador ou relogger que herde a interface IAnalyzer ou IRelogger. Em C, implementar os retornos de chamadas em funções globais e fornecer ponteiros para eles na estrutura ANALYSIS_CALLBACKS ou RELOG_CALLBACKS. |
| Construindo grupos | [MakeStaticAnalyzerGroup](functions/make-static-analyzer-group.md)<br />[MakeStaticReloggerGroup](functions/make-static-relogger-group.md)<br />[MakeDynamicAnalyzerGroup](functions/make-dynamic-analyzer-group.md)<br />[MakeDynamicReloggerGroup](functions/make-dynamic-relogger-group.md) |  | A API C++ fornece funções e tipos auxiliares para agrupar vários objetos analisadores e relogger. Os grupos são uma maneira limpa de dividir uma análise complexa em etapas mais simples. [vcperf](https://github.com/microsoft/vcperf) é organizado desta forma. |
| Analisando ou readiando | [Analisar](functions/analyze.md)<br />[Relog](functions/relog.md) | [AnalyzeA](functions/analyze-a.md)<br />[AnalyzeW](functions/analyze-w.md)<br />[Reloga](functions/relog-a.md)<br />[RelogW](functions/relog-w.md) |  |

### <a name="analyzing-and-relogging"></a>Analisando e readiando

O consumo de um rastreamento é feito através de uma sessão de análise ou de uma sessão de relogamento.

O uso de uma análise regular é apropriado para a maioria dos cenários. Este método lhe dá a flexibilidade `printf` para escolher o seu formato de saída: texto, xml, JSON, banco de dados, chamadas REST e assim por diante.

O relogamento é para análises de propósito especial que precisam produzir um arquivo de saída ETW. Usando o relogamento, você pode traduzir os eventos C++ Build Insights em seu próprio formato de evento ETW. Um uso apropriado do relogamento seria conectar os dados do C++ Build Insights às ferramentas e infra-estrutura de ETW existentes. Por exemplo, [vcperf](https://github.com/microsoft/vcperf) faz uso das interfaces de relogging. Isso porque ele deve produzir dados que o Analisador de Desempenho do Windows, uma ferramenta eTW, pode entender. Algum conhecimento prévio de como o ETW funciona é necessário se você planeja usar as interfaces de relogamento.

### <a name="creating-analyzer-groups"></a>Criando grupos de analisadores

É importante saber como criar grupos. Aqui está um exemplo que mostra como criar um grupo analisador que imprime *Hello, world!* para cada evento de início de atividade que recebe.

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

### <a name="sdk-types-and-functions-related-to-events"></a>Tipos e funções de SDK relacionadas a eventos

| Funcionalidade | API de C++ | API do C | Observações |
|--|--|--|--|
| Eventos de correspondência e filtragem | [MatchEventStackInMemberfunction](functions/match-event-stack-in-member-function.md)<br />[MatchEventStack](functions/match-event-stack.md)<br />[MatcheventInMemberfunction](functions/match-event-in-member-function.md)<br />[MatchEvent](functions/match-event.md) |  | A API C++ oferece funções que facilitam a extração dos eventos com os seus traços. Com a API C, esta filtragem deve ser feita manualmente. |
| Tipos de dados de eventos | [Atividade](cpp-event-data-types/activity.md)<br />[BackEndPass](cpp-event-data-types/back-end-pass.md)<br />[Bottomup](cpp-event-data-types/bottom-up.md)<br />[C1DLL](cpp-event-data-types/c1-dll.md)<br />[C2DLL](cpp-event-data-types/c2-dll.md)<br />[Codegeneration](cpp-event-data-types/code-generation.md)<br />[Commandline](cpp-event-data-types/command-line.md)<br />[Compilador](cpp-event-data-types/compiler.md)<br />[CompilerPass](cpp-event-data-types/compiler-pass.md)<br />[EnvironmentVariable](cpp-event-data-types/environment-variable.md)<br />[Evento](cpp-event-data-types/event.md)<br />[EventGroup](cpp-event-data-types/event-group.md)<br />[EventStack](cpp-event-data-types/event-stack.md)<br />[ExecutávelImageOutput](cpp-event-data-types/executable-image-output.md)<br />[ExpOutput](cpp-event-data-types/exp-output.md)<br />[Entrada de arquivos](cpp-event-data-types/file-input.md)<br />[Saída de arquivos](cpp-event-data-types/file-output.md)<br />[ForceInlinee](cpp-event-data-types/force-inlinee.md)<br />[FrontEndFile](cpp-event-data-types/front-end-file.md)<br />[FrontEndFileGroup](cpp-event-data-types/front-end-file-group.md)<br />[FrontendPass](cpp-event-data-types/front-end-pass.md)<br />[Função](cpp-event-data-types/function.md)<br />[Saída implib](cpp-event-data-types/imp-lib-output.md)<br />[Invocação](cpp-event-data-types/invocation.md)<br />[Grupo de Invocação](cpp-event-data-types/invocation-group.md)<br />[LibOutput](cpp-event-data-types/lib-output.md)<br />[Vinculador](cpp-event-data-types/linker.md)<br />[LinkerGroup](cpp-event-data-types/linker-group.md)<br />[LinkerPass](cpp-event-data-types/linker-pass.md)<br />[Ltcg](cpp-event-data-types/ltcg.md)<br />[ObjOutput](cpp-event-data-types/obj-output.md)<br />[OptICF](cpp-event-data-types/opt-icf.md)<br />[OptLBR](cpp-event-data-types/opt-lbr.md)<br />[OptRef](cpp-event-data-types/opt-ref.md)<br />[Passe1](cpp-event-data-types/pass1.md)<br />[Passe2](cpp-event-data-types/pass2.md)<br />[PreLTCGOptRef](cpp-event-data-types/pre-ltcg-opt-ref.md)<br />[Evento simples](cpp-event-data-types/simple-event.md)<br />[Nome do Símbolo](cpp-event-data-types/symbol-name.md)<br />[Instantiação do modelo](cpp-event-data-types/template-instantiation.md)<br />[TemplateInstantiationGroup](cpp-event-data-types/template-instantiation-group.md)<br />[Thread](cpp-event-data-types/thread.md)<br />[Topdown](cpp-event-data-types/top-down.md)<br />[Traceinfo](cpp-event-data-types/trace-info.md)<br />[Análise de Programas Inteiros](cpp-event-data-types/whole-program-analysis.md) | [CL_PASS_DATA](c-event-data-types/cl-pass-data-struct.md)<br />[EVENT_COLLECTION_DATA](c-event-data-types/event-collection-data-struct.md)<br />[EVENT_DATA](c-event-data-types/event-data-struct.md)<br />[EVENT_ID](c-event-data-types/event-id-enum.md)<br />[FILE_DATA](c-event-data-types/file-data-struct.md)<br />[FILE_TYPE_CODE](c-event-data-types/file-type-code-enum.md)<br />[FRONT_END_FILE_DATA](c-event-data-types/front-end-file-data-struct.md)<br />[FUNCTION_DATA](c-event-data-types/function-data-struct.md)<br />[FUNCTION_FORCE_INLINEE_DATA](c-event-data-types/function-force-inlinee-data-struct.md)<br />[INVOCATION_DATA](c-event-data-types/invocation-data-struct.md)<br />[INVOCATION_VERSION_DATA](c-event-data-types/invocation-version-data-struct.md)<br />[MSVC_TOOL_CODE](c-event-data-types/msvc-tool-code-enum.md)<br />[NAME_VALUE_PAIR_DATA](c-event-data-types/name-value-pair-data-struct.md)<br />[SYMBOL_NAME_DATA](c-event-data-types/symbol-name-data-struct.md)<br />[TEMPLATE_INSTANTIATION_DATA](c-event-data-types/template-instantiation-data-struct.md)<br />[TEMPLATE_INSTANTIATION_KIND_CODE](c-event-data-types/template-instantiation-kind-code-enum.md)<br />[TRACE_INFO_DATA](c-event-data-types/trace-info-data-struct.md)<br />[TRANSLATION_UNIT_PASS_CODE](c-event-data-types/translation-unit-pass-code-enum.md) |  |

### <a name="activities-and-simple-events"></a>Atividades e eventos simples

Os eventos vêm em duas categorias: *atividades* e *eventos simples.* As atividades são processos contínuos no tempo que têm um começo e um fim. Eventos simples são ocorrências pontuais e não têm duração. Ao analisar os traços do MSVC com o C++ Build Insights SDK, você receberá eventos separados quando uma atividade é iniciada e parada. Você receberá apenas um evento quando um evento simples ocorrer.

### <a name="parent-child-relationships"></a>Relações entre pais e filhos

Atividades e eventos simples estão relacionados entre si através de relacionamentos entre pais e filhos. O pai de uma atividade ou evento simples é a atividade abrangente em que ocorrem. Por exemplo, ao compilar um arquivo fonte, o compilador tem que analisar o arquivo e, em seguida, gerar o código. As atividades de análise e geração de código são ambas as crianças da atividade do compilador.

Eventos simples não têm duração, então nada mais pode acontecer dentro deles. Como tal, eles nunca têm filhos.

As relações pai-filho de cada atividade e evento simples são indicadas na [tabela de eventos](event-table.md). Conhecer esses relacionamentos é importante ao consumir eventos C++ Build Insights. Muitas vezes você terá que confiar neles para entender o contexto completo de um evento.

### <a name="properties"></a>Propriedades

Todos os eventos têm as seguintes propriedades:

| Propriedade | Descrição |
|--|--|
| Identificador de tipo | Um número que identifica exclusivamente o tipo de evento. |
| Identificador de instância | Um número que identifica exclusivamente o evento dentro do traço. Se dois eventos do mesmo tipo ocorrerem em um rastreamento, ambos obterão um identificador de instância único. |
| Hora de início | O momento em que uma atividade começou, ou a hora em que um evento simples ocorreu. |
| Identificador de processo | Um número que identifica o processo em que o evento ocorreu. |
| Identificador de segmento | Um número que identifica o segmento em que o evento ocorreu. |
| Índice do processador | Um índice baseado em zero indicando qual processador lógico o evento foi emitido. |
| Nome do evento | Uma seqüência que descreve o tipo de evento. |

Todas as atividades que não sejam eventos simples também possuem essas propriedades:

| Propriedade | Descrição |
|--|--|
| Hora de parar | O tempo em que a atividade parou. |
| Duração exclusiva | O tempo gasto em uma atividade, excluindo o tempo gasto em suas atividades infantis. |
| Tempo de CPU | O tempo que a CPU passou executando o código no segmento anexado à atividade. Não inclui o tempo em que o fio ligado à atividade estava dormindo. |
| Tempo exclusivo da CPU | O mesmo que o tempo da CPU, mas excluindo o tempo da CPU gasto pelas atividades do filho. |
| Responsabilidade do relógio de parede | A contribuição da atividade para o tempo geral do relógio de parede. A responsabilidade do tempo de parede leva em conta o paralelismo entre as atividades. Por exemplo, vamos supor que duas atividades não relacionadas sejam executadas em paralelo. Ambos têm uma duração de 10 segundos, e exatamente o mesmo tempo de partida e parada. Neste caso, o Build Insights atribui a ambos uma responsabilidade de tempo de relógio de parede de 5 segundos. Em contraste, se essas atividades são executadas uma após a outra sem sobreposição, ambas são atribuídas uma responsabilidade de tempo de parede de 10 segundos. |
| Responsabilidade exclusiva do relógio de parede | O mesmo que a responsabilidade do relógio de parede, mas exclui a responsabilidade do tempo de parede-relógio das atividades infantis. |

Alguns eventos têm suas próprias propriedades além das mencionadas. Neste caso, essas propriedades adicionais estão listadas na [tabela de eventos](event-table.md).

### <a name="consuming-events-provided-by-the-c-build-insights-sdk"></a>Eventos de consumo fornecidos pelo C++ Build Insights SDK

#### <a name="the-event-stack"></a>A pilha de eventos

Sempre que o C++ Build Insights SDK lhe dá um evento, ele vem na forma de uma pilha. A última entrada na pilha é o evento atual, e as entradas antes dele são sua hierarquia de pais. Por exemplo, eventos de início e parada do [LTCG](event-table.md#ltcg) ocorrem durante a passagem 1 do linker. Neste caso, a pilha que você \[receberia contém: [LINKER](event-table.md#linker), [PASS1](event-table.md#pass1), LTCG\]. A hierarquia dos pais é conveniente porque você pode rastrear um evento até sua raiz. Se a atividade LTCG mencionada acima for lenta, você pode saber imediatamente qual invocação do linker estava envolvida.

#### <a name="matching-events-and-event-stacks"></a>Correspondência de eventos e pilhas de eventos

O C++ Build Insights SDK oferece todos os eventos em um rastreamento, mas na maioria das vezes você só se importa com um subconjunto deles. Em alguns casos, você só pode se importar com um subconjunto de *pilhas*de eventos . O SDK fornece facilidades para ajudá-lo a extrair rapidamente os eventos ou pilha de eventos que você precisa e rejeitar os que você não precisa. É feito através dessas funções correspondentes:

|  |  |
|--|--|
| [MatchEvent](functions/match-event.md) | Mantenha um evento se corresponder a um dos tipos especificados. Eventos compatíveis com a frente para um lambda ou outro tipo callable. A hierarquia dos pais do evento não é considerada por esta função. |
| [MatcheventInMemberfunction](functions/match-event-in-member-function.md) | Mantenha um evento se corresponder ao tipo especificado no parâmetro de uma função de membro. Avançar eventos compatíveis com a função de membro. A hierarquia dos pais do evento não é considerada por esta função. |
| [MatchEventStack](functions/match-event-stack.md) | Mantenha um evento se o evento e sua hierarquia de pais coincidirem com os tipos especificados. Encaminhe o evento e os eventos de hierarquia dos pais combinados para um lambda ou outro tipo callable. |
| [MatchEventStackInMemberfunction](functions/match-event-stack-in-member-function.md) | Mantenha um evento se o evento e sua hierarquia de pais corresponderem aos tipos especificados na lista de parâmetros de uma função de membro. Encaminhe o evento e os eventos de hierarquia dos pais combinados para a função de membro. |

As funções de `MatchEventStack` correspondência de pilha de eventos, como permitir lacunas ao descrever a hierarquia dos pais para corresponder. Por exemplo, você pode dizer que \[está interessado na pilha [LINKER](event-table.md#linker), [LTCG.](event-table.md#ltcg) \] Também corresponderia \[à pilha LINKER,\] [PASS1,](event-table.md#pass1)LTCG. O último tipo especificado deve ser o tipo de evento a combinar e não faz parte da hierarquia dos pais.

#### <a name="capture-classes"></a>Classes de captura

O `Match*` uso das funções requer que você especifique os tipos que deseja corresponder. Esses tipos são selecionados a partir de uma lista de classes de *captura*. As aulas de captura vêm em várias categorias, descritas abaixo.

| Categoria | Descrição |
|--|--|
| Exato | Essas classes de captura são usadas para corresponder a um tipo específico de evento e nenhuma outra. Um exemplo é a classe [Compilador,](cpp-event-data-types/compiler.md) que corresponde ao evento [COMPILER.](event-table.md#compiler) |
| Curinga | Essas classes de captura podem ser usadas para corresponder a qualquer evento da lista de eventos que eles suportam. Por exemplo, o [curinga Atividade](cpp-event-data-types/activity.md) corresponde a qualquer evento de atividade. Outro exemplo é o [curinga CompilerPass,](cpp-event-data-types/compiler-pass.md) que pode corresponder tanto ao [FRONT_END_PASS](event-table.md#front-end-pass) quanto ao evento [BACK_END_PASS.](event-table.md#back-end-pass) |
| Agrupar | Os nomes das classes de captura de grupo terminam em *Grupo*. Eles são usados para combinar vários eventos do mesmo tipo em uma fileira, ignorando lacunas. Eles só fazem sentido ao combinar eventos recursivos, porque você não sabe quantos existem na pilha de eventos. Por exemplo, a atividade [FRONT_END_FILE](event-table.md#front-end-file) acontece toda vez que o compilador analisa um arquivo. Esta atividade é recursiva porque o compilador pode encontrar uma diretiva de inclusão enquanto está analisar o arquivo. A classe [FrontEndFile](cpp-event-data-types/front-end-file.md) corresponde a apenas um evento FRONT_END_FILE na pilha. Use a classe [FrontEndFileGroup](cpp-event-data-types/front-end-file-group.md) para corresponder a toda a hierarquia de incluir. |
| Grupo curinga | Um grupo curinga combina as propriedades de curingas e grupos. A única classe desta categoria é [o InvocationGroup](cpp-event-data-types/invocation-group.md), que corresponde e captura todos os eventos [LINKER](event-table.md#linker) e [COMPILER](event-table.md#compiler) em uma única pilha de eventos. |

Consulte a tabela do [evento](event-table.md) para saber quais classes de captura podem ser usadas para corresponder a cada evento.

#### <a name="after-matching-using-captured-events"></a>Após a correspondência: usando eventos capturados

Uma vez que uma `Match*` correspondência é concluída com sucesso, as funções constroem os objetos da classe de captura e os encaminham para a função especificada. Use esses objetos de classe de captura para acessar as propriedades dos eventos.

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
