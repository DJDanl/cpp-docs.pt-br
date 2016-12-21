---
title: "Novidades do Visual C++ no Visual Studio 2015 | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 1cc09fad-85a2-43c2-b022-bb99f5fe0ad7
caps.latest.revision: 101
caps.handback.revision: 101
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Novidades do Visual C++ no Visual Studio 2015
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

No Visual Studio de 2015, o compilador do C\+\+ e a biblioteca padrão foram atualizados com suporte aprimorado para o C \+ \+ 11 inicial suporte e certos recursos do C\+\+ 14.  Eles também incluem suporte preliminar para determinados recursos deve ser a 17 C\+\+ padrão.  
  
 Também adicionamos modelos de projeto para desenvolvimento de vários dispositivo de plataforma cruzada em[Android e iOS](../Topic/Visual%20C++%20for%20Cross-Platform%20Mobile%20Development.md)feitas várias[diagnóstico](#BK_Diagnostics)e[produtividade](#BK_IDE)aperfeiçoamentos e melhoria significativa[criar vezes](#BK_FasterBuildTimes).  
  
> [!WARNING]
>  No Visual Studio de 2015, o Visual C\+\+ não está instalado por padrão.  Durante a instalação, certifique\-se de escolher**personalizado**instalação e, em seguida, escolha os componentes do C\+\+ você precisa.  Ou, se o Visual Studio já estiver instalado, escolha**arquivo &#124; Novo &#124; Projeto &#124; C\+\+**e você será solicitado a instalar os componentes necessários.  
  
 Para obter informações sobre outras adições no Visual Studio de 2015, consulte[O que há de novo no Visual Studio 2015](../Topic/What's%20New%20in%20Visual%20Studio%202015.md).  
  
 Neste tópico:  
  
1.  [Compilador](#BK_Compiler)  
  
2.  [Biblioteca Padrão C++](#BK_CppStdLib)  
  
3.  [Biblioteca de tempo de execução do C](#BK_CRT)  
  
4.  [Tempos de compilação](#BK_FasterBuildTimes)  
  
5.  [Qualidade de desempenho e de código](#BK_PerfCodeQuality)  
  
6.  [Produtividade, depuração e diagnóstico](#BK_IDE)  
  
    1.  [IntelliSense de arquivo único](#BK_SingleFileIntelliSense)  
  
    2.  [Refatoração](#BK_Refactoring)  
  
    3.  [Aprimoramentos de banco de dados do programa](#BK_PDB)  
  
    4.  [Diagnóstico](#BK_Diagnostics)  
  
7.  [Direcionamento Windows 10](#BK_Win10)  
  
8.  [Diagnóstico de gráficos](#BK_GraphicsDiagnostics)  
  
9. [Nova ferramenta de uso de GPU](#BK_GPUUsage)  
  
10. [Novos recursos do MFC](#BK_MFC)  
  
## Suporte a padrões ISO C\/C\+\+  
  
###  <a name="BK_Compiler"></a> Compilador  
  
-   **Funções reiniciáveis \(continuação\/await\)**a continuação e await palavras\-chave fornecem suporte de nível de linguagem para funções reiniciáveis assíncronas de programação e permite.  Atualmente, esse recurso é ainda é experimental e só está disponível para x 64 alvos.  **\(Proposto para o C \+ \+ 17 \[N3858\]\)**  
  
-   **As expressões Lambda \(Polymorphic\) genérico**tipos de parâmetro de função Lambda agora podem ser especificados usando automática; o compilador interpreta automaticamente neste contexto significa que o operador de chamada de função do fechamento é um modelo de função de membro e que cada uso auto na expressão lambda corresponde a um parâmetro de tipo de modelo distintos.  **\(C \+ \+ 14\)**  
  
-   **Generalizada capturar as expressões Lambda**também conhecida como captura de init.  O resultado de uma expressão arbitrária que agora pode ser atribuído a uma variável na cláusula de captura de uma lambda.  Isso permite mover somente tipos a serem capturados por valor e habilita uma expressão lambda para definir os membros de dados arbitrários de seu objeto de fechamento.  **\(C \+ \+ 14\)**  
  
-   **Literais binários**literais binários agora têm suporte.  Tais literais são prefixados com 0B ou 0b e consistem somente os dígitos de 0 e 1.  **\(C \+ \+ 14\)**  
  
-   **Dedução de tipo de retorno**o tipo de retorno de funções normais agora pode ser deduzido, incluindo funções com várias instruções de retorno e recursiva.  Tais definições de função são precedidas da palavra\-chave auto como definições de função com um tipo de retorno à direita, mas o tipo de retorno à direita é omitido.  **\(C \+ \+ 14\)**  
  
-   **decltype\(auto\)**dedução usando a palavra\-chave auto para inicializar expressões retira qualificadores de ref e qualificadores cv nível superior da expressão do tipo.  decltype\(Auto\) preserva ref e VC qualificadores e agora pode ser usado em qualquer lugar que automaticamente pode ser usado, exceto ao introduzir uma função com um inferido à direita ou tipo de retorno.  **\(C \+ \+ 14\)**  
  
-   **Implícita geração de mover funções membro especiais**mover construtores e mover os operadores de atribuição agora são implicitamente gerados quando as condições permitem, colocando o compilador em total conformidade com referências de rvalue de 11 C \+ \+.  **\(C \+ \+ 11\)**  
  
-   **Herdando construtores**uma classe derivada pode agora especificar herdam os construtores de sua base de classe Base, incluindo a instrução usando Base::Base; em sua definição.  Uma classe derivada pode herdar apenas todos os construtores de sua classe base, não é possível herdar construtores base específicos.  Uma classe derivada não pode herdar de várias classes base se eles têm construtores que possuem uma assinatura idêntica, nem pode a classe derivada define um construtor que tem uma assinatura idêntica a qualquer um dos seus construtores herdadas.  **\(C \+ \+ 11\)**  
  
-   **Consulta de alinhamento e controle**o alinhamento de uma variável pode ser consultado usando o operador alignof\(\) e controlado usando o especificador de alignas\(\).  alignof\(\) retorna o limite de bytes no qual as instâncias do tipo devem ser alocadas; para referências retorna o alinhamento do tipo referenciado e matrizes retorna o alinhamento do tipo de elemento.  alignas\(\) controla o alinhamento de uma variável; leva uma constante ou um tipo, onde um tipo é a abreviação para alignas\(alignof\(type\)\).  **\(C \+ \+ 11\)**  
  
-   **em tamanho desalocação**o globals `void operator delete(void *, std::size_t) noexcept`e`void operator delete[](void *, std::size_t) noexcept`agora podem ser sobrecarregados  
  
-   **Sizeof estendido**o tamanho de uma variável de membro de classe ou estrutura pode ser determinado sem uma instância da classe ou estrutura usando sizeof\(\).**\(C\+\+11\)**  
  
-   **Atributos**fornecem uma maneira de estender a sintaxe de funções, variáveis, tipos e outros elementos do programa sem definir novas palavras\-chave.**\(C\+\+11\)**  
  
-   **constexpr**criar variáveis de tempo de compilação constantes, funções e tipos definidos pelo usuário.  **\(C \+ \+ 11\)**  
  
-   **Literais definidos pelo usuário \(UDLs\)**significativos sufixos podem agora ser anexados a literais numéricos e de seqüência de caracteres para dar\-lhes semântica específica.  O compilador interpreta como sufixos literais como chamadas para o operador de UDL apropriado.  **\(C \+ \+ 11\)**  
  
-   **Thread\-Safe "Mágica" estática**variáveis locais estáticas agora são inicializadas de forma segura para thread, eliminando a necessidade de sincronização manual.  Somente a inicialização é thread\-safe, uso de variáveis locais estáticas por vários threads deve ainda ser sincronizado manualmente.  O recurso de thread\-safe estática pode ser desabilitado usando o sinalizador \/Zc:threadSafeInit\-para evitar assumir uma dependência do CRT.  **\(C \+ \+ 11\)**  
  
-   **Armazenamento Local de thread**usar a palavra\-chave thread\_local para declarar que um objeto independente deve ser criado para cada thread.  **\(C \+ \+ 11\)**  
  
-   **noexcept**o operador noexcept agora pode ser usado para verificar se uma expressão pode gerar uma exceção.  O especificador noexcept agora pode ser usado para especificar que uma função não lança exceções.  **\(C \+ \+ 11\)**  
  
-   **Inline Namespaces**agora é possível especificar um namespace como inline elevar seu conteúdo no namespace delimitador.  Namespaces embutidos pode ser usada para criar bibliotecas de controle de versão que expõem sua versão mais recente por padrão, enquanto ainda disponibilizar as versões anteriores de API explicitamente.  **\(C \+ \+ 11\)**  
  
-   **Uniões irrestritas**tipo de união A agora pode conter tipos com construtores não triviais.  Construtores para tais uniões devem ser definidos.  **\(C \+ \+ 11\)**  
  
-   **Novos tipos de caracteres e literais Unicode**caracteres e cadeia de caracteres literais em UTF\-8, UTF\-16 e UTF\-32 agora têm suporte e novos char16\_t de tipos de caractere e char32\_t foram introduzidos.  Literais de caracteres podem ser prefixados com u8 \(UTF\-8\), u \(UTF\-16\) ou U \(UTF\-32\) como U'a', enquanto os literais de cadeia de caracteres Além disso podem ser precedidos por equivalentes de cadeia de caracteres bruta u8R \(UTF\-8\-cadeia de caracteres bruta\), uR \(UTF\-16\-cadeia de caracteres bruta\) ou UR \(UTF\-32\-cadeia de caracteres bruta\).  Caracteres universais nomes podem ser livremente usados em literais unicode como u '\\u00EF' u8 "\\u00EF é i" e "\\U000000ef é".  **\(C \+ \+ 11\)**  
  
-   **separadores de dígito**aspas podem ser inseridas em intervalos regulares para facilitar a leitura de literais numéricos longo: `int x = 1'000'000;`**C \+ \+ 14**  
  
-   **\_\_func\_\_**\_\_func\_\_ o identificador predefinido é definida implicitamente como uma cadeia de caracteres que contém o nome não qualificado e acrescido da função.  
  
-   **Restrict \_**restringir agora pode ser aplicado às referências.  
  
###  <a name="BK_CppStdLib"></a> Biblioteca Padrão C\+\+  
  
-   **Literais definidos pelo usuário \(UDLs\) padrão para tipos de biblioteca**\< chrono \>, \< string \>, e os cabeçalhos de \< complex \> agora fornecem operadores UDL para sua conveniência.  Por exemplo, std::chrono::milliseconds\(123\) 123ms significa "hello" s significa std::string\("hello"\) e 3.14i significa std::complex \(0,0, 3.14\).  
  
-   **Nulo iteradores Forward**biblioteca padrão agora permite a criação de iteradores de encaminhamento que não fazem referência a uma instância de contêiner.  Esses iteradores são inicializados por valor e comparam como iguais para um tipo específico de contêiner.  Comparar um valor inicializado iterador que não é inicializado do zero é indefinido.  **\(C \+ \+ 14\)**  
  
-   **quoted\(\)**biblioteca padrão agora oferece suporte a função quoted\(\) para facilitar o trabalho com valores de cadeia de caracteres entre aspas e e\/s.  Com quoted\(\), um inteiro entre aspas a cadeia de caracteres é tratado como uma única entidade \(como cadeias de caracteres de espaço não caracteres estão em fluxos de e\/s\); Além disso, as seqüências de escape são preservadas por meio de operações de e\/s.  **\(C \+ \+ 14\)**  
  
-   **Pesquisa associativo heterogêneos**biblioteca padrão agora oferece suporte a funções de pesquisa heterogêneos para contêineres associativos.  Essas funções permitem pesquisa por tipos diferentes de key\_type como o tipo é comparável ao key\_type.  **\(C \+ \+ 14\)**  
  
-   **Sequências de inteiros de tempo de compilação**biblioteca padrão agora oferece suporte ao tipo de integer\_sequence que representa uma seqüência de valores inteiros que podem ser avaliadas em tempo de compilação para facilitar o trabalho com pacotes de parâmetro e simplificar determinado padrões de programação do modelo.  **\(C \+ \+ 14\)**  
  
-   **Exchange \(\)**biblioteca padrão agora oferece suporte a função de utilitário std::exchange\(\) para atribuir um novo valor a um objeto e retorna seu valor antigo.  Para tipos complexos, o Exchange \(\) evita copiando o valor antigo quando um construtor de movimentação está disponível, evita copiando o novo valor se ele é um temporário é movido e aceita qualquer tipo como o novo valor aproveitando qualquer operador de atribuição de conversão.  **\(C \+ \+ 14\)**  
  
-   **Dual\-Range Equal \(\), is\_permutation\(\), mismatch\(\)**biblioteca padrão agora oferece suporte a sobrecargas para std::equal\(\), std::is\_permutation\(\) e std::mismatch\(\) que aceitam dois intervalos.  Essas sobrecargas verificar que as duas seqüências têm a mesma extensão, o que remove essa responsabilidade do código de chamada; para sequências que não há suporte para os requisitos de um iterador aleatório, essas sobrecargas verifica o comprimento durante a comparação de elementos, que é mais eficiente.  **\(C \+ \+ 14\)**  
  
-   **obter \(\< T \>\)**biblioteca padrão agora oferece suporte à função do modelo get \< T \> \(\) para permitir que elementos de tupla ser endereçados por seu tipo.  Se uma tupla contém dois ou mais elementos do mesmo tipo obtém \(\< T \>\) a tupla não pode ser resolvida por esse tipo, mas outros elementos exclusivamente digitado ainda podem ser resolvidos.  **\(C \+ \+ 14\)**  
  
-   **tuple\_element\_t**biblioteca padrão agora oferece suporte a tuple\_element\_t \< i, T \> alias de tipo que é um alias para typename tuple\_element \< i, T \>:: tipo.  Isso fornece alguma conveniência para programadores de modelo, semelhantes a outras alias de tipo metafunction no \< type\_traits \>.  **\(C \+ \+ 14\)**  
  
-   **Especificações técnicas do sistema de arquivos "V3"**a implementação incluída das especificações técnicas do sistema de arquivos foi atualizada para a versão 3 da especificação.  \[N3940\]  
  
-   **Mínimo alocadores**biblioteca padrão agora oferece suporte à interface do alocador mínimo em todo; correções importantes incluem std:: Function, shared\_ptr, allocate\_shared\(\) e basic\_string.  **\(C \+ \+ 11\)**  
  
-   **\< Chrono \>**o chrono tipos high\_resolution\_clock e steady\_clock foram corrigidos.  **\(C \+ \+ 11\)**  
  
-   **N2761 atômicos em manipuladores de sinal \(C \+ \+ 11\)**  
  
-   **N3922 novas regras para automática com listas entre chaves de inicialização. \(17 C \+ \+\)**  
  
-   **N4051 typename em parâmetros de modelo do modelo, \(C \+ \+ 17\)**  
  
-   **N4259 std::uncaught\_exceptions\(\)**  
  
-   **Atributos N4266 para namespaces e enumeradores**  
  
-   **Literais de caracteres u8 N4267**  
  
###  <a name="BK_CRT"></a> Biblioteca de tempo de execução do C  
 **Refatoração de biblioteca CRT**o CRT foi refatorado em duas partes.  O**CRT Universal**contém o código que implementa a biblioteca de tempo de execução C padrão.  Vcruntime140.dll \(ou. lib\) contém código específico da versão para o processo de inicialização e manipulação de exceção.  A CRT Universal tem uma API estável, para que possa ser usado sem alterar o número de versão em cada versão do Visual Studio.  Agora é um componente do sistema operacional Windows que é atendido pelo Windows Update.  Ele já está instalado no Windows 10.  Usando o Visual C\+\+ Redistributable Package \(vcredist\), você pode distribuí\-lo junto com seus aplicativos para versões anteriores do Windows.  
  
 **Conformidade C99** [!INCLUDE[vs_dev14](../mfc/includes/vs_dev14_md.md)]implementa totalmente a biblioteca padrão C99, com exceção de qualquer recurso de biblioteca que depende de recursos de compilador ainda não é suportados pelo compilador Visual C\+\+ \(por exemplo, \< tgmath \> não é implementado\).  
  
 **Desempenho**grande parte da biblioteca foi refatorado para agilizar e simplificar o uso de macro do arquivo de cabeçalho.  Isso acelera a compilação e o IntelliSense e melhora a legibilidade.  Além disso, muitas funções stdio foram reescritas para melhor desempenho e conformidade com os padrões.  
  
### Alterações significativas  
 Esse suporte aprimorado para padrões ISO C\/C\+\+ pode exigir alterações no código existente para que ele está em conformidade com C \+ \+ 11 e C99 e compilada corretamente no Visual Studio de 2015.  Para obter mais informações, consulte[Alterações significativas no Visual C\+\+ 2015](../Topic/Visual%20C++%20change%20history%202003%20-%2020151.md).  
  
 A classe Concurrency:: Task e tipos relacionados em ppltasks não se baseiam no tempo de execução ConcRT.  Eles agora usam o Threadpool do Windows como seu Agendador.  Esse código imacts única que usa primitivos de sincronização ConcRT dentro de operações Concurrency:: Task.  Esse código use os primitivos de sincronização do Windows.  
  
 Os primitivos de sincronização no STL também não se baseiam em ConcRT.  Para evitar deadlocks, não use os primitivos de sincronização de STL dentro de tais funções**concurrency::parallel\_for**ou com os tipos de agentes assíncronos de PPL.  
  
##  <a name="BK_FasterBuildTimes"></a> Tempos de compilação  
  
-   **Geração de código de tempo de vinculação incremental \(\/ltcg\)**vinculação Incremental agora pode ser usado com \/ltcg diminuir tempos de link de aplicativos usando \/ltcg.  Ativar esse recurso usando o \/LTCG: incremental e opções de vinculador \/LTCG:incremental\_rebuild.  \\  
  
-   **Vinculação incremental para bibliotecas estáticas**alterações bibliotecas estáticas que são referenciadas por outros módulos de código agora vincular incrementalmente.  
  
-   **\/Debug:FastLink**substancialmente diminui vincular vezes usando novas técnicas de criação de PDB.  
  
-   Aprimoramentos de algoritmos foram feitos para o vinculador para diminuir tempos de link.  
  
-   Aperfeiçoamentos foram feitos que irá permitir a criação de modelo pesado de código mais rapidamente.  
  
-   **Instrumentação fast perfil interativa otimização \(PGO\)**um modo de instrumentação novo e leve para jogos e sistemas em tempo real foi introduzido em PGO.  Junto com outros novos recursos disponibilizados por meio de \/GENPROFILE e \/FASTGETPROFILE opções de vinculador agora você pode equilibrar a qualidade do código e velocidade de compilação quando usando PGO.  
  
-   **Redução de tamanho do arquivo de objeto**aprimoramentos da biblioteca padrão C\+\+ e de compilador resultam em arquivos de objeto significativamente menores e bibliotecas estáticas.  Esses aprimoramentos não afetam o tamanho de vinculadas dinamicamente DLLs \(bibliotecas\) ou executáveis \(EXEs\) porque o código redundante historicamente foi removido pelo vinculador.  
  
##  <a name="BK_PerfCodeQuality"></a> Qualidade de desempenho e de código  
  
-   **Melhorias vetorização automática**agora inclui a vetorização do fluxo de controle \(if\-then\-else\), vetorização durante a compilação em \/O1 \(minimizar tamanho\), e aprimoramentos gerais de vetor a qualidade do código, incluindo suporte a STL paralela, vetorização mais baseado em intervalo loops e suportam para \#pragma loop\(ivdep\).  
  
-   **Aprimoramentos à otimização escalar**melhor geração de operações bit\-teste, mesclagem de fluxo de controle e otimizações de código \(loop\-se alternando\) e outras otimizações escalares \(por exemplo, melhor geração de código para std::min e std::max\).  
  
-   **Otimização Guiada por perfil \(PGO\)**uma série de melhorias foram feita PGO, inclusive conjuntos de referência aprimorados, melhores recursos de layout de dados, e a capacidade de reutilizar feitas anteriormente inlining, acelerar vs.  tamanho e layouts.  
  
##  <a name="BK_IDE"></a> Produtividade, depuração e diagnóstico  
  
###  <a name="BK_SingleFileIntelliSense"></a> IntelliSense de arquivo único  
 Agora você obter IntelliSense quando você abre um arquivo de código fonte única no editor, sem a necessidade de abrir qualquer arquivo de projeto.  
  
###  <a name="BK_Refactoring"></a> Refatoração  
 Adicionamos o suporte à refatoração do C\+\+ com os seguintes recursos:  
  
-   **Renomear símbolo**altera todas as ocorrências de um símbolo para um novo nome.  
  
-   **Função extração**mover o código selecionado para sua própria função.  Esta refatoração está disponível como uma extensão do Visual Studio na Galeria do Visual Studio.  
  
-   **Implementar puros virtuais**gera definições de função para funções virtuais puras herdadas por uma classe ou estrutura.  Várias e herança recursivas são suportados.  Ative esta refatoração de definição de classe herdeira para implementar todas as herdadas de funções virtuais puras ou de um especificador de classe base para implementar funções virtuais puras somente dessa classe base.  
  
-   **Criar declaração ou definição**gera uma declaração de uma definição existente ou uma definição default de uma declaração existente.  Acesse esta refatoração da definição ou declaração existente ou do indicador de lâmpada elétrica.  
  
-   **Mover a definição de função**move o corpo de uma função entre os arquivos de cabeçalho e código de origem.  Ative esta refatoração de assinatura da função.  
  
-   **Converter em um Literal de cadeia de caracteres brutos**converte uma cadeia de caracteres que contém seqüências de escape em um literal de cadeia de caracteres bruta.  Seqüências de escape com suporte são \\ \\ \(barra invertida\) \\n \(nova linha\), \\t \(guia\) \\' \(aspa simples\) \\ "\(aspas duplas\) e \\?  \(ponto de interrogação\).  Ative esse recurso clicando em qualquer lugar dentro de uma cadeia de caracteres.  
  
 Localizar em arquivos foi aprimorada, permitindo resultados subseqüentes a ser anexado aos resultados anteriores; resultados acumulados podem ser excluídos.  
  
 **Melhorias do IntelliSense legibilidade**instanciações do modelo complexo e definições de tipo são simplificadas na Ajuda do parâmetro e inforapida para facilitar a leitura.  
  
###  <a name="BK_PDB"></a> Aprimoramentos de banco de dados do programa  
  
-   Velocidade de verificação de solução foi aprimorada, especialmente para grandes soluções.  
  
-   Operações como ir para definição não são bloqueadas durante a verificação de solução exceto durante a verificação inicial da solução quando uma nova solução é aberta pela primeira vez.  
  
##  <a name="BK_Diagnostics"></a> Diagnóstico  
  
1.  **Visualizações do depurador**Natvis Adicionar visualizações ao seu projeto do Visual Studio para facilitar o gerenciamento e integração de controle de origem do depurador.  Arquivos do Natvis podem ser editados e salvo durante uma sessão de depuração e o depurador selecionará automaticamente as alterações.  Para obter mais informações, consulte[postagem de blog](http://blogs.msdn.com/b/vcblog/archive/2014/06/12/project-support-for-natvis.aspx).  
  
2.  **Diagnóstico de memória nativa**  
  
    1.  **Sessões de diagnóstico de memória**\(Ctrl \+ Alt \+ F2\) permite que você monitore o uso de memória em tempo real do seu aplicativo nativo durante uma sessão de depuração.  
  
    2.  **Instantâneos de memória**capturar uma imagem momentânea do conteúdo da pilha do aplicativo.  Diferenças no estado de heap podem ser examinadas comparando dois instantâneos de memória.  Exibir tipos de objetos, valores de instância e pilhas de chamadas de alocação para cada instância depois de interromper o aplicativo.  Exiba a árvore de chamada por quadro de pilha para cada instantâneo.  
  
3.  **Melhorias na detecção de deadlocks e recuperação**ao chamar funções C\+\+ do windows inspeção e imediato.  
  
4.  **Compilador diagnósticos aprimorados**o compilador fornece avisos avançados sobre código suspeito.  Foram adicionados novos avisos \(por exemplo, variáveis sombreados e incompatíveis printf cadeias de caracteres de formato\).  Mensagens de aviso existentes se tornaram mais claras.  
  
5.  **o sinalizador \/Wv**avisos introduzidos após uma versão específica do compilador XX. AA. ZZZZ pode ser desabilitado usando o \/Wv:XX. AA. Sinalizador ZZZZ.  Outros avisos podem ser desabilitados especificamente além daqueles especificados por meio do sinalizador de \/Wv.  
  
6.  **Suporte aprimorado para depurar o código otimizado**depurar código com os sinalizadores \/Z7, \/zo \* ou \/Zi habilitados.  
  
##  <a name="BK_Win10"></a> Direcionamento Windows 10  
 O Visual Studio agora oferece suporte a direcionamento 10 do Windows em C\+\+.  Novos modelos de projeto para desenvolvimento de aplicativos Universal do Windows oferecem suporte a direcionamento dispositivos Windows 10 como computadores desktop, celulares, tablets, HoloLens e outros dispositivos.  Para obter mais informações, consulte[criar um aplicativo "hello world" no Windows 10](https://msdn.microsoft.com/en-us/library/windows/apps/dn996906.aspx).  
  
##  <a name="BK_GraphicsDiagnostics"></a> Diagnóstico de gráficos  
 Diagnóstico de gráficos foi aprimorado com os seguintes recursos:  
  
-   **Diagnóstico de gráficos oferecem suporte para DirectX12.** A ferramenta de diagnóstico de gráficos do Visual Studio agora oferece suporte a depuração de problemas de renderização em aplicativos de DirectX12.  
  
-   **Capturar consecutivas**captura até 30 quadros consecutivos com uma captura.  
  
-   **Captura programática**iniciar a captura de quadro programaticamente.  Captura programática é especialmente útil para depuração de sombreadores de cálculo em programas que nunca chama presente ou quando um problema de renderização é difícil capturar manualmente, mas pode ser previsto por meio de programação do estado do aplicativo em tempo de execução.  
  
-   **Lista de eventos de gráficos aprimorados**A chamadas de desenho novo é adicionado que exibe eventos capturados e seu estado em uma hierarquia organizada por chamadas de desenho.  Você pode expandir chamadas de desenho para exibir o estado do dispositivo atual no momento da chamada de desenho e você ainda pode expandir cada tipo de estado para exibir os eventos que definem seus valores.  
  
-   **Suporte para Windows Phone 8.1**diagnóstico de gráficos agora totalmente dá suporte à depuração de aplicativos do Windows Phone 8.1 no emulador do Windows Phone ou na vinculado Phone.  
  
-   **Análise de quadro de gráficos**essa ferramenta coleta medidas de desempenho em quadros capturados; Além disso também executa um conjunto de testes predefinidos que fornece informações sobre como o desempenho seria afetado quando várias técnicas de textura são aplicadas.  Análise de quadro também coleta contadores de desempenho do hardware.  
  
-   **Dedicado a interface do usuário para análise de gráficos**nova janela do analisador de elementos gráficos do Visual Studio é um espaço de trabalho dedicado para análise de quadros de gráficos.  
  
-   **Sombreador editar e aplicar**exibir o impacto das alterações de código de sombreador em um log capturado sem executar o aplicativo novamente.  
  
-   Configurar captura opções em Ferramentas \-\> Opções \-\> Diagnóstico de gráficos.  
  
-   Ferramenta de linha de comando para a captura e reprodução de quadros.  
  
 Para obter mais informações, consulte[Diagnóstico de gráficos \(depurando gráficos DirectX\)](../Topic/Visual%20Studio%20Graphics%20Diagnostics.md).  
  
##  <a name="BK_GPUUsage"></a> Nova ferramenta de uso de GPU  
 A ferramenta de uso de GPU no Visual Studio de 2015 pode ser usada para entender o uso da GPU de aplicativos DirectX.  Tempo de quadro, taxa de quadros e a utilização da CPU gráficos estão disponíveis os aplicativos em execução em tempo real.  Além disso, coletando e analisando dados detalhados de uso GPU, essa ferramenta pode fornecer ideias sobre o tempo de execução da CPU e GPU eventos individuais do DirectX e, portanto, pode ser útil para determinar se a CPU ou GPU é o afunilamento de desempenho.  Consulte[Uso de GPU](../Topic/GPU%20Usage.md).  
  
##  <a name="BK_MFC"></a> Novos recursos do MFC  
 Agora você pode especificar como os controles automaticamente, redimensionar e movam quando um usuário altera o tamanho da caixa de diálogo.  Para obter mais informações, consulte[Layout dinâmico](../mfc/dynamic-layout.md).  
  
## Consulte também  
 [O que há de novo no Visual Studio 2015](../Topic/What's%20New%20in%20Visual%20Studio%202015.md)   
 [Blog da equipe do Visual C\+\+](http://blogs.msdn.com/b/vcblog/)