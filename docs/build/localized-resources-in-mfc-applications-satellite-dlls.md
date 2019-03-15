---
title: 'Recursos localizados em aplicativos MFC: DLLs satélite'
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
ms.openlocfilehash: c593d0bae6fc23cfd765116c44b07caa2a6d8ccf
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57821320"
---
# <a name="localized-resources-in-mfc-applications-satellite-dlls"></a>Recursos localizados em aplicativos MFC: DLLs satélite

Versão do MFC 7.0 e posterior oferece suporte avançado para DLLs satélite, um recurso que ajuda na criação de aplicativos localizados para vários idiomas. Um satélite DLL é um [DLL somente recurso](creating-a-resource-only-dll.md) que contém recursos de um aplicativo localizados para um idioma específico. Quando o aplicativo começa a ser executado, o MFC carrega automaticamente o recurso localizado mais apropriado para o ambiente. Por exemplo, você poderia ter um aplicativo com recursos de idioma inglês com duas DLLs satélite, um contendo uma tradução em francês de seus recursos e a outra que contém uma tradução para o alemão. Quando o aplicativo é executado em um sistema de idioma inglês, ele usa os recursos em inglês. Se executado em um sistema em francês, ele usa os recursos em francês; Se executado em um sistema em alemão, ele usa os recursos em alemão.

Para dar suporte a recursos localizados em um aplicativo do MFC, MFC tenta carregar uma DLL satélite que contém recursos localizados para um idioma específico. DLLs satélite são nomeadas *ApplicationNameXXX*. dll, onde *ApplicationName* é o nome do .exe ou. dll usando o MFC, e *XXX* é o código de três letras do idioma os recursos (por exemplo, 'ENU' ou 'DEU').

MFC tenta carregar a DLL de recurso para cada um dos seguintes idiomas na ordem, parando quando encontra uma:

1. Da interface do usuário idioma padrão do usuário atual, conforme retornado da API do Win32 GetUserDefaultUILanguage().

1. Idioma de interface do usuário padrão do usuário atual, sem qualquer sublinguagem específico (ou seja, ENC [canadense em inglês] se torna PTB [dos EUA Em inglês]).

1. O idioma padrão do sistema da interface do usuário, conforme retornado da API GetSystemDefaultUILanguage(). Em outras plataformas, esse é o idioma do sistema operacional em si.

1. O idioma padrão do sistema da interface do usuário, sem qualquer sublinguagem específico.

1. Uma linguagem falsa com o código de 3 letras loc.

Se não encontrar quaisquer DLLs satélite MFC, ele usa todos os recursos estão contidos no próprio aplicativo.

Por exemplo, suponha que um aplicativo LangExample.exe usa MFC e está em execução em um sistema de interface do usuário vários; o idioma da interface do usuário do sistema é ENU [dos EUA Em inglês] e o idioma da interface do usuário atual é definido como FRC [francês canadense]. MFC procura as DLLs abaixo na seguinte ordem:

1. LangExampleFRC.dll (idioma da interface do usuário).

1. LangExampleFRA.dll (idioma da interface do usuário sem um subidioma, neste exemplo, francês (França).

1. LangExampleENU.dll (idioma de interface do usuário do sistema).

1. LangExampleLOC.dll.

Se nenhuma dessas DLLs for encontrada, o MFC usa os recursos em LangExample.exe.

## <a name="see-also"></a>Consulte também

[DLLs no Visual C++](dlls-in-visual-cpp.md)<br/>
[TN057: Localização de componentes MFC](../mfc/tn057-localization-of-mfc-components.md)
