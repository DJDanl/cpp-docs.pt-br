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
ms.openlocfilehash: ddea5a74dbd40d097398d04c0b2bc274df5ec972
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62252501"
---
# <a name="atl-and-the-free-threaded-marshaler"></a>ATL e marshaler livre de threads

Página de atributos do ATL Simple Object Wizard fornece uma opção que permite que sua classe agregar o marshaler livre (FTM).

O assistente gera código para criar uma instância do marshaler livre na `FinalConstruct` e liberar a instância em `FinalRelease`. Uma macro COM_INTERFACE_ENTRY_AGGREGATE é adicionada automaticamente para o mapa de COM para garantir que `QueryInterface` as solicitações de [IMarshal](/windows/desktop/api/objidlbase/nn-objidlbase-imarshal) são manipuladas pelo marshaler livre.

O marshaler livre permite acesso direto a interfaces em seu objeto de qualquer thread no mesmo processo, acelerar chamadas entre apartments. Essa opção destina-se a classes que usam o modelo de threading os dois.

Ao usar essa opção, as classes devem assumir a responsabilidade para o acesso thread-safe de seus dados. Além disso, os objetos que o marshaler livre de agregação e precisam usar ponteiros de interface obtidos de outros objetos devem executar etapas adicionais para garantir que as interfaces são empacotadas corretamente. Normalmente, isso envolve armazenar os ponteiros de interface na tabela de interface global (GIT) e Obtendo o ponteiro de GIT cada vez que ele é usado. ATL fornece a classe [CComGITPtr](../atl/reference/ccomgitptr-class.md) para ajudá-lo a usar ponteiros de interface armazenados em do GIT.

## <a name="see-also"></a>Consulte também

[Conceitos](../atl/active-template-library-atl-concepts.md)<br/>
[CoCreateFreeThreadedMarshaler](/windows/desktop/api/combaseapi/nf-combaseapi-cocreatefreethreadedmarshaler)<br/>
[IMarshal](/windows/desktop/api/objidlbase/nn-objidlbase-imarshal)<br/>
[Quando usar a tabela de Interface Global](/windows/desktop/com/when-to-use-the-global-interface-table)<br/>
[Problemas de Threading do servidor em processo](/windows/desktop/com/in-process-server-threading-issues)
