---
title: 'DLLs de extensão: visão geral'
ms.date: 05/06/2019
helpviewer_keywords:
- AFXDLL library
- MFC DLLs [C++], MFC extension DLLs
- DLLs [C++], extension
- shared DLL versions [C++]
- extension DLLs [C++], about MFC extension DLLs
ms.assetid: eb5e10b7-d615-4bc7-908d-e3e99b7b1d5f
ms.openlocfilehash: ea8e950e28907ea1a4a85c1f39392d5505f08c49
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65221363"
---
# <a name="mfc-extension-dlls-overview"></a>DLLs de extensão do MFC: visão geral

Uma DLL de extensão do MFC é uma DLL que normalmente implementa classes reutilizáveis derivadas de classes de biblioteca MFC existentes. As DLLs de extensão do MFC são criadas usando a versão da biblioteca de vínculo dinâmico do MFC (também conhecida como a versão compartilhada do MFC). Somente os executáveis do MFC (aplicativos ou DLLs regulares do MFC) criados com a versão compartilhada do MFC podem usar uma DLL de extensão do MFC. Com uma DLL de extensão do MFC, você pode derivar novas classes personalizadas do MFC e, em seguida, oferecer essa versão estendida do MFC a aplicativos que chamam sua DLL.

DLLs de extensão também podem ser usadas para passar objetos derivados do MFC entre o aplicativo e a DLL. As funções de membro associadas ao objeto passado existem no módulo em que o objeto foi criado. Como essas funções são exportadas corretamente ao usar a versão de DLL compartilhada do MFC, você pode passar livremente ponteiros de objeto derivados MFC ou MFC entre um aplicativo e as DLLs de extensão do MFC que ele carrega.

Para obter um exemplo de uma DLL que atende aos requisitos básicos de uma DLL de extensão do MFC, consulte o exemplo do MFC [DLLHUSK](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/advanced/dllhusk). Em particular, examine os arquivos TESTDLL1. cpp e Testdll2. cpp.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Inicializar uma DLL de extensão do MFC](run-time-library-behavior.md#initializing-extension-dlls)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [DLLs de extensão do MFC](extension-dlls.md)

- [Usando DLLs de extensão do banco de dados, OLE e sockets do MFC em DLLs comuns do MFC](using-database-ole-and-sockets-extension-dlls-in-regular-dlls.md)

- [DLLs que não sejam MFC: visão geral](non-mfc-dlls-overview.md)

- [DLLs MFC regulares vinculadas estaticamente ao MFC](regular-dlls-statically-linked-to-mfc.md)

- [DLLs MFC regulares vinculadas dinamicamente ao MFC](regular-dlls-dynamically-linked-to-mfc.md)

- [Criando uma DLL do MFC](../mfc/reference/mfc-dll-wizard.md)

## <a name="see-also"></a>Confira também

[Tipos de DLLs](kinds-of-dlls.md)
