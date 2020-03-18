---
title: Perguntas frequentes do MFC DLL
ms.date: 05/06/2019
helpviewer_keywords:
- troubleshooting [C++], DLLs
- DLLs [C++], frequently asked questions
- FAQs [C++], DLLs
ms.assetid: 09dd068e-fc33-414e-82f7-289c70680256
ms.openlocfilehash: 9108aaf3fcface847b0391455a2aecd4d45658c4
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79417344"
---
# <a name="dll-frequently-asked-questions"></a>{1&gt;Perguntas frequentes sobre DLLs&lt;1}

Veja a seguir algumas perguntas frequentes sobre DLLs.

- [Uma DLL do MFC pode criar vários threads?](#mfc_multithreaded_1)

- [Um aplicativo multithread pode acessar uma DLL do MFC em threads diferentes?](#mfc_multithreaded_2)

- [Há alguma classe ou função do MFC que não pode ser usada em uma DLL do MFC?](#mfc_prohibited_classes)

- [Quais técnicas de otimização devo usar para melhorar o desempenho do aplicativo cliente ao carregar?](#mfc_optimization)

- [Há um vazamento de memória em minha DLL do MFC regular, mas meu código parece bom. Como posso encontrar o vazamento de memória?](#memory_leak)

## <a name="mfc_multithreaded_1"></a>Uma DLL do MFC pode criar vários threads?

Exceto durante a inicialização, uma DLL do MFC pode criar vários threads com segurança, desde que use as funções do armazenamento local de threads do Win32 (TLS), como **TlsAlloc** , para alocar o armazenamento local do thread. No entanto, se uma DLL **do MFC usar __declspec (thread)** para alocar o armazenamento local do thread, o aplicativo cliente deverá ser vinculado implicitamente à dll. Se o aplicativo cliente for vinculado explicitamente à DLL, a chamada para **LoadLibrary** não carregará a dll com êxito. Para obter mais informações sobre variáveis locais de thread em DLLs, consulte [thread](../cpp/thread.md).

Uma DLL do MFC que cria um novo thread MFC durante a inicialização deixará de responder quando for carregada por um aplicativo. Isso inclui sempre que um thread é criado chamando `AfxBeginThread` ou `CWinThread::CreateThread` dentro:

- O `InitInstance` de um objeto derivado de `CWinApp`em uma DLL do MFC regular.

- Uma função `DllMain` ou **RawDllMain** fornecida em uma DLL do MFC regular.

- Uma função `DllMain` ou **RawDllMain** fornecida em uma DLL de extensão do MFC.

## <a name="mfc_multithreaded_2"></a>Um aplicativo multithread pode acessar uma DLL do MFC em threads diferentes?

Os aplicativos multithread podem acessar DLLs do MFC regulares que se vinculam dinamicamente a DLLs de extensão MFC e MFC de threads diferentes. Um aplicativo pode acessar DLLs do MFC regulares que são vinculadas estaticamente ao MFC de vários threads criados no aplicativo.

## <a name="mfc_prohibited_classes"></a>Há alguma classe ou função do MFC que não pode ser usada em uma DLL do MFC?

DLLs de extensão usam a classe derivada de `CWinApp`do aplicativo cliente. Eles não devem ter sua própria classe derivada de `CWinApp`.

As DLLs regulares do MFC devem ter uma classe derivada de `CWinApp`e um único objeto dessa classe de aplicativo, assim como um aplicativo MFC. Ao contrário do objeto `CWinApp` de um aplicativo, o objeto `CWinApp` da DLL não tem um bomba principal de mensagem.

Observe que, como o mecanismo de `CWinApp::Run` não se aplica a uma DLL, o aplicativo possui a bomba principal de mensagem. Se a DLL abrir caixas de diálogo sem janela restrita ou tiver uma janela de quadro principal própria, a bomba principal da mensagem do aplicativo deverá chamar uma rotina exportada pela DLL que, por sua vez, chama a função membro `CWinApp::PreTranslateMessage` do objeto de aplicativo da DLL.

## <a name="mfc_optimization"></a>Quais técnicas de otimização devo usar para melhorar o desempenho do&#39;aplicativo cliente durante o carregamento?

Se sua DLL for uma DLL do MFC regular que é vinculada estaticamente ao MFC, alterá-la para uma DLL do MFC regular que é vinculada dinamicamente ao MFC reduz o tamanho do arquivo.

Se a DLL tiver um grande número de funções exportadas, use um arquivo. def para exportar as funções (em vez de usar **__declspec (dllexport)** ) e use o [atributo NONAME](exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md) de arquivo. def em cada função exportada. O atributo NONAME faz com que apenas o valor ordinal e não o nome da função sejam armazenados na tabela de exportação da DLL, o que reduz o tamanho do arquivo.

As DLLs que são vinculadas implicitamente a um aplicativo são carregadas quando o aplicativo é carregado. Para melhorar o desempenho durante o carregamento, tente dividir a DLL em DLLs diferentes. Coloque todas as funções que o aplicativo de chamada precisa imediatamente após o carregamento em uma DLL e faça com que o aplicativo de chamada vincule implicitamente a essa DLL. Coloque as outras funções que o aplicativo de chamada não precisa imediatamente em outra DLL e faça com que o aplicativo seja vinculado explicitamente a essa DLL. Para obter mais informações, consulte [vincular um executável a uma DLL](linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use).

## <a name="memory_leak"></a>Há&#39;um vazamento de memória em minha dll comum do MFC, mas meu código parece bem. Como posso encontrar o vazamento de memória?

Uma possível causa do vazamento de memória é que o MFC cria objetos temporários que são usados dentro de funções de manipulador de mensagens. Em aplicativos MFC, esses objetos temporários são limpos automaticamente na função `CWinApp::OnIdle()` que é chamada entre as mensagens de processamento. No entanto, nas bibliotecas de vínculo dinâmico (DLLs) do MFC, a função `OnIdle()` não é chamada automaticamente. Como resultado, os objetos temporários não são limpos automaticamente. Para limpar objetos temporários, a DLL deve chamar explicitamente `OnIdle(1)` periodicamente.

## <a name="see-also"></a>Confira também

[Criar DLLs C /C++ no Visual Studio](dlls-in-visual-cpp.md)
