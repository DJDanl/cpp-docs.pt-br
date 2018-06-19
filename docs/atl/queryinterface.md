---
title: QueryInterface | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- QueryInterface
dev_langs:
- C++
helpviewer_keywords:
- interfaces, pointers
- interfaces, availability
- QueryInterface method
ms.assetid: 62fce95e-aafa-4187-b50b-e6611b74c3b3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cde92ee56e51a86acbfb7e459571291bc3cae76c
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32356955"
---
# <a name="queryinterface"></a>QueryInterface
Embora haja mecanismos pelos quais um objeto pode expressar a funcionalidade que ele fornece estaticamente (antes que seja instanciado), o mecanismo COM fundamentais é usar o **IUnknown** método chamado [QueryInterface ](http://msdn.microsoft.com/library/windows/desktop/ms682521).  
  
 Cada interface é derivada de **IUnknown**, de modo que cada interface tem uma implementação de `QueryInterface`. Independentemente de implementação, esse método consulta um objeto usando o IID da interface para que o chamador deseja um ponteiro. Se o objeto der suporte a essa interface, `QueryInterface` recupera um ponteiro para a interface, enquanto também chama `AddRef`. Caso contrário, retornará o **E_NOINTERFACE** código de erro.  
  
 Observe que você deve obedecer [contagem de referência](../atl/reference-counting.md) regras em todos os momentos. Se você chamar **versão** em um ponteiro de interface para diminuir a contagem de referência como zero, você não deve usar esse ponteiro novamente. Ocasionalmente, talvez seja necessário obter uma referência fraca a um objeto (ou seja, você poderá obter um ponteiro para uma das suas interfaces sem incrementar a contagem de referência), mas não é aceitável para fazer isso chamando `QueryInterface` seguido por  **Versão**. O ponteiro obtido na forma é inválido e não deve ser usado. Isso mais prontamente torna-se aparente quando [_ATL_DEBUG_INTERFACES](reference/debugging-and-error-reporting-macros.md#_atl_debug_interfaces) é definido para definir esta macro é uma maneira útil de encontrar erros de contagem de referência.  
  
## <a name="see-also"></a>Consulte também  
 [Introdução ao COM](../atl/introduction-to-com.md)   
 [QueryInterface: Navegando em um objeto](http://msdn.microsoft.com/library/windows/desktop/ms687230)

