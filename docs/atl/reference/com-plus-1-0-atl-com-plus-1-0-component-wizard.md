---
title: COM+ 1.0, o Assistente de componente ATL COM+ 1.0
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.class.atl.mts.options
ms.assetid: 2fbe259c-6be1-4d0e-9cfe-721c75c97cb1
ms.openlocfilehash: 014193f4017aa47b819558cbd4753e6abcffcaaf
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50562052"
---
# <a name="com-10-atl-com-10-component-wizard"></a>COM+ 1.0, o Assistente de componente ATL COM+ 1.0

Use esta página do ATL COM+ 1.0 componente Assistente para especificar o tipo de interface e interfaces adicionais com suporte.

Para obter mais informações sobre projetos ATL e classes COM da ATL, consulte [componentes de área de trabalho COM ATL](../../atl/atl-com-desktop-components.md).

- **Interface**

   Indica o tipo de interface que o objeto dá suporte. Por padrão, o objeto dá suporte a uma interface dupla.

   |Opção|Descrição|
   |------------|-----------------|
   |**Duplo**|Especifica que o objeto dá suporte a uma interface dupla (seu vtable tem funções de interface personalizada e associação tardia `IDispatch` métodos). Permite que os clientes COM e controladores de automação acessar o objeto.|
   |**Personalizado**|Especifica que o objeto dá suporte a uma interface personalizada (seu vtable tem funções de interface personalizada). Uma interface personalizada pode ser mais rápida do que uma interface dupla, especialmente entre os limites do processo.<br /><br /> - **Automação compatível** adiciona suporte de automação para a interface personalizada. Para projetos atribuídos, define o **oleautomation** atributo na coclass.|

- **Passível de enfileiramento**

   Indica que os clientes poderão chamar esse componente de forma assíncrona usando filas de mensagens. Adiciona o componente atribuído macro personalizado (TLBATTR_QUEUEABLE, 0) para o arquivo. h (atribuídos projetos) ou ao arquivo. idl (nonattributed projetos).

- **Suporte**

   Indica suporte adicional para o controle de objeto e de tratamento de erro.

   |Opção|Descrição|
   |------------|-----------------|
   |**ISupportErrorInfo**|Cria o suporte para o [ISupportErrorInfo](../../atl/reference/isupporterrorinfoimpl-class.md) de interface para que o objeto pode retornar informações de erro para o cliente.|
   |**IObjectControl**|Fornece o acesso a objetos para os três [IObjectControl](/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontrol) métodos: [ativar](/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontrol-activate), [CanBePooled](/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontrol-canbepooled), e [desativar](/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontrol-deactivate).|
   |**IObjectConstruct**|Cria o suporte para o [IObjectConstruct](/windows/desktop/api/comsvcs/nn-comsvcs-iobjectconstruct) interface para gerenciar passando parâmetros de outros métodos ou objetos.|

- **Transação**

   Indica que o objeto oferece suporte a transações. Inclui o arquivo mtxattr.h no arquivo. idl (nonattributed projetos).

   |Opção|Descrição|
   |------------|-----------------|
   |**Com suporte**|Especifica que o objeto nunca é a raiz de um fluxo de transações, adicionando o custom(TLBATTR_TRANS_SUPPORTED,0) de macro do atributo de componente para o arquivo. h (atribuídos projetos) ou ao arquivo. idl (nonattributed projetos).|
   |**Necessária**|Especifica que o objeto pode ou não ser a raiz de um fluxo de transação, adicionando o custom(TLBATTR_TRANS_REQUIRED,0) de macro do atributo de componente para o arquivo. h (atribuídos projetos) ou ao arquivo. idl (nonattributed projetos).|
   |**Não tem suporte**|Especifica que o objeto exclui as transações. Adiciona o custom(TLBATTR_TRANS_NOTSUPP,0) de macro do atributo de componente para o arquivo. h (atribuídos projetos) ou ao arquivo. idl (nonattributed projetos).|
   |**Requer novo**|Especifica que o objeto é sempre a raiz de um fluxo de transações, adicionando o custom(TLBATTR_TRANS_REQNEW,0) de macro do atributo de componente para o arquivo. h (atribuídos projetos) ou ao arquivo. idl (nonattributed projetos).|

## <a name="see-also"></a>Consulte também

[Assistente de componente de COM+ 1.0 da ATL](../../atl/reference/atl-com-plus-1-0-component-wizard.md)<br/>
[Componente ATL COM+ 1.0](../../atl/reference/adding-an-atl-com-plus-1-0-component.md)

