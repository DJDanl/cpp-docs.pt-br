---
title: 'Multithread: Criando Threads de trabalho | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- multithreading [C++], worker threads
- background tasks [C++]
- threading [C++], worker threads
- worker threads [C++]
- threading [C++], creating threads
- threading [MFC], worker threads
- threading [C++], user input not required
ms.assetid: 670adbfe-041c-4450-a3ed-be14aab15234
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 175fc018ddba436f9a331f861a492dcd43e1ec1e
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="multithreading-creating-worker-threads"></a>Multithread: criando threads de trabalho
Um thread de trabalho normalmente é usado para lidar com tarefas em segundo plano que o usuário não deve ter para aguardar para continuar a usar seu aplicativo. Tarefas, como o recálculo e impressão de plano de fundo são bons exemplos de threads de trabalho. Este tópico detalha as etapas necessárias para criar um thread de trabalho. Os tópicos incluem:  
  
-   [Iniciando o thread](#_core_starting_the_thread)  
  
-   [Implementando a função de controle](#_core_implementing_the_controlling_function)  
  
-   [Exemplo](#_core_controlling_function_example)  
  
 Criar um thread de trabalho é uma tarefa relativamente simples. Apenas duas etapas são necessárias para obter o thread em execução: Implementando a função de controle e iniciar o thread. Não é necessário derivar uma classe de [CWinThread](../mfc/reference/cwinthread-class.md). Você pode derivar uma classe, se você precisar de uma versão especial do `CWinThread`, mas ele não é necessário para a maioria dos threads de trabalho simples. Você pode usar `CWinThread` sem modificação.  
  
##  <a name="_core_starting_the_thread"></a> Iniciando o Thread  
 Há duas versões sobrecarregadas de `AfxBeginThread`: uma que só pode criar threads de trabalho e outra que pode criar threads de interface do usuário e de threads de trabalho. Para começar a execução do seu thread de trabalho usando a primeira sobrecarga, chame [AfxBeginThread](../mfc/reference/application-information-and-management.md#afxbeginthread), fornecendo as seguintes informações:  
  
-   O endereço da função de controle.  
  
-   O parâmetro a ser passado para a função de controle.  
  
-   (Opcional) A prioridade desejada do thread. O padrão é a prioridade normal. Para obter mais informações sobre os níveis de prioridade disponíveis, consulte [SetThreadPriority](http://msdn.microsoft.com/library/windows/desktop/ms686277) no [!INCLUDE[winsdkshort](../atl-mfc-shared/reference/includes/winsdkshort_md.md)].  
  
-   (Opcional) O tamanho da pilha desejado para o thread. O padrão é a mesma pilha de tamanho, como o thread de criação.  
  
-   (Opcional) **CREATE_SUSPENDED** se você quiser que o thread a ser criado em um estado suspenso. O padrão é 0, ou iniciar o thread normalmente.  
  
-   (Opcional) Os atributos de segurança desejado. O padrão é o mesmo acesso que o thread de pai. Para obter mais informações sobre o formato dessas informações de segurança, consulte [SECURITY_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379560) no [!INCLUDE[winsdkshort](../atl-mfc-shared/reference/includes/winsdkshort_md.md)].  
  
 `AfxBeginThread` cria e inicializa um `CWinThread` objeto, inicia e retorna seu endereço para que você possa consultá-lo mais tarde. Verificações são feitas em todo o procedimento para verificar se que todos os objetos são desalocados corretamente caso de falha de qualquer parte da criação.  
  
##  <a name="_core_implementing_the_controlling_function"></a> Implementando a função de controle  
 A função de controle define o thread. Quando essa função é inserida, o thread é iniciado e quando ela for encerrada, o segmento é encerrado. Essa função deve ter o seguinte protótipo:  
  
```  
UINT MyControllingFunction( LPVOID pParam );  
```  
  
 O parâmetro é um valor único. O valor que a função recebe esse parâmetro é o valor que foi passado para o construtor quando o objeto de thread foi criado. A função de controle pode interpretar esse valor, de alguma forma, que ele escolhe. Ele pode ser tratado como um valor escalar ou um ponteiro para uma estrutura que contém vários parâmetros, ou pode ser ignorado. Se o parâmetro faz referência a uma estrutura, a estrutura pode ser usada não apenas para passar dados do chamador para o thread, mas também para passar dados do thread para o chamador. Se você usar dessa estrutura para passar dados de volta para o chamador, o thread precisa notificar o chamador quando os resultados estão prontos. Para obter informações sobre a comunicação do thread de trabalho para o chamador, consulte [Multithreading: dicas de programação](../parallel/multithreading-programming-tips.md).  
  
 Quando a função termina, ele deverá retornar um **UINT** valor que indica o motivo do término. Normalmente, este código de saída é 0 para indicar êxito com outros valores que indica os diferentes tipos de erros. Isso é totalmente dependente de implementação. Alguns threads podem manter contagens de uso de objetos e retornar o número atual de usos do objeto. Para ver como os aplicativos podem recuperar esse valor, consulte [Multithreading: encerrando Threads](../parallel/multithreading-terminating-threads.md).  
  
 Há algumas restrições sobre o que você pode fazer em um programa multi-threaded escrito com a biblioteca do MFC. Para obter descrições dessas restrições e outras dicas sobre o uso de threads, consulte [Multithreading: dicas de programação](../parallel/multithreading-programming-tips.md).  
  
##  <a name="_core_controlling_function_example"></a> Controlando o exemplo de função  
 O exemplo a seguir mostra como definir uma função de controle e usá-lo de outra parte do programa.  
  
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
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [Multithreading: criando threads da interface do usuário](../parallel/multithreading-creating-user-interface-threads.md)  
  
## <a name="see-also"></a>Consulte também  
 [Multithreading com C++ e MFC](../parallel/multithreading-with-cpp-and-mfc.md)