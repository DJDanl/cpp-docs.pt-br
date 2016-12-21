---
title: "Windows Sockets: usando classe CAsyncSocket | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CAsyncSocket"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CAsyncSocket, modelo de programação"
  - "Identificador SOCKET"
  - "soquetes [C++], operação assíncrona"
  - "soquetes [C++], convertendo entre cadeias de caracteres Unicode e MBCS"
  - "Windows Sockets [C++], assíncronos"
  - "Windows Sockets [C++], convertendo cadeias de caracteres Unicode e MBCS"
ms.assetid: 825dae17-7c1b-4b86-8d6c-da7f1afb5d8d
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Windows Sockets: usando classe CAsyncSocket
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica como usar a classe [CAsyncSocket](../Topic/CAsyncSocket%20Class.md).  Lembre\-se de que essa classe encapsula soquetes API do windows em um nível muito baixo.  `CAsyncSocket` é para uso dos programadores que conhecem comunicações de rede em detalhes mas desejar conveniência de retornos de chamada para a notificação de eventos de rede.  Com base nessa pressuposição, este artigo fornece apenas a instrução básica.  Você provavelmente deve considerar o uso de `CAsyncSocket` se você deseja a facilidade de soquetes do windows de lidar com vários protocolos de rede em um aplicativo de MFC mas não quiser sacrificar flexibilidade.  Você também pode sentir que você pode obter a melhor eficiência programando as comunicações mais diretamente você mesmo do que você pode usar o modelo de backup mais geral da classe `CSocket`.  
  
 `CAsyncSocket` é documentado na *referência de MFC*.  Visual C\+\+ também fornece a especificação de soquetes do windows, localizada em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  Os detalhes são\-lhe restantes.  Visual C\+\+ não fornece um aplicativo de exemplo para `CAsyncSocket`.  
  
 Se você não for altamente experiência em comunicações de rede e não quiser que uma solução simples, a classe [CSocket](../mfc/reference/csocket-class.md) de uso com um objeto de `CArchive` .  Consulte [Soquetes do windows: Usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md) para obter mais informações.  
  
 Este artigo abrange:  
  
-   Criando e usando um objeto de `CAsyncSocket` .  
  
