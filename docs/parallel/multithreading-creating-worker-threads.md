---
title: 'Multithreading: Criando Threads de trabalho no MFC'
ms.date: 11/04/2016
helpviewer_keywords:
- multithreading [C++], worker threads
- background tasks [C++]
- threading [C++], worker threads
- worker threads [C++]
- threading [C++], creating threads
- threading [MFC], worker threads
- threading [C++], user input not required
ms.assetid: 670adbfe-041c-4450-a3ed-be14aab15234
ms.openlocfilehash: f36e02d1ba6074a7ec8203bea761b3528a120162
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62212821"
---
# <a name="multithreading-creating-worker-threads-in-mfc"></a>Multithreading: Criando Threads de trabalho no MFC

Um thread de trabalho normalmente é usado para lidar com tarefas em segundo plano que o usuário não deve ter que aguardar para continuar a usar seu aplicativo. Tarefas como o recálculo e a impressão em segundo plano são bons exemplos de threads de trabalho. Este tópico detalha as etapas necessárias para criar um thread de trabalho. Os tópicos incluem:

- [Iniciando o thread](#_core_starting_the_thread)

- [Implementando a função de controle](#_core_implementing_the_controlling_function)

- [Exemplo](#_core_controlling_function_example)

Criar um thread de trabalho é uma tarefa relativamente simples. Apenas duas etapas são necessárias para fazer seu thread ser executado: implementar a função de controle e iniciar o thread. Não é necessário derivar uma classe de [CWinThread](../mfc/reference/cwinthread-class.md). Você pode derivar uma classe, se você precisar de uma versão especial do `CWinThread`, mas ele não é necessário para a maioria dos threads de trabalho simples. Você pode usar `CWinThread` sem modificação.

##  <a name="_core_starting_the_thread"></a> Iniciando o Thread

Há duas versões sobrecarregadas do `AfxBeginThread`: um que só cria threads de trabalho e outro que pode criar threads de interface do usuário e threads de trabalho. Para iniciar a execução de seu thread de trabalho usando a primeira sobrecarga, chame [AfxBeginThread](../mfc/reference/application-information-and-management.md#afxbeginthread), fornecendo as seguintes informações:

- O endereço da função de controle.

- O parâmetro a ser passado para a função de controle.

- (Opcional) A prioridade desejada do thread. O padrão é prioridade normal. Para obter mais informações sobre os níveis de prioridade disponíveis, consulte [SetThreadPriority](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadpriority) no SDK do Windows.

- (Opcional) O tamanho desejado de pilha do thread. O padrão é o mesmo tamanho de pilha do thread de criação.

- (Opcional) CREATE_SUSPENDED se você quiser que o thread a ser criado em um estado suspenso. O padrão é 0 ou iniciar o thread normalmente.

- (Opcional) Os atributos de segurança desejado. O padrão é o mesmo acesso que o thread pai. Para obter mais informações sobre o formato de informações de segurança, consulte [SECURITY_ATTRIBUTES](https://msdn.microsoft.com/library/windows/desktop/aa379560) no SDK do Windows.

`AfxBeginThread` cria e inicializa um `CWinThread` inicia o objeto para você e retorna seu endereço para que você possa consultá-lo mais tarde. Verificações são feitas em todo o procedimento para garantir que todos os objetos são desalocados corretamente caso de falha de qualquer parte da criação.

##  <a name="_core_implementing_the_controlling_function"></a> Implementando a função de controle

A função de controle define o thread. Quando essa função é inserida, o thread se inicia e quando ele é encerrado, o thread é encerrado. Essa função deve ter o seguinte protótipo:

```
UINT MyControllingFunction( LPVOID pParam );
```

O parâmetro é um único valor. O valor que a função recebe neste parâmetro é o valor que foi passado para o construtor quando o objeto de thread foi criado. A função de controle pode interpretar esse valor de qualquer forma que escolher. Ele pode ser tratado como um valor escalar ou um ponteiro para uma estrutura que contém vários parâmetros, ou ele pode ser ignorado. Se o parâmetro faz referência a uma estrutura, a estrutura pode ser usada não apenas para passar dados do chamador para o thread, mas também para passar dados de volta do thread para o chamador. Se você usar essa estrutura para passar dados de volta para o chamador, o thread precisa notificar o chamador quando os resultados estão prontos. Para obter informações sobre a comunicação do thread de trabalho para o chamador, consulte [Multithreading: Dicas de programação](multithreading-programming-tips.md).

Quando a função é encerrada, ele deverá retornar um valor UINT indicando o motivo do encerramento. Normalmente, esse código de saída é 0 para indicar êxito com outros valores que indicam diferentes tipos de erros. Isso é puramente dependente de implementação. Alguns threads podem manter contagens de uso de objetos e retornar o número atual de usos desse objeto. Para ver como os aplicativos podem recuperar esse valor, consulte [Multithreading: Encerrando Threads](multithreading-terminating-threads.md).

Há algumas restrições sobre o que você pode fazer em um programa multithreaded escrito com a biblioteca do MFC. Para obter descrições dessas restrições e outras dicas sobre o uso de threads, consulte [Multithreading: Dicas de programação](multithreading-programming-tips.md).

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

- [Multithreading: criar threads de interface de usuário](multithreading-creating-user-interface-threads.md)

## <a name="see-also"></a>Consulte também

[Multithreading com C++ e MFC](multithreading-with-cpp-and-mfc.md)
