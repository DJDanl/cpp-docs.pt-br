---
title: Aplicativos de desktop (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: a020b534-293c-44e2-aa48-516c43ddeb8f
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f9c8180288374711db4e6d866c73a0bc8919caf2
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="desktop-applications-visual-c"></a>Aplicativos de desktop (Visual C++)
Um *aplicativo de desktop* em C++ é um aplicativo nativo que pode acessar o conjunto completo de APIs do Windows e o executa em uma janela ou no console do sistema. Aplicativos de área de trabalho em C++ podem ser executados no Windows XP por meio do Windows 10 (embora oficialmente não há suporte para o Windows XP e há muitas APIs do Windows que foram introduzidos desde então).   Um aplicativo de área de trabalho é diferente de um aplicativo do Windows UWP (plataforma Universal), que pode ser executado em computadores que executam o Windows 10 e também no XBox, Windows Phone, Surface Hub e outros dispositivos. Para obter mais informações sobre a área de trabalho vs. Aplicativos UWP, consulte [escolha sua tecnologia](https://msdn.microsoft.com/en-us/library/windows/desktop/dn614993\(v=vs.85\).aspx).  
  
 **Terminologia**  
  
-   Um *Win32* aplicativo é um aplicativo de desktop em C++ que pode fazer uso de nativo do Windows [APIs de C do Windows e/ou APIs COM](https://msdn.microsoft.com/en-us/library/windows/desktop/ff818516\(v=vs.85\).aspx) CRT e APIs da biblioteca padrão e 3º bibliotecas de terceiros. Um aplicativo Win32 que é executado em uma janela requer o desenvolvedor explicitamente trabalhar com mensagens do Windows dentro de uma função de procedimento do Windows. Apesar do nome, um aplicativo Win32 pode ser compilado como um (x86) 32 bits ou 64 bits (x64) binário. No IDE do Visual Studio, os termos x86 e Win32 são sinônimos.  
  
-   O [modelo COM (Component Object)](https://msdn.microsoft.com/en-us/library/windows/desktop/ms694363\(v=vs.85\).aspx) é uma especificação que permite que os programas escritos em linguagens diferentes para se comunicar uns com os outros. Destruição de descoberta e o objeto da interface do Windows muitos componentes são implementados como objetos COM e seguem as regras COM padrões para a criação do objeto.  Usar objetos de aplicativos de desktop do C++ é relativamente simples, mas gravar seu próprio objeto COM é mais avançada. O [biblioteca ATL (Active Template)](../atl/atl-com-desktop-components.md) fornece macros e funções auxiliares que simplificam o desenvolvimento de COM.  
  
-   Um aplicativo MFC é um aplicativo de área de trabalho do Windows que usam o [Microsoft Foundation Classes](../mfc/mfc-desktop-applications.md) para criar a interface do usuário. Um aplicativo MFC também pode usar componentes COM, bem como CRT e APIs da biblioteca padrão. MFC fornece um wrapper fino de orientada a objeto C++ sobre o loop de mensagem de janela e APIs do Windows. MFC é a opção padrão para aplicativos, especialmente aplicativos de tipo de empresa — que têm vários controles de interface de usuário ou controles de usuário personalizada. MFC fornece classes auxiliares conveniente para gerenciamento de janela, serialização, manipulação de texto, impressão e elementos de interface de usuário moderna, como a faixa de opções. Para ser eficaz com MFC, você deve estar familiarizado com o Win32.  
  
-   C + + CLI aplicativo ou componente usa extensões de sintaxe de C++ (como permitido pela especificação de C++) para habilitar a interação entre o .NET e o código C++ nativo.  C + + aplicativo CLI pode ter partes que executam nativamente e partes que são executados no .NET Framework, com acesso à biblioteca de classe Base do .NET. C + + CLI é a opção preferencial quando você tem o código C++ nativo que precisa para trabalhar com o código escrito em c# ou Visual Basic. Ele é usado principalmente para uso em DLLs de .NET em vez de código de interface do usuário. Para obter mais informações, consulte [programação .NET com C + + CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).  
  
 Qualquer aplicativo de área de trabalho em C++ pode usar classes de tempo de execução do C (CRT) e a biblioteca padrão e funções, objetos e as funções públicas do Windows, que são conhecidas coletivamente como a API do Windows. Para obter uma introdução a aplicativos de área de trabalho do Windows em C++, consulte [saiba de programa do Windows em C++](http://go.microsoft.com/fwlink/p/?LinkId=262281).  
  
## <a name="in-this-section"></a>Nesta seção  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Aplicativos de console](../windows/console-applications-in-visual-cpp.md)|Contém informações sobre os aplicativos de console. Um aplicativo do console Win32 (ou Win64) tem sem sua própria janela e nenhum loop de mensagem. Ele é executado na janela do console e entrada e saída são manipuladas pela linha de comando.|  
|[Aplicativos de área de trabalho do Windows](../windows/windows-desktop-applications-cpp.md)|Como criar aplicativos de desktop que executam o windows em vez do console.|  
|[Recursos para criar um jogo usando DirectX (C++)](../windows/resources-for-creating-a-game-using-directx.md)|Links para conteúdo para a criação de jogos em C++.|  
|[Passo a passo: Criando e usando uma biblioteca estática](../windows/walkthrough-creating-and-using-a-static-library-cpp.md)|Como criar um arquivo binário.|  
|[Como usar o SDK do Windows 10 em um aplicativo da área de trabalho do Windows](../windows/how-to-use-the-windows-10-sdk-in-a-windows-desktop-application.md)|Contém as etapas para configurar seu projeto compilar usando o SDK do Windows 10.|  
  
## <a name="related-articles"></a>Artigos relacionados  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Desenvolvimento em Windows](http://go.microsoft.com/fwlink/p/?LinkId=262282)|Contém informações sobre a API do Windows e COM. (Algumas APIs do Windows e DLLs de terceiros são implementadas como objetos COM.)|  
|[Hilo: Desenvolvendo aplicativos do C++ para Windows 7](http://go.microsoft.com/fwlink/p/?LinkId=262284)|Descreve como criar um aplicativo de desktop Windows cliente avançado que usa Windows animação e Direct2D para criar uma interface de usuário baseada em carrossel.  Este tutorial não foi atualizado desde o Windows 7, mas ainda fornece uma introdução detalhada à programação do Win32.|  
|[Visual C++](../visual-cpp-in-visual-studio.md)|Descreve os principais recursos do Visual C++ no Visual Studio e links para o restante da documentação do Visual C++.|  
  
## <a name="see-also"></a>Consulte também  
 [Visual C++](../visual-cpp-in-visual-studio.md)
