---
title: Tornando um Noncreatable de objeto do ATL
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.ATL.objects
helpviewer_keywords:
- noncreatable ATL objects
- ATL projects, noncreatable objects
ms.assetid: 80d0bca2-dea0-4801-9a85-6243124437f6
ms.openlocfilehash: 966c7c1e42cd707726a8ca65bb80914c29ad582e
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57814495"
---
# <a name="making-an-atl-object-noncreatable"></a>Tornando um Noncreatable de objeto do ATL

Você pode alterar os atributos de um objeto COM baseados em ATL para que um cliente diretamente não é possível criar o objeto. Nesse caso, o objeto deve ser retornado por meio de uma chamada de método em outro objeto vez criado diretamente.

## <a name="to-make-an-object-noncreatable"></a>Para fazer um objeto noncreatable

1. Remover o [OBJECT_ENTRY_AUTO](object-map-macros.md#object_entry_auto) para o objeto. Se você quiser que o objeto a ser não passível de criação, mas o controle a ser registrado, substitua OBJECT_ENTRY_AUTO com [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](object-map-macros.md#object_entry_non_createable_ex_auto).

1. Adicione a [noncreatable](../../windows/noncreatable.md) atributo coclass no arquivo. idl. Por exemplo:

    ```
    [uuid(A1992E3D-3CF0-11D0-826F-00A0C90F2851),
    helpstring("MyObject"),
    noncreatable]
    coclass MyObject
    {
        [default] interface IMyInterface;
    }
    ```

## <a name="see-also"></a>Consulte também

[Assistente de Projeto da ATL](../../atl/reference/atl-project-wizard.md)<br/>
[Tipos de projeto do Visual C++](../../build/reference/visual-cpp-project-types.md)<br/>
[Programando com código de tempo de execução C e da ATL](../../atl/programming-with-atl-and-c-run-time-code.md)<br/>
[Princípios básicos de objetos COM da ATL](../../atl/fundamentals-of-atl-com-objects.md)<br/>
[Configurações de projeto padrão da ATL](../../atl/reference/default-atl-project-configurations.md)
