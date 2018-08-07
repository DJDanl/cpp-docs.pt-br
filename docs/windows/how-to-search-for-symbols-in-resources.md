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
ms.openlocfilehash: 3040e89ee4c729953c1a56f0c8728ba4d5b9d7b6
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39570514"
---
# <a name="how-to-search-for-symbols-in-resources"></a>Como procurar símbolos em recursos
### <a name="to-find-symbols-in-resources"></a>Para localizar símbolos em recursos  
  
1.  Dos **edite** menu, escolha **Localizar símbolo**.  
  
2.  No [caixa de diálogo Localizar símbolo](http://msdn.microsoft.com/63e93d9c-784f-418d-a76a-723da5ff5d96), no **localizar** caixa, selecione uma cadeia de caracteres de pesquisa anterior na lista suspensa ou digite a tecla de atalho que você deseja localizar (por exemplo, ID_ACCEL1).  
  
    > [!TIP]
    >  Para usar [expressões regulares](/visualstudio/ide/using-regular-expressions-in-visual-studio) para a sua pesquisa, você deve usar o [comando Localizar nos arquivos](/visualstudio/ide/reference/find-command) do **editar** menu, em vez do **Localizar símbolo**comando. Para habilitar a expressões regulares, você deve ter o **uso: expressões regulares** na caixa de diálogo do [caixa de diálogo Localizar](http://msdn.microsoft.com/dad03582-4931-4893-83ba-84b37f5b1600). Em seguida, você pode clicar no botão de seta para a direita à direita do **localizar** caixa para exibir uma lista de expressões regulares de pesquisa. Quando você seleciona uma expressão dessa lista, ele será substituído como o texto de pesquisa na **localizar** caixa.  
  
3.  Selecione qualquer uma da **localizar** opções.  
  
4.  Clique em **Localizar próximo**.  
  
    > [!NOTE]
    >  Você não pode pesquisar símbolos em recursos binários, acelerador ou cadeia de caracteres.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, e [passo a passo: usando recursos para localização com o ASP.NET](http://msdn.microsoft.com/Library/bb4e5b44-e2b0-48ab-bbe9-609fb33900b6).  
  
## <a name="requirements"></a>Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Símbolos: Identificadores de recursos](../windows/symbols-resource-identifiers.md)   
 [Arquivos de recurso](../windows/resource-files-visual-studio.md)   
 [Editores de recursos](../windows/resource-editors.md)