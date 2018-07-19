---
title: ATL e a versão gratuita marshaler | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ATL, free threaded marshaler
- free threaded marshaler
- threading [C++], marshaler in ATL
- threading [ATL], free threaded marshaler
- FTM in ATL
ms.assetid: 2db88a13-2217-4ebc-aa7e-432d5da902eb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 015b07e5870aa6269dc76af8610d42fb469a6d33
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37848344"
---
# <a name="atl-and-the-free-threaded-marshaler"></a>ATL e marshaler livre de threads
Página de atributos do ATL Simple Object Wizard fornece uma opção que permite que sua classe agregar o marshaler livre (FTM).  
  
 O assistente gera código para criar uma instância do marshaler livre na `FinalConstruct` e liberar a instância em `FinalRelease`. Uma macro COM_INTERFACE_ENTRY_AGGREGATE é adicionada automaticamente para o mapa de COM para garantir que `QueryInterface` as solicitações de [IMarshal](http://msdn.microsoft.com/library/windows/desktop/dd542707) são manipuladas pelo marshaler livre.  
  
 O marshaler livre permite acesso direto a interfaces em seu objeto de qualquer thread no mesmo processo, acelerar chamadas entre apartments. Essa opção destina-se a classes que usam o modelo de threading os dois.  
  
 Ao usar essa opção, as classes devem assumir a responsabilidade para o acesso thread-safe de seus dados. Além disso, os objetos que o marshaler livre de agregação e precisam usar ponteiros de interface obtidos de outros objetos devem executar etapas adicionais para garantir que as interfaces são empacotadas corretamente. Normalmente, isso envolve armazenar os ponteiros de interface na tabela de interface global (GIT) e Obtendo o ponteiro de GIT cada vez que ele é usado. ATL fornece a classe [CComGITPtr](../atl/reference/ccomgitptr-class.md) para ajudá-lo a usar ponteiros de interface armazenados em do GIT.  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)   
 [CoCreateFreeThreadedMarshaler](http://msdn.microsoft.com/library/windows/desktop/ms694500)   
 [IMarshal](http://msdn.microsoft.com/library/windows/desktop/dd542707)   
 [Quando usar a tabela de Interface Global](http://msdn.microsoft.com/library/windows/desktop/ms693729)   
 [Problemas de Threading do servidor em processo](http://msdn.microsoft.com/library/windows/desktop/ms687205)