-   [Suas responsabilidades com CAsyncSocket](#_core_your_responsibilities_with_casyncsocket).  
  
##  <a name="_core_creating_and_using_a_casyncsocket_object"></a> Criando e usando um objeto de CAsyncSocket  
  
#### Para usar CAsyncSocket  
  
1.  Construir um objeto de [CAsyncSocket](../Topic/CAsyncSocket%20Class.md) e use o objeto para criar o identificador de **SOCKET** subjacente.  
  
     A criação de um soquete segue o padrão de MFC de compilação de dois estágios.  
  
     Por exemplo:  
  
     [!CODE [NVC_MFCSimpleSocket#3](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCSimpleSocket#3)]  
  
     \- ou \-  
  
     [!CODE [NVC_MFCSimpleSocket#4](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCSimpleSocket#4)]  
  
     O primeiro construtor anterior cria um objeto de `CAsyncSocket` na pilha.  O segundo construtor cria `CAsyncSocket` no heap.  A primeira chamada de [Crie](../Topic/CAsyncSocket::Create.md) anterior usa os parâmetros padrão para criar um soquete de fluxo.  O segundo chamada de **Criar** cria um soquete de datagrama com uma porta e um endereço especificados. \(Você pode usar uma versão de **Criar** com qualquer método de criação.\)  
  
     Os parâmetros a **Criar** são:  
  
    -   Uma porta “”: um inteiro curto.  
  
         Para um soquete de servidor, você deve especificar uma porta.  Para um soquete de cliente, normalmente você aceita o valor padrão para esse parâmetro, que permite que o windows que os soquetes elas selecionam uma porta.  
  
    -   Um tipo de soquete: **SOCK\_STREAM** \(o padrão\) ou **SOCK\_DGRAM**.  
  
    -   Um soquete “endereço, como” ftp.microsoft.com” ou “128.56.22.8”.  
  
         Este é o endereço IP \(IP\) na rede.  Você provavelmente sempre confiará no valor padrão para este parâmetro.  
  
     Os termos “port” e “endereço de soquete” são explicados em [Soquetes do windows: Portas e endereço de soquete](../mfc/windows-sockets-ports-and-socket-addresses.md).  
  
2.  Se o soquete é um cliente, conecte o objeto de soquete a um soquete do servidor, usando [CAsyncSocket::Connect](../Topic/CAsyncSocket::Connect.md).  
  
     \- ou \-  
  
     Se o soquete é um servidor, defina o soquete para iniciar a escutar \(com [CAsyncSocket::Listen](../Topic/CAsyncSocket::Listen.md)\) para se conectam tentativas de um cliente.  Após o recebimento de uma solicitação de conexão, aceitar\-la com [CAsyncSocket::Accept](../Topic/CAsyncSocket::Accept.md).  
  
     Após aceito uma conexão, você pode executar tarefas como validando senhas.  
  
    > [!NOTE]
    >  A função de membro de **Aceitar** usa uma referência a um novo objeto vazio, de `CSocket` como o parâmetro.  Você deve construir esse objeto antes de chamar **Aceitar**.  Se esse objeto de soquete sair do escopo, a conexão é fechada.  Não chame **Criar** para esse novo objeto de soquete.  Para obter um exemplo, consulte o artigo [Soquetes do windows: Sequência de operações](../Topic/Windows%20Sockets:%20Sequence%20of%20Operations.md).  
  
3.  Realize comunicações com outros soquetes chamando as funções de membro do objeto de `CAsyncSocket` que encapsulam as funções de API de soquetes do windows.  
  
     Consulte os soquetes especificação do windows e a classe [CAsyncSocket](../Topic/CAsyncSocket%20Class.md)*na referência de MFC*.  
  
4.  Destruir o objeto de `CAsyncSocket` .  
  
     Se você criou o objeto de soquete na pilha, seu destruidor é chamado quando a função contentor sai do escopo.  Se você criou o objeto de soquete no heap, usando o operador de **new** , você é responsável para usar o operador de **delete** para destruir o objeto.  
  
     O destruidor chama a função de membro de [Término](../Topic/CAsyncSocket::Close.md) do objeto antes de destruir o objeto.  
  
 Para obter um exemplo dessa sequência em código \(realmente para um objeto de `CSocket` \), consulte [Soquetes do windows: Sequência de operações](../Topic/Windows%20Sockets:%20Sequence%20of%20Operations.md).  
  
##  <a name="_core_your_responsibilities_with_casyncsocket"></a> Suas responsabilidades com CAsyncSocket  
 Quando você cria um objeto da classe [CAsyncSocket](../Topic/CAsyncSocket%20Class.md), o objeto encapsula um identificador de **SOCKET** do windows e fornece operações naquele identificador.  Quando você usa `CAsyncSocket`, você deve tratar problemas que você poderá enfrentar usando a API diretamente.  Por exemplo:  
  
-   “Bloqueando” cenários.  
  
-   Diferenças de ordem de byte entre os computadores enviando e recebendo.  
  
-   Conversão entre Unicode e cadeias de caracteres do conjunto de caracteres multibyte \(MBCS\).  
  
 Para definições desses termos e de informações adicionais, consulte [Soquetes do windows: Bloqueio](../Topic/Windows%20Sockets:%20Blocking.md), [Soquetes do windows: A ordenação de bytes](../mfc/windows-sockets-byte-ordering.md), [Soquetes do windows: Convertendo cadeias de caracteres](../mfc/windows-sockets-converting-strings.md).  
  
 Independentemente desses problemas, a classe **CAsycnSocket** pode ser a opção direita para você se seu aplicativo exigir qualquer flexibilidade e controla\-o pode ser obtido.  Caso contrário, você deve considerar o uso da classe `CSocket` em vez disso.  `CSocket` oculta muito detalhes do: bombeia mensagens do windows durante chamadas de bloqueio e fornece acesso a `CArchive`, que gerencia diferenças de ordem de byte e conversão de cadeia de caracteres para você.  
  
 Para obter mais informações, consulte:  
  
-   [Soquetes do windows: Plano de fundo](../mfc/windows-sockets-background.md)  
  
-   [Soquetes do windows: Soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)  
  
-   [Soquetes do windows: Soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)  
  
## Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)