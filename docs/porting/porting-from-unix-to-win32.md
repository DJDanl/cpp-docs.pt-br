---
title: Portando de UNIX para Win32
ms.date: 08/02/2018
helpviewer_keywords:
- APIs [C++], porting to Win32
- Windows API [C++], migrating from UNIX
- migration [C++]
- UNIX [C++], porting to Win32
- porting to Win32 [C++], from UNIX
- porting to Win32 [C++]
- Win32 applications [C++], migrating from UNIX
ms.assetid: 3837e4fe-3f96-4f24-b2a1-7be94718a881
ms.openlocfilehash: 70cbff207931ada378a89b978acf13fadb3a8744
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51694082"
---
# <a name="porting-from-unix-to-win32"></a>Portando de UNIX para Win32

Ao migrar aplicativos do UNIX para o Windows, há várias opções:

- Usar bibliotecas UNIX para portar aplicativos do UNIX para Win32

- Portar aplicativos do UNIX para Win32 de maneira nativa

- Executar aplicativos UNIX no Windows usando o subsistema POSIX

## <a name="unix-libraries"></a>Bibliotecas UNIX

Uma opção que os programadores do UNIX geralmente consideram é usar bibliotecas semelhantes ao UNIX de terceiros para permitir que o código UNIX seja compilado como um executável Win32. Várias bibliotecas comerciais (e pelo menos uma de domínio público) fazem isso. É uma opção para alguns aplicativos. A vantagem dessas bibliotecas de portabilidade é que eles minimizam o esforço de portagem inicial. A principal desvantagem, para um produto de software concorrente, é que uma porta Win32 nativa de um aplicativo geralmente será mais rápida e, inevitavelmente, terá mais funcionalidade. Poderá ser estranho para o aplicativo sair do shell do UNIX se ele precisar fazer chamadas ao Win32 para obter mais potência do Windows.

A lista a seguir fornece recursos da Microsoft e de terceiros para portar e dar suporte à migração do UNIX para Visual C++:

### <a name="unix-migration-guides"></a>Guias de migração do UNIX

