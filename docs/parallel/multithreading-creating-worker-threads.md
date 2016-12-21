---
title: "Multithread: criando threads de trabalho | Microsoft Docs"
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
  - "tarefas em segundo plano [C++]"
  - "multithreading [C++], threads de trabalho"
  - "threading [C++], criando threads"
  - "threading [C++], entrada de usuário não necessária"
  - "threading [C++], threads de trabalho"
  - "threading [MFC], threads de trabalho"
  - "threads de trabalho [C++]"
ms.assetid: 670adbfe-041c-4450-a3ed-be14aab15234
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Multithread: criando threads de trabalho
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um thread de trabalho é comumente usado para controlar tarefas em segundo plano que o usuário não deve ter que aguardar para continuar usando seu aplicativo.  Tarefas como o recálculo e a impressão em segundo plano são bons exemplos de threads de trabalho.  Este tópico detalha as etapas necessárias à criação de um thread de trabalho.  Os tópicos incluem:  
  
-   [Iniciando o thread](#_core_starting_the_thread)  
  
-   [Implementando a função de controle](#_core_implementing_the_controlling_function)  
  
-   [Exemplo](#_core_controlling_function_example)  
  
 Criar um thread de trabalho é uma tarefa relativamente simples.  Somente duas etapas são necessárias para fazer seu thread ser executado: implementar a função de controle e iniciar o thread.  Não é necessário derivar uma classe de [CWinThread](../mfc/reference/cwinthread-class.md).  É possível derivar uma classe se você precisar de uma versão especial do `CWinThread`, mas isso não é necessário para a maioria das threads de trabalho simples.  É possível usar o `CWinThread` sem alteração.  
  
##  <a name="_core_starting_the_thread"></a> Iniciando o thread  
 Há duas versões sobrecarregadas de `AfxBeginThread`: uma que só cria threads de trabalho e outra que pode criar threads de interface de usuário e threads de trabalho.  Para iniciar a execução de seu thread de trabalho usando a primeira sobrecarga, chame [AfxBeginThread](../Topic/AfxBeginThread.md) fornecendo as seguintes informações:  
  
-   O endereço da função de controle.  
  
-   O parâmetro a ser passado para a função de controle.  
  
-   \(Opcional\) A prioridade desejada do thread.  O padrão é prioridade normal.  Para obter mais informações sobre os níveis de prioridade disponíveis, consulte [SetThreadPriority](http://msdn.microsoft.com/library/windows/desktop/ms686277) em [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)].  
  
-   \(Opcional\) O tamanho desejado de pilha para o thread.  O padrão é o mesmo tamanho de pilha do thread de criação.  
  
-   \(Opcional\) **CREATE\_SUSPENDED** se você deseja que o segmento seja criado em um estado suspenso.  O padrão é 0 ou iniciar o thread normalmente.  
  
-   \(Opcional\) Os atributos de segurança desejados.  O padrão é o mesmo acesso que o thread pai.  Para obter mais informações sobre o formato dessas informações de segurança, consulte [ATRIBUTOS DE SEGURANÇA](http://msdn.microsoft.com/library/windows/desktop/aa379560) em [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)].  
  
 `AfxBeginThread` cria e inicializa um objeto `CWinThread` para você, inicia o e retorna seu endereço para que você possa consultá\-lo posteriormente.  As verificações são feitas durante qualquer procedimento para certificar\-se que todos os objetos são desalocados corretamente se qualquer parte da falha de design.  
  
##  <a name="_core_implementing_the_controlling_function"></a> Implementando a função de controle  
 A função de controle define o thread.  A thread é iniciada quando a função é inserida e encerrada quando a função é finalizada.  Essa função deve ter o seguinte protótipo:  
  
```  
UINT MyControllingFunction( LPVOID pParam );  
```  
  
 O parâmetro é um valor único.  O valor que a função recebe neste parâmetro é o valor que foi passado para o construtor quando o objeto de thread foi criado.  A função de controle pode interpretar esse valor de qualquer forma que escolher.  Pode ser tratado como um valor escalar ou um ponteiro para uma estrutura que contém vários parâmetros, ou pode ser ignorado.  Se o parâmetro refere\-se a uma estrutura, a estrutura pode ser usada para transmitir não apenas dados do chamador para o thread, mas também para passar dados de volta do thread para o chamador.  Caso você use essa estrutura para repassar dados ao chamador, o thread precisa notificar o chamador quando os resultados estão prontos.  Para obter informações sobre a comunicação do thread de trabalho com o chamador, consulte [Multithreading: Dicas de programação](../parallel/multithreading-programming-tips.md).  
  
 Quando a função encerrar, ela deverá retornar um valor de **UINT** que indica a razão para o encerramento.  Em geral, esse código de saída é 0 para indicar o êxito com outros valores que indicam diferentes tipos de erros.  Isso é puramente dependente de implementação.  Alguns threads podem manter contagens de uso de objetos e retornar o número atual de usos desse objeto.  Para ver como os aplicativos podem recuperar esse valor, consulte [Multithreading: Segmentos de terminação](../parallel/multithreading-terminating-threads.md).  
  
 Há algumas restrições sobre o que você pode fazer em um programa multithreaded escrito com a biblioteca do MFC.  Para obter descrições dessas restrições e outras dicas sobre o uso de threads, consulte [Multithreading: Dicas de programação](../parallel/multithreading-programming-tips.md).  
  
##  <a name="_core_controlling_function_example"></a> Exemplo da função de controle  
 O exemplo a seguir mostra como definir uma função de controle e usá\-la de outra parte do programa.  
  
```  
UINT MyThreadProc( LPVOID pParam )  
{  
    CMyObject* pObject = (CMyObject*)pParam;  
  
    if (pObject == NULL ||  
        !pObject->IsKindOf(RUNTIME_CLASS(CMyObject)))  
    return 1;   // if pObject is not valid  
  
    // do something with 'pObject'  
  
    return 0;   // thread completed successfully  
}  
  
// inside a different function in the program  
.  
.  
.  
pNewObject = new CMyObject;  
AfxBeginThread(MyThreadProc, pNewObject);  
.  
.  
.  
```  
  
## Que você deseja saber mais?  
  
-   [Multithreading: Criando Threads da Interface do Usuário](../parallel/multithreading-creating-user-interface-threads.md)  
  
## Consulte também  
 [Multithread com C\+\+ e MFC](../parallel/multithreading-with-cpp-and-mfc.md)