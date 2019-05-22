---
title: Assistente de componentes COM+ 1.0, ATL COM+ 1.0
ms.date: 05/09/2019
f1_keywords:
- vc.codewiz.class.atl.mts.options
ms.assetid: 2fbe259c-6be1-4d0e-9cfe-721c75c97cb1
ms.openlocfilehash: bff7f87fbdebbff9a1823ae8718c64be4f47a2ea
ms.sourcegitcommit: fc1de63a39f7fcbfe2234e3f372b5e1c6a286087
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/15/2019
ms.locfileid: "65707444"
---
# <a name="com-10-atl-com-10-component-wizard"></a>Assistente de componentes COM+ 1.0, ATL COM+ 1.0

::: moniker range="vs-2019"

Esse assistente não está disponível no Visual Studio 2019 e versões posteriores.

::: moniker-end

::: moniker range="<=vs-2017"

Use esta página do Assistente do Componente COM+ 1.0 da ATL para especificar o tipo de interface e interfaces adicionais às quais dar suporte.

Para saber mais sobre projetos da ATL e classes COM da ATL, confira [Componentes de Área de Trabalho COM da ATL](../../atl/atl-com-desktop-components.md).

- **Interface**

   Indica o tipo de interface com a qual o objeto é compatível. Por padrão, o objeto é compatível com uma interface dupla.

   |Opção|Descrição|
   |------------|-----------------|
   |**Dupla**|Especifica que o objeto é compatível com uma interface dupla (seu vtable tem funções de interface personalizada e métodos `IDispatch` de associação tardia). Permite que os clientes COM e os Controladores de automação acessem o objeto.|
   |**Personalizado**|Especifica que o objeto é compatível com uma interface personalizada (seu vtable tem funções de interface personalizada). Uma interface personalizada pode ser mais rápida do que uma interface dupla, principalmente entre limites de processo.<br /><br /> - **Automação compatível** Adiciona suporte de automação à interface personalizada. Para projetos atribuídos, define o atributo **oleautomation** na coclass.|

- **Passível de enfileiramento**

   Indica que os clientes podem chamar este componente de maneira assíncrona usando filas de mensagens. Adiciona a macro atribuída do componente custom(TLBATTR_QUEUEABLE, 0) ao arquivo .h (projetos atribuídos) ou ao arquivo .idl (projetos não atribuídos).

- **Suporte**

   Indica suporte adicional para tratamento de erro e controle de objeto.

   |Opção|Descrição|
   |------------|-----------------|
   |**ISupportErrorInfo**|Cria suporte para a interface [ISupportErrorInfo](../../atl/reference/isupporterrorinfoimpl-class.md) para que o objeto possa retornar informações do erro para o cliente.|
   |**IObjectControl**|Fornece o acesso a objetos para os três métodos [IObjectControl](/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontrol): [Activate](/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontrol-activate), [CanBePooled](/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontrol-canbepooled) e [Deactivate](/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontrol-deactivate).|
   |**IObjectConstruct**|Cria suporte para a interface [IObjectConstruct](/windows/desktop/api/comsvcs/nn-comsvcs-iobjectconstruct) para gerenciar a passagem de parâmetros de outros métodos ou objetos.|

- **Transação**

   Indica que o objeto é compatível com transações. Inclui a arquivo mtxattr.h no arquivo .idl (projetos não atribuídos).

   |Opção|Descrição|
   |------------|-----------------|
   |**Com suporte**|Especifica que o objeto nunca é a raiz de um fluxo de transação adicionando a macro de atributo de componente custom(TLBATTR_TRANS_SUPPORTED,0) ao arquivo .h (projetos atribuídos) ou ao arquivo .idl (projetos não atribuídos).|
   |**Necessária**|Especifica que o objeto pode ou não ser a raiz de um fluxo de transação adicionando a macro de atributo de componente custom(TLBATTR_TRANS_REQUIRED,0) ao arquivo .h (projetos atribuídos) ou ao arquivo .idl (projetos não atribuídos).|
   |**Sem suporte**|Especifica que o objeto exclui transações. Adiciona a macro de atributo do componente custom(TLBATTR_TRANS_NOTSUPP,0) ao arquivo .h (projetos atribuídos) ou ao arquivo .idl (projetos não atribuídos).|
   |**Requer novo**|Especifica que o objeto sempre é a raiz de um fluxo de transação adicionando a macro de atributo de componente custom(TLBATTR_TRANS_REQNEW,0) ao arquivo .h (projetos atribuídos) ou ao arquivo .idl (projetos não atribuídos).|

::: moniker-end

## <a name="see-also"></a>Consulte também

[Assistente de componente de COM+ 1.0 da ATL](../../atl/reference/atl-com-plus-1-0-component-wizard.md)<br/>
[Componente COM+ 1.0 da ATL](../../atl/reference/adding-an-atl-com-plus-1-0-component.md)
