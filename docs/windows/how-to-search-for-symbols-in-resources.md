---
title: 'Como: Procurar símbolos em recursos | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- symbols, finding
- resources [Visual Studio], searching for symbols
ms.assetid: 6efef8e8-d0d4-4c49-b895-314974e7791a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f105f41c465d2750d372a8794a9ab66fa13db466
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43215976"
---
# <a name="how-to-search-for-symbols-in-resources"></a>Como procurar símbolos em recursos

### <a name="to-find-symbols-in-resources"></a>Para localizar símbolos em recursos

1. Dos **edite** menu, escolha **Localizar símbolo**.

2. No [caixa de diálogo Localizar símbolo](https://msdn.microsoft.com/63e93d9c-784f-418d-a76a-723da5ff5d96), no **localizar** caixa, selecione uma cadeia de caracteres de pesquisa anterior na lista suspensa ou digite a tecla de atalho que você deseja localizar (por exemplo, ID_ACCEL1).

   > [!TIP]
   > Para usar [expressões regulares](/visualstudio/ide/using-regular-expressions-in-visual-studio) para a sua pesquisa, você deve usar o [comando Localizar nos arquivos](/visualstudio/ide/reference/find-command) do **editar** menu, em vez do **Localizar símbolo**comando. Para habilitar a expressões regulares, você deve ter o **uso: expressões regulares** na caixa de diálogo do [caixa de diálogo Localizar](https://msdn.microsoft.com/dad03582-4931-4893-83ba-84b37f5b1600). Em seguida, você pode clicar no botão de seta para a direita à direita do **localizar** caixa para exibir uma lista de expressões regulares de pesquisa. Quando você seleciona uma expressão dessa lista, ele será substituído como o texto de pesquisa na **localizar** caixa.

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