O [Guia de migração de aplicativos UNIX personalizados](https://technet.microsoft.com/library/bb656290.aspx) fornece ajuda técnica sobre migração de código do ambiente UNIX para o ambiente Win32.

O [Guia de projeto de migração do Unix](https://technet.microsoft.com/library/bb656287.aspx) complementa o Guia de migração de aplicativos UNIX personalizados oferecendo ajuda de alto nível sobre migração de projetos substanciais do Unix para Win32. O guia fornece conselhos sobre problemas a serem considerados em cada estágio da migração do projeto.

### <a name="microsoft-windows-services-for-unix-sfu"></a>Microsoft Windows SFU (Services for UNIX)

O Microsoft Windows SFU (Services for UNIX) oferece um amplo conjunto de serviços de plataforma cruzada para integrar o Windows a ambientes baseados no UNIX existentes. O Services for UNIX oferece compartilhamento de arquivos, administração e acesso remotos, sincronização de senha, gerenciamento comum de diretórios, um conjunto comum de utilitários e um shell.

[Windows Services for UNIX](http://www.microsoft.com/downloads/details.aspx?FamilyID=896c9688-601b-44f1-81a4-02878ff11778&displaylang=en)

### <a name="interopsystemscom"></a>InteropSystems.com

[http://www.interopsystems.com/](http://www.interopsystems.com/)

Um site de terceiros de uma empresa que oferece software que dá suporte à portabilidade do UNIX para Win32.

### <a name="c-boost-web-site"></a>Site da Web do Boost do C++

[http://boost.sourceforge.net/regression-logs/](http://boost.sourceforge.net/regression-logs/)

[http://boost.sourceforge.net/boost-build2/](http://boost.sourceforge.net/boost-build2/)

## <a name="porting-unix-applications-directly-to-win32"></a>Portando aplicativos UNIX diretamente para Win32

Outra opção é portar aplicativos UNIX diretamente para Win32. Usando bibliotecas ANSI C/C++ e bibliotecas comerciais do compilador C, muitas chamadas de sistema tradicional que dependiam de aplicativos UNIX estão disponíveis em aplicativos Win32.

O modelo de saída de aplicativos baseados em **stdio** não precisa ser alterado, pois as APIs de console do Win32 imitam o modelo **stdio** e as versões de *cursos* existentes que usam APIs de console doWin32. Para obter mais informações, consulte [SetConsoleCursorPosition](/windows/console/setconsolecursorposition).

Os aplicativos baseados em soquete Berkeley precisam de poucas alterações para funcionar como aplicativos Win32. A interface do Windows Sockets foi criada para oferecer portabilidade com soquetes BSD, com alterações mínimas observadas nas seções introdutórias da especificação do WinSock.

O Windows dá suporte a RPC em conformidade com DCE, de modo que os aplicativos baseados em RPC são facilmente utilizáveis. Consulte [RPC Functions (Funções RPC)](/windows/desktop/Rpc/rpc-functions).

Uma das maiores áreas de diferença está no modelo de processo. O UNIX tem `fork`; o Win32, não. Dependendo do uso de `fork` e da base de código, o Win32 tem duas APIs que podem ser usadas: `CreateProcess` e `CreateThread`. Um aplicativo UNIX que bifurca várias cópias de si mesmo pode ser reformulado no Win32 para ter vários processos ou um único processo com vários threads. Se vários processos são usados, há vários métodos de IPC que podem ser usados para comunicação entre os processos (e talvez para atualizar o código e os dados do novo processo para que eles sejam como o pai, se a funcionalidade que `fork` fornece for necessária). Para obter mais informações sobre IPC, consulte [Interprocess Communications (Comunicações entre processos)](/windows/desktop/ipc/interprocess-communications).

Os modelos gráficos do Windows e do UNIX são muito diferentes. O UNIX usa o GUI do Sistema X Window, enquanto o Windows usa o GDI. Embora sejam semelhantes no conceito, não há mapeamento simples da API do X para a API do GDI. No entanto, o suporte OpenGL está disponível para migrar aplicativos UNIX baseados em OpenGL. E há clientes e servidores do X para Windows. Consulte [Contextos de dispositivo](/windows/desktop/gdi/device-contexts) para obter informações sobre GDI.

Os aplicativos UNIX básicos, incluindo muitos aplicativos CGI, devem ser portados facilmente para Visual C++ em execução no Windows. Funções como `open`, `fopen`, `read`, `write` e outras estão disponíveis na biblioteca em tempo de execução do Visual C++. Além disso, há um mapeamento individual entre as APIs de C UNIX e as APIs do Win32: `open` para `CreateFile`, `read` para `ReadFile`, `write` para `WriteFile`, `ioctl` para `DeviceIOControl`, `close` para `CloseFile` e assim por diante.

## <a name="windows-posix-subsystem"></a>Subsistema POSIX do Windows

Outra opção que os programadores do UNIX procuram é o subsistema POSIX do Windows. No entanto, ele dá suporte apenas ao POSIX 1003.1, que era a única versão padronizada do POSIX quando o Windows NT foi criado. Desde então, houve pouca demanda para estender esse subsistema, porque a maioria dos aplicativos foram convertidos em Win32. O sistema 1003.1 é de interesse limitado para aplicativos completos, pois ele não inclui muitos recursos (como os do 1003.2, suporte de rede e assim por diante). Aplicativos completos executados no subsistema POSIX do Windows não têm acesso a recursos do Windows disponíveis para aplicativos Win32, como arquivos mapeados na memória, rede e gráficos. Aplicativos como VI, LS e GREP são os principais destinos do subsistema POSIX do Windows.

## <a name="see-also"></a>Consulte também

[Guia de atualização e portabilidade do Visual C++](visual-cpp-change-history-2003-2015.md)<br/>
[UNIX](../c-runtime-library/unix.md)<br/>
[Regras de inferência](../build/inference-rules.md)