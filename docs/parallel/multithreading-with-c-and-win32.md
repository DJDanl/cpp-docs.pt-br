---
title: Multithread com C e Win32
ms.date: 08/09/2019
helpviewer_keywords:
- Windows API [C++], multithreading
- multithreading [C++], C and Win32
- Visual C, multithreading
- Win32 applications [C++], multithreading
- threading [C++], C and Win32
- Win32 [C++], multithreading
- threading [C]
ms.assetid: 67cdc99e-1ad9-452b-a042-ed246b70040e
ms.openlocfilehash: 1764561e0b2b43b8a89d8a1eb2e85d84ce33c4fc
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77141962"
---
# <a name="multithreading-with-c-and-win32"></a>Multithread com C e Win32

O compilador C/C++ Microsoft (MSVC) fornece suporte para a criação de aplicativos multithread. Considere usar mais de um thread se seu aplicativo precisar executar operações caras que possam fazer com que a interface do usuário não responda.

Com o MSVC, há várias maneiras de programar com vários threads: você C++pode usar o/WinRT e a biblioteca de Windows Runtime, a biblioteca do Microsoft Foundation C++Class (MFC), a/CLI e o tempo de execução do .net, ou a biblioteca de tempo de execução do C e a API do Win32. Este artigo trata de vários threads em C. Para obter um exemplo de código, consulte [exemplo de programa multithread em C](sample-multithread-c-program.md).

## <a name="multithread-programs"></a>Programas multithread

Um thread é basicamente um caminho de execução por meio de um programa. Também é a menor unidade de execução agendada pelo Win32. Um thread consiste em uma pilha, o estado dos registros de CPU e uma entrada na lista de execução do Agendador do sistema. Cada thread compartilha todos os recursos do processo.

Um processo consiste em um ou mais threads e no código, nos dados e em outros recursos de um programa na memória. Recursos de programa típicos são arquivos abertos, semáforos e memória alocada dinamicamente. Um programa é executado quando o Agendador do sistema fornece um de seus controle de execução de threads. O Agendador determina quais threads devem ser executados e quando eles devem ser executados. Os threads de prioridade mais baixa podem precisar aguardar enquanto os threads de prioridade mais alta concluem suas tarefas. Em máquinas com vários processadores, o Agendador pode mover threads individuais para processadores diferentes para balancear a carga da CPU.

