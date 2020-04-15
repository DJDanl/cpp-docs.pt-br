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

Este tópico fornece informações para ajudá-lo a determinar o tipo de DLL a ser construído.

## <a name="different-kinds-of-dlls-available"></a><a name="_core_the_different_kinds_of_dlls_available_with_visual_c.2b2b"></a>Diferentes tipos de DLLs disponíveis

Usando o Visual Studio, você pode construir DLLs Win32 em C ou C++ que não usam a biblioteca Microsoft Foundation Class (MFC). Você pode criar um projeto dll não-MFC com o Assistente de Aplicativo Win32.

A biblioteca MFC em si está disponível, em bibliotecas de links estáticos ou em vários DLLs, com o MFC DLL Wizard. Se o seu DLL estiver usando o MFC, o Visual Studio suporta três cenários diferentes de desenvolvimento de DLL:

- Construindo um DLL MFC regular que vincula estáticamente o MFC

- Construindo um DLL MFC regular que vincula dinamicamente o MFC

- Construindo uma dll de extensão MFC, que sempre vincula dinamicamente mfc

### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [DLLs que não sejam MFC: visão geral](non-mfc-dlls-overview.md)

- [DLLs MFC regulares vinculadas estaticamente ao MFC](regular-dlls-statically-linked-to-mfc.md)

- [DLLs MFC regulares vinculadas dinamicamente ao MFC](regular-dlls-dynamically-linked-to-mfc.md)

- [DLLs de extensão do MFC: visão geral](extension-dlls-overview.md)

- [Que tipo de DLL usar](#_core_which_kind_of_dll_to_use)

## <a name="deciding-which-kind-of-dll-to-use"></a><a name="_core_which_kind_of_dll_to_use"></a>Decidindo que tipo de DLL usar

Se o seu DLL não usar O MFC, use o Visual Studio para construir um DLL Win32 não-MFC. Ligar sua DLL ao MFC (estáticamente ou dinamicamente) ocupa espaço e memória de disco significativos. Você não deve vincular ao MFC a menos que seu DLL realmente use MFC.

Se o seu DLL estiver usando MFC e será usado por aplicativos MFC ou não-MFC, você deve criar um DLL MFC regular que se vincula dinamicamente ao MFC ou a um DLL MFC regular que se vincula estáticamente ao MFC. Na maioria dos casos, você provavelmente deseja usar uma DLL MFC regular que se vincula dinamicamente ao MFC porque o tamanho do arquivo da DLL será muito menor e a economia na memória de usar a versão compartilhada do MFC pode ser significativa. Se você se vincular estáticamente ao MFC, o tamanho do arquivo da sua DLL será maior e potencialmente terá memória extra porque ele carrega sua própria cópia privada do código da biblioteca Do MFC.

A construção de uma DLL que se conecta dinamicamente ao MFC é mais rápida do que construir uma DLL que se vincula estáticamente ao MFC porque não é necessário vincular o próprio MFC. Isso é especialmente verdadeiro em compilações de depuração onde o linker deve compactar as informações de depuração. Ao vincular-se a uma DLL que já contém as informações de depuração, há menos informações de depuração para compactar dentro de sua DLL.

Uma desvantagem em vincular dinamicamente ao MFC é que você deve distribuir os DLLs compartilhados Mfcx0.dll e Msvcrxx.dll (ou arquivos semelhantes) com o seu DLL. Os DLLs do MFC são livremente rediputáveis, mas você ainda deve instalar os DLLs em seu programa de configuração. Além disso, você deve enviar o Msvcrxx.dll, que contém a biblioteca de tempo de execução C que é usada tanto pelo seu programa quanto pelos próprios DLLs do MFC.

Se o seu DLL será usado apenas por executáveis MFC, você tem uma escolha entre construir uma DLL MFC regular ou uma DLL de extensão MFC. Se a DLL implementar classes reutilizáveis derivadas das classes MFC existentes ou você precisar passar objetos derivados de MFC entre o aplicativo e o DLL, você deve construir uma DLL de extensão MFC.

Se a DLL se vincula dinamicamente ao MFC, as DLLs do MFC podem ser redistribuídas com o dll. Esta arquitetura é particularmente útil para compartilhar a biblioteca de classes entre vários arquivos executáveis para economizar espaço em disco e minimizar o uso da memória.

### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [DLLs que não sejam MFC: visão geral](non-mfc-dlls-overview.md)

- [DLLs MFC regulares vinculadas estaticamente ao MFC](regular-dlls-statically-linked-to-mfc.md)

- [DLLs MFC regulares vinculadas dinamicamente ao MFC](regular-dlls-dynamically-linked-to-mfc.md)

- [DLLs de extensão do MFC: visão geral](extension-dlls-overview.md)

## <a name="see-also"></a>Confira também

[Criar DLLs C /C++ no Visual Studio](dlls-in-visual-cpp.md)
