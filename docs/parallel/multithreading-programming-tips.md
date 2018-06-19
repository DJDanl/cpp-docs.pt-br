---
title: 'Multithread: Dicas de programação | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- multithreading [C++], programming tips
- handle maps [C++]
- access control [C++], multithreading
- objects [C++], multiple threads and
- non-MFC threads [C++]
- threading [MFC], programming tips
- critical sections [C++]
- synchronization [C++], multithreading
- programming [C++], multithreaded
- communications [C++], between threads
- threading [C++], best practices
- troubleshooting [C++], multithreading
- Windows handle maps [C++]
ms.assetid: ad14cc70-c91c-4c24-942f-13a75e58bf8a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b9c4241b9257244de840db1f57c5e7abcb32f206
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33689981"
---
# <a name="multithreading-programming-tips"></a>Multithread: dicas de programação
Aplicativos multithread exigem cuidado mais rígido que os aplicativos de thread único ao acessar dados. Porque há vários, caminhos independentes de execução em usam simultaneamente em aplicativos multissegmentados, os algoritmos, os dados ou ambos devem estar cientes que os dados podem ser usados por mais de um segmento por vez. Este tópico explica as técnicas para evitar possíveis problemas ao programar aplicativos multithread com a biblioteca Microsoft Foundation Class (MFC).  
  
-   [Acessando objetos de vários Threads](#_core_accessing_objects_from_multiple_threads)  
  
-   [Acessando objetos MFC de Threads não MFC](#_core_accessing_mfc_objects_from_non.2d.mfc_threads)  
  
-   [Mapas de identificador do Windows](#_core_windows_handle_maps)  
  
-   [Comunicação entre Threads](#_core_communicating_between_threads)  
  
##  <a name="_core_accessing_objects_from_multiple_threads"></a> Acessando objetos de vários Threads  
 Por motivos de desempenho e tamanho, objetos MFC não são thread-safe no nível do objeto, somente no nível de classe. Isso significa que você pode ter dois segmentos separados manipulando dois `CString` objetos, mas não dois threads, manipulando os mesmos `CString` objeto. Se for absolutamente necessário manipular o mesmo objeto de vários threads, proteger esse acesso com mecanismos de sincronização Win32 adequados, como seções críticas. Para obter mais informações sobre seções críticas e outros objetos relacionados, consulte [sincronização](http://msdn.microsoft.com/library/windows/desktop/ms686353) no [!INCLUDE[winsdkshort](../atl-mfc-shared/reference/includes/winsdkshort_md.md)].  
  
 A biblioteca de classes usa seções críticas internamente para proteger as estruturas de dados globais, como aqueles usados pela alocação de memória de depuração.  
  
##  <a name="_core_accessing_mfc_objects_from_non.2d.mfc_threads"></a> Acessando objetos MFC de Threads não MFC  
 Se você tiver um aplicativo multithread que cria um thread de maneira diferente usando um [CWinThread](../mfc/reference/cwinthread-class.md) do objeto, você não pode acessar outros objetos MFC de thread. Em outras palavras, se você quiser acessar qualquer objeto MFC de um thread secundário, você deve criar esse thread com um dos métodos descritos no [Multithreading: Criando Threads de Interface do usuário](../parallel/multithreading-creating-user-interface-threads.md) ou [Multithreading: Criando Threads de trabalho](../parallel/multithreading-creating-worker-threads.md). Esses métodos são os únicos que permitem que a biblioteca de classes inicializar variáveis internas necessárias para lidar com aplicativos multithread.  
  
##  <a name="_core_windows_handle_maps"></a> Mapas de identificador do Windows  
 Como regra geral, um thread pode acessar somente os objetos MFC que ele criou. Isso ocorre porque temporários e permanentes mapas de identificador do Windows são mantidos no armazenamento local de thread para ajudar a manter a proteção de acesso simultâneo de vários threads. Por exemplo, um thread de trabalho não é possível executar um cálculo e, em seguida, chamar um documento `UpdateAllViews` a função de membro com o windows que contêm modos de exibição em novos dados modificados. Isso não tem nenhum efeito, porque o mapa de `CWnd` objetos `HWND`s é local para o thread principal. Isso significa que um thread pode ter um mapeamento de um identificador para um objeto C++, mas outro thread pode mapear esse mesmo identificador para um objeto diferente de C++. As alterações feitas em um thread não deve ser refletidas no outro.  
  
 Há várias formas para esse problema. A primeira é passar identificadores individuais (como uma `HWND`) em vez de objetos C++ para o thread de trabalho. O thread de trabalho, em seguida, adiciona esses objetos para seu mapa temporário chamando apropriada `FromHandle` função de membro. Você também pode adicionar o objeto ao mapa permanente do thread chamando **Attach**, mas isso deve ser feito apenas se têm a garantia de que o objeto existirá mais tempo do que o thread.  
  
 Outro método é criar novas mensagens definidas pelo usuário correspondente para as diferentes tarefas seus threads de trabalho será executando e postar essas mensagens para a janela principal do aplicativo usando **:: PostMessage**. Esse método de comunicação é semelhante a dois aplicativos diferentes conversar com exceção de que ambos os threads são executados no mesmo espaço de endereço.  
  
 Para obter mais informações sobre mapas de identificador, consulte [3 de observação técnica](../mfc/tn003-mapping-of-windows-handles-to-objects.md). Para obter mais informações sobre o armazenamento local de thread, consulte [armazenamento Local de Thread](http://msdn.microsoft.com/library/windows/desktop/ms686749) e [usando o armazenamento Local de Thread](http://msdn.microsoft.com/library/windows/desktop/ms686991) no [!INCLUDE[winsdkshort](../atl-mfc-shared/reference/includes/winsdkshort_md.md)].  
  
##  <a name="_core_communicating_between_threads"></a> Comunicação entre Threads  
 MFC fornece um número de classes que permitem que os threads sincronizar o acesso a objetos para manter a segurança do thread. O uso dessas classes é descrito em [Multithreading: como usar as Classes de sincronização](../parallel/multithreading-how-to-use-the-synchronization-classes.md) e [Multithreading: quando usar as Classes de sincronização](../parallel/multithreading-when-to-use-the-synchronization-classes.md). Para obter mais informações sobre esses objetos, consulte [sincronização](http://msdn.microsoft.com/library/windows/desktop/ms686353) no [!INCLUDE[winsdkshort](../atl-mfc-shared/reference/includes/winsdkshort_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Multithreading com C++ e MFC](../parallel/multithreading-with-cpp-and-mfc.md)