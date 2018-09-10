---
title: 'Como: Procurar símbolos em recursos (C++) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- symbols [C++], finding
- resources [C++], searching for symbols
ms.assetid: 6efef8e8-d0d4-4c49-b895-314974e7791a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 51b2045a1605a37fa9c0d17fdc0c9456652345bd
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44314190"
---
# <a name="how-to-search-for-symbols-in-resources-c"></a>Como: Procurar símbolos em recursos (C++)

### <a name="to-find-symbols-in-resources"></a>Para localizar símbolos em recursos

1. Dos **edite** menu, escolha **Localizar símbolo**.

2. No [caixa de diálogo Localizar símbolo](/visualstudio/ide/go-to), no **localizar** caixa, selecione uma cadeia de caracteres de pesquisa anterior na lista suspensa ou digite a tecla de atalho que você deseja localizar (por exemplo, ID_ACCEL1).

   > [!TIP]
   > Para usar [expressões regulares](/visualstudio/ide/using-regular-expressions-in-visual-studio) para a sua pesquisa, você deve usar o [comando Localizar nos arquivos](/visualstudio/ide/reference/find-command) do **editar** menu, em vez do **Localizar símbolo**comando. Para habilitar a expressões regulares, você deve ter o **uso: expressões regulares** na caixa de diálogo do [caixa de diálogo Localizar](/visualstudio/ide/finding-and-replacing-text). Em seguida, você pode clicar no botão de seta para a direita à direita do **localizar** caixa para exibir uma lista de expressões regulares de pesquisa. Quando você seleciona uma expressão dessa lista, ele será substituído como o texto de pesquisa na **localizar** caixa.

3. Selecione qualquer uma da **localizar** opções.

4. Clique em **Localizar próximo**.

   > [!NOTE]
   > Você não pode pesquisar símbolos em recursos binários, acelerador ou cadeia de caracteres.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recurso a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir recursos cadeias de caracteres de propriedades.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Símbolos: identificadores de recursos](../windows/symbols-resource-identifiers.md)  
[Arquivos de recurso](../windows/resource-files-visual-studio.md)  
[Editores de recursos](../windows/resource-editors.md)