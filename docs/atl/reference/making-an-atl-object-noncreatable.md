---
title: Tornando um objeto ATL não passível de criação
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.ATL.objects
helpviewer_keywords:
- noncreatable ATL objects
- ATL projects, noncreatable objects
ms.assetid: 80d0bca2-dea0-4801-9a85-6243124437f6
ms.openlocfilehash: b2d0a21ec9e68f76650f0f6cb78446bd93540fa2
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91506955"
---
# <a name="making-an-atl-object-noncreatable"></a>Tornando um objeto ATL não passível de criação

Você pode alterar os atributos de um objeto COM baseado em ATL para que um cliente não possa criar o objeto diretamente. Nesse caso, o objeto seria retornado por meio de uma chamada de método em outro objeto em vez de ser criado diretamente.

## <a name="to-make-an-object-noncreatable"></a>Para tornar um objeto não-cri

1. Remova o [OBJECT_ENTRY_AUTO](object-map-macros.md#object_entry_auto) do objeto. Se você quiser que o objeto seja não-CRI, mas o controle seja registrado, substitua OBJECT_ENTRY_AUTO por [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](object-map-macros.md#object_entry_non_createable_ex_auto).

1. Adicione o atributo não- [cri](../../windows/attributes/noncreatable.md) à coclass no arquivo. idl. Por exemplo:

    ```
    [uuid(A1992E3D-3CF0-11D0-826F-00A0C90F2851),
    helpstring("MyObject"),
    noncreatable]
    coclass MyObject
    {
        [default] interface IMyInterface;
    }
    ```

## <a name="see-also"></a>Confira também

[Assistente de Projeto da ATL](../../atl/reference/atl-project-wizard.md)<br/>
[Tipos de projeto do C++ no Visual Studio](../../build/reference/visual-cpp-project-types.md)<br/>
[Programação com o código de tempo de execução ATL e C](../../atl/programming-with-atl-and-c-run-time-code.md)<br/>
[Conceitos básicos de objetos COM ATL](../../atl/fundamentals-of-atl-com-objects.md)<br/>
[Configurações padrão do projeto do ATL](../../atl/reference/default-atl-project-configurations.md)
