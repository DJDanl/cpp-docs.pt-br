---
title: Noções básicas sobre as dependências de um aplicativo do Visual C++
ms.date: 11/04/2016
helpviewer_keywords:
- application deployment [C++], dependencies
- Dependency Walker
- dependencies [C++], application deployment and
- deploying applications [C++], dependencies
- DUMPBIN utility
- DLLs [C++], dependencies
- depends.exe
- libraries [C++], application deployment issues
ms.assetid: 62a44c95-c389-4c5f-82fd-07d7ef09dbf9
ms.openlocfilehash: ed510e0d289349b1d7a0129a1c586b0bf1715b7e
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57751473"
---
# <a name="understanding-the-dependencies-of-a-visual-c-application"></a>Noções básicas sobre as dependências de um aplicativo do Visual C++

Para determinar de quais bibliotecas do Visual C++ um aplicativo depende, exiba as propriedades do projeto. (No Gerenciador de Soluções, clique com o botão direito do mouse no projeto e escolha **Propriedades** para abrir a caixa de diálogo **Páginas de Propriedades**.) Você também pode usar o Dependency Walker (depends.exe), que fornece um panorama mais abrangente das dependências.

Na caixa de diálogo **Páginas de Propriedades**, examine várias páginas em **Propriedades de Configuração** para entender as dependências. Por exemplo, se o projeto usar as bibliotecas MFC e você escolher **Uso do MFC**, **Usar MFC em uma DLL Compartilhada** na página **Propriedades de Configuração**, **Geral**, o aplicativo dependerá de DLLs do MFC, como mfc\<versão>.dll, em tempo de execução. Se o aplicativo não usar o MFC, ele poderá depender da biblioteca CRT, caso você escolha um valor da **Biblioteca em Tempo de Execução** de **DLL de Depuração Multi-threaded (/MDd)** ou **DLL Multi-threaded (/MD)** na página **Propriedades de Configuração**, **C/C++**, **Geração de Código**.

Um modo mais abrangente de determinar de quais DLLs o aplicativo depende é usar o Dependency Walker (depends.exe) para abrir o aplicativo. Baixe a ferramenta no site do [Dependency Walker](http://go.microsoft.com/fwlink/p/?LinkId=132640).

Usando depends.exe, você pode examinar uma lista de DLLs vinculadas ao aplicativo no tempo de carregamento e uma lista de suas DLLs carregadas com atraso. Caso deseje obter uma lista completa de DLLs carregadas dinamicamente em tempo de execução, use o recurso de criação de perfil em depends.exe para testar o aplicativo até ter certeza de que todos os caminhos de código foram usados. Quando você encerra a sessão de criação de perfil, depends.exe mostra quais DLLs foram carregadas dinamicamente durante o tempo de execução.

Quando você usar o depends.exe, lembre-se de que uma DLL pode depender de outra DLL ou de uma versão específica de uma DLL. Você pode usar o depends.exe no computador de desenvolvimento ou em um computador de destino. No computador de desenvolvimento, o depends.exe relata as DLLs que são necessárias para oferecer suporte a um aplicativo. Se você tiver dificuldade para executar um aplicativo em um computador de destino, copie o depends.exe para ele e abra o aplicativo na ferramenta para que você possa determinar se alguma DLL necessária está ausente ou incorreta.

Quando você souber de quais DLLs seu aplicativo depende, poderá determinar quais precisam ser redistribuídas com seu aplicativo ao implantá-lo em outro computador. Na maioria dos casos, não é necessário redistribuir DLLs do sistema, mas talvez seja necessário redistribuir DLLs para bibliotecas do Visual C++. Para obter mais informações, confira [Determinando quais DLLs devem ser redistribuídas](../ide/determining-which-dlls-to-redistribute.md).

## <a name="see-also"></a>Consulte também

[Implantando aplicativos da área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)
