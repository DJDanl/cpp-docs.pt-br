---
title: "Noções básicas sobre as dependências de um aplicativo Visual C++ | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
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
caps.latest.revision: "20"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 64b7974b16767d226df5e71e7f3ae0e61514ed37
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="understanding-the-dependencies-of-a-visual-c-application"></a>Noções básicas sobre as dependências de um aplicativo do Visual C++
Para determinar quais bibliotecas do Visual C++ depende de um aplicativo, você pode exibir as propriedades do projeto. (No Gerenciador de soluções, clique com botão direito no projeto e escolha **propriedades** para abrir o **páginas de propriedade** caixa de diálogo.) Você também pode usar o Dependency Walker (depends.exe), que fornece um panorama mais abrangente das dependências.  
  
 No **páginas de propriedade** caixa de diálogo, você pode examinar várias páginas em **propriedades de configuração** para entender as dependências. Por exemplo, se seu projeto usa as bibliotecas MFC e você escolher **uso de MFC**, **Use MFC em uma DLL compartilhada** no **propriedades de configuração**, **geral**  página, seu aplicativo em tempo de execução depende MFC DLLs, como mfc\<versão >. dll. Se seu aplicativo não usar MFC, ele pode depender da biblioteca CRT se você escolher um **biblioteca de tempo de execução** valor **multi-threaded depurar DLL (/ MDd)** ou **multi-threaded DLL (/ MD)**no **propriedades de configuração**, **C/C++**, **geração de código** página.  
  
 É uma maneira mais abrangente para determinar quais DLLs depende de seu aplicativo usar dependência Walker (depends.exe) para abrir o aplicativo. Você pode baixar a ferramenta a partir de [dependência Walker](http://go.microsoft.com/fwlink/p/?LinkId=132640) site da web.  
  
 Usando depends.exe, você pode examinar uma lista de DLLs que são vinculados para o aplicativo em tempo de carregamento e uma lista de suas DLLs carregadas com atraso. Se você quiser obter uma lista completa das DLLs carregadas dinamicamente em tempo de execução, você pode usar o recurso de criação de perfil em depends.exe para testar o aplicativo até que você tiver certeza de que todos os caminhos de código tiveram sido exercidos. Quando você terminar a sessão de criação de perfil, depends.exe mostra quais DLLs foram carregados dinamicamente em tempo de execução.  
  
 Quando você usar o depends.exe, lembre-se de que uma DLL pode depender de outra DLL ou de uma versão específica de uma DLL. Você pode usar o depends.exe no computador de desenvolvimento ou em um computador de destino. No computador de desenvolvimento, o depends.exe relata as DLLs que são necessárias para oferecer suporte a um aplicativo. Se você tiver dificuldade para executar um aplicativo em um computador de destino, copie o depends.exe para ele e abra o aplicativo na ferramenta para que você possa determinar se alguma DLL necessária está ausente ou incorreta.  
  
 Quando você souber de quais DLLs seu aplicativo depende, poderá determinar quais precisam ser redistribuídas com seu aplicativo ao implantá-lo em outro computador. Na maioria dos casos, você não precisa redistribuir DLLs do sistema, mas talvez seja necessário redistribuir DLLs para bibliotecas do Visual C++. Para obter mais informações, consulte [determinando quais DLLs devem ser redistribuídas](../ide/determining-which-dlls-to-redistribute.md).  
  
## <a name="see-also"></a>Consulte também  
 [Implantando aplicativos de área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)