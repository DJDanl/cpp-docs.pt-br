---
title: Perguntas frequentes sobre o DLL do MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- troubleshooting [C++], DLLs
- DLLs [C++], frequently asked questions
- FAQs [C++], DLLs
ms.assetid: 09dd068e-fc33-414e-82f7-289c70680256
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6f5740989562aea799f3a49adfa464e2c460acb3
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32372504"
---
# <a name="dll-frequently-asked-questions"></a>Perguntas frequentes sobre DLL  
  
A seguir está algumas perguntas frequentes (FAQ) sobre DLLs.  
    
-   [Uma DLL MFC pode criar vários threads?](#mfc_multithreaded_1)  

-   [Um aplicativo multithread pode acessar uma DLL MFC em threads diferentes?](#mfc_multithreaded_2)  
  
-   [Existem classes MFC ou funções que não podem ser usadas em uma DLL MFC?](#mfc_prohibited_classes)  
  
-   [As técnicas de otimização devo usar para melhorar o desempenho do aplicativo cliente durante o carregamento?](#mfc_optimization)  
  
-   [Há um vazamento de memória em minha DLL MFC regular, mas meu código parece correto. Como localizar o vazamento de memória?](#memory_leak)  

## <a name="mfc_multithreaded_1"></a> Uma DLL MFC pode criar vários threads?  
  
Exceto durante a inicialização, uma DLL MFC pode crie com segurança vários threads desde que ele usa o thread de Win32 TLS (armazenamento local), como funções **TlsAlloc** alocar armazenamento local de thread. No entanto, se usar uma DLL MFC **__declspec(thread)** para alocar armazenamento local de thread, o aplicativo cliente deve ser implicitamente vinculado à DLL. Se o aplicativo cliente explicitamente links para a DLL, a chamada para **LoadLibrary** não será carregado com êxito a DLL. Para obter mais informações sobre a criação de vários threads dentro de MFC DLLs, consulte o artigo da Base de dados de Conhecimento, "PRB: chamando LoadLibrary para carregar uma DLL que tem estático TLS" (Q118816). Para obter mais informações sobre variáveis de local de thread em DLLs, consulte [thread](../cpp/thread.md).
  
 Uma DLL MFC que cria um novo thread MFC durante a inicialização irá parar de responder quando ele é carregado por um aplicativo. Isso inclui sempre que um thread é criado chamando `AfxBeginThread` ou `CWinThread::CreateThread` dentro de:  
  
-   O `InitInstance` de um `CWinApp`-objeto em uma DLL MFC regular derivado.  
  
-   Um fornecido `DllMain` ou **RawDllMain** função em uma DLL MFC regular.  
  
-   Um fornecido `DllMain` ou **RawDllMain** função em uma DLL de extensão do MFC.  
  
 Para obter mais informações sobre a criação de threads durante a inicialização, consulte o artigo da Base de dados de Conhecimento, "PRB: não é possível criar um MFC Thread durante a inicialização DLL" (Q142243).  
  
## <a name="mfc_multithreaded_2"></a> Um aplicativo multithread pode acessar uma DLL MFC em threads diferentes?
Aplicativos multithread podem acessar a DLLs normais do MFC que vincular dinamicamente a MFC e DLLs de extensão do MFC de diversos threads. E a partir do Visual C++ versão 4.2, um aplicativo pode acessar a DLLs normais do MFC estaticamente vinculadas a MFC de vários threads criados no aplicativo.  
  
 Antes da versão 4.2, apenas um thread externo pode anexar a uma DLL MFC regular que estatisticamente vinculadas a MFC. Para obter mais informações sobre as restrições de acesso a DLLs normais do MFC estaticamente vinculadas a MFC de vários threads (antes do Visual C++ versão 4.2), consulte o artigo da Base de dados de Conhecimento, "vários Threads e MFC _USRDLLs" (Q122676).  
  
 Observe que o termo USRDLL não é usado na documentação do Visual C++. Uma DLL MFC regular que está estaticamente vinculada ao MFC tem as mesmas características que o antigo USRDLL.  


## <a name="mfc_prohibited_classes"></a> Existem classes MFC ou funções que não podem ser usadas em uma DLL MFC?
Uso de DLLs de extensão de `CWinApp`-derivado da classe do aplicativo cliente. Eles não devem ter seus próprios `CWinApp`-classe derivada.  
  
DLLs normais do MFC deve ter um `CWinApp`-derivado de classe e um único objeto dessa classe de aplicativo, como um aplicativo do MFC. Ao contrário de `CWinApp` objeto de um aplicativo, o `CWinApp` objeto da DLL não tem uma bomba de mensagem principal.  
  
 Observe que, como o `CWinApp::Run` mecanismo não se aplica a uma DLL, o aplicativo que detém a bomba de mensagem principal. Se a DLL abre caixas de diálogo sem janela restrita ou tem uma janela do quadro principal de seu próprio, bomba de mensagem principal do aplicativo deve chamar uma rotina exportada pela DLL, que por sua vez, chama o `CWinApp::PreTranslateMessage` a função de membro de objeto de aplicativo da DLL.  

## <a name="mfc_optimization"></a> As técnicas de otimização devo usar para aprimorar o aplicativo cliente&#39;desempenho s ao carregar?
Se a DLL é uma DLL MFC regular que está estaticamente vinculada ao MFC, alterá-la como um regular DLL do MFC que estão vinculados dinamicamente ao MFC reduz o tamanho do arquivo.  
  
 Se a DLL tiver um grande número de funções exportadas, use um arquivo. def para exportar as funções (em vez de usar **dllexport**) e usar o arquivo. def [atributo NONAME](../build/exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md) em cada função exportada. O atributo NONAME faz com que apenas o valor ordinal e não o nome da função a ser armazenado na tabela de exportação de DLL, que reduz o tamanho do arquivo.  
  
 DLLs que são implicitamente vinculadas a um aplicativo são carregados quando o aplicativo é carregado. Para melhorar o desempenho durante o carregamento, tente dividir o DLL em DLLs diferentes. Colocar todas as funções que o aplicativo de chamada precisa imediatamente após o carregamento em uma DLL e ter o aplicativo de chamada implicitamente vincular a essa DLL. Colocar as outras funções que o aplicativo de chamada não precisa imediatamente em outra DLL e ter o aplicativo vinculado de maneira explícita para essa DLL. Para obter mais informações, consulte [determinar qual método de associação usar](../build/linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use).  

## <a name="memory_leak"></a> Há&#39;s um vazamento de memória no meu DLL MFC regular, mas meu código parece correto. Como localizar o vazamento de memória?  
  
Uma possível causa da perda de memória é MFC cria objetos temporários que são usados dentro de funções de manipulador de mensagens. Em aplicativos MFC, esses objetos temporários são automaticamente limpos no `CWinApp::OnIdle()` função que é chamada entre o processamento de mensagens. No entanto, em bibliotecas de vínculo dinâmico (DLLs), do MFC de `OnIdle()` função não é chamada automaticamente. Como resultado, objetos temporários não forem automaticamente limpos. Para limpar os objetos temporários, a DLL deve chamar explicitamente `OnIdle(1)` periodicamente.  
  
## <a name="see-also"></a>Consulte também  
 [DLLs no Visual C++](../build/dlls-in-visual-cpp.md)