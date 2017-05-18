---
title: COM+ 1.0, o Assistente de componentes do ATL COM+ 1.0 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.mts.options
dev_langs:
- C++
ms.assetid: 2fbe259c-6be1-4d0e-9cfe-721c75c97cb1
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 36295e5ce296ea6ba982c4ce8cf729bf45860883
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="com-10-atl-com-10-component-wizard"></a>COM+ 1.0, o Assistente de componentes do ATL COM+ 1.0
Use esta página do COM+ 1.0 componente assistente ATL para especificar o tipo de interface e interfaces adicionais com suporte.  
  
 Para obter mais informações sobre projetos ATL e classes ATL COM, consulte [componentes de área de trabalho do ATL COM](../../atl/atl-com-desktop-components.md).  
  
 **Interface**  
 Indica o tipo de interface que o objeto oferece suporte. Por padrão, o objeto oferece suporte a uma interface dupla.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Dual**|Especifica que o objeto oferece suporte a uma interface dupla (seu vtable tem funções de interface personalizada e associação tardia `IDispatch` métodos). Permite que clientes COM e controladores de automação acessar o objeto.|  
|**Personalizado**|Especifica que o objeto oferece suporte a uma interface personalizada (seu vtable tem funções de interface personalizada). Uma interface personalizada pode ser mais rápida do que uma interface dupla, especialmente nos limites do processo.<br /><br /> -   **Automação compatível** adiciona suporte de automação de interface personalizada. Para projetos atribuídos, define o **oleautomation** atributo o coclass.|  
  
 **Passível de enfileiramento**  
 Indica que os clientes podem chamar esse componente forma assíncrona usando filas de mensagens. Adiciona o componente atribuída macro personalizado (TLBATTR_QUEUEABLE, 0) para o arquivo. h (projetos atribuídos) ou para o arquivo. idl (nonattributed projetos).  
  
 **Suporte**  
 Indica suporte adicional para controle de tratamento e o objeto de erro.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**ISupportErrorInfo**|Cria o suporte para o [ISupportErrorInfo](../../atl/reference/isupporterrorinfoimpl-class.md) de interface para o objeto possa retornar informações de erro para o cliente.|  
|**IObjectControl**|Fornece o acesso a objetos para os três [IObjectControl](http://msdn.microsoft.com/library/windows/desktop/ms686474) métodos: [ativar](http://msdn.microsoft.com/library/windows/desktop/ms681303), [CanBePooled](http://msdn.microsoft.com/library/windows/desktop/ms684322), e [desativar](http://msdn.microsoft.com/library/windows/desktop/ms687094).|  
|**IObjectConstruct**|Cria o suporte para o [IObjectConstruct](http://msdn.microsoft.com/library/windows/desktop/ms680583) interface para gerenciar passando parâmetros de outros métodos ou objetos.|  
  
 **Transação**  
 Indica que o objeto oferece suporte a transações. Inclui o arquivo mtxattr.h no arquivo. idl (nonattributed projetos).  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Com suporte**|Especifica que o objeto nunca é a raiz de um fluxo de transações, adicionando o custom(TLBATTR_TRANS_SUPPORTED,0) de macro do atributo de componente para o arquivo. h (projetos atribuídos) ou para o arquivo. idl (nonattributed projetos).|  
|**Necessária**|Especifica que o objeto pode ou não ser a raiz de um fluxo de transações, adicionando o custom(TLBATTR_TRANS_REQUIRED,0) de macro do atributo de componente para o arquivo. h (projetos atribuídos) ou para o arquivo. idl (nonattributed projetos).|  
|**Sem suporte**|Especifica que o objeto exclui as transações. Adiciona o custom(TLBATTR_TRANS_NOTSUPP,0) de macro do atributo de componente para o arquivo. h (projetos atribuídos) ou para o arquivo. idl (nonattributed projetos).|  
|**Requer novo**|Especifica que o objeto é sempre a raiz de um fluxo de transações, adicionando o custom(TLBATTR_TRANS_REQNEW,0) de macro do atributo de componente para o arquivo. h (projetos atribuídos) ou para o arquivo. idl (nonattributed projetos).|  
  
## <a name="see-also"></a>Consulte também  
 [Assistente para ATL COM+ 1.0 do componente](../../atl/reference/atl-com-plus-1-0-component-wizard.md)   
 [ATL componente COM+ 1.0](../../atl/reference/adding-an-atl-com-plus-1-0-component.md)


