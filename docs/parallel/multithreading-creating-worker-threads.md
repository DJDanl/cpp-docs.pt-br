---
title: 'Multithreading: criando threads de trabalho no MFC'
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
ms.openlocfilehash: ab5b05b64ebcfbd6d15bd2229ee19d18fa7f919d
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77140510"
---
# <a name="multithreading-creating-worker-threads-in-mfc"></a>Multithreading: criando threads de trabalho no MFC

Um thread de trabalho é comumente usado para lidar com tarefas em segundo plano que o usuário não deve esperar para continuar usando seu aplicativo. Tarefas como recálculo e impressão em segundo plano são bons exemplos de threads de trabalho. Este tópico detalha as etapas necessárias para criar um thread de trabalho. Os tópicos incluem:

- [Iniciando o thread](#_core_starting_the_thread)

- [Implementando a função de controle](#_core_implementing_the_controlling_function)

- [Exemplo](#_core_controlling_function_example)

Criar um thread de trabalho é uma tarefa relativamente simples. Somente duas etapas são necessárias para que seu thread seja executado: implementando a função de controle e iniciando o thread. Não é necessário derivar uma classe de [CWinThread](../mfc/reference/cwinthread-class.md). Você pode derivar uma classe se precisar de uma versão especial do `CWinThread`, mas ela não é necessária para a maioria dos threads de trabalho simples. Você pode usar `CWinThread` sem modificação.

## <a name="_core_starting_the_thread"></a>Iniciando o thread

Há duas versões sobrecarregadas do `AfxBeginThread`: uma que só pode criar threads de trabalho e uma que possa criar threads de interface do usuário e threads de trabalho. Para iniciar a execução do thread de trabalho usando a primeira sobrecarga, chame [AfxBeginThread](../mfc/reference/application-information-and-management.md#afxbeginthread), fornecendo as seguintes informações:

- O endereço da função de controle.

- O parâmetro a ser passado para a função de controle.

- Adicional A prioridade desejada do thread. O padrão é a prioridade normal. Para obter mais informações sobre os níveis de prioridade disponíveis, consulte [SetThreadPriority](/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadpriority) no SDK do Windows.

- Adicional O tamanho de pilha desejado para o thread. O padrão é a mesma pilha de tamanho que o thread de criação.

- Adicional CREATE_SUSPENDED se você quiser que o thread seja criado em um estado suspenso. O padrão é 0 ou iniciar o thread normalmente.

- Adicional Os atributos de segurança desejados. O padrão é o mesmo acesso que o thread pai. Para obter mais informações sobre o formato dessas informações de segurança, consulte [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) no SDK do Windows.

`AfxBeginThread` cria e inicializa um objeto de `CWinThread` para você, inicia-o e retorna seu endereço para que você possa consultá-lo mais tarde. As verificações são feitas em todo o procedimento para garantir que todos os objetos sejam desalocados corretamente caso qualquer parte da criação falhe.

## <a name="_core_implementing_the_controlling_function"></a>Implementando a função de controle

A função de controle define o thread. Quando essa função é inserida, o thread é iniciado e quando ele é encerrado, o thread é encerrado. Essa função deve ter o seguinte protótipo:

```cpp
UINT MyControllingFunction( LPVOID pParam );
```

O parâmetro é um único valor. O valor que a função recebe nesse parâmetro é o valor que foi passado para o Construtor quando o objeto de thread foi criado. A função de controle pode interpretar esse valor de qualquer maneira que escolher. Ele pode ser tratado como um valor escalar ou um ponteiro para uma estrutura que contém vários parâmetros ou pode ser ignorado. Se o parâmetro se referir a uma estrutura, a estrutura poderá ser usada não apenas para passar dados do chamador para o thread, mas também para passar dados de volta do thread para o chamador. Se você usar essa estrutura para passar dados de volta para o chamador, o thread precisará notificar o chamador quando os resultados estiverem prontos. Para obter informações sobre como se comunicar do thread de trabalho com o chamador, consulte [multithreading: dicas de programação](multithreading-programming-tips.md).

Quando a função é encerrada, ela deve retornar um valor UINT que indica o motivo do encerramento. Normalmente, esse código de saída é 0 para indicar êxito com outros valores indicando diferentes tipos de erros. Isso é puramente dependente de implementação. Alguns threads podem manter contagens de uso de objetos e retornar o número atual de usos desse objeto. Para ver como os aplicativos podem recuperar esse valor, consulte [multithreading: encerrando threads](multithreading-terminating-threads.md).

Há algumas restrições sobre o que você pode fazer em um programa multithread escrito com a biblioteca do MFC. Para obter descrições dessas restrições e outras dicas sobre como usar threads, consulte [multithreading: dicas de programação](multithreading-programming-tips.md).

## <a name="_core_controlling_function_example"></a>Exemplo de função de controle

O exemplo a seguir mostra como definir uma função de controle e usá-la de outra parte do programa.

```cpp
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

- [Multithreading: criando threads da interface do usuário](multithreading-creating-user-interface-threads.md)

## <a name="see-also"></a>Consulte também

[Multithreading com C++ e MFC](multithreading-with-cpp-and-mfc.md)
