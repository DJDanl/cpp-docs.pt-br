---
title: 'Multithreading: encerrando threads no MFC'
ms.date: 08/27/2018
helpviewer_keywords:
- premature thread termination
- starting threads
- threading [MFC], terminating threads
- multithreading [C++], terminating threads
- threading [C++], stopping threads
- terminating threads
- stopping threads
- AfxEndThread method
ms.assetid: 4c0a8c6d-c02f-456d-bd02-0a8c8d006ecb
ms.openlocfilehash: 0625be0a628a6ae991acd2fa1f7118a4deabccda
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217864"
---
# <a name="multithreading-terminating-threads-in-mfc"></a>Multithreading: encerrando threads no MFC

Duas situações normais fazem com que um thread seja encerrado: a função de controle é encerrada ou o thread não tem permissão para ser executado até a conclusão. Se um processador de texto usava um thread para impressão em segundo plano, a função de controle será encerrada normalmente se a impressão for concluída com êxito. No entanto, se o usuário quiser cancelar a impressão, o thread de impressão em segundo plano precisará ser encerrado prematuramente. Este tópico explica como implementar cada situação e como obter o código de saída de um thread após sua finalização.

- [Término de thread normal](#_core_normal_thread_termination)

- [Término prematuro de thread](#_core_premature_thread_termination)

- [Recuperando o código de saída de um thread](#_core_retrieving_the_exit_code_of_a_thread)

## <a name="normal-thread-termination"></a><a name="_core_normal_thread_termination"></a>Término de thread normal

Para um thread de trabalho, a terminação de thread normal é simples: saia da função de controle e retorne um valor que significa o motivo do encerramento. Você pode usar a função [AfxEndThread](../mfc/reference/application-information-and-management.md#afxendthread) ou uma **`return`** instrução. Normalmente, 0 significa conclusão bem-sucedida, mas cabe a você.

Para um thread de interface do usuário, o processo é tão simples quanto: de dentro do thread da interface do usuário, chame [PostQuitMessage](/windows/win32/api/winuser/nf-winuser-postquitmessage) no SDK do Windows. O único parâmetro que `PostQuitMessage` usa é o código de saída do thread. Para threads de trabalho, 0 normalmente significa uma conclusão bem-sucedida.

## <a name="premature-thread-termination"></a><a name="_core_premature_thread_termination"></a>Término prematuro de thread

Encerrar um thread prematuramente é quase tão simples: chame [AfxEndThread](../mfc/reference/application-information-and-management.md#afxendthread) de dentro do thread. Passe o código de saída desejado como o único parâmetro. Isso interrompe a execução do thread, desaloca a pilha do thread, desanexa todas as DLLs anexadas ao thread e exclui o objeto de thread da memória.

`AfxEndThread`deve ser chamado de dentro do thread a ser encerrado. Se você quiser encerrar um thread de outro thread, deverá configurar um método de comunicação entre os dois threads.

## <a name="retrieving-the-exit-code-of-a-thread"></a><a name="_core_retrieving_the_exit_code_of_a_thread"></a>Recuperando o código de saída de um thread

Para obter o código de saída do thread de trabalho ou da interface do usuário, chame a função [GetExitCodeThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodethread) . Para obter informações sobre essa função, consulte a SDK do Windows. Essa função usa o identificador para o thread (armazenado no `m_hThread` membro de dados de `CWinThread` objetos) e o endereço de um DWORD.

Se o thread ainda estiver ativo, o `GetExitCodeThread` colocará STILL_ACTIVE no endereço DWORD fornecido; caso contrário, o código de saída será colocado nesse endereço.

A recuperação do código de saída dos objetos [CWinThread](../mfc/reference/cwinthread-class.md) leva a uma etapa extra. Por padrão, quando um `CWinThread` thread é encerrado, o objeto de thread é excluído. Isso significa que você não pode acessar o `m_hThread` membro de dados porque o `CWinThread` objeto não existe mais. Para evitar essa situação, siga um destes procedimentos:

- Defina o `m_bAutoDelete` membro de dados como false. Isso permite que o `CWinThread` objeto sobreviver após o término do thread. Você pode acessar o `m_hThread` membro de dados depois que o thread tiver sido encerrado. No entanto, se você usar essa técnica, será responsável por destruir o `CWinThread` objeto porque a estrutura não o excluirá automaticamente para você. Este é o método preferencial.

- Armazene o identificador do thread separadamente. Depois que o thread for criado, copie seu `m_hThread` membro de dados (usando `::DuplicateHandle` ) para outra variável e acesse-o por meio dessa variável. Dessa forma, o objeto é excluído automaticamente quando o encerramento ocorre e você ainda pode descobrir por que o thread foi encerrado. Tenha cuidado para que o thread não seja encerrado antes de você poder duplicar o identificador. A maneira mais segura de fazer isso é passar CREATE_SUSPENDED para [AfxBeginThread](../mfc/reference/application-information-and-management.md#afxbeginthread), armazenar o identificador e, em seguida, retomar o thread chamando [ResumeThread](../mfc/reference/cwinthread-class.md#resumethread).

Qualquer método permite determinar por que um `CWinThread` objeto foi encerrado.

## <a name="see-also"></a>Confira também

[Multithread com C++ e MFC](multithreading-with-cpp-and-mfc.md)<br/>
[_endthread, _endthreadex](../c-runtime-library/reference/endthread-endthreadex.md)<br/>
[_beginthread, _beginthreadex](../c-runtime-library/reference/beginthread-beginthreadex.md)<br/>
[ExitThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-exitthread)
