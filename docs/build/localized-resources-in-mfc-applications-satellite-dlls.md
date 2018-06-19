---
title: 'Recursos localizados em aplicativos MFC: DLLs satélites | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0740f567f17c8d44069211274ab1a4c66da311c1
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32369111"
---
# <a name="localized-resources-in-mfc-applications-satellite-dlls"></a>Recursos localizados em aplicativos MFC: DLLs satélites
Versão MFC 7.0 e posterior oferece suporte avançado para satélite DLLs, um recurso que ajuda na criação de aplicativos localizados em vários idiomas. Uma DLL de satélite um [somente de recurso DLL](../build/creating-a-resource-only-dll.md) que contém os recursos do aplicativo localizados para um idioma específico. Quando o aplicativo começa a executar, MFC carrega automaticamente o recurso localizado mais apropriado para o ambiente. Por exemplo, você pode ter um aplicativo com recursos de idioma inglês com duas satélite DLLs, uma que contém uma tradução francesa de seus recursos e outra que contém uma tradução para o alemão. Quando o aplicativo é executado em um sistema de idioma inglês, ele usa os recursos em inglês. Se executado em um sistema em francês, ele usa os recursos em francês; Se executado em um sistema em alemão, ele usa os recursos em alemão.  
  
 Para dar suporte a recursos localizados em um aplicativo MFC, MFC tenta carregar uma DLL satélite que contém recursos localizados para um idioma específico. DLLs satélite são nomeados *ApplicationNameXXX*. dll, onde *ApplicationName* é o nome do .exe ou. dll usando MFC, e *XXX* é o código de três letras para o idioma os recursos (por exemplo, 'PTB' ou 'DEU').  
  
 MFC tenta carregar a DLL de recurso para cada um dos seguintes idiomas na ordem, parando quando encontrar um:  
  
1. Da interface do usuário idioma padrão do usuário atual, conforme retornado da API do Win32 GetUserDefaultUILanguage().  
  
2.  Idioma de interface do usuário padrão do usuário atual, sem qualquer subidioma específico (ou seja, ENC [inglês canadense] se torna PTB [dos EUA Em inglês]).  
  
3.  O idioma padrão do sistema da interface do usuário, conforme retornado da API GetSystemDefaultUILanguage(). Em outras plataformas, esse é o idioma do sistema operacional em si.  
  
4.  O idioma padrão do sistema da interface do usuário, sem qualquer subidioma específico.  
  
5.  Uma linguagem falsa com o código de 3 letras loc.  
  
 Se o MFC não encontrar qualquer DLLs satélite, ele usa todos os recursos que estão contidos no próprio aplicativo.  
  
 Por exemplo, suponha que um aplicativo LangExample.exe usa MFC e está em execução em um sistema de interface do usuário várias; o idioma da interface do usuário do sistema é ENU [dos EUA Em inglês] e o idioma da interface do usuário atual é definido como FRC [francês canadense]. MFC procura as DLLs a seguir na seguinte ordem:  
  
1.  LangExampleFRC.dll (idioma da interface do usuário do usuário).  
  
2.  LangExampleFRA.dll (linguagem de interface do usuário do usuário sem subidioma, neste exemplo, francês (França).  
  
3.  LangExampleENU.dll (idioma da interface do usuário do sistema).  
  
4.  LangExampleLOC.dll.  
  
 Se nenhuma dessas DLLs forem encontradas, o MFC usa os recursos no LangExample.exe.  
  
## <a name="see-also"></a>Consulte também  
 [DLLs no Visual C++](../build/dlls-in-visual-cpp.md)   
 [TN057: localização de componentes MFC](../mfc/tn057-localization-of-mfc-components.md)