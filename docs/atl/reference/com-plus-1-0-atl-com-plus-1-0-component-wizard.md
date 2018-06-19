---
title: COM+ 1.0, o Assistente de componente ATL COM+ 1.0 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.mts.options
dev_langs:
- C++
ms.assetid: 2fbe259c-6be1-4d0e-9cfe-721c75c97cb1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9a23f148fbdc611c8a11d8116b2e7dff34fc9d8f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32358194"
---
# <a name="com-10-atl-com-10-component-wizard"></a>COM+ 1.0, o Assistente de componente ATL COM+ 1.0
Use esta página do ATL COM+ 1.0 componente Assistente para especificar o tipo de interface e interfaces adicionais com suporte.  
  
 Para obter mais informações sobre projetos ATL e classes ATL COM, consulte [componentes de área de trabalho do ATL COM](../../atl/atl-com-desktop-components.md).  
  
 **Interface**  
 Indica o tipo de interface para que o objeto oferece suporte. Por padrão, o objeto oferece suporte a uma interface dupla.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Duplo**|Especifica que o objeto oferece suporte a uma interface dupla (seu vtable tem associação tardia e funções de interface personalizada `IDispatch` métodos). Permite que clientes COM e controladores de automação acessar o objeto.|  
|**Personalizado**|Especifica que o objeto oferece suporte a uma interface personalizada (seu vtable tem funções de interface personalizada). Uma interface personalizada pode ser mais rápida do que uma interface dupla, especialmente em limites de processo.<br /><br /> -   **Automação compatível** adiciona suporte de automação para a interface personalizada. Para projetos atribuídos, define o **oleautomation** atributo em coclass.|  
  
 **Passível de enfileiramento**  
 Indica que os clientes poderão chamar esse componente de forma assíncrona usando filas de mensagens. Adiciona o componente atribuído macro personalizado (TLBATTR_QUEUEABLE, 0) para o arquivo. h (projetos atribuídos) ou para o arquivo. idl (projetos nonattributed).  
  
 **Suporte**  
 Indica suporte adicional para controle de objeto e tratamento de erros.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**ISupportErrorInfo**|Cria suporte para o [ISupportErrorInfo](../../atl/reference/isupporterrorinfoimpl-class.md) interface para o objeto possa retornar informações de erro para o cliente.|  
|**Controledeobjetoi**|Fornece o acesso de objeto para os três [Controledeobjetoi](http://msdn.microsoft.com/library/windows/desktop/ms686474) métodos: [ativar](http://msdn.microsoft.com/library/windows/desktop/ms681303), [CanBePooled](http://msdn.microsoft.com/library/windows/desktop/ms684322), e [desativar](http://msdn.microsoft.com/library/windows/desktop/ms687094).|  
|**Constructodeobjetoi**|Cria suporte para o [Constructodeobjetoi](http://msdn.microsoft.com/library/windows/desktop/ms680583) interface para gerenciar passando parâmetros de outros métodos ou objetos.|  
  
 **Transação**  
 Indica que o objeto oferece suporte a transações. Inclui o arquivo mtxattr.h no arquivo. idl (projetos nonattributed).  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Com suporte**|Especifica que o objeto nunca é a raiz de um fluxo de transações, adicionando o custom(TLBATTR_TRANS_SUPPORTED,0) de macro do atributo de componente para o arquivo. h (projetos atribuídos) ou para o arquivo. idl (projetos nonattributed).|  
|**Necessária**|Especifica que o objeto pode ou não ser a raiz de um fluxo de transação adicionando o custom(TLBATTR_TRANS_REQUIRED,0) de macro do atributo de componente para o arquivo. h (projetos atribuídos) ou para o arquivo. idl (projetos nonattributed).|  
|**Sem suporte**|Especifica que o objeto exclui transações. Adiciona o custom(TLBATTR_TRANS_NOTSUPP,0) de macro do atributo de componente para o arquivo. h (projetos atribuídos) ou para o arquivo. idl (projetos nonattributed).|  
|**Requer novo**|Especifica que o objeto é sempre a raiz de um fluxo de transações, adicionando o custom(TLBATTR_TRANS_REQNEW,0) de macro do atributo de componente para o arquivo. h (projetos atribuídos) ou para o arquivo. idl (projetos nonattributed).|  
  
## <a name="see-also"></a>Consulte também  
 [Assistente para ATL COM+ 1.0 do componente](../../atl/reference/atl-com-plus-1-0-component-wizard.md)   
 [Componente ATL COM+ 1.0](../../atl/reference/adding-an-atl-com-plus-1-0-component.md)

