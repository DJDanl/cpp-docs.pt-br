---
title: Dicas para melhorar código crítico em termos de tempo
ms.date: 11/04/2016
helpviewer_keywords:
- _lsearch function
- qsort function
- background tasks
- standard sort routines
- clock cycle losses
- code, time-critical
- memory [C++], monitoring usage
- execution, speed improvements
- local heap performance
- optimization [C++], time-critical code
- performance [C++], time-critical code
- threading [C++], performance
- cache [C++], hits and misses
- linear search performance
- page faults
- best practices, time-critical code
- searching [C++], improving performance
- sorting data, improving performance
- threading [C++], best practices
- threading [C++], background tasks
- lists, sorting
- bsearch function
- MFC [C++], performance
- sort routines
- programs [C++], performance
- _lfind function
- heap allocation, time-critical code performance
ms.assetid: 3e95a8cc-6239-48d1-9d6d-feb701eccb54
ms.openlocfilehash: 97a9a54be1b322edfe8cfeca84e03f9a6766b8fe
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824187"
---
# <a name="tips-for-improving-time-critical-code"></a>Dicas para melhorar código crítico em termos de tempo

Para gravar códigos rápidos, você precisa conhecer todos os aspectos do aplicativo e saber como ele interage com o sistema. Este tópico sugere alternativas para algumas das técnicas de codificação mais óbvias que podem ajudá-lo a garantir que as partes do código, para as quais o tempo é essencial, tenham um desempenho satisfatório.

Em suma, para melhorar o código para o qual o tempo é essencial, você precisa:

- Saber quais partes do programa precisam ser rápidas.

- Conhecer o tamanho e a velocidade do código.

- Conhecer o custo dos novos recursos.

- Conhecer o trabalho mínimo necessário para concluir a tarefa.

Para coletar informações sobre o desempenho do seu código, você pode usar o monitor de desempenho (perfmon.exe).

## <a name="sections-in-this-article"></a>Seções deste artigo

