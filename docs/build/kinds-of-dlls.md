---
title: Tipos de DLLs
ms.date: 05/06/2019
helpviewer_keywords:
- MFC DLLs [C++], types
- DLLs [C++], types
- DLLs [C++], MFC
ms.assetid: f6a30db9-6138-4b2c-90cc-a17855e499a6
ms.openlocfilehash: dae44d2dd39597420ce2a2c4e1642e8a7f0784e2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328494"
---
# <a name="kinds-of-dlls"></a>Tipos de DLLs

Este tópico fornece informações para ajudá-lo a determinar o tipo de DLL a ser compilado.

## <a name="different-kinds-of-dlls-available"></a><a name="_core_the_different_kinds_of_dlls_available_with_visual_c.2b2b"></a>Tipos diferentes de DLLs disponíveis

Usando o Visual Studio, você pode criar DLLs do Win32 em C ou C++ que não usam a biblioteca do Microsoft Foundation Class (MFC). Você pode criar um projeto de DLL não MFC com o assistente de aplicativo Win32.

A própria biblioteca do MFC está disponível, em bibliotecas de link estático ou em várias DLLs, com o assistente de DLL do MFC. Se sua DLL estiver usando o MFC, o Visual Studio dará suporte a três cenários de desenvolvimento de DLL diferentes:

- Criando uma DLL do MFC regular que vincula estaticamente o MFC

- Criando uma DLL do MFC regular que vincula dinamicamente o MFC

- Criando uma DLL de extensão do MFC, que sempre vincula dinamicamente o MFC

### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [DLLs que não sejam MFC: visão geral](non-mfc-dlls-overview.md)

- [DLLs MFC regulares vinculadas estaticamente ao MFC](regular-dlls-statically-linked-to-mfc.md)

- [DLLs MFC regulares vinculadas dinamicamente ao MFC](regular-dlls-dynamically-linked-to-mfc.md)

- [DLLs de extensão do MFC: visão geral](extension-dlls-overview.md)

- [Qual tipo de DLL usar](#_core_which_kind_of_dll_to_use)

## <a name="deciding-which-kind-of-dll-to-use"></a><a name="_core_which_kind_of_dll_to_use"></a>Decidindo qual tipo de DLL usar

Se a DLL não usar o MFC, use o Visual Studio para criar uma DLL do Win32 não MFC. Vincular sua DLL ao MFC (estática ou dinamicamente) ocupa espaço em disco e memória significativos. Você não deve vincular ao MFC, a menos que sua DLL realmente use o MFC.

Se sua DLL usar o MFC e será usada por aplicativos MFC ou não MFC, você deverá criar uma DLL do MFC regular que vincule dinamicamente ao MFC ou a uma DLL do MFC regular que seja vinculada estaticamente ao MFC. Na maioria dos casos, você provavelmente desejará usar uma DLL do MFC regular que é vinculada dinamicamente ao MFC porque o tamanho do arquivo da DLL será muito menor e a economia na memória usando a versão compartilhada do MFC pode ser significativa. Se você vincular estaticamente ao MFC, o tamanho do arquivo da sua DLL será maior e potencialmente ocupará memória extra, pois ele carrega sua própria cópia privada do código da biblioteca do MFC.

A criação de uma DLL que vincula dinamicamente ao MFC é mais rápida do que a criação de uma DLL que se vincula estaticamente ao MFC porque não é necessário vincular o próprio MFC. Isso é especialmente verdadeiro em compilações de depuração em que o vinculador deve compactar as informações de depuração. Ao vincular com uma DLL que já contém as informações de depuração, há menos informações de depuração para compactar em sua DLL.

Uma desvantagem de vincular dinamicamente ao MFC é que você deve distribuir as DLLs compartilhadas MFCx0. dll e Msvcrxx. dll (ou arquivos semelhantes) com sua DLL. As DLLs do MFC são redistribuíveis livremente, mas você ainda deve instalar as DLLs em seu programa de instalação. Além disso, você deve enviar o Msvcrxx. dll, que contém a biblioteca de tempo de execução C, que é usada pelo seu programa e pelas próprias DLLs do MFC.

Se sua DLL for usada apenas por executáveis do MFC, você terá a opção de criar uma DLL do MFC regular ou uma DLL de extensão do MFC. Se sua DLL implementar classes reutilizáveis derivadas das classes existentes do MFC ou se você precisar passar objetos derivados do MFC entre o aplicativo e a DLL, deverá criar uma DLL de extensão do MFC.

Se a DLL for vinculada dinamicamente ao MFC, as DLLs do MFC poderão ser redistribuídas com sua DLL. Essa arquitetura é particularmente útil para compartilhar a biblioteca de classes entre vários arquivos executáveis para economizar espaço em disco e minimizar o uso de memória.

### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [DLLs que não sejam MFC: visão geral](non-mfc-dlls-overview.md)

- [DLLs MFC regulares vinculadas estaticamente ao MFC](regular-dlls-statically-linked-to-mfc.md)

- [DLLs MFC regulares vinculadas dinamicamente ao MFC](regular-dlls-dynamically-linked-to-mfc.md)

- [DLLs de extensão do MFC: visão geral](extension-dlls-overview.md)

## <a name="see-also"></a>Confira também

[Criar DLLs C /C++ no Visual Studio](dlls-in-visual-cpp.md)
