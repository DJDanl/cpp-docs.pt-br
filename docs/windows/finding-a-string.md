---
title: Localizando uma cadeia de caracteres | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.string
dev_langs:
- C++
helpviewer_keywords:
- strings [C++], searching
- strings [C++]
ms.assetid: c2497173-f356-4f77-97d6-f0ac41782510
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 67d3d4ba38563b4716a87d4b57a4753fe1b49e9c
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39652088"
---
# <a name="finding-a-string"></a>Localizando uma cadeia de caracteres
Você pode pesquisar um ou mais cadeias de caracteres na tabela de cadeia de caracteres e usar [expressões regulares](/visualstudio/ide/using-regular-expressions-in-visual-studio) com o **localizar nos arquivos** comando (**editar** menu) para localizar todas as instâncias de cadeias de caracteres que correspondem a um padrão.  
  
### <a name="to-find-a-string-in-the-string-table"></a>Para localizar uma cadeia de caracteres na tabela de cadeia de caracteres  
  
1.  Abra a tabela de cadeia de caracteres clicando duas vezes em seu ícone no [exibição de recurso](../windows/resource-view-window.md).  
  
    > [!NOTE]
    >  Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  Sobre o **editar** menu, clique em **localizar e substituir**, em seguida, escolha **localizar**.  
  
3.  No **localizar** caixa, selecione uma cadeia de caracteres de pesquisa anterior na lista suspensa ou digite o identificador de texto ou recurso de legenda da cadeia de caracteres que você deseja localizar.  
  
4.  Selecione qualquer uma da **localizar** opções.  
  
5.  Clique em **Localizar próximo**.  
  
    > [!TIP]
    >  Para usar expressões regulares ao pesquisar arquivos, use o **localizar nos arquivos** comando. Digite uma expressão regular para corresponder a um padrão ou clique no botão à direita do **localizar** caixa para exibir uma lista de expressões regulares de pesquisa. Quando você seleciona uma expressão dessa lista, ele será substituído como o texto de pesquisa na **localizar** caixa. Se você usar expressões regulares, certifique-se a **usar: expressões regulares** caixa de seleção está selecionada.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados (aquelas que visam o common language runtime), consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [instruções passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Passo a passo: usando recursos para localização com o ASP.NET](http://msdn.microsoft.com/Library/bb4e5b44-e2b0-48ab-bbe9-609fb33900b6).  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editor de cadeias de caracteres](../windows/string-editor.md)   