---
title: ATL e marshaler livre de threads
ms.date: 11/04/2016
helpviewer_keywords:
- ATL, free threaded marshaler
- free threaded marshaler
- threading [C++], marshaler in ATL
- threading [ATL], free threaded marshaler
- FTM in ATL
ms.assetid: 2db88a13-2217-4ebc-aa7e-432d5da902eb
ms.openlocfilehash: 94e4961c69e9441d160d72d9b72afcee3677e25f
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491907"
---
# <a name="atl-and-the-free-threaded-marshaler"></a>ATL e marshaler livre de threads

A página de atributos do assistente de objeto simples do ATL fornece uma opção que permite que sua classe agregue o marshaler livre de threads (FTM).

O assistente gera código para criar uma instância do marshaler com thread gratuito no `FinalConstruct` e liberar essa instância no. `FinalRelease` Uma macro COM_INTERFACE_ENTRY_AGGREGATE é automaticamente adicionada ao mapa com para garantir que `QueryInterface` as solicitações de [IMarshal](/windows/win32/api/objidlbase/nn-objidlbase-imarshal) sejam tratadas pelo marshaler livre de threads.

O marshaler livre de threads permite acesso direto a interfaces em seu objeto de qualquer thread no mesmo processo, acelerando chamadas entre apartamento. Essa opção destina-se a classes que usam o modelo de Threading.

Ao usar essa opção, as classes devem assumir a responsabilidade pela segurança de thread de seus dados. Além disso, os objetos que agregam o marshaler de thread livre e precisam usar ponteiros de interface obtidos de outros objetos devem executar etapas adicionais para garantir que as interfaces sejam corretamente empacotadas. Normalmente, isso envolve armazenar os ponteiros de interface na tabela de interface global (GIT) e obter o ponteiro do GIT cada vez que ele é usado. A ATL fornece a classe [CComGITPtr](../atl/reference/ccomgitptr-class.md) para ajudá-lo a usar os ponteiros de interface armazenados no git.

## <a name="see-also"></a>Consulte também

[Conceitos](../atl/active-template-library-atl-concepts.md)<br/>
[CoCreateFreeThreadedMarshaler](/windows/win32/api/combaseapi/nf-combaseapi-cocreatefreethreadedmarshaler)<br/>
[IMarshal](/windows/win32/api/objidlbase/nn-objidlbase-imarshal)<br/>
[Quando usar a tabela de interface global](/windows/win32/com/when-to-use-the-global-interface-table)<br/>
[Problemas de Threading do servidor em processo](/windows/win32/com/in-process-server-threading-issues)
