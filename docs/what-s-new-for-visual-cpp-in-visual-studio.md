---
title: Novidades do Visual C++ no Visual Studio | Microsoft Docs
ms.custom: 
ms.date: 8/2/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- vs-ide-general
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 8801dbdb-ca0b-491f-9e33-01618bff5ae9
author: mblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: b90891be2ca726bb6cdd28d024cda68494e69af4
ms.openlocfilehash: 9103da7fb4e10553d2558b15a24bc6a894dd1eff
ms.contentlocale: pt-br
ms.lasthandoff: 08/15/2017

---

# <a name="whats-new-for-visual-c-in-includevsdev15mdmiscincludesvsdev15mdmd"></a>Novidades do Visual C++ no [!INCLUDE[vs_dev15_md](misc/includes/vs_dev15_md.md)]

[!INCLUDE[vs_dev15_md](misc/includes/vs_dev15_md.md)] traz muitas atualizações e correções para o ambiente do Visual C++. Corrigimos mais de 250 bugs e problemas relatados no compilador e nas ferramentas, muitas enviadas pelos clientes através do [Microsoft Connect](https://connect.microsoft.com/VisualStudio "Microsoft Connect"). Obrigado por relatar bugs!  Para obter mais informações sobre todas as novidades do Visual Studio, visite [Novidades no [!INCLUDE[vs_dev15_md](misc/includes/vs_dev15_md.md)]](https://go.microsoft.com/fwlink/?linkid=834481).

<!--The compiler and tools version number in [!INCLUDE[vs_dev15_md](misc/includes/vs_dev15_md.md)] is 14.10.24629. -->


## <a name="c-compiler"></a>Compilador C++

### <a name="c-conformance-improvements"></a>Aprimoramentos de conformidade do C++
Nesta versão, atualizamos o compilador do C++ e a biblioteca padrão com suporte aprimorado para os recursos C++11 e C++14, bem como o suporte preliminar para determinados recursos esperados no padrão C++ 17. Para obter informações detalhadas, consulte [Aprimoramentos de conformidade do C++ no Visual Studio 2017](cpp-conformance-improvements-2017.md).

### <a name="new-compiler-switches"></a>Novas opções de compilador  

 -**/std:c++14** and **/std:c++latest**: essas opções de compilador habilitam a opção por versões específicas da linguagem de programação de ISO C++ em um projeto. Para saber mais, veja [-std (especificar versão de idioma padrão)](build/reference/std-specify-language-standard-version.md). A maioria dos recursos padrão de rascunho estão protegidos pela opção //std:c++latest. 

**Visual Studio 2017 versão 15.3**: a opção **/std:c++17** habilita o conjunto de recursos do C++17 implementado pelo compilador do Visual C++. Esta opção desabilita o suporte ao compilador e à biblioteca padrão para recursos que são alterados ou novos em versões mais recentes das atualizações de defeito e rascunho de trabalho do padrão C++.

-[/permissive-](build/reference/permissive-standards-conformance.md): habilitar todas as opções de compilador de conformidade estrita com os padrões e desabilitar a maioria das extensões de compilador específicas da Microsoft (mas não __declspec(dllimport), por exemplo). (Desativada por padrão, mas será ativada por padrão em algum momento no futuro.)

-[/diagnostics](build/reference/diagnostics-compiler-diagnostic-options.md): habilitar a exibição do número de linha, do número de linha e da coluna ou do número de linha e da coluna e um cursor sob a linha de código em que o diagnóstico de erro ou aviso foi encontrado.

-[/debug:fastlink](build/reference/debug-generate-debug-info.md):  
Habilitar tempo de vinculação incremental até 30% mais rápido (em relação ao Visual Studio 2015) ao não copiar todas as informações de depuração para o arquivo PDB. Em vez disso, o arquivo PDB aponta para as informações de depuração para os arquivos de biblioteca e de objeto usados para criar o executável. Consulte [Ciclo de build do C++ mais rápido no VS "15" com /Debug:fastlink](https://blogs.msdn.microsoft.com/vcblog/2016/10/05/faster-c-build-cycle-in-vs-15-with-debugfastlink/) e [Recomendações para acelerar compilações do C++ no Visual Studio](https://blogs.msdn.microsoft.com/vcblog/2016/10/26/recommendations-to-speed-c-builds-in-visual-studio/).

O [!INCLUDE[vs_dev15_md](misc/includes/vs_dev15_md.md)] permite o uso de /sdl com /await. Removemos a limitação /RTC com Co-rotinas. 

### <a name="codegen-security-diagnostics-and-versioning"></a>Geração de código, segurança, diagnóstico e controle de versão
Esta versão apresenta várias melhorias na otimização, na geração de código, no controle de versão do conjunto de ferramentas e nos diagnósticos. Alguns aprimoramentos importantes incluem:  

- Melhor geração de código de loops: suporte para vetorização automática da divisão de inteiros constantes, melhor identificação de padrões de memset.
- Segurança de código aperfeiçoada: melhor emissão de diagnóstico do compilador de estouro de buffer e o /guard:cf agora protege instruções de troca que geram uma tabela de jump.
- Controle de versão: o valor da macro do pré-processador interna _MSC_VER está sendo monotonicamente atualizado a cada atualização do conjunto de ferramentas do Visual C++. Para obter mais informações, consulte [Versão do compilador do Visual C++](https://blogs.msdn.microsoft.com/vcblog/2016/10/05/visual-c-compiler-version/).
- Novo layout do conjunto de ferramentas: o compilador e as ferramentas de build relacionadas têm um novo local e nova estrutura de diretório em seu computador de desenvolvimento. O novo layout habilita instalações lado a lado de várias versões do compilador. Para obter mais informações, consulte [Layout de ferramentas do compilador no Visual Studio "15"](https://blogs.msdn.microsoft.com/vcblog/2016/10/07/compiler-tools-layout-in-visual-studio-15/).
- Diagnósticos aprimorados: a janela de saída agora mostra a coluna em que ocorre um erro. Para obter mais informações, consulte [Aprimoramentos de diagnóstico do compilador do C++ no VS "15" Preview 5](https://blogs.msdn.microsoft.com/vcblog/2016/10/05/c-compiler-diagnostics-improvements-in-vs-15-rc/).
- Ao usar corrotinas, a palavra-chave experimental "yield" (disponível na opção /await) foi removida. Em vez disso, seu código deve ser atualizado para usar `co_yield`. Para obter mais informações, consulte [Blog da equipe do Visual C++](https://blogs.msdn.microsoft.com/vcblog/). 

**Visual Studio 2017 versão 15.3**: aprimoramentos adicionais para o diagnóstico no compilador. Para saber mais, confira [Aperfeiçoamentos de diagnóstico no Visual Studio 2017 15.3.0](https://blogs.msdn.microsoft.com/vcblog/2017/07/21/diagnostic-improvements-in-vs2017-15-3-0/).

## <a name="c-libraries"></a>Bibliotecas C++

### <a name="standard-library-improvements"></a>Aprimoramentos da Biblioteca Padrão:

* Pequenas melhorias no diagnóstico de basic_string _ITERATOR_DEBUG_LEVEL != 0. Acionar uma verificação de IDL no mecanismo de cadeia de caracteres agora relatará o comportamento específico que acionou a verificação. Por exemplo, em vez de "não é possível desreferenciar o iterador de cadeia de caracteres", você verá "não é possível desreferenciar o iterador de cadeia de caracteres porque ele está fora do intervalo (por exemplo, um iterador de fim)".
* Melhoria de desempenho: sobrecargas de basic_string::find(char) chamam traits::find apenas uma vez. Anteriormente, isso era implementado como uma pesquisa de cadeia de caracteres geral para de uma cadeia de caracteres de comprimento 1.
* Melhoria de desempenho: basic_string::operator== agora verifica o tamanho da cadeia de caracteres antes de comparar o conteúdo das cadeias de caracteres.
* Melhoria de desempenho: removido o acoplamento de controle em basic_string, que dificultava a análise do otimizador do compilador. Resolve a \<string\> VSO# 262848 ": reserve() does too much work". Observe que, para todas as cadeias de caracteres curtas, chamar a reserva ainda não tem nenhum custo por não fazer nada.
* Adicionamos \<any\>, \<string_view\>, apply(), make_from_tuple().
* std::vector foi revisado para fazer correções e melhorar o desempenho: a suavização durante a inserção/posicionamento agora é tratada corretamente como exigido por padrão, a garantia de exceção forte agora é fornecida quando exigido pelo padrão por meio de move_if_noexcept() e outra lógica e inserção/posicionamento executa menos operações de elemento.
* A Biblioteca Padrão do C++ agora evita desrreferenciar ponteiros nulos sofisticados.
* Adicionados \<opcional\>, \<variante\>, shared_ptr::weak_type e \<cstdalign\>.
* Habilitado o C++14 constexpr em min/max/minmax(initializer_list) e o min_element/max_element/minmax_element().
* Melhor desempenho do weak_ptr::lock().
* O operador de atribuição de mudança do std::promise foi corrigido, pois anteriormente poderia causar bloqueio indefinido no código.
* Erros de compilador corrigidos, com a conversão implícita atômica de \<T \*\> para T \*.
* pointer_traits\<Ptr\> agora detecta corretamente Ptr::rebind\<U\>.
* Corrigido um qualificador const ausente no operador de subtração do move_iterator.
* Corrigida a geração silenciosa de código incorreta em alocadores definidos pelo usuário com monitoração de estado, solicitando propagate_on_container_copy_assignment e propagate_on_container_move_assignment.
* O atômico\<T\> agora tolera o operator&() sobrecarregado.
* Para aumentar a taxa de transferência do compilador, os cabeçalhos da Biblioteca Padrão do C++ agora evitam incluir declarações para intrínsecos do compilador que são desnecessários.
* Alguma melhoria do diagnóstico do compilador para chamadas bind() incorretas.
* O desempenho dos construtores de movimentação do std::string/std::wstring foram aprimorados em mais de três vezes
* Para obter uma lista completa de aprimoramentos da Biblioteca Padrão, veja as [Correções da Biblioteca Padrão no VS 2017 RTM](https://blogs.msdn.microsoft.com/vcblog/2017/02/06/stl-fixes-in-vs-2017-rtm/).

#### <a name="visual-studio-2017-version-153"></a>Visual Studio 2017 versão 15.3

##### <a name="c17-features"></a>Recursos C++17 
Vários recursos adicionais do C++17 foram implementados. Para saber mais, veja [Conformidade com a linguagem Visual C++](visual-cpp-language-conformance.md).

##### <a name="other-new-features"></a>Outros recursos novos
* Implementado P0602R0 "variante e opcional devem propagar a trivialidade copiar/mover".
* A Biblioteca Padrão agora oficialmente tolera RTTI dinâmico sendo desabilitado via /GR-. dynamic_pointer_cast() e rethrow_if_nested() inerentemente exigem dynamic_cast, de modo que a Biblioteca Padrão agora os marca como =delete em /GR-.
* Mesmo quando o RTTI dinâmico tiver sido desabilitado por meio de /GR-, "static RTTI" (na forma de typeid(SomeType)) ainda está disponível e é utilizado por vários componentes da Biblioteca Padrão. A Biblioteca Padrão agora também dá suporte a desativá-lo, por meio de /D_HAS_STATIC_RTTI=0. *Observe que isso irá desabilitar target() e target_type() de std::any, std::function, e get_deleter() do shared_ptr.*

##### <a name="correctness-fixes"></a>Correções de exatidão
* Os contêineres da Biblioteca Padrão agora fixam seus max_size() como numeric_limits\<difference_type\>::max() em vez de max do size_type. Isso garante que o resultado de distance() em iteradores do contêiner seja representável no tipo de retorno de distance().
* Corrigida a especialização ausente auto_ptr\<void\>.
* Os algoritmos de meow_n() anteriormente não conseguiam ser compilados se o argumento de comprimento não era um tipo integral; eles agora tentarão converter comprimentos não integrais para o difference_type dos iteradores.
* normal_distribution\<float\> não emite mais avisos dentro da Biblioteca Padrão sobre o estreitamento de double para float.
* Corrigidas algumas operações basic_string que estavam comparando com npos em vez de max_size() durante a verificação de estouro de tamanho máximo.
* condition_variable::wait_for(lock, relative_time, predicate) aguardaria o tempo relativo todo no caso de uma ativação falsa. Agora ele aguardará apenas um único intervalo do tempo relativo.
* future::get() agora invalida o futuro, como o padrão exige.
* iterator_traits\<void \*\> era um erro de hardware porque tentou formar void&;; agora claramente torna-se uma estrutura vazia para permitir o uso de iterator_traits em condições SFINAE "is iterator".
* Alguns avisos relatados pelo Clang -Wsystem-headers foram corrigidos.
* Também corrigida a "especificação de exceção na declaração não corresponde à declaração anterior" relatado por Clang -Wmicrosoft-exception-spec.
* Também corrigidos os avisos de ordenação mem-initializer-list relatados por Clang e C1XX.
* Os contêineres não ordenados não trocavam seus hashers ou predicados quando os próprios contêineres eram trocados. Agora eles fazem isso.
* Muitas operações de troca de contêiner agora são marcadas noexcept (como a Biblioteca Padrão nunca pretende lançar uma exceção ao detectar a condição de um comportamento indefinido non-propagate_on_container_swap non-equal-allocator).
* Muitas operações vetor\<bool\> agora estão marcadas como noexcept.
* A Biblioteca Padrão agora imporá o alocador de correspondência value_types (em modo C++17) com uma trava de escape de recusa.
* Corrigidas algumas condições onde self-range-insert em basic_strings misturaria o conteúdo das cadeias de caracteres. (Observação: self-range-insert em vectors ainda é proibido pelo Standard.)
* basic_string::shrink_to_fit() não é mais afetado pelo propagate_on_container_swap do alocador.
* std::decay agora manipula tipos de função abomináveis (ou seja, tipos de função que sejam qualificados para cv-e/ou ref).
* Alteradas as diretivas de inclusão para usar diferenciação adequada de maiúsculas e minúsculas e barras invertidas, melhorando a portabilidade.
* Corrigido o aviso C4061 "enumerador 'Meow' na troca do enumerador 'Kitten' não é manipulado explicitamente por um rótulo case". Esse aviso é desativado por padrão e foi corrigido como uma exceção à política geral da Biblioteca Padrão para avisos. (A Biblioteca Padrão é /W4 limpo, mas não tenta ser /Wall limpo. Muitos avisos de desativação por padrão são muito barulhentos e não devem ser usados com regularidade.)
* Aprimoradas as verificações de depuração de std::list. Os iteradores de lista agora verificam operator->(), e list::unique() agora marcam iteradores como invalidados.
* Corrigida a metaprogramação de uses-allocator na tupla.

##### <a name="performancethroughput-fixes"></a>Correções de desempenho/taxa de transferência
* Solucionadas as interações com noexcept que impediam a implementação embutida de std::atomic em funções que usam o tratamento de exceções estruturado (SEH).
* Alterada a função interna _Deallocate() da Biblioteca Padrão para otimizar em código menor, permitindo que ele seja embutido em outros locais.
* Alterado std::try_lock() para usar a expansão de pacote em vez de recursão.
* Aprimorado o algoritmo de impedimento de deadlock std::lock() para usar operações lock() em vez de girar em todos os try_lock()s dos bloqueios.
* Habilitada a otimização de valor de retorno nomeado em system_category::message().
* conjunto e disjunção agora instanciam tipos N + 1, em vez de tipos 2N + 2.
* std::function não instancia mais máquinas de suporte de alocador para cada chamável apagado por tipo, melhorando a taxa de transferência e reduzindo o tamanho de .obj em programas que passam vários lambdas distintos para std::function.
* allocator_traits\<std::allocator\> contém operações std::allocator manualmente embutidas, reduzindo o tamanho do código no código que interage com std::allocator por meio de allocator_traits apenas (ou seja, grande parte do código).
* A interface de alocador mínima C++11 agora é manipulada pela Biblioteca Padrão chamando allocator_traits diretamente, em vez de envolver o alocador em uma classe interna _Wrap_alloc. Isso reduz o tamanho do código gerado para suporte de alocador, melhora a capacidade do otimizador de raciocinar sobre contêineres da Biblioteca Padrão em alguns casos e fornece uma melhor experiência de depuração (porque agora você pode ver o tipo de alocador, em vez de _Wrap_alloc\<seu tipo de alocador\> no depurador).
* Removida a metaprogramação para allocator::reference personalizada, que os alocadores, na verdade, não têm permissão para personalizar. (Os alocadores podem fazer contêineres usarem ponteiros sofisticados, mas não referências sofisticadas.)
* O front-end do compilador foi ensinado a descompactar iteradores de depuração em loops for baseados em intervalo, melhorando o desempenho de compilações de depuração.
* O caminho de redução interna de basic_string para shrink_to_fit() e reserve() não está mais no caminho de operações de realocação, reduzindo o tamanho do código para todo os membros de mutação.
* O caminho de crescimento interno de basic_string não está mais no caminho de shrink_to_fit().
* As operações de mutação de basic_string agora são fatoradas em funções de caminho rápido de não alocação e caminho lento de alocação, tornando mais provável para o caso comum de não realocar ser embutido em chamadores.
* As operações de mutação de basic_string agora constroem buffers realocados no estado desejado em vez do redimensionamento em vigor. Por exemplo, inserir no início de uma cadeia de caracteres agora move o conteúdo após a inserção exatamente uma vez (para baixo ou para o buffer recém-alocado), em vez de duas vezes no caso de realocação (para o buffer recém-alocado e, em seguida, para baixo).
* As operações chamando a biblioteca padrão C em \<cadeia de caracteres\> agora armazena em cache o endereço do errno para remover interações repetidas com TLS.
* Implementação simplificada do is_pointer.
* Concluída a alteração da expressão SFINAE com base em função para baseada em struct/void_t.
* Os algoritmos de Biblioteca Padrão agora evitam iteradores de pós-incrementação.
* Corrigidos os avisos de truncamento ao usar alocadores de 32 bits em sistemas de 64 bits.
* A atribuição de movimentação std::vector agora é mais eficiente para o caso de alocador não POCMA não igual, reutilizando o buffer quando possível.

##### <a name="readability-and-other-improvements"></a>Legibilidade e outras melhorias
* A Biblioteca Padrão agora usa constexpr de C++14 incondicionalmente, em vez de macros definidas condicionalmente.
* A Biblioteca Padrão agora usa modelos de alias internamente.
* A Biblioteca Padrão agora usa nullptr internamente, em vez de nullptr_t{}. (O uso interno de NULL foi erradicado. O uso interno de 0-as-null está sendo eliminado gradualmente.)
* A Biblioteca Padrão agora usa std::move() internamente, em vez de usar std::forward() indevidamente.
* static_assert(false, "message") foi alterado para a mensagem #error. Isso melhora o diagnóstico do compilador porque #error interrompe imediatamente a compilação.
* A Biblioteca Padrão não marca mais funções como __declspec(dllimport). A tecnologia moderna de vinculador não exige mais isso.
* SFINAE extraído para argumentos de modelo padrão, o que reduz a desordem em comparação com tipos de retorno e tipos de argumento de função.
* As verificações de depuração em \<random\> agora usam o maquinário usual da Biblioteca Padrão, em vez da função interna _Rng_abort() que chamava fputs() para stderr. A implementação dessa função está sendo retida para compatibilidade binária, mas foi removida na próxima versão incompatível com binário da Biblioteca Padrão. 

### <a name="open-source-library-support"></a>Suporte à biblioteca de software livre  
Vcpkg é uma ferramenta de linha de comando de software livre que simplifica bastante o processo de aquisição e build de bibliotecas estáticas e DLLS de software livre do C++ no Visual Studio. Para obter mais informações, consulte [vcpkg: um gerenciador de pacotes para C++](vcpkg.md).

### <a name="cpprest-sdk-290"></a>CPPRest SDK 2.9.0  
A CPPRestSDK, uma API da Web de plataforma cruzada para o C++, foi atualizada para a versão 2.9.0. Para obter mais informações, consulte [CppRestSDK 2.9.0 está disponível no GitHub](https://blogs.msdn.microsoft.com/vcblog/2016/10/21/cpprestsdk-2-9-0-is-available-on-github/).

### <a name="atl"></a>ATL
* Ainda outro conjunto de correções de compatibilidade de pesquisa de nome
* Construtores de movimentação e operadores de atribuição existentes são agora corretamente marcados como sem lançamento
* Não suprimir aviso C4640 válido sobre a inicialização segura de thread de estatísticas locais no atlstr.h
* A inicialização segura de thread de estatísticas locais foi desabilitada automaticamente no conjunto de ferramentas XP ao [usar ATL E compilar uma DLL]. Esse não é mais o caso. Você poderá adicionar /Zc:threadSafeInit- in em suas configurações de projeto se desejar que a inicialização segura de thread seja desativada. 

### <a name="visual-c-runtime"></a>Tempo de execução do Visual C++
* Novo cabeçalho "cfguard.h" para símbolos de proteção de fluxo de controle. 

## <a name="c-ide"></a>C++ IDE

* Agora, o desempenho de alteração de configuração é melhor para projetos nativos C++ e muito melhor para projetos C++/CLI. Quando uma configuração de solução for ativada pela primeira vez, depois ela será mais rápida, e todas as ativações subsequentes dessa configuração de solução serão quase instantâneas.

**Visual Studio 2017 versão 15.3**:
* Vários assistentes de código e de projeto foram reescritos no estilo de caixa de diálogo de assinatura.
* **Adicionar Classe** agora inicia o assistente para Adicionar Classe diretamente. Todos os outros itens que estavam anteriormente aqui agora estão disponíveis em **Adicionar > Novo Item**.
* Os projetos de Win32 agora estão sob a categoria Área de Trabalho do Windows na caixa de diálogo **Novo Projeto**.
* Os modelos de Console do Windows e Aplicativo de Área de Trabalho agora criam projetos sem exibir um assistente. Agora há um novo Assistente de Área de Trabalho do Windows, sob a mesma categoria e que exibe as mesmas opções de antes.

### <a name="intellisense"></a>Intellisense  
* O novo mecanismo de banco de dados com base em SQLite agora está sendo usado por padrão. Isso acelerará operações de banco de dados como Ir para Definição e Localizar Todas as Referências e poderá aprimorar significativamente o tempo de análise inicial da solução. A configuração foi movida para Ferramentas > Opções > Editor de texto > C/C++ > Avançado (estava anteriormente em... C/C++ > Experimental).

* Melhoramos o desempenho do IntelliSense em projetos e arquivos que não estão usando cabeçalhos pré-compilados – um Cabeçalho Pré-Compilado Automático será criado para os cabeçalhos no arquivo atual.

* Adicionamos filtragem de erros e ajuda para erros do IntelliSense e na lista de erros. Agora, ao clicar na coluna de erro é possível filtrar. Além disso, clicar em erros específicos ou pressionar F1 iniciará uma pesquisa online sobre a mensagem de erro.

  ![Lista de Erros](media/ErrorList1.png "Lista de Erros")

  ![Lista de Erros Filtrada](media/ErrorList2.png "Lista de Erros Filtrada")

* Adicionada a capacidade de filtrar por tipo os itens da Lista de Membros.

  ![Filtragem da Lista de Membros](media/mlfiltering.png "Filtragem da Lista de Membros")

* Adicionado um novo recurso experimental Predictive IntelliSense, que fornece filtragem ciente de contexto daquilo que aparece na Lista de Membros. Consulte [Melhorias do IntelliSense no C++ – IntelliSense Preditivo e Filtragem](https://blogs.msdn.microsoft.com/vcblog/2016/10/05/c-intellisense-improvements-predictive-intellisense-filtering/)

* Localizar Todas as Referências (Shift+F12) agora ajuda a movimentar-se facilmente, até mesmo em bases de código complexas. Ela fornece agrupamento, filtragem, classificação e pesquisa avançada nos resultados e, para algumas linguagens, colorização, para que você obtenha uma compreensão clara de suas referências. Para o C++, a nova interface do usuário inclui informações sobre se estamos lendo de uma variável ou gravando em uma variável.

* O recurso Dot-to-Arrow IntelliSense passou de experimental a avançado e agora está habilitado por padrão. Os recursos do editor Expandir Escopos e Expandir Precedência também passaram de experimental para avançados.

* Os recursos de refatoração experimental Alterar Assinatura e Extrair Função agora estão disponíveis por padrão.

* O recurso experimental para 'Carregamento de projeto mais rápido' em C++. Na próxima vez que você abrir um projeto C++ ele será carregado mais rapidamente e depois disso ele carregará muito mais rápido!

Alguns desses recursos são comuns a outras linguagens e alguns são específicos do C++. Para obter mais informações sobre esses novos recursos, consulte [Anunciando o Visual Studio "15"](https://blogs.msdn.microsoft.com/visualstudio/2016/10/05/announcing-visual-studio-15-preview-5/). 


### <a name="support-for-non-msbuild-projects-with-open-folder"></a>Suporte para projetos que não são de MSBuild com o Open Folder
O Visual Studio 2017 apresenta o recurso "Open Folder", que o habilita a escrever código, compilar e depurar em uma pasta que contém o código-fonte sem a necessidade de criar soluções ou projetos. Isso facilita muito para começar a usar o Visual Studio, mesmo que seu projeto não seja um projeto com base em MSBuild. Com o "Open Folder", você obtém acesso às funcionalidades poderosas de entendimento, edição, build e depuração de código que o Visual Studio já fornece para projetos do MSBuild. Para saber mais, veja [Projetos Abrir Pasta no Visual C++](ide/non-msbuild-projects.md).

* Melhorias na experiência de Abrir Pasta. Você pode personalizar sua experiência por meio desses arquivos json:
  - CppProperties.json para personalizar a experiência de navegação e do IntelliSense.
  - Tasks.json para personalizar as etapas de build. 
  - Launch.json para personalizar a experiência de depuração.

**Visual Studio 2017 versão 15.3**: 
* Suporte aprimorado para ambientes de compilação e compiladores alternativos como MinGW e Cygwin. Para saber mais, veja [Usando MinGW e Cygwin com Visual C++ e Abrir Pasta](https://blogs.msdn.microsoft.com/vcblog/2017/07/19/using-mingw-and-cygwin-with-visual-cpp-and-open-folder/).
* Adicionado suporte para definir variáveis de ambiente globais e específicas de configuração em "CppProperties.json" e "CMakeSettings.json". Essas variáveis de ambiente podem ser consumidas por configurações de depuração definidas em "launch.vs.json" e tarefas em "tasks.vs.json".
* Suporte aprimorado para o gerador Ninja do CMake, incluindo a capacidade de direcionar facilmente plataformas de 64 bits.

### <a name="cmake-support-via-open-folder"></a>Suporte a CMake através do Open Folder
O Visual Studio 2017 apresenta suporte ao uso de projetos CMake sem a conversão para arquivos de projeto MSBuild (.vcxproj). Para saber mais, veja [Projetos CMake no Visual C++](ide/cmake-tools-for-visual-cpp.md). Abrir projetos CMake com “Open Folder” configurará automaticamente o ambiente para editar, compilar e depurar com o C++.

* O C++ IntelliSense funciona sem a necessidade de criar um arquivo CppProperties.json na pasta raiz. Além disso, adicionamos uma nova lista suspensa para permitir aos usuários mudar facilmente entre as configurações fornecidas pelos arquivos CppProperties.json e CMake.

* Há suporte para configurações adicionais por meio de um arquivo CMakeSettings.json que reside na mesma pasta que o arquivo CMakeLists.txt.

  ![Abrir Pasta com CMake](media/cmake_cpp.png "Abrir Pasta com CMake")

**Visual Studio 2017 versão 15.3**: suporte adicionado para o gerador Ninja do CMake. Para saber mais, veja [Suporte a CMake no Visual Studio – novidades na versão prévia 2 do 2017 15.3](https://blogs.msdn.microsoft.com/vcblog/2017/06/14/cmake-support-in-visual-studio-whats-new-in-2017-15-3-preview-2/). 

## <a name="c-installation-workloads"></a>Cargas de trabalho de instalação em C++ 

### <a name="windows-desktop-development-with-c"></a>Desenvolvimento do Windows Desktop com C++:  
Agora, fornecemos uma experiência de instalação mais granular da carga de trabalho original do C++. Adicionamos componentes selecionáveis que permitem a instalação apenas das ferramentas das quais você precisa.  Observe que os tamanhos de instalação indicados para os componentes listados na interface de usuário do instalador não são precisos e subestimam o tamanho total.

Para criar projetos Win32 com êxito na carga de trabalho de área de trabalho C++, é necessário instalar um conjunto de ferramentas e um SDK do Windows. Instalar os componentes recomendados (selecionados) “Conjunto de ferramentas do VC++ 2017 v141 (x86, x64)” e “SDK do Windows 10 (10.0.14393)” garantirá que isso funcionará. Se as ferramentas necessárias não estiverem instaladas, os projetos não serão criados com êxito e o assistente parará de responder.

### <a name="linux-development-with-c"></a>Desenvolvimento de Linux com C++:  
A extensão popular [Visual C++ para Desenvolvimento no Linux](https://visualstudiogallery.msdn.microsoft.com/725025cf-7067-45c2-8d01-1e0fd359ae6e) agora faz parte do Visual Studio. Essa instalação fornece tudo o que você precisa para desenvolver e depurar aplicativos em C++, em execução em um ambiente Linux.  

**Visual Studio 2017 versão 15.2**: aprimoramentos para compartilhamento de código entre plataformas e visualização de tipo. Para saber mais, veja [Aprimoramentos do C++ para Linux para compartilhamento de código entre plataformas e visualização de tipo](https://blogs.msdn.microsoft.com/vcblog/2017/05/10/linux-cross-platform-and-type-visualization/).

### <a name="game-development-with-c"></a>Desenvolvimento de jogos com C++:  
Use todo o poder do C++ para compilar jogos profissionais com DirectX ou Cocos2d.  

### <a name="mobile-development-with-c-android-and-ios"></a>Desenvolvimento Mobile com C++ (Android e iOS):  
Agora, você pode criar e depurar aplicativos móveis usando o Visual Studio, que pode ser destinado ao Android e iOS.  

### <a name="universal-windows-apps"></a>Aplicativos universais do Windows:  
O C++ é fornecido como um componente opcional para a carga de trabalho do Aplicativo Universal do Windows.  Atualmente, a atualização de projetos em C++ deve ser feita manualmente. Se abrir um projeto da UWP voltado ao v140 no Visual Studio 2017, será necessário selecionar o conjunto de ferramentas de plataforma v141 nas páginas de propriedades do projeto se você não tiver instalado o Visual Studio 2015.

## <a name="new-options-for-c-on-universal-windows-platform"></a>Novas opções para C++ na Plataforma Universal do Windows
Agora você tem novas opções para gravar e empacotar aplicativos do C++ para a Plataforma Universal do Windows e para a Windows Store: você pode usar o Desktop App Converter para empacotar o aplicativo da área de trabalho existente para implantação por meio da Windows Store. Para obter mais informações, consulte [Usando o tempo de execução do Visual C++ em projeto Centennial](https://blogs.msdn.microsoft.com/vcblog/2016/07/07/using-visual-c-runtime-in-centennial-project/) e [Traga seu aplicativo da área de trabalho para a UWP (Plataforma Universal do Windows) com a Ponte de Desktop](https://msdn.microsoft.com/en-us/windows/uwp/porting/desktop-to-uwp-root).

Ao escrever código novo, você pode usar a C++/WinRT, uma projeção de linguagem C++ padrão para o Windows Runtime implementada exclusivamente em arquivos de cabeçalho. Ela permite que você crie e consuma APIs de Windows Runtime usando qualquer compilador C++ em conformidade com os padrões. A C++/WinRT foi concebida para oferecer aos desenvolvedores em C++ um acesso de primeira classe à moderna API do Windows. Para obter mais informações, consulte [C++/WinRT disponível no GitHub](https://moderncpp.com/).


## <a name="clangc2-platform-toolset"></a>Conjunto de ferramentas de plataforma Clang/C2
O conjunto de ferramentas Clang/C2 que acompanha o [!INCLUDE[vs_dev15_md](misc/includes/vs_dev15_md.md)] agora dá suporte à opção /bigobj, que é essencial para o build de projetos grandes. Ele também inclui várias correções de bugs importantes, tanto em front-end quanto em back-end do compilador.

## <a name="c-code-analysis"></a>Análise de Código C++

Os verificadores principais do C++ para impor as [principais diretrizes do C++](https://github.com/isocpp/CppCoreGuidelines) agora são distribuídas com o Visual Studio. Simplesmente habilite os verificadores na caixa de diálogo Extensões de Análise de Código nas páginas de propriedades do projeto e as extensões serão incluídas quando você executar análise de código. 

![CppCoreCheck](media/CppCoreCheck.png "Página de propriedades CppCoreCheck") 

**Visual Studio 2017 versão 15.3**: adicionado suporte para regras relacionadas ao gerenciamento de recursos. Para saber mais, veja [Uso dos verificadores de diretrizes de núcleo do C++](/visualstudio/code-quality/using-the-cpp-core-guidelines-checkers).

## <a name="unit-testing"></a>Teste de unidade

Novas extensões do Visual Studio permitem que você execute os testes de unidade com base no teste do Google e Boost.Test diretamente no Visual Studio. Para saber mais, veja [Atualizações de teste de unidade do C++: anunciando o adaptador Boost.Test e suporte aprimorado para teste do Google](https://blogs.msdn.microsoft.com/vcblog/2017/08/04/c-unit-testing-updates-announcing-boost-test-adapter-and-improved-google-test-support/).

## <a name="visual-studio-graphics-diagnostics"></a>Diagnóstico de gráficos do Visual Studio

O Diagnóstico de Gráficos do Visual Studio é um conjunto de ferramentas de registro e análise de problemas de desempenho e renderização em aplicativos Direct3D. Os recursos de Diagnóstico de Gráficos podem ser usados com aplicativos em execução localmente no seu computador Windows, em um emulador de dispositivo Windows ou em um dispositivo ou computador remoto.

* **Entrada e saída para sombreadores de vértice e de geometria:** a capacidade de exibir a entrada e saída de sombreadores de vértices e sombreadores de geometria tem sido um dos recursos mais solicitados e agora há suporte nas ferramentas. É só selecionar o estágio VS ou GS na exibição de Estágios da Pipeline para iniciar a inspeção de sua entrada e saída na tabela abaixo.

  ![Entrada/saída de sombreadores](media/io-shaders.png)

* **Pesquisa e filtro na tabela de objetos:** fornece uma maneira rápida e fácil de localizar os recursos que você está procurando.

  ![Pesquisar](media/search.png)
   
* **Histórico de Recursos:** esse novo modo de exibição fornece uma maneira simplificada de ver todo o histórico de modificações de um recurso, enquanto ele foi usado durante a renderização de um quadro capturado. Para invocar o histórico de qualquer recurso, basta clicar no ícone de relógio ao lado de qualquer hiperlink de recurso.

  ![Histórico de recurso](media/resource-history.png)

  Isso exibirá a nova janela de ferramentas de Histórico de Recursos, preenchida com o histórico de alterações do recurso.

  ![Alteração de histórico do recurso](media/resource-history-change.png)

  Observe que, se o quadro foi capturado com a captura de pilha de chamadas completa habilitada (**Visual Studio > Ferramentas > Opções > Diagnóstico de Gráficos**), o contexto de cada evento de alteração poderá ser rapidamente deduzido e inspecionado dentro de seu projeto do Visual Studio.  

* **Estatísticas de API:** exibir um resumo de alto nível do uso da API em seu quadro. Isso pode ser útil na descoberta de chamadas que você pode nem perceber que está fazendo ou chamadas que você está fazendo demasiadamente. Esta janela está disponível por meio de **Exibir > Estatísticas de API** no Analisador de Gráficos do Visual Studio.

  ![Estatísticas de API](media/api-stats.png)

* **Estatísticas de Memória:** exibir a quantidade de memória que o driver está alocando para os recursos que você cria no quadro. Esta janela está disponível por meio de Exibir->Estatísticas de Memória no Analisador de Gráficos do Visual Studio. Os dados podem ser copiados para um arquivo CSV para exibição em uma planilha ao clicar com o botão direito do mouse e escolher Copiar Tudo.

  ![Estatísticas de memória](media/memory-stats.png)
 
* **Validação de Quadro:** a nova lista de erros e avisos fornece uma maneira fácil de navegar em sua lista de eventos com base em problemas potenciais detectados pela camada de depuração Direct3D. Clique em Exibir->Validação de Quadro no Analisador de Gráficos do Visual Studio para abrir a janela. Em seguida, clique em Executar Validação para iniciar a análise. Pode levar vários minutos para a análise ser concluída, dependendo da complexidade do quadro.

  ![Validação de quadro](media/frame-validation.png)
 
* **Análise de Quadros para D3D12:** usar a Análise de Quadros para analisar o desempenho da chamada de desenho com experimentos “what-if” direcionados. Mudar para a guia de Análise de Quadros e executar uma análise para exibir o relatório. Para obter mais detalhes, assista ao vídeo [GoingNative 25: Análise de Quadros de Gráficos do Visual Studio](https://channel9.msdn.com/Shows/C9-GoingNative/GoingNative-25-Offline-Analysis-Graphics-Tool).

  ![Análise de quadro](media/frame-analysis.png)

* **Melhorias do Uso de GPU:** abrir os rastreamentos feitos por meio do criador de perfil de Uso de GPU do Visual Studio com a Exibição de GPU ou a ferramenta WPA (Windows Performance Analyzer) para uma análise mais detalhada. Se você tiver o Windows Performance Toolkit instalado, haverá dois hiperlinks na parte inferior direita da visão geral da sessão: um para a WPA e outro para a Exibição de GPU.

  ![Uso de GPU](media/gpu-usage.png)
 
  Os rastreamentos abertos na Exibição de GPU por meio desse link oferecem suporte a aplicação de zoom e ao movimento panorâmico sincronizados na linha do tempo entre o VS e a Exibição de GPU. Uma caixa de seleção no VS é usada para controlar se a sincronização está habilitada ou não. 

  ![Exibição de GPU](media/gpu-view.png) 


 

