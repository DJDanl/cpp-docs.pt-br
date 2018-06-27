---
title: 'Windows Sockets: Usando classe CAsyncSocket | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CAsyncSocket
dev_langs:
- C++
helpviewer_keywords:
- CAsyncSocket class [MFC], programming model
- Windows Sockets [MFC], asynchronous
- sockets [MFC], converting between Unicode and MBCS strings
- SOCKET handle
- sockets [MFC], asynchronous operation
- Windows Sockets [MFC], converting Unicode and MBCS strings
ms.assetid: 825dae17-7c1b-4b86-8d6c-da7f1afb5d8d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: dc461a0a2325f768711f6d7529949ee24a1b4a25
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36954878"
---
# <a name="windows-sockets-using-class-casyncsocket"></a>Windows Sockets: usando classe CAsyncSocket
Este artigo explica como usar a classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md). Lembre-se de que esta classe encapsula a API do Windows Sockets em um nível muito baixo. `CAsyncSocket` é para uso por programadores que saber em detalhes as comunicações de rede, mas deseja a conveniência de retornos de chamada de notificação de eventos de rede. Com base nesta suposição, este artigo fornece apenas a instrução básica. Provavelmente você deve considerar o uso `CAsyncSocket` se você deseja facilidade de Windows Sockets de lidar com vários protocolos de rede em um aplicativo MFC, mas não desejar sacrificar a flexibilidade. Você também pode achar que você pode obter o melhor eficiência por programação as comunicações mais diretamente a você mesmo que você poderia usando o modelo de alternativo mais geral da classe `CSocket`.  
  
 `CAsyncSocket` está documentado no *referência MFC*. Visual C++ também fornece a especificação de Windows Sockets, localizada no SDK do Windows. Os detalhes são deixados para você. Visual C++ não fornece um aplicativo de exemplo para `CAsyncSocket`.  
  
 Se você não é altamente conhecimentos sobre comunicações de rede e quer uma solução simple, use a classe [CSocket](../mfc/reference/csocket-class.md) com um `CArchive` objeto. Consulte [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md) para obter mais informações.  
  
 Este artigo aborda:  
  
-   Criando e usando um `CAsyncSocket` objeto.  
  