- [Perdas no cache e falhas de página](#_core_cache_hits_and_page_faults)

- [Classificação e pesquisa](#_core_sorting_and_searching)

- [MFC e bibliotecas de classes](#_core_mfc_and_class_libraries)

- [Bibliotecas compartilhadas](#vcovrsharedlibraries)

- [Heaps](#_core_heaps)

- [Threads](#_core_threads)

- [Conjunto de trabalho pequeno](#_core_small_working_set)

##  <a name="_core_cache_hits_and_page_faults"></a> Perdas no cache e falhas de página

O ocorrência de perda nos caches interno e externo, assim como as falhas de página (direcionamento para o armazenamento secundário das instruções e dos dados do programa), deixam seu programa lento.

Um acerto de cache da CPU pode custar seu programa de 10 a 20 ciclos de relógio. Uma ocorrência de cache externo pode custar de 20 a 40 ciclos de relógio. Uma falha de página pode custar um milhão de ciclos (partindo do princípio de que o processador gerencia 500 milhões de instruções por segundo e que a falha leva 2 milissegundos). Portanto, o melhor para a execução do programa é que você grave um código que diminua as ocorrências de perna no cache e falhas de página.

Uma das causas da lentidão dos programas é que esses programas têm mais falhas de página ou mais perda no cache com mais frequência do que o necessário. Para evitar isso, é importante usar estruturas de dados com boa localidade de referência, o que significa manter itens relacionados juntos. Às vezes, uma estrutura de dados, que parece excelente, acaba sendo horrível devido à má localidade de referência, e o contrário também pode acontecer. Veja dois exemplos:

- Listas vinculadas com alocação dinâmica podem prejudicar o desempenho do programa porque, quando você pesquisa um item ou navega até o final da lista, cada link ignorado pode sofrer perda no cache ou causar uma falha de página. Uma implementação de lista baseada em matrizes simples pode ser muito mais rápida porque o cache é melhor e há menos falhas de página. Apesar de ser mais difícil expandir a matriz, ela é a opção mais rápida.

- As tabelas de hash que usam listas vinculadas com alocação dinâmica podem prejudicar o desempenho. Consequentemente, esse tipo de tabela usa essas listas para armazenar seu conteúdo podem apresentar desempenho consideravelmente pior. Na verdade, na análise final, uma simples pesquisa linear na matriz pode ser mais rápida (dependendo das circunstâncias). As tabelas de hash baseadas em matrizes, também chamadas de "hash fechado", muitas vezes são implementações ignoradas com um desempenho melhor.

##  <a name="_core_sorting_and_searching"></a> Classificação e pesquisa

Por natureza, a classificação consome mais tempo do que muitas operações comuns. A melhor forma de evitar a lentidão desnecessária é evitar a classificação em tarefas com tempo crítico. Você também pode:

- Adie a classificação até um momento não críticos de desempenho.

- Classificar os dados em um momento anterior, não críticos de desempenho.

- Classificar apenas os dados que realmente precisam ser classificados.

Em alguns casos, você também pode compilar a lista na ordem classificada. Cuidado. Se precisar inserir dados na ordem classificada, você pode precisar de uma estrutura de dados complexa com má localidade de referência, o que resulta em perdas no cache e falhas de páginas. Não existe uma única solução para todos os casos. Experimente diversas possibilidades e avalie as diferenças.

Veja algumas dicas gerais referentes à classificação:

- Use a classificação de inventário para minimizar os bugs.

- Tudo o que for possível fazer previamente para diminuir a complexidade da classificação pode ajudar. Se uma apresentação simples aos dados simplificar as comparações e diminuir a classificação de O(n log n) para O(n), provavelmente, você terá ações mais rápidas.

- Pense na localidade de referência do algoritmo de classificação e nos dados em que ela deve ser executada.

Há menos alternativas para as pesquisas do que para a classificação. Se o tempo for crítico na operação de pesquisa, uma pesquisa binária ou verificação da tabela de hash quase sempre é a melhor opção, mas no caso da classificação, é necessário levar a localidade em consideração. Uma pesquisa linear por meio de uma pequena matriz pode ser mais rápida do que uma pesquisa binária por meio de uma estrutura de dados com diversos ponteiros, que resultam em falhas na página ou perdas no cache.

##  <a name="_core_mfc_and_class_libraries"></a> MFC e bibliotecas de classes

As MFC (Microsoft Foundation Classes) podem simplificar muito a gravação do código. Ao gravar códigos para os quais o tempo é crítico, você deve levar em consideração a sobrecarga inerente a algumas dessas classes. Avalie o código da MFC que seu código com tempo crítico usa para ver se ele atende às suas necessidades de desempenho. A lista a seguir identifica as classes e as funções de MFC que você deve conhecer:

- `CString` MFC chama a biblioteca de tempo de execução C para alocar memória para um [CString](../atl-mfc-shared/reference/cstringt-class.md) dinamicamente. Em termos gerais, `CString` é tão eficiente quanto qualquer outra cadeia de caracteres com alocação dinâmica. Da mesma forma que na cadeia de caracteres com alocação dinâmica, há sobrecarga desse tipo de alocação e versão. Geralmente, uma matriz `char` simples na pilha pode ter a mesma finalidade e ser mais rápida. Não use um `CString` para armazenar uma cadeia de caracteres constante. Use `const char *` em seu lugar. Qualquer operação executada com um objeto `CString` acarreta alguma sobrecarga. Usando a biblioteca de tempo de execução [funções de cadeia de caracteres](../c-runtime-library/string-manipulation-crt.md) pode ser mais rápida.

- `CArray` Um [CArray](../mfc/reference/carray-class.md) fornece flexibilidade que não, mas seu programa não precise disso. Se conhecer os limites específicos da matriz, você pode usar uma matriz global fixa. Se usar `CArray`, use `CArray::SetSize` para estabelecer seu tamanho e especificar em quantos elementos ela cresce quando a realocação é necessária. Caso contrário, a adição de elementos pode fazer com que a matriz seja realocada e copiada com frequência, o que é ineficaz e pode fragmentar a memória. Além disso, lembre-se de que se você inserir um item em uma matriz, `CArray` move os itens subsequentes na memória e pode precisar expandir a matriz. Essas ações podem resultar em perdas no cache e falhas de página. Se verificar o código usado pela MFC, você pode ver que é possível gravar códigos mais específicos a seu cenário, para melhorar o desempenho. Como `CArray` é um modelo, você pode fornecer especializações `CArray` para tipos específicos, por exemplo.

- `CList` [CList](../mfc/reference/clist-class.md) é uma lista duplamente vinculada, portanto, a inserção é rápida no início, fim e na posição conhecida (`POSITION`) na lista. A verificação de elementos por valor ou índice requer uma pesquisa sequencial, mas esse tipo de pesquisa pode ser lento se a lista for longa. Se seu código não precisar de uma lista vinculada duas vezes, reconsidere o uso de `CList`. Usar uma lista vinculada uma única vez evita a sobrecarga de atualizar um ponteiro adicional para todas as operações, bem como a memória desse ponteiro. Não há muita memória adicional, mas ainda assim ela apresenta uma chance de perdas no cache ou falhas de página.

- `IsKindOf` Essa função pode gerar muitas chamadas e acessar muita memória em diferentes áreas de dados, levando a má localidade de referência. Ela é útil para compilações de depuração (por exemplo, em uma chamada ASSERT), mas evite usá-la na compilação de versão.

- `PreTranslateMessage` Use `PreTranslateMessage` quando uma árvore de janelas específicas precisa aceleradores de teclado diferentes ou quando é necessário inserir a manipulação de mensagens na bomba de mensagens. `PreTranslateMessage` altera as mensagens de expedição da MFC. Se você substituir `PreTranslateMessage`, só faça isso no nível necessário. Por exemplo, não é necessário substituir `CMainFrame::PreTranslateMessage` se você tiver interesse somente nas mensagens encaminhadas aos filhos de uma exibição específica. Em vez disso, substitua `PreTranslateMessage` na classe de exibição.

   Não drible o caminho de expedição normal usando `PreTranslateMessage` para manipular mensagens enviadas a qualquer janela. Use [procedimentos de janela](../mfc/registering-window-classes.md) e mapas de mensagens do MFC para essa finalidade.

- `OnIdle` Podem ocorrer eventos ociosos às vezes você esperava, tais como entre `WM_KEYDOWN` e `WM_KEYUP` eventos. Os timers podem ser mais eficientes para disparar seu código. Não force a chamada de `OnIdle` diversas vezes com a geração de mensagens falsas ou com o retorno de `TRUE` da substituição de `OnIdle`, pois assim seu thread nunca entrará em modo de suspensão. Nesse caso, o timer ou um thread separado pode ser mais adequado.

##  <a name="vcovrsharedlibraries"></a> Bibliotecas compartilhadas

É bom poder reutilizar códigos. No entanto, se você for usar o código de outra pessoa, deve saber exatamente o que o código faz nos casos em que o desempenho é crítico. A melhor forma de saber isso é seguir o código-fonte ou dimensioná-lo com ferramentas como o PView ou o Monitor de Desempenho.

##  <a name="_core_heaps"></a> Heaps

Use diversos heaps com discrição. Os heaps adicionais criados com `HeapCreate` e `HeapAlloc` permitem que você gerencie e descarte um conjunto relacionado de alocações. Não comprometa muita memória. Se estiver usando diversos heaps, preste atenção principalmente na quantidade de memória que é comprometida inicialmente.

Em vez de usar diversos heaps, você pode usar funções auxiliares para servir de interface entre seu código e o heap padrão. As funções auxiliares facilitam as estratégias de alocação personalizadas que podem melhorar o desempenho do seu aplicativo. Por exemplo, se você sempre faz pequenas alocações de desempenho, pode concentrá-las em uma parte do heap padrão. Você pode alocar um grande bloco de memória e usar a função auxiliar para subalocar desse bloco. Se fizer isso, você não terá heaps adicionais com a memória não utilizada porque a alocação parte do heap padrão.

No entanto, em alguns casos, o uso do heap padrão pode diminuir a localidade de referência. Use o Process Viewer, o Spy++ ou o Monitor de Desempenho para dimensionar os efeitos de mover os objetos entre os heaps.

Dimensione seus heaps para dar conta de cada alocação no heap. Use o tempo de execução C [rotinas de heap de depuração](/visualstudio/debugger/crt-debug-heap-details) do ponto de verificação e despejar seu heap. Você pode ler o resultado em um programa de planilhas, como o Microsoft Excel, e usar tabelas dinâmicas para exibir os resultados. Observe o número total, o tamanho e a distribuição das alocações. Compare esses dados com o tamanho dos conjuntos de trabalho. Observe também o clustering dos objetos dimensionados relacionados.

Você também pode usar os contadores de desempenho para monitorar o uso de memória.

##  <a name="_core_threads"></a> Threads

No caso de tarefas em seguindo plano, a manipulação eficiente e ociosa de eventos pode ser mais rápida do que usar threads. Com ela, é mais fácil compreender a localidade de referência em um programa com um único thread.

Uma boa regra é só usar o thread se uma notificação de sistema operacional usada em seu bloco estiver na raiz do trabalho em segundo plano. Nesse caso, os threads são a melhor solução porque é pouco prático bloquear um thread principal em um evento.

Os threads também apresentam problemas de comunicação. Você deve gerenciar o vínculo de comunicação entre seus threads por meio de uma lista de mensagens ou da alocação e do uso de memória compartilhada. O gerenciamento do vínculo de comunicação geralmente requer sincronização para evitar condições de corrida e problemas de deadlock. Essa complexidade pode resultar em bugs e problemas de desempenho.

Para obter mais informações, consulte [processamento de Loop ocioso](../mfc/idle-loop-processing.md) e [Multithreading](../parallel/multithreading-support-for-older-code-visual-cpp.md).

##  <a name="_core_small_working_set"></a> Conjunto de trabalho pequeno

Conjuntos de trabalho menores possibilitam a melhor localidade de referência, resultam em menos falhas e páginas e geram mais ocorrências de cache. O conjunto de trabalho do processo é a métrica mais próxima que o sistema operacional oferece para medir a localidade de referência diretamente.

- Para definir os limites superiores e inferiores do conjunto de trabalho, use [SetProcessWorkingSetSize](/windows/desktop/api/winbase/nf-winbase-getprocessworkingsetsize).

- Para obter os limites superiores e inferiores do conjunto de trabalho, use [GetProcessWorkingSetSize](/windows/desktop/api/winbase/nf-winbase-setprocessworkingsetsize).

- Para exibir o tamanho do conjunto de trabalho, use o Spy++.

## <a name="see-also"></a>Consulte também

[Otimizando seu código](optimizing-your-code.md)
