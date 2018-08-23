---
title: 'Multithreading: Dicas de programação | Microsoft Docs'
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
ms.openlocfilehash: 2ad830117323aef807fcebc1ef61b4dfb1900bd9
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42591305"
---
# <a name="multithreading-programming-tips"></a>Multithread: dicas de programação
Aplicativos multithread exigem cuidados mais rígidos que aplicativos de thread único, ao acessar dados. Como há vários, independentes caminhos de execução em usam simultaneamente em aplicativos multithreaded, os algoritmos, os dados ou ambos devem estar cientes que os dados podem ser usados por mais de um thread por vez. Este tópico explica as técnicas para evitar possíveis problemas ao programar aplicativos multithread com a biblioteca Microsoft Foundation Class (MFC).  
  
- [Acessar objetos de vários Threads](#_core_accessing_objects_from_multiple_threads)  
  
- [Acessando objetos MFC de Threads não MFC](#_core_accessing_mfc_objects_from_non.2d.mfc_threads)  
  
- [Mapas de identificador do Windows](#_core_windows_handle_maps)  
  
- [Comunicação entre Threads](#_core_communicating_between_threads)  
  
##  <a name="_core_accessing_objects_from_multiple_threads"></a> Acessar objetos de vários Threads  
 
Por motivos de desempenho e tamanho, objetos MFC não são thread-safe no nível do objeto, somente no nível de classe. Isso significa que você pode ter dois processos separados, manipulação de duas diferentes `CString` objetos, mas não de dois threads manipulando o mesmo `CString` objeto. Se for absolutamente necessário ter vários threads manipulando o mesmo objeto, proteger esse acesso com mecanismos de sincronização Win32 apropriados, como seções críticas. Para obter mais informações sobre as seções críticas e outros objetos relacionados, consulte [sincronização](http://msdn.microsoft.com/library/windows/desktop/ms686353) no SDK do Windows.  
  
A biblioteca de classes usa seções críticas internamente para proteger as estruturas de dados globais, como aqueles usados pela alocação de memória de depuração.  
  
##  <a name="_core_accessing_mfc_objects_from_non.2d.mfc_threads"></a> Acessando objetos MFC de Threads não MFC  
 
Se você tiver um aplicativo multi-threaded que cria um thread de forma que não seja usando um [CWinThread](../mfc/reference/cwinthread-class.md) do objeto, você não pode acessar outros objetos MFC de thread em questão. Em outras palavras, se você quiser acessar qualquer objeto do MFC de um thread secundário, você deve criar esse thread com um dos métodos descritos em [Multithreading: Criando Threads de Interface do usuário](../parallel/multithreading-creating-user-interface-threads.md) ou [Multithreading: Criando Threads de trabalho](../parallel/multithreading-creating-worker-threads.md). Esses métodos são os únicos que permitem que a biblioteca de classes inicializar as variáveis internas necessárias para lidar com aplicativos multi-threaded.  
  
##  <a name="_core_windows_handle_maps"></a> Mapas de identificador do Windows  
 
Como regra geral, um thread pode acessar somente os objetos MFC que ele criou. Isso ocorre porque os mapas de identificador Windows temporários e permanentes são mantidos no armazenamento local de thread para ajudar a manter a proteção de acesso simultâneo de vários threads. Por exemplo, um thread de trabalho não é possível executar um cálculo e, em seguida, chamar um documento `UpdateAllViews` a função de membro para ter o windows que contêm exibições sobre os novos dados modificados. Isso não tem nenhum efeito, porque o mapa de `CWnd` objetos a serem HWNDs é local para o thread primário. Isso significa que um thread pode ter um mapeamento de um identificador do Windows para um objeto C++, mas outro thread pode ser mapeado esse mesmo identificador para um objeto diferente de C++. As alterações feitas em um thread não seriam refletidas no outro.  
  
Há várias maneiras de resolver esse problema. A primeira é passar identificadores individuais (como um HWND) em vez de objetos de C++ para o thread de trabalho. O thread de trabalho, em seguida, adiciona esses objetos para seu mapa temporário chamando apropriado `FromHandle` função de membro. Você também pode adicionar o objeto de mapa de permanente do thread chamando `Attach`, mas isso deve ser feito apenas se você tem a garantia que o objeto existirá mais tempo do que o thread.  
  
Outro método é criar novas mensagens definidas pelo usuário correspondente para as diferentes tarefas seus threads de trabalho será executando e postar essas mensagens em janela principal do aplicativo usando `::PostMessage`. Esse método de comunicação é semelhante a dois aplicativos diferentes que conversam, exceto pelo fato de que ambos os threads estão em execução no mesmo espaço de endereço.  
  
Para obter mais informações sobre mapas de identificador, consulte [Technical Observação 3](../mfc/tn003-mapping-of-windows-handles-to-objects.md). Para obter mais informações sobre o armazenamento local de thread, consulte [armazenamento Local de Thread](http://msdn.microsoft.com/library/windows/desktop/ms686749) e [usando o armazenamento Local de Thread](http://msdn.microsoft.com/library/windows/desktop/ms686991) no SDK do Windows.  
  
##  <a name="_core_communicating_between_threads"></a> Comunicação entre Threads  
 
MFC fornece várias classes que permitem que os threads sincronizar o acesso a objetos para manter o acesso thread-safe. O uso dessas classes é descrito em [Multithreading: como usar as Classes de sincronização](../parallel/multithreading-how-to-use-the-synchronization-classes.md) e [Multithreading: quando usar as Classes de sincronização](../parallel/multithreading-when-to-use-the-synchronization-classes.md). Para obter mais informações sobre esses objetos, consulte [sincronização](http://msdn.microsoft.com/library/windows/desktop/ms686353) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  

[Multithreading com C++ e MFC](../parallel/multithreading-with-cpp-and-mfc.md)