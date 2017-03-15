---
title: "Multithread: dicas de programa&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "controle de acesso [C++], multithreading"
  - "comunicações [C++], entre threads"
  - "seções críticas [C++]"
  - "mapas de identificador [C++]"
  - "multithreading [C++], dicas de programação"
  - "threads não MFC [C++]"
  - "objetos [C++], vários threads e"
  - "programação [C++], com multithread"
  - "sincronização [C++], multithreading"
  - "threading [C++], práticas recomendadas"
  - "threading [MFC], dicas de programação"
  - "solucionando problemas [C++], multithreading"
  - "mapas de identificador do Windows [C++]"
ms.assetid: ad14cc70-c91c-4c24-942f-13a75e58bf8a
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Multithread: dicas de programa&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os aplicativos multi\-threaded exigem um cuidado mais restrito de aplicativos de thread único para acessar dados.  Como há vários independentes, os caminhos de execução em uso simultaneamente em aplicativos multithreaded, os algoritmos, os dados, ou ambos devem saber que os dados possam ser usados por mais de um thread de cada vez.  Este tópico explica técnicas para evitar possíveis problemas ao programar aplicativos multi\-threaded com a biblioteca de \(MFC\) da classe do Microsoft.  
  
-   [Acessando objetos de vários threads](#_core_accessing_objects_from_multiple_threads)  
  
-   [Acessando objetos MFC de threads não MFC](#_core_accessing_mfc_objects_from_non.2d.mfc_threads)  
  
-   [Mapas do windows](#_core_windows_handle_maps)  
  
-   [Comunicação entre threads](#_core_communicating_between_threads)  
  
##  <a name="_core_accessing_objects_from_multiple_threads"></a> Acessando objetos de vários threads  
 Por motivo de desempenho, tamanho e dos objetos de MFC não é seguro para threads no nível de objeto, somente no nível da classe.  Isso significa que você pode ter dois threads separados que manipula dois objetos diferentes de `CString` , mas não dois threads que manipulam mesmo `CString` objeto.  Se você absolutamente necessário ter vários threads que manipulam o mesmo objeto, protege esse acesso com mecanismos adequados de sincronização do Win32, como seções críticos.  Para obter mais informações sobre as seções críticos e outros objetos relacionados, consulte [Sincronização](http://msdn.microsoft.com/library/windows/desktop/ms686353) em [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)].  
  
 A biblioteca de classe usar seções críticos internamente para proteger estruturas de dados globais, como as usadas pela alocação de memória de depuração.  
  
##  <a name="_core_accessing_mfc_objects_from_non.2d.mfc_threads"></a> Acessando objetos MFC de threads não MFC  
 Se você tiver um aplicativo multi\-threaded que cria um thread em um modo diferente da utilização de um objeto de [CWinThread](../mfc/reference/cwinthread-class.md) , você não pode acessar outros objetos MFC desse thread.  Ou seja se você quiser acessar qualquer objeto MFC de um thread secundário, você deve criar esse thread com um dos métodos descritos em [Multithreading: Criando threads da interface do usuário](../parallel/multithreading-creating-user-interface-threads.md) ou em [Multithreading: Criando threads de trabalho](../parallel/multithreading-creating-worker-threads.md).  Esses métodos são os únicos que permitem que a biblioteca de classes inicializa as variáveis internas necessários para controlar aplicativos multi\-threaded.  
  
##  <a name="_core_windows_handle_maps"></a> Mapas do windows  
 Como regra geral, um thread pode acessar apenas o MFC objetos que criou.  Isso porque os mapas temporários e permanentes do windows são mantidos no armazenamento de thread local para ajudar a manter a proteção de acesso simultâneo de vários threads.  Por exemplo, um thread de trabalho não pode executar um cálculo e chamar a função de membro de `UpdateAllViews` de um documento para que as janelas que contêm exibições nos novos dados alterados.  Isto não tem nenhum efeito de todo, pois os objetos de `CWnd` a `HWND`s é local para o thread principal.  Isso significa que um thread pode ter um mapeamento de um identificador do windows ao objeto c criando, mas outro thread pode mapear a mesma identificador para um objeto diferente C\+\+.  As alterações feitas em um thread não serão refletidas no outro.  
  
 Há várias formas solução alternativa para esse problema.  O primeiro é transmitir o identificador individual \(como `HWND`\) ao invés de objetos C\+\+ ao thread de trabalho.  O thread de trabalho adicione esses objetos em seu mapa temporário chamando a função de membro apropriado de `FromHandle` .  Você também pode adicionar o objeto ao mapa permanente de thread chamando **Anexar**, mas isso deve ser feito apenas se você garante que o objeto existirá por mais tempo que o thread.  
  
 Outro método é criar novas mensagens definidas pelo usuário que correspondem às tarefas que diferentes seus threads de trabalho serão executados e para publicar essas mensagens para a janela principal do aplicativo usando **::PostMessage**.  Esse método de comunicação é semelhante a dois aplicativos diferentes que conversam exceto que os threads estão em execução no mesmo espaço de endereço.  
  
 Para obter mais informações sobre mapas de identificador, consulte [Observação 3 técnica](../mfc/tn003-mapping-of-windows-handles-to-objects.md).  Para obter mais informações sobre o armazenamento de thread local, consulte [Executável o armazenamento local](http://msdn.microsoft.com/library/windows/desktop/ms686749) e [Usando armazenamento de thread local](http://msdn.microsoft.com/library/windows/desktop/ms686991) em [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)].  
  
##  <a name="_core_communicating_between_threads"></a> Comunicação entre threads  
 MFC O fornece um número de classes que permitem que os threads sincroniza o acesso a objetos para manter a segurança de thread.  O uso dessas classes é descrito em [Multithreading: Como usar as classes de sincronização](../parallel/multithreading-how-to-use-the-synchronization-classes.md) e em [Multithreading: Quando usar as classes de sincronização](../parallel/multithreading-when-to-use-the-synchronization-classes.md).  Para obter mais informações sobre esses objetos, consulte [Sincronização](http://msdn.microsoft.com/library/windows/desktop/ms686353) em [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)].  
  
## Consulte também  
 [Multithread com C\+\+ e MFC](../parallel/multithreading-with-cpp-and-mfc.md)