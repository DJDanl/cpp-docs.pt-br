---
title: Alterando as propriedades de um recurso de cadeia de caracteres (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- resource identifiers, string properties
- string tables [C++], changing strings
- strings [C++], properties
ms.assetid: 0a220434-f444-4405-9a64-d28d6b965687
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: cfd55cbb67bc62760fba26f098a772d62042ea88
ms.sourcegitcommit: 3a141cf07b5411d5f1fdf6cf67c4ce928cf389c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/11/2018
ms.locfileid: "49081988"
---
# <a name="changing-the-properties-of-a-string-resource-c"></a>Alterando as propriedades de um recurso de cadeia de caracteres (C++)

### <a name="to-change-a-string-or-its-identifier"></a>Para alterar uma cadeia de caracteres ou seu identificador

1. Abra a tabela de cadeia de caracteres clicando duas vezes em seu ícone no [exibição de recurso](../windows/resource-view-window.md).

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. Selecione a cadeia de caracteres que você deseja editar e clique duas vezes o **identificação**, **valor**, ou **legenda** coluna. Agora você pode:

   - Selecione uma **ID** da **ID de lista suspensa** lista ou digite um `ID` diretamente no local.

   - Digite um número diferente na **valor** coluna.

   - Digite as edições na **legenda** coluna.

        > [!NOTE]
        >  Você também pode editar as propriedades da cadeia de caracteres na [janela de propriedades](/visualstudio/ide/reference/properties-window).

Para obter informações sobre como adicionar recursos a projetos gerenciados (aquelas que visam o common language runtime), consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [instruções passo a passo: Localizando Windows Forms](/previous-versions/visualstudio/visual-studio-2010/y99d1cd3).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de cadeias de caracteres](../windows/string-editor.md)  