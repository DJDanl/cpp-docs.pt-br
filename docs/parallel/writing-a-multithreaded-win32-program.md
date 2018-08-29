---
title: Escrevendo um programa Win32 multithread | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- thread stacks [C++]
- resources [C++], multithreading
- stacks [C++]
- shared resources [C++]
- threading [C++], sharing common resources
- multithreading [C++], thread stacks
- multithreading [C++], sharing common resources
- mutual exclusion [C++]
- communications [C++], between threads
- mutex [C++]
- threading [C++], thread stacks
ms.assetid: 1415f47d-417f-4f42-949b-946fb28aab0e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 98abce752ca02e40be68787d06fa8d4c17ce3e4b
ms.sourcegitcommit: f7703076b850c717c33d72fb0755fbb2215c5ddc
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/28/2018
ms.locfileid: "43131197"
---
# <a name="writing-a-multithreaded-win32-program"></a>Escrevendo um programa Win32 multithread
Quando você escreve um programa com vários threads, você deve coordenar seu comportamento e [uso de recursos do programa](#_core_sharing_common_resources_between_threads). Você também deve verificar se que cada thread recebe [sua própria pilha](#_core_thread_stacks).  
  
##  <a name="_core_sharing_common_resources_between_threads"></a> Compartilhando recursos comuns entre os Threads  
  
> [!NOTE]
>  Para obter uma discussão semelhante do ponto de vista do MFC, consulte [Multithreading: dicas de programação](multithreading-programming-tips.md) e [Multithreading: quando usar as Classes de sincronização](multithreading-when-to-use-the-synchronization-classes.md).  
  
Cada thread tem sua própria pilha e registra sua própria cópia da CPU. Outros recursos, como arquivos, dados estáticos e memória heap, são compartilhados por todos os threads no processo. Usando esses recursos comuns de segmentos devem ser sincronizados. O Win32 fornece várias maneiras de recursos, incluindo semáforos e exclusões mútuas, eventos e seções críticas.  
  
Quando vários threads estiverem acessando os dados estáticos, o programa deve fornecer para conflitos de recursos possíveis. Considere um programa em que um thread atualiza uma estrutura de dados estáticos que contém *x*,*y* coordenadas para os itens a serem exibidos por outro thread. Se o thread de atualização altera o *x* coordenar e admitir preempção antes que ele possa alterar o *y* coordenada, o thread de exibição pode ser agendado antes do *y* coordenada é atualizado. O item seria exibido no local errado. Você pode evitar esse problema usando semáforos para controlar o acesso à estrutura.  
  
Um mutex (abreviação de *mut*ual *ex*conclusão) é uma maneira de se comunicar entre threads ou processos que são executados de forma assíncrona um do outro. Essa comunicação é geralmente usada para coordenar as atividades de vários threads ou processos, normalmente, controlando o acesso a um recurso compartilhado por bloquear e desbloquear o recurso. Para resolver isso *x*,*y* problemas de atualizações coordenadas, o thread de atualização define um mutex indicando que a estrutura de dados está em uso antes de executar a atualização. Ele desmarque o mutex depois que ambas as coordenadas tinham sido processadas. O thread de exibição deve aguardar o mutex ser claro, antes de atualizar a exibição. Esse processo de esperar um mutex é chamado muitas vezes, porque o processo será bloqueado e não pode continuar até que o mutex limpa o bloqueio em um mutex.  
  
O programa de Bounce mostrado na [programa de C Multithread de exemplo](sample-multithread-c-program.md) usa um mutex nomeado `ScreenMutex` para coordenar as atualizações de tela. Cada vez que um dos threads de vídeo está pronto para escrever na tela, ele chama `WaitForSingleObject` com o identificador `ScreenMutex` e infinito constante para indicar que o `WaitForSingleObject` chamada deve bloquear o mutex e o tempo limite. Se `ScreenMutex` é claro, a função espera define o mutex para que outros threads não possam interferir com a exibição e continua a execução do thread. Caso contrário, o thread bloqueia até que o mutex limpa. Quando o thread conclui a atualização da exibição, ela libera o mutex chamando `ReleaseMutex`.  
  
Tela exibe e dados estáticos são apenas dois dos recursos que exigem o gerenciamento cuidadoso. Por exemplo, seu programa pode ter vários threads acessando o mesmo arquivo. Porque outro thread pode ter sido movido o ponteiro do arquivo, cada thread deve redefinir o ponteiro do arquivo antes de ler ou gravar. Além disso, cada thread Certifique-se de que ele não admitir preempção entre a hora em que ele posiciona o ponteiro e a hora em que ele acessa o arquivo. Esses threads devem usar um semáforo para coordenar o acesso ao arquivo por colchetes cada acesso de arquivo com `WaitForSingleObject` e `ReleaseMutex` chamadas. O exemplo de código a seguir ilustra essa técnica:  
  
```  
HANDLE    hIOMutex= CreateMutex (NULL, FALSE, NULL);  
  
WaitForSingleObject( hIOMutex, INFINITE );  
fseek( fp, desired_position, 0L );  
fwrite( data, sizeof( data ), 1, fp );  
ReleaseMutex( hIOMutex);  
```  
  
##  <a name="_core_thread_stacks"></a> Pilhas de thread  
 
Todo espaço de pilha padrão do aplicativo é alocado para o primeiro thread de execução, o que é conhecido como o thread 1. Como resultado, você deve especificar a quantidade de memória para alocar para uma pilha separada para cada thread adicional seu programa precisa. O sistema operacional aloca espaço em pilha adicionais para o thread, se necessário, mas você deve especificar um valor padrão.  
  
O primeiro argumento de `_beginthread` chamada é um ponteiro para o `BounceProc` função, que executa os threads. O segundo argumento especifica o tamanho da pilha padrão para o thread. O último argumento é um número de ID que é passado para `BounceProc`. `BounceProc` usa o número de identificação para propagar o gerador de número aleatório e para selecionar o atributo de cor do thread e exibir caracteres.  
  
Threads que fazem chamadas para a biblioteca de tempo de execução do C ou para a API do Win32 devem permitir espaço em pilha suficiente para a biblioteca e as funções da API que eles chamam. O C `printf` função requer mais de 500 bytes de espaço de pilha, e você deve ter 2 K de espaço de pilha disponível ao chamar as rotinas de API do Win32.  
  
Como cada thread tem sua própria pilha, você pode evitar colisões potenciais sobre itens de dados usando-se como dados estáticos pequeno quanto possível. Projete seu programa usar as variáveis de pilha automáticas para todos os dados que podem ser privados para um thread. As únicas variáveis globais no programa Bounce são mutexes ou variáveis que nunca é alterado depois que eles são inicializados.  
  
Win32 também fornece armazenamento Local de Thread (TLS) para armazenar dados por thread. Para obter mais informações, consulte [armazenamento Local de Thread (TLS)](thread-local-storage-tls.md).  
  
## <a name="see-also"></a>Consulte também  
 
[Multithreading com C e Win32](multithreading-with-c-and-win32.md)