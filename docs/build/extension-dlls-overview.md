---
title: 'DLLs de extensão: Visão geral'
ms.date: 11/04/2016
helpviewer_keywords:
- AFXDLL library
- MFC DLLs [C++], MFC extension DLLs
- DLLs [C++], extension
- shared DLL versions [C++]
- extension DLLs [C++], about MFC extension DLLs
ms.assetid: eb5e10b7-d615-4bc7-908d-e3e99b7b1d5f
ms.openlocfilehash: ab9b980cbb3e89eebee945e90c54f23d6717a1a4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62196723"
---
# <a name="mfc-extension-dlls-overview"></a>DLLs de extensão do MFC: Visão geral

Uma extensão MFC DLL é uma DLL que normalmente implementa classes reutilizáveis derivadas de classes existentes da biblioteca Microsoft Foundation Class. DLLs de extensão do MFC são criados usando a versão da biblioteca de vínculo dinâmico do MFC (também conhecido como a versão compartilhada do MFC). Somente executáveis MFC (aplicativos ou DLLs MFC regulares) que são criados com a versão compartilhada do MFC podem usar uma DLL de extensão do MFC. Com uma DLL de extensão MFC, você pode derivar novas classes personalizadas de MFC e, em seguida, esta versão estendida do MFC para aplicativos que chamam a DLL da oferta.

DLLs de extensão também podem ser usadas para passar objetos derivados do MFC entre o aplicativo e a DLL. As funções de membro associadas com o objeto passado existem no módulo no qual o objeto foi criado. Porque essas funções são exportadas corretamente ao usar a versão DLL compartilhada do MFC, você pode passar livremente MFC ou ponteiros para objetos derivados do MFC entre um aplicativo e a extensão MFC DLLs, ele carrega.

Para obter um exemplo de uma DLL que cumpre os requisitos básicos de uma DLL de extensão do MFC, consulte o exemplo MFC [DLLHUSK](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/advanced/dllhusk). Em particular, examine os arquivos Testdll1.cpp e Testdll2.cpp.

Observe que o termo AFXDLL não é mais usada na documentação do Visual C++. Uma DLL de extensão do MFC tem as mesmas características que o antigo AFXDLL.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Inicializar uma DLL de extensão do MFC](run-time-library-behavior.md#initializing-extension-dlls)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [DLLs de extensão de MFC](extension-dlls.md)

- [Usando banco de dados, OLE e DLLs de extensão de MFC de soquetes em DLLs MFC regulares](using-database-ole-and-sockets-extension-dlls-in-regular-dlls.md)

- [DLLs não MFC: visão geral](non-mfc-dlls-overview.md)

- [DLLs MFC regulares vinculadas estaticamente ao MFC](regular-dlls-statically-linked-to-mfc.md)

- [DLLs MFC regulares vinculadas dinamicamente ao MFC](regular-dlls-dynamically-linked-to-mfc.md)

- [Criando uma DLL MFC](../mfc/reference/mfc-dll-wizard.md)

## <a name="see-also"></a>Consulte também

[Tipos de DLLs](kinds-of-dlls.md)
