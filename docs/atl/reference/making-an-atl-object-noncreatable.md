---
title: Tornando um Noncreatable de objeto ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.appwiz.ATL.objects
dev_langs:
- C++
helpviewer_keywords:
- noncreatable ATL objects
- ATL projects, noncreatable objects
ms.assetid: 80d0bca2-dea0-4801-9a85-6243124437f6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4a77ed656d39888e85e607ee4fdd96b384d0d250
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43761450"
---
# <a name="making-an-atl-object-noncreatable"></a>Tornando um Noncreatable de objeto do ATL

Você pode alterar os atributos de um objeto COM baseados em ATL para que um cliente diretamente não é possível criar o objeto. Nesse caso, o objeto deve ser retornado por meio de uma chamada de método em outro objeto vez criado diretamente.

### <a name="to-make-an-object-noncreatable"></a>Para fazer um objeto noncreatable

1. Remover o [OBJECT_ENTRY_AUTO](object-map-macros.md#object_entry_auto) para o objeto. Se você quiser que o objeto a ser não passível de criação, mas o controle a ser registrado, substitua OBJECT_ENTRY_AUTO com [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](object-map-macros.md#object_entry_non_createable_ex_auto).

2. Adicione a [noncreatable](../../windows/noncreatable.md) atributo coclass no arquivo. idl. Por exemplo:

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

[ATL Project Wizard](../../atl/reference/atl-project-wizard.md)   
[Tipos de projeto do Visual C++](../../ide/visual-cpp-project-types.md)   
[Criando projetos da área de trabalho com assistentes de aplicativo](../../ide/creating-desktop-projects-by-using-application-wizards.md)   
[Programando com código de tempo de execução de C e ATL](../../atl/programming-with-atl-and-c-run-time-code.md)   
[Conceitos básicos de objetos COM da ATL](../../atl/fundamentals-of-atl-com-objects.md)   
[Configurações de projeto padrão da ATL](../../atl/reference/default-atl-project-configurations.md)

