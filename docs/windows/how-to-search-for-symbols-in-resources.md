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
ms.openlocfilehash: b45780223191c8dacec12d5312f4d2ac724b4d4f
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33880212"
---
# <a name="how-to-search-for-symbols-in-resources"></a>Como procurar símbolos em recursos
### <a name="to-find-symbols-in-resources"></a>Para localizar símbolos em recursos  
  
1.  Do **editar** menu, escolha **Localizar símbolo**.  
  
2.  No [caixa de diálogo Localizar símbolo](http://msdn.microsoft.com/en-us/63e93d9c-784f-418d-a76a-723da5ff5d96), além de **localizar** caixa, selecione uma cadeia de caracteres de pesquisa anterior na lista suspensa ou digite a tecla de aceleração que você deseja localizar (por exemplo, ID_ACCEL1).  
  
    > [!TIP]
    >  Para usar [expressões regulares](/visualstudio/ide/using-regular-expressions-in-visual-studio) de pesquisa, você deve usar o [comando Localizar nos arquivos](/visualstudio/ide/reference/find-command) do **editar** menu em vez do **Localizar símbolo**comando. Para habilitar a expressões regulares, você deve ter o **uso: expressões regulares** na caixa de diálogo de [caixa de diálogo Localizar](http://msdn.microsoft.com/en-us/dad03582-4931-4893-83ba-84b37f5b1600). Em seguida, você pode clicar no botão de seta para a direita à direita do **localizar** caixa para exibir uma lista de expressões regulares de pesquisa. Quando você seleciona uma expressão na lista, ele é substituído como o texto de pesquisa no **localizar** caixa.  
  
3.  Selecione qualquer uma da **localizar** opções.  
  
4.  Clique em **Localizar próximo**.  
  
    > [!NOTE]
    >  Não é possível procurar símbolos em cadeia de caracteres, acelerador ou binários de recursos.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acesso a recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos para propriedades, e [passo a passo: usando recursos para localização com o ASP.NET](http://msdn.microsoft.com/Library/bb4e5b44-e2b0-48ab-bbe9-609fb33900b6).  
  
 **Requisitos**  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Símbolos: Identificadores de recursos](../windows/symbols-resource-identifiers.md)   
 [Arquivos de recurso](../windows/resource-files-visual-studio.md)   
 [Editores de recursos](../windows/resource-editors.md)