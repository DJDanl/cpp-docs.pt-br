---
title: 'Recursos localizados em aplicativos MFC: DLLs satélites'
ms.date: 11/04/2016
helpviewer_keywords:
- multiple language support [C++]
- localization [C++], MFC resources
- localized resources [C++]
- MFC DLLs [C++], localizing
- DLLs [C++], localizing MFC
- resources [MFC], localizing
- resource-only DLLs [C++]
- resource-only DLLs [C++], MFC applications
- satellite DLLs [C++]
ms.assetid: 3a1100ae-a9c8-47b5-adbd-cbedef5992ef
ms.openlocfilehash: 1f512cc17832564b5eb530b97f8bfb2642c43d43
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65220746"
---
# <a name="localized-resources-in-mfc-applications-satellite-dlls"></a>Recursos localizados em aplicativos MFC: DLLs satélites

O MFC versão 7,0 e posterior fornece suporte aprimorado para DLLs satélite, um recurso que ajuda na criação de aplicativos localizados para vários idiomas. Uma DLL satélite é uma [DLL somente de recursos](creating-a-resource-only-dll.md) que contém os recursos de um aplicativo localizados para um idioma específico. Quando o aplicativo começa a ser executado, o MFC carrega automaticamente o recurso localizado mais apropriado para o ambiente. Por exemplo, você pode ter um aplicativo com recursos de idioma em inglês com duas DLLs satélite, uma contendo uma tradução francesa de seus recursos e a outra que contém uma tradução em alemão. Quando o aplicativo é executado em um sistema de idioma inglês, ele usa os recursos em inglês. Se for executado em um sistema francês, ele usará os recursos em francês; Se for executado em um sistema alemão, ele usará os recursos do alemão.

Para dar suporte a recursos localizados em um aplicativo MFC, o MFC tenta carregar uma DLL satélite contendo recursos localizados em um idioma específico. As DLLs satélite são nomeadas *ApplicationNameXXX*. dll, em que *ApplicationName* é o nome do. exe ou. dll usando MFC, e *xxx* é o código de três letras para a linguagem dos recursos (por exemplo, ' PTB ' ou ' deu ').

O MFC tenta carregar a DLL de recursos para cada um dos seguintes idiomas em ordem, parando quando encontrar uma:

1. O idioma padrão da interface do usuário atual, conforme retornado da API do Win32 GetUserDefaultUILanguage ().

1. O idioma padrão da interface do usuário atual, sem qualquer sublinguagem específica (ou seja, ENC [Canadá inglês] se torna PTB [Inglês dos EUA]).

1. O idioma da interface do usuário padrão do sistema, conforme retornado da API GetSystemDefaultUILanguage (). Em outras plataformas, esse é o idioma do sistema operacional em si.

1. O idioma da interface do usuário padrão do sistema, sem qualquer subidioma específico.

1. Uma linguagem falsa com o código de três letras LOC.

Se o MFC não encontrar nenhuma DLL satélite, ele usará quaisquer recursos contidos no próprio aplicativo.

Por exemplo, suponha que um aplicativo LangExample. exe Use MFC e esteja sendo executado em um sistema de interface de usuário múltipla; o idioma da interface do usuário do sistema é PTB [Português do Brasil] e o idioma da interface do usuário atual é definido como FRC [Canadá francês]. O MFC procura as seguintes DLLs na seguinte ordem:

1. LangExampleFRC. dll (idioma da interface do usuário).

1. LangExampleFRA. dll (idioma da interface do usuário sem o subidioma, neste exemplo francês (França).

1. LangExampleENU. dll (idioma da interface do usuário do sistema).

1. LangExampleLOC. dll.

Se nenhuma dessas DLLs for encontrada, o MFC usará os recursos em LangExample. exe.

## <a name="see-also"></a>Confira também

[Criar DLLs C /C++ no Visual Studio](dlls-in-visual-cpp.md)<br/>
[TN057: localização de componentes MFC](../mfc/tn057-localization-of-mfc-components.md)