Cada thread em um processo Opera de forma independente. A menos que você os torne visível entre si, os threads são executados individualmente e não sabem de outros threads em um processo. Os threads que compartilham recursos comuns, no entanto, devem coordenar seu trabalho usando semáforos ou outro método de comunicação entre processos. Para obter mais informações sobre a sincronização de threads, consulte [escrevendo um programa Win32 multithread](#writing-a-multithreaded-win32-program).

## <a name="library-support-for-multithreading"></a>Suporte de biblioteca para multithread

Todas as versões do CRT agora oferecem suporte a multithreading, com exceção das versões sem bloqueio de algumas funções. Para obter mais informações, consulte [desempenho de bibliotecas multi-threaded](../c-runtime-library/multithreaded-libraries-performance.md). Para obter informações sobre as versões do CRT disponíveis para vincular ao seu código, consulte [recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md).

## <a name="include-files-for-multithreading"></a>Incluir arquivos para multithread

Os arquivos de inclusão padrão do CRT declaram as funções da biblioteca de tempo de execução do C conforme elas são implementadas nas bibliotecas. Se as opções do compilador especificarem as convenções de chamada [__fastcall ou __vectorcall](../build/reference/gd-gr-gv-gz-calling-convention.md) , o compilador assumirá que todas as funções devem ser chamadas usando a Convenção de chamada registrar. As funções de biblioteca de tempo de execução usam a Convenção de chamada C e as declarações nos arquivos de inclusão padrão dizem ao compilador para gerar referências externas corretas para essas funções.

## <a name="crt-functions-for-thread-control"></a>Funções de CRT para controle de thread

Todos os programas Win32 têm pelo menos um thread. Qualquer thread pode criar threads adicionais. Um thread pode concluir seu trabalho rapidamente e, em seguida, encerrar, ou pode permanecer ativo durante a vida útil do programa.

As bibliotecas CRT fornecem as seguintes funções para a criação e a terminação de thread: [_beginthread, _beginthreadex](../c-runtime-library/reference/beginthread-beginthreadex.md), [_endthread e _endthreadex](../c-runtime-library/reference/endthread-endthreadex.md).

As funções `_beginthread` e `_beginthreadex` criam um novo thread e retornam um identificador de thread se a operação for bem-sucedida. O thread será encerrado automaticamente se concluir a execução. Ou, ele pode ser encerrado com uma chamada para `_endthread` ou `_endthreadex`.

> [!NOTE]
> Se você chamar as rotinas de tempo de execução em C de um programa criado com LIBCMT. lib, deverá iniciar seus threads com a função `_beginthread` ou `_beginthreadex`. Não use as funções do Win32 `ExitThread` e `CreateThread`. O uso de `SuspendThread` pode levar a um deadlock quando mais de um thread é bloqueado aguardando o thread suspenso concluir seu acesso a uma estrutura de dados de tempo de execução C.

### <a name="_core_the__beginthread_function"></a>As funções _beginthread e _beginthreadex

As funções `_beginthread` e `_beginthreadex` criam um novo thread. Um thread compartilha o código e os segmentos de dados de um processo com outros threads no processo, mas tem seus próprios valores de registro exclusivos, espaço de pilha e endereço de instrução atual. O sistema dá tempo de CPU a cada thread, para que todos os threads em um processo possam ser executados simultaneamente.

`_beginthread` e `_beginthreadex` são semelhantes à função [CreateThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-createthread) na API do Win32, mas têm estas diferenças:

- Eles inicializam determinadas variáveis de biblioteca de tempo de execução do C. Isso é importante apenas se você usar a biblioteca de tempo de execução C em seus threads.

- `CreateThread` ajuda a fornecer controle sobre os atributos de segurança. Você pode usar essa função para iniciar um thread em um estado suspenso.

`_beginthread` e `_beginthreadex` retornar um identificador para o novo thread, se tiver êxito ou um código de erro, se houver um erro.

### <a name="_core_the__endthread_function"></a>As funções _endthread e _endthreadex

A função [_endthread](../c-runtime-library/reference/endthread-endthreadex.md) encerra um thread criado por `_beginthread` (e, da mesma forma, `_endthreadex` encerra um thread criado pelo `_beginthreadex`). Os threads são encerrados automaticamente quando são concluídos. `_endthread` e `_endthreadex` são úteis para o encerramento condicional de dentro de um thread. Um thread dedicado ao processamento de comunicações, por exemplo, pode ser fechado se não for possível obter o controle da porta de comunicação.

## <a name="writing-a-multithreaded-win32-program"></a>Escrevendo um programa Win32 multithread

Ao escrever um programa com vários threads, você deve coordenar seu comportamento e [usar os recursos do programa](#_core_sharing_common_resources_between_threads). Além disso, certifique-se de que cada thread receba [sua própria pilha](#_core_thread_stacks).

### <a name="_core_sharing_common_resources_between_threads"></a>Compartilhando recursos comuns entre threads

> [!NOTE]
> Para uma discussão semelhante do ponto de vista do MFC, consulte [multithreading: dicas de programação](multithreading-programming-tips.md) e [multithreading: quando usar as classes de sincronização](multithreading-when-to-use-the-synchronization-classes.md).

Cada thread tem sua própria pilha e sua própria cópia dos registros de CPU. Outros recursos, como arquivos, dados estáticos e memória de heap, são compartilhados por todos os threads no processo. Os threads que usam esses recursos comuns devem ser sincronizados. O Win32 fornece várias maneiras de sincronizar recursos, incluindo semáforos, seções críticas, eventos e mutexes.

Quando vários threads estão acessando dados estáticos, seu programa deve fornecer possíveis conflitos de recursos. Considere um programa em que um thread atualiza uma estrutura de dados estática contendo coordenadas *x*,*y* para itens a serem exibidos por outro thread. Se o thread de atualização alterar a coordenada *x* e for admitido antes de poder alterar a coordenada *y* , o thread de exibição poderá ser agendado antes que a coordenada *y* seja atualizada. O item seria exibido no local errado. Você pode evitar esse problema usando semáforos para controlar o acesso à estrutura.

Um mutex (abreviação de *Mut*ual *ex*clusion) é uma maneira de se comunicar entre threads ou processos que estão sendo executados de forma assíncrona um do outro. Essa comunicação pode ser usada para coordenar as atividades de vários threads ou processos, normalmente controlando o acesso a um recurso compartilhado bloqueando e desbloqueando o recurso. Para resolver esse problema de atualização de coordenadas *x*,*y* , o thread de atualização define um mutex indicando que a estrutura de dados está em uso antes de executar a atualização. Ele limparia o mutex depois que ambas as coordenadas tivessem sido processadas. O thread de exibição deve aguardar que o mutex seja limpo antes de atualizar a exibição. Esse processo de espera por um mutex geralmente é chamado de *bloqueio* em um mutex, porque o processo está bloqueado e não pode continuar até que o mutex seja apagado.

O programa Bounce. c mostrado no [programa multithread c de exemplo](sample-multithread-c-program.md) usa um mutex chamado `ScreenMutex` para coordenar atualizações de tela. Cada vez que um dos threads de exibição está pronto para gravar na tela, ele chama `WaitForSingleObject` com o identificador para `ScreenMutex` e constante infinita para indicar que a chamada `WaitForSingleObject` deve bloquear no mutex e não atingir o tempo limite. Se `ScreenMutex` estiver desmarcada, a função Wait definirá o mutex para que outros threads não possam interferir na exibição e continuará executando o thread. Caso contrário, o thread será bloqueado até que o mutex seja apagado. Quando o thread conclui a atualização de exibição, ele libera o mutex chamando `ReleaseMutex`.

Telas de tela e dados estáticos são apenas dois dos recursos que exigem gerenciamento cuidadoso. Por exemplo, seu programa pode ter vários threads acessando o mesmo arquivo. Como outro thread pode ter movido o ponteiro do arquivo, cada thread deve redefinir o ponteiro do arquivo antes da leitura ou gravação. Além disso, cada thread deve garantir que não seja preempção entre o tempo que ele posiciona o ponteiro e a hora em que ele acessa o arquivo. Esses threads devem usar um semáforo para coordenar o acesso ao arquivo digitando cada acesso ao arquivo com chamadas de `WaitForSingleObject` e `ReleaseMutex`. O exemplo de código a seguir ilustra essa técnica:

```C
HANDLE    hIOMutex = CreateMutex (NULL, FALSE, NULL);

WaitForSingleObject( hIOMutex, INFINITE );
fseek( fp, desired_position, 0L );
fwrite( data, sizeof( data ), 1, fp );
ReleaseMutex( hIOMutex);
```

### <a name="_core_thread_stacks"></a>Pilhas de thread

Todo o espaço de pilha padrão de um aplicativo é alocado para o primeiro thread de execução, que é conhecido como Thread 1. Como resultado, você deve especificar a quantidade de memória a ser alocada para uma pilha separada para cada thread adicional de que seu programa precisa. O sistema operacional aloca espaço de pilha adicional para o thread, se necessário, mas você deve especificar um valor padrão.

O primeiro argumento na chamada `_beginthread` é um ponteiro para a função `BounceProc`, que executa os threads. O segundo argumento especifica o tamanho de pilha padrão para o thread. O último argumento é um número de ID que é passado para `BounceProc`. `BounceProc` usa o número de ID para propagar o gerador de números aleatórios e selecionar o atributo de cor e o caractere de exibição do thread.

Os threads que fazem chamadas para a biblioteca de tempo de execução C ou para a API do Win32 devem permitir espaço suficiente de pilha para as funções de biblioteca e API que eles chamam. A função C `printf` requer mais de 500 bytes de espaço de pilha, e você deve ter de 2K bytes de espaço de pilha disponível ao chamar rotinas de API do Win32.

Como cada thread tem sua própria pilha, você pode evitar colisões potenciais em itens de dados usando o mínimo possível de dados estáticos. Projete seu programa para usar variáveis de pilha automáticas para todos os dados que podem ser particulares a um thread. As únicas variáveis globais no programa Bounce. c são mutexes ou variáveis que nunca são alteradas depois de inicializadas.

O Win32 também fornece armazenamento de thread local (TLS) para armazenar dados por thread. Para obter mais informações, consulte [TLS (armazenamento local de thread)](thread-local-storage-tls.md).

## <a name="avoiding-problem-areas-with-multithread-programs"></a>Evitando áreas de problema com programas multithread

Há vários problemas que você pode encontrar ao criar, vincular ou executar um programa multithread C. Alguns dos problemas mais comuns são descritos na tabela a seguir. (Para obter uma discussão semelhante do ponto de vista do MFC, consulte [multithreading: dicas de programação](multithreading-programming-tips.md).)

|Problema|Causa provável|
|-------------|--------------------|
|Você recebe uma caixa de mensagem mostrando que seu programa causou uma violação de proteção.|Muitos erros de programação do Win32 causam violações de proteção. Uma causa comum de violações de proteção é a atribuição indireta de dados a ponteiros nulos. Como isso resulta em seu programa tentando acessar a memória que não pertence a ele, uma violação de proteção é emitida.<br /><br /> Uma maneira fácil de detectar a causa de uma violação de proteção é compilar seu programa com informações de depuração e, em seguida, executá-lo por meio do depurador no ambiente do Visual Studio. Quando ocorre a falha de proteção, o Windows transfere o controle para o depurador e o cursor é posicionado na linha que causou o problema.|
|Seu programa gera vários erros de compilação e vinculação.|Você pode eliminar muitos problemas potenciais definindo o nível de aviso do compilador como um de seus valores mais altos e contratando as mensagens de aviso. Usando as opções de nível de aviso nível 3 ou nível 4, você pode detectar conversões de dados não intencionais, protótipos de função ausentes e uso de recursos não-ANSI.|

## <a name="see-also"></a>Consulte também

[Suporte multithread para código mais antigo (Visual C++)](multithreading-support-for-older-code-visual-cpp.md)\
[Exemplo de programa multithread em C](sample-multithread-c-program.md)\
[Armazenamento local de threads (TLS)](thread-local-storage-tls.md)\
[Operações de simultaneidade e C++assíncronas com/WinRT](/windows/uwp/cpp-and-winrt-apis/concurrency)\
[Multithreading com C++ e MFC](multithreading-with-cpp-and-mfc.md)