-   [Suas responsabilidades com CAsyncSocket](#_core_your_responsibilities_with_casyncsocket).  
  
##  <a name="_core_creating_and_using_a_casyncsocket_object"></a> Criando e usando um objeto CAsyncSocket  
  
#### <a name="to-use-casyncsocket"></a>Para usar CAsyncSocket  
  
1.  Construir um [CAsyncSocket](../mfc/reference/casyncsocket-class.md) de objeto e usar o objeto para criar subjacente **soquete** tratar.  
  
     Criação de um soquete segue o padrão do MFC de construção de dois estágios.  
  
     Por exemplo:  
  
     [!code-cpp[NVC_MFCSimpleSocket#3](../mfc/codesnippet/cpp/windows-sockets-using-class-casyncsocket_1.cpp)]  
  
     -ou-  
  
     [!code-cpp[NVC_MFCSimpleSocket#4](../mfc/codesnippet/cpp/windows-sockets-using-class-casyncsocket_2.cpp)]  
  
     O primeiro construtor acima cria um `CAsyncSocket` objeto na pilha. O segundo construtor cria um `CAsyncSocket` no heap. A primeira [criar](../mfc/reference/casyncsocket-class.md#create) chamada acima usa os parâmetros padrão para criar um soquete de fluxo. O segundo `Create` chamada cria um soquete de datagrama com uma porta especificada e o endereço. (Você pode usar o `Create` versão com qualquer um dos métodos de construção.)  
  
     Os parâmetros para `Create` são:  
  
    -   Uma "porta": um inteiro curto.  
  
         Para um soquete de servidor, você deve especificar uma porta. Para um soquete do cliente, normalmente você aceitar o valor padrão para esse parâmetro, o que permite que o Windows Sockets selecione uma porta.  
  
    -   Um tipo de soquete: **SOCK_STREAM** (o padrão) ou **SOCK_DGRAM**.  
  
    -   Um soquete "address" como "ftp.microsoft.com" ou "128.56.22.8".  
  
         Este é seu endereço de IP (Internet Protocol) na rede. Você provavelmente sempre irá contar com o valor padrão para esse parâmetro.  
  
     Os termos "port" e "endereço de soquete" é explicado em [Windows Sockets: portas e endereços de soquete](../mfc/windows-sockets-ports-and-socket-addresses.md).  
  
2.  Se o soquete é um cliente, conecte-se o objeto de soquete em um servidor de soquete, usando [CAsyncSocket::Connect](../mfc/reference/casyncsocket-class.md#connect).  
  
     -ou-  
  
     Se o soquete é um servidor, defina o soquete para começar a escutar (com [CAsyncSocket::Listen](../mfc/reference/casyncsocket-class.md#listen)) para as tentativas de conexão de um cliente. Ao receber uma solicitação de conexão, aceite-o com [CAsyncSocket::Accept](../mfc/reference/casyncsocket-class.md#accept).  
  
     Após aceitar uma conexão, você pode executar tarefas como: validando senhas.  
  
    > [!NOTE]
    >  O `Accept` função de membro usa uma referência a um novo e vazio `CSocket` objeto como seu parâmetro. Você deve construir esse objeto antes de chamar `Accept`. Se esse objeto de soquete sai do escopo, a conexão será fechada. Não chame `Create` para esse novo objeto de soquete. Para obter um exemplo, consulte o artigo [Windows Sockets: sequência de operações](../mfc/windows-sockets-sequence-of-operations.md).  
  
3.  Executar comunicações com outros soquetes chamando o `CAsyncSocket` funções de membro do objeto que encapsula as funções de API do Windows Sockets.  
  
     Consulte a especificação de Windows Sockets e classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md) no *referência MFC*.  
  
4.  Destruir a `CAsyncSocket` objeto.  
  
     Se você criou o objeto de soquete na pilha, seu destruidor é chamado quando a função contendo sai do escopo. Se você criou o objeto de soquete no heap, usando o **novo** operador, você é responsável por usando o **excluir** operador para destruir o objeto.  
  
     O destrutor chama o objeto [fechar](../mfc/reference/casyncsocket-class.md#close) função de membro antes de destruir o objeto.  
  
 Para obter um exemplo dessa sequência no código (na verdade, para um `CSocket` objeto), consulte [Windows Sockets: sequência de operações](../mfc/windows-sockets-sequence-of-operations.md).  
  
##  <a name="_core_your_responsibilities_with_casyncsocket"></a> Suas responsabilidades com CAsyncSocket  
 Quando você cria um objeto da classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md), o objeto encapsula um Windows **soquete** tratar e fornece operações nesse identificador. Quando você usa `CAsyncSocket`, você deve lidar com todos os problemas que você poderá enfrentar se usando a API diretamente. Por exemplo:  
  
-   Cenários de "Bloqueio".  
  
-   Diferenças de ordem de byte entre o envio e recebimento de máquinas.  
  
-   Converter entre caracteres multibyte e Unicode defina cadeias de caracteres (MBCS).  
  
 Para obter definições desses termos e informações adicionais, consulte [Windows Sockets: bloqueando](../mfc/windows-sockets-blocking.md), [Windows Sockets: ordenação de bytes](../mfc/windows-sockets-byte-ordering.md), [Windows Sockets: Convertendo cadeias de caracteres](../mfc/windows-sockets-converting-strings.md) .  
  
 Apesar desses problemas, classe `CAsycnSocket` pode ser a escolha certa para você, se seu aplicativo requer que toda a flexibilidade e controle, você pode obter. Se não, você deve considerar o uso de classe `CSocket` em vez disso. `CSocket` oculta muitos detalhes de você: it bombas Windows mensagens durante chamadas de bloqueio e lhe dá acessem a `CArchive`, que gerencia as diferenças de ordem de byte e conversão de cadeia de caracteres para você.  
  
 Para obter mais informações, consulte:  
  
-   [Windows Sockets: tela de fundo](../mfc/windows-sockets-background.md)  
  
-   [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)  
  
-   [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)  
  
## <a name="see-also"></a>Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)

