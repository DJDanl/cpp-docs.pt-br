---
title: Tipos de DLLs
ms.date: 11/04/2016
helpviewer_keywords:
- MFC DLLs [C++], types
- DLLs [C++], types
- DLLs [C++], MFC
ms.assetid: f6a30db9-6138-4b2c-90cc-a17855e499a6
ms.openlocfilehash: daf042f742a9c4b7757813fc73eeb4b6d1a87413
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50441113"
---
# <a name="kinds-of-dlls"></a>Tipos de DLLs

Este tópico fornece informações para ajudá-lo a determinar o tipo de DLL a ser compilada.

##  <a name="_core_the_different_kinds_of_dlls_available_with_visual_c.2b2b"></a> Diferentes tipos de DLLs disponíveis

Usando o Visual C++, você pode compilar DLLs Win32 em C ou C++ que não usam a biblioteca Microsoft Foundation Class (MFC). Você pode criar um projeto de DLL não MFC com o Assistente de aplicativo Win32.

A própria biblioteca do MFC está disponível, em bibliotecas de vínculo estático ou em um número de DLLs, com o Assistente de DLL do MFC. Se a sua DLL estiver usando o MFC, o Visual C++ dá suporte a três diferentes cenários de desenvolvimento de DLL:

- Compilando uma DLL MFC regular que estaticamente vincula MFC

- Compilando uma DLL MFC regular que dinamicamente vincula MFC

- Criando uma DLL de extensão do MFC, que sempre vinculam dinamicamente o MFC

### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [DLLs não MFC: visão geral](../build/non-mfc-dlls-overview.md)

- [DLLs MFC regulares vinculadas estaticamente ao MFC](../build/regular-dlls-statically-linked-to-mfc.md)

- [DLLs MFC regulares vinculadas dinamicamente ao MFC](../build/regular-dlls-dynamically-linked-to-mfc.md)

- [DLLs de extensão do MFC: visão geral](../build/extension-dlls-overview.md)

- [Que tipo de DLL usar](#_core_which_kind_of_dll_to_use)

##  <a name="_core_which_kind_of_dll_to_use"></a> Decidindo que tipo de DLL usar

Se a sua DLL não usa o MFC, use o Visual C++ para compilar uma DLL não MFC Win32. Vincular seu DLL ao MFC (estaticamente ou dinamicamente) ocupa espaço significativo em disco e de memória. Você não deve vincular ao MFC, a menos que a DLL realmente use MFC.

Se sua DLL for usar o MFC e será usado por aplicativos MFC ou não MFC, você deve criar uma DLL MFC regular que vincula dinamicamente ao MFC ou uma DLL MFC regular que vincula estaticamente ao MFC. Na maioria dos casos, você provavelmente desejará usar uma DLL MFC regular que vincula dinamicamente ao MFC, porque o tamanho do arquivo da DLL será muito menor e a economia na memória do uso da versão compartilhada de MFC poderá ser significativa. Se você vincular estaticamente ao MFC, o tamanho do arquivo da DLL será maior e potencialmente ocupam memória extra porque ela carrega sua própria cópia particular do código da biblioteca MFC.

Compilar uma DLL que vincula dinamicamente ao MFC é mais rápido que compilar uma DLL que vincula estaticamente ao MFC, porque ele não é necessário vincular o próprio MFC. Isso é especialmente verdadeiro em compilações de depuração em que o vinculador deverá compactar as informações de depuração. Por meio da vinculação com uma DLL que já contém as informações de depuração, há menos informações de depuração para compactar dentro da DLL.

Uma desvantagem de vincular dinamicamente ao MFC é que você deve distribuir as DLLs compartilhadas Mfcx0.dll e msvcrxx (ou arquivos semelhantes) com sua DLL. As DLLs do MFC são livremente redistribuíveis, mas você ainda deve instalar as DLLs no seu programa de instalação. Além disso, você deve enviar o msvcrxx, que contém a biblioteca de tempo de execução C que é usada pelo seu programa e as próprias DLLs MFC.

Se sua DLL for usado somente por executáveis MFC, você tem de escolher entre criar uma DLL MFC regular ou uma DLL de extensão do MFC. Se sua DLL implementa classes reutilizáveis derivadas das classes existentes do MFC ou se você precisar passar objetos derivados do MFC entre o aplicativo e a DLL, você deve criar uma DLL de extensão do MFC.

Se a sua DLL se vincula dinamicamente ao MFC, as DLLs do MFC podem ser redistribuídas com sua DLL. Essa arquitetura é particularmente útil para o compartilhamento de biblioteca de classes entre vários arquivos executáveis para economizar espaço em disco e minimizar o uso de memória.

Antes da versão 4.0, os tipos de Visual C++ suporte apenas para dois de DLLs que usavam o MFC: USRDLLs e AFXDLLs. DLLs MFC regulares vinculadas estaticamente ao MFC têm as mesmas características da antiga usrdll. DLLs de extensão MFC têm as mesmas características que o AFXDLLs antigo.

### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [DLLs não MFC: visão geral](../build/non-mfc-dlls-overview.md)

- [DLLs MFC regulares vinculadas estaticamente ao MFC](../build/regular-dlls-statically-linked-to-mfc.md)

- [DLLs MFC regulares vinculadas dinamicamente ao MFC](../build/regular-dlls-dynamically-linked-to-mfc.md)

- [DLLs de extensão do MFC: visão geral](../build/extension-dlls-overview.md)

## <a name="see-also"></a>Consulte também

[DLLs no Visual C++](../build/dlls-in-visual-cpp.md